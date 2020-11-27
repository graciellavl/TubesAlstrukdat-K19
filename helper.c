// gak jadi pakai

#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/matriks.h"

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