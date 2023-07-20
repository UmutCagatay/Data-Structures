#include "ATaktik.h"

ATaktik ATaktikOlustur()
{
    ATaktik this;
    this = (ATaktik)malloc(sizeof(struct ATAKTIK));
    this->super = TaktikOlustur();
    this->super->Savas = &SavasA;
    this->TaktikPopulasyonAl = &ATaktikPopulasyonAl;
    this->TaktikYoket = &ATaktikYoket;

    return this;
}

int SavasA(const ATaktik this)
{
    return (int)pow(this->super->pop,2) % 1000;
}

void ATaktikPopulasyonAl(const ATaktik this, int pop)
{
	this->super->TaktikPopulasyonAl(this->super, pop);
}

void ATaktikYoket(const ATaktik this){
	if(this == NULL) return;
	this->super->TaktikYoket(this->super);
	free(this);
}