#include <stdio.h>
#include <stdlib.h>

#ifndef _GAME_UTIL_h
#define _GAME_UTIL_h

#include "../ADT/queue/queue.h"
#include "../ADT/array/arraydin.h"
#include "../ADT/map/map.h"
#include "../ADT/map/listMap.h"
#include "../ADT/stackchar/stackchar.h"
#include "../ADT/arrayOfGame/arrayOfGame.h"
#include "../games/diner_dash/diner_dash.h"
#include "../games/random_number_generator/random_number_generator.h"
#include "../games/game_tambahan/game_tambahan.h"
#include "../games/hangman/hangman.h"
#include "../games/TicTacToe/tictactoe.h"
#include "../games/SnakeOnMeteor/snakeonmeteor.h"
#include "../games/TowerOfHanoi/TowerOfHanoi.h"

/* Prosedur untuk membuat game
 * I.S. Program telah berjalan
 * F.S. Game baru yang dicreate oleh user berhasil ditambahkan pada daftar game.
 */
void createGame(ArrayOfGame *arr, ListMap *L, Map *M);

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
void deleteGame(ArrayOfGame *arr, Queue qGame, ListMap *L);

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
void playGame(ArrayOfGame arr, Queue *qGame, Stackchar *hist, ListMap *L);

/* Prosedur untuk melewatkan game dari daftar antrian sebayak n game.
 * I.S : Program telah berjalan.
 * F.S : Menampilkan antrian game.
 *       Game dilewatkan sebanyak n, lalu game dimulai.
 */
void skipGame(int n, ArrayOfGame arr, Queue *qGame, Stackchar *hist, ListMap *L);

/* Prosedur untuk menampilkan permainan apa saja yang telah dimainkan
dari data yang sudah ada dari file konfigurasi (jika load) dan dari mulai
Start Game juga, dengan n adalah jumlah permainan yang telah dimainkan yang ingin ditampilkan.
Urutan teratas merupakan permainan terakhir yang dimainkan.
Jika n lebih besar dari jumlah permainan yang telah dimainkan, akan menampilkan seluruh
permainan yang telah dimainkan.
I.S.: Program telah berjalan. 
F.S.: Menampilkan daftar game yang telah dimainkan. */
void history(int n, Stackchar hist);

/* Prosedur untuk menghapus semua history permainan yang dimainkan. 
I.S.: Program telah berjalan.
F.S.: Menghapus daftar game yang telah dimainkan. */
void resetHistory(Stackchar *hist);

/* Prosedur untuk menampilkan scoreboard dari masing-masing game.
 * Setiap scoreboard dari masing-masing game akan direpresentasikan dengan map, dan digabungkan menjadi list of map
 I.S : Program telah berjalan. 
 F.S : Menampilkan daftar scoreboard dari masing-masing game. */
void scoreboard(ListMap L, ArrayOfGame arr);

/* Prosedur untuk menghapus semua atau sebagian scoreboard.
I.S : Program telah berjalan
F.S : Menghapus semua, sebagian, atau tidak sama sekali scoreboard sesuai dengan input user*/
void resetScoreboard (ListMap *L, ArrayOfGame *arr);
#endif