#include <stdio.h>
#include <stdlib.h>
#include "game_util.h"

/* Prosedur untuk membuat game
 * I.S. Program telah berjalan
 * F.S. Game baru yang dicreate oleh user berhasil ditambahkan pada daftar game.
 */
void createGame(ArrayOfGame *arr, ListMap *L, Map *M) // masi bingung pointeer mapnya
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTINPUTKATA();
    if (SearchArrayOfGameUnique((*arr), currentWord) == -1)
    {
        InsertGameAt(arr, currentWord, (*arr).Neff);
        CreateEmptyMap(M);   // membuat map kosong untuk scoreboard
        insertToList(L, *M); // menambahkan map ke list scoreboard
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
void deleteGame(ArrayOfGame *arr, Queue qGame, ListMap *L, Stackchar *hist)
{
    /*KAMUS LOKAL*/
    IdxTypeArrayOfGame idx;
    Stackchar hist_copy;
    infotypeStackchar X;
    int i, j;
    /*ALGORITMA*/
    listGame(arr);
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
        if ((n <= 6) || (isInQueue(qGame, game)))
        {
            printf("Game tidak dapat dihapus\n");
        }
        else
        {
            DeleteGameAt(arr, n - 1);
            deleteListMapAt(L, n);
            CreateEmptyStackChar(&hist_copy);
            j = TopStackchar(*hist);
            for (i=0;i<=j;i++) {
                PopStackChar(hist, &X);
                if (!IsEqual(game, X)) {
                    PushStackChar(&hist_copy, X);
                }
            }
            CopyStackChar(hist_copy, hist);
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
void playGame(ArrayOfGame arr, Queue *qGame, Stackchar *hist, ListMap *L)
{
    /*KAMUS LOKAL*/
    Word game;
    int score, idx;
    char *nama;
    char* cek_nama;
    boolean invalid = true;
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
            RNG(&score);
        }
        else if (IsEqual(game, "DINER DASH"))
        {
            printf("Game yang dimainkan adalah DINER DASH\n");
            PushStackChar(hist, "DINER DASH");
            DinerDash(&score);
        }
        else if (IsEqual(game, "HANGMAN"))
        {
            printf("Game yang dimainkan adalah HANGMAN\n");
            PushStackChar(hist, "HANGMAN");
            hangMan(&score);
        }
        else if (IsEqual(game, "TOWER OF HANOI"))
        {
            printf("Game yang dimainkan adalah TOWER OF HANOI\n");
            PushStackChar(hist, "TOWER OF HANOI");
            TowerOfHanoi(&score);
        }
        else if (IsEqual(game, "SNAKE ON METEOR"))
        {
            printf("Game yang dimainkan adalah SNAKE ON METEOR\n");
            PushStackChar(hist, "SNAKE ON METEOR");
            SnakeOnMeteor(&score);
        }
        else if (IsEqual(game, "TIC TAC TOE"))
        {
            printf("Game yang dimainkan adalah TIC TAC TOE\n");
            PushStackChar(hist, "TIC TAC TOE");
            tictactoe(&score);
        }
        else
        {
            printf("Game yang dimainkan adalah %s\n", WordToString(game));
            PushStackChar(hist, WordToString(game));
            gameTambahan(&score);
        }
        printf("Skor akhir: %d\n", score);
        while (invalid) {
            printf("Nama: ");
            STARTINPUTKATA();
            nama = WordToString(currentWord);
            cek_nama = WordToString(currentWord);
            idx = SearchArrayOfGame(arr, game);
            invalid = IsMemberMapUnique((*L).peta[idx], cek_nama);
            if (invalid)
            {
                printf("Nama pengguna tersebut sudah ada di scoreboard. Silakan input nama yang berbeda!\n");
            }
            else
            {
                InsertMap(&(*L).peta[idx], nama, score);
                printf("Namamu berhasil ditambahkan ke scoreboard!\n");
            }
        }
    }
}

/* Prosedur untuk melewatkan game dari daftar antrian sebayak n game.
 * I.S : Program telah berjalan.
 * F.S : Menampilkan antrian game.
 *       Game dilewatkan sebanyak n, lalu game dimulai.
 */
void skipGame(int n, ArrayOfGame arr, Queue *qGame, Stackchar *hist, ListMap *L)
{
    /*KAMUS LOKAL*/
    int score, idx;
    char *nama;
    char* cek_nama;
    boolean invalid = true;
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
            for (int i = 0; i < length(*qGame); i++)
            {
                dequeue(qGame, &skipped); // delete game yang ke n
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
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
        if (!isEmpty(*qGame))
        {
            dequeue(qGame, &game);
            if (IsEqual(game, "RNG"))
            {
                printf("Game yang dimainkan adalah RNG\n");
                PushStackChar(hist, "RNG");
                RNG(&score);
            }
            else if (IsEqual(game, "DINER DASH"))
            {
                printf("Game yang dimainkan adalah DINER DASH\n");
                PushStackChar(hist, "DINER DASH");
                DinerDash(&score);
            }
            else if (IsEqual(game, "HANGMAN"))
            {
                printf("Game yang dimainkan adalah HANGMAN\n");
                PushStackChar(hist, "HANGMAN");
                hangMan(&score);
            }
            else if (IsEqual(game, "TOWER OF HANOI"))
            {
                printf("Game yang dimainkan adalah TOWER OF HANOI\n");
                PushStackChar(hist, "TOWER OF HANOI");
                TowerOfHanoi(&score);
            }
            else if (IsEqual(game, "SNAKE ON METEOR"))
            {
                printf("Game yang dimainkan adalah SNAKE ON METEOR\n");
                PushStackChar(hist, "SNAKE ON METEOR");
                SnakeOnMeteor(&score);
            }
            else if (IsEqual(game, "TIC TAC TOE"))
            {
                printf("Game yang dimainkan adalah TIC TAC TOE\n");
                PushStackChar(hist, "TIC TAC TOE");
                tictactoe(&score);
            }
            else
            {
                printf("Game yang dimainkan adalah %s\n", WordToString(game));
                PushStackChar(hist, WordToString(game));
                gameTambahan(&score);
            }
            printf("Skor akhir: %d\n", score);
            while (invalid) {
                printf("Nama: ");
                STARTINPUTKATA();
                nama = WordToString(currentWord);
                cek_nama = WordToString(currentWord);
                idx = SearchArrayOfGame(arr, game);
                invalid = IsMemberMapUnique((*L).peta[idx], cek_nama);
                if (invalid)
                {
                    printf("Nama pengguna tersebut sudah ada di scoreboard. Silakan input nama yang berbeda!\n");
                }
                else
                {
                    InsertMap(&(*L).peta[idx], nama, score);
                    printf("Namamu berhasil ditambahkan ke scoreboard!\n");
                }
            }
        }
        else
        {
            printf("Antrian game mu sudah habis\n");
        }
    }
    printf("Sekarang antrian game-mu adalah : \n");
    displayQueueGame(*qGame);
}

/* Prosedur untuk menampilkan permainan apa saja yang telah dimainkan
dari data yang sudah ada dari file konfigurasi (jika load) dan dari mulai
Start Game juga, dengan n adalah jumlah permainan yang telah dimainkan yang ingin ditampilkan.
Urutan teratas merupakan permainan terakhir yang dimainkan.
Jika n lebih besar dari jumlah permainan yang telah dimainkan, akan menampilkan seluruh
permainan yang telah dimainkan.
I.S.: Program telah berjalan.
F.S.: Menampilkan daftar game yang telah dimainkan. */
void history(int n, Stackchar hist)
{
    char *X;
    if (n < 1)
    {
        printf("Mohon masukkan angka yang benar, yaitu lebih dari 0.\n");
    }
    else {
        if (IsEmptyStackChar(hist))
        {
            printf("-----History Kosong-----\n");
        }
        else
        {
            printf("Berikut adalah daftar Game yang telah dimainkan\n");
            if (n > TopStackchar(hist))
            {
                n = TopStackchar(hist)+1;
            }
            for (int i = 0; i < n; i++)
            {
                PopStackChar(&hist, &X);
                printf("%d. %s\n", (i + 1), X);
            }
        }
    }
}

/* Prosedur untuk menghapus semua history permainan yang dimainkan.
I.S.: Program telah berjalan.
F.S.: Menghapus daftar game yang telah dimainkan. */
void resetHistory(Stackchar *hist)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
    STARTINPUTKATA();
    if (IsEqual(currentWord, "YA"))
    {
        CreateEmptyStackChar(hist);
        printf("History berhasil di-reset.\n");
    }
    else if (IsEqual(currentWord, "TIDAK"))
    {
        printf("History tidak jadi di-reset.\n");
        history((TopStackchar(*hist) + 1), (*hist));
    }
    else
    {
        printf("Mohon masukkan jawaban yang benar.\n");
    }
}

/* Prosedur untuk menampilkan scoreboard dari masing-masing game.
 * Setiap scoreboard dari masing-masing game akan direpresentasikan dengan map, dan digabungkan menjadi list of map
 I.S : Program telah berjalan.
 F.S : Menampilkan daftar scoreboard dari masing-masing game. */
void scoreboard(ListMap L, ArrayOfGame arr)
{
    /*KAMUS LOKAL*/
    ElTypeArrayOfGame game;
    /*ALGORITMA*/
    for (int i = 0; i < L.Neff; i++)
    {
        game = arr.A[i];
        printf("**** SCOREBOARD %s ****\n", WordToString(game));
        printf("| NAMA\t\t\t| SKOR\t\t\t|\n");
        printf("|-----------------------------------------------|\n");
        if (IsEmptyMap((L).peta[i])){
            printf("--------------- SCOREBOARD KOSONG ---------------\n\n");
        }
        else
        {
            displayMap((L).peta[i]);
            printf("\n"); 
            printf("\n"); 
        }
    }
}

/* Prosedur untuk menghapus semua atau sebagian scoreboard.
I.S : Program telah berjalan
F.S : Menghapus semua, sebagian, atau tidak sama sekali scoreboard sesuai dengan input user*/
void resetScoreboard(ListMap *L, ArrayOfGame *arr)
{
    /*KAMUS LOKAL*/
    ElTypeArrayOfGame game;
    /*ALGORITMA*/
    printf("DAFTAR SCOREBOARD :\n");
    printf("0. ALL\n");
    for (int i = 0; i < LengthArrayOfGame(*arr); i++)
    {
        game = arr->A[i];
        printf("%d. ", i + 1);
        printf("%s\n", WordToString(game));
    }
    printf("SCOREBOARD YANG INGIN DIHAPUS :");
    STARTINPUTKATA();

    if (WordToInt(currentWord) == 0)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL\n");
        printf("(YA/TIDAK)?");
        STARTINPUTKATA();
        if (IsEqual(currentWord, "YA"))
        {
            resetAllMap(L);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsEqual(currentWord, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
        }
        else
        {
            printf("Mohon masukkan jawaban yang benar.\n");
        }
    }
    else if (WordToInt(currentWord) <= LengthArrayOfGame(*arr))
    {
        game = arr->A[WordToInt(currentWord) - 1];
        Word game_idx = currentWord;
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s \n", WordToString(game));
        printf("(YA/TIDAK)?");
        STARTINPUTKATA();
        if (IsEqual(currentWord, "YA"))
        {
            resetAtMap(L, WordToInt(game_idx) - 1);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsEqual(currentWord, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
        }
        else
        {
            printf("Mohon masukkan jawaban yang benar.\n");
        }
    }
    else
    {
        printf("Mohon masukkan jawaban yang benar.\n");
    }
}
