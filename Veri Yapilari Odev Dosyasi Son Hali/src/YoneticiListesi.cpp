/**
* @file Veri Yapilari Odev Dosyasi
* @description Program verilen dosya icerisinde ki verileri(satirlari, satirdaki sayilari, ortalamalarini, konumlarini) sistemde yonetmemizi sagliyor.
* @course 2. Ogretim C Grubu
* @assignment 1. Odev
* @date Odev Bitis Tarihi 17.11.22 Bitis Saati 02:18 Bitis Suresi 3 Gun
* @author Umut Can Çağatay
*/
#include "YoneticiListesi.hpp" //Sinifin header dosyasini kalitim aliyor

YoneticiListesi::YoneticiListesi(DosyaOkuma* &dosya, const int &satirSayisi) //YoneticiListesi kurucu metodu. Parametre olarak DosyaOkuma nesnesi(dosya) adresi ve satir sayisi aliyor.
{
    ilkYDugum = 0;  //Ilk dugum baslangicta yanlis bir adres gostermemeli, bu yuzden 0 ataniyor.
    this->satirAdet = satirSayisi; //Satir sayisini her defasinda parametre almak yerine sistemde tutuluyor.
    satirListe = new SatirListesi*[satirSayisi];    //SatirListesinin Listesi olusturuluyor.(Satirsayisi kadar)
    yoneticiEkle(dosya);    //Olusturulan SatirListeleri YDugumlere ataniyor. Boylece YDugum nesnelerinin her biri bir adet SatirListesi tutuyor. YDugum nesneleride YoneticiListesi ile yonetiliyor.
}

YoneticiListesi::~YoneticiListesi() //YoneticiListesi yikici metodu. Heap bellekten alinan alanlar(YDugum) serbest birakiliyor.
{
    YDugum* gec = ilkYDugum;
    while (gec != 0)
    {
        YDugum* sil = gec;
        gec = gec->sonrakiYDugum;
        delete sil;
    }
    delete[] satirListe;    //Kurucuda olusturulan satirListe nesnesi siliniyor.(alani serbest birakiliyor)
}

void YoneticiListesi::yoneticiEkle(DosyaOkuma* &dosya)      //YDugumler olusturuluyor ve YDugumlere SatirListesi nesnelerinin adresleri araciligi ile ataniyor.
{
    for (int i = 0; i < satirAdet; i++)                     //Satiradeti kadar yani SatirListesi adeti kadar donen dongu
    {   
        satirListe[i] = new SatirListesi(dosya->satirDondur(i));    //SatirListesi nesnesine satir verileri ataniyor.
        YDugum* yeniYDugum = new YDugum(satirListe[i]);             //YDugum nesneleri olusturuluyor. SatirListesi nesneleri YDugum nesnelerine baglaniyor.
        if (ilkYDugum == 0)
        {
            ilkYDugum = yeniYDugum;
        }
        else
        {
            YDugum* gecYDugum = ilkYDugum;

            while (gecYDugum->sonrakiYDugum != 0)
            {
                gecYDugum = gecYDugum->sonrakiYDugum;
            }
            gecYDugum->sonrakiYDugum = yeniYDugum;
            yeniYDugum->oncekiYDugum = gecYDugum;
        }
    }
}

int YoneticiListesi::rastgeleSayiDondur(int &index) //Istenilen indexte ki SatirListesinde kac dugum varsa o sayi araliginda rastgele sayi uretiyor.
{                                                   //(Ornek ==> 5 dugum varsa 0 ile 4 arasinda(indexte kullanildigi icin boyle uygun) 5 birim araliginda uretiliyor.)
    return rand() % dugumGetir(index)->adres->dugumSayisiDondur();
}

YDugum* YoneticiListesi::dugumGetir(int &sira)  //Istenilen indexte ki YDugum(SatirListesi) donduruyor.
{
    if (sira < 0)
    {
        cout << "dugumGetir(): 0'dan buyuk deger giriniz!" << endl;
    }
    YDugum* gec = ilkYDugum;
    int sayac = 0;
    while (gec != 0)
    {
        if (sira == sayac)
        {
            return gec;
        }
        gec = gec->sonrakiYDugum;
        sayac++;
    }
    return 0;
}

void YoneticiListesi::yoneticiDugumCikar(int &sira) //'p' komutu icin sile fonksiyonu. Silinecek dugumun onceki sonraki yedekleniyor.
{                                                   // Onceki Sonraki dugumlerin varligi kontrol edilerek secili dugum aradan cikarilarak siliniyor. Onceki Sonraki baglaniyor.
    YDugum* silinecek = dugumGetir(sira);           //Eger silinen ilk dugumse sonraki yeni ilk dugum oluyor.
    YDugum* silOnceki = silinecek->oncekiYDugum;
    YDugum* silSonraki = silinecek->sonrakiYDugum;

    if (silSonraki)
    {
        silSonraki->oncekiYDugum = silOnceki;
    }
    if (silOnceki)
    {
        silOnceki->sonrakiYDugum = silSonraki;
    }
    else
    {
        ilkYDugum = silSonraki;
    }
    sira = 0;   //Dugum silindikten sonra yazdir ekranin listenin en basina gitmesi icin sira referansla aliniyor parametreye index veriliyor yani sira index.. index i sifirliyoruz.
    delete silinecek;
    silinecek = 0;
    satirAdet--;    //Dugum eksildigi icin Satir Adeti 1 eksiliyor.
}

void YoneticiListesi::yerGuncelleme(int &index) //Ortalama degistiginde YDugum nesnelerinin konumlarini guncelleyen fonksiyon.
{
    YDugum* yedek = dugumGetir(index);              //Yeri degistirilecek dugum yedek adi altinda yedekleniyor.

    YDugum* yedekOnceki = yedek->oncekiYDugum;
    YDugum* yedekSonraki = yedek->sonrakiYDugum;

    if (yedekSonraki)
    {
        yedekSonraki->oncekiYDugum = yedekOnceki;
    }
    
    if (yedekOnceki)
    {
        yedekOnceki->sonrakiYDugum = yedekSonraki;
    }
    else
    {
        ilkYDugum = yedekSonraki;
    }                                               //Fonksiyon basindan buraya kadarki islem secili indekste ki dugumun cikarilma islemi bir cikarma isleminin aynisi.
                                                    
    YDugum* gec = ilkYDugum;
    while((gec->sonrakiYDugum != 0) && (yedek->adres->ortalamaDondur() > gec->adres->ortalamaDondur()))
    {
        gec = gec->sonrakiYDugum;       //Dongu son dugume varana kadar donuyor. Bu sirada kosulda yedek dugumun ortalamasi dongude ki siradaki dugumden buyuk mu kontrol ediyor. Eger ki buyukse donguden cikiyor.
    }
    YDugum* gecOnceki = gec->oncekiYDugum; //Dongude ki sirada kaldigimiz dugum onceki dugumunun adresini aliyoruz.
    
    gec->oncekiYDugum = yedek;              //Buradan sonrasi dugum ekleme islemi ile ayni. Onceki Dugum var mi kontrol ediyoruz. Yoksa ilk dugum yedek dugum oluyor.
    yedek->sonrakiYDugum = gec;
    if (gecOnceki)  
    {
        gecOnceki->sonrakiYDugum = yedek;
        yedek->oncekiYDugum = gecOnceki;
    }
    else
    {
        ilkYDugum = yedek;
    }
}

void YoneticiListesi::yoneticiYazdir(int &index, int &atla) //Yazdir fonksiyonunun YoneticiListesi'ne ait kismi. Ekrana 8'er sayfa olacak sekilde YDugum nesneleri(SatirListeleri) yazdiriliyor.
{                                                           //Sayfa da ilerleme gerileme kodlari burada yazili.
    int sinir;  //Dongulerdeki donme sinirini belirleyecek degiskenlerin tanimi.
    int sinir2; //sinir ve sinir2 kacinci sayfada olunduguna gore 8'in kati deger alacaklar. sinir dongunun baslangic degeri sinir2 ise sinir'in 8 fazlasi bitis degeri olacak.
    int control = 0; //Sayfanin ilk <== ==> son yazdirilmasini kontrol edecek degisken.
    system("cls");

    if ((atla == -1) || (atla == 1)) //Buraya 'a' ve 'd' girdilerine geldikten sonra donmenizi tercih ederim. atla yazdir fonksiyonundan parametre olarak geliyor.
    {                                //atla varsayilan olarak 0dir. Konsoldan 'a' tuslandiginda -1, 'd' tuslandiginda 1 olarak doner.
        if (((8 * ((index/8) + atla)) >= satirAdet))    //(8 * ((index/8) + atla)) ==> indexte kac tane 8 var bul, daha sonra atla degerini sonuca ekle, sonucla 8 i carp/
        {                                               //Eger sonuc satir adetine esit ya da buyukse sinir ve sinir2 yi normal bir sekilde ata.(Bu kontrol sayfadan cikmamasi icin)
            sinir = 8 * (index/8);                      //'d' komutu icin kontrol
            sinir2 = 8 * ((index/8)+1);                 //Ornek olarak uygulamada 3 sayfa olsun. 3. sayfa gosteriliyor bir daha 'd' basildiginda out_of_range hatasi almamak icin kontrol ediyoruz.
        }
        else if (((8 * ((index/8) + atla)) < 0))        //Ayni islem sifirdan kucuk oluyor mu kontrol et. 'a' komutu icin kontrol ediliyor.
        {           
            sinir = 8 * (index/8);
            sinir2 = 8 * ((index/8)+1);
        }
        
        else                                            //Eger ki bir sikinti yoksa ornek olarak uygulama da 3 safya var. 3. sayfa mevcutsa atlayi ekle ilerle.
        {
            sinir = (8 * ((index/8) + atla));
            sinir2 = (8 * (((index/8)+1) + atla));
            index = sinir;
        }
    }
    else                                //Eger atla degeri girilmemiste varsayilan olarak 0 olacak ve yukaridaki donguye girmeden simdi ki varsayilan atamalar yapilacak/
    {                                   //sinir dongunun baslangic verisi, sinir2 ise bitis verisi.
        sinir = 8 * (index/8);          // 8 * (index/8) su anlama geliyor: indexte kac tane 8 var yani kac tane sayfa olacak bir nevi onu hesapliyor. Daha sonra onu 8 ile carp. Baslangic verisi sonuc.
        sinir2 = 8 * ((index/8)+1);     //sinir2 ise sinir in 8 eklenmis hali. Ancak formulde bunu 8 * kat dersek kat'a +1 ekleme yaparak yapiyoruz.
    }

    for (int i = (sinir); i < (sinir2); i++)    // Sayfadaki dugumleri kontrol ediyor. Iclerinde sayfanin yarim kaldigi ya da son sayfanin 8in kati olup olmadigini kontrol ediyor.
    {    
        if (dugumGetir(i) == NULL || satirAdet-sinir == 8 || satirAdet-sinir == 0)
        {
            control = 1;    //Eger ki kosullardan biri dogruysa control 1 donuyor. Hemen asagida ki kodlarda kullaniliyor.
        }
    }
    
    if (sinir == 0)     //Ilk sayfadaysa bunu belirtecek yazilar yaziliyor.
    {
        if (control == 1)
        {
            cout << "ilk" << setw(99) << "son" << endl;
        }
        else
            cout << "ilk" << setw(99) << "==>" << endl;
    }
    else if (control == 1)  //Yukarida ki control degiskeni 1 donuyse yani son sayfada ise son oldugunu belirtecek yazilar yaziliyor.
    {
        cout << "<==" << setw(99) << "son" << endl;
    }
    else    //Ilk ya da son degilse aradaki sayfalardan baska bir sey olamaz bu yuzden ara sayfa oldugunu belirten yazilar yazdiriyor.
    {
        cout << "<==" << setw(99) << "==>" << endl;
    }
     
    
    for (int i = (sinir); i < (sinir2); i++)        //Dugumlerin adresleri 8'erli olarak yaziliyor
    {
        if (dugumGetir(i) == NULL)  //Verilen indexte dugum bulunamadiysa dongu kiriliyor. Ornek olarak 7 tane Dugum var Diyelim 8. yok. 7 tane yazdirip birakiyor. Olmayan 8. icin yazdirma yapmiyor.
        {
            break;
        }
        cout << setw(10) << dugumGetir(i) << "   ";
    }

    cout << endl;

    for (int i = (sinir); i < (sinir2); i++)    //Veriler arasina cizgi cekiyor.
    {
        if (dugumGetir(i) == NULL)
        {
            break;
        }
        cout << setw(11) << "-----------  ";
    }
    
    cout << endl;

    for (int i = (sinir); i < (sinir2); i++)    //Onceki Dugumlerin adreslerini 8'erli olarak yazdiriyor.
    {
        if (dugumGetir(i) == NULL)
        {
            break;
        }
        cout << setw(1) << "|" << setw(9) << dugumGetir(i)->oncekiYDugum << setw(1) << "|" <<"  ";
    }

    cout << endl;

    for (int i = (sinir); i < (sinir2); i++)    //Veriler arasina cizgi cekiyor.
    {
        if (dugumGetir(i) == NULL)
        {
            break;
        }
        cout << setw(11) << "-----------  ";
    }

    cout << endl;

    for (int i = (sinir); i < (sinir2); i++)    //Dugumlerin gosterdigi adreste ki SatirListesinde ki verilerin aritmetik ortalamasini yazdiriyor.
    {
        if (dugumGetir(i) == NULL)
        {
            break;
        }
        cout << setw(1) << "|" << setw(9) << fixed << setprecision(1) << dugumGetir(i)->adres->ortalamaDondur() << setw(1) << "|" <<"  ";
    }

    cout << endl;

    for (int i = (sinir); i < (sinir2); i++)    //Veriler arasina cizgi cekiyor.
    {
        if (dugumGetir(i) == NULL)
        {
            break;
        }
        cout << setw(11) << "-----------  ";
    }
    
    cout << endl;

    for (int i = (sinir); i < (sinir2); i++)    //Sonraki Dugumlerin adreslerini 8'erli olarak yazdiriyor.
    {
        if (dugumGetir(i) == NULL)
        {
            break;
        }
        cout << setw(1) << "|" << setw(9) << dugumGetir(i)->sonrakiYDugum << setw(1) << "|" <<"  ";
    }

    cout << endl;

    for (int i = (sinir); i < (sinir2); i++)    //Veriler arasina cizgi cekiyor.
    {
        if (dugumGetir(i) == NULL)
        {
            break;
        }
        cout << setw(11) << "-----------  ";
    }
    
    cout << endl << endl;
}   

void YoneticiListesi::yazdir()
{
    int index = 0;  //index degiskeni. Dugumler arasinda gezinmemyi saglayacak.
    int atla = 0;   //atla degiskeni. Sayfa sayfa gezinmeyi saglayacak.
    int kontrol = 0;//SatirListesi dugum silme isleminde dugum isaret etmeyi acip kapatacak anahtar.
    int isaret = 0; //SatirListesi dugum silme isleminde silinecek dugumun indeksini alacak, isaret edecek degisken.
    char girdi;     //Konsoldan komut girdilerini alacak degisken.
    while (true)    //Sonsuza kadar donen bir dongu
    {   
        system("cls");  //Konsol ekrani baslangicta temizleniyor.
        if (ilkYDugum == 0) //Eger hic dugum yoksa ekrana bilgi yazilari yazdiriliyor ve Program sonlandiriliyor.
        {
            cout << "Listenin tamami silindi. Somurdun bitti yeter :D" << endl;
            cout << "Program sonlandiriliyor..." << endl << endl;
            break;
        }
        yoneticiYazdir(index, atla);                                //YoneyiciListesi yazdiriliyor.
        dugumGetir(index)->adres->satirYazdir(index,kontrol,isaret);//YoneticiListesinde secili olan ydugumun(SatirListesi) dugumleri ydugumun altina yazdiriliyor.
        atla = 0;   //varsayilan olarak 0 ataniyor.
        cin >> girdi;   //komut girdisi aliniyor.

        if (girdi == 'c')   //Girdi 'c' ise index 1 arttiriliyor. Sonraki dugume geciliyor. Eger dugum son dugumse sonrasina gidilmiyor.
        {
            index++;
            if (index >= satirAdet)
            {
                index--;
            }
            
        }
        if (girdi == 'z')   //Girdi 'z' ise index 1 azaltiliyor. Onceki dugume geciliyor. Eger dugum ilk dugumse oncesine gidilmiyor.
        {
            index--;
            if (index < 0)
            {
                index++;
            }
            
        }
        if (girdi == 'd')   //Girdi 'd' ise atla 1 ataniyor. Atla nin 1 donmesi yoneticiYazdir fonksiyonuna iletiliyor. Sonraki sayfaya gecisi sagliyor.
        {
            atla = 1;
        }
        if (girdi == 'a')   //Girdi 'a' ise atla -1 ataniyor. Atla nin -1 donmesi yoneticiYazdir fonksiyonuna iletiliyor. Onceki sayfaya gecisi sagliyor.
        {
            atla = -1;
        }
        if (girdi == 'p')   //Girdi 'p' ise YoneticiListesi nden secili olan ydugum cikartiliyor(siliniyor).
        {
            yoneticiDugumCikar(index);
        }
        if (girdi == 'k')   //Girdi 'k' ise secili YDugum den(SatirListesi) rastgele bir dugum seciliyor. Tekrar girdi isteniyor. Girdi tekrar 'k' olursa secili dugum SatirListesinden siliniyor.
        {
            kontrol = 1;    //SatirListesi yazdir komutunda ki isaret parametresini aktif ediyor.
            isaret = rastgeleSayiDondur(index); //Isaret en fazla SatirListesindeki dugum sayisinin 1 eksigi, en az 0 arasinda rastgele bir sayi aliyor.
            system("cls");
            yoneticiYazdir(index, atla);
            dugumGetir(index)->adres->satirYazdir(index,kontrol,isaret);    //Ekrana silinecek dugum secili olarak yeniden Listeler yazdiriliyor.

            cin >> girdi;
            if (girdi == 'k')   //2. girdi yani onay bekleniyor onay gelirse dugum siliniyor.
            {
                dugumGetir(index)->adres->dugumSil(isaret); //Secili indexteki dugum siliniyor.
                if (dugumGetir(index)->adres->dugumSayisiDondur() <= 0) //Eger YDugumde(SatirListesi) hic dugum kalmamista YDugum u siliyor.
                {
                    yoneticiDugumCikar(index);
                }
                else    //YDugumde hala dugum mevcutsa yeni ortalamasina gore yer guncellestirmesini yapiyor.
                    yerGuncelleme(index);
            }
            kontrol = 0;    //Kontrol ve isaret varsayilana donerek dugum silme modu kapatiliyor :D
            isaret = 0;
        }
        
        if (girdi == 'e')   //Ek olarak ben programi sonlandirma tusu yaptim.
        {
            system("cls");
            cout << "Program sonlandirildi..." << endl << endl;
            break;
        }
    }
    
}