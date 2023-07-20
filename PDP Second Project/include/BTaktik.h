#ifndef BTaktik_h
#define BTaktik_h

#include "Taktik.h"

struct BTAKTIK
{
    Taktik super;

    void (*TaktikPopulasyonAl)(struct BTAKTIK*, int);
    void (*TaktikYoket)(struct BTAKTIK*);
};
typedef struct BTAKTIK* BTaktik;

    BTaktik BTaktikOlustur();
    int SavasB(const BTaktik);
    void BTaktikPopulasyonAl(const BTaktik, int);
    void BTaktikYoket(const BTaktik);

#endif