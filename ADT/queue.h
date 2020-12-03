/* File : queue.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUE_H
#define _QUEUE_H

#include "../boolean.h"
#include "stack.h"
#include <stdlib.h>

/* Konstanta */
#define Nil 0

/* Deklarasi infoOrder */
typedef struct {
	int noPelanggan;
	int hargaPesanan;
	Stack daftarKomponen;
} infoOrder;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * addressQ;

typedef struct tElmtQueue {
	infoOrder Info;
	addressQ NextQ;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	addressQ HEAD;  /* alamat penghapusan */
	addressQ TAIL;  /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define NextQ(P) (P)->NextQ
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infoOrder X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        NextQ(P)=Nil*/
/*      P=Nil jika alokasi gagal */
void DealokasiQ (addressQ  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean QueueEmpty (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int QElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateQueue(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infoOrder X );
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element terakhir
/* jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element terakhir,
/* maka TAIL = element X. */
void Dequeue (Queue * Q, infoOrder * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

void PrintQueue (Queue Q, int count);

#endif