#ifndef Koloni_h
#define Koloni_h

#include "stdio.h"
#include "stdlib.h"

struct KOLONI
{
    int populasyon;
    int yemekStok;
    int kazanma;
    int kaybetme;
    int sembol;
    int is_alive;

    void (*KoloniTurAtla)(struct KOLONI*);
    void (*KoloniYoket)(struct KOLONI*);
};
typedef struct KOLONI* Koloni;

Koloni KoloniOlustur(int);
void KoloniTurAtla(const Koloni);
void KoloniYoket(const Koloni);

#endif