#include "AUretim.h"

AUretim AUretimOlustur()
{
    AUretim this;
    this = (AUretim)malloc(sizeof(struct AURETIM));
    this->super = UretimOlustur();
    this->super->Uret = &UretA;     
    this->UretimPopulasyonAl = &AUretimPopulasyonAl;
    this->UretimYoket = &AUretimYoket;

    return this;
}

int UretA(const AUretim this)
{
    return (int)pow(this->super->pop,1/2) % 10;
}

void AUretimPopulasyonAl(const AUretim this, int pop)
{
	this->super->UretimPopulasyonAl(this->super, pop);
}

void AUretimYoket(const AUretim this){
	if(this == NULL) return;
	this->super->UretimYoket(this->super);
	free(this);
}