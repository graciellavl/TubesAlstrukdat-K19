#include <stdio.h>
#include <stdlib.h>

#include "ADT/mesinkar.c"
#include "ADT/mesinkata.c"
#include "ADT/matriks.c"
#include "helper.c"

void GAME() {
    printf("Hi");
    // if (IsKataSama(MAP, CKata)) {
    //     TulisMATRIKS(M);
    // }
}

void ExitGame() {
    printf("Terima kasih sudah bermain.");
}

int main() {
    printf("FILENAME: ");
    char filename[100];
    STARTCOMMAND();
    printf("%s\n", CKata.TabKata);
    /* *** Membaca File Konfigurasi Permainan *** */
    STARTGAME(CKata.TabKata);

    // Membaca Baris
    int Brs = toInteger(CKata);
    // printf("Brs %d\n", Brs);
    ADVKATA();

    // Membaca Kolom
    int Kol = toInteger(CKata);
    // printf("Kol %d\n", Kol);
    ADVKATA();

    int jlhBangunan = toInteger(CKata);
    ADVKATA();

    MATRIKS M;
    MakeMatriks(Brs, Kol, &M);
    int pelanggan = 0;
    for (int i = 0; i < jlhBangunan; i++) {
        ElType jenis = toBangunan(CKata);
        if (jenis == 'C') {
            pelanggan += 1 ;
            jenis = toElType(pelanggan);
        }
        // printf("%c", jenis);
        ADVKATA();
        int Baris = toInteger(CKata);
        ADVKATA();
        int Kolom = toInteger(CKata);
        SetElmt(&M, Baris, Kolom, jenis);
        ADVKATA(); 
    }
    
    for (int i = 0; i < jlhBangunan; i++) {
        for (int j = 0; j < jlhBangunan; j++) {
            printf("%d", i);
            ADVKATA();
        }
        printf("\n");
    }
    TulisMATRIKS(M);
    CKata = toKata(" ");
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    printf("%s", CKata.Length);
    // if (!IsKataSama(CKata, toKata("EXIT"))) {
    //     GAME(CKata);
    // } else {
    //     ExitGame(CKata);
    // }
    return 0;
}