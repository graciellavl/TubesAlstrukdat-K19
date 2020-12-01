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
    S->T[S->TOP] = X;
    S->TOP++;
}
void Pop(Stack *S, Komponen *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    S->TOP--;
    (*X) = S->T[S->TOP];
}

Stack InverseStack(Stack S) {
    Stack temp;
    CreateStack(&temp);
    Komponen K;
    address P = S.TOP;
    while (P != Nil) {
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
        while(P != Nil) {
            Pop(&temp, &K);
            printf("%d. %s\n", count, K.nama);
            P = temp.TOP;
            count++;
        }
    }
}