#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_SECS 1.0f

void delay(int b){
    clock_t delay = b * CLOCKS_PER_SEC;
    clock_t start = clock();
    while ( ( clock() - start ) < delay );
}

typedef struct cvor{
    struct cvor *next;
    struct cvor *prev;
    char naziv[100];
    int second;
}CVOR;

int br = 1;
int suma = 0;

CVOR *add_begin(CVOR **p){
    CVOR *now = (CVOR*)malloc(sizeof(CVOR));
    strcpy(now->naziv, "naziv\0");
    int i = 0;
    while ( now->naziv[i] != '\0' ) i++;
    now->naziv[i] = (char)(br+'0');
    now->naziv[i+1] = '\0';
    br++;

    //srand(time(NULL));
    now->second = rand() % 5 + 1;

    suma+=now->second;

    now->next = 0;
    now->prev = 0;

    if ( *p == 0 ){
        *p = now;
    }else{
        now->next = *p;

        if ( (*p)->prev == 0 ){
            now->prev = *p;
            (*p)->next = now;
            (*p)->prev = now;
        }else{
            now->prev = (*p)->prev;
            (*p)->prev = now;
        }
    }

    return now;
}

void ispis(CVOR *p){
    int i = 0;

    for (;i<br-1;i++){
        printf("Naziv: %s, Sekunde: %d\n\n", p->naziv, p->second);
        p = p->next;
    }
}

void ispisl(CVOR *p){
    int i = 0;

    for (;i<br-1;i++){
        delay(p->second);
        printf("Naziv: %s, Sekunde: %d\n\n", p->naziv, p->second);
        p = p->prev;
    }
}

void ispisd(CVOR *p){
    int i = 0;

    for (;i<br-1;i++){
        delay(p->second);
        printf("Naziv: %s, Sekunde: %d\n\n", p->naziv, p->second);
        p = p->next;
    }
}


int main()
{
    CVOR *p = 0;
    int broj = 0;

    printf("Odaberite broj procesa: \n");
    scanf("%d", &broj);

    int i = 0;
    for (;i<broj;i++){
        p = add_begin(&p);
    }

    ispis(p);

    printf("Odaberite smjer: \n");
    printf("        - Lijevo [1]\n");
    printf("        - Desno  [2]\n");

    int dir;
    scanf("%d", &dir);

    printf("Unesite rijec START za pokretanje: ");
    char t[100];
    scanf("%s", t);

    if ( !strcmp(t, "START") ){
        if ( dir == 1 ){
            ispisl(p);
        }else{
            ispisd(p);
        }
    }

    printf("Ukupno vrijeme izvrsavanja procesa: %d\n", suma);
    return 0;
}
