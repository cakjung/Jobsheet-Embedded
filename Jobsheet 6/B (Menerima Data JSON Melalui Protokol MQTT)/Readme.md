# Menerima Data JSON Melalui Protokol MQTT
Pada percobaan ini kita akan melakukan ujicoba pengiriman data yang berupa JSON. Terdapat 2 percobaan, yaitu:

## 1. Pengiriman 1 Topik Pesan
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker

Node :
- Inject (1 buah)
- MQTT Out (1 buah)
- MQTT In (1 buah)
- JSON Parser (1 buah)
- Function (1 buah)
- Debug (1 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%206/B%20(Menerima%20Data%20JSON%20Melalui%20Protokol%20MQTT)/flows%20(Job%206-B1).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/47021956-41d2-43d5-891b-2f2cab50cad9)

### Flowchart

![Flowchart Job 6-B1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/d4fa2680-cc36-4092-8e64-51fa32f403aa)

### Hasil dan Pembahasan
Pada percobaan ini kita akan mengirimkan nilai dari properti `humi` menggunakan protokol MQTT. Berikut adalah isi dari **inject node**:

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c88389b7-2824-43a8-81bf-8a1416fee005)

Untuk itu seperti pada percobaan sebelumnya, ada beberapa langkah yang harus dilakukan:
- Mengkoneksikan node-red ke Mosquitto
- Mengkonfigurasikan node MQTT Out dan In
- Mengubah tipe data menjadi object menggunakan node JSON Parser
- Mengambil nilai properti humi menggunakan dot notation pada node function

Berikut adalah hasilnya:

![Job 6-B1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/ebf54a02-2b48-4078-ac5c-9ccd3a13091b)

### Kesimpulan
Protokol MQTT juga dapat digunakan untuk mengirimkan data JSON atau objek.

## 2. Pengiriman 2 Topik Pesan
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker

Node :
- Inject (2 buah)
- MQTT Out (2 buah)
- MQTT In (2 buah)
- JSON Parser (2 buah)
- Function (8 buah)
- Debug (7 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%206/B%20(Menerima%20Data%20JSON%20Melalui%20Protokol%20MQTT)/flows%20(Job%206-B2).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/96fab167-0274-47fc-a1ce-9c04ec702b46)

### Flowchart

![Flowchart Job 6-B2-C1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/6e9f1751-e851-4d37-8642-211e7320c2cf)

### Hasil dan Pembahasan
Pada percobaan ini kita akan mengirimkan 2 pesan dengan topik yang berbeda menggunakan protokol MQTT. Setiap properti dari pesan nantinya akan ditampilkan pada `debug node` yang berbeda-beda.

**1. Inject Node**
- Livingroom/sensors = berisikan data objek {"temp":24,"humi":30,"light":10}.
- Kitchen/sensors = berisikan data objek {"flame":0,"metane":0,"temp":24,"humi":38}.

**2. Function untuk Multi-Input**
```javascript
var topic = msg.topic;
if(topic == "livingroom/sensors") {
    return [msg,null]; // jika topik pesan adalah livingroom/sensors, maka teruskan pesan ke output pertama
}
if(topic == "kitchen/sensors") {
    return [null,msg]; // jika topik pesan adalah kitchen/sensors, maka teruskan pesan ke output kedua
}
return msg;
```
Karena terdapat perbedaan topik, maka hal tersebut menjadi celah atau `gap` yang dapat digunakan sebagai argumen dari fungsi `if`.

**3. Publisher dan Subscriber** : menyesuaikan topik

**4. JSON Parser** : terhubung ke masing-masing subscriber, memastikan agar pesan selalu berbentuk objek

**5. Output Function** : digunakan untuk mengambil nilai dari properti tertentu. Karena ada 7 properti yang berbeda, maka terdapat pula 7 node function yang terhubung ke 7 output (`debug node`):
- **Function `temp-livingroom`**
  
  ```javascript
  msg.payload = msg.payload.temp; 
  return msg;
  ```
- **Function `humi-livingroom`**
  
  ```javascript
  msg.payload = msg.payload.humi; 
  return msg;
  ```
- **Function `light-livingroom`**
  
  ```javascript
  msg.payload = msg.payload.light; 
  return msg;
  ```
- **Function `flame-kitchen`**
  
  ```javascript
  msg.payload = msg.payload.flame; 
  return msg;
  ```
- **Function `metane-kitchen`**
  
  ```javascript
  msg.payload = msg.payload.metane; 
  return msg;
  ```
- **Function `temp-kitchen`**
  
  ```javascript
  msg.payload = msg.payload.temp; 
  return msg;
  ```
- **Function `humi-kitchen`**
  
  ```javascript
  msg.payload = msg.payload.humi; 
  return msg;
  ```

Berikut adalah hasilnya:

![Job 6-B2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c285141a-4e0e-4c32-b854-a8a3346a6a59)

Meskipun terdapat properti yang sama, seperti `temp` dan `humi`, akan tetapi topik dari pesannya berbeda. Dengan begitu, nilai dari properti pesan tidak akan tertukar meskipun memiliki key atau properti yang sama dengan pesan lainnya.

### Kesimpulan
Protokol MQTT dapat mengirim data JSON dengan topik yang berbeda tanpa tertukar nilai propertinya, karena kuncinya ada pada topik pesan. Meskipun propertinya sama, asalkan topik pesan berbeda maka properti pesan tidak akan tertukar. Maka dari itu topik merupakan properti dari pesan yang krusial dalam pengiriman menggunakan protokol MQTT.
