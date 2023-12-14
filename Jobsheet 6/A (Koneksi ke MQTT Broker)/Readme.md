# Koneksi ke MQTT Broker
Pada percobaan ini kita akan mempelajari bagaimana cara mengkoneksikan publisher dan subscriber pada node-red menggunakan `Mosquitto`, yang merupakan MQTT Broker yang akan digunakan. Mosquitto akan kita gunakan dalam jobsheet 6 ini.

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker

Node :
- Inject (1 buah)
- Debug (1 buah)
- MQTT Out (1 buah)
- MQTT In (1 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%206/A%20(Koneksi%20ke%20MQTT%20Broker)/flows%20(Job%206-A).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/e6cab948-c83b-4306-9988-645e83bebae5)

### Flowchart

![Flowchart Job 6-A](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/41ffdc36-21bf-4ca9-8949-bc274af1fd7e)

### Hasil dan Pembahasan

![Job 6-A](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/e5e7c571-35b8-4ca6-b0e2-4e7675575968)

Node `MQTT Out` berfungsi sebagai publisher sedangkan node `MQTT In`berfungsi sebagai subscriber, dimana topik pesan yang digunakan adalah `livingroom/sensors`. Sesuai dengan prinsip Protokol MQTT, publisher dengan subscriber yang memiliki topik yang sama, akan dapat melakukan pertukaran pesan.

Namun untuk dapat melakukan percobaan diatas, kita diharuskan menginstall broker terlebih dahulu. Jika tidak, maka node MQTT Out dan In tidak akan dapat terhubung walaupun memiliki topik yang sama. 

Karena software node-red yang saya gunakan terinstall di OS Ubuntu, maka cara menginstallnya adalah seperti berikut:
```linux
sudo add-apt-repository ppa:mosquitto-dev/mosquitto-ppa
sudo apt install mosquitto mosquitto-clients
```
Untuk memastikan Mosquitto sudah berjalan atau tidak, dapat kita ketikkan **systemctl status mosquitto** pada CLI Ubuntu:
![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/bb1add2b-8f1d-4f9b-8405-557c1b2a6e4e)

Maka ketika kita men-deploy flow node-red kita, akan terdapat info seperti berikut:
![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/81a1c0a5-d64e-465a-9d5e-129b32f6e2ed)

Ini menandakan bahwa kita sudah bisa menggunakan protokol MQTT pada flow node-red kita. Selain itu pastikan kolom `host` pada node MQTT sudah kita atur menjadi `localhost` dan portnya menjadi 1883. Seperti gambar berikut:
![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/e75f49fb-9277-403e-83ba-9a8a7ecd9c04)


### Kesimpulan
Untuk menggunakan protokol MQTT pada node-red, kita harus menginstall broker terlebih dahulu, salah satunya adalah Mosquitto. Kemudian untuk menambah publisher, kita bisa menggunakan node `MQTT Out` yang sudah dikonfigurasikan pengaturan brokernya. Dan untuk menambah subscriber, kita bisa menggunakan node `MQTT In` yang juga sudah dikonfigurasikan pengaturan brokernya. Pastikan juga kedua node memiliki topik yang sama agar pesan dapat dikirimkan.
