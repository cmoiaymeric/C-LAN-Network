#include "graphe.h"
#include "algos.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    graphe g;
    init_graphe(&g);


    for (size_t i = 0; i < 5; ++i)
        ajouter_sommet(&g);
    printf("ordre = %zu\n", ordre(&g));
    printf("index sommet 3 = %zu\n",index_sommet(&g,3));
    printf("index sommet 7 = %zu\n",index_sommet(&g,7));

    arete a1;
    a1.s1 = 1;
    a1.s2 = 2;
    arete a2;
    a2.s1 = 1;
    a2.s2 = 3;
    arete a3;
    a3.s1 = 2;
    a3.s2 = 1;

    ajouter_arete(&g,a1);
    ajouter_arete(&g,a2);
    printf("Arrete 1-2 = %u\n",existe_arete(&g,a3));


    printf("AFFICHER GRAPHE\n");
    printf("===============\n");
    afficher(&g);

    deinit_graphe(&g);

    return EXIT_SUCCESS;
}
