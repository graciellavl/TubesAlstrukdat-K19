#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"

Kata MOVE;
Kata STATUS;
Kata CHECKORDER;
Kata STARTBUILD;
Kata FINISHBUILD;
Kata ADDCOMPONENT;
Kata REMOVECOMPONENT;
Kata SHOP;
Kata DELIVER;
Kata END_DAY;
Kata SAVE;
Kata MAP;
Kata EXIT;

void Command() {
    MOVE.TabKata[0] = 'M';
    MOVE.TabKata[1] = 'O';
    MOVE.TabKata[2] = 'V';
    MOVE.TabKata[3] = 'E';
    MOVE.Length = 4;

    CHECKORDER.TabKata[0] = 'C';
    CHECKORDER.TabKata[1] = 'H';
    CHECKORDER.TabKata[2] = 'E';
    CHECKORDER.TabKata[3] = 'C';
    CHECKORDER.TabKata[4] = 'K';
    CHECKORDER.TabKata[5] = 'O';
    CHECKORDER.TabKata[6] = 'R';
    CHECKORDER.TabKata[7] = 'D';
    CHECKORDER.TabKata[8] = 'E';
    CHECKORDER.TabKata[9] = 'R';
    CHECKORDER.Length = 10;

    STARTBUILD.TabKata[0] = 'S';
    STARTBUILD.TabKata[1] = 'T';
    STARTBUILD.TabKata[2] = 'A';
    STARTBUILD.TabKata[3] = 'R';
    STARTBUILD.TabKata[4] = 'T';
    STARTBUILD.TabKata[5] = 'B';
    STARTBUILD.TabKata[6] = 'U';
    STARTBUILD.TabKata[7] = 'I';
    STARTBUILD.TabKata[8] = 'L';
    STARTBUILD.TabKata[9] = 'D';
    STARTBUILD.Length = 10;

    FINISHBUILD.TabKata[0] = 'F';
    FINISHBUILD.TabKata[1] = 'I';
    FINISHBUILD.TabKata[2] = 'N';
    FINISHBUILD.TabKata[3] = 'I';
    FINISHBUILD.TabKata[4] = 'S';
    FINISHBUILD.TabKata[5] = 'H';
    FINISHBUILD.TabKata[6] = 'B';
    FINISHBUILD.TabKata[7] = 'U';
    FINISHBUILD.TabKata[8] = 'I';
    FINISHBUILD.TabKata[9] = 'L';
    FINISHBUILD.TabKata[10] = 'D';
    FINISHBUILD.Length = 11;

    ADDCOMPONENT.TabKata[0] = 'A';
    ADDCOMPONENT.TabKata[1] = 'D';
    ADDCOMPONENT.TabKata[2] = 'D';
    ADDCOMPONENT.TabKata[3] = 'C';
    ADDCOMPONENT.TabKata[4] = 'O';
    ADDCOMPONENT.TabKata[5] = 'M';
    ADDCOMPONENT.TabKata[6] = 'P';
    ADDCOMPONENT.TabKata[7] = 'O';
    ADDCOMPONENT.TabKata[8] = 'N';
    ADDCOMPONENT.TabKata[9] = 'E';
    ADDCOMPONENT.TabKata[10] = 'N';
    ADDCOMPONENT.TabKata[11] = 'T';
    ADDCOMPONENT.Length = 12;

    REMOVECOMPONENT.TabKata[0] = 'R';
    REMOVECOMPONENT.TabKata[1] = 'E';
    REMOVECOMPONENT.TabKata[2] = 'M';
    REMOVECOMPONENT.TabKata[3] = 'O';
    REMOVECOMPONENT.TabKata[4] = 'V';
    REMOVECOMPONENT.TabKata[5] = 'E';
    REMOVECOMPONENT.TabKata[6] = 'C';
    REMOVECOMPONENT.TabKata[7] = 'O';
    REMOVECOMPONENT.TabKata[8] = 'M';
    REMOVECOMPONENT.TabKata[9] = 'P';
    REMOVECOMPONENT.TabKata[10] = 'O';
    REMOVECOMPONENT.TabKata[11] = 'N';
    REMOVECOMPONENT.TabKata[12] = 'E';
    REMOVECOMPONENT.TabKata[13] = 'N';
    REMOVECOMPONENT.TabKata[14] = 'T';
    REMOVECOMPONENT.Length = 15;

    SHOP.TabKata[0] = 'S';
    SHOP.TabKata[1] = 'H';
    SHOP.TabKata[2] = 'O';
    SHOP.TabKata[3] = 'P';
    SHOP.Length = 4;

    DELIVER.TabKata[0] = 'D';
    DELIVER.TabKata[1] = 'E';
    DELIVER.TabKata[2] = 'L';
    DELIVER.TabKata[3] = 'I';
    DELIVER.TabKata[4] = 'V';
    DELIVER.TabKata[5] = 'E';
    DELIVER.TabKata[6] = 'R';
    DELIVER.Length = 7;

    END_DAY.TabKata[0] = 'E';
    END_DAY.TabKata[1] = 'N';
    END_DAY.TabKata[2] = 'D';
    END_DAY.TabKata[3] = '_';
    END_DAY.TabKata[4] = 'D';
    END_DAY.TabKata[5] = 'A';
    END_DAY.TabKata[6] = 'Y';
    END_DAY.Length = 7;

    SAVE.TabKata[0] = 'S';
    SAVE.TabKata[1] = 'A';
    SAVE.TabKata[2] = 'V';
    SAVE.TabKata[3] = 'E';
    SAVE.Length = 4;

    EXIT.TabKata[0] = 'E';
    EXIT.TabKata[1] = 'X';
    EXIT.TabKata[2] = 'I';
    EXIT.TabKata[3] = 'T';
    EXIT.Length = 4;

    MAP.TabKata[0] = 'M';
    MAP.TabKata[1] = 'A';
    MAP.TabKata[2] = 'P';
    MAP.Length = 3;
}

Kata toKata(char* command) {
    int i;
    Kata output;
    for (i = 0; i < sizeof(command); i++) {
        output.TabKata[i] = command[i];
    }
    output.Length = sizeof(command);
    return output;
}