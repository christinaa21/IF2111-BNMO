#include <stdio.h>
#include <stdlib.h>

#ifndef _GAME_UTIL_h
#define _GAME_UTIL_h

#include "../ADT/queue/queue.h"
#include "../ADT/array/arraydin.h"
#include "../ADT/arrayOfGame/arrayOfGame.h"
#include "../games/diner_dash/diner_dash.h"
#include "../games/random_number_generator/random_number_generator.h"
#include "../games/game_tambahan/game_tambahan.h"

void createGame(ArrayOfGame *arr);
// I.S. Program telah berjalan
// F.S. Game baru yang dicreate oleh user berhasil ditambahkan pada daftar game.

/**
 * Menampilkan list game yang tersedia
 * I.S. Program telah berjalan
 * F.S. Daftar game yang disediakan oleh sistem tertampil di layar.
 */
void listGame(ArrayOfGame *arr);

/**
 * Menghapus game dari list game yang tersedia
 * I.S. Program telah berjalan
 * F.S. Game yang dipilih dari daftar game dihapus dengan aturan sebagai berikut:
 *      - Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna.
 *      - 5 game pertama pada file konfigurasi tidak dapat dihapus.
 *      - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.
 */
void deleteGame(ArrayOfGame *arr);

/**
 * Menambahkan game dari list game ke antrian game yang akan dimainkan
 * I.S. Program telah berjalan
 * F.S. Jika nomor game yang dipilih ada pada daftar game yang tersedia, maka game
 *      tersebut ditambahkan ke dalam antrian game pengguna.
 *      Jika nomor game yang dipilih tidak ada pada daftar game yang tersedia, maka
 *      ditampilkan pesan error pada layar.
 *      Antrian game ini akan hilang ketika pemain menjalankan command quit.
 */
void queueGame(Queue *qGame, ArrayOfGame arr);

void displayQueueGame();
// I.S. Program telah berjalan
// F.S. Menampilkan antrian game pengguna.

void playGame();
// I.S. Program telah berjalan
// F.S. Game yang dipilih dimulai jika game tersebut sesuai dengan spesifikasi game.
//      Game selain yang dispesifikasikan pada panduan tugas besar akan menampilkan pesan error.

void skipGame();
// I.S. Program telah berjalan
// F.S. Game dilewatkan sebanyak n, lalu game dimulai.

#endif