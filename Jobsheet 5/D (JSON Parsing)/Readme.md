# JSON Parsing
Pada percobaan ini kita akan menggunakan `JSON Parser` untuk memproses suatu data yang memiliki tipe data JSON.

## Menggunakan JSON Parsing
**Alat dan Bahan**

Software :

- Ubuntu Virtual Machine
- Node-red

Node :
- Inject (1 buah)
- Debug (1 buah)
- Function (1 buah)
- Json Parser (1 buah)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%205/D%20(JSON%20Parsing)/flows%20(Job%205-D).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/cb634b7a-fec3-433a-9788-41ad0c7ab590)

**Flowchart**

![Flowchart Job 5-D](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/1c9a6f5d-e537-447e-8a16-f0bb7f309b05)

**Hasil dan Pembahasan**

![Job 5-D](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a600c696-2624-4570-9bb5-3566d70311b5)

Fungsi dari node `JSON Parser` adalah untuk mengubah tipe data pesan yang berupa `JSON` ke `Javascript Object` dan sebaliknya, node ini lumayan penting karena JSON merupakan tipe data yang umum digunakan. Meskipun begitu, ada suatu proses dimana kita harus mengubah format data JSON tadi menjadi bentuk lain, salah satunya adalah objek javascript. Dengan mengubahnya ke bentuk JS object, proses pengolahan datanya akan menjadi lebih mudah.

**Sebagai contoh**

Terdapat data berupa JSON yang berisi: {"nama":"adriano"}. Jika kita ingin menampilkan nilai dari key `nama`, maka kita harus mengkonversikannya menjadi objek javascript.
```js
json_decode(msg) // merubah JSON {"nama":"adriano"} menjadi {nama: adriano}
msg.payload = msg.payload.nama // merubah pesan agar menampilkan nilai dari key nama
return msg
```
Json_decode merupakan kode native javascript yang digunakan untuk merubah atau menconvert JSON menjadi object, jadi fungsinya seperti node `JSON Parser` pada software Node-Red. Dengan menerapkan kode seperti diatas, maka output atau `msg` yang ditampilkan adalah `adriano`.

Namun bagaimana jika data JSON tidak kita parsing, maka output yang ditampilkan adalah `"{"nama":"adriano"}"`. Jadi data masih berupa string, data seperti ini tidak dapat diolah oleh node `function`.

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/7a72b635-0a6d-4f30-a883-909f6afd73da)

Pada percobaan kali ini, data yang akan ditampilkan adalah temperature, dimana tipe data pesan saat sebelum dikirimkan masih berbentuk JSON. Dengan menggunakan JSON Parser yang difungsikan untuk mengubah JSON ke objek javascript, maka data JSON tersebut dapat diproses oleh mesin agar dapat diambil nilai `temperature`nya.

**Kesimpulan**

JSON Parser berfungsi untuk merubah atau memodifikasi tipe data pesan yang berupa Object menjadi JSON String atau sebaliknya, node ini sangat penting karena dapat menentukan bagaimana alur pemrosesan data kedepannya. Jika tidak melakukan `parsing data`, maka data JSON tidak akan dapat diolah.
