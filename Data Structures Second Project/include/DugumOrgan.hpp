/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef DugumOrgan_hpp
#define DugumOrgan_hpp
#include "IkiliAramaAgaci.hpp"

class DugumOrgan    //Organin Dugumu. Dugumlerin her biri bir ikili arama agaci bilgisi tutuyor.
{
public:
    DugumOrgan(IkiliAramaAgaci* adres);
    ~DugumOrgan();
    IkiliAramaAgaci* adres;
};


#endif