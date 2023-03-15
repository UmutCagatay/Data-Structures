/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#ifndef Dugum_hpp // Koruma bariyerleri
#define Dugum_hpp
#include <iostream>
using namespace std;

class Dugum //Satirdan okudugumuz verileri saklayacagimiz nesneleri yarattigimiz Dugum sinifi
{
public:
    Dugum(int &veri);   //Dugum kurucu metodu. Parametre olarak Dosyadan okunan satirdaki bir sayiyi aliyor
    ~Dugum();       //Dugum yok edici metodu. Dugum elemani olarak herhangi bir heap alani almadigimiz icin kullanilmadi. Belki gormek istersiniz diye yazili birakiyorum.
    int veri;   //Satirdan okunan sayinin saklandigi degisken
    Dugum* sonraki; //Satir Listesinde bir dugumun sonrasindaki dugume ulasmamizi saglayan Dugum imzasi.
    Dugum* onceki;  //Satir Listesinde bir dugumun oncesindeki dugume ulasmamizi saglayan Dugum imzasi.
};

#endif // Koruma bariyerleri