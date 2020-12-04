#include "stack.h"
#include "../mesinkata/mesinkata.h"

void CreateStack(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    S->TOP = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean StackEmpty(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    return S.TOP == Nil;
}

boolean StackFull(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return S.TOP == MaxEl;
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, Komponen X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
	if (StackEmpty(*S)) {
		(*S).TOP = 1;
	} else {
		(*S).TOP += 1;
	}
	(*S).T[(*S).TOP-1] = X;
}

void Pop(Stack *S, Komponen *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	(*X) = (*S).T[(*S).TOP-1];
	if ((*S).TOP == 1) {
		(*S).TOP = Nil;
	} else {
		(*S).TOP--;
	}
}

Stack InverseStack(Stack S) 
/* Mengirim Stack yang merupakan kebalikan dari Stack yang diinput */
{
    Stack temp;
    CreateStack(&temp);
    Komponen K;
    address P = S.TOP;
    while (!StackEmpty(S)) {
        Pop(&S, &K);
        Push(&temp, K);
        P = S.TOP;
    }
    return temp;
}

void PrintStack(Stack S) 
/* Mencetak Stack ke layar sesuai format yang diinginkan */
/* I.S. S terdefinisi */
/* F.S. Stack tercetak pada layar */
{
    if (StackEmpty(S)){
        printf("Belum ada komponen terpasang.\n");
    } else {
        Stack temp;
        temp = InverseStack(S);
        Komponen K;
        address P = S.TOP;
        int count = 1;
        while(!StackEmpty(temp)) {
            Pop(&temp, &K);
            printf("%d. %s\n", count, K.nama);
            P = temp.TOP;
            count++;
        }
    }
}

boolean IsStackSama(Stack S1, Stack S2) 
/* Mengirim true jika stack S1 dan stack S2 sama */
/* Ciri stack sama : Semua elemennya bernilai sama */
{
    Komponen K1;
    Komponen K2;
    boolean sama = true;
    if (StackFull(S1) && StackFull(S2)) {
        while ( !StackEmpty(S1) && !StackEmpty(S2) && sama) {
            Pop(&S1, &K1);
            Pop(&S2, &K2);
            if (!IsKataSama(toKata(K1.nama), toKata(K2.nama))) {
                sama = false;
            }
        }
    } else {
        sama = false;
    }
    return sama;
}