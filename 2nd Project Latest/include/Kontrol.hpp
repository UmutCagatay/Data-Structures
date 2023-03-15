/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef Kontrol_hpp
#define Kontrol_hpp
#include "IkiliAramaAgaci.hpp"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Kontrol
{
public:
    Kontrol();
    ~Kontrol();
    void mutasyonKontrol(IkiliAramaAgaci* agac); //Mutasyon islemlerinin gerceklestirildigi fonksiyon.
private:
    void bsort(int* dizi, int uzunluk);     //Agac silinmeden kopyalanan verileri yeniden siralar
    void sirala(int* sayi1, int* sayi2);    //Agac silinmeden kopyalanan verileri yeniden siralar
    Doku** doku;
    IkiliAramaAgaci* agac;
    int** sayilar;
    int sayiAdet;
    int dokuAdet;
};

#endif