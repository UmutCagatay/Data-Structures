/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#ifndef YDugum_hpp  // Koruma bariyerleri
#define YDugum_hpp
#include "SatirListesi.hpp" //SatirListesi kalitim aliyor

class YDugum //Her bir tanesinde bir adet SatirListesi tutacagimiz dugumlerin sinif tanimi
{
public:
    YDugum(SatirListesi* &adres); //YDugum kurucu fonksiyonu. Parametre olarak SatirListesi pointer turunden adres aliyor.
    ~YDugum(); //Uygulama bitisinde heap bellek alanindan alan hafizayi geri sisteme iade ediyor.
    SatirListesi* adres;    //YDugum e atanan SatirListesinin adresini tutan veri.
    YDugum* sonrakiYDugum; //YoneticiListesinde bir dugumun sonrasindaki dugume ulasmamizi saglayan YDugum imzasi.
    YDugum* oncekiYDugum; //YoneticiListesinde bir dugumun oncesindeki dugume ulasmamizi saglayan YDugum imzasi.
};

#endif  // Koruma bariyerleri