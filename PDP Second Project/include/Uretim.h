#ifndef Uretim_h
#define Uretim_h

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct URETIM
{
    int pop;
    void (*UretimYoket)(struct URETIM*);
    void (*UretimPopulasyonAl)(struct URETIM*, int);
    int (*Uret)();
};
typedef struct URETIM* Uretim;

Uretim UretimOlustur();
void UretimPopulasyonAl(const Uretim, int);
void UretimYoket(const Uretim);

#endif