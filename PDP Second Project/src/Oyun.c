#include "Oyun.h"

int KoloniSayisiBul(char* text)
{
    int adet = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            adet++;
        }       
    }
    if (text[len-1] != ' ')
    {
        adet++;
    }
    
    return adet;
}

void OyunKolonileriOlustur(const Oyun this, char* text)
{
    char sayi_char[30];
    int sayac = 0;
    int koloni_sayac = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        
        if (text[i] == ' ')
        {
            
            this->Koloni_Listesi[koloni_sayac] = KoloniOlustur(atoi(sayi_char));
            koloni_sayac++;
            memset(sayi_char,0,strlen(sayi_char));
            sayac = 0;
            
            continue;
        }
        sayi_char[sayac] = text[i];
        sayac++;
    }
    if (text[len-1] != ' ')
    {   
        this->Koloni_Listesi[koloni_sayac] = KoloniOlustur(atoi(sayi_char));
    }
    
}

Oyun OyunOlustur(char* text)
{
    srand(time(NULL));
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->Taktik_A = ATaktikOlustur();
    this->Taktik_B = BTaktikOlustur();
    this->Uretim_A = AUretimOlustur();
    this->Uretim_B = BUretimOlustur();
    this->OyunBaslat = &OyunBaslat;
    this->OyunYoket = &OyunYoket;
    this->tur_sayisi = 1;
    this->koloni_sayisi = KoloniSayisiBul(text);
    this->alive_koloni = this->koloni_sayisi;
    this->Koloni_Listesi = (Koloni*)malloc(this->koloni_sayisi * sizeof(struct KOLONI));

    OyunKolonileriOlustur(this, text);

    for (int i = 0; i < this->koloni_sayisi; i++)
    {
        this->Koloni_Listesi[i]->sembol = 65+i;
    }
    
    return this;
}



void OyunBaslat(const Oyun this)
{
    system("cls");
    do{
        if ((this->alive_koloni == 0) || (this->alive_koloni == 1))
        {       
            break;
        }
               
        EkranaYazdir(this);
        SavasYap(this);
        UretimYap(this);
        TurAtla(this);

        getchar();
    }while (this->alive_koloni != 1);
    EkranaYazdir(this);
    if (this->alive_koloni == 0)
    {
        printf("Son kolonilerin populasyonlari veya yemek stoklari bir sonraki tura gecmeye yeterli olmadi. Son koloniler kendi kendilerini yok ettiler.\n");
    }
    printf("Oyun sona erdi...");
    getchar();
}

void Savastir(const Oyun this, Koloni koloni1, Koloni koloni2)
{
    int random = rand() % 2;
    int koloni1_savasgucu;
    int koloni2_savasgucu;
    
    if (random == 0)
    {
        this->Taktik_A->TaktikPopulasyonAl(this->Taktik_A,koloni1->populasyon);
        koloni1_savasgucu = this->Taktik_A->super->Savas();
    }
    else
    {
        this->Taktik_B->TaktikPopulasyonAl(this->Taktik_B,koloni1->populasyon);
        koloni1_savasgucu = this->Taktik_B->super->Savas();
    }
    random = rand() % 2;
    if (random == 0)
    {
        this->Taktik_A->TaktikPopulasyonAl(this->Taktik_A,koloni2->populasyon);
        koloni2_savasgucu = this->Taktik_A->super->Savas();
    }
    else
    {
        this->Taktik_B->TaktikPopulasyonAl(this->Taktik_B,koloni2->populasyon);
        koloni2_savasgucu = this->Taktik_B->super->Savas();
    }

    double yuzde = abs(koloni1_savasgucu - koloni2_savasgucu) / 1000;
    if (koloni1_savasgucu == koloni2_savasgucu)
    {
        if (koloni1->populasyon == koloni2->populasyon)
        {
            random = rand() % 2;
            if (random == 0)
            {
                koloni2->populasyon -= (int)(koloni2->populasyon * yuzde);
                int yemek = koloni2->yemekStok * 10 / 100;
                koloni2->yemekStok -= yemek;
                koloni1->yemekStok += yemek;
                KoloniKazan(koloni1);
                KoloniKaybet(koloni2);
                if (koloni2->populasyon <= 0 || koloni2->yemekStok <= 0)
                {
                    koloni2->is_alive = 0;
                    this->alive_koloni--;
                }
                
            }
            else
            {
                koloni1->populasyon -= (int)(koloni1->populasyon * yuzde);
                int yemek = koloni1->yemekStok * 10 / 100;
                koloni1->yemekStok -= yemek;
                koloni2->yemekStok += yemek;
                KoloniKaybet(koloni1);
                KoloniKazan(koloni2);
                if (koloni1->populasyon <= 0 || koloni1->yemekStok <= 0)
                {
                    koloni1->is_alive = 0;
                    this->alive_koloni--;
                }
            }
            
        }
        
        else if (koloni1->populasyon > koloni2->populasyon)
        {
            koloni2->populasyon -= (int)(koloni2->populasyon * yuzde);
            int yemek = koloni2->yemekStok * 10 / 100;
            koloni2->yemekStok -= yemek;
            koloni1->yemekStok += yemek;
            KoloniKazan(koloni1);
            KoloniKaybet(koloni2);
            if (koloni2->populasyon <= 0 || koloni2->yemekStok <= 0)
            {
                koloni2->is_alive = 0;
                this->alive_koloni--;
            }
        }
        else
        {
            koloni1->populasyon -= (int)(koloni1->populasyon * yuzde);
            int yemek = koloni1->yemekStok * 10 / 100;
            koloni1->yemekStok -= yemek;
            koloni2->yemekStok += yemek;
            KoloniKaybet(koloni1);
            KoloniKazan(koloni2);
            if (koloni1->populasyon <= 0 || koloni1->yemekStok <= 0)
            {
                koloni1->is_alive = 0;
                this->alive_koloni--;
            }
        }
        
    }
    
    else if (koloni1_savasgucu > koloni2_savasgucu)
    {
        koloni2->populasyon -= (int)(koloni2->populasyon * yuzde);
        int yemek = koloni2->yemekStok * 10 / 100;
        koloni2->yemekStok -= yemek;
        koloni1->yemekStok += yemek;
        KoloniKazan(koloni1);
        KoloniKaybet(koloni2);
        if (koloni2->populasyon <= 0 || koloni2->yemekStok <= 0)
        {
            koloni2->is_alive = 0;
            this->alive_koloni--;
        }
    }

    else
    {
        koloni1->populasyon -= (int)(koloni1->populasyon * yuzde);
        int yemek = koloni1->yemekStok * 10 / 100;
        koloni1->yemekStok -= yemek;
        koloni2->yemekStok += yemek;
        KoloniKaybet(koloni1);
        KoloniKazan(koloni2);
        if (koloni1->populasyon <= 0 || koloni1->yemekStok <= 0)
        {
            koloni1->is_alive = 0;
            this->alive_koloni--;
        }
    }

}

void SavasYap(const Oyun this)
{
    int index = 0;
    for (int i = 0; i < this->koloni_sayisi; i++)
    {
        if (this->Koloni_Listesi[i]->is_alive == 1)
        {
            index = i + 1;
            for (int j = 0; j < this->koloni_sayisi-(i+1); j++)
            {
                if (this->Koloni_Listesi[index]->is_alive == 1)
                {
                    Savastir(this, this->Koloni_Listesi[i],this->Koloni_Listesi[index]);
                    index++;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            continue;
        }    
    }
}

void UretimYap(const Oyun this)
{
    int random;
    int koloni_uretimgucu;
    for (int i = 0; i < this->koloni_sayisi; i++)
    {
        if (this->Koloni_Listesi[i]->is_alive == 1)
        {
            random = rand() % 2;

            if (random == 0)
            {
                this->Uretim_A->UretimPopulasyonAl(this->Uretim_A,this->Koloni_Listesi[i]->populasyon);
                koloni_uretimgucu = this->Uretim_A->super->Uret();
            }
            else
            {
                this->Uretim_B->UretimPopulasyonAl(this->Uretim_B,this->Koloni_Listesi[i]->populasyon);
                koloni_uretimgucu = this->Uretim_B->super->Uret();
            }
            this->Koloni_Listesi[i]->yemekStok += koloni_uretimgucu;
        }
        else
        {
            continue;
        }
    }
}

void TurAtla(const Oyun this)
{
    for (int i = 0; i < this->koloni_sayisi; i++)
    {
        if (this->Koloni_Listesi[i]->is_alive == 1)
        {
            this->Koloni_Listesi[i]->KoloniTurAtla(this->Koloni_Listesi[i]);
            if (this->Koloni_Listesi[i]->populasyon <= 0 || this->Koloni_Listesi[i]->yemekStok <= 0)
            {
                this->Koloni_Listesi[i]->is_alive = 0;
                this->alive_koloni--;
            }
        }
        else
        {
            continue;
        }
    }
    
}

void EkranaYazdir(const Oyun this)
{
    printf("Tur Sayisi: %d\t",this->tur_sayisi);printf("Hayatta Olan Koloni Sayisi: %d\n",this->alive_koloni);
    printf("-------------------------------------------------------------------------\n");
    printf("Koloni\t Populasyon\t Yemek Stogu\t Kazanma\tKaybetme\n");
    for (int i = 0; i < this->koloni_sayisi; i++)
    {
        printf("  %3c ",this->Koloni_Listesi[i]->sembol);
        if (this->Koloni_Listesi[i]->is_alive == 1)
        {
            printf("%10d\t%10d %10d\t   %10d\n", this->Koloni_Listesi[i]->populasyon, this->Koloni_Listesi[i]->yemekStok, this->Koloni_Listesi[i]->kazanma, this->Koloni_Listesi[i]->kaybetme);
        }
        else
        {
            printf("\t      --\t\t--\t   --\t\t   --\n");
        }
    }
    printf("-------------------------------------------------------------------------\n");
    this->tur_sayisi++;
    
}

void KoloniKazan(const Koloni this)
{
    this->kazanma++;
}

void KoloniKaybet(const Koloni this)
{
    this->kaybetme++;
}

void OyunYoket(const Oyun this)
{
    if(this == NULL) return;
    for (int i = 0; i < this->koloni_sayisi; i++)
    {
        this->Koloni_Listesi[i]->KoloniYoket(this->Koloni_Listesi[i]);
    }
    this->Taktik_A->TaktikYoket(this->Taktik_A);
    this->Taktik_B->TaktikYoket(this->Taktik_B);
    this->Uretim_A->UretimYoket(this->Uretim_A);
    this->Uretim_B->UretimYoket(this->Uretim_B);
    
	free(this);
}