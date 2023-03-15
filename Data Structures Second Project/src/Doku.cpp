/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Doku.hpp"
#include <iostream>
using namespace std;
Doku::Doku()    //Kurucu fonksiyon
{
    ilk = ortaSayi = 0;
    sayiAdedi = 0;
}

Doku::~Doku()   //Yikici fonksiyon. Bilgisini tuttugu Hucre verilerini siler.
{
    Hucre* gec = ilk;
    while (gec != 0)
    {
        Hucre* sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}

void Doku::dokuEkle(int* dizi, int &sayiAdedi)  //Parametre olarak aldigi dizideki(satirdaki sayilar) sayilari 1 sayi 1 hucre olacak sekilde saklar.
{
    this->sayiAdedi = sayiAdedi;
    for (int i = 0; i < sayiAdedi; i++)
    {
        Hucre* yeni = new Hucre(dizi[i]);
        if (ilk == 0)
        {
            ilk = yeni;
        }
        else
        {
            Hucre* gec = ilk;
            while (gec->sonraki != 0)
            {
                gec = gec->sonraki;
            }
            gec->sonraki = yeni;
        }
    }
}

void Doku::dokuOrtaSayi()   //Dokudaki sayilarin ortasindaki sayiyi bulur.
{
    Hucre* gec = ilk;
    for (int i = 0; i < sayiAdedi/2; i++)
    {
        gec = gec->sonraki;
    }
    ortaSayi = gec;
}

void Doku::mutasyonDoku()   //Mutasyon sirasinda calisir. Eger Hucrede saklanan sayi cift sayiysa ikiye bolunur, tek sayiysa dokunulmaz.
{
    Hucre* gec = ilk;
    while (gec != 0)
    {
        if (gec->veri % 2 == 0)
        {
            gec->veri = gec->veri/2;
        }
        gec = gec->sonraki;
    }
}

int* Doku::diziCevir()  //Dokudaki sayi bilgilerini bir int dizisine yedekler ve diziyi geri dondurur.
{
    if (ilk)
    {
        sayilar = new int[sayiAdedi];
        int i = 0;
        Hucre* gec = ilk;
        while (gec != 0)
        {
            sayilar[i] = gec->veri;
            i++;
            gec = gec->sonraki;
        }
        return sayilar;
    }
    return 0;
}