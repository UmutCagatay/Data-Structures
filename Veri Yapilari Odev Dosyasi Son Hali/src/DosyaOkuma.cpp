/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#include "DosyaOkuma.hpp" //Sinifin header dosyasini kalitim aliyor

DosyaOkuma::DosyaOkuma(string &dosyaAdi) //Kurucu fonksiyon ==> Nesne olusturuldugunda yapilacak islemleri gerceklestiriyor.
{
    this->dosyaAdi = dosyaAdi;                          //Kurucu fonksiyon oncelikle dosyaadini yani dosya verisini sisteme aktariyor.
    satirSayisiBulma();                                 //Ardindan dosyadaki satir sayisi bulunuyor.
    stringSatirListe = new string[satirSayisiGetir()];  //Satir sayisi kadar buyuklukte satirlar okundugunda yedeklenecek string dizi olusturuluyor.
    satirOkuma();                                       //Satir okuma islemi gerceklestiriliyor.
    satirOrtSirala();                                   //Okunan satirlar icindeki sayilarin arit. ort. gore siralaniyor.
}

DosyaOkuma::~DosyaOkuma()   //Heap bellekten alinan hafiza iade ediliyor.
{
    delete[] stringSatirListe;
    delete[] sayiOrtDizi;
}

string DosyaOkuma::satirDondur(int &sira) //SatirListesi olustururken kullanmak icin satir donduren fonksiyon.
{
    return stringSatirListe[sira];
}

bool DosyaOkuma::dizilisDogrumu(float* &sayidizi) //SatirOrtSirala da kullanilan sayilar dogru siralanmis mi kontrol yapan boolean fonksiyon
{
    for (int i = 0; i < satirSayisiGetir()-1; i++) //Satir sayisi kadar donen dongu
    {
        if (sayidizi[i] > sayidizi[i+1])           //Eger ki ornek verecek olursak 5. siradaki 6. siradakinden buyukse true donduruyor. Boylece SayiOrtSiralada ki dongu donmeye devam edecek.
        {
            return true;
        }
    }
    return false;                                   //Siralama dogruysa false donduruyor.
}

void DosyaOkuma::satirOrtSirala()                   //SatirListesine verileri aktarmadan once Satirlari arit. ort. gore kucukten buyuge siralayan fonksiyon. Boylece basit bir dongu ile SatirListelerine satir bilgilerini aktarabilecegiz.
{
    int sayi;
    int sayac;
    string gecici;

    sayiOrtDizi = new float[satirSayisiGetir()];    //Ortalamalari tutmak icin ve siralamak icin dizi.

    for (int i = 0; i < satirSayisiGetir(); i++)    //Olusturulan dizinin buyun elemanlarini sifirliyor,
    {
        sayiOrtDizi[i] = 0;
    }

    for (int i = 0; i < satirSayisiGetir(); i++)    //Satirdaki sayilari diziye aktarip 1 satirdaki sayilarin ortalamasini bulan kodu butun satirlari donecek kadar donduren dongu.
    {
        sayac = 0;
        stringstream ss(stringSatirListe[i]);       
        while (ss >> sayi)                          
        {                                           
            sayiOrtDizi[i] += (float)sayi;         //Satirdaki sayilari yine satirla ayni indekse sahip dizide topluyor. 
            sayac++;                                
        }
        sayiOrtDizi[i] /= (float)sayac;             //Indekste ki toplanmis sayilari sayi adedine bolerek ortalama sayiOrtDizi[indeks] seklinde olarak ataniyor.
    }

    while (dizilisDogrumu(sayiOrtDizi))             //Dizideki sayilar dogru siralanmis mi kontrol eden boolean fonksiyon. Dogru siralanma oldugunda donguyu kiracak.
    {
        for (int i = 0; i < satirSayisiGetir()-1; i++)
        {
            if (sayiOrtDizi[i] > sayiOrtDizi[i+1])                  //
            {                                                       //
                swap(sayiOrtDizi[i],sayiOrtDizi[i+1]);              //Eger ki onceki indeks sonraki indeksten buyukse listelerdeki yerlerini degistiriyor.
                stringSatirListe[i].swap(stringSatirListe[i+1]);    //
            }                                                       //
        }
    }
}

void DosyaOkuma::satirOkuma()   //Satir okumasinin yapildigi ve stringSatirListeye satirlarin atandigi fonksiyon.
{
    ifstream dosya(dosyaAdi);
    if (dosya.is_open())
    {
        string satir;
        int sira = 0;
        while (!dosya.eof())
        {
            getline(dosya,satir);   //Satir okuyor ve satir degiskenine atiyor
            stringSatirListe[sira].assign(satir);   //stringSatirListe'ine satirlar ataniyor.
            sira++;
        }
        dosya.close();
    }
}

void DosyaOkuma::satirSayisiBulma() //Dosyada ki satir sayisini bulan fonksiyon
{
    ifstream dosya(dosyaAdi);
    if (dosya.is_open())
    {
        int sayac = 0;
        string satir;
        while(!dosya.eof())
        {
            getline(dosya,satir);
            sayac++;
        }
        dosya.close();
        satirSayisi = sayac;
    }
    else
    {
        cout << "Dosya okunamadi. Dosya adini kontrol ediniz." << endl; //exception yapilabilir
    }
}

int DosyaOkuma::satirSayisiGetir() //Her seferinde satir sayisi hesaplamak yerine sistemde tutulan satir sayisini donduren fonksiyon.
{
    return satirSayisi;
}