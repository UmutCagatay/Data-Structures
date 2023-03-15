/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Test.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Test::Test()    //Kurucu fonksiyon. 1 adet organizma nesnesi olusturuyor.
{
    agacSayac = sistemSayac = 0;
    agac = 0;
    organ = 0;
    sistem = 0;
    organizma = new Organizma();
}

Test::~Test()
{
    delete organizma;
}

Doku* Test::dokuEkleFonk(int* dizi, int &sayiAdedi) //Doku olusturma fonksiyonu. Doku olusturma, doku icerisine bilgileri aktarma ve dokunun orta sayisini bulan fonksiyonlari calistiriyor. Doku cinsinden veri donduruyor.
{
    if (dizi)
    {
        Doku* doku = new Doku();
        doku->dokuEkle(dizi, sayiAdedi);
        doku->dokuOrtaSayi();
        return doku;
    }
    else
        return 0;
}

IkiliAramaAgaci* Test::agacEkleFonk(Doku* doku) //Agac olusturma fonksiyonu. Agac olusturma, agac icerisine doku bilgisini aktarma islemlerini gerceklestiriyor.
{                                               //1 agac 20 adet doku tutmasi gerekli oldugu icin 1 agac 20 dokuya zaten sahipse yeni agac olusturuyor ve yeni agac uzerinden islemlerine devam ediyor.
    if (doku)
    {
        if (agacSayac == 0)
        {
            agac = new IkiliAramaAgaci();
            agac->agacEkle(doku);
            agacSayac++;
            return agac;
        }
        else if (agacSayac == 20)
        {
            agac = new IkiliAramaAgaci();
            agac->agacEkle(doku);
            agacSayac = 1;
            return agac;
        }
        else
        {
            agac->agacEkle(doku);
            agacSayac++;
            return 0;
        }
    }
    else
        return 0;
}

Organ* Test::organEkleFonk(IkiliAramaAgaci* agac)   //Organ olusturma fonksiyonu. Organ olusturma, organa agacin aktarilmasi islemlerini gerceklestiriyor.
{                                                   //1 Organ 1 adet agac tutabiliyor.
    if (agac)
    {
        organ = new Organ();
        organ->organEkle(agac);
        return organ;
    }
    else
    {
        return 0;
    }
}

Sistem* Test::sistemEkleFonk(Organ* organ)  //Sistem olusturma fonksiyonu. Sistem olusturma, sisteme organin aktarilmasi islemlerini gerceklestiriyor.
{                                           //1 Sistem 100 adet organ tutmasi gerekli oldugu icin 1 sistem 100 organa zaten sahipse yeni sistem olusturuyor ve yeni sistem uzerinden islemlerine devam ediyor.
    if (organ)
    {   
        if (sistemSayac == 0)
        {
            sistem = new Sistem();
            sistem->sistemEkle(organ);
            sistemSayac++;
            return sistem;
        }
        else if (sistemSayac == 100)
        {
            sistem = new Sistem();
            sistem->sistemEkle(organ);
            sistemSayac = 1;
            return sistem;
        }
        else
        {
            sistem->sistemEkle(organ);
            sistemSayac++;
            return 0;
        }
    }
    else
        return 0;
}

void Test::organizmaEkleFonk(Sistem* sistem)    //Organizma olusturma fonksiyonu. Organizmaya sistem bilgisini aktariyor. Programda yalnizca 1 adet organizma olabilir. Sistemler sinirsiz sayida organizmaya atanabilir.
{
    if (sistem)
    {
        organizma->organizmaEkle(sistem);
    }
}

void Test::ekranaYazdir()   //Ekrana yazdirma islemleri gerceklestirilir. Organizma yazdirilir, mutasyona ugratilir ardindan mutasyona ugramis organizma tekrar yazdirilir.
{
    system("cls");
    cout << right << setw(20) << "" << "ORGANIZMA" << endl;
    organizma->organizmaYazdir();
    organizma->mutasyonOrganizma();
    cin.ignore();
    system("cls");
    cout << right << setw(15) << "" << "ORGANIZMA (MUTASYONA UGRADI)" << endl;
    organizma->organizmaYazdir();
    cin.ignore();
}