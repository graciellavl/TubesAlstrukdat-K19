/* *** ******** ******** ******** ******** ******** ****** *** KELOMPOK 19 *** ****** ******** ******** ******** ******** ******** *** */
                                                /* 18219075 Graciella Valeska Liander   */
                                                /* 18219034 Aindrea Rayhan Supriyanto   */
                                                /* 18219061 Gian Denggan Bendjamin      */
                                                /* 18219074 Kumaras Gideon Sitorus      */
                                                /* 18219098 Muhamad Agung Ahsary        */


/* *** ******** ******** ******** ******** ******** ****** *** LIBRARY YANG DIGUNAKAN *** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* *** ******** ******** ******** ******** ******** ****** *** FILE HEADER *** ****** ******** ******** ******** ******** ******** *** */

#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/matriks/matriks.h"
#include "ADT/point/point.h"
#include "ADT/graph/graph.h"
#include "ADT/arraydinamis/arraydinamis.h"
#include "ADT/stack/stack.h"
#include "ADT/queue/queue.h"

/* *** ******** ******** ******** ******** ******** ****** *** FUNGSI PEMBANTU *** ****** ******** ******** ******** ******** ******** *** */

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

void stringCopy (char* dest, char* src){
    int i;
    for (i = 0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void kataStringCopy (char* dest, Kata src){
    int i;
    for (i = 0; i < src.Length && src.TabKata[i] != '\0'; ++i) {
        dest[i] = src.TabKata[i];
    }
    dest[i] = '\0';
}

Kata NamaBangunan(int loc) {
    Kata cur;
    if (loc == 0) {
        cur = toKata("Base"); 
    } else if (loc == 1) {
        cur = toKata("Shop");
    } else {
        cur = toKata("Pelanggan ");
    }
    return cur;
}

char* PrintError(int i){
    switch (i)
    {
    case 1:
        return "Motherboard";
        break;
    case 2:
        return "CPU";
        break;
    case 3:
        return "Memory";
        break;
    case 4:
        return "CPU Cooler";
        break;
    case 5:
        return "Case";
        break;
    case 6:
        return "GPU";
        break;
    case 7:
        return "Storage";
        break;
    case 8:
        return "PSU";
        break;
    default:
        break;
    }
}

void CreateOrder (List ListKomponen, Queue * QOrder) {
    int randomNumber;
    int count = rand() %10 +1;
    time_t t;
    srand((unsigned) time(&t));
    for (randomNumber = 0; randomNumber < count; randomNumber++) {
        infoOrder info;
        info.hargaPesanan = (rand() % 1000) + 2000;
        info.noPelanggan = (rand() % 7) +1;
        Stack S;
        CreateStack(&S);
        int i = 1;
        int increment = 1;
        List temp = MakeList();
        while (increment < 9) {
            while (ListKomponen.A[i].kode == increment) {
                InsertLast(&temp, ListKomponen.A[i].nama, ListKomponen.A[i].kode, 1, ListKomponen.A[i].harga);
                i++;
            }
            int randomKomponen = rand() % Length(temp);
            Komponen K;
            K.kode = temp.A[randomKomponen].kode;
            K.jumlah = temp.A[randomKomponen].jumlah;
            K.harga = temp.A[randomKomponen].harga;
            kataStringCopy(K.nama, temp.A[randomKomponen].nama);
            Push(&S, K);
            increment ++;
            temp = MakeList();
        }
        info.daftarKomponen = S;
        Enqueue(QOrder, info);
    } 
}


/* *** ******** ******** ******** ******** ******** ****** *** FUNGSI UTAMA *** ****** ******** ******** ******** ******** ******** *** */

int main() {
    // Menginisiasi permainan 
    List ListKomponen = MakeList();
    STARTGAME("item.txt");
    Kata komponen;
    while (CC != MARK) {
        int kode = toInteger(CKata);
        ADVKATA();
        int harga = toInteger(CKata);
        ADVKATA();
        InsertLast(&ListKomponen, CKata, kode, 1, harga);
        ADVKATA();
    }

/* *** ******** ******** ******** ******** ******** ****** *** VARIABEL GLOBAL *** ****** ******** ******** ******** ******** ******** *** */

    int money = 5000;           // uang
    int noPelanggan;            // pelanggan terakhir
    int hargaPesanan;           // harga pesanan terakhir
    int order = 1;              // pesanan ke -
    int loc = 0;                // lokasi saat ini
    boolean IsBuild = false;    // status build
    boolean IsDelivered = true; // status deliver

/* *** ******** ******** ******** ******** ******** ****** *** SETTING BUILD *** ****** ******** ******** ******** ******** ******** *** */

    List Inventory = MakeList();
    Stack Build;
    CreateStack(&Build);
    Stack Order;
    CreateStack(&Order);
    Queue QOrder;
    CreateQueue(&QOrder);

/* *** ******** ******** ******** ******** ******** ****** *** PROGRAM UTAMA *** ****** ******** ******** ******** ******** ******** *** */

    printf("___       ________________ _____________________  ____________\n");
    printf("__ |     / /__  ____/__  / __  ____/_  __ \\__   |/  /__  ____/\n");
    printf("__ | /| / /__  __/  __  /  _  /    _  / / /_  /|_/ /__  __/   \n");
    printf("__ |/ |/ / _  /___  _  /___/ /___  / /_/ /_  /  / / _  /___   \n");
    printf("____/|__/  /_____/  /_____/\\____/  \\____/ /_/  /_/  /_____/  \n");
    printf("Santo Tycoon | Kelompok 19 | IF2111 Algoritma dan Struktur Data \n\n");
    printf("Play or Load?\n(P/L): ");
    STARTCOMMAND();
    printf("\n");

    char* state = CCommand.TabKata;
    char namafile[100];
    while (!IsKataSama(CCommand, toKata("L")) && !IsKataSama(CCommand, toKata("P"))) {
        printf("Inputan tidak valid!\n");
        printf("(P/L): ");
        STARTCOMMAND();
    }

/* *** ******** ******** ******** ******** ******** ****** *** LOAD PERMAINAN *** ****** ******** ******** ******** ******** ******** *** */

    if (IsKataSama(CCommand, toKata("L"))) {
        char file[100];
        printf("Nama file permainan yang disimpan: ");
        STARTCOMMAND();
        kataStringCopy(file, CCommand);

        printf("Nama file konfigurasi yang digunakan: ");
        STARTCOMMAND();
        kataStringCopy(namafile, CCommand);
        
        STARTGAME(file);

        money = toInteger(CKata);
        ADVKATA();

        noPelanggan = toInteger(CKata);
        ADVKATA();

        hargaPesanan = toInteger(CKata);
        ADVKATA();

        order = toInteger(CKata);
        ADVKATA();
        
        loc = toInteger(CKata);
        ADVKATA();
        
        if (toInteger(CKata) == 1) {
            IsBuild = true;
        } else {
            IsBuild = false;
        }
        ADVKATA();
        
        if (toInteger(CKata) == 1) {
            IsDelivered = true;
        } else {
            IsDelivered = false;
        }
        ADVKATA();
        
        int inv = toInteger(CKata);
        for (int i = 0; i < inv; i++) {
            ADVKATA();
            int hargainv = toInteger(CKata);
            ADVKATA();
            int jlhinv = toInteger(CKata);
            ADVKATA();
            int kodeinv = toInteger(CKata);
            ADVKATA();
            InsertLast(&Inventory, CKata, kodeinv, jlhinv, hargainv);
        }
        
        ADVKATA();
        int qorder = toInteger(CKata);
        
        Stack tempLoad;
        CreateStack(&tempLoad);
        Komponen KLoad;
        infoOrder orderLoad;
        int noCust;
        int harga;

        for (int i = 0; i < qorder; i++) {
            ADVKATA();
            noCust = toInteger(CKata);
            ADVKATA();
            harga = toInteger(CKata);
            for (int j = 0; j < 8; j++) {
                ADVKATA();
                kataStringCopy(KLoad.nama, CKata);
                ADVKATA();
                KLoad.harga = toInteger(CKata);
                ADVKATA();
                KLoad.jumlah = toInteger(CKata);
                ADVKATA();
                KLoad.kode = toInteger(CKata);
                Push(&tempLoad, KLoad);
            }
            orderLoad.noPelanggan = noCust;
            orderLoad.hargaPesanan = harga;
            orderLoad.daftarKomponen = tempLoad;
            Enqueue(&QOrder, orderLoad);
        }
        ADVKATA();
        for (int j = 0; j < 8; j++) {
            kataStringCopy(KLoad.nama, CKata);
            ADVKATA();
            KLoad.harga = toInteger(CKata);
            ADVKATA();
            KLoad.jumlah = toInteger(CKata);
            ADVKATA();
            KLoad.kode = toInteger(CKata);
            Push(&Order, KLoad);
            ADVKATA();
        }
        while (CC != '.') {
            kataStringCopy(KLoad.nama, CKata);
            ADVKATA();
            KLoad.harga = toInteger(CKata);
            ADVKATA();
            KLoad.jumlah = toInteger(CKata);
            ADVKATA();
            KLoad.kode = toInteger(CKata);
            Push(&Build, KLoad);
            ADVKATA();
        }
    } else {
        CreateOrder(ListKomponen, &QOrder);
        noPelanggan = InfoHead(QOrder).noPelanggan;
        hargaPesanan = InfoHead(QOrder).hargaPesanan;
        /* *** Membaca Nama File Konfigurasi *** */
        printf("\nSelamat memulai permainan baru!\n");
        printf("FILENAME: ");
        STARTCOMMAND();
        kataStringCopy(namafile, CCommand);
        
        /* *** Membaca File Konfigurasi Permainan *** */
    }

/* *** ******** ******** ******** ******** ******** ****** *** BACA FILE KONFIGURASI *** ****** ******** ******** ******** ******** ******** *** */

    STARTGAME(namafile);
    // Membaca Baris
    int Brs = toInteger(CKata);
    ADVKATA();

    // Membaca Kolom
    int Kol = toInteger(CKata);
    ADVKATA();

    int jlhBangunan = toInteger(CKata);
    MATRIKS M;
    MakeMatriks(Brs, Kol, &M);
    int pelanggan = 0;
    for (int i = 0; i < jlhBangunan; i++) {
        ADVKATA();
        ElType jenis = toBangunan(CKata);
        if (jenis == 'C') {
            pelanggan += 1 ;
            jenis = toChar(pelanggan);
        }
        ADVKATA();
        int Baris = toInteger(CKata);
        ADVKATA();
        int Kolom = toInteger(CKata);
        SetElmt(&M, Baris, Kolom, jenis);
    }
    Graph G;
    CreateGraph(&G, 0);
    for (int i = 1; i < jlhBangunan; i++) {
        InsertNode(&G, i);
    }
    for (int i = 0; i < jlhBangunan; i++) {
        for (int j = 0; j < jlhBangunan; j++) {
            ADVKATA();
            if (CKata.TabKata[0] == '1') {
                InsertSuccNode(&G, i, j);
            }
        }
    }
    
/* *** ******** ******** ******** ******** ******** ****** *** STATE PEMAIN *** ****** ******** ******** ******** ******** ******** *** */

    loc = 0; 
    ElType temp = 'B';
    POINT getTemp = GetPoint(M, temp);
    ElType player = 'P';
    SetElmt(&M, getTemp.X, getTemp.Y, player);
    POINT getPlayer = GetPoint(M, player);

/* *** ******** ******** ******** ******** ******** ****** *** MEMULAI PERMAINAN *** ****** ******** ******** ******** ******** ******** *** */

    printf("\n---------------------------------------------------------\n");
    printf("SELAMAT BERMAIN\n");
    printf("---------------------------------------------------------\n");
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    printf("\n");

/* *** ******** ******** ******** ******** ******** ****** *** LOOPING COMMAND *** ****** ******** ******** ******** ******** ******** *** */

    while (!IsKataSama(CCommand, toKata("EXIT"))) {
    
/* *** ******** ******** ******** ******** ******** ****** *** MOVE *** ****** ******** ******** ******** ******** ******** *** */

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
                    printf("Kamu telah mencapai lokasi Pelanggan %c!\n", toChar(loc-1));
                }
            } else {
                printf("Tujuan tidak valid.\n");
            }

/* *** ******** ******** ******** ******** ******** ****** *** STATUS *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("STATUS"))) {
            printf("Uang tersisa: $%d\n", money);
            if (IsBuild) {
                printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", order, InfoHead(QOrder).noPelanggan);
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

/* *** ******** ******** ******** ******** ******** ****** *** CHECKORDER *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("CHECKORDER"))) {
            if (!QueueEmpty(QOrder)) {
                printf("Nomor order: %d\n", order);
                printf("Pemesan: Pelanggan %d\n", InfoHead(QOrder).noPelanggan);
                printf("Invoice: $%d\n", InfoHead(QOrder).hargaPesanan); 
                printf("Komponen: \n");
                PrintStack(InfoHead(QOrder).daftarKomponen);
            } else {
                printf("Tidak ada pesanan saat ini!\n");
            }

/* *** ******** ******** ******** ******** ******** ****** *** STARTBUILD *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("STARTBUILD"))) {
            if (loc != 0) {
                printf("Kamu harus berada di Base untuk memulai sebuah build.\n");
            } else {
                if (!QueueEmpty(QOrder)) {
                    Order = InfoHead(QOrder).daftarKomponen;
                    CreateStack(&Build);
                    if (IsDelivered) {
                        IsBuild = true;
                        IsDelivered = false;
                        printf("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", order, InfoHead(QOrder).noPelanggan);
                    } else {
                        printf("Kamu belum menyelesaikan pesananmu!\n");
                    }
                } else {
                    printf("Kamu telah menyelesaikan semua pesanan hari ini!\n");
                }
            }

/* *** ******** ******** ******** ******** ******** ****** *** FINISHBUILD *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("FINISHBUILD"))) {
            if (loc == 0) {
                if (!IsBuild) {
                    printf("Belum ada pesanan yang dimulai.\n");
                } else {
                    if (IsStackSama(Build, Order)) { 
                        IsBuild = false;
                        printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n", order, InfoHead(QOrder).noPelanggan);
                        order++;
                        infoOrder X;
                        Dequeue(&QOrder, &X);
                    } else {
                        printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
                    }
                }
            } else {
                printf("Kamu harus berada di Base untuk menyelesaikan sebuah build.\n");
            }

/* *** ******** ******** ******** ******** ******** ****** *** ADDCOMPONENT *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("ADDCOMPONENT"))) {
            if (loc != 0) {
                printf("Kamu harus di base untuk memasang komponen!\n");
            } else {
                if (IsBuild) {
                    if (!StackFull(Build)) {
                        printf("Komponen yang telah terpasang: \n");
                        PrintStack(Build);
                        printf("\n");
                        printf("Komponen yang tersedia:\n");
                        PrintInventory(Inventory);
                        printf("\n");
                        printf("Komponen yang ingin dipasang: ");
                        STARTCOMMAND();
                        if(toInteger(CCommand) <= Length(Inventory) && toInteger(CCommand) > 0) {
                            Item addItem = Get(Inventory, toInteger(CCommand)-1);
                            boolean add = true;
                            if (StackEmpty(Build)) {
                                if (addItem.kode != 1) {
                                    add = false;
                                    printf("Kamu harus memasang %s terlebih dahulu!\n", PrintError(1));
                                } 
                            } else if ((addItem.kode - Build.T[Build.TOP-1].kode) != 1){ 
                                add = false;
                                printf("Kamu harus memasang %s terlebih dahulu!\n", PrintError(Build.T[Build.TOP-1].kode + 1));
                            }
                            if (add) {
                                UpdateList(&Inventory, addItem.nama, addItem.kode, -1, addItem.harga);
                                Komponen X;
                                kataStringCopy(X.nama, addItem.nama);
                                X.harga = addItem.harga;
                                X.kode = addItem.kode;
                                X.jumlah = addItem.jumlah;
                                Push(&Build, X);
                                printf("Komponen berhasil dipasang!\n");
                            }
                        } else {
                            printf("Komponen tidak tersedia.\n");
                        }
                    } else {
                        printf("Komputer sudah selesai. Silahkan FINISHBUILD.\n");
                    }
                } else {
                    printf("Kamu belum memulai build apapun.\n");
                }
            }

/* *** ******** ******** ******** ******** ******** ****** *** REMOVECOMPONENT *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("REMOVECOMPONENT"))) {
            if (loc != 0) {
                printf("Kamu harus di base untuk melepas komponen!\n");
            } else {
                if (IsBuild){
                    if (!StackEmpty(Build)) {
                        Komponen X;
                        Pop(&Build, &X);
                        UpdateList(&Inventory, toKata(X.nama), X.kode, 1, X.harga);
                        printf("Komponen %s berhasil dicopot!\n", X.nama); 
                    } else {
                        printf("Belum ada komponen terpasang!\n");
                    }
                } else {
                    printf("Kamu belum memulai build apapun.\n");
                }
            }

/* *** ******** ******** ******** ******** ******** ****** *** SHOP *** ****** ******** ******** ******** ******** ******** *** */

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
                if (index > 0 && index <= Length(ListKomponen)) {
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
                } else {
                    printf("Item tidak tersedia.\n");
                }
            }

/* *** ******** ******** ******** ******** ******** ****** *** DELIVER *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("DELIVER"))) {
            if (IsDelivered) {
                printf("Semua pesanan telah diantar.\n");
            } else {
                if (loc-1 == noPelanggan) {
                    if (IsBuild) {
                        printf("Kamu belum menyelesaikan build pesanan!\n");    
                    } else {
                        if (!StackFull(Order)) {
                            printf("Kamu belum menyelesaikan build pesanan!\n");
                        } else {
                            IsDelivered = true;
                            money = money + hargaPesanan;
                            CreateStack(&Order);
                            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d!\n", order-1, noPelanggan);
                            if (!QueueEmpty(QOrder)) {
                                noPelanggan = InfoHead(QOrder).noPelanggan;
                                hargaPesanan = InfoHead(QOrder).hargaPesanan;
                            } else {
                                printf("Kamu sudah menyelesaikan semua pesanan hari ini!\n");
                                printf("Silahkan END_DAY untuk menambah pesanan baru!\n");
                            }
                        }
                    }
                } else {
                    printf("Kamu sedang tidak berada di Pelanggan %d.\n", noPelanggan);
                }
            }

/* *** ******** ******** ******** ******** ******** ****** *** END_DAY *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("END_DAY"))) {
            CreateOrder(ListKomponen, &QOrder);
            if (IsDelivered) {
                noPelanggan = InfoHead(QOrder).noPelanggan;
                hargaPesanan = InfoHead(QOrder).hargaPesanan;
            } 
            printf("Hari sudah berganti. Kamu telah mendapat orderan baru.\n");
            PrintQueue(QOrder, order);

/* *** ******** ******** ******** ******** ******** ****** *** SAVE *** ****** ******** ******** ******** ******** ******** *** */

        } else if (IsKataSama(CCommand, toKata("SAVE"))) {
            printf("Lokasi save file: ");
            STARTCOMMAND(); 
            char fileoutput[100];
            kataStringCopy(fileoutput, CCommand);
            FILE * output;
            output = fopen(fileoutput, "w");

            if (output == NULL) {
                printf("Permainan tidak dapat disimpan.\n");
                printf("Mohon coba kembali.\n");
            } else {
                fprintf(output, "%d ", money);
                fprintf(output, "%d ", noPelanggan);
                fprintf(output, "%d ", hargaPesanan);
                fprintf(output, "%d ", order);
                fprintf(output, "%d ", loc);
                if (IsBuild) {
                    fprintf(output, "%d ", 1);
                } else {
                    fprintf(output, "%d ", 0);
                }
                if (IsDelivered) {
                    fprintf(output, "%d\n", 1);
                } else {
                    fprintf(output, "%d\n", 0);
                }
                fprintf(output, "%d\n", Length(Inventory));
                char listinv[100];
                for (int i = 0; i < Length(Inventory); i++) {
                    fprintf(output, "%d ", Inventory.A[i].harga);
                    fprintf(output, "%d ", Inventory.A[i].jumlah);
                    fprintf(output, "%d ", Inventory.A[i].kode);
                    kataStringCopy(listinv, Inventory.A[i].nama);
                    fprintf(output, "%s\n", listinv);
                }
                Stack tempS;
                CreateStack(&tempS);
                Komponen K;
                fprintf(output, "%d\n", QElmt(QOrder));
                addressQ temp = Head(QOrder);
                while (temp != Nil) {
                    fprintf(output, "%d ", Info(temp).noPelanggan);
                    fprintf(output, "%d\n", Info(temp).hargaPesanan);
                    tempS = InverseStack(Info(temp).daftarKomponen);
                    while(!StackEmpty(tempS)) {
                        Pop(&tempS, &K);
                        fprintf(output, "%s ", K.nama);
                        fprintf(output, "%d ", K.harga);
                        fprintf(output, "%d ", K.jumlah);
                        fprintf(output, "%d ", K.kode);
                    }
                    fprintf(output, "\n");
                    temp = NextQ(temp);
                }
                Stack tempS1;
                CreateStack(&tempS1);
                tempS1 = InverseStack(Order);
                while(!StackEmpty(tempS1)) {
                    Pop(&tempS1, &K);
                    fprintf(output, "%s ", K.nama);
                    fprintf(output, "%d ", K.harga);
                    fprintf(output, "%d ", K.jumlah);
                    fprintf(output, "%d ", K.kode);
                }
                fprintf(output, "\n");

                Stack tempS2;
                CreateStack(&tempS2);
                tempS2 = InverseStack(Build);
                while(!StackEmpty(tempS2)) {
                    Pop(&tempS2, &K);
                    fprintf(output, "%s ", K.nama);
                    fprintf(output, "%d ", K.harga);
                    fprintf(output, "%d ", K.jumlah);
                    fprintf(output, "%d ", K.kode);
                }
                fprintf(output, "\n.");
            }
            fclose(output);
            printf("File berhasil disimpan ke %s!\n", fileoutput);

        } else if (IsKataSama(CCommand, toKata("MAP"))) {
            TulisMATRIKS(M);

/* *** ******** ******** ******** ******** ******** ****** *** COMMAND TIDAK VALID *** ****** ******** ******** ******** ******** ******** *** */

        } else {
            printf("Command tidak valid.\n");
        }

/* *** ******** ******** ******** ******** ******** ****** *** LOOPING COMMAND *** ****** ******** ******** ******** ******** ******** *** */

        printf("---------------------------------------------------------\n");
        printf("ENTER COMMAND: ");
        STARTCOMMAND();
        printf("\n");
    }

/* *** ******** ******** ******** ******** ******** ****** *** DEALOKASI MEMORI *** ****** ******** ******** ******** ******** ******** *** */

    Inventory = MakeList();
    DeallocateList(&Inventory);

    CreateQueue(&QOrder);
    DealokasiQ(QOrder.HEAD);

/* *** ******** ******** ******** ******** ******** ****** *** AKHIR PERMAINAN *** ****** ******** ******** ******** ******** ******** *** */

    printf("\nTerima kasih sudah bermain.\n");
    printf("---------------------------------------------------------\n");
    
    return 0;
}