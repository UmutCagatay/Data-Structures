/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Kontrol.hpp"

Kontrol::Kontrol()  //Kurucu fonksiyon
{
    dokuAdet = 0;
}

Kontrol::~Kontrol()
{
    //Islem yaparken alinan doku ve sayilar islem bitince hafiza tasarrufu icin fonksiyon icinde siliniyor. Agac yapisi ise zaten organizma icinde yer tutuyor, organizma silinince siliniyor.
}

void Kontrol::mutasyonKontrol(IkiliAramaAgaci* agac)    //Mutasyon islemlerinin gerceklestirildigi fonksiyon. Parametre olarak 1 agac aliyor. Agac mutasyona ugruyor mu kontrol ediyor.
{                                                       //Eger agac mutasyona ugruyorsa agacin icerigini yedekliyor. Yedeklenen bilgileri yeniden kucukten buyuge siraliyor.
    this->agac = agac;                                  //Agacin icini temizliyor. Ardindan agacin icine yeniden siralanmis bilgileri dokulara atayarak dokulari ekliyor.
    if(this->agac->mutasyonAgac())
    {
        doku = new Doku*[20];
        sayilar = new int*[20];
        this->agac->agacAktar(doku);
        for (int i = 0; i < 20; i++)
        {
            sayiAdet = doku[i]->sayiAdedi;
            sayilar[i] = doku[i]->diziCevir();
            bsort(sayilar[i], sayiAdet);
        }
        this->agac->temizle();
        for (int i = 0; i < 20; i++)
        {
            Doku* yeniDoku = new Doku();
            yeniDoku->dokuEkle(sayilar[i], sayiAdet);
            yeniDoku->dokuOrtaSayi();
            this->agac->agacEkle(yeniDoku);
        }
        for (int i = 0; i < 20; i++)
        {
            delete doku[i];
        }
        delete doku;
        for (int i = 0; i < 20; i++)
        {
            delete sayilar[i];
        }
        delete sayilar;
    }
}

void Kontrol::bsort(int* dizi, int uzunluk) //Dizideki sayilari dolasan fonksiyon.
{
    for(int j=0; j<uzunluk-1; j++)
    {
        for(int k=j+1; k<uzunluk; k++)
        {
            sirala(dizi+j, dizi+k);
        }  
    }         
}

void Kontrol::sirala(int* sayi1, int* sayi2)    //Iki sayinin kucukluk buyukluk kontrolunu yapan fonksiyon.
{
    if(*sayi1 > *sayi2)   
   {
      int gec = *sayi1;  
      *sayi1 = *sayi2;
      *sayi2 = gec;
   }
}