#include "file.h"

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
