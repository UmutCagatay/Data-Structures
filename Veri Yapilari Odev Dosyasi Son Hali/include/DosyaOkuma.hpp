/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#ifndef DosyaOkuma_hpp // Koruma bariyerleri
#define DosyaOkuma_hpp
#include <string>
#include <sstream>
#include <fstream>  //Kutuphaneler ve namespace
#include <iostream>
using namespace std;

class DosyaOkuma    // Dosya okuma islemlerini gerceklestiren DosyaOkuma class'i
{
public:
    DosyaOkuma(string &dosyaAdi);   //DosyaOkumanin kurucu metodu. Metod DosyaOkuma nesnesi olusturulurken kurucu olarak dosyanin adini parametre aliyor ve icerisine yazdigimiz kodlari nesne olusturulunca calistiriyor.
    ~DosyaOkuma(); //Yikici Metot: Uygulama sona erdirilirken heap alanindan aldigi hafizayi sistem geri iade ediyor.
    void satirOkuma();  //Dosyayi satir satir okuyan fonksiyon
    int satirSayisiGetir(); //Sistemde kayirli satir adetini donduren fonksiyon
    string satirDondur(int &sira); //SatirOkuma ile okudugumuz degerleri ust siniflara(SatirListesi) aktarimi saglayan fonksiyon
    void satirOrtSirala(); //Verileri ust siniflara aktarmadan once ortalamaya gore siralayan fonksiyon
private:
    string dosyaAdi; //dosya adini tutan string
    string* stringSatirListe; //Satirlarin aritmetik ortalamasini hesaplayip siralarken int degerleri saklamak icin kullanilan cpp klasorunde adina olusturulan dizinin imzasi
    int satirSayisi;    //Dosyada ki satir sayisini her seferinde hesaplamak yerine sistemde tutuluyor.
    float *sayiOrtDizi;    //Satirlarin aritmetik ortalamasini hesaplayip siralarken float degerleri saklamak icin kullanilan cpp klasorunde adina olusturulan dizinin imzasi
    void satirSayisiBulma(); //Dosyada ki satir sayisini bulan fonksiyon
    bool dizilisDogrumu(float* &sayidizi); //Veriler aritmetik ort. gore siralanirken dogru siralandi mi kontrolu yapan fonksiyon
};

#endif // Koruma bariyerleri