#ifndef Taktik_h
#define Taktik_h

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct TAKTIK
{
    int pop;
    void (*TaktikYoket)(struct TAKTIK*);
    void (*TaktikPopulasyonAl)(struct TAKTIK*, int);
    int (*Savas)();
};
typedef struct TAKTIK* Taktik;

Taktik TaktikOlustur();
void TaktikPopulasyonAl(const Taktik, int);
void TaktikYoket(const Taktik);

#endif