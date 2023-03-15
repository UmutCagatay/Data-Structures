/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef Sistem_hpp
#define Sistem_hpp
#include "DugumSistem.hpp"

class Sistem //Organ bilgilerini tutan class. 1 Sistem 100 Organ tutabilir.
{
public:
    Sistem();
    ~Sistem();
    void sistemEkle(Organ* organ);  //Sisteme parametre olarak verilen organ bilgisini atar.
    void sistemYazdir();    //Icerisindeki organin yazdir fonksiyonunu cagirir.
    void mutasyonSistem();  //Icerisindeki organin mutasyon fonksiyonunu cagirir.
private:
    DugumSistem* ilk;
};


#endif