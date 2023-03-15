/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef Organizma_hpp
#define Organizma_hpp
#include "DugumOrganizma.hpp"

class Organizma //Organizma yapisi
{
public:
    Organizma();
    ~Organizma();
    void organizmaEkle(Sistem* sistem); //Organizmaya parametre olarak verilen sistem bilgisini atar.
    void organizmaYazdir();     //Icerisindeki organin yazdir fonksiyonunu cagirir.
    void mutasyonOrganizma();   //Icerisindeki organin mutasyon fonksiyonunu cagirir.
private:
    DugumOrganizma* ilk;
};


#endif