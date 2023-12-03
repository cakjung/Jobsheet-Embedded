# Switch Node
Pada percobaan ini kita akan menggunakan `switch node` untuk memproses suatu data yang akan dikirimkan.

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red

Node :
- Inject (2 buah)
- Debug (2 buah)
- Switch (1 buah)

### Program 
<a href="https://github.com/cakjung/Jobsheet-Embedded/blob/main/Jobsheet%205/C%20(Switch%20Node)/flows%20(Job%205-C).json">(File flows.json)</a>

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/eebc83b6-18fe-4ca4-b4cb-3445791de972)

### Flowchart

![Flowchart Job 5-C](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/78ebac3e-bcd2-4586-ba8d-24e11a950022)

### Hasil dan Pembahasan

![Job 5-C](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/563102b4-0adf-4fb9-835f-bb0deede2f82)

Berbeda dengan node `function`, untuk memproses data pada node `switch` tidak memerlukan pemrograman sama sekali. Kita hanya menambahkan `action` atau aksi untuk dapat melakukan pemrosesan data. 

Ada berbagai macam action yang dapat dilakukan:

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/75ceffd6-3f55-4449-94a7-37985edbbae7)

Karena pada percobaan ini kita hanya menentukan apakah jumlah inputan angka melebihi atau kurang dari 28, maka kita hanya menambahkan 2 aksi, yaitu > dan <=. Kemudian kita masukkan angka 28 pada kolom input, dan pastikan tipe data yang dipilih adalah number.

![image](https://github.com/cakjung/Jobsheet-Embedded/assets/128274951/77dce191-de5e-4322-9b91-17c04d7be7e6)

Aksi pertama akan meneruskan pesan ke output pertama jika benar, sedangkan apabila yang benar adalah aksi kedua, maka pesan akan diteruskan ke output kedua.

### Kesimpulan

Switch node berfungsi untuk merubah atau memodifikasi pesan atau data agar sesuai dengan apa yang kita inginkan, dimana kita hanya perlu menambahkan aksi saja tanpa perlu melakukan coding atau pemrograman seperti pada function node.
