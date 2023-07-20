#ifndef AUretim_h
#define AUretim_h

#include "Uretim.h"

struct AURETIM
{
    Uretim super;

    void (*UretimPopulasyonAl)(struct AURETIM*, int);
    void (*UretimYoket)(struct AURETIM*);
};
typedef struct AURETIM* AUretim;

    AUretim AUretimOlustur();
    int UretA(const AUretim);
    void AUretimPopulasyonAl(const AUretim, int);
    void AUretimYoket(const AUretim);

#endif