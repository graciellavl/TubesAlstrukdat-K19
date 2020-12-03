#include "queue.h"

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infoOrder X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X,
        NextQ(P)=Nil
/*      P=Nil jika AlokasiQ gagal */
{
    *P = (addressQ)malloc(sizeof(ElmtQueue));
    if(*P!=Nil){
        Info(*P)=X;
        NextQ(*P)=Nil;
    }
}
void DealokasiQ (addressQ  P)
/* I.S. P adalah hasil AlokasiQ, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}
boolean QueueEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return (Head(Q)==Nil && Tail(Q)==Nil);
}
int QElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
{
    int C=0;
    if(!QueueEmpty(Q)){
        addressQ P=Head(Q);
        while(P!=Nil){
            C++;
            P=NextQ(P);
        }
    }
    return C;
}
void CreateQueue(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
{
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
}
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infoOrder X)
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element terakhir
/* jika AlokasiQ berhasil; jika AlokasiQ gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element terakhir,
/* maka TAIL = element X. */
{
    addressQ P;
    AlokasiQ(&P,X);
    if (P!=Nil) {
        if (QueueEmpty(*Q)) {
            Head(*Q)=P;
            Tail(*Q)=P;
        }
        else {
            NextQ(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}
void Dequeue (Queue * Q, infoOrder * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    (*X) = InfoHead(*Q);
    addressQ temp;
    temp = Head(*Q);
    if (QElmt(*Q) == 1) {
        CreateQueue(Q);
    }
    else {
        Head(*Q) = NextQ(temp);
    }
    DealokasiQ(temp);
}

void PrintQueue (Queue Q, int count) {
    addressQ temp = Head(Q);
    printf("Daftar pesanan: \n");
    while (temp != Nil) {
        printf("%d. Pesanan Pelanggan %d - $%d\n", count, Info(temp).noPelanggan, Info(temp).hargaPesanan);
        // printf("Daftar komponen: \n");
        // PrintStack(Info(temp).daftarKomponen);
        temp = NextQ(temp);
        count++;
    }
}
