#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "file.h"

NODE *GETNODE(){
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->left = new->parent = new->right = 0;
    new->c = '/';
    new->v = 0.0;
    new->bin = '0';
    return new;
}

void PREORDER(NODE *p){
    if ( p == 0 ) return;

    printf("Character: %c, Value: %.10lf\n", p->c, p->v);
    PREORDER(p->left);
    PREORDER(p->right);
}

/*

    POZIVAMO FUNKCIJA ZA LIJEVO PODSTABLO I DESNO PODSTABLO
    NIZ PROMJENLJIVA KOJA PAMTI 0 LIJEVO ILI 1 DESNO
    KADA DODJE DO KRAJNJEG CVORA ISPISUJE VRIJEDNOSTI ODGOVARAJUCEG ZNAKA(ZNAMO DA SU KRANJI
CVOROVI UVIJEK NEKOG ZNAKA)
    LEVEL PROMJENLJIVA KOJA NAM POMAZE DA PAZIMO NA KOJE MJESTO DA DODAMO 0 ILI 1

*/

void ispis(NODE *p, char niz[70], int level){
    if ( p == 0 ){
        return;
    }
    niz[level-1] = p->bin;
    niz[level] = '\0';
    level++;

    if ( p->right == 0 && p->left == 0 ){
        printf("Character: %c, Binary String: %s\n", p->c, niz);
    }

    ispis(p->left, niz, level);
    ispis(p->right, niz, level);
}

int main()
{
    QNODE *p = 0;
    input();

    int i = 0;
    int broj = 0;
    for (;i<62;i++){
        if ( p_c[i].v == 0.0 ) continue;

        broj++;
        NODE *Z = GETNODE();

        Z->v = p_c[i].v;
        Z->c = p_c[i].ch;

        Q_ADD(&p, Z);
    }

    for (i=0;i<broj-1;i++){
        NODE *Z = GETNODE();

        Q_PRINT(p);

        NODE *X = Q_MIN_DELETE(&p);
        NODE *Y = Q_MIN_DELETE(&p);

        Z->v = X->v + Y->v;
        X->bin = '0';
        Y->bin = '1';
        Z->left = X;
        Z->right = Y;
        X->parent = Y->parent = Z;

        Q_ADD(&p, Z);
    }

    NODE *p_node = Q_MIN_DELETE(&p);

    PREORDER(p_node);

    char niz[70];
    niz[0] = '\0';

    ispis(p_node->right, niz, 1);
    ispis(p_node->left, niz, 1);
    return 0;
}
