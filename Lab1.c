#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor{
    struct cvor *left;
    struct cvor *right;
    char proces[1000];
    int second;
}CVOR;

int suma = 0;
int n;

CVOR *add_begin(CVOR **p, int i){
    CVOR *new = (CVOR*)malloc(sizeof(CVOR));
    new->second = rand() % 5 + 1;
    strcpy(new->proces, "proces\0");

    suma+= new->second;

    char broj[100];
    itoa(i, broj, 10);

    strcat(new->proces, broj);

    if ( *p == 0 ){
        new->left = new;
        new->right = new;

        *p = new;
    }else{
        new->left = (*p)->left;
        new->right = *p;
        (*p)->left = new;

        *p = new;
    }

    return new;
}

void print_right(CVOR *p, int flag){
    int i = 0;
    for (;i<n;i++){
        if (flag) Sleep(p->second * 1000);
        printf("%s %d\n", p->proces, p->second);
        p = p->right;
    }
}

void print_left(CVOR *p){
    int i = 0;
    for (;i<n;i++){
        Sleep(p->second * 1000);
        printf("%s %d\n", p->proces, p->second);
        p = p->left;
    }
}

int main(){
    printf("Unesite broj procesa: ");
    scanf("%d", &n);

    CVOR *p = 0;

    int i = 1;
    for (;i<=n;i++){
        p = add_begin(&p, i);
    }

    print_right(p, 0);

    int smjer = -1;
    do{
        printf("Izaberite smjer ispisa: \n");
        printf("     - Lijevo [1]\n");
        printf("     - Desno  [2]\n");
        scanf("%d", &smjer);
    }while (smjer != 1 && smjer != 2);

    char str[100];
    do{
        printf("Unesite naredbu START: ");
        scanf("%s", str);
    }while ( strcmp(str, "START") != 0 );

    if ( smjer == 1 ){
        print_left(p);
    }else{
        print_right(p, 1);
    }

    printf("Suma izvrsavanja procesa je: %d", suma);
    return 0;
}
