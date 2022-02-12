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

typedef struct File File;
struct File {
    Element *premier;
};

File *initialiserFile();
void enfiler(File *file, void *donnee);
void *defiler(File *file);
void afficherFile(File *file);
