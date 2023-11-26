# GPIO
Percobaan ini ditujukan agar dapat memahami penggunaan pin GPIO pada ESP32. Terdapat 4 percobaan yang berbeda :
# 1. Membuat Blink LED menggunakan millis()
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (1 buah)
- Resistor 220 Ohm (1 buah)
- Resistor 10 kOhm (1 buah)
- Push Button (1 buah)

**Skema Rangkaian**

![Skematik (Job 1-A)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/66c26000-428d-4d83-95aa-9acc5118c28d)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/tree/main/Jobsheet%201/A%20(GPIO)/1._Langkah_2.ino/1._Langkah_2.ino.ino">(File .ino)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/6fdb5909-513d-4e39-92b7-99230cfb9cc6)

**Flowchart**

![Flowchart Job1 A-2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/cde437ea-2f4a-4ac4-a70b-d957d6386fb9)


**Hasil dan Pembahasan**

![Job 1A_2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/f2d83b66-ab0b-4652-923e-cf0927875a22)

Program ini dibuat untuk mengatur kedipan LED setiap 1 detik. Pengendalian LED dilakukan menggunakan fungsi `millis()` yang merupakan metode non-blocking/asinkron. Metode asinkron akan terus dijalankan dan tidak terpaku pada program utama (berjalan terpisah). Beberapa variabel yang digunakan meliputi:

- `ledPin`: Menentukan pin yang terhubung ke Output (LED) (GPIO 5).
- `ledState`: Variabel yang mengindikasikan keadaan LED (HIGH atau LOW).
- `previousMillis`: Menyimpan waktu terakhir (LED) berubah keadaan.
- `interval`: Menyimpan interval waktu (dalam milidetik) untuk kedipan LED (1000 ms atau 1 detik).

Pada bagian setup(), `ledPin` diatur sebagai OUTPUT dengan menggunakan pinMode(), memberi tahu Arduino bahwa pin tersebut akan mengendalikan LED. Pada loop(), pertama-tama nilai `currentMillis` diperoleh menggunakan millis(), yang mencatat waktu sejak Arduino dinyalakan. Program kemudian memeriksa apakah selisih waktu antara `currentMillis` dan `previousMillis` lebih besar atau sama dengan `interval` (1 detik). Ini berfungsi sebagai mekanisme waktu untuk mengubah keadaan LED. Jika selisih waktu sudah mencapai atau melebihi interval, maka `previousMillis` diperbarui dengan `currentMillis`. Selanjutnya, program memeriksa keadaan `ledState`. Jika `ledState` adalah LOW (mati), maka akan diubah menjadi HIGH (nyala), dan sebaliknya. Terakhir, menggunakan digitalWrite(), LED akan diatur sesuai dengan nilai `ledState`, menciptakan efek kedipan LED dengan interval 1 detik.

**Kesimpulan**

Program ini berfungsi menghasilkan efek berkedip pada LED setiap 1 detik dengan menggunakan fungsi millis() untuk menghindari ketergantungan atau sinkronisasi waktu (blocking), sehingga cocok digunakan sebagai timer untuk program LED berkedip.

# 2. Membuat Blink LED saat penekanan button
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (1 buah)
- Resistor 220 Ohm (1 buah)
- Resistor 10 kOhm (1 buah)
- Push Button (1 buah)

**Skema Rangkaian**

![Skematik (Job 1-A)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/66c26000-428d-4d83-95aa-9acc5118c28d)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%201/A%20(GPIO)/1._Langkah_3.ino/1._Langkah_3.ino.ino">(File .ino)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/8c5b6f6a-76ef-4e4e-a3d5-bf5fa6002ee1)


**Flowchart**

![Flowchart Job1 A-3](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/8881fd0b-b384-4144-86a7-54ffc5afdbee)

**Hasil dan Pembahasan**

![Job 1A_3](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/26d0fab2-db22-4e74-8843-61296125cf6d)

Program dimulai dengan melakukan inisialisasi variabel input dan output:

- `buttonPin` (pin 4) dan `ledPin` (pin 5) diumumkan sebagai konstanta yang menentukan pin yang akan digunakan dalam program.
- `buttonState` merupakan variabel yang akan menyimpan status (HIGH atau LOW) dari tombol tekan.
 
Dalam bagian `setup()`, program memulai inisialisasi komunikasi serial dengan Serial.begin(115200), memungkinkan program berkomunikasi dengan komputer melalui Serial Monitor dengan kecepatan 115200 baud. Selanjutnya, `pinMode()` digunakan untuk mengatur `buttonPin` sebagai input (untuk membaca tombol tekan) dan `ledPin` sebagai output (untuk mengendalikan LED).

Pada bagian `loop()`, program menjalankan beberapa tugas berulang kali:

- `buttonState` diisi dengan nilai yang dibaca dari `buttonPin` menggunakan `digitalRead()`. Ini akan menghasilkan nilai HIGH jika tombol tekan ditekan, dan LOW jika tidak.
- `Serial.println(buttonState)` digunakan untuk mencetak nilai `buttonState` ke Serial Monitor, memungkinkan kita melihat status tombol tekan dalam Serial Monitor.
- Program kemudian memeriksa nilai `buttonState` dalam suatu kondisi:
  - Jika `buttonState` bernilai HIGH (tombol tekan ditekan), maka `digitalWrite(ledPin, HIGH)` akan dijalankan untuk menyalakan LED dengan mengatur pin `ledPin` menjadi HIGH.
  - Jika `buttonState` bernilai LOW (tombol tekan tidak ditekan), maka `digitalWrite(ledPin, LOW)` akan dijalankan untuk mematikan LED dengan mengatur pin `ledPin` menjadi LOW.

**Kesimpulan**

Program ini berfungsi menyalakan LED hanya ketika button ditekan, jadi button berfungsi sebagai saklar atau switch. Selain itu, kondisi dari button juga tercatat pada serial monitor.

# 3. Membuat Blink LED berdurasi 500ms saat penekanan button
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (2 buah)
- Resistor 220 Ohm (2 buah)
- Resistor 10 kOhm (2 buah)
- Push Button (2 buah)

**Skema Rangkaian**

![Skematik Job1 A-4](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/afadce2f-fa8f-4c50-9947-4ee9b5f3dcca)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%201/A%20(GPIO)/1._Langkah_4.ino/1._Langkah_4.ino.ino">(File .ino)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/934a9c2c-6c56-4c7e-b06f-05337d6f0ffa)

**Flowchart**

![Flowchart Job1 A-4](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/13236481-a557-43a9-873d-3528fc2c1880)

**Hasil dan Pembahasan**

![Job 1A_4](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/3ec1ab7c-023f-425a-a32d-bdd115286f46)

Program ini memulai dengan mendeklarasikan pin GPIO untuk dua push button (`buttonPin1` dan `buttonPin2`) serta dua LED (`ledPin1` dan `ledPin2`).

Dalam fungsi `setup()`, pin-pin diatur sesuai dengan fungsinya, yaitu push button sebagai input dan LED sebagai output.

Dalam fungsi `loop()`, status dari kedua push button dibaca dan dicetak ke Serial Monitor. Selanjutnya, terdapat sebuah fungsi yang mengatur perilaku LED berdasarkan status push button:

   - Jika `buttonState2` (status dari push button kedua) adalah HIGH, maka LED akan berkedip bergantian dengan interval 0.5 sekon atau 500 ms.
   - Jika `buttonState1` (status dari push button pertama) adalah HIGH, maka kedua LED akan menyala bersamaan.
   - Jika keduanya tidak ditekan, kedua LED dimatikan.

Program ini secara umum memahami input dari push button dan mengendalikan LED sesuai dengan kondisi push button tersebut. 

**Kesimpulan**

Program ini berfungsi menghasilkan efek LED berkedip hanya ketika button ke-2 ditekan, dan hanya menyalakan (tidak berkedip) kedua LED ketika button ke-1 ditekan. Selain itu, kondisi dari setiap button juga tercatat pada serial monitor.

# 4. Membuat Running LED saat penekanan button
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (3 buah)
- Resistor 220 Ohm (3 buah)
- Resistor 10 kOhm (3 buah)
- Push Button (3 buah)

**Skema Rangkaian**

![Skematik Job1 A-5](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/54bbf8d8-14ec-41c8-a6d0-a0d9fb4908b7)


**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%201/A%20(GPIO)/1._Langkah_5.ino/1._Langkah_5.ino.ino">(File .ino)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/8bb99a15-12d1-4099-aa03-b66595a3fdea)


**Flowchart**

![Flowchart Job1 A-5](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/e2619de2-dd2b-4d34-9b21-5f3e86da6693)


**Hasil dan Pembahasan**

![Job 1A_5](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/dba1458c-f8e8-429f-a66c-c3fba2d6dd6d)

Running LED merupakan beberapa lampu LED yang menyala bergantian dengan rapi (kiri ke kanan atau sebaliknya), maka setidaknya dibutuhkan 3 lampu LED untuk menerapkannya.

Program ini mendeklarasikan beberapa pin GPIO untuk push button (`buttonPin1`, `buttonPin2`, dan `buttonPin3`) dan LED (`ledPin1`, `ledPin2`, dan `ledPin3`).

Sebuah array bernama `pinLED` digunakan untuk menyimpan pin dari tiga LED. Penggunaan array pinLED memudahkan pengaturan pin untuk LED, memungkinkan perubahan konfigurasi dengan mudah.

Dalam fungsi `setup()`, pin-pin diatur sesuai dengan fungsinya, yaitu push button sebagai input dan LED sebagai output. 

Dalam fungsi `loop()`, status dari ketiga push button dibaca dan dicetak ke Serial Monitor. Selanjutnya, terdapat kondisional yang mengatur perilaku LED berdasarkan status push button:

   - Jika `buttonState1` (status dari push button pertama) adalah HIGH, maka ketiga LED akan menyala bersamaan.
   - Jika `buttonState2` (status dari push button kedua) adalah HIGH, maka LED 1 dan LED 2 akan berkedip bergantian dengan interval waktu 500 ms.
   - Jika `buttonState3` (status dari push button ketiga) adalah HIGH, maka ketiga LED akan berkedip secara bergantian. Masing-masing LED akan menyala dan mati dengan interval waktu 500 ms.

**Kesimpulan**

Program ini menunjukkan implementasi yang baik dalam mengendalikan beberapa LED dengan beberapa push button. Ketika push button pertama ditekan, ketiga LED akan menyala secara bersamaan. Jika push button kedua ditekan, LED pertama akan menyala, kemudian mati, diikuti oleh LED kedua yang menyala dan mati. Sedangkan saat push button ketiga ditekan, ketiga LED akan berkedip bergantian.
