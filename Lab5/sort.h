#include "sort.h"

void read_csv(){
    FILE *fp = fopen("movies.csv", "r");

    n = 0;

    char buff[2000];

    while ( fgets(buff, 20000, fp) ){
        int br = 0;
        niz[n].num_act = 0;

        char *p;
        p = strtok(buff, ",");

        while ( p != NULL ){
            if ( !br ){
                double d = atof(p);

                niz[n].middle_grade = d;
                br++;
            }else if ( br == 1 ){
                strcpy(niz[n].name, p);
                br++;
            }else if ( br == 2 ){
                int d = atoi(p);
                niz[n].year = d;
                br++;
            }else if ( br == 3 ){
                strcpy(niz[n].actors[niz[n].num_act], p);
                niz[n].num_act++;
            }

            p = strtok(NULL, ",");
        }

        strcpy(niz[n].genre, niz[n].actors[niz[n].num_act-1]);
        niz[n].num_act--;

        n++;
    }

    fclose(fp);
}

void shell_sort(FILM a[]){
    int h = n / 2;

    for (;h>0;h/=2){
        int i = 0;

        for (i=h;i<n;i++){
            FILM x = a[i];
            int j = 0;

            for (j=i;j>=h && x.middle_grade < a[j-h].middle_grade;j-=h){
                a[j] = a[j-h];
            }

            a[j] = x;
        }
    }
}

void m_heap(FILM a[], int vel,int br){
    int broj = br;
    int l = 2*broj+1;
    int r = 2*broj+2;

    if ( l < vel && a[l].middle_grade > a[broj].middle_grade ){
        broj = l;
    }

    if ( r < vel && a[r].middle_grade > a[broj].middle_grade ){
        broj = r;
    }

    if ( broj != br ){
        FILM x = a[br];
        a[br] = a[broj];
        a[broj] = x;

        m_heap(a, vel, broj);
    }
}

void heap_sort(FILM a[]){
    int i = 0;

    for (i = n / 2 - 1;i>=0;i--)
        m_heap(a, n, i);

    for (i=n-1;i>=0;i--){
        FILM x = a[0];
        a[0] = a[i];
        a[i] = x;

        m_heap(a, i, 0);
    }
}

int split(FILM a[], int begin, int end){
    int i = begin;
    int j = end;
    double pivot = a[begin].middle_grade;
    FILM b = a[begin];

    while ( i < j ){
        while ( a[i].middle_grade <= pivot && i < j ) i++;
        while ( a[j].middle_grade > pivot ) j--;

        if ( i < j ){
            FILM pom = a[i];
            a[i] = a[j];
            a[j] = pom;
        }
    }

    a[begin] = a[j];
    a[j] = b;
    return j;
}

void quick_sort(FILM a[], int begin, int end){
    if ( begin < end ){
        int pivot = split(a, begin, end);
        quick_sort(a, begin, pivot - 1);
        quick_sort(a, pivot + 1, end);
    }
}

void print(char aa[], FILM a[]){
    FILE *fp = fopen(aa, "w");

    int i = 0;

    fprintf(fp, "OCJENA, NAZIV FILMA, GODINA, GLUMCI, ZANR\n");
    for (;i<n;i++){
        int j = 0;
        fprintf(fp, "%.2lf,%s, %d,", a[i].middle_grade, a[i].name, a[i].year);

        for (;j<a[i].num_act;j++){
            fprintf(fp, "%s,", a[i].actors[j]);
        }

        fprintf(fp, "%s\n", a[i].genre);
    }

    fclose(fp);
}

void sort_sort(ALGORITAM a[]){
    int h = 3 / 2;

    for (;h>0;h/=2){
        int i = 0;

        for (i=h;i<3;i++){
            ALGORITAM x = a[i];
            int j = 0;

            for (j=i;j>=h && x.time < a[j-h].time;j-=h){
                a[j] = a[j-h];
            }

            a[j] = x;
        }
    }
}
