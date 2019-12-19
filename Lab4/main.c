#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    GRAPH g;
    INPUT_MATRIX(&g);

    int i;
    for (i=0;i<g.n;i++){
        PRINT_NEIGH(g.niz[i]);
        printf("\n");
    }

    printf("BFS:\n\n");
    bfs(&g);

    DELETE_GRAPH(&g);
    return 0;
}
