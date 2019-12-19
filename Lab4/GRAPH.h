#ifndef graf
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 100
typedef struct node{
    int broj;
    char info;
    struct node *next;
}NODE;

typedef struct graph{
    int n;
    NODE *niz[MAX];
    char val[MAX];
}GRAPH;

typedef struct red{
}RED;

/*============== GRAPH ==============*/

void PRINT_NEIGH(NODE *);
void INPUT_MATRIX(GRAPH *);
NODE *ADD_END(NODE **, char, int);
void DELETE_GRAPH(GRAPH *);
void DELETE_LIST(NODE **);

/*============== QUEUE ==============*/

void ADD_Q(NODE **, NODE **, NODE *);
void PRINT_Q(NODE *);
void DELETE_Q(NODE **, NODE **);
int DELETE(NODE **, NODE **, NODE *);

/*============== BOTH ===============*/

void bfs(GRAPH *);
void dfs(GRAPH *);
void floyd(GRAPH *);

#endif // graf
