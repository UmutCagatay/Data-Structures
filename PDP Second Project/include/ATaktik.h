#ifndef ATaktik_h
#define ATaktik_h

#include "Taktik.h"

struct ATAKTIK
{
    Taktik super;

    void (*TaktikPopulasyonAl)(struct ATAKTIK*, int);
    void (*TaktikYoket)(struct ATAKTIK*);
};
typedef struct ATAKTIK* ATaktik;

    ATaktik ATaktikOlustur();
    int SavasA(const ATaktik);
    void ATaktikPopulasyonAl(const ATaktik, int);
    void ATaktikYoket(const ATaktik);

#endif