# PWM (Pulse Width Modulation)
Merupakan metode perubahan lebar pulsa untuk menghasilkan nilai tegangan analog yang diinginkan. Pin yang difungsikan sebagai PWM analog
output akan mengeluarkan sinyal pulsa digital dengan frekuensi 5000 Hz yang mana nilai tegangan analog diperoleh dengan mengubah duty cycle atau perbandingan lamanya pulsa HIGH terhadap periode (T) dari sinyal digital tersebut.

`Duty cycle` adalah persentasi panjang pulsa HIGH dalam satu periode sinyal. Ketika duty cycle 0% atau sinyal LOW penuh, maka nilai analog yang dikeluarkan adalah 0 Volt atau setara dengan GND. Begitupun sebaliknya, ketika duty cycle 100% atau sinyal HIGH penuh, maka nilai analog yang dikeluarkan adalah 3.3 Volt.

Terdapat 2 percobaan yang dilakukan :

# 1. Membuat efek fade pada LED Berkedip dengan menggunakan PWM
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (1 buah)
- Resistor 220 Ohm (1 buah)
- Kabel Jumper (secukupnya)

**Skema Rangkaian**

![Skematik (Job 1-B)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/3f0760d2-d9eb-4aab-a234-b688ef62fd7e)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%201/B%20(PWM)/PWM1/PWM1.ino">(File .ino)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/1326d238-dcec-474a-b6df-41129977a31f)

**Flowchart**

![Flowchart Job1 B-1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/dfffb900-8fdf-4bb0-8a5a-53239ca34066)

**Hasil dan Pembahasan**

![Job 1B_1](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/9364bc58-fb14-49c2-b333-051d0a8ef9af)

Program ini memberikan contoh implementasi Pulse Width Modulation (PWM) pada mikrokontroler Arduino untuk mengontrol kecerahan LED. Berikut adalah cara kerjanya:

1. **Konfigurasi PIN:**
   - `ledPin`: Merupakan pin GPIO yang terhubung ke LED dan digunakan untuk mengontrol output PWM. Dalam contoh ini, terhubung ke pin GPIO16.

2. **Konfigurasi PWM:**
   - `freq`: Menyimpan frekuensi PWM yang diinginkan, diukur dalam hertz (Hz). Pada contoh ini, frekuensinya adalah 5000 Hz.
   - `ledChannel`: Menyimpan nomor saluran PWM yang digunakan. Pada mikrokontroler ESP32, terdapat beberapa saluran PWM yang bisa digunakan. Pada contoh ini, menggunakan saluran 0.
   - `resolution`: Menyimpan resolusi PWM dalam bit. Semakin tinggi nilai resolusinya, semakin halus perubahan kecerahan LED. Pada contoh ini, resolusinya adalah 8 bit.

3. **Setup() :**
   - `ledcSetup()`: Mengonfigurasi saluran PWM dengan frekuensi dan resolusi yang telah ditentukan sebelumnya.
   - `ledcAttachPin()`: Menghubungkan saluran PWM dengan pin GPIO yang telah ditentukan (ledPin).

4. **Loop() :**
   - Terdapat dua loop for yang digunakan untuk meningkatkan dan mengurangi kecerahan LED.
   - Dalam setiap loop, nilai PWM (`dutyCycle`) diubah dari 0 hingga 255 dan sebaliknya.
   - `ledcWrite()`: Digunakan untuk menetapkan tingkat kecerahan LED berdasarkan nilai `dutyCycle` tadi.
   - `delay(15)`: Memberikan jeda waktu (delay) 15 milidetik untuk memberikan efek `fade` atau perlahan.

**Kesimpulan**

Program ini menciptakan efek perlahan naik dan turun pada kecerahan LED, yang umumnya digunakan untuk menciptakan efek `fade` atau perubahan cahaya yang halus. Nilai delay dan rentang nilai dutyCycle dapat disesuaikan untuk mengatur kecepatan perubahan dan rentang kecerahan LED.

# 2. Mengendalikan 3 buah LED dengan menggunakan PWM
**Alat dan Bahan**

- ESP32 (1 buah)
- LED (3 buah)
- Resistor 220 Ohm (3 buah)
- Kabel Jumper (secukupnya)

**Skema Rangkaian**

![Skematik (Job 1-B)](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/a0b4743d-f632-4af1-8a28-5b65060eacbb)

**Program** <a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%201/B%20(PWM)/PWM2/PWM2.ino">(File .ino)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/bae3c01b-7cb2-4c14-8680-7968bc11bbae)

**Flowchart**

![Flowchart Job1 B-2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/369cf872-dd94-4084-8ce0-409afbe29897)

**Hasil dan Pembahasan**

![Job 1B_2](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/2bd4008b-b1fa-4960-8ae7-ec75085a26d2)

Pada percobaan kedua ini pada dasarnya sama dengan percobaan pertama, hanya saja terdapat 2 LED tambahan. Untuk itu, kita tambahkan 2 variabel baru untuk menginisialisasi pin GPIO (yaitu GPIO 17 dan GPIO 5). Kemudian kita tambahkan 2 fungsi ledAttachPin() baru untuk mengaktifkan konfigurasi PWM pada 2 pin GPIO tersebut (17 dan 5).

**Kesimpulan**

Program ini menggunakan satu saluran PWM untuk mengendalikan tiga LED, sehingga intensitas cahaya pada ketiganya akan sama karena saling berbagi saluran yang sama. Program memberikan efek cahaya perlahan naik dan turun pada ketiga LED, menciptakan tampilan visual yang menarik. 
