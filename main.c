#include <stdio.h>
#include <stdlib.h>

#include "ADT/mesinkar.c"
#include "ADT/mesinkata.c"
#include "ADT/matriks.c"
#include "command.c"

Kata EXIT;
Kata MAP;

// void Command() {
//     END.TabKata[0] = 'E';
//     END.TabKata[1] = 'N';
//     END.TabKata[2] = 'D';
//     END.Length = 3;

//     MAP.TabKata[0] = 'M';
//     MAP.TabKata[1] = 'A';
//     MAP.TabKata[2] = 'P';
// }

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

void GAME() {
    printf("Hi");
    // if (IsKataSama(MAP, CKata)) {
    //     TulisMATRIKS(M);
    // }
}

void ExitGame() {
    printf("Terima kasih sudah bermain.");
}

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

ElType toElType(int digit) {
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
    if (CKata.TabKata[1] == 'B') {
        return 'B';
    } else if (CKata.TabKata[1] == 'S') {
        return 'S';
    } else if (CKata.TabKata[1] == 'C') {
        return 'C';
    } else if (CKata.TabKata[1] == 'P') {
        return 'P';
    }
}

int main() {
    Command();

    /* *** Membaca File Konfigurasi Permainan *** */
    STARTGAME("pitakar.txt");

    // Membaca Baris
    int Brs = toInteger(CKata);
    // printf("Brs %d\n", Brs);
    ADVKATA();

    // Membaca Kolom
    int Kol = toInteger(CKata);
    // printf("Kol %d\n", Kol);
    ADVKATA();

    int jlhBangunan = toInteger(CKata);
    ADVKATA();

    MATRIKS M;
    MakeMatriks(Brs, Kol, &M);
    int pelanggan = 0;
    for (int i = 0; i < jlhBangunan; i++) {
        ElType jenis = toBangunan(CKata);
        if (jenis == 'C') {
            pelanggan += 1 ;
            jenis = toElType(pelanggan);
        }
        // printf("%c", jenis);
        ADVKATA();
        int Baris = toInteger(CKata);
        ADVKATA();
        int Kolom = toInteger(CKata);
        SetElmt(&M, Baris, Kolom, jenis);
        ADVKATA(); 
    }
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    while (!EndKata) {
        for (int i = 0; i < CKata.Length; i++) {
            printf("%c", CKata.TabKata[i]);
        }
        printf("%d\n", CKata.Length);
        ADVKATA();
    }
    if (!IsKataSama(CKata, EXIT)) {
        GAME(CKata);
    } else {
        ExitGame(CKata);
    }
    return 0;
}