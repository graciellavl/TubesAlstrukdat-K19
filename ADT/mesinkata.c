#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK){
        ADV();
    }
}

void STARTCOMMAND()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    COMMAND();
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    } else {
        EndKata = false;
        ADVKATA();
    }
}

void STARTGAME(char* filename)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(filename);
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    } else {
        EndKata = false;
        ADVKATA();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK && !EndKata){
        EndKata = true;
    } else{
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != MARK) && (CC != BLANK) && i != NMax) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = (i < NMax) ? i : NMax;
}