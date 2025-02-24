#ifndef __DYNAMIC_LIST__
#define __DYNAMIC_LIST__
#include "../boolean.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"

#define InitialSize 10

typedef int IdxType;
typedef struct {
  int kode;
  int jumlah;
  int harga;
  Kata nama;
} Item;
typedef struct {
    Item *A;
    int Capacity;
    int Neff;
} List;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList();

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(List *list);

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsEmpty(List list);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(List list);

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
Item Get(List list, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(List list);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(List *list, Kata el, int qty, int kode, int harga, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(List *list, Kata el, int kode, int qty, int harga);

/**
 * Fungsi untuk mengubah komponen pada list.
 * Prekondisi: list terdefinisi
 */
void UpdateList(List *L, Kata el, int kode, int qty, int harga);

/**
 * Fungsi untuk menghapus elemen pada list.
 * Prekondisi: list terdefinisi
 */
void DeleteAt(List *list, IdxType i);

/**
 * Fungsi untuk mencari elemen pada list.
 * Prekondisi: list terdefinisi
 */
boolean SearchList(List *L, Kata el);

/**
 * Fungsi untuk menampilkan isi list sesuai format inventory.
 * Prekondisi: list terdefinisi
 */
void PrintInventory(List L);

/**
 * Fungsi untuk menampilkan isi list sesuai format shop.
 * Prekondisi: list terdefinisi
 */
void PrintShop(List L);

#endif