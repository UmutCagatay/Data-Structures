/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#ifndef SatirListesi_hpp    // Koruma bariyerleri
#define SatirListesi_hpp
#include "Dugum.hpp"        
#include "DosyaOkuma.hpp"   //Kutuphaneler ve Header baglantilari. Dugum.hpp Satirlistesinin yapitasi Dugum icin, DosyaOkuma Dosyadan okunan verilerin aktarilmasi icin lazim.
#include <sstream>
#include <iomanip>

class SatirListesi //SatirListesi nesnesi olusturmamizi saglayan class tanimi
{
public:
    SatirListesi(const string &satir);  //SatirListesi kurucusu. Nesne olustururken bir string parametresi aliyor(satir).
    ~SatirListesi();    //SatirListesi yok edicisi. Heap bellek alanindan alinan Dugum nesnelerini siliyor.
    void satirYazdir(int &index,int &kontrol, int &isaret); //Ekrana secili indekste ki SatirListesini yazdiriyor.
    void dugumSil(int &sira); //Secili indeksteki dugumu siliyor.
    float ortalamaDondur(); //Bir satirlistesinin verilerinin aritmetik ortalamasini istenildigi zaman donduruyor.
    int dugumSayisiDondur(); //Dugum sayisini istenildigi zaman donduren fonksiyon.
private:
    Dugum* ilkDugum;    //Olusturulacak SatirListesi nesnelerinin ilk dugumunun adresini tutacak olan dugumun imzasi.
    int dugumSayisi;    //Sistemde dugum sayisini tutan degisken.
    float ortalama;     //Sistemde satirlistesindeki verilerin aritmetik ortalamasini tutan degisken.
    void ortalamaHesapla(); //Bir SatirListesinde ki verilerin aritmatik ortalamasini hesaplayan fonksiyon.
    void satirListeEkle(const string &satir);   //Olusturulan SatirListesi nesnesine satirdaki verileri aktaran fonksiyon.
    void boslukBirak(int &index); //Yazdir fonksiyonunda kullanilan istenilen kadar bosluk birakan YoneticiListesi yazdir fonksiyonu ile SatirListesi yazdir fonksiyonunun hizali duzgun yazilmasini sagliyor.
    Dugum* dugumGetirSatir(int &sira); //SatirListesinde istenilen indekste ki dugumu donduren fonksiyon.
};

#endif  // Koruma bariyerleri