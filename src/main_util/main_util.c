#include <stdlib.h>
#include <stdio.h>

#include "../ADT/queue/queue.h"
#include "../ADT/arrayOfGame/arrayOfGame.h"
#include "./main_util.h"
#include "../ADT/mesinkata/mesinkata.h"

/* Prosedur untuk menjalankan program 
 * I.S : Sembarang.
 * F.S : menjalankan program dengan melakukan load terhadap konfigurasi.
*/
void start(ArrayOfGame *arr)
{
    /*KAMUS LOKAL*/
    int count;
    /*ALGORITMA*/
    *arr = MakeArrayOfGame();
    char *FILE = "./config.txt";
    STARTWORD(FILE);
    count = WordToInt(currentWord);
    for (int i = 0; i < count; i++)
    {
        ADVWORD();
        InsertGameLast(arr, currentWord);
    }
    printf("File Konfigurasi sistem berhasi dibaca. BNMO berhasil dijalankan\n");
}

/* Prosedur untuk menjalankan file yang tersimpan dari history program 
 * I.S. Program telah berjalan.
 * F.S. Menjalankan file yang telah tersimpan sebelumnya dari file eksternal.
*/
void load(char *savefile, ArrayOfGame *arrGame)
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    *arrGame = MakeArrayOfGame();
    char *path = "Data/";
    char *newfile = ConcateChar(path, savefile);
    STARTWORD(newfile);
    int count = WordToInt(currentWord);
    int i;
    for (i = 0; i < count; i++)
    {
        ADVWORD();
        InsertGameLast(arrGame, currentWord);
    }
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

/* Prosedur untuk menyimpan file program yang telah dijalankan 
 * I.S : Program telah berjalan.
 * F.S : Menyimpan file yang telah dijalankan ke dalam file eksternal
*/
void save(char *savefile, ArrayOfGame arrGame)
{
    /*KAMUS LOKAL*/
    FILE *fp;
    int i;
    char *game;
    char *path = "Data/";
    /*ALGORITMA*/
    char *newfile = ConcateChar(path, savefile);
    fp = fopen(newfile, "w+");
    fprintf(fp, "%d\n", LengthArrayOfGame(arrGame));
    for (i = 0; i < LengthArrayOfGame(arrGame); i++)
    {
        game = WordToString((arrGame).A[i]);
        fprintf(fp, "%s\n", game);
    }
    fclose(fp);
    printf("Save file berhasil disimpan.\n");
}

/* Prosedur untuk menampilkan command yang bisa dimasukan user 
 * I.S : Program telah berjalan
 * F.S : Menampilkan bantuan untuk penggunaan program
*/
void help()
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    printf("Hai Hai Jangan Merasa Tersesat,\n");
    printf("Berikut adalah hal-hal yang bisa kamu lakukan :\n");
    printf("01. SAVE <filename> : untuk menyimpan state game pemain saat ini ke dalam suatu file\n");
    printf("02. CREATE GAME      : untuk menambahkan game baru pada daftar game\n");
    printf("03. LIST GAME        : untuk menampilkan daftar game yang disediakan oleh sistem\n");
    printf("04. DELETE GAME      : untuk menghapus sebuah game dari daftar game\n");
    printf("05. QUEUE GAME       : untuk mendaftarkan permainan kedalam list\n");
    printf("06. PLAY GAME        : ntuk memainkan sebuah permainan\n");
    printf("07. SKIPGAME <n>    : untuk melewati n permainan yang ada di dalam list\n");
    printf("07. QUIT            : untuk keluar dari program\n");
    printf("08. HELP            : untuk melihat informasi dari command-command\n");
}

/* Prosedur untuk berhenti dari program 
 * I.S : Program sedang berjalan
 * F.S : Keluar dari program dengan array telah didealokasikan
  */
void quit(ArrayOfGame arrGame)
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    printf("Apakah kamu ingin save game kamu? (Y/N)\n");
    STARTINPUTKATA();
    while (!(IsEqual(currentWord, "Y") || IsEqual(currentWord, "N")))
    {
        printf("Input tidak valid. Silahkan masukkan Y jika kamu ingin save progress kamu dan N jika tidak (Y/N) : \n");
        STARTINPUTKATA();
    }

    if (IsEqual(currentWord, "Y"))
    {
        char *savefile;
        printf("Masukkan nama file penyimpanan: ");
        STARTINPUTKATA();
        savefile = WordToString(currentWord);
        save(savefile, arrGame);
        printf("Game kamu berhasil disave. Sampai jumpa!\n");
    }

    printf("Game has ended\n");
    printf("Thank you for playing BNMO\n");
    exit(0);
}

/* Prosedur untuk menampilkan pesan kesalahan input user 
 * I.S : Program sedang berjalan
 * F.S : Menampilkan pesan bahwa command yang dimasukkan tidak valid
*/
void otherCommand()
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    printf("Command yang diberikan tidak sesuai yang diinginkan\n Silahkan masukkan input yang valid.");
}