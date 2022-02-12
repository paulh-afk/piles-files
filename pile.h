#include <stdio.h>
#include <stdlib.h>

#ifndef ELEMENT
#define ELEMENT
typedef struct Element Element;
struct Element {
    void *donnee;
    Element *suivant;
};
#endif

typedef struct Pile Pile;
struct Pile {
    Element *premier;
};

Pile *initialiserPile();
void empiler(Pile *pile, void *donnee);
void *depiler(Pile *pile);
void afficherPile(Pile *pile);
