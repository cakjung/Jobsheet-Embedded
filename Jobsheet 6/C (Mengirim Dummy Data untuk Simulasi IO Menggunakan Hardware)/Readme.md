# Mengirim Dummy Data untuk Simulasi I/O Menggunakan Hardware
Pada percobaan ini kita akan melakukan ujicoba pengiriman data menggunakan hardware, untuk itu diperlukan aplikasi `MQTT Box` yang dapat diinstall pada `Microsoft Store` atau dapat menginstall extensionnya pada browser `Google Chrome`. Terdapat 2 percobaan, yaitu:

## 1. Pengiriman 2 Topik Pesan berbentuk JSON dengan MQTT Box
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker
- MQTT Box

Node :
- Inject (2 buah)
- MQTT Out (2 buah)
- MQTT In (2 buah)
- JSON Parser (2 buah)
- Function (8 buah)
- Debug (7 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%206/B%20(Menerima%20Data%20JSON%20Melalui%20Protokol%20MQTT)/flows%20(Job%206-B2).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/93bd26f7-74f6-4f90-b7e1-cfc4836c2b39)

### Flowchart

![Flowchart Job 6-B2-C1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/46c98dcf-6ccc-4b74-9e0d-88b940d61e31)

### Hasil dan Pembahasan
Untuk mempercepat percobaan, saya menggunakan flow program yang sudah saya buat pada percobaan sebelumnya. Jika sebelumnya untuk mengirimkan pesan dapat menggunakan node `inject`, sekarang aplikasi MQTT Box-lah yang akan digunakan untuk mengirimkan pesan dengan menggunakan protokol MQTT. Untuk percobaan ini, saya menggunakan MQTT Box versi Microsoft Store:

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/9473bd22-a49d-4210-baa4-346dbcb667b0)

Setelah mengkoneksikan ke Mosquitto Broker, saya membuat 2 publisher baru dengan topik livingroom/sensors dan kitchen/sensors. Untuk mempercepat, saya menggunakan data yang sama seperti pada node `inject` pada percobaan sebelumnya. Berikut adalah hasilnya:

![Job 6-C1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/dcc10905-0dd7-4f57-91c3-dae17c771a54)

Jadi dengan menggunakan aplikasi MQTT Box, kita bisa mengirimkan pesan menggunakan protokol MQTT dengan cara `Add Publisher` kemudian mengisi kolom topic dan payload, jadi konsepnya sama seperti gabungan dari node `MQTT Out` dan `Inject Node`. Pesan yang dikirimkan akan ditampilkan pada bagian kosong dibawah tombol `Publish`. Selain itu, menu `Add Subscriber` dapat menjadikan MQTT Box sebagai penerima pesan (sama seperti node `MQTT In`). Pesan yang diterima juga akan ditampilkan pada bagian kosong dibawah tombol `Subscribe`

### Kesimpulan
MQTT Box dapat digunakan untuk melakukan pengiriman pesan (publisher) menggunakan protokol MQTT. Selain itu, juga bisa berfungsi sebagai penerima pesan (subscriber). Log atau riwayat dari pesan yang dikirim dan diterima juga dapat dilihat, sehingga aplikasi ini dapat digunakan sebagai pengganti node `Inject dan MQTT Out` atau node `Debug dan MQTT In` pada aplikasi node-red.

## 2. Multi-Input Tipe Data menggunakan MQTT Box
Percobaan ini merupakan pengembangan dari percobaan sebelumnya, dimana terdapat beberapa input dengan tipe data yang berbeda yang harus ditampilkan pada debug node khusus.
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker
- MQTT Box

Node :
- Inject (2 buah)
- MQTT Out (2 buah)
- MQTT In (2 buah)
- JSON Parser (2 buah)
- Function (10 buah)
- Debug (13 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%206/C%20(Mengirim%20Dummy%20Data%20untuk%20Simulasi%20IO%20Menggunakan%20Hardware)/flows%20(Job%206-C2).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/b61368e5-b9e3-436c-a06c-1633435d1520)

### Flowchart

![Flowchart Job 6-C2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/ec4d4695-85f4-4045-9767-b0e318e78f8f)

### Hasil dan Pembahasan
Pada percobaan ini saya menggunakan program pada node function untuk menyeleksi tipe data dari pesan, jadi letak pembedanya hanya ada pada node function yang berfungsi sebagai switch.

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/7c7747bd-152d-4d32-86a3-0481f0d5f0f0)

Karena output dari function memiliki urutan yang mengarah pada jenis debug node yang sama, yaitu: 
1. objek
2. string
3. number
4. boolean

Maka kedua function memiliki program yang sama. Berikut adalah programnya:

**Program pada Function yang difungsikan sebagai switch**
```javascript
if (typeof msg.payload === "object") {
    return [msg];
}
else if (typeof msg.payload === "string") {
    return [null, msg];
}
else if (typeof msg.payload === "number") {
    return [null, null, msg];
}
else if (typeof msg.payload === "boolean") {
    return [null, null, null, msg];
}
```

Sama seperti pada percobaan sebelumnya, saya memanfaatkan perbedaan dari topik pesan untuk dijadikan argumen dari fungsi `if`. Setiap function yang berfungsi mengambil nilai dari properti juga sama seperti percobaan sebelumnya. Berikut adalah hasilnya:

**Hasil Percobaan Multi-Input pada Topik Livingroom**

![Job 6-C2 (Livingroom)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c55f6031-2290-4fc3-8310-bd2583c44af9)

**Hasil Percobaan Multi-Input pada Topik Kitchen**

![Job 6-C2 (Kitchen)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/b5c1adab-a469-4861-af7a-8a10adf55597)

Selain pesan berbentuk JSON, MQTT Box juga dapat mengirimkan pesan string, number, atau boolean. Selain itu, juga terdapat tipe data lain yang dapat dikirimkan diantaranya:

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/27a674e5-ed94-447e-b200-89a33efec46a)

### Kesimpulan
Dengan menggunakan MQTT Box, pengiriman format data yang berbeda atau Multi-Input akan menjadi lebih mudah dan cepat tanpa harus membuat node `inject` atau input yang banyak pada flow program node-red.
