#include "Uretim.h"

Uretim UretimOlustur()
{
    Uretim this;
	this = (Uretim)malloc(sizeof(struct URETIM));
	this->pop = 0;
	this->UretimPopulasyonAl = &UretimPopulasyonAl;
    this->UretimYoket = &UretimYoket;
	return this;
}

void UretimPopulasyonAl(const Uretim this, int pop)
{
	this->pop = pop;
}

void UretimYoket(const Uretim this){
	if(this == NULL) return;
	free(this);
}