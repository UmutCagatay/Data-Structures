/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef DugumSistem_hpp
#define DugumSistem_hpp
#include "Organ.hpp"

class DugumSistem   //Sistemin Dugumu. Dugumlerin her biri bir organ bilgisi tutuyor.
{
public:
    DugumSistem(Organ* adres);
    ~DugumSistem();
    Organ* adres;
    DugumSistem* sonraki;
};


#endif