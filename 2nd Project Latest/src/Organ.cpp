/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Organ.hpp"
#include <iostream>
using namespace std;
Organ::Organ()  //Kurucu fonksiyon. 1 kontrol nesnesi olusturuyor.
{
    ilk = 0;
    kontrol = new Kontrol;
}

Organ::~Organ()
{
    delete ilk;
    delete kontrol;
}

void Organ::organEkle(IkiliAramaAgaci* agac)    //Parametre olarak verilen agaci dugumune atiyor.
{
    if (agac)
    {
        DugumOrgan* yeni = new DugumOrgan(agac);
        if (ilk == 0)
        {
            ilk = yeni;
        }
    }
}

void Organ::organYazdir()   //Adresini tuttugu agacin agacYazdir fonksiyonunu cagiriyor.
{
    ilk->adres->agacYazdir();
}

void Organ::mutasyonOrgan() //Bilgisini tuttugu agaci mutasyonKontrolune sokuyor.
{
    donen = dondur();
    kontrol->mutasyonKontrol(donen);
}

IkiliAramaAgaci* Organ::dondur()    //Agac adresi donduren fonksiyon.
{
    return ilk->adres;
}