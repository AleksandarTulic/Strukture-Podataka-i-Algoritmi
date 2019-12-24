#include "sort.h"

int main()
{
    srand(time(0));
    read_csv();
    FILM ab[1500];
    clock_t start, end;

    int i = 0;
    for (;i<n;i++){
        ab[i] = niz[i];
    }

    start = clock();
    shell_sort(ab);
    end = clock();
    print("Shell_sort.txt", ab);
    printf("SHELL SORT: %10lf\n", ((double)((double)(end - start)) / (double)CLOCKS_PER_SEC));

    for (i=0;i<n;i++){
        ab[i] = niz[i];
    }

    start = clock();
    quick_sort(ab, 0, n-1);
    end = clock();
    print("Quick_sort.txt", ab);
    printf("QUICK SORT: %10lf\n", (end - start) / (double)CLOCKS_PER_SEC);

    for (i=0;i<n;i++){
        ab[i] = niz[i];
    }

    start = clock();
    heap_sort(ab);
    end = clock();
    print("Heap_sort.txt", ab);
    printf("HEAP SORT: %10lf\n", (end - start) / (double)CLOCKS_PER_SEC);
    return 0;
}
