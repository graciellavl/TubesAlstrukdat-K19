#include <stdio.h>
#include <stdlib.h>

#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/matriks.h"
#include "ADT/point.h"
#include "ADT/graph.h"
#include "ADT/list.h"
#include "ADT/stack.h"

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
    List ListKomponen = MakeList();
    STARTGAME("item.txt");
    Kata komponen;
    while (CC != MARK) {
        int kode = toInteger(CKata);
        ADVKATA();
        int harga = toInteger(CKata);
        // printf("%d\n", harga);
        ADVKATA();
        InsertLast(&ListKomponen, CKata, kode, 1, harga);
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
    printf("\n--------------------------------\n");
    printf("SELAMAT BERMAIN\n");
    printf("--------------------------------\n");
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    printf("\n");
    
    // Permainan dimulai
    
    // Setup awal tapi dummy
    // int i = 0;
    int money = 1000;          // uang
    int order = 0;             // pesanan ke -
    int cust = 1;              // nomor pemesan
    int loc = 0;               // lokasi saat ini
    boolean IsBuild = false;   // status build
    boolean IsDelivered = true;   // status deliver
    ElType temp = 'B';
    POINT getTemp = GetPoint(M, temp);
    ElType player = 'P';
    SetElmt(&M, getTemp.X, getTemp.Y, player);
    POINT getPlayer = GetPoint(M, player);
    List Inventory = MakeList();
    Stack Build;
    CreateStack(&Build);
    Stack Order;
    CreateStack(&Order);

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
            if (IsBuild) {
                printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", order, cust);
            } else {
                printf("Sedang tidak mengerjakan build.\n");
            }
            printf("Lokasi: Pemain sedang berada pada ");
            if (loc < 2) {
                PrintKata(NamaBangunan(loc));
                printf("\n");
            } else {
                printf("Pelanggan %c\n", toChar(loc-1));
            }
            printf("Inventory anda: \n");
            PrintInventory(Inventory);

        } else if (IsKataSama(CCommand, toKata("CHECKORDER"))) {
            printf("Nomor order: %d\n", order);
            printf("Pemesan: %d\n", cust);
            printf("Invoice: %d\n", 100); //ganti duit
            printf("Komponen: \n");
            PrintStack(Order);
        } else if (IsKataSama(CCommand, toKata("STARTBUILD"))) {
            // pelanggan update dari queue
            order++;
            CreateStack(&Build);
            if (IsDelivered) {
                IsBuild = true;
                IsDelivered = false;
                printf("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", order, cust);
            } else {
                printf("Kamu belum menyelesaikan pesananmu!\n");
            }

        } else if (IsKataSama(CCommand, toKata("FINISHBUILD"))) {
            if (StackFull(Build)) { 
                IsBuild = false;
                printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n", order, cust);
            } else {
                printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
            }
        } else if (IsKataSama(CCommand, toKata("ADDCOMPONENT"))) {
            if (loc != 0) {
                printf("Kamu harus di base untuk memasang komponen!\n");
            } else {
                if (IsBuild) {
                    printf("Komponen yang telah terpasang: \n");
                    PrintStack(Build);
                    printf("\n");
                    printf("Komponen yang tersedia:\n");
                    PrintInventory(Inventory);
                    printf("\n");
                    printf("Komponen yang ingin dipasang: ");
                    STARTCOMMAND();
                    Item addItem = Get(Inventory, toInteger(CCommand)-1);
                    // Kondisi sama dengan stack yg di order tp belum dibikin 
                    if (!StackFull(Build)) {
                        UpdateList(&Inventory, addItem.nama, addItem.kode, -1, addItem.harga);
                        Komponen X;
                        strcpy(X.nama, addItem.nama.TabKata);
                        // X.nama = addItem.nama.TabKata;
                        X.harga = addItem.harga;
                        X.kode = addItem.kode;
                        X.jumlah = addItem.jumlah;
                        Push(&Build, X);
                        if (Build.T[Build.TOP].kode != addItem.kode) {
                            printf("Komponen berhasil dipasang!\n");
                        } 
                    }
                } else {
                    printf("Kamu belum memulai build apapun.\n");
                }
            }
        } else if (IsKataSama(CCommand, toKata("REMOVECOMPONENT"))) {
            if (loc != 0) {
                printf("Kamu harus di base untuk melepas komponen!\n");
            } else {
                if (!StackEmpty(Build)) {
                    Komponen X;
                    Pop(&Build, &X);
                    UpdateList(&Inventory, toKata(X.nama), X.kode, 1, X.harga);
                    printf("Komponen %s berhasil dicopot!\n", X.nama); 
                } else {
                    printf("Belum ada komponen terpasang!\n");
                }
            }
        } else if (IsKataSama(CCommand, toKata("SHOP"))) {
            if(loc != 1) {
                printf("Kamu tidak berada di Shop.\n");
                printf("Mohon pindah ke Shop terlebih dahulu.\n");
            } else {
                printf("Komponen yang tersedia: \n");
                PrintShop(ListKomponen);
                printf("Komponen yang ingin dibeli: ");
                STARTCOMMAND();
                int index = toInteger(CCommand); 
                printf("Masukkan jumlah yang ingin dibeli: ");
                STARTCOMMAND();
                int kuantitas = toInteger(CCommand);
                Item dibeli = Get(ListKomponen, index-1);
                int total = (kuantitas)*(dibeli.harga);
                if (kuantitas == 0) {
                    printf("Kamu tidak membeli apa-apa.\n");
                } else {
                    if (total > money ) {
                        printf("Uang tidak cukup!\n");
                    } else {
                        money = money - total;
                        UpdateList(&Inventory, dibeli.nama, dibeli.kode, kuantitas, dibeli.harga);
                        printf("Komponen berhasil dibeli!\n");
                    }
                }
            }

        } else if (IsKataSama(CCommand, toKata("DELIVER"))) {
            printf("DELIVER masuk\n");
            // IsBuild = false;
            IsDelivered = true;

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
                fprintf(output, "%s\n", namafile);
                fprintf(output, "%d\n", money);
                fprintf(output, "%d\n", order);
                fprintf(output, "%d\n", cust);
                fprintf(output, "%d\n", loc);
                if (IsBuild) {
                    fprintf(output, "%d\n", 1);
                } else {
                    fprintf(output, "%d\n", 0);
                }
        // yg ini skip aja anggap selalu mulai dari base
                // ElType temp = 'B';
                // POINT getTemp = GetPoint(M, temp);
                // ElType player = 'P';
                // SetElmt(&M, getTemp.X, getTemp.Y, player);
                // POINT getPlayer = GetPoint(M, player);
        
        // yg ini nanti lg mager
                // List Inventory = MakeList();
                // Stack Build;
                // CreateStack(&Build);
                // Stack Order;
                // CreateStack(&Order);
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
        // i++;
    }
    printf("\nTerima kasih sudah bermain.\n");
    printf("--------------------------------\n");
    return 0;
}