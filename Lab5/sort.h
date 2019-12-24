#ifndef sort_h_include
#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct film{
    double middle_grade;
    char name[100];
    int year;
    char actors[10][100];
    int num_act;
    char genre[100];
}FILM;

FILM niz[1500];
int n;

void print(char [], FILM []);
void read_csv();
void schell_sort(FILM []);
void m_heap(FILM [], int, int);
void heap_sort(FILM []);
int split(FILM [], int, int);
void quick_sort(FILM [], int, int);

#endif // sort_h_include
