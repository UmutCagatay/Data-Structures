#include "BTaktik.h"

BTaktik BTaktikOlustur()
{
    BTaktik this;
    this = (BTaktik)malloc(sizeof(struct BTAKTIK));
    this->super = TaktikOlustur();
    this->super->Savas = &SavasB;     
    this->TaktikPopulasyonAl = &BTaktikPopulasyonAl;
    this->TaktikYoket = &BTaktikYoket;

    return this;
}

int SavasB(const BTaktik this)
{
    return (int)pow(this->super->pop,3) % 1000;
}

void BTaktikPopulasyonAl(const BTaktik this, int pop)
{
	this->super->TaktikPopulasyonAl(this->super, pop);
}

void BTaktikYoket(const BTaktik this){
	if(this == NULL) return;
	this->super->TaktikYoket(this->super);
	free(this);
}