#include "Header.h"

// Pile

Pile *initialiser() {
    Pile *pile = malloc(sizeof(*pile));

    if(pile == NULL) {
        exit(EXIT_FAILURE);
    }

    pile->premier = NULL;

    return pile;
}

void empiler(Pile *pile, void *donnee) {
    Element *nouveau = malloc(sizeof(*nouveau));

    if(pile == NULL || nouveau == NULL) {
        exit(EXIT_FAILURE);
    }

    nouveau->donnee = donnee;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

void *depiler(Pile *pile) {
    if(pile == NULL) {
        exit(EXIT_FAILURE);
    }

    void *donnee = 0;
    Element *aSupprimer = pile->premier;

    if(pile->premier != NULL) {
        donnee = aSupprimer->donnee;
        pile->premier = aSupprimer->suivant;
        free(aSupprimer);
    }

    return donnee;
}

void afficherPile(Pile *pile) {
    if(pile == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *elementCourant = pile->premier;

    while(elementCourant != NULL) {
        printf("%d\n", elementCourant->donnee);
        elementCourant = elementCourant->suivant;
    }
    printf("\n");
}

// File

File *initialiserFile() {
    File *file = malloc(sizeof(*file));

    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    file->premier = NULL;

    return file;
}

void enfiler(File *file, void *donnee) {
    Element *element = malloc(sizeof(*element));

    if(file == NULL || element == NULL) {
        exit(EXIT_FAILURE);
    }

    element->donnee = donnee;
    element->suivant = NULL;

    if(file->premier == NULL) {
        file->premier = element;
    } else {
        Element *courant = file->premier;
        while(courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = element;
    }
}

void *defiler(File *file) {
    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    void *donnee = 0;

    if(file->premier != NULL) {
        Element *aSupprimer = file->premier;
        donnee = aSupprimer->donnee;
        file->premier = aSupprimer->suivant;
        free(aSupprimer);
    }

    return donnee;
}

void afficherFile(File *file) {
    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *actuel = file->premier;

    while(actuel != NULL) {
        printf("%d ", actuel->donnee);
        actuel = actuel->suivant;
    }
    printf("\n");
}

int main() {
    printf("-------------------");
    printf("\nPILE - LIFO\n");
    Pile *maPile = initialiser();

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
