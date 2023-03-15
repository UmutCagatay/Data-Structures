/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef Test_hpp
#define Test_hpp
#include "Organizma.hpp"

class Test  //Programin arka planinin calistirildigi merkez komuta sistemi
{
public:
    Test();
    ~Test();
    void ekranaYazdir(); //Organizmayi ekrana yazdirir.
    friend class DosyaOkuma;    //Dosya okuma islemlerinde organizmayi olusturan komutlarin kullanilmasina izin verir.
private:
    Doku* dokuEkleFonk(int* dizi, int &sayiAdedi);  //Doku ekle fonksiyonunu cagirir.
    IkiliAramaAgaci* agacEkleFonk(Doku* doku);  //Agac ekle fonksiyonunu cagirir.
    Organ* organEkleFonk(IkiliAramaAgaci* agac);    //Organ ekle fonksiyonunu cagirir.
    Sistem* sistemEkleFonk(Organ* organ);   //Sistem ekle fonksiyonunu cagirir.
    void organizmaEkleFonk(Sistem* sistem); //Organizma ekle fonksiyonunu cagirir.
    IkiliAramaAgaci* agac;
    Organ* organ;
    Sistem* sistem;
    Organizma* organizma;
    int agacSayac;
    int sistemSayac;
};

#endif