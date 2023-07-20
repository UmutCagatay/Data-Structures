#include "Koloni.h"

Koloni KoloniOlustur(int populasyon)
{
    Koloni this;
    this = (Koloni)malloc(sizeof(struct KOLONI));
    this->populasyon = populasyon;
    this->yemekStok = populasyon * populasyon;
    this->kazanma = 0;
    this->kaybetme = 0;
    this->sembol = 0;
    this->is_alive = 1;
    this->KoloniTurAtla = &KoloniTurAtla;
    this->KoloniYoket = &KoloniYoket;

    return this;
}

void KoloniTurAtla(const Koloni this)
{
    this->populasyon += (this->populasyon* 1/5);
    this->yemekStok -= (this->populasyon * 2);
}

void KoloniYoket(const Koloni this){
	if(this == NULL) return;
	free(this);
}
