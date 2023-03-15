/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "IkiliAramaAgaci.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()  //Kurucu fonksiyon.
{
    kok = 0;
    sayac = 0;
    denge = true;
}

IkiliAramaAgaci::~IkiliAramaAgaci()
{
    temizle();
}

bool IkiliAramaAgaci::bosmu()   //Agacin bos olup olmadigini kontrol ediyor.
{
    return kok == NULL;
}

void IkiliAramaAgaci::temizle() //Agacin bir dugumunu silen fonksiyonu agac bosalana kadar cagiriyor. Yani agaci temizliyor.
{
	while(!bosmu()) 
        dugumSil(kok);
}
void IkiliAramaAgaci::agacEkle(Doku* doku)  //agacEkle fonksiyonunu disaridan cagirmaya yarayan fonksiyon. Agac bos degilse ayni fonksiyonun overload halini kok bilgisi vererek yeniden cagiriyor.
{
    if (kok == 0)
        kok = new DugumAgac(doku);
    else
    {    
        agacEkle(doku, kok);
    }
}
void IkiliAramaAgaci::agacEkle(Doku* doku, DugumAgac* aktifDugum)   //Parametre olarak verilen dokuyu agaca ekliyor.
{
    if (aktifDugum->doku->ortaSayi->veri > doku->ortaSayi->veri)
    {
        if (aktifDugum->sol)
            agacEkle(doku, aktifDugum->sol);
        else
            aktifDugum->sol = new DugumAgac(doku);
    }
    else if (aktifDugum->doku->ortaSayi->veri < doku->ortaSayi->veri)
    {
        if (aktifDugum->sag)
            agacEkle(doku, aktifDugum->sag);
        else
            aktifDugum->sag = new DugumAgac(doku);
    }
    else if (aktifDugum->doku->ortaSayi->veri == doku->ortaSayi->veri)
    {
        if (aktifDugum->sol)
            agacEkle(doku, aktifDugum->sol);
        else
            aktifDugum->sol = new DugumAgac(doku);
    }
    else return;
}

int IkiliAramaAgaci::yukseklikBul() //yukseklikBul fonksiyonunun disaridan cagirmaya yarayan fonksiyon. Ayni fonksiyonun overload halini kok bilgisi vererek yeniden cagiriyor.
{
    return yukseklikBul(kok);
}
int IkiliAramaAgaci::yukseklikBul(DugumAgac* aktifDugum)    //Parametre olarak verilen dugumun yuksekligini buluyor.
{
    if (aktifDugum)
    {
        aktifDugum->yukseklik = 1+max(yukseklikBul(aktifDugum->sol), yukseklikBul(aktifDugum->sag));
        return aktifDugum->yukseklik;
    }
    return -1;
}

void IkiliAramaAgaci::dengelimi()   //dengelimi fonksiyonunu disaridan cagirmaya yarayan fonksiyon. Ayni fonksiyonun overload halini kok bilgisi vererek yeniden cagiriyor.
{
    dengelimi(kok);
}
void IkiliAramaAgaci::dengelimi(DugumAgac* aktifDugum)  //Agac AVL agaci mantigi olarak dusunuldugunde dengeli mi dengesiz mi oldugunu buluyor.
{
    if (aktifDugum)
    {
        if (!(abs(yukseklikBul(aktifDugum->sol) - yukseklikBul(aktifDugum->sag)) < 2))  //Yukseklik farki 2 veya daha fazla ise dengesiz yapiyor.
            denge = false;
        dengelimi(aktifDugum->sol);
        dengelimi(aktifDugum->sag);
    }
}

void IkiliAramaAgaci::agacYazdir()  //Agac dengeliyse bosluk dengesizse # karakterini yazdiriyor.
{
    dengelimi();
    if (denge)
        cout << " ";
    else
        cout << "#";
    
}

bool IkiliAramaAgaci::mutasyonAgac()    //mutasyonAgac fonksiyonunu disaridan cagirmaya yarayan fonksiyon. Eger agacin kokunde tuttugu dokunun ortasindaki sayi 50'e tam bolunuyorsa ayni fonksiyonun overload halini kok bilgisi vererek yeniden cagiriyor.
{
    if (kok)
    {
        if (kok->doku->ortaSayi->veri % 50 == 0)
        {
            mutasyonAgac(kok);
            return true;
        }
        else
            return false;
    }
}

void IkiliAramaAgaci::mutasyonAgac(DugumAgac* aktifDugum)   //Agacin butun dugumlerini dolasip dugumler icin mutasyonDoku fonksiyonunu cagiriyor.(Dokudaki sayilar ciftse ikiye boluyor)
{
    if (aktifDugum)
    {
        mutasyonAgac(aktifDugum->sol);
        mutasyonAgac(aktifDugum->sag);
        aktifDugum->doku->mutasyonDoku();
    }
}

void IkiliAramaAgaci::agacAktar(Doku** doku)    //agacAktar fonksiyonunu disaridan cagirmaya yarayan fonksiyon. Ayni fonksiyonun overload halini kok bilgisi vererek yeniden cagiriyor.
{
    sayac = 0;
    agacAktar(doku, kok);
}

void IkiliAramaAgaci::agacAktar(Doku** doku, DugumAgac* aktifDugum) //Parametre olarak doku dizisi aliyor. Agaci post order olarak dolasip doku dizisine kendi doku bilgilerini aktariyor.
{
    if (aktifDugum)
    {
        agacAktar(doku, aktifDugum->sol);
        agacAktar(doku, aktifDugum->sag);
        doku[sayac] = aktifDugum->doku;
        sayac++;
    }
}

bool IkiliAramaAgaci::dugumSil(DugumAgac* &aktifDugum)  //Agacin bir dugumunu silmeye yarayan fonksiyon.
{
	DugumAgac *silinecek = aktifDugum;
	
	if(aktifDugum->sag == NULL) 
        aktifDugum = aktifDugum->sol;

	else if(aktifDugum->sol == NULL) 
        aktifDugum = aktifDugum->sag;

	else
    {
		silinecek = aktifDugum->sol;
		DugumAgac *ebeveyn = aktifDugum;
		while(silinecek->sag != NULL)
        {
			ebeveyn = silinecek;
			silinecek = silinecek->sag;
		}
		aktifDugum->doku->ortaSayi->veri = silinecek->doku->ortaSayi->veri;

		if(ebeveyn == aktifDugum) 
            aktifDugum->sol = silinecek->sol;
		else 
            ebeveyn->sag = silinecek->sol;
	}
	delete silinecek;
}