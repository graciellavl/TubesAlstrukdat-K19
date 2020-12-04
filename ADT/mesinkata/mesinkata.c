#include <stdio.h>
#include "mesinkata.h"
#include "../mesinkar/mesinkar.h"

boolean EndKata;
Kata CKata;
Kata CCommand;

/* *** ADT untuk baca file eksternal *** */

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK || CC == ENTER){
        ADV();
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
    while ((CC != MARK) && (CC != BLANK) && (CC != ENTER) && i != NMax) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = (i < NMax) ? i : NMax;
}



/* *** ADT untuk baca commands *** */

void IgnoreDot()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK) && (CC == '.')) {
        ADVC();
    }
}

void STARTCOMMAND()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    COMMAND();
    IgnoreDot();
    if (CC == ENTER){
        EndKata = true;
    } else {
        EndKata = false;
        ADVCOMMAND();
    }
}


void ADVCOMMAND()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreDot();
    if (CC == ENTER && !EndKata){
        EndKata = true;
    } else{
        SalinCommand();
        IgnoreDot();
    }
}

void SalinCommand()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != BLANK) && (CC != ENTER) && i != NMax) {
        CCommand.TabKata[i] = CC;
        ADVC();
        i++;
    }
    CCommand.Length = (i < NMax) ? i : NMax;
}

// addition

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

void PrintKata(Kata K) {
    for (int i = 0; i < K.Length; i ++) {
        printf("%c", K.TabKata[i]);
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