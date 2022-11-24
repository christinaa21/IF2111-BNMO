#include <stdio.h>
#include <stdlib.h>

#ifndef _GAME_UTIL_h
#define _GAME_UTIL_h

#include "../ADT/queue/queue.h"
#include "../ADT/array/arraydin.h"
#include "../ADT/map/map.h"
#include "../ADT/map/listMap.h"
#include "../ADT/arrayOfGame/arrayOfGame.h"
#include "../games/diner_dash/diner_dash.h"
#include "../games/random_number_generator/random_number_generator.h"
#include "../games/game_tambahan/game_tambahan.h"
#include "../games/hangman/hangman.h"
#include "../games/TicTacToe/tictactoe.h"

/* Prosedur untuk membuat game
 * I.S. Program telah berjalan
 * F.S. Game baru yang dicreate oleh user berhasil ditambahkan pada daftar game.
 */
void createGame(ArrayOfGame *arr);

/* Prosedur yang menampilkan daftar game
 * I.S. Program telah berjalan
 * F.S. Daftar game yang disediakan oleh sistem tertampil di layar.
 */
void listGame(ArrayOfGame *arr);

/* Prosedur untuk menghapus game pada indeks ke-i dari arrayofgame
 * I.S. Program telah berjalan
 * F.S. Game yang dipilih dari daftar game dihapus dengan aturan sebagai berikut:
        - Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna.
        - 5 game pertama pada file konfigurasi tidak dapat dihapus.
        - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.
*/
void deleteGame(ArrayOfGame *arr, Queue qGame);

/* Prosedur untuk memasukan game dalam antrian
 * I.S: Program telah berjalan
 * F.S: Jika nomor game yang dipilih ada pada daftar game yang tersedia, maka game
 *      tersebut ditambahkan ke dalam antrian game pengguna.
 *      Jika nomor game yang dipilih tidak ada pada daftar game yang tersedia, maka
 *      ditampilkan pesan error pada layar.
 *      Antrian game ini akan hilang ketika pemain menjalankan command quit.
 */
void queueGame(Queue *qGame, ArrayOfGame arr);

/* Prosedur untuk menampilkan antrian game yang sudah dimasukan dalam prosedur queuegame
 * I.S : Program telah berjalan.
 * F.S : Menampilkan antrian game pengguna.
 */
void displayQueueGame(Queue qGame);

/* Prosedur untuk memainkan game yang ada dalam daftar permainan.
 * I.S : Program telah berjalan.
 * F.S : Game yang dipilih dimulai jika game tersebut sesuai dengan spesifikasi game.
         Game selain yang dispesifikasikan pada panduan tugas besar akan menampilkan pesan error.
*/
void playGame(Queue *qGame);

/* Prosedur untuk melewatkan game dari daftar antrian sebayak n game.
 * I.S : Program telah berjalan.
 * F.S : Menampilkan antrian game.
 *       Game dilewatkan sebanyak n, lalu game dimulai.
 */
void skipGame(int n, Queue *qGame);

#endif