/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "DosyaOkuma.hpp"

DosyaOkuma::DosyaOkuma(string dosyaAdi, Test* &test)    //Kurucu fonksiyon. Dosya adini alir ve Islemlerin gerceklesmesini kontrol eden Test nesnesini parametre alir.
{
    this->dosyaAdi = dosyaAdi;
    sayiAdedi = 0;
    satirOkuma(test);
}

DosyaOkuma::~DosyaOkuma()
{
    //Alinan hafizalar islem bitince geri edildigi icin yokedicide silmeye gerek yok.
}

void DosyaOkuma::satirOkuma(Test* &test)    //Dosya okuma islemi gerceklestirilir. Dosya satir satir okunur. Satir okundugunda icersindeki bilgi int dizisine cevirilir.
{                                           //Dizi radix sort kullanilarak kucukten buyuge siralanir. Siralanan dizi radix fonksiyonu ile geri dondurulur. Fonksiyon doku ekle kisminda kullanilir.
    ifstream dosya(dosyaAdi);               //Test nesnesi ile zincirleme sekilde ekle fonksiyonlari kullanilir. Fonksiyonlar birbirini parametre alir.
    if (dosya.is_open())                    //Organizma harici diger fonksiyonlar ekleme yaptiklari turden nesneyi geri dondururler. Boylece zincirleme sekilde ekleme islemleri yapilir.
    {
        Radix *radix;
        string satir;
        int sira = 0;
        while (!dosya.eof())
        {
            sayiAdedi = 0;
            getline(dosya,satir);
            sayiAdediBul(satir);
            sayilar = new int[sayiAdedi];
            diziCevir(satir);
            radix = new Radix(sayilar,sayiAdedi);
            test->organizmaEkleFonk(test->sistemEkleFonk(test->organEkleFonk(test->agacEkleFonk(test->dokuEkleFonk(radix->sirala(),sayiAdedi)))));
            delete[] sayilar;
            delete radix;
        }
        dosya.close();
    }
}

void DosyaOkuma::diziCevir(string satir)    //Satirdaki degerleri int dizisine aktarir.(String to int)
{
    int sayi;
    int i = 0;
    stringstream ss(satir);
    while (ss >> sayi)
    {
        sayilar[i] = sayi;
        i++;
    }
    ss.clear();
}

void DosyaOkuma::sayiAdediBul(string satir) //Satirdaki sayi adetini bulur.
{
    int sayi;
    stringstream ss(satir);
    while (ss >> sayi)
    {
        sayiAdedi++;
    }
    ss.clear();
}