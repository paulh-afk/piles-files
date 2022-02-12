#include "pile.h"

Pile *initialiserPile() {
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
