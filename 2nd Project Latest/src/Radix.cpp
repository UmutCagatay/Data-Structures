/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Radix.hpp"
#include<iomanip>
Radix::Radix(int* sayilar,int adet) //Parametre olarak aldigi dizideki bilgileri kendi icerisindeki diziye aktariyor. Siralamada kullanacagi kuyruk dizisini olusturuyor.
{
    this->sayiAdedi = adet;

    this->sayilar = new int[sayiAdedi];

    for(int i=0;i<sayiAdedi;i++)
        this->sayilar[i] = sayilar[i];

    kuyruklar = new Queue*[10];
    for(int i=0;i<10;i++)
        kuyruklar[i] = new Queue();
    
    
}
Radix::~Radix()
{
    delete[] sayilar;
    for(int i=0;i<10;i++)
        delete kuyruklar[i];
    
    delete [] kuyruklar;

    
}

int *Radix::sirala()    //Dizideki sayilari radixsort mantigina gore siraliyor ve diziyi donduruyor.
{

    for(int i=0;i<sayiAdedi;i++)
    {
        int sonBasamak = sayilar[i]%10;

        kuyruklar[sonBasamak]->ekle(sayilar[i]);

    }
    int maxBasamakSayisi = maxBasamakSayisiGetir();
    
    
    int basamakCarpani = 10;

    for(int i = 1;i<maxBasamakSayisi;i++ )
    {
        int uzunluklar[10];

        kuyrukUzunluklariGetir(uzunluklar);

        for(int j=0;j<10;j++)
        {
            int es = uzunluklar[j];

            while(es)
            {
                int siradakiSayi = kuyruklar[j]->getir();

                kuyruklar[j]->cikar();
                int basamak = (siradakiSayi/basamakCarpani)%10;
                kuyruklar[basamak]->ekle(siradakiSayi);
                es--;
            }
        }
        basamakCarpani*=10;
    }
    int diziIndex = 0;
    for(int i=0;i<10;i++)
    {
        while(!kuyruklar[i]->bosmu())
        {
            sayilar[diziIndex] = kuyruklar[i]->getir();
            kuyruklar[i]->cikar();
            diziIndex++;
        }
    }
    
    return sayilar;
}

int Radix::maxBasamakSayisiGetir()
{
    int maxBasamakSayisi = basamakSayisiGetir(sayilar[0]);

    for(int i=1;i<sayiAdedi;i++)
    {
        int siradakiBasamakSayisi = basamakSayisiGetir(sayilar[i]);
        if(maxBasamakSayisi<siradakiBasamakSayisi)
            maxBasamakSayisi = siradakiBasamakSayisi;
    }
    return maxBasamakSayisi;
}
int Radix::basamakSayisiGetir(int sayi)
{
    int basamakSayisi = 0;
    while(sayi)
    {
        sayi = sayi/10;
        basamakSayisi++;
    }
    return basamakSayisi;

}

void Radix::kuyrukUzunluklariGetir(int* uzunluklar)
{
    for(int i=0;i<10;i++)
    {
        uzunluklar[i] = kuyruklar[i]->elemanSayisiGetir();
    } 
}