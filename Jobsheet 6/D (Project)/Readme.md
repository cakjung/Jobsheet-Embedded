# Project Jobsheet 6
Hal-hal yang harus dilakukan:
- Mengembangkan flow program yang telah dibuat agar ketika terdapat input nilai metane > 5, maka akan ditampilkan pada log atau debug node “Warning”. Jika input metane <=5, tampilkan data pada debug node “Save”.
- Menyimpan data output flow program ke dalam database mysql, serta mencatat waktu saat data tersimpan menggunakan tipe data timestamp
- Membandingkan Publisher dengan QoS yang berbeda
![Job 6-Project (Kitchen)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/b49850f9-efa0-479c-8d02-26e29a7b8776)
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker
- MQTT Box
- XAMPP
- MySQL Server

Node :
- Inject (2 buah)
- MQTT Out (2 buah)
- MQTT In (2 buah)
- JSON Parser (2 buah)
- Function (12 buah)
- Debug (16 buah)
- Mysql (2 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%206/D%20(Project)/flows%20(Job%206-Project).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c3245f8f-5c56-4486-a473-59bbd32b8104)

### Flowchart

![Flowchart Job 6-Project](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/eef8c7cb-858b-41af-93f3-600a89894176)

### Hasil dan Pembahasan
Pada project kali ini, diharuskan untuk menyimpan nilai dari properti pesan pada database server. Karena saya sudah menginstall `MySQL`, yang merupakan database server pada sistem operasi windows, maka langkah pertama adalah mengkoneksikannya ke aplikasi node-red pada VM Ubuntu. Tahapan-tahapan yang saya lakukan, diantaranya:

**1. Menginstall library mysql pada node-red**
   
   ![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/4093ac37-a9eb-4cfc-9029-d206a9bc8d38)

**2. Menambahkan node `mysql` pada bagian storage**
   
   ![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/e8390d8c-35bf-493f-a449-52bb5f83643a)

**3. Mengkonfigurasi host, akun, dan nama database yang akan digunakan**
   
   ![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a79f849b-3f58-4968-9cce-e855dc942039)

   **Catatan**: `172.18.0.1` merupakan IP dari sistem operasi windows yang saya gunakan, sedangkan untuk port saya isi dengan `3306` karena itu merupakan port bawaan (default) yang digunakan oleh MySQL agar dapat bekerja. Kemudian nama database (`nodered`) merupakan nama database yang sudah saya buat sebelumnya.
   
**4. Membuat tabel untuk dijadikan tempat penyimpanan pesan dengan topik livingroom/sensors yang saya namakan `tugas_job6_livingroom`**

   ![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/6dd61295-54e1-40b4-92ae-d7c784904d98)

**5. Membuat tabel untuk dijadikan tempat penyimpanan pesan dengan topik kitchen/sensors yang saya namakan `tugas_job6_kitchen`**

   ![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/b4dd936f-f600-424f-9f08-1e72a2309d8c)

   **Catatan**: Saya tidak memiliki alasan khusus mengapa memilih `decimal(4,2)` menjadi tipe data dari properti pesan. Maksud `4,2` dari tipe data tersebut adalah 4 angka didepan koma dan 2 angka dibelakang koma. Kemudian tipe data `timestamp` digunakan untuk menyimpan data berupa waktu dengan satuan terkecilnya adalah detik.

**6. Ujicoba koneksi ke database (MySQL), jika berhasil maka akan muncul label `connected`**
   
   ![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/5c8fb158-53c1-4736-953d-eb11fd0b7b7c)

Setelah berhasil mengkoneksikan ke MySQL Server, Selanjutnya adalah membuat query agar dapat menambahkan data ke tabel yang sudah dibuat pada MySQL. Yang harus diperhatikan adalah kita harus menjadikan `query SQL` sebagai `topik` dari pesan, ini merupakan aturan yang sudah ter-dokumentasi pada keterangan library mysql pada node-red. Untuk itu saya membuat program menggunakan node function, berikut adalah program yang saya buat:

**1. Query Tabel Livingroom**
```javascript
var val = msg.payload;
var temp = val.temp; // membuat variabel baru untuk mendefinisikan nilai properti temp
var humi = val.humi; // membuat variabel baru untuk mendefinisikan nilai properti humi
var light = val.light; // membuat variabel baru untuk mendefinisikan nilai properti light

msg.topic = "INSERT INTO tugas_job6_livingroom(timestamps, temp, humi, light) VALUES(NOW(), "+temp+", "+humi+", "+light+");";
return msg; // pesan akan diteruskan ke debug node untuk ditampilkan
```
  - `INSERT INTO` merupakan perintah dalam bahasa SQL yang berfungsi untuk menambahkan data ke tabel
  - 'tugas_job6_livingroom(timestamps, temp, humi, light)' merupakan tujuannya, dimana nama tabel adalah `tugas_job6_livingroom` dan `timestamp, temp, humi, light` merupakan urutan dari kolom yang harus diisi.
  - `VALUES()` merupakan perintah yang berfungsi menetapkan nilai ke urutan kolom, karenanya data yang dimasukkan harus urut sesuai dengan urutan kolom.
  - Data pertama adalah NOW(), NOW() merupakan fungsi pada bahasa SQL yang berarti menampilkan data waktu saat ini, sehingga dapat dimanfaatkan sebagai penanda waktu kapan data dimasukkan ke database.
  - Data kedua adalah +temp+, tanda `+` diawal dan akhir variabel merupakan penanda untuk memasukkan `variabel javascript` ke bahasa SQL. Jika tidak ada penanda tersebut, maka SQL akan me-`return` atau mengembalikan nilai yang salah.
  - Dan seterusnya sampai data ke-4 (light).

**2. Query Tabel Kitchen**
```javascript
var val = msg.payload;
var metane = val.metane; // membuat variabel baru untuk mendefinisikan nilai properti metane
var flame = val.flame; // membuat variabel baru untuk mendefinisikan nilai properti flame
var temp = val.temp; // membuat variabel baru untuk mendefinisikan nilai properti temp
var humi = val.humi; // membuat variabel baru untuk mendefinisikan nilai properti humi

msg.topic ="INSERT INTO tugas_job6_kitchen(metane, flame, temp, humi, timestamps) VALUES("+metane+", "+flame+", "+temp+", "+humi+", NOW());"; // menambahkan data ke tabel tugas_job6_kitchen
return msg; // pesan akan diteruskan ke debug node untuk ditampilkan
```

**3. Menambahkan function untuk menghitung nilai properti metane**
```javascript
var val = msg.payload;
msg.payload = val.metane;
if(msg.payload > 5) {
    return [msg,null]; // jika nilai metane lebih dari 5, maka akan meneruskan pesan ke debug node "Warning"
}
if(msg.payload <= 5) {
    return [null,msg]; // jika nilai metane kurang dari atau sama dengan 5, maka akan meneruskan pesan ke debug node "Save"
}
return msg;
```

*Berikut adalah hasilnya:*

**Menyimpan pesan dengan topik Livingroom/sensors**
![Job 6-Project (Livingroom)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/0d018b01-3268-4ce7-8d43-bf99e494ee10)

**Menyimpan pesan dengan topik Kitchen/sensors**
![Job 6-Project (Kitchen)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/9952977a-0c21-46de-9bda-c8c37910448c)

Pada hasil percobaan, saya menggunakan QoS yang berbeda pada kedua publisher. Publisher livingroom saya atur QoS nya menjadi 0, sedangkan publisher kitchen saya atur QoS nya menjadi 2. Secara teori, publisher kitchen-lah yang lebih unggul terkait proses pengiriman datanya karena lebih handal dan aman terhadap packet loss, akan tetapi pada hasil percobaan tidak terjadi kesalahan sama sekali (tidak terjadi packet loss). **Jumlah dari data yang terkirim dan disimpan pada database adalah sama, hal ini menandakan kedua QoS sama bagusnya.** 

Mungkin karena pengiriman data terjadi pada perangkat yang sama, yaitu dari Sistem Operasi Windows ke VM Ubuntu. Jadi latensinya sangat rendah sehingga meskipun menggunakan QoS yang rentan terkena packet loss (QoS 0), jaringan masih cukup handal atau `reliable` untuk dijadikan sebagai media pertukaran pesan atau data.

### Kesimpulan
Protokol MQTT juga dapat digunakan untuk menyimpan pesan ke database server, seperti MySQL Server. Selain harus mengkoneksikan terlebih dahulu sebelum mengirimkan pesan, kita juga harus mengatur `query SQL` menjadi topik dari pesan agar query dapat berfungsi. Pastikan memilih QoS 2 dalam menyimpan pesan ke database, supaya tidak ada pesan yang gagal tersimpan karena masalah koneksi atau hal lain. QoS 2 juga dapat memfilter atau menyeleksi pesan dengan ID yang berbeda, sehingga tidak ada pesan yang terduplikasi (memiliki ID yang sama).
