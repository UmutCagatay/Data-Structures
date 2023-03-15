/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef Radix_hpp
#define Radix_hpp
#include "Queue.hpp"

class Radix //Verileri Siralamaya Yarayan Yapi.
{
public:
    Radix(int* sayilar,int adet);
    ~Radix();
    int* sirala();
private:
    int     maxBasamakSayisiGetir();
    int     basamakSayisiGetir(int sayi);
    void    kuyrukUzunluklariGetir(int* uzunluklar);
    Queue** kuyruklar;
    int*    sayilar;
    int     sayiAdedi;
};

#endif