#include <stdio.h>
#include <stdlib.h>
#include "game_util.h"

/* Prosedur untuk membuat game
 * I.S. Program telah berjalan
 * F.S. Game baru yang dicreate oleh user berhasil ditambahkan pada daftar game.
 */
void createGame(ArrayOfGame *arr, ListMap *L, Map M) //masi bingung pointeer mapnya
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTINPUTKATA();
    if (SearchArrayOfGame((*arr), currentWord) == -1)
    {
        InsertGameAt(arr, currentWord, (*arr).Neff);
        CreateEmptyMap(&M); //membuat map kosong untuk scoreboard
        insertToList(L,M); //menambahkan map ke list scoreboard
        printf("Game berhasil ditambahkan\n");
    }
    else
    {
        printf("Nama game tersebut sudah ada dalam list. Game gagal ditambahkan.\n");
    }
}

/* Prosedur yang menampilkan daftar game
 * I.S. Program telah berjalan
 * F.S. Daftar game yang disediakan oleh sistem tertampil di layar.
 */
void listGame(ArrayOfGame *arr)
{
    /*KAMUS LOKAL*/
    ElTypeArrayOfGame game;
    /*ALGORITMA*/
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i = 0; i < LengthArrayOfGame(*arr); i++)
    {
        game = arr->A[i];
        printf("%d. ", i + 1);
        printf("%s\n", WordToString(game));
    }
}

/* Prosedur untuk menghapus game pada indeks ke-i dari arrayofgame
 * I.S. Program telah berjalan
 * F.S. Game yang dipilih dari daftar game dihapus dengan aturan sebagai berikut:
        - Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna.
        - 5 game pertama pada file konfigurasi tidak dapat dihapus.
        - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.
*/
void deleteGame(ArrayOfGame *arr, Queue qGame)
{
    /*KAMUS LOKAL*/
    IdxTypeArrayOfGame idx;
    listGame(arr);
    ListMap L;
    /*ALGORITMA*/
    printf("Masukkan nomor yang akan dihapus :");
    STARTINPUTKATA();
    int n = WordToInt(currentWord);
    if (n > LengthArrayOfGame(*arr))
    {
        printf("Maaf, nomor yang Anda masukkan melebihi jumlah game yang ada.\n");
    }
    else if (n <= 0)
    {
        printf("Maaf, nomor yang Anda masukkan tidak valid.\n");
    }
    else
    {
        ElTypeArrayOfGame game = GetGame((*arr), n - 1);
        if ((n <= 7) || (isInQueue(qGame, game)))
        {
            printf("Game tidak dapat dihapus\n");
        }
        else
        {
            DeleteGameAt(arr, n - 1);
            deleteAtMap(&L,n);
            printf("Game berhasil dihapus\n");
        }
    }
}

/* Prosedur untuk memasukan game dalam antrian
 * I.S: Program telah berjalan
 * F.S: Jika nomor game yang dipilih ada pada daftar game yang tersedia, maka game
 *      tersebut ditambahkan ke dalam antrian game pengguna.
 *      Jika nomor game yang dipilih tidak ada pada daftar game yang tersedia, maka
 *      ditampilkan pesan error pada layar.
 *      Antrian game ini akan hilang ketika pemain menjalankan command quit.
 */
void queueGame(Queue *qGame, ArrayOfGame arr)
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    printf("Berikut adalah daftar antrian game-mu sekarang: \n");
    displayQueueGame(*qGame);
    printf("\n");
    listGame(&arr);
    printf("\n");
    printf("Nomor game yang akan ditambahkan ke antrian: ");
    STARTINPUTKATA();

    while (WordToInt(currentWord) > LengthArrayOfGame(arr) || WordToInt(currentWord) < 1)
    {
        printf("Nomor game yang Anda masukkan tidak valid. Mohon ulangi.\n");
        printf("Nomor game yang akan ditambahkan ke antrian: ");
        STARTINPUTKATA();
    }

    enqueue(qGame, arr.A[WordToInt(currentWord) - 1]);
    printf("Game berhasil ditambahkan ke antrian\n");
    printf("Sekarang ini adalah list game mu: \n");
    displayQueueGame(*qGame);
}

/* Prosedur untuk menampilkan antrian game yang sudah dimasukan dalam prosedur queuegame
 * I.S : Program telah berjalan.
 * F.S : Menampilkan antrian game pengguna.
 */
void displayQueueGame(Queue qGame)
{
    /*KAMUS LOKAL*/
    int i, temp1, temp2;
    i = 1;
    ElTypeQueue val;
    /*ALGORITMA*/
    if (!isEmpty(qGame))
    {
        while (IDX_HEAD(qGame) != IDX_UNDEF)
        {
            dequeue(&qGame, &val);
            printf("%d. %s\n", i, WordToString(val));
            i++;
        }
    }
}

/* Prosedur untuk memainkan game yang ada dalam daftar permainan.
 * I.S : Program telah berjalan.
 * F.S : Game yang dipilih dimulai jika game tersebut sesuai dengan spesifikasi game.
         Game selain yang dispesifikasikan pada panduan tugas besar akan menampilkan pesan error.
*/
void playGame(Queue *qGame, ArrayOfGame *hist)
{
    /*KAMUS LOKAL*/
    Word game;
    /*ALOGRITMA*/
    printf("Berikut adalah daftar antrian game-mu sekarang: \n");
    displayQueueGame(*qGame);
    if (isEmpty(*qGame))
    {
        printf("Maaf, antrian game-mu kosong. Silakan menambahkan game ke antrian terlebih dahulu dengan mengetik command: QUEUE GAME\n");
    }
    else
    {
        dequeue(qGame, &game);
        if (IsEqual(game, "RNG"))
        {
            printf("Game yang dimainkan adalah RNG\n");
            PushStackChar(hist, "RNG");
            RNG();
        }
        else if (IsEqual(game, "DINER DASH"))
        {
            printf("Game yang dimainkan adalah DINER DASH\n");
            PushStackChar(hist, "DINER DASH");
            DinerDash();
        }
        else if (IsEqual(game, "HANGMAN"))
        {
            printf("Game yang dimainkan adalah HANGMAN\n");
            PushStackChar(hist, "HANGMAN");
            hangMan();
        }
        else if (IsEqual(game, "TOWER OF HANOI"))
        {
            printf("Game yang dimainkan adalah TOWER OF HANOI\n");
            PushStackChar(hist, "TOWER OF HANOI");
            TowerOfHanoi();
        }
        else if (IsEqual(game, "SNAKE ON METEOR"))
        {
            printf("Game yang dimainkan adalah SNAKE ON METEOR\n");
            PushStackChar(hist, "SNAKE ON METEOR");
            SnakeOfMeteor();
        }
        else if (IsEqual(game, "TIC TAC TOE"))
        {
            printf("Game yang dimainkan adalah TIC TAC TOE\n");
            PushStackChar(hist, "TIC TAC TOE");
            tictactoe();
        }
        else
        {
            printf("Game yang dimainkan adalah %s\n", WordToString(game));
            PushStackChar(hist, WordToString(game));
            gameTambahan();
        }
    }
}

/* Prosedur untuk melewatkan game dari daftar antrian sebayak n game.
 * I.S : Program telah berjalan.
 * F.S : Menampilkan antrian game.
 *       Game dilewatkan sebanyak n, lalu game dimulai.
 */
void skipGame(int n, Queue *qGame, ArrayOfGame *hist)
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    printf("Berikut adalah daftar antrian game-mu sekarang: \n");
    displayQueueGame(*qGame);
    printf("\n");
    if (n > length(*qGame))
    {
        if (isEmpty(*qGame))
        {
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        }
        else
        {
            Word skipped;
            for (int i = 0; i <= length(*qGame); i++)
            {
            dequeue(qGame, &skipped); // delete game yang ke n
            }
            printf("Maaf, jumlah game yang ingin dilewati melebihi jumlah game yang ada di antrian. Silakan coba lagi.\n");
        }
    }
    else if (n < 1)
    {
        printf("Maaf, nomor game yang Anda masukkan tidak valid. Nomor game harus lebih dari 0.\n");
    }
    else
    {
        Word skipped;
        for (int i = 0; i < n; i++)
        {
            dequeue(qGame, &skipped); // delete game yang ke n
        }

        Word game;
        if(!isEmpty(*qGame)){
            dequeue(qGame, &game);
            if (IsEqual(game, "RNG"))
            {
                printf("Game yang dimainkan adalah RNG\n");
                PushStackChar(hist, "RNG");
                RNG();
            }
            else if (IsEqual(game, "DINER DASH"))
            {
                printf("Game yang dimainkan adalah DINER DASH\n");
                PushStackChar(hist, "DINER DASH");
                DinerDash();
            }
            else if (IsEqual(game, "HANGMAN"))
            {
                printf("Game yang dimainkan adalah HANGMAN\n");
                PushStackChar(hist, "HANGMAN");
                hangMan();
            }
            else if (IsEqual(game, "TOWER OF HANOI"))
            {
                printf("Game yang dimainkan adalah TOWER OF HANOI\n");
                PushStackChar(hist, "TOWER OF HANOI");
                TowerOfHanoi();
            }
            else if (IsEqual(game, "SNAKE ON METEOR"))
            {
                printf("Game yang dimainkan adalah SNAKE ON METEOR\n");
                PushStackChar(hist, "SNAKE ON METEOR");
                SnakeOfMeteor();
            }
            else if (IsEqual(game, "TIC TAC TOE"))
            {
                printf("Game yang dimainkan adalah TIC TAC TOE\n");
                PushStackChar(hist, "TIC TAC TOE");
                tictactoe();
            }
            else
            {
                printf("Game yang dimainkan adalah %s\n", WordToString(game));
                PushStackChar(hist, WordToString(game));
                gameTambahan();
            }
        }
        else {
            printf("Antrian game mu sudah habis\n");
        }
    }
    printf("Sekarang antrian game-mu adalah : \n");
    displayQueueGame(*qGame);
}

void scoreboard(ListMap L ) {
    printAllList(L); 
}

/* Prosedur untuk menampilkan permainan apa saja yang telah dimainkan
dari data yang sudah ada dari file konfigurasi (jika load) dan dari mulai
Start Game juga, dengan n adalah jumlah permainan yang telah dimainkan yang ingin ditampilkan.
Urutan teratas merupakan permainan terakhir yang dimainkan.
Jika n lebih besar dari jumlah permainan yang telah dimainkan, akan menampilkan seluruh
permainan yang telah dimainkan.
I.S.: Program telah berjalan. 
F.S.: Menampilkan daftar game yang telah dimainkan. */
void history(int n, Stackchar hist) {
    char* X;
    if (n < 1) {
        printf("Mohon masukkan angka yang benar, yaitu lebih dari 0.\n");
    } else {
        printf("Berikut adalah daftar Game yang telah dimainkan\n");
        if (n > Top(hist)) {
            n = Top(hist);
        }
        for (int i=0; i < n; i++) {
            PopStack(&hist, &X);
            printf("%d. %s\n", (i+1), X);
        }
    }
}

/* Prosedur untuk menghapus semua history permainan yang dimainkan. 
I.S.: Program telah berjalan.
F.S.: Menghapus daftar game yang telah dimainkan. */
void resetHistory(Stackchar *hist) {
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
    STARTINPUT();
    if (IsEqual(currentWord, "YA")) {
        CreateEmptyStackChar(hist);
    } else if (IsEqual(currentWord, "TIDAK")) {
        printf("History tidak jadi di-reset. ");
        history(Top(*hist), (*hist));
    } else {
        printf("Mohon masukkan jawaban yang benar.\n");
    }
}