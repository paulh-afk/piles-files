#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;
struct Element {
    void *donnee;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile {
    Element *premier;
};

typedef struct File File;
struct File {
    Element *premier;
};
