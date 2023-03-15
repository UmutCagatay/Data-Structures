/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Organizma.hpp"
#include <iostream>
using namespace std;

Organizma::Organizma()  //Kurucu fonksiyon.
{
    ilk = 0;
}

Organizma::~Organizma()
{
    DugumOrganizma* gec = ilk;
    while (gec != 0)
    {
        DugumOrganizma* sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}

void Organizma::organizmaEkle(Sistem* sistem)   //Parametre aldigi sistemi dugum olarak icerisine ekliyor. Yani Organizmaya Sistem ekliyor.
{
    if (sistem)
    {
        DugumOrganizma* yeni = new DugumOrganizma(sistem);
        if (ilk == 0)
        {
            ilk = yeni;
        }
        else
        {
            DugumOrganizma* gec = ilk;
            while (gec->sonraki != 0)
            {
                gec = gec->sonraki;
            }
            gec->sonraki = yeni;
        }
    }
}

void Organizma::organizmaYazdir()   //Icerisinde tuttugu tum sistemler icin sistemYazdir fonksiyonunu cagiriyor.
{
    DugumOrganizma* gec = ilk;
    while (gec != 0)
    {
        gec->adres->sistemYazdir();
        gec = gec->sonraki;
    }
    cout << endl;
}

void Organizma::mutasyonOrganizma() //Icerisinde tuttugu tum sistemler icin mutasyonSistem fonksiyonunu cagiriyor.
{
    DugumOrganizma* gec = ilk;
    while (gec != 0)
    {
        gec->adres->mutasyonSistem();
        gec = gec->sonraki;
    }
}