/**
* @file         Veri Yapilari Odev Dosyasi
* @description  Program Veri.txt icerisindeki sayilari okuyup verilerin istenen sekilde sakliyor ve veriler istenen kosullarda olup olmadigini kontrol ederek bu kosullara gore ekrana cikti yazdiriyor. Ardindan verileri istenen degisikligi uygulayip yeni ciktiyi ekrana yazdiriyor. Aslinda asil amac verilerin yonetimi.
* @course       2. Ogretim C Grubu
* @assignment   2. Odev
* @date         17.12.2022
* @author       Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
*/

#include "Queue.hpp"
#include <iomanip>

Queue::Queue()
{
    ilk=son=0;
    elemanSayisi=0;
}
Queue::~Queue()
{
    while(ilk!=0)
    {
        Dugum*gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }
}
bool Queue::bosmu() //Kuyruk bos mu kontrol ediyor.
{
    if(ilk==0)
        return true;
    return false;
}

void Queue::ekle(int veri)  //Aldigi veriyi dugum olarak kuyruga ekliyor.
{
    if(ilk==0)
    {
        ilk=new Dugum(veri);
        son= ilk;

    }
    else
    {
        Dugum*yeni = new Dugum(veri);
        son->sonraki = yeni;
        son = yeni;

    }
    elemanSayisi++;
}
void Queue::cikar() //Kuyruktan veri/dugum cikartiyor
{
    if(ilk!=0)
    {
        Dugum*gec = ilk->sonraki;
        delete ilk;
        ilk=gec;
        if(ilk==0)
            son=0;
        elemanSayisi--;
    }
}
int Queue::getir()  //Kuyrugun ilk dugumunun tuttugu veriyi donduruyor.
{
    if(ilk!=0)
        return ilk->veri;
}

int Queue::elemanSayisiGetir()  //Eleman sayisini tutan veriyi donduruyor.
{
    return elemanSayisi;
}