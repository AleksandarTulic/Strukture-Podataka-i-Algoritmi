#include "graph.h"

void PRINT_NEIGH(NODE *p){
    while ( p ){
        printf("%c\n", p->info);
        p = p->next;
    }
}

NODE *ADD_END(NODE **p, char info, int broj){
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->next = 0;
    new->info = info;
    new->broj = broj;

    if ( *p == 0 ){
        *p = new;
    }else{
        NODE *h;
        for (h = *p; h->next;h=h->next);
        h->next = new;
    }

    return new;
}

void INPUT_MATRIX(GRAPH *g){
    FILE *fp = fopen("matrix.txt", "r");

    fscanf(fp, "%d\n", &g->n);

    char buff[g->n];

    int i=0;
    for (;i<g->n;i++){
        fscanf(fp, "%c\n", &buff[i]);
    }

    for (i=0;i<g->n;i++){
        g->niz[i] = 0;
    }

    for (i=0;i<g->n;i++){
        char t[100];
        fscanf(fp, "%s\n", t);

        ADD_END(&g->niz[i], buff[i], i);

        int j = 0;
        for (;j<g->n;j++){
            if ( t[j] == '1' ){
                ADD_END(&g->niz[i], buff[j], j);
            }
        }

        g->val[i] = buff[i];
    }

    fclose(fp);
}

void DELETE_LIST(NODE **p){
    while ( *p ){
        NODE *q = (*p)->next;
        free(*p);
        *p = q;
    }
}

void DELETE_GRAPH(GRAPH *g){
    int i;

    for (i=0;i<g->n;i++){
        DELETE_LIST(&g->niz[i]);
    }
}

void dfs(GRAPH *g){
    int flag[g->n];
    int i = 0;

    for (;i<g->n;i++){
        flag[i] = 0;
    }

    void dfs_traversal(int cvor){
        if ( flag[cvor] ){
            return;
        }

        flag[cvor] = 1;
        printf("%c\n", g->niz[cvor]->info);

        NODE *buff = g->niz[cvor];

        while ( buff ){
            dfs_traversal(buff->broj);
            buff = buff->next;
        }
    }

    dfs_traversal(1);
}

void bfs(GRAPH *g){
    int flag[g->n];
    int i = 0;

    for (;i<g->n;i++){
        flag[i] = 0;
    }

    NODE *f = 0;
    NODE *r = 0;
    ADD_Q(&f, &r, g->niz[0]);

    char arr[100];
    int curr = 0;

    while ( f != 0 ){
        NODE now;
        DELETE(&f, &r, &now);

        arr[curr++] = now.info;
        flag[now.broj] = 1;

        printf("DOSAD POSJECENI CVOREVI: ");
        for (i=0;i<curr;i++){
            printf("%c ", arr[i]);
        }

        printf("\n\n");

        NODE *pp = g->niz[now.broj];
        while ( pp != 0 ){
            if ( !flag[pp->broj] ){
                flag[pp->broj] = 1;
                ADD_Q(&f, &r, pp);
            }
            pp = pp->next;
        }

        printf("CVOROVE KOJE JOS TREBA POSJETITI: ");
        PRINT_Q(f);
    }
}

/*============== QUEUE ==============*/

void ADD_Q(NODE **pf, NODE **pr, NODE *buff){
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->broj = buff->broj;
    new->info = buff->info;
    new->next = 0;

    if ( *pf == 0 ){
        *pf = *pr = new;
    }else{
        (*pr)->next = new;
        *pr = new;
    }
}

void PRINT_Q(NODE *f){
    while ( f ){
        printf("%c ", f->info);
        f = f->next;
    }

    printf("\n");
}

int DELETE(NODE **pf, NODE **pr, NODE *buff){
    if ( *pf == 0 ) return 0;

    NODE *p = *pf;
    buff->broj = p->broj;
    buff->info = p->info;

    if ( *pf == *pr ) *pf = *pr = 0;
    else *pf = p->next;

    free(p);
    return 1;
}

void DELETE_Q(NODE **pf, NODE **pr){
    NODE now;
    while ( DELETE(pf, pr, &now) );
}
