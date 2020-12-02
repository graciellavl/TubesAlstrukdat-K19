#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/matriks.h"
#include "ADT/point.h"
#include "ADT/graph.h"
#include "ADT/list.h"
#include "ADT/stack.h"
#include "ADT/queue.h"

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
        // cur[12] = toChar(loc-1); 
    }
    return cur;
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
        ADVKATA();
        InsertLast(&ListKomponen, CKata, kode, 1, harga);
        ADVKATA();
    }

    int money = 5000;          // uang
    int order = 1;             // pesanan ke -
    int loc = 0;               // lokasi saat ini
    boolean IsBuild = false;   // status build
    boolean IsDelivered = true;   // status deliver

    List Inventory = MakeList();
    Stack Build;
    CreateStack(&Build);
    Stack Order;
    CreateStack(&Order);
    Queue QOrder;
    CreateQueue(&QOrder);
    CreateOrder(ListKomponen, &QOrder);

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
    char* namafile;
    if (IsKataSama(CCommand, toKata("L"))) {
        printf("Load . . . \n");
        STARTGAME("save/config.txt");
    } else {
        /* *** Membaca Nama File Konfigurasi *** */
        printf("Selamat memulai permainan baru!\n");
        printf("FILENAME: ");
        STARTCOMMAND();
        namafile = CCommand.TabKata;
        
        printf("Loading . . .\n");
        /* *** Membaca File Konfigurasi Permainan *** */
        STARTGAME(CCommand.TabKata);
    }

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
    // ADVKATA();
    for (int i = 0; i < jlhBangunan; i++) {
        for (int j = 0; j < jlhBangunan; j++) {
            ADVKATA();
            if (CKata.TabKata[0] == '1') {
                InsertSuccNode(&G, i, j);
            }
        }
    }
    
// Inisialisasi state permainan
    ElType temp = 'B';
    POINT getTemp = GetPoint(M, temp);
    ElType player = 'P';
    SetElmt(&M, getTemp.X, getTemp.Y, player);
    POINT getPlayer = GetPoint(M, player);
    
// Memulai permainan

    printf("\n---------------------------------------------------------\n");
    printf("SELAMAT BERMAIN\n");
    printf("---------------------------------------------------------\n");
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    printf("\n");

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

        } else if (IsKataSama(CCommand, toKata("CHECKORDER"))) {
            printf("Nomor order: %d\n", order);
            printf("Pemesan: Pelanggan %d\n", InfoHead(QOrder).noPelanggan);
            printf("Invoice: $%d\n", InfoHead(QOrder).hargaPesanan); 
            printf("Komponen: \n");
            PrintStack(InfoHead(QOrder).daftarKomponen);

        } else if (IsKataSama(CCommand, toKata("STARTBUILD"))) {
            if (loc != 0) {
                printf("Kamu harus berada di Base untuk memulai sebuah build.\n");
            } else {
                Order = InfoHead(QOrder).daftarKomponen;
                CreateStack(&Build);
                if (IsDelivered) {
                    IsBuild = true;
                    IsDelivered = false;
                    printf("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", order, InfoHead(QOrder).noPelanggan);
                } else {
                    printf("Kamu belum menyelesaikan pesananmu!\n");
                }
            }

        } else if (IsKataSama(CCommand, toKata("FINISHBUILD"))) {
            if (!IsBuild) {
                printf("Belum ada pesanan yang dimulai.\n");
            } else {
                if (IsStackSama(Build, Order)) { 
                    PrintStack(Build);
                    PrintStack(Order);
                    IsBuild = false;
                    printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n", order, InfoHead(QOrder).noPelanggan);
                    order++;
                    infoOrder X;
                    Dequeue(&QOrder, &X);
                } else {
                    printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
                }
            }

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
                            UpdateList(&Inventory, addItem.nama, addItem.kode, -1, addItem.harga);
                            Komponen X;
                            kataStringCopy(X.nama, addItem.nama);
                            X.harga = addItem.harga;
                            X.kode = addItem.kode;
                            X.jumlah = addItem.jumlah;
                            Push(&Build, X);
                            printf("Komponen berhasil dipasang!\n");
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

        } else if (IsKataSama(CCommand, toKata("DELIVER"))) {
            if (loc-1 == InfoHead(QOrder).noPelanggan) {
                if (!IsBuild) {
                    printf("Kamu belum menyelesaikan build pesanan!\n");    
                } else {
                    if (!StackFull(Order)) {
                        printf("Kamu belum menyelesaikan build pesanan!\n");
                    } else {
                        IsDelivered = true;
                        money = money + InfoHead(QOrder).hargaPesanan;
                        CreateStack(&Order);
                        printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d!\n", order-1, InfoHead(QOrder).noPelanggan);
                    }
                }
            } else {
                printf("Kamu sedang tidak berada di Pelanggan %d.\n", InfoHead(QOrder).noPelanggan);
            }

        } else if (IsKataSama(CCommand, toKata("END_DAY"))) {
            CreateOrder(ListKomponen, &QOrder);
            printf("Hari sudah berganti. Kamu telah mendapat orderan baru.\n");

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
                fprintf(output, "%d\n", InfoHead(QOrder).noPelanggan);
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
        printf("---------------------------------------------------------\n");
        printf("ENTER COMMAND: ");
        STARTCOMMAND();
        printf("\n");
    }
    printf("\nTerima kasih sudah bermain.\n");
    printf("---------------------------------------------------------\n");
    return 0;
}