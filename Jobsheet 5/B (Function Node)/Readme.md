# Function Node
Pada percobaan ini kita akan menggunakan `function node` untuk memproses suatu data yang akan dikirimkan. Terdapat 2 percobaan yang akan dilakukan:

## 1. Function Node Bawaan (Tanpa Pemrograman)
**Alat dan Bahan**

Software :

- Ubuntu Virtual Machine
- Node-red

Node :

- Inject (1 buah)
- Debug (1 buah)
- Function (1 buah)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%205/B%20(Function%20Node)/flows%20(Job%205-B1).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/7b2a31d3-51fb-4eb8-b0d2-b5f438482c8a)

**Flowchart**

![Flowchart Job 5-B1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/755d0e08-41a3-48ab-a053-d1345c196605)

**Hasil dan Pembahasan**

![Job 5-B1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/bce225ab-62e6-4734-89e7-c0d8898fe88a)

Simulasi ini merupakan pengembangan dari flow sebelumnya, dimana terdapat penampahan 1 buah `function` node. Node function ini memungkinkan kita agar dapat memodifikasi data sesuai apa yang kita inginkan, seperti:
- Memproses data, node ini dapat memproses data yang diterima dari input node dan mengirimkan data yang sudah diproses ke output node
- Mengubah data, data yang diubah dapat berupa format pesan atau tipe data dari pesan
- Mengambil data, jadi node dapat berfungsi untuk mengambil data dari suatu sumber (misalnya database).

Node ini menggunakan bahasa javascript sebagai bahasa pemrogramannya.

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/d4ee6a0d-df73-4de5-b0c8-6319c7c05c95)

Pada percobaan ini, tidak ada proses tambahan yang dilakukan didalam node `function`. Jadi hasilnya akan seperti percobaan sebelumnya, yang hanya berupa input node dan output node.

**Kesimpulan**

Function node berfungsi untuk merubah atau memodifikasi pesan atau data agar sesuai dengan apa yang kita inginkan, tentunya dengan cara memprogramnya dengan bahasa `Javascript`.

## 2. Memprogram Function Node
**Alat dan Bahan**

Software :

- Ubuntu Virtual Machine
- Node-red

Node :

- Inject (2 buah)
- Debug (1 buah)
- Function (2 buah)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%205/B%20(Function%20Node)/flows%20(Job%205-B2).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/361f4432-2625-4127-b7a3-978ac97ac9d8)

**Flowchart**

![Flowchart Job 5-B2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/61172a70-6825-4903-ad76-44c2819f4f9a)

**Hasil dan Pembahasan**

![Job 5-B2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a9ef2a2c-ef72-45e0-8577-145b8b85b29b)

Simulasi ini merupakan pengembangan dari flow sebelumnya, dimana terdapat penampahan 2 buah `inject` dan `debug` node. Tujuan utamanya adalah bagaimana caranya data dari `Input 1` ditampilkan pada `Output 1`, dan data dari `Input 2` ditampilkan pada `Output 2`. Untuk itu, kita perlu memodifikasi function node agar dapat memproses data-data yang akan dilewatkan. 

**Isi node `Fungsi`**
```javascript
var topic = msg.topic;
if(topic == 'test1') {
    return [msg,null];
}
else if (topic == 'test2') {
    return [null,msg];
}
return msg;
```

**1. Membuat variabel baru** 
```javascript
var topic = msg.topic;
```
kode ini digunakan untuk mempermudah pemanggilan msg.topic dengan cara menyamakan nilainya.

**2. Menentukan Arah Pesan**
```js
if(topic == 'test1') {
    return [msg,null];
}
else if (topic == 'test2') {
    return [null,msg];
}
```
Array yang terdapat pada kode merupakan nilai output dari function node, pada gambar hasil percobaan juga sudah terlihat bahwa terdapat 2 output pada function node.

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/95e14b95-66bd-45e1-b826-4b0b2067c637)

Nilai pertama dari array merupakan `Output pertama`, maka nilai selanjutnya yang ada dalam array juga merupakan output selanjutnya. Isi dari node `Fungsi` menyatakan bahwa jika topik pesan bernilai `test1`, maka teruskan pesan ke output pertama. Selain itu, jika topik pesan bernilai `test2`, maka teruskan pesan ke output kedua.

**Kesimpulan**

Function node terbukti dapat digunakan sebagai filter pesan atau data, pesan yang melewati function akan diproses dan hasilnya akan diteruskan ke tujuan (node) selanjutnya.
