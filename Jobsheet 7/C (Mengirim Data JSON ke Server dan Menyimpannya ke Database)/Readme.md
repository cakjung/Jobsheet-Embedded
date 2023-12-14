# Mengirim Data JSON ke Server dan Menyimpannya ke Database

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman
- XAMPP
- MySQL Server

Node :
- Http in (1 buah)
- Function (2 buah)
- Debug (1 buah)
- Switch (1 buah)
- Http response (2 buah)
- Mysql (1 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%207/C%20(Mengirim%20Data%20JSON%20ke%20Server%20dan%20Menyimpannya%20ke%20Database)/flows%20(job%207%20c).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/031e1e75-d79d-4dc1-bfee-f08b8cdde278)

### Flowchart

![Flowchart Job 7-C](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/6799dbf9-7a14-4b01-a76d-21c650b0531b)

### Hasil dan Pembahasan
![job-7-c](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a9be10e3-07a3-4524-82b0-029abf8116d6)

Pada gambar hasil percobaan terlihat bahwa ketika request `POST` dilakukan, muncul pesan pada debug node sekaligus menambahkan properti dari pesan tersebut ke tabel `banjir_table` yang ada pada database `nodered`. Berikut adalah tahap-tahap pembuatan dari flow program: 

**1. Pesan dikirim ke URL *server/sensor/node1***

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/7b851462-aea9-433f-b9ab-19018d328636)

POST merupakan metode HTTP yang digunakan untuk mengirimkan suatu data baru ke server, jadi si pengirim data atau pesan adalah client. Sedangkan URL `/testin` merupakan tempat tujuan dari pesan.

**2. Node http in menangkap metode POST dengan URL yang sama**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/40a82950-86f6-4c85-8226-0577ba3c84ff)

**3. Program Node Function Validation**
```javascript
// function ini berfungsi sebagai filter pesan yang akan menentukan HTTP Response
var status = 0;
if (msg.payload.dev_id && msg.payload.rainfall && msg.payload.level) {
    status = 1;  // mengubah nilai status menjadi 1 jika pada pesan yang dikirim terdapat properti: dev_id, rainfall, dan level
}
msg.payload.status = status;
return msg;
```

**4. Konfigurasi Node Switch, dan kedua node response sama seperti percobaan sebelumnya**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a4280cf2-ed82-4bbb-8836-70af08de7a82)

Yang menjadi pembeda dengan percobaan sebelumnya adalah output 1 dari switch node juga terhubung ke node `function query`.

**Node Response `OK`**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/d406d19f-08d2-4039-8540-dc6bf22fb4a3)

**Node Response `Bad`**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c017815c-5e4c-49cc-9ab2-8b16f0f75c4b)

**5. Node Function Query**: berfungsi memasukkan properti dev_id, rainfall, dan level ke tabel `banjir_table`
```javascript
msg.topic = "INSERT INTO banjir_table(dev_id,rainfall,level) VALUES(" + msg.payload.dev_id + "," + msg.payload.rainfall + "," + msg.payload.level +");";
return msg;
```

- Value yang pertama (msg.payload.dev_id) akan dimasukkan ke kolom `dev_id` pada tabel.
- Value yang kedua (msg.payload.rainfall) akan dimasukkan ke kolom `rainfall` pada tabel.
- Value yang ketiga (msg.payload.level) akan dimasukkan ke kolom `level` pada tabel.
  
Hasil olahan pesan akan dikirimkan ke node `Database` (mysql) dan ditampilkan isinya pada node `Response` (debug).

**6. Node Mysql**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c90f4353-841d-4c6a-84a5-d8df23996aa9)

Karena tabel `banjir_table` saya buat pada database yang sama yaitu `nodered`, maka konfigurasi dari node `mysql` sama seperti percobaan sebelumnya. 

Seperti yang terlihat pada gambar hasil percobaan, bahwa: 
- Ketika pesan memiliki properti dev_id, rainfall, dan level, maka response yang diberikan adalah `200` atau OK. Properti dari pesan kemudian disimpan di database pada kolom tabel `banjir_table`.
- Ketika pesan tidak memiliki salah satu saja dari properti dev_id, rainfall, dan level, maka response yang diberikan adalah `400` atau Bad. Properti dari pesan tidak akan disimpan pada database.

### Kesimpulan
Protokol HTTP juga dapat digunakan untuk menyimpan data atau pesan ke dalam database server.
