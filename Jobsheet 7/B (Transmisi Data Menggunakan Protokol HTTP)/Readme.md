# Transmisi Data Menggunakan Protokol HTTP
Pada percobaan kali ini, ujicoba pengiriman pesan akan menggunakan protokol HTTP. Berbeda dengan MQTT, HTTP memerlukan koordinasi dari client dan server, keduanya harus aktif agar pesan dapat dikirimkan. Selain itu, protokol HTTP ini bekerja pada port 80. Untuk melakukan pengiriman menggunakan HTTP, kita bisa memanfaatkan software API Caller bernama `Postman`. Postman merupakan apikasi yang dapat melakukan pengujian dan debugging pada API menggunakan permintaan (`request`) HTTP, `response` atau hasilnya juga dapat dilihat secara langsung pada aplikasi Postman.

Terdapat 3 percobaan yang akan dilakukan:

## 1. Melakukan HTTP Request
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman

Node :
- Http in (1 buah)
- Debug (1 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%207/B%20(Transmisi%20Data%20Menggunakan%20Protokol%20HTTP)/flows%20(job%207%20b1).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/2bd99658-1543-46c9-a8c0-671a4c4eba5e)

### Flowchart

![Flowchart Job 7-B1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/452483f3-97d4-40e1-a9a1-e4cf5ba18ea8)

### Hasil dan Pembahasan
![job-7-b1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/4115c0e4-2777-4260-8681-b0dbdbc4f821)

Pada gambar hasil percobaan terlihat bahwa ketika request `POST` dilakukan, muncul pesan pada debug node. Hal ini bisa terjadi pesan dikirimkan ke alamat atau URL dari server (node-red), dimana pada node-red sudah terdapat node `http in` yang menerima pesan tersebut. 

**1. Pesan dikirim ke URL *server/testin***

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/84522ba4-c8b5-4364-bf30-5605580d923c)

POST merupakan metode HTTP yang digunakan untuk mengirimkan suatu data baru ke server, jadi si pengirim data atau pesan adalah client. Sedangkan URL `/testin` merupakan tempat tujuan dari pesan.

**2. Node http in menangkap metode POST dengan URL yang sama**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/8d20b969-5998-47c0-8120-a0dd06435033)

Fungsi dari node `http in` adalah untuk membuat `HTTP endpoint` atau tujuan dari permintaan yang dilakukan oleh client, node ini juga dapat dikonfigurasikan untuk melakukan metode HTTP lainnya seperti GET, PUT, DELETE, dll.

### Kesimpulan
Dengan menggunakan `Postman` dan node `http in`, kita sudah bisa melakukan sebuah request HTTP untuk mengirimkan suatu pesan atau data.

## 2. Menampilkan Masing-masing Properti dari Pesan Menggunakan HTTP
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman

Node :
- Http in (1 buah)
- Debug (3 buah)
- Function (3 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%207/B%20(Transmisi%20Data%20Menggunakan%20Protokol%20HTTP)/flows%20(job%207%20b2).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/e1c680d5-ed19-409f-8287-bd5702551b4f)

### Flowchart

![Flowchart Job 7-B2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/101699cb-1942-4324-8cb8-a886d06ccb96)

### Hasil dan Pembahasan
![job-7-b2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/758f2eb6-7005-42d8-b623-ae7c6ac2562c)

Tujuan dari percobaan ini adalah untuk menampilkan masing-masing properti dari pesan pada debug node, maka dari itu program yang saya buat pada function, kurang lebih sama seperti pada percobaan sebelumnya:

**Function validation temp**
```javascript
var obj = msg.payload;
msg.payload = obj.temp;  // mengisi pesan dengan nilai properti `temp`
return msg;
```

**Function validation humi**
```javascript
var obj = msg.payload;
msg.payload = obj.humi;  // mengisi pesan dengan nilai properti `humi`
return msg;
```

**Function validation light**
```javascript
var obj = msg.payload;
msg.payload = obj.light; // mengisi pesan dengan nilai properti `light`
return msg;
```

Namun yang perlu diperhatikan adalah walaupun data yang terkirim adalah **angka** 17, namun data yang diterima justru berbentuk *string*. Hal ini bisa terjadi dikarenakan tidak adanya node `JSON Parser` pada flow yang dibuat, jadi data (berbentuk JSON string) yang terkirim belum sepenuhnya menjadi objek saat sampai di node function. Maka dari itu, pesan yang diterima masih berbentuk **string**.

Selain itu, ada hal lain yang juga perlu untuk diperhatikan.

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a7260576-9eb6-4261-9341-ef658e8f8382)

Setelah pesan dikirimkan, proses pengiriman pada Postman seakan-akan masih saja berjalan. Padahal pesan sudah sampai pada tujuan (debug node). Hal ini terjadi karena Postman tidak mendapatkan `HTTP response` dari server, maka dari itu tampilan pada aplikasi Postman seperti gambar diatas.

### Kesimpulan
Dalam mengirimkan suatu pesan atau data, pastikan terdapat node JSON Parse agar data dapat terbaca dengan benar. Hal ini dapat mengantisipasi kesalahan seperti pembacaan data yang salah.

## 3. Membuat HTTP Response
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman

Node :
- Http in (1 buah)
- Debug (2 buah)
- Function (1 buah)
- Switch (1 buah)
- Http response (2 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%207/B%20(Transmisi%20Data%20Menggunakan%20Protokol%20HTTP)/flows%20(job%207%20b3).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/727acbf1-12f7-4fbb-85c6-9a86f3783d88)

### Flowchart

![Flowchart Job 7-B3](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/d84be520-545a-4ea6-853d-fd0d1843ee4a)

### Hasil dan Pembahasan
![job-7-b3](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/0dbfd631-d8f1-4a97-b277-8e2ddacf8300)

Tujuan dari percobaan ini adalah untuk membuat sebuah jawaban atau `response` yang nantinya akan dikirimkan ke pengirim untuk memberi tahu pesan sudah diterima atau belum. Pada percobaan ini, terdapat 2 buah node `http response` yang berfungsi mengirimkan `Status Code` ke pengirim (Postman). Berikut adalah penjelasan dari proses pengiriman pesannya:

**Node Function**
```javascript
var status = 0;
if (msg.payload.temp && msg.payload.humi && msg.payload.light) {
    status = 1; // mengubah nilai status menjadi 1 jika pada pesan yang dikirim terdapat properti: temp, humi, dan light
}
msg.payload.status = status;
return msg;
```

**Node Switch**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a4280cf2-ed82-4bbb-8836-70af08de7a82)

Node switch akan membaca nilai status dari pesan yang dikirim. Jika nilai status adalah 1, maka pesan akan diteruskan ke output 1. Dan jika nilai status adalah 0, maka pesan akan diteruskan ke output 2. Output 1 dari switch terhubung ke node http `Response OK` sedangkan Output 2 dari switch terhubung ke node http `Response Bad`.

**Node Response `OK`**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/d406d19f-08d2-4039-8540-dc6bf22fb4a3)

**Node Response `Bad`**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c017815c-5e4c-49cc-9ab2-8b16f0f75c4b)

Seperti yang terlihat pada gambar hasil percobaan, bahwa: 
- Ketika pesan memiliki properti temp, humi, dan light, maka response yang diberikan adalah `200` atau OK.
- Ketika pesan tidak memiliki salah satu saja dari properti temp, humi, dan light, maka response yang diberikan adalah `400` atau Bad.

Response yang berupa `Status Code` atau kode status inilah yang akan dibaca oleh Postman, sehingga hasilnya akan berbeda dengan percobaan sebelumnya yang tidak menggunakan node `http response`. Postman akan menampilkan kondisi dari pesan yang dikirimkan, berikut adalah tampilan `response tab` pada aplikasi Postman:

1. Ketika nilai kode status adalah `200`
![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/78b5f928-d204-4520-81cf-6a98b936411c)

2. Ketika nilai kode status adalah `400`
![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/9c378544-174a-463e-a423-9742091e6dbd)

### Kesimpulan
Berbeda dengan node `http in`, node `http response` berfungsi mengirimkan `response` atau jawaban terhadap permintaan yang dibuat oleh pengirim (yang melakukan permintaan). Kedua node ini dapat menjelaskan bagaimana server merespons permintaan yang diminta oleh klien, dan sebaliknya.
