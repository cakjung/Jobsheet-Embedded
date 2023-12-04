# JSON Parsing
Pada percobaan ini kita akan menggunakan `JSON Parser` untuk memproses suatu data yang memiliki tipe data JSON.

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red

Node :
- Inject (1 buah)
- Debug (1 buah)
- Function (1 buah)
- Json Parser (1 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%205/D%20(JSON%20Parsing)/flows%20(Job%205-D).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/cb634b7a-fec3-433a-9788-41ad0c7ab590)

### Flowchart

![Flowchart Job 5-D](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/1c9a6f5d-e537-447e-8a16-f0bb7f309b05)

### Hasil dan Pembahasan

![Job 5-D](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a600c696-2624-4570-9bb5-3566d70311b5)

Fungsi dari node `JSON Parser` adalah untuk mengubah tipe data pesan menjadi `JSON String` atau `Javascript Object`, node ini lumayan penting karena JSON merupakan format tipe data berbentuk teks yang merepresentasikan objek javascript. Meskipun begitu, ada suatu proses dimana kita harus mengubah format data JSON tadi menjadi bentuk lain, salah satunya adalah objek javascript. Dengan mengubahnya ke bentuk JS object, proses pengolahan datanya akan menjadi lebih mudah. Caranya adalah menggunakan fungsi `JSON.parse()` pada kode editor javascript, atau jika kita menggunakan node-red, maka kita hanya membutuhkan node `JSON Parser`.

**Isi Inject Node**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/7a72b635-0a6d-4f30-a883-909f6afd73da)

**Isi Function Node**

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/00bdbe67-38ca-4dce-9dae-e5267ee4c34a)

Pada percobaan kali ini, data yang akan ditampilkan adalah temperature, dimana tipe data pesan saat sebelum dikirimkan berbentuk JSON. Untuk mengambil nilai temperature saja, maka kita bisa menggunakan `dot notation` pada bahasa javascript.

**Contoh penggunaan dot notation**

Berdasarkan dari isi `inject node`, maka isi dari `msg.payload` adalah berupa objek berikut: `{temperature: 27, humidity: 50}`. Maka kita bisa membuat program seperti berikut:

```js
var obj = msg.payload // nilai dari obj sama dengan nilai payload dari properti pesan
msg.payload = obj.temperature // isi dari pesan sama dengan nilai dari properti temperature
```
Dot notation merupakan suatu cara untuk mengakses properti dari sebuah objek, seperti pada program diatas. Dengan begitu kita bisa menampilkan pesan berupa nilai dari properti temperature pada node output.

Selain itu, terdapat baris program alternatif dari kedua baris tersebut adalah:
```js
msg.payload = msg.payload.temperature
```
Nilai dari pesan (payload) sama dengan nilai dari properti `temperature` yang diambil dari objek (karena sebelumnya pesan masih berbentuk objek). **Jadi kedua program tersebut sama**. Karena pemrosesan datanya tidak kompleks, maka sebaiknya baris program dibuat sederhana dan tidak perlu memprogram secara panjang serta berbelit-belit. 

### Kesimpulan

JSON Parser berfungsi untuk merubah atau memodifikasi tipe data pesan menjadi Object atau JSON String, dan untuk mengambil salah satu propertinya, kita bisa menggunakan dot notation.
