/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp
#include "DugumAgac.hpp"

class IkiliAramaAgaci   //Ikili arama agac class. Bir nesnesi 20 adet dugum nesnesi bilgisi tutar.
{
public:
    IkiliAramaAgaci();
    ~IkiliAramaAgaci();
    void agacEkle(Doku* doku);  //Olusturulmus doku bilgisini agaca ekler.(Agacin dugumune doku bilgisini atar)
    void agacYazdir();  //Organizma ekrana yazdirilirken en merkez duraktir. Agacin denge durumunu kontrol eder ve dengeye gore ekrana ciktiyi yazdirir.
    friend class Kontrol; //Kontrol class i icinde agac fonksiyonlari kullanilmasi gerekmektedir. Agacin private fonksiyonlarina Kontrol classi icin erisim saglar.
private:
    DugumAgac* kok;
    int sayac;
    bool denge;
    bool bosmu(); //Agacin bos olup olmadigini kontrol eder.
    void temizle(); //Agac bos degilse dugumSil fonksiyonunu cagirir.
    void agacEkle(Doku* doku, DugumAgac* aktifDugum); //Olusturulmus doku bilgisini agaca ekler.(Agacin dugumune doku bilgisini atar)
    bool mutasyonAgac(); //Agacin mutasyona ugrayip ugramayacagi kontrolunu saglar. 
    void mutasyonAgac(DugumAgac* aktifDugum); //Agacin mutasyona ugrayip ugramayacagi kontrolunu saglar. 
    void agacAktar(Doku** doku); //Mutasyon sirasinda agactaki verilerin yedeklenmesini saglar.
    void agacAktar(Doku** doku, DugumAgac* aktifDugum); //Mutasyon sirasinda agactaki verilerin yedeklenmesini saglar.
    void dengelimi(); //Agacin AVL agaci bakimindan denge durumunu kontrol eder.
    void dengelimi(DugumAgac* aktifDugum); //Agacin AVL agaci bakimindan denge durumunu kontrol eder.
    int yukseklikBul(); //Agacin dugumlerinin yuksekliklerini bulur.
    int yukseklikBul(DugumAgac* aktifDugum); //Agacin dugumlerinin yuksekliklerini bulur.
    bool dugumSil(DugumAgac* &aktifDugum); ////Agacin icerigini tamamen temizler. Agaci bosaltir.
};
#endif