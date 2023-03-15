/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"

class Doku  //Doku dosyadan okunan bir satiri temsil eder.
{
public:
    Doku();
    ~Doku();
    void dokuEkle(int* dizi, int &sayiAdedi); //Dokunun icerigini ekleyen fonksiyon
    void dokuOrtaSayi(); //Dokunun ortasindaki veriyi bulan fonksiyon
    void mutasyonDoku(); //Mutasyon sirasinda hucrelerdeki verileri degistiren fonksiyon
    int* diziCevir(); //Dokudaki verileri int dizisine aktarip diziyi donduruyor
    int sayiAdedi;
    int* sayilar;
    Hucre* ortaSayi;
private:
    Hucre* ilk;
};


#endif