/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type nodeinfotype, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_H_
#define _BINTREE_H_

/* Modul lain yang digunakan : */
#include "../../boolean.h"
#include "../mesinkata/mesinkarakter.h"
#include "../mesinkata/mesinkata.h"
#include <math.h>

/* *** Definisi Type Pohon Biner *** */
typedef int nodeinfotype;
typedef struct tNode *addrNode;
typedef struct tNode
{
   nodeinfotype info;
   addrNode left;
   addrNode right;
} TreeNode;
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

/* *** Konstruktor *** */

/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NULL) jika alokasi gagal */
BinTree Tree(nodeinfotype Akar, BinTree L, BinTree R);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
        jika alokasi berhasil. P = NULL jika alokasi gagal. */
void MakeTree(nodeinfotype Akar, BinTree L, BinTree R, BinTree *P);

/* Manajemen Memory */

/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NULL, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = NULL, Right(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
addrNode AlokNode(nodeinfotype X);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
void DealokNode(addrNode P);

/* *** Predikat-Predikat Penting *** */

/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerLeft(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsUnerRight(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
boolean IsBiner(BinTree P);

/* *** Traversal *** */

/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintPreorder(BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintInorder(BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintPostorder(BinTree P);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
void PrintTree(BinTree P, int h);

/* *** Searching *** */

/* Mengirimkan true jika ada node dari P yang bernilai X */
boolean SearchTree(BinTree P, nodeinfotype X);

/* *** Fungsi-Fungsi Lain *** */

/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbNode(BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
int NbDaun(BinTree P);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Level(BinTree P, nodeinfotype X);
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
int Tinggi(BinTree P);

/* *** Operasi lain *** */
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaunTerkiri(BinTree *P, nodeinfotype X);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void AddDaun(BinTree *P, nodeinfotype X, nodeinfotype Y, boolean Kiri);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaunTerkiri(BinTree *P, nodeinfotype *X);
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
void DelDaun(BinTree *P, nodeinfotype X);

/* *** Binary  Search  Tree  *** */
/* Mengirimkan true jika ada node dari P yang bernilai X */
boolean BSearch(BinTree P, nodeinfotype X);
/* Mengirimkan alamat node dari P yang bernilai X */
addrNode SearchDaun(BinTree P, nodeinfotype X);
/* Mengirimkan alamat node dari P yang memiliki child kiri left dan child kanan right */

/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */
void InsSearch(BinTree *P, nodeinfotype X);

/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
void DelBtree(BinTree *P, nodeinfotype X);

void BuildTreeFromWord(BinTree *T, Word w, int *idx);

#endif