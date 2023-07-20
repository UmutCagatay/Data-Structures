#include "Taktik.h"

Taktik TaktikOlustur()
{
    Taktik this;
	this = (Taktik)malloc(sizeof(struct TAKTIK));
	this->pop = 0;
	this->TaktikPopulasyonAl = &TaktikPopulasyonAl;
    this->TaktikYoket = &TaktikYoket;
	return this;
}

void TaktikPopulasyonAl(const Taktik this, int pop)
{
	this->pop = pop;
}

void TaktikYoket(const Taktik this){
	if(this == NULL) return;
	free(this);
}