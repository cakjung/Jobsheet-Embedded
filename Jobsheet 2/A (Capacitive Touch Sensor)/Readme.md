# ESP32 Capacitive Touch Sensor
Melakukan ujicoba kontrol LED pada ESP32 menggunakan input berupa sentuhan. Terdapat 5 percobaan yang dilakukan, diantaranya:

## 1. Membaca data input yang berupa sentuhan

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)

### Skema Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/f172e71d-7663-476e-b929-b32ce02d00b5)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/tree/main/Jobsheet%202/A%20(Capacitive%20Touch%20Sensor)/Job%202-A_1/Job_2-A_1.ino"> File .ino </a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/1450a2ac-7aea-4e1e-9ffd-c59da7d0bd37)

### Flowchart

![Flowchart Job 2-A 1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/6e549d6e-be9d-49d4-bd70-7e5236a04f59)

### Hasil dan Pembahasan

![Job-2-A_1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/00dd0ecd-e43b-4f3e-909d-f6e0fc4cb13c)

Program ini adalah contoh penggunaan fitur *touch* pada ESP32. Fitur ini memungkinkan ESP32 membaca nilai dari sensor sentuh yang terhubung ke pin tertentu. Fungsi yang digunakan untuk membuat sensor ini adalah `touchRead()`. Nilai input tersebut akan ditampilkan pada Serial Monitor. Berikut analisis singkat dari program:

**A. Setup Komunikasi Serial:**

```cpp
Serial.begin(115200); // komunikasi ini akan digunakan untuk membaca data lewat `serial monitor`
delay(1000);
```
   - Baudrate serial diatur pada 115200 bps.
   - Terdapat delay sebesar 1000 ms untuk memberikan waktu ESP32 untuk stabil.

**B. Loop:**

```cpp
Serial.println(touchRead(4));
delay(1000);
```
   - Pada setiap iterasi, nilai dari input berupa sentuhan yang terhubung ke pin GPIO 4 dibaca menggunakan fungsi `touchRead(4)`.
   - Nilai tersebut kemudian ditampilkan melalui Serial Monitor.
   - Terdapat delay 1000 ms untuk memberikan interval waktu antar pembacaan.

Jika tidak terdapat input yang terbaca, maka garis pada grafik akan naik. Sedangkan jika terdapat sentuhan, maka garis akan turun ke level tertentu. Fungsi touchRead() sendiri memiliki nilai analog yang berkisar antara 0 hingga 1023. Angka tersebut akan direpresentasikan sesuai dengan grafik pada serial monitor.

### Kesimpulan
Variasi nilai yang ditampilkan menunjukkan level sentuhan pada sensor. Perlu dipahami bahwa nilai yang dibaca dari sensor sentuh bersifat relatif dan dapat bervariasi, hal ini bisa disebabkan oleh faktor lingkungan atau alat dan komponen yang digunakan.

## 2. Menyalakan LED dengan sensor sentuh

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (1 buah)
- Lampu LED (1 buah)

### Skema Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/f172e71d-7663-476e-b929-b32ce02d00b5)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%202/A%20(Capacitive%20Touch%20Sensor)/Job%202-A_2/Capacitive_Touch_Sensor/Capacitive_Touch_Sensor.ino"> File .ino </a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/26630fd3-0d41-4456-b54c-63b9c148660d)

### Flowchart

![Flowchart Job 2-A 2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/54eb4735-b853-46e7-bff4-e5295cafd7af)

### Hasil dan Pembahasan

![Job-2-A_2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/176d258e-1789-458f-9c60-0adb591cf1d3)

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menyalakan atau mematikan LED. Berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int touchPin = 4;
const int ledPin = 16;
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, yang merupakan pin untuk mengendalikan LED.

**B. Setup():**

```cpp
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
delay(1000);
```
   - `ledPin` diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.
   - Terdapat delay awal 1000 ms untuk memastikan kestabilan ESP32.

**C. Loop():**

```cpp
touchValue = touchRead(touchPin); // memasukkan nilai input (sentuhan) ke variabel baru
Serial.print(touchValue);
delay(500);

if (touchValue == 0) {
  digitalWrite (ledPin, HIGH);
} else {
  digitalWrite (ledPin, LOW);
}
delay(1000);
```
   - Nilai dari sensor sentuh (`touchValue`) dibaca menggunakan fungsi `touchRead(touchPin)`.
   - Nilai tersebut ditampilkan pada Serial Monitor.
   - Jika sensor sentuh mendeteksi sentuhan (nilai sama dengan 0), maka LED akan menyala.
   - Jika sensor sentuh tidak mendeteksi sentuhan (nilai tidak sama dengan 0), maka LED akan mati.

### Kesimpulan
Untuk menyalakan LED dibutuhkan nilai acuan untuk penanda dimana LED akan menyala dan LED akan mati. Karena fungsi dari touchread sendiri memiliki nilai analog (0 - 1023).

## 3. Membuat Blink LED dengan sensor sentuh

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (1 buah)
- Lampu LED (1 buah)

### Skema Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/f172e71d-7663-476e-b929-b32ce02d00b5)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%202/A%20(Capacitive%20Touch%20Sensor)/Job%202-A_3/Capacitive_Touch_Sensor_Blink/Capacitive_Touch_Sensor_Blink.ino"> File .ino </a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/5ff4f955-c982-48e3-aff1-dc90ad5be468)

### Flowchart

![Flowchart Job 2-A 3](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/c9655e7d-6d3a-439c-9891-d4c11d35deaa)

### Hasil dan Pembahasan

![Job-2-A_3](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/493fea73-d2a5-411c-ad73-985dc987927c)

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menyalakan LED (Blink) atau mematikan LED. Berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int touchPin = 4;
const int ledPin = 16;
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, yang merupakan pin untuk mengendalikan LED.

**B. Setup():**

```cpp
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
delay(1000);
```
   - `ledPin` diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.
   - Terdapat delay awal 1000 ms untuk memastikan kestabilan ESP32.

**C. Loop():**

```cpp
touchValue = touchRead(touchPin); // memasukkan nilai input (sentuhan) ke variabel baru
Serial.print(touchValue);
delay(500);

if (touchValue <= 30) {
  digitalWrite (ledPin, HIGH);
  delay(1000);
  digitalWrite (ledPin, LOW);
  delay(1000);
} else {
  digitalWrite (ledPin, LOW);
}
delay(1000);
```
   - Nilai dari sensor sentuh (`touchValue`) dibaca menggunakan fungsi `touchRead(touchPin)`.
   - Nilai tersebut ditampilkan pada Serial Monitor.
   - Jika sensor sentuh mendeteksi sentuhan (nilai kurang dari sama dengan 30), maka LED akan menyala (Blink).
   - Jika sensor sentuh tidak mendeteksi sentuhan (nilai lebih dari 30), maka LED akan mati.

### Kesimpulan
Berbeda dengan program sebelumnya, program kali ini lebih sensitif. Hal ini disebabkan nilai acuannya ditingkatkan menjadi 30 (analog), sehingga pembacaan sentuhan pada sensor akan lebih akurat dan cepat.

## 4. Menghitung jumlah sentuhan

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (1 buah)
- Lampu LED (1 buah)

### Skema Rangkaian

![image](https://github.com/alfan459/Embedded-System/assets/54757609/f172e71d-7663-476e-b929-b32ce02d00b5)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%202/A%20(Capacitive%20Touch%20Sensor)/Job%202-A_4/Capacitive_Touch_Sensor_disentuh_bertambah/Capacitive_Touch_Sensor_disentuh_bertambah.ino"> File .ino </a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/698086dc-f4c7-4154-8fa7-b50c692ca044)

### Flowchart

![Flowchart Job 2-A 4](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a203cd8b-64c2-438c-a985-56fd5ffba281)

### Hasil dan Pembahasan

![Job-2-A_4](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/84294871-20f8-4c7f-ac81-aa0a3085b327)

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menampilkan jumlah sentuhan pada layar serial monitor. Untuk itu terdapat beberapa perubahan pada program, berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int ledPin = 16;
const int touchPin = 4;
int touchValue = 0; 
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, yang merupakan pin untuk mengendalikan LED.
   - `touchValue` digunakan sebagai variabel untuk menghitung atau *Counter* jumlah sentuhan.

**B. Setup():**

```cpp
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
```
   - `ledPin` diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.

**C. Loop():**

```cpp
touchValue = touchRead(touchPin); // memasukkan nilai input (sentuhan) ke variabel baru
Serial.print(touchValue);
delay(500);

if (touchRead(touchPin) <= 30) {
    touchValue++; // Menambah touchValue ketika sensor disentuh
    digitalWrite(ledPin, HIGH); // Nyalakan LED ketika sensor disentuh
    delay(1000); // Tahan LED selama 1 detik
    digitalWrite(ledPin, LOW); // Matikan LED
    delay(1000); // Tunggu selama 1 detik
  }

  Serial.println("jumlah sentuhan = " + String(touchValue)); // Tampilkan touchValue di Serial Monitor
  delay(500);
```
   - Jika sensor sentuh (`touchPin`) mendeteksi sentuhan, maka program akan melakukan beberapa tindakan:
     - Menambah nilai `touchValue` sebanyak 1.
     - Menyalakan LED (`ledPin`).
     - Menampilkan informasi sentuhan ke Serial Monitor.
     - Menunggu 500 ms untuk menghindari deteksi berulang.
   - Jika sensor sentuh tidak mendeteksi sentuhan, maka LED dimatikan.
     
### Kesimpulan
Untuk menambahkan sebuah nilai variable dapat dilakukan dengan increment (++), salah satu contoh pemanfaatannya adalah pada program *Counter*

## 5. Menyalakan running LED dengan sentuhan

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (3 buah)
- Lampu LED (3 buah)

### Skema Rangkaian

![Skematik (Job 2-A 5)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/16075eb2-dfc3-4437-9e54-4e57ba034ec5)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/tree/main/Jobsheet%202/A%20(Capacitive%20Touch%20Sensor)/Job%202-A_5/Capacitive_Touch_Sensor_RunLED"> File .ino </a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/0e56b801-2c24-4425-a824-d41976fae866)

### Flowchart

![Flowchart Job 2-A 5](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/4f75bd93-e8c4-4c68-8830-534bc274abb4)

### Hasil dan Pembahasan

![Job-2-A_5](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/14dbfb6f-f935-42c5-8eb1-2c887cab333b)

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menyalakan LED (Running) atau mematikan LED. Berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int ledPin = 16;
const int ledPin1 = 18;
const int ledPin2 = 19;
const int touchPin = 4;
const int numLED = 3;
const int pinLED[numLED] = {16,18,19};
int touchValue = 0;
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, 18, dan 19, yang merupakan pin untuk mengendalikan LED 1, 2, dan 3.
   - 'pinLed' digunakan untuk menambahkan ketiga LED kedalam sebuah array.

**B. Setup():**

```cpp
Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT); // LED kedua
  pinMode(ledPin2, OUTPUT); // LED ketiga
  for(int i=0; i<3; i++){
   pinMode(pinLED[i], OUTPUT);
  }
```
   - `ledPin` dan 'pinLED' diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.

**C. Loop():**

```cpp
if (touchRead(touchPin) <= 30) {
    touchValue++; // Menambah touchValue ketika sensor disentuh
    for (int i = 0; i < 3; i++) { // pengulangan tindakan pada ketiga LED
      digitalWrite(pinLED[i], HIGH);
      delay(500);
      digitalWrite(pinLED[i], LOW);
    }
  } else {
    // matikan LED
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  Serial.println("jumlah sentuhan = " + String(touchValue)); // Tampilkan touchValue di Serial Monitor
  delay(500);
```
   - Jika sensor sentuh (`touchPin`) mendeteksi sentuhan, maka program akan melakukan beberapa tindakan:
     - Melakukan looping for untuk menyalakan LED (Running):
       - Ketika nilai i = 0 (iterasi for pertama), menyalakan dan mematikan LED pertama.
       - Ketika nilai i = 1 (iterasi for kedua), menyalakan dan mematikan LED kedua.
       - Ketika nilai i = 2 (iterasi for ketiga), menyalakan dan mematikan LED ketiga.
   - Jika sensor sentuh tidak mendeteksi sentuhan, maka semua LED tidak akan menyala.
   - Menampilkan jumlah sentuhan terbaru (jika ada)

### Kesimpulan
Selain diimplementasikan untuk membuat blink LED, touchRead() juga dapat dikembangkan untuk membuat rangkaian running LED.
