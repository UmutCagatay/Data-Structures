#include "Oyun.h"

int main()
{
    system("cls");
    char text[300];
    printf("Kodu giriniz: ");
    fgets(text, 300, stdin);
    
    Oyun o = OyunOlustur(text);
    
    o->OyunBaslat(o);

    return 0;
}