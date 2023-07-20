#include "BUretim.h"

BUretim BUretimOlustur()
{
    BUretim this;
    this = (BUretim)malloc(sizeof(struct BURETIM));
    this->super = UretimOlustur();
    this->super->Uret = &UretB;    
    this->UretimPopulasyonAl = &BUretimPopulasyonAl; 
    this->UretimYoket = &BUretimYoket;

    return this;
}

int UretB(const BUretim this)
{
    return (int)pow(this->super->pop,1/3) % 10;
}

void BUretimPopulasyonAl(const BUretim this, int pop)
{
	this->super->UretimPopulasyonAl(this->super, pop);
}

void BUretimYoket(const BUretim this){
	if(this == NULL) return;
	this->super->UretimYoket(this->super);
	free(this);
}