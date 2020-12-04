#include <stdio.h>
#include "../mesinkar/mesinkar.h"

static FILE * pita;
static FILE * command;
static int retval;

char CC;
boolean EOP;

/* *** ADT untuk baca file eksternal *** */

void START(char* filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = fopen(filename,"r");
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



/* *** ADT untuk baca file eksternal *** */

void COMMAND() 
/*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != ENTER maka EOP akan padam (false)
    Jika CC = ENTER maka EOP akan menyala (true) */
{
    pita = stdin;
    ADVC();
}


void ADVC()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != ENTER
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = ENTER
Jika CC = ENTER maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == ENTER);
    if (EOP) {
        // fclose(pita); --> Membiarkan agar pita dapat terus terbaca oleh mesin
    }
}

