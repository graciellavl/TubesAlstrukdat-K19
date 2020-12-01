#include <stdio.h>
#include "boolean.h"
#include "ADT/matriks.c"
#include "ADT/point.c"
#include "ADT/list.c"
#include "ADT/mesinkar.c"
#include "ADT/mesinkata.c"
#include "ADT/graph.c"
#include "ADT/stack.c"

int main() {
    Stack S;
    CreateStack(&S);
    if (StackEmpty(S)) {
        printf("Kosong\n");
    }
    // PrintStack(S);
    Komponen K, T;
    K.harga = 10;
    K.jumlah = 1;
    K.kode = 2;
    K.nama = "nama";
    Push(&S, K);
    PrintStack(S);
    T.harga = 20;
    T.jumlah = 2;
    T.kode = 4;
    T.nama = "nama1";
    Push(&S, T);
    PrintStack(S);
    printf("ok\n");
}
//     printf("in\n");
//     CreateStack(&S);
//     printf("createstack\n");
//     // PrintStack(S);
//     Komponen K, T;
//     K.nama = "tes";
//     K.jumlah = 1;
//     K.kode = 1;
//     K.harga = 10;
//     Push(&S, K);
//     PrintStack(S);
//     T.nama = "tes1";
//     T.jumlah = 2;
//     T.kode = 2;
//     T.harga = 12;
//     Push(&S, T);
//     printf("push acc\n");
//     // PrintStack(S);
//     printf("Ok\n");
// }
// Kata getKata(Kata K) {
//     Kata kata;
//     kata.Length = K.Length;
//     for (int i = 0; i < kata.Length; i++) {
//         kata.TabKata[i] = kata.TabKata[i];
//     }
//     printf("\noutput file %s\n", kata.TabKata);
//     printf("len: %s\n", kata.Length);
//     return kata;
// }

// int main() {
//     MATRIKS M;
//     MakeMatriks(2, 2, &M);
//     TulisMATRIKS(M);
//     SetElmt(&M, 1, 1, 'E');
//     TulisMATRIKS(M);
//     POINT P = GetPoint(M, 'E');
//     TulisPOINT(P);
// }

// int main() {
//     STARTGAME("komponen.txt");
//     Kata kata;
//     while (CC != MARK) {
//         kata = Salin(CKata);
//         // printf("ini untuk kode CKata %s \n", CKata.TabKata);
//         printf("ini untuk kode %s\n", kata.TabKata);
//         ADVKATA();
//         kata = Salin(CKata);
//         printf("ini untuk nama CKata %s \n", kata.TabKata);
//         // printf("ini untuk nama %s\n", kata.TabKata);
//         printf("\n");
//         ADVKATA();
//     }
// }

// int main() {
//     printf("start: ");
//     STARTCOMMAND();
//     printf("output 1: %s\n", CCommand.TabKata);
//     STARTCOMMAND();
//     printf("tes: ");
//     printf("output 2: %s\n", CCommand.TabKata);
    
//     printf("output 3: ");
//     for (int i = 0; i<CCommand.Length; i++) {
//         printf("%c", CCommand.TabKata[i]);
//     }
//     // char *fileoutput;
//     Kata fileoutput;
//     for (int i = 0; i < CCommand.Length; i++) {
//         fileoutput.TabKata[i] = CCommand.TabKata[i];
//     }

//     // for (int i = 0; i < CCommand.Length; i++) {
//     //     fileoutput[i] = CCommand.TabKata[i];
//     // }
//     printf("\noutput file %s\n", fileoutput.TabKata);
//     printf("ok");
// }

// int main() {
//     char* a = "NVDIA GRAPH";
//     char* b = "NVDIA GRAPH";
//     if (a==b) {
//         printf("yes");
//     }
// }

// int main() {
//     Graph G;
//     CreateGraph(&G, 1);

//     InsertNode(&G, 2);

//     InsertNode(&G, 3);

//     InsertNode(&G, 4);

//     InsertSuccNode(&G, 1, 2);
//     InsertSuccNode(&G, 2, 3);
//     InsertSuccNode(&G, 2, 4);
//     printGraph(G);
// }

// int main() {
//     char* string;
//     char* nama;
//     string = "kata";
//     nama = string;
//     printf("ini string %s\n", string);
//     printf("ini kata %s\n", nama);
//     Kata tes;
//     tes = toKata("hi\n");
//     int i;
//     for (i = 0; i < tes.Length; i++) {
//         printf("%c", tes.TabKata[i]);
//     }
//     printf("%d", tes.Length);
// }

/*
LIST

*/

// int main() {
//     List L = MakeList();
//     if (IsEmpty(L)) {
//         printf("IsEmpty kosong\n");
//     }
//     printf("Length array %d\n", Length(L));
    
//     char* tes = "tes";
//     InsertLast(&L, "tes", 1, 2);
//     printf("%s\n", L.A[0].nama);
//     printf("%d\n", L.A[0].jumlah);
//     printf("%d\n", L.A[0].kode);

//     if (SearchList(&L, tes)) {
//         UpdateList(&L, tes, 1, -1);
//         printf("SearchList sukses\n");
//     } else {
//         InsertLast(&L, tes, 1, 1);
//     }

//     char* nope = "nope";
//     if (SearchList(&L, nope)) {
//         UpdateList(&L, nope, 1, -1);
//     } else {
//         InsertLast(&L, nope, 1, 1);
//         printf("SearchList sukses\n");
//     }
//     printf("\n");

//     printf("Nama %s\n", L.A[0].nama);
//     printf("Jumlah %d\n", L.A[0].jumlah);
//     printf("Kode %d\n", L.A[0].kode);
//     printf("\n");

//     UpdateList(&L, tes, 1, 1);
//     printf("Nama %s\n", L.A[0].nama);
//     printf("Jumlah %d\n", L.A[0].jumlah);
//     printf("Kode %d\n", L.A[0].kode);
//     printf("\n");
//     PrintList(L);

//     UpdateList(&L, tes, 1, -2);
//     printf("Nama %s\n", L.A[0].nama);
//     printf("Jumlah %d\n", L.A[0].jumlah);
//     printf("Kode %d\n", L.A[0].kode);
//     printf("\n");
//     PrintList(L);

//     printf("Nama %s\n", L.A[1].nama);
//     printf("Jumlah %d\n", L.A[1].jumlah);
//     printf("Kode %d\n", L.A[1].kode);
//     printf("\n");
// }

/*
POINT
- Baca posisi pemain & save

*/

// int main() {
//     POINT P;
//     BacaPOINT (&P); 
//     TulisPOINT(P);
//     MATRIKS M;
//     MakeMatriks(10, 10, &M);
//     SetElmt(&M, Absis(P), Ordinat(P), 'B');
//     printf("\n");
//     TulisMATRIKS(M);
//     printf("\n");
//     printf("%c", GetElmt(M, Absis(P), Ordinat(P)));
// }


// ---------------------------------------------------------
/*
MAP

Konfigurasi map (Baca dari file luar)
Line pertama    : MakeMatriks
Line kedua      : iterasi loop
Line ke3 - n    : SetEl
Line ke n+1     : TulisMatriks, MakeGraph
*/


// int main() {
//     printf("tes\n");
//     MATRIKS M;
//     indeks kol, brs;
//     if (!IdxValid(brs, kol)) {
//         printf("Baris atau kolom tidak valid.\n");
//     } else {
//         MakeMatriks(brs, kol, &M);
//         TulisMATRIKS(M);
//         SetElmt(&M, 2, 2, '3'); // nanti fungsinya ada di main
//         TulisMATRIKS(M);
//         printf("%c", GetElmt(M,2,2)); // nanti fungsinya ada di main
//     }
//     return 0;
// }
