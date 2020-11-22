#include <stdio.h>
#include "mesinkar.h"

static FILE * pita;
static FILE * command;
static int retval;

char CC;
boolean EOP;

void START(char* filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = fopen("pitakar.txt","r");
    ADV();
}

void COMMAND() {
    pita = stdin;
    ADV();
}

void ADV()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
        fclose(pita);
    }
}
