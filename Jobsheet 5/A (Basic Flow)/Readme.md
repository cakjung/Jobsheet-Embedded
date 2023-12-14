# Basic Flow
Simulasi awal menggunakan Node-RED : melakukan pengujian pengiriman pada node `input` dan menampilkannya pada node `output`

**Alat dan Bahan**

Software :

- Ubuntu Virtual Machine
- Node-red

Node :

- Inject (1 buah)
- Debug (1 buah)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%205/A%20(Basic%20Flow)/flows%20(Job%205-A).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a07741c5-707b-4588-bf9f-f6d1d3c45e24)

**Flowchart**

![Flowchart Job 5-A](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/789f49dc-6d58-4344-a9ed-2df6101a68d9)

**Hasil dan Pembahasan**

![job-5-a](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/0820c8ca-b93e-40af-a2eb-733d6ec3303f)

Pada gambar hasil percobaan terlihat bahwa flow yang dibuat merupakan simulasi sederhana dari suatu proses pengiriman data atau pesan (`msg`), dimana terdapat `Inject Node` yang berfungsi sebagai pengirim data dan `Debug Node` yang berfungsi sebagai penerima data. 

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/fd014d16-a9cd-4fb8-a112-760c83c78442)

Data atau pesan yang dapat dikirimkan juga memiliki berbagai macam tipe, beberapa diantaranya yang umum digunakan adalah:
- String, contoh = "Halo Adriano". Tipe data ini merupakan huruf.
- Number, contoh = 17. Tipe data ini merupakan angka.
- Boolean, contoh = true atau false. Tipe data ini merupakan representasi dari bilangan biner (1 dan 0).
- JSON, contoh = {"nama":"adriano","absen":"17"}. Tipe data ini merupakan sebuah objek, dimana dalam suatu objek terdapat beberapa `key` yang memiliki `value` atau nilai. Pada contoh dapat dilihat bahwa terdapat 2 key, yaitu `nama` dan `absen`. Sedangkan `adriano` dan `17` merupakan `value` dari `key` tersebut.
- Timestamp, tipe data berfungsi untuk mengirimkan waktu saat ini.

Pesan yang akan dikirimkan dinamakan `payload`, kemudian `topic` dari pesan dapat digunakan untuk mengisi tujuan. Pada percobaan ini, `topic` belum berpengaruh pada proses pengiriman data, karena hanya terdiri dari Input/Output sederhana saja. Penggunaan dari `msg.topic` akan lebih terlihat pada jobsheet selanjutnya.

**Kesimpulan**

Aplikasi node-red dapat digunakan sebagai media pembelajaran atau simulasi yang berbentuk seperti flow (alur), dengan begitu kita dapat lebih mudah memahami alur kerja atau bagaimana data itu dikirimkan pada suatu sistem.
