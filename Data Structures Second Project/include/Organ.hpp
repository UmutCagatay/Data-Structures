/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef Organ_hpp
#define Organ_hpp
#include "DugumOrgan.hpp"
#include "Kontrol.hpp"

class Organ //Agac bilgilerini tutan class. 1 Organ 1 Agac tutabilir.
{
public:
    Organ();
    ~Organ();
    void organEkle(IkiliAramaAgaci* agac); //Organa parametre olarak verilen agac bilgisini atar.
    void organYazdir(); //Icerisindeki agacin yazdir fonksiyonunu cagirir.
    void mutasyonOrgan(); //Icerisindeki agacin mutasyon fonksiyonunu cagirir.
private:
    IkiliAramaAgaci* dondur(); //Agac adresi dondurur.
    IkiliAramaAgaci* donen;
    Kontrol* kontrol;
    DugumOrgan* ilk;
};


#endif