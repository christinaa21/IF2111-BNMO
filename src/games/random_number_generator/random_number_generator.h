#ifndef __RANDOM_NUMBER_GENERATOR__
#define __RANDOM_NUMBER_GENERATOR__

#include <stdio.h>
#include <stdlib.h>

#include "../../../boolean.h"
#include "../../main_util/main_util.h"
#include "../../ADT/array/arraydin.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/prioQueue/prioqueue.h"

/*** Penjelasan Permainan ***\
 * -	Permainan dimulai dengan menyediakan sebuah number random dari sistem
 * -    User akan memasukan sebuah angka untuk menebak
 * -    Sistem akan memberi informasi apakah nomor tebakan lebih besar atau lebih kecil
 * -    User akan terus memasukan input nomor hingga berhasil tertebak */
void RNG();

#endif