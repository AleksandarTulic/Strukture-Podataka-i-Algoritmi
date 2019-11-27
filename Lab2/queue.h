#ifndef queue_h

/* STRUKTURA STABLA */

typedef struct node{
    double v;
    char c;
    struct node *left;
    struct node *right;
    struct node *parent;
    char bin;
}NODE;

/* STRUKTURA PQ */

typedef struct qnode{
    NODE *p;
    struct qnode *left;
    struct qnode *right;
}QNODE;

/* DODAVANJE CVORA PRI CEMU SE SORTIRA PO RASTUCEM - PQ */

QNODE *Q_ADD(QNODE **, NODE *);

/* BRISANJE PRVOG CVORA ODNOSNO NAJMANJE VRIJEDNOSTI PRI CEMU SE VRACA ADRESA CVORA STABLA */

NODE *Q_MIN_DELETE(QNODE **);

/* ISPIS LISTE */

void Q_PRINT(QNODE *);

#endif // queue_h
