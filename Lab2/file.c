#include "file.h"
#include <stdlib.h>
#include <stdio.h>

int flag(char ch){
    if ( ch >= 'a' && ch <= 'z' ) return 1;
    else if ( ch >= 'A' && ch <= 'Z' ) return 1;
    else if ( ch >= '0' && ch <= '9' ) return 1;
    else return 0;
}

void input(){
    FILE *fp = fopen("tekst.txt", "r");

    char t;
    double br = 0.0;
    t = fgetc(fp);
    while ( t != EOF ){

        if ( flag(t) ){
            alo[(int)t]++;
            br+=1.0;
            n++;
        }

        t = fgetc(fp);
    }

    fclose(fp);

    int i = 0;
    int brr = 0;
    for (;i<200;i++){
        if ( alo[i] ){
            p_c[brr].ch = (char)i;
            p_c[brr].v = (double)alo[i]/br;
            p_c[brr].v*= 100.0;
            brr++;
            printf("%.2lf\n", p_c[brr-1].v);
        }
    }
}
