/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#include "Dugum.hpp" //Sinifin header dosyasini kalitim aliyor

Dugum::Dugum(int &veri) //Dugum kurucusunun tanimlaniyor. Parametre olarak bir veri aliyor. Bu veriyi Dugume ait veriye atiyor. Sonraki ve onceki degerlerini NULL yapiyor.
{
    this->veri = veri;
    sonraki = onceki = NULL;
}
Dugum::~Dugum()
{
    
}