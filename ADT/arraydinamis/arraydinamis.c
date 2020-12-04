#include "arraydinamis.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList() {
    List list;
    list.A = (Item *) malloc(InitialSize * sizeof(Item));
    list.Capacity = InitialSize;
    list.Neff = 0;
    return list;
}

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(List *list) {
    free(list->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsEmpty(List list) {
    return list.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(List list) {
    return list.Neff;
}

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
Item Get(List list, IdxType i) {
    return list.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(List list) {
    return list.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(List *list, Kata el, int qty, int kode, int harga, IdxType i) {
    int length = Length(*list);
    int capacity = GetCapacity(*list);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        Item *array = (Item *) malloc(desiredCapacity * sizeof(Item));
        for (int a = 0; a < length; a++) {
            array[a] = Get(*list, a);
        }
        free(list->A);
        
        list->A = array;
        list->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        list->A[a + 1] = list->A[a];
    }

    list->A[i].nama = el;
    list->A[i].jumlah = qty;
    list->A[i].kode = kode;
    list->A[i].harga = harga;
    list->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(List *list, Kata el, int kode, int qty, int harga) {
    int insertAt = Length(*list);
    InsertAt(list, el, qty, kode, harga, insertAt);
}

/**
 * Fungsi untuk mengubah komponen pada list.
 * Prekondisi: list terdefinisi
 */
void UpdateList(List *L, Kata el, int kode, int qty, int harga) {
    if (qty != 0) {
        if (SearchList(L, el)) {
            int capacity = Length(*L);
            for (int i=0; i < capacity; i++) {
                if (IsKataSama(el, L->A[i].nama)) {
                    L->A[i].jumlah += qty;
                    if (L->A[i].jumlah == 0) {
                        DeleteAt(L, i);
                    }
                }
            }
        } else {
            if (qty < 0) {
                printf("Komponen tidak tersedia.\n");
            } else {
                InsertLast(L, el, kode, qty, harga);
            }
        }
    }
}

/**
 * Fungsi untuk menghapus elemen pada list.
 * Prekondisi: list terdefinisi
 */
void DeleteAt(List *list, IdxType i){
    int length = Length(*list);
    if (length != 0){
        for (int a = i; a < length-1; a++) {
            list->A[a] = list->A[a + 1];
        }
        list->A[length-1].nama.Length = 0;
        list->Neff--;
    }
}

/**
 * Fungsi untuk mencari elemen pada list.
 * Prekondisi: list terdefinisi
 */
boolean SearchList(List *L, Kata el) {
    for (int i = 0; i < Length(*L); i++) {
        if ( IsKataSama(el, L->A[i].nama) ) {
            return true;
        }
    }
    return false;
}

/**
 * Fungsi untuk menampilkan isi list sesuai format inventory.
 * Prekondisi: list terdefinisi
 */
void PrintInventory(List L) {
    for (int i = 0; i < Length(L); i++) {
        Item item = Get(L, i);
        printf("%d. ", i+1);
        PrintKata(item.nama);
        printf(" (%d)\n", item.jumlah);
    }
}

/**
 * Fungsi untuk menampilkan isi list sesuai format shop.
 * Prekondisi: list terdefinisi
 */
void PrintShop(List L) {
    for (int i = 0; i < Length(L); i++) {
        Item item = Get(L, i);
        printf("%d. ", i+1);
        PrintKata(item.nama);
        printf(" - $%d\n", item.harga);
    }
}
