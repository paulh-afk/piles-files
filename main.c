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
        printf("%d\n", (int*)elementCourant->donnee);
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
    Element *nouveau = malloc(sizeof(*nouveau));

    if(file == NULL || nouveau == NULL) {
        exit(EXIT_FAILURE);
    }

    nouveau->donnee = donnee;
    nouveau->suivant = NULL;

    if(file->premier != NULL) {
        Element *elementActuel = file->premier;

        while(elementActuel != NULL) {
            elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    } else {
        file->premier = nouveau;
    }
}

int defiler(File *file) {
    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    void *donnee = 0;

    if(file->premier != NULL) {
        Element *element = file->premier;

        donnee = element->donnee;
        file->premier = element->suivant;
        free(element);
    }

    return donnee;
}

void afficherFile(File *file) {

}

int main() {
    Pile *maPile = initialiser();

    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("Je depile %d\n", (int*)depiler(maPile));
    printf("Je depile %d\n", (int*)depiler(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    File *maFile = initialiserFile();

    return 0;
}
