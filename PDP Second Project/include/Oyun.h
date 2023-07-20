#ifndef Oyun_h
#define Oyun_h

#include "ATaktik.h"
#include "BTaktik.h"
#include "AUretim.h"
#include "BUretim.h"
#include "Koloni.h"
#include "time.h"

struct OYUN
{
    int koloni_sayisi;
    int alive_koloni;
    int tur_sayisi;
    ATaktik Taktik_A;
    BTaktik Taktik_B;
    AUretim Uretim_A;
    BUretim Uretim_B;
    Koloni *Koloni_Listesi;

    void (*OyunBaslat)(struct OYUN*);
    void (*OyunYoket)(struct OYUN*);

};
typedef struct OYUN* Oyun;

    Oyun OyunOlustur(char*);
    void OyunBaslat(const Oyun);
    void EkranaYazdir(const Oyun);
    void SavasYap(const Oyun);
    void UretimYap(const Oyun);
    void TurAtla(const Oyun);
    void KoloniKazan(const Koloni);
    void KoloniKaybet(const Koloni);

    void OyunYoket(const Oyun);

#endif