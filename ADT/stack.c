#include "stack.h"

void CreateStack(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    S->TOP = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool StackEmpty(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    return S.TOP == Nil;
}

bool StackFull(Stack S)
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
    // printf("dalam push %s\n", (*S).T[(*S).TOP-1].nama);
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

Stack InverseStack(Stack S) {
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

void PrintStack(Stack S) {
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