#include "Header.h"

int main() {
    printf("-------------------");
    printf("\nPILE - LIFO\n");
    Pile *maPile = initialiserPile();

    empiler(maPile, (int*)4);
    empiler(maPile, (int*)8);
    empiler(maPile, (int*)15);
    empiler(maPile, (int*)16);
    empiler(maPile, (int*)23);
    empiler(maPile, (int*)42);

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("Je depile %d\n", (int*)depiler(maPile));
    printf("Je depile %d\n", (int*)depiler(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("-------------------");
    printf("\nFILE - FIFO\n");

    File *maFile = initialiserFile();

    enfiler(maFile, (int*)4);
    enfiler(maFile, (int*)8);
    enfiler(maFile, (int*)15);
    enfiler(maFile, (int*)16);
    enfiler(maFile, (int*)23);
    enfiler(maFile, (int*)42);

    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    printf("\nJe defile %d\n", (int*)defiler(maFile));
    printf("Je defile %d\n\n", (int*)defiler(maFile));

    printf("Etat de la file :\n");
    afficherFile(maFile);

    return 0;
}
