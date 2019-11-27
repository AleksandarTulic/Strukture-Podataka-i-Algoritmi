#ifndef file_h

typedef struct mini_struct{
    char ch; //KARAKTER
    double v; //NJEGOVA VJERATNOCA POJAVLJIVANJA
}MINI_STRUCT;

int alo[200]; //BROJIMO KOLIKO KOG KARAKTERA IMA
MINI_STRUCT p_c[62]; // PAMTI STRUKTURU GORNJU ZA KASNIJE
int n;

int flag(char ch);
void input();

#endif // file_h
