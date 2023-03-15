/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#include "SatirListesi.hpp" //Sinifin header dosyasini kalitim aliyor

SatirListesi::SatirListesi(const string &satir) //SatirListesi kurucu metodu. 1 adet satiri ve icindeki sayi verilerini tutacak nesneyi tanimliyor. Icindeki komutlari nesne olusturuldugunda calistiriyor.
{
    ilkDugum = 0;           //Ilk dugum yanlis bir adres gostermemesi icin 0(NULL) atiyoruz.
    ortalama = 0;           //Ortalama baslangicta 0 olmali.
    satirListeEkle(satir);  //Parametre olarak alinan satiri alip bir satir verilerini nesneye aktariyor.
    ortalamaHesapla();      //Dosya sinifinda ortalamayi hesaplamistik ancak nesne olusturmadan bilgiyi cekemiyoruz. Kod kalabaligi yapmak yerine ve heap alanini bosa kullanmamak icin yeniden ortalamayi hesapliyoruz.
}

SatirListesi::~SatirListesi()   //SatirListesi yok edici metodu. Heap bellek alanina alinan hafiza geri iade ediliyor.(Dugumler siliniyor ve hafiza serbest birakiliyor.)
{
    Dugum* gec = ilkDugum;
    while (gec != 0)
    {
        Dugum* sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}

void SatirListesi::satirListeEkle(const string &satir) //Satir bilgilerini SatirListesi nesnesine aktariyor. Nesne dugumleri olusturuluyor.
{
    int sayi;
    dugumSayisi = 0;        //Bir SatirListesindeki dugum sayisi tutuluyor.
    stringstream ss(satir);
    while (ss >> sayi)
    {
        dugumSayisi++;
        Dugum* yeni = new Dugum(sayi); //Dugum Olusturuluyor, veri ataniyor.
        if (ilkDugum == 0)
        {
            ilkDugum = yeni;
        }
        else
        {
            Dugum* gec = ilkDugum;

            while (gec->sonraki != 0)
            {
                gec = gec->sonraki;
            }
            gec->sonraki = yeni;
            yeni->onceki = gec;
        }
    }
}

void SatirListesi::ortalamaHesapla() //Bir SatirListesine ait Dugumlerdeki verilerin ortalamasini hesapliyor.
{
    if (ilkDugum == 0);                 //Eger nesneye ait hic dugum yoksa islem yapmiyor
    else if (ilkDugum->sonraki == 0)    //Nesnenin tek dugumu varsa ortalama direkt tek dugumun verisi olur.
    {
        ortalama = ilkDugum->veri;
    }
    else                                //Eger SatirListesinde birden falza dugum varsa ortalamalarini hesapliyor.
    {   
        ortalama = 0;
        int sayac = 0;
        Dugum* gec = ilkDugum;
        while (gec != 0)
        {
            ortalama += gec->veri;
            sayac++;
            gec = gec->sonraki;
        }
        ortalama /= sayac;
    }
}

float SatirListesi::ortalamaDondur()    //Sisteme kaydedilen Bir SatirListesine ait ortalama bilgisini donduren fonksiyon.
{
    return ortalama;
}

int SatirListesi::dugumSayisiDondur()   //Sisteme kayitli Bir SatirListesine ait dugumSayisini donduren fonksiyon.
{
    return dugumSayisi;
}

Dugum* SatirListesi::dugumGetirSatir(int &sira) //Bir SatirListesinde ki istenilen indekste ki dugumu donduruyor.
{
    if (sira < 0)
    {
        cout << "dugumGetirSatir(): 0'dan buyuk deger giriniz!" << endl;
    }
    Dugum* gec = ilkDugum;
    int sayac = 0;
    while (gec != 0)
    {
        if (sira == sayac)
        {
            return gec;
        }
        gec = gec->sonraki;
        sayac++;
    }
    return 0;
}

void SatirListesi::dugumSil(int &sira)              //Bir SatirListesinde ki istenilen indekste ki dugumu siliyor.
{
    if (dugumGetirSatir(sira))
    {
        Dugum* silinecek = dugumGetirSatir(sira);   //Istenilen siradaki dugum kolaylik acisindan yine bir Dugum degiskenine ataniyor.
        Dugum* silOnceki = silinecek->onceki;       //Dugumun onceki ve sonraki dugumlerinin adresleri yedekleniyor.
        Dugum* silSonraki = silinecek->sonraki;

        if (silSonraki)                             //Dugumden sonra bir dugum yoksa olmayan bir sonraki dugumun onceki elemanina erisemeyecegimiz icin if kontrolu yapiyoruz.
        {
            silSonraki->onceki = silOnceki;
        }
        if (silOnceki)                              //Dugumden once bir dugum yoksa olmayan bir onceki dugumun sonraki elemanina erisemeyecegimiz icin if kontrolu yapiyoruz.
        {
            silOnceki->sonraki = silSonraki;
        }
        else                                        //Eger silOnceki yoksa sildigimiz dugumden sonraki dugum yeni ilk dugum olacaktir.
        {
            ilkDugum = silSonraki;
        }
        delete silinecek;                           //dugum siliniyor ve adresi 0 ataniyor. Guvenli bir sekilde dugum silindi.
        silinecek = 0;
        dugumSayisi--;                              //Dugum silindigi icin dugum sayisini eksiltiliyor.
        if (dugumSayisi > 0)                        //Liste de hala dugum varsa ortalamasi hesaplaniyor.
        {
            ortalamaHesapla();
        }
    }
}


void SatirListesi::boslukBirak(int &index)          //Yazdir fonksiyonu icin istenilen kadar bosluk birakan fonksiyon. YoneticiListesi yazdir fonksiyonunda secili listenin dugumlerini altina yazdirmak icin gerektigi kadar bosluk birakiyor.
{
    cout << setw(13*(index%8)) << "";
}

void SatirListesi::satirYazdir(int &index,int &kontrol, int &isaret) //YoneticiListesinde kacinci liste secili index i parametre olarak aliyor. Kontrol YoneticiListesinden geliyor. k harfi ile kullanilan komut icin kullaniliyor. Isarette ayni sekilde k ilgili komut icin ekrana ok cikariyor.
{
    if (kontrol == 0) //Kontrol parametesi dugum silme yazisini acip kapama dugmesi gibi diyebilirim. 0 ise normal yazdiriyor. 1 ise ekrana silinecek dugumu isaret ederek yazdirilmasini saglayacak komuta giriyor.
    {
        Dugum* gec = ilkDugum;
        boslukBirak(index); cout << "^^^^^^^^^^^  " << endl;
        while (gec != 0)                                                    //Bu komut genel olarak SatirListesinin dugumlerini alt alta yazdiriyor.
        {
            boslukBirak(index); cout << setw(10) << gec << endl;
            boslukBirak(index); cout << setw(11) << "-----------  " << endl;
            boslukBirak(index); cout << setw(1) << "|" << setw(5) << gec->veri << setw(5) << "|" << endl;
            boslukBirak(index); cout << setw(11) << "-----------  " << endl;
            boslukBirak(index); cout << setw(1) << "|" << setw(9) << gec->sonraki << setw(1) << "|" << endl;
            boslukBirak(index); cout << setw(11) << "-----------  " << endl << endl;
            gec = gec->sonraki;
        }
    }
    else if (kontrol == 1) //Kontrol 1 donmesi dugum silme islemi yapiliyor demektir. Kontrol 0 iken isaret parametresinin bir onemi yoktur. Isaret parametresi ancak kontrol 1 oldugunda onemlidir.
    {
        int sayac = 0;
        Dugum* gec = ilkDugum;
        boslukBirak(index); cout << "^^^^^^^^^^^  " << endl;
        while (gec != 0)
        {
            if (sayac == isaret) //Isaret parametresi rastgele bir index donduruyor. Dongu isaret ile ayni indexe gelene kadar donuyor sayac bunu sayiyor. Sayac ile isaret ayni oldugunda silinecek dugume gelindi demektir. Bu dugum ok ile isaret ediliyor.
            {
                boslukBirak(index); cout << setw(10) << gec << endl;
                boslukBirak(index); cout << setw(11) << "-----------  " << endl;
                boslukBirak(index); cout << setw(1) << "|" << setw(5) << gec->veri << setw(5) << "|" << endl;
                boslukBirak(index); cout << setw(11) << "-----------  " << setw(20) << "<=== Silinecek Dugum" << endl;
                boslukBirak(index); cout << setw(1) << "|" << setw(9) << gec->sonraki << setw(1) << "|" << endl;
                boslukBirak(index); cout << setw(11) << "-----------  " << endl << endl;
                gec = gec->sonraki;
            }
            else
            {
                boslukBirak(index); cout << setw(10) << gec << endl;
                boslukBirak(index); cout << setw(11) << "-----------  " << endl;
                boslukBirak(index); cout << setw(1) << "|" << setw(5) << gec->veri << setw(5) << "|" << endl;
                boslukBirak(index); cout << setw(11) << "-----------  " << endl;
                boslukBirak(index); cout << setw(1) << "|" << setw(9) << gec->sonraki << setw(1) << "|" << endl;
                boslukBirak(index); cout << setw(11) << "-----------  " << endl << endl;
                gec = gec->sonraki;
            }
            sayac++;
        }
    }
}