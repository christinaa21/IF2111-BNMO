// create game, list game, queue game, delete game, play game, skip game
#include <stdio.h>
#include <stdlib.h>

#include "game_util.h"

void createGame(ArrayOfGame *arr){
    printf("Masukkan nama game yang akan ditambahkan: ");
    Word namagame;
    scanf("%[^\n]s", namagame.TabWord);
    printf("\n");
    InsertGameLast(arr,namagame);
    printf("Game berhasil ditambahkan\n");
}
// I.S. Program telah berjalan
// F.S. Game baru yang dicreate oleh user berhasil ditambahkan pada daftar game.

void listGame(ArrayOfGame *arr) {
// I.S. Program telah berjalan
// F.S. Daftar game yang disediakan oleh sistem tertampil di layar.
    ElTypeArrayOfGame game;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i = 0; i < LengthArrayOfGame(*arr); i++) {
        game = arr->A[i];
        printf("%d. ", i);
        printf("%s\n", game.TabWord);
    }
    
}

void deleteGame(ArrayOfGame *arr) {
// I.S. Program telah berjalan
// F.S. Game yang dipilih dari daftar game dihapus dengan aturan sebagai berikut:
//      - Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna.
//      - 5 game pertama pada file konfigurasi tidak dapat dihapus.
//      - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.
    IdxTypeArrayOfGame idx;
    listGame(arr);
    printf("Masukkan nomor yang akan dihapus :");
    scanf("%d", &idx);
    if (idx <= 5) {
        printf("Game tidak");
    } 
    // case game ada pada queue
    // else if () {}
    else {
        DeleteGameAt(arr, (idx-1));
        printf("Game berhasil dihapus\n");
    }
    
    
}

void queueGame(Queue *qGame, ArrayOfGame arr);
// I.S. Program telah berjalan
// F.S. Jika nomor game yang dipilih ada pada daftar game yang tersedia, maka game
//      tersebut ditambahkan ke dalam antrian game pengguna.
//      Jika nomor game yang dipilih tidak ada pada daftar game yang tersedia, maka
//      ditampilkan pesan error pada layar.
//      Antrian game ini akan hilang ketika pemain menjalankan command quit.

void displayQueueGame();
// I.S. Program telah berjalan
// F.S. Menampilkan antrian game pengguna.

void playGame(Queue *qGame) {
    int game;
    displayQueueGame();
    if (isEmpty(*qGame)) {
        printf("Maaf, antrian game-mu kosong. Silakan menambahkan game ke antrian terlebih dahulu dengan mengetik command: QUEUE GAME\n");
    } else {
        /* Asumsi: Game yg ada di qGame merupakan nomor-nomor game yang ada di List Game.
                    Game nomor 1-5 mengikuti game yang ada di file konfigurasi, yaitu:
                    1 = RNG
                    2 = Diner Dash
                    3 = Dinosaur in earth
                    4 = Risewoman
                    5 = Eiffel Tower */
        dequeue(qGame, &game);
        if (game == 1) {
            RNG();
        } else if (game == 2) {
            DinerDash();
        } else if (game >= 3) {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n");
        } else if (game >= 4) {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n");
        } else if (game >= 5) {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n");
        } else {
            gameTambahan();
        }
    }
}
// I.S. Program telah berjalan
// F.S. Game yang dipilih dimulai jika game tersebut sesuai dengan spesifikasi game.
//      Game selain yang dispesifikasikan pada panduan tugas besar akan menampilkan pesan error.

void skipGame(ArrayOfGame *arr, int n){ 
    // belum di cek lagi bentar gais
    //jujur masih bingung cara baca <n> nya
    displayQueueGame(); 
    if (n > LengthArrayOfGame(*arr)) {
        printf("Tidak ada permainan lagi dalam daftar game-mu.");
     } else if (n<1) {
        printf("Maaf, nomor game yang Anda masukkan tidak valid. Nomor game harus lebih dari 0.");
    } else {
        for (int i =0; i<n; i++){
            DeleteAt(arr, n+1); // delete game yang ke n
            }
        }
    }
// I.S. Program telah berjalan
// F.S. Game dilewatkan sebanyak n, lalu game dimulai.