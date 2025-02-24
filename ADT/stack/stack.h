
#ifndef stack_H
#define stack_H
#include <stdio.h>
#include "../boolean.h"
/* MODUL STACK
Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik
dan ukuran sama
TOP adalah alamat elemen puncak*/

#define false 0
#define true 1
#define Nil 0
#define MaxEl 8

typedef int bool;
typedef int address;

typedef struct {
  int kode;
  int jumlah;
  int harga;
  char nama[100];
} Komponen;

typedef struct
{
    Komponen T[MaxEl];
    address TOP;
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean StackEmpty(Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */

boolean StackFull(Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, Komponen X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */

void Pop(Stack *S, Komponen *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

Stack InverseStack(Stack S);
/* Mengirim Stack yang merupakan kebalikan dari Stack yang diinput */

void PrintStack(Stack S);
/* Mencetak Stack ke layar sesuai format yang diinginkan */
/* I.S. S terdefinisi */
/* F.S. Stack tercetak pada layar */

boolean IsStackSama(Stack S1, Stack S2);
/* Mengirim true jika stack S1 dan stack S2 sama */
/* Ciri stack sama : Semua elemennya bernilai sama */

#endif