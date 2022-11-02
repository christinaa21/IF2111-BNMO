// create game, list game, queue game, delete game, play game, skip game
#include <stdio.h>
#include <stdlib.h>

#include "game_util.h"

void createGame(ArrayOfGame *arr){
    printf("Masukkan nama game yang akan ditambahkan: ");
    Word namagame;
    scanf("%[^\n]s", namagame.TabWord);
    printf("\n");
    InsertGameLast(&arr,namagame);
    printf("Game berhasil ditambahkan\n");
}
// I.S. Program telah berjalan
// F.S. Game baru yang dicreate oleh user berhasil ditambahkan pada daftar game.

void listGame(ArrayOfGame *arr);
// I.S. Program telah berjalan
// F.S. Daftar game yang disediakan oleh sistem tertampil di layar.

void deleteGame(ArrayOfGame *arr);
// I.S. Program telah berjalan
// F.S. Game yang dipilih dari daftar game dihapus dengan aturan sebagai berikut:
//      - Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna.
//      - 5 game pertama pada file konfigurasi tidak dapat dihapus.
//      - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.

void queueGame(Queue *qGame);
// I.S. Program telah berjalan
// F.S. Jika nomor game yang dipilih ada pada daftar game yang tersedia, maka game
//      tersebut ditambahkan ke dalam antrian game pengguna.
//      Jika nomor game yang dipilih tidak ada pada daftar game yang tersedia, maka
//      ditampilkan pesan error pada layar.
//      Antrian game ini akan hilang ketika pemain menjalankan command quit.

void displayQueueGame();
// I.S. Program telah berjalan
// F.S. Menampilkan antrian game pengguna.

void playGame(Queue qGame) {
    int game;
    displayQueueGame();
    printf("ENTER GAME: ");
    scanf("%d", &game);
    printf("\n");
    if (isEmpty(qGame)) {
        printf("Maaf, antrian game-mu kosong. Silakan menambahkan game ke antrian terlebih dahulu dengan mengetik command: QUEUE GAME\n");
    } else {
        if (game > length(qGame)) {
            printf("Maaf, nomor game yang Anda masukkan lebih dari jumlah antrian game yang Anda miliki.\nSilakan masukkan nomor game yang sesuai.\n");
        } else if (game < 1) {
            printf("Maaf, nomor game yang Anda masukkan tidak valid. Nomor game harus lebih dari 0.");
        } else {
            /* Asumsi: Game yg ada di qGame merupakan nomor-nomor game yang ada di List Game.
                       Game nomor 1-5 mengikuti game yang ada di file konfigurasi, yaitu:
                       1 = RNG
                       2 = Diner Dash
                       3 = Dinosaur in earth
                       4 = Risewoman
                       5 = Eiffel Tower */
            if (qGame.buffer[game-1] == 1) {
                RNG();
            } else if (qGame.buffer[game-1] == 2) {
                DinerDash();
            } else if (qGame.buffer[game-1] >= 3) {
                printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n");
            } else if (qGame.buffer[game-1] >= 4) {
                printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n");
            } else if (qGame.buffer[game-1] >= 5) {
                printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n");
            } else {
                gameTambahan();
            }
        }
    }
}
// I.S. Program telah berjalan
// F.S. Game yang dipilih dimulai jika game tersebut sesuai dengan spesifikasi game.
//      Game selain yang dispesifikasikan pada panduan tugas besar akan menampilkan pesan error.

void skipGame();
// I.S. Program telah berjalan
// F.S. Game dilewatkan sebanyak n, lalu game dimulai.