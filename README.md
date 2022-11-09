# BNMO

### IF2111 ALGORITMA DAN STRUKTUR DATA

Deskripsi BNMO

Game ini menggunakan aplikasi abstract data type (ADT) dalam bahasa C

## Struktur Folder
Berikut adalah struktur folder dari project BNMO kami:
- Folder `bin` yang berisi ...
- Folder `Data` yang berisi data data pengguna
- Folder `Docs` yang berisi dokumen-dokumen yang kami gunakan dan perlukan
- Folder `src` yang berisi :
    - folder `ADT` yang berguna untuk menyimpan seluruh ADT yang kami gunakan
    - folder `game_util` yang digunakan untuk menyimpan seluruh utilities dalam game yang kami perlukan (create game, list game, queue game, delete game, play game, skip game)
    - folder `main_util` yang digunakan untuk menyimpan utilities yang diperlukan untuk menyimpan utilities utama (start, load, save, quit, help)
    - folder `games` yang digunakan untuk menyimpan seluruh game kami (RNG dan Diner Dash)
- file `boolean.h` untuk digunakan saat memerlukan header boolean
- file `config.txt` sebagai file awal yang akan dijalankan saat fungsi `start` dijalankan
- program utama kami yang disimpan dalam `main.c`
- file `Makefile` untuk melakukan kompilasi terhadap program utama

## Prosedur Penggunaan
> Program ini dapat dikompilasi dengan Makefile. Sangat disarankan untuk selalu mengompilasi ulang program sebelum digunakan.

### Windows

Program dapat dijalankan di command prompt anda dengan memiliki package make

Package make bisa didapatkan dengan menginstall chocolatey terlebih dahulu.
Untuk langkah-langkah menginstall chocolatey dapat mengikuti link berikut:
https://chocolatey.org/install

Jika chocolatey telah terinstall pada PATH dalam Environmental Variables Device anda, anda dapat melakukan prosedur berikut:
1. Buka Windows powershell dalam device anda dan **run as administrator**

2. Untuk menginstall package make
```
choco install make
```
3. Tunggu hingga package make selesai diinstall and you're good to go.

Setelah package make terinstall, anda dapat mengompilasi program dengan menjalankan prosedur berikut:
1. masuk ke folder IF2111-BNMO yang telah anda download / clone dari github repositorynya.

2. Buka windows terminal dalam folder tersebut.

3. Untuk mengompilasi program ini, anda dapat mengetik 
```
make compile
```

4. Setelah program selesai di-compile, anda dapat mengetik 
```
./main
```

5. Program telah berjalan dan silahkan nikmati perjalanan anda

## Kontributor
Program ini dikembangkan sebagai salah satu tugas besar mata kuliah Algoritma dan Struktur Data. Program ini dikembangkan oleh (K02 Kelompok Al-Stroke-Dead)
1. Rahmah Putri Azzahra `18219052`
    kontrib
2. Vincent Franstyo `18221100`
    kontrib
3. Karina Rahadiani `18221104`
    kontrib
4. Christina Wijaya `18221106`
    kontrib
5. Sultan Alta Alvaro Valencia `18221110`
    kontrib

dengan asisten : Jason Stanley Yoman

## Feature / Command
|No.    |Command        |Status     |
|----   | ------        | -----    |
|1      |Start          | 🗸        |
|2      |Load           | 🗸        |
|3      |Save           | 🗸        |
|4      |Create Game    | 🗸        |
|5      |List Game      | 🗸        |
|6      |Delete Game    | 🗸        |
|7      |Queue Game     | 🗸        |
|8      |Play Game      | 🗸        |
|9      |Skip Game      | 🗸        |
|10     |Quit           | 🗸        |
|11     |Help           | 🗸        |
|12     |Command Lain   | 🗸        |
|13     |RNG            | 🗸        |
|14     |Diner Dash     | 🗸        |


