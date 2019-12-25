#include "sort.h"

int main()
{
    srand(time(0));
    read_csv();
    FILM ab[1000];
    clock_t start, end;

    ALGORITAM arr[3];

    strcpy(arr[0].name, "SHELL_sort");
    int i = 0;
    for (;i<n;i++){
        ab[i] = niz[i];
    }
    start = clock();
    shell_sort(ab);
    end = clock();
    print("Shell_sort.txt", ab);
    arr[0].time = (end - start) / ((double)CLOCKS_PER_SEC);

    strcpy(arr[1].name, "QUICK_sort");
    for (i=0;i<n;i++){
        ab[i] = niz[i];
    }
    start = clock();
    quick_sort(ab, 0, n-1);
    end = clock();
    print("Quick_sort.txt", ab);
    arr[1].time = (end - start) / ((double)CLOCKS_PER_SEC);

    strcpy(arr[2].name, "HEAP_sort");
    for (i=0;i<n;i++){
        ab[i] = niz[i];
    }
    start = clock();
    heap_sort(ab);
    end = clock();
    print("Heap_sort.txt", ab);
    arr[2].time = (end - start) / ((double)CLOCKS_PER_SEC);

    sort_sort(arr);

    for (i=0;i<3;i++){
        printf("%s %lf\n", arr[i].name, arr[i].time);
    }
    return 0;
}
