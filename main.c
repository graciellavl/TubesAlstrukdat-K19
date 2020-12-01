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

char toChar (int digit) {
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

Kata NamaBangunan(int loc) {
    Kata cur;
    if (loc == 0) {
        cur = toKata("Base"); 
    } else if (loc == 1) {
        cur = toKata("Shop");
    } else {
        cur = toKata("Pelanggan ");
        // cur[12] = toChar(loc-1); 
    }
    return cur;
}
/* *** ******** FUNGSI UTAMA ******** *** */

int main() {
    // Menginisiasi permainan 
    List Komponen = MakeList();
    STARTGAME("komponen.txt");
    Kata komponen;
    while (CC != MARK) {
        int kode = toInteger(CKata);
        ADVKATA();
        int harga = toInteger(CKata);
        // printf("%d\n", harga);
        ADVKATA();
        InsertLast(&Komponen, CKata, kode, 1, harga);
        ADVKATA();
    }
    // PrintShop(Komponen);

    /* *** Membaca Nama File Konfigurasi *** */
    printf("FILENAME: ");
    STARTCOMMAND();
    char* namafile = CCommand.TabKata;
    // printf("%s\n", namafile);
    
    printf("Loading . . .\n");
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
    // printf("jlh bangunan %d\n", jlhBangunan);
    MATRIKS M;
    MakeMatriks(Brs, Kol, &M);
    int pelanggan = 0;
    for (int i = 0; i < jlhBangunan; i++) {
        ADVKATA();
        ElType jenis = toBangunan(CKata);
        if (jenis == 'C') {
            pelanggan += 1 ;
            jenis = toChar(pelanggan);
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
    // printf("Kata %s\n", CKata.TabKata);
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
        // printf("\n");
    }
    // printGraph(G);
    // printf("\n\n");
    printf("%c", GetElmt(M, 10,3));
    TulisPOINT(GetPoint(M, 'B'));
    TulisPOINT(GetPoint(M, 'S'));
    TulisPOINT(GetPoint(M, '1'));
    TulisPOINT(GetPoint(M, '2'));
    TulisPOINT(GetPoint(M, '3'));
    TulisPOINT(GetPoint(M, '4'));
    TulisPOINT(GetPoint(M, '5'));
    TulisPOINT(GetPoint(M, '6'));
    TulisPOINT(GetPoint(M, '7'));
    printf("\n--------------------------------\n");
    printf("SELAMAT BERMAIN\n");
    printf("--------------------------------\n");
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    printf("\n");
    
    // Permainan dimulai
    
    // Setup awal tapi dummy
    int i = 0;
    int money = 1000;
    int order = 1;
    int cust = 1;
    int loc = 0;
    ElType temp = '2';
    POINT getTemp = GetPoint(M, temp);
    ElType player = 'P';
    SetElmt(&M, getTemp.X, getTemp.Y, player);
    POINT getPlayer = GetPoint(M, player);
    // printf("tes\n");
    // TulisPOINT(getTemp);
    List Inventory = MakeList();

    while (!IsKataSama(CCommand, toKata("EXIT"))) {
    
        if (IsKataSama(CCommand, toKata("MOVE"))) {
            if (loc < 2) {
                printf("Kamu berada pada ");
                PrintKata(NamaBangunan(loc));
                printf("\n");
            } else {
                printf("Kamu berada pada Pelanggan %c\n", toChar(loc-1));
            }
            printf("Daftar lokasi yang dapat dicapai: \n");
            adrNode P = First(G);
            adrSuccNode curPos;
            while (P != Nil && id(P) != loc) {
                P = Next(P);
            }
            if (id(P) == loc) {
                adrSuccNode X = Trail(P);
                curPos = X;
                int no = 1;
                while (X != Nil) {
                    if (id(X) > 1) {
                        printf("%d. Pelanggan %c\n", no, toChar(id(X) - 1));
                    } else {
                        printf("%d. ", no);
                        PrintKata(NamaBangunan(id(X)));
                        printf("\n");
                    }
                    no++;
                    X = Next(X);
                }
            }
            printf("Nomor tujuan: ");
            STARTCOMMAND();
            int count = toInteger(CCommand);
            int inc = 1;
            boolean sama = false;
            while ((curPos != Nil) && !sama) {
                if (inc == count) {
                    sama = true;
                } else {
                    curPos = Next(curPos);
                    inc++;
                }
            }
            if (sama) {
                loc = id(curPos);
                if (loc < 2) {
                    getPlayer = GetPoint(M, player);
                    SetElmt(&M, getPlayer.X, getPlayer.Y, temp);
                    if (loc == 0) {
                        temp = 'B';
                        getTemp = GetPoint(M, temp);
                    } else if (loc == 1) {
                        temp = 'S';
                        getTemp = GetPoint(M, temp);
                    } 
                    SetElmt(&M, getTemp.X, getTemp.Y, 'P');
                    printf("Kamu telah mencapai lokasi ");
                    PrintKata(NamaBangunan(loc));
                    printf("\n");
                } else {
                    getPlayer = GetPoint(M, player);
                    SetElmt(&M, getPlayer.X, getPlayer.Y, temp);
                    temp = toChar(loc-1);
                    getTemp = GetPoint(M, temp);
                    SetElmt(&M, getTemp.X, getTemp.Y, 'P');
                    printf("Kamu telah mencapai lokasi Pelanggan %c\n", toChar(loc-1));
                }
            } else {
                printf("Tujuan tidak valid.\n");
            }
        } else if (IsKataSama(CCommand, toKata("STATUS"))) {
            printf("Uang tersisa: $%d\n", money);
            printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", order, cust);
            printf("Lokasi: Pemain sedang berada pada %s\n", loc);
            printf("Inventory anda: \n");
            PrintInventory(Inventory);

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
            PrintInventory(Inventory);
            printf("Komponen yang ingin dipasang: ");
            STARTCOMMAND();
            // Kondisi kalo bisa dipasang dan tidak

        } else if (IsKataSama(CCommand, toKata("REMOVECOMPONENT"))) {
            // cabut komponen top
            printf("Komponen %s berhasil dicopot!\n", "top"); 

        } else if (IsKataSama(CCommand, toKata("SHOP"))) {
            if(loc != 1) {
                printf("Kamu tidak berada di Shop.\n");
                printf("Mohon pindah ke Shop terlebih dahulu.\n");
            } else {
                printf("Komponen yang tersedia: \n");
                PrintShop(Komponen);
                printf("Komponen yang ingin dibeli: ");
                STARTCOMMAND();
                int index = toInteger(CCommand); 
                printf("Masukkan jumlah yang ingin dibeli: ");
                STARTCOMMAND();
                int kuantitas = toInteger(CCommand);
                Item dibeli = Get(Komponen, index-1);
                int total = (kuantitas)*(dibeli.harga);
                if (kuantitas == 0) {
                    printf("Kamu tidak membeli apa-apa.\n");
                } else {
                    if (total > money ) {
                        printf("Uang tidak cukup!\n");
                    } else {
                        UpdateList(&Inventory, dibeli.nama, dibeli.kode, kuantitas, dibeli.harga);
                        printf("Komponen berhasil dibeli!\n");
                    }
                }
            }

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
        // printf("\n");
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