/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#include "YDugum.hpp" //Sinifin header dosyasini kalitim aliyor

YDugum::YDugum(SatirListesi* &adres)    //YDugum kurucu fonksiyonu. Parametre olarak bir SatirListesi adresini aliyor.
{
    this->adres = adres;            //Kurucuda aldigi adresi kendi adres degiskenine atiyor.
    sonrakiYDugum = oncekiYDugum = NULL;
}
YDugum::~YDugum()
{
    adres->~SatirListesi();         //Butun uygulama icerisinde cok kritik bir nokta. Adresini tuttugu SatirListesinin yikicisini kendi yikicisinda cagiriyor.
}