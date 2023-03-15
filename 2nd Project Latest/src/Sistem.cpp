/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Sistem.hpp"
#include <iostream>
using namespace std;

Sistem::Sistem()    //Kurucu fonksiyon.
{
    ilk = 0;
}

Sistem::~Sistem()
{
    DugumSistem* gec = ilk;
    while (gec != 0)
    {
        DugumSistem* sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}

void Sistem::sistemEkle(Organ* organ)   //Parametre aldigi organi dugum olarak icerisine ekliyor. Yani Sisteme organ ekliyor.
{
    if (organ)
    {
        DugumSistem* yeni = new DugumSistem(organ);
        if (ilk == 0)
        {
            ilk = yeni;
        }
        else
        {
            DugumSistem* gec = ilk;
            while (gec->sonraki != 0)
            {
                gec = gec->sonraki;
            }
            gec->sonraki = yeni;
        }
    }
}

void Sistem::sistemYazdir() //Icerisinde tuttugu tum organlar icin organYazdir fonksiyonunu cagiriyor.
{
    DugumSistem* gec = ilk;
    while (gec != 0)
    {
        gec->adres->organYazdir();
        gec = gec->sonraki;
    }
    cout << endl;
}

void Sistem::mutasyonSistem()   //Icerisinde tuttugu tum organlar icin mutasyonOrgan fonksiyonunu cagiriyor.
{
    DugumSistem* gec = ilk;
    while (gec != 0)
    {
        gec->adres->mutasyonOrgan();
        gec = gec->sonraki;
    }
}