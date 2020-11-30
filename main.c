#include <stdio.h>
#include <stdlib.h>

#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/matriks.h"
#include "ADT/point.h"
#include "ADT/graph.h"
#include "ADT/list.h"

/* *** ******** FUNGSI PEMBANTU ******** *** */

int digit(char C) {
    switch (C)
    {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 0;
        break;
    }
}

int toInteger(Kata CKata) {
    int result = 0;
    int base = 1;
    for (int i = CKata.Length-1; i >= 0; i--) {
        result += digit(CKata.TabKata[i])*(base);
        base *= 10; 
    }
    return result;
}

ElType toElType(int digit) {
    switch (digit)
    {
    case 1:
        return '1';
        break;
    case 2:
        return '2';
        break;
    case 3:
        return '3';
        break;
    case 4:
        return '4';
        break;
    case 5:
        return '5';
        break;
    case 6:
        return '6';
        break;
    case 7:
        return '7';
        break;
    case 8:
        return '8';
        break;
    case 9:
        return '9';
        break;
    default:
        return '0';
        break;
    }
}

ElType toBangunan(Kata CKata) {
    if (CKata.TabKata[0] == 'B') {
        return 'B';
    } else if (CKata.TabKata[0] == 'S') {
        return 'S';
    } else if (CKata.TabKata[0] == 'C') {
        return 'C';
    } else if (CKata.TabKata[0] == 'P') {
        return 'P';
    }
}

int stringLength (char* string) {
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

Kata toKata(char* command) {
    int i;
    Kata output;
    for (i = 0; i < stringLength(command); i++) {
        output.TabKata[i] = command[i];
    }
    output.Length = stringLength(command);
    return output;
}

boolean IsKataSama(Kata InputCommand, Kata Command) {
    boolean sama = true;
    if (InputCommand.Length != Command.Length) {
        return !sama;
    } else {
        int i = 0;
        while (sama && (i < Command.Length)) {
            if (InputCommand.TabKata[i] != Command.TabKata[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}


/* *** ******** FUNGSI UTAMA ******** *** */

int main() {
    // Menginisiasi permainan 
    // List Komponen = MakeList();
    // STARTGAME("komponen.txt");
    // Kata komponen;
    // while (CC != MARK) {
    //     int kode = toInteger(CKata);
    //     printf("kode %d ", kode);
    //     ADVKATA();
    //     // komponen = (CKata);
    //     // for (int i = 0; i < CKata.Length; i++) {
    //     //     komponen[i] = CKata.TabKata[i];
    //     // }
    //     printf("%d ", CKata.Length);
    //     // komponen = Salin(CKata);
    //     printf("komponen %s ", komponen.TabKata);
    //     printf("\n");
    //     InsertLast(&Komponen, CKata.TabKata, kode, 1);
    //     ADVKATA();
    // }
    // PrintList(Komponen);

    /* *** Membaca Nama File Konfigurasi *** */
    printf("FILENAME: ");
    STARTCOMMAND();
    char* namafile = CCommand.TabKata;
    // printf("%s\n", namafile);
    
    // printf("Loading . . .\n");
    /* *** Membaca File Konfigurasi Permainan *** */
    STARTGAME(CCommand.TabKata);

    // Membaca Baris
    int Brs = toInteger(CKata);
    // printf("Brs %d\n", Brs);
    ADVKATA();

    // Membaca Kolom
    int Kol = toInteger(CKata);
    // printf("Kol %d\n", Kol);
    ADVKATA();

    int jlhBangunan = toInteger(CKata);
    printf("jlh bangunan %d\n", jlhBangunan);
    MATRIKS M;
    MakeMatriks(Brs, Kol, &M);
    int pelanggan = 0;
    for (int i = 0; i < jlhBangunan; i++) {
        ADVKATA();
        ElType jenis = toBangunan(CKata);
        if (jenis == 'C') {
            pelanggan += 1 ;
            jenis = toElType(pelanggan);
            // printf("jenis %c\n", jenis);
        }
        // printf("%c", jenis);
        ADVKATA();
        // printf("%d %c\n", i, CKata.TabKata[0]);
        int Baris = toInteger(CKata);
        // printf("%d %d\n", i, Baris);
        ADVKATA();
        // printf("%d %c\n", i, CKata.TabKata[0]);
        int Kolom = toInteger(CKata);
        // printf("%d %d\n", i, Kolom);
        SetElmt(&M, Baris, Kolom, jenis);
    }
    printf("Kata %s\n", CKata.TabKata);
    Graph G;
    CreateGraph(&G, 0);
    for (int i = 1; i < jlhBangunan; i++) {
        InsertNode(&G, i);
    }
    // ADVKATA();
    for (int i = 0; i < jlhBangunan; i++) {
        for (int j = 0; j < jlhBangunan; j++) {
            ADVKATA();
            // printf("i: %d j: %d nilai: %c\n", i, j, CKata.TabKata[0]);
            if (CKata.TabKata[0] == '1') {
                InsertSuccNode(&G, i, j);
            }
            // printf(" %c", CKata.TabKata[0]);
        }
        printf("\n");
    }
    printf("\n");
    // printGraph(G);
    // printf("\n\n");

    printf("\n--------------------------------\n");
    printf("SELAMAT BERMAIN\n");
    printf("--------------------------------\n");
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    printf("\n");
    
    // Permainan dimulai
    
    // Setup awal tapi dummy
    int i = 0;
    int money = 0;
    int order = 1;
    int cust = 1;
    char* loc = "Base";
    List L = MakeList();
    InsertLast(&L, "tes", 1, 1);
    InsertLast(&L, "tes", 2, 1);
    InsertLast(&L, "tes", 3, 1);
    InsertLast(&L, "tes", 4, 1);


    while (!IsKataSama(CCommand, toKata("EXIT"))) {
    
        if (IsKataSama(CCommand, toKata("MOVE"))) {
            printf("Kamu berada pada ???\n");
            printf("Daftar lokasi yang dapat dicapai: \n");

        } else if (IsKataSama(CCommand, toKata("STATUS"))) {
            printf("Uang tersisa: $%d\n", money);
            printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", order, cust);
            printf("Lokasi: Pemain sedang berada pada %s\n", loc);
            printf("Inventory anda: \n");
            PrintList(L);

        } else if (IsKataSama(CCommand, toKata("CHECKORDER"))) {
            printf("Nomor order: %d\n", order);
            printf("Pemesan: %d\n", cust);
            printf("Invoice: %d\n", 100); //ganti duit
            printf("Komponen: \n");
            //PrintStack(S);

        } else if (IsKataSama(CCommand, toKata("STARTBUILD"))) {
            printf("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", order, cust);
            // CreateStack

        } else if (IsKataSama(CCommand, toKata("FINISHBUILD"))) {
            if (true) { // CountStack = 8?
                printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n", order, cust);
            } else {
                printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
            }
        } else if (IsKataSama(CCommand, toKata("ADDCOMPONENT"))) {
            printf("Komponen yang telah terpasang: \n");
            //PrintStack(S);
            printf("Komponen yang tersedia:\n");
            PrintList(L);
            printf("Komponen yang ingin dipasang: ");
            STARTCOMMAND();
            // Kondisi kalo bisa dipasang dan tidak

        } else if (IsKataSama(CCommand, toKata("REMOVECOMPONENT"))) {
            // cabut komponen top
            printf("Komponen %s berhasil dicopot!\n", "top"); 

        } else if (IsKataSama(CCommand, toKata("SHOP"))) {
            printf("SHOP masuk\n");

        } else if (IsKataSama(CCommand, toKata("DELIVER"))) {
            printf("DELIVER masuk\n");

        } else if (IsKataSama(CCommand, toKata("END_DAY"))) {
            printf("END_DAY masuk\n");

        } else if (IsKataSama(CCommand, toKata("SAVE"))) {
            printf("Lokasi save file: ");
            STARTCOMMAND(); 
            Kata fileoutput;
            for (int i = 0; i < CCommand.Length; i++) {
                fileoutput.TabKata[i] = CCommand.TabKata[i];
            }
            FILE * output;
            output = fopen(fileoutput.TabKata, "w");

            if (output == NULL) {
                printf("Permainan tidak dapat disimpan.\n");
                printf("Mohon coba kembali.\n");
            } else {
                fprintf(output, "%s", namafile);
            }
            fclose(output);

        } else if (IsKataSama(CCommand, toKata("MAP"))) {
            TulisMATRIKS(M);
            
        } else {
            printf("Command tidak valid.\n");
        }
        printf("\n");
        printf("--------------------------------\n");
        printf("ENTER COMMAND: ");
        STARTCOMMAND();
        printf("\n");
        i++;
    }
    printf("\nTerima kasih sudah bermain.\n");
    printf("--------------------------------\n");
    return 0;
}