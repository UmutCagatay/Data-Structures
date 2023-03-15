/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#ifndef YoneticiListesi_hpp // Koruma bariyerleri
#define YoneticiListesi_hpp
#include "YDugum.hpp" //Verilerini tuttugu YDugum header file kalitim aliyor

class YoneticiListesi //SatirListelerini yoneten nesneyi olusturan class
{
public:
    YoneticiListesi(DosyaOkuma* &dosya, const int &satirSayisi); //YoneticiListesi kurucu metodu. Parametre olarak DosyaOkuma pointer turunde adres ve Dosyada ki satir sayisi bilgisini aliyor.
    ~YoneticiListesi(); //YoneticiListesi yok edici metodu. Heap bellek alanindan aldigimiz hafizayi sisteme geri iade ediyor.
    void yazdir(); //Ekrana uygulama arayuzunu ve verileri yazdiran fonksiyon.
private:
    YDugum* ilkYDugum; //YoneticiListesinin ilk verisini tutacak YDugum imzasi.
    SatirListesi* *satirListe; // SatirListesi nesnesinin imzasi.
    int satirAdet;  //Satir adedini tutan veri.
    void yoneticiEkle(DosyaOkuma* &dosya); //SatirListelerini YDugumlere aktariyor.
    YDugum* dugumGetir(int &sira); //Istenilen endeksteki SatirListesini(YDugum) donduruyor.
    void yoneticiYazdir(int &index, int &atla);  //Yazdir fonksiyonunun YoneticiListesi kismini yazdiran fonksiyon.
    void yoneticiDugumCikar(int &sira); //YoneticiListesinden istenilen indekste ki dugumu cikaran fonksiyon
    int rastgeleSayiDondur(int &index); //Rastgele sayi ureten ve donduren fonksiyon.
    void yerGuncelleme(int &index); //Ortalamalari degisen YDugumlerin siralamalarini guncelleyen fonksiyon.
};

#endif  // Koruma bariyerleri