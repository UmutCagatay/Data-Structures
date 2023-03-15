/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#include "YoneticiListesi.hpp" //YoneticiListesinden kalitim aliyor. YoneticiListesi diger classlari zaten kalitim aldigi icin ve diger classlarda kutuphaneler zaten ekli oldugu icin sadece YoneticiListesi eklemem yeterli.

int main()
{   
    system("cls");
    string dosyaAdi;
    cout << "Dosya adini .txt ile birlikte giriniz. Dosya isminde turkce karakter olmamali(Ornek: veriler.txt)" << endl;
    cout << "Dosya: "; cin >> dosyaAdi;
    DosyaOkuma* dosya = new DosyaOkuma(dosyaAdi); //Verilen dosya adi sisteme aktarilarak yeni bir dosya nesnesi olusturuluyor.
    YoneticiListesi* yonetici = new YoneticiListesi(dosya,dosya->satirSayisiGetir()); //YoneticiListesine dosya ve dosyada ki satir sayisi aktarilarak yeni bir nesne olusturuluyor.
    yonetici->yazdir(); //YoneticiListesi kurucusunda sistemde yapilacak butun islemleri gerceklestirdi. Geriye sadece ekrana yazdirmak ve uygulamayi kullanmak kaliyor.

    delete dosya;   //Heap bellekten alinan hafiza geri sisteme iade ediliyor, serbest birakiliyor.
    delete yonetici;//Heap bellekten alinan hafiza geri sisteme iade ediliyor, serbest birakiliyor.
}