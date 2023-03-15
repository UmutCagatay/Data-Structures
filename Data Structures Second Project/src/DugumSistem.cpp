/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "DugumSistem.hpp"

DugumSistem::DugumSistem(Organ* adres)  //Kurucu fonksiyon. Parametre aldigi organ cinsinden adresi kendi adres degiskenine atar. Boylece organ bilgisi organda saklanmis olur.
{
    this->adres = adres;
    sonraki = 0;
}

DugumSistem::~DugumSistem()
{
    adres->~Organ();
}