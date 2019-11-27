#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QNODE *Q_ADD(QNODE **p, NODE *bp){
    QNODE *new = (QNODE*)malloc(sizeof(QNODE));
    new->left = new->right = 0;
    new->p = bp;

    if ( (*p) == 0 ){
        *p = new;
    }else{
        QNODE *buff = *p;

        while ( buff->p->v < bp->v && buff->right != 0 ){
            buff = buff->right;
        }

        if ( buff->left == 0 ){
            new->right = buff;
            buff->left = new;
            *p = new;
        }else if ( buff->right == 0 ){
            if ( buff->p->v <= bp->v ){
                new->left = buff;
                buff->right = new;
            }else{
                new->left = buff->left;
                new->right = buff;
                buff->left->right = new;
                buff->left = new;
            }
        }else{
            new->left = buff->left;
            new->right = buff;
            buff->left->right = new;
            buff->left = new;
        }
    }

    return new;
}

NODE *Q_MIN_DELETE(QNODE **p){
    if ( *p == 0 ) return 0;
    QNODE *buff1 = *p;
    NODE *buff2 = buff1->p;

    *p = (*p)->right;
    if ( *p != 0 ) (*p)->left = 0;
    free(buff1);

    return buff2;
}

void Q_PRINT(QNODE *p){
    while ( p ){
        printf("%.2lf ", p->p->v);
        p = p->right;
    }

    printf("\n");
}
