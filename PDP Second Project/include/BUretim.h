#ifndef BUretim_h
#define BUretim_h

#include "Uretim.h"

struct BURETIM
{
    Uretim super;

    void (*UretimPopulasyonAl)(struct BURETIM*, int);
    void (*UretimYoket)(struct BURETIM*);
};
typedef struct BURETIM* BUretim;

    BUretim BUretimOlustur();
    int UretB(const BUretim);
    void BUretimPopulasyonAl(const BUretim, int);
    void BUretimYoket(const BUretim);

#endif