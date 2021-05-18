#include "ucretlendirme.h"

ucretlendirme::ucretlendirme()
{
    mesafeKatsayi = 0.0;
    mesafeFiyati = 0.0;
    desiFiyati = 0.0;
    ucret = 0.0;
}

float ucretlendirme::ucretHesapla(float mesafe, float desi)
{
    if(mesafe < 201)
        mesafeKatsayi = 0.06f;
    else if(mesafe < 601)
        mesafeKatsayi = 0.05f;
    else if(mesafe < 1000)
        mesafeKatsayi = 0.04f;
    else
        mesafeKatsayi = 0.03f;

    mesafeFiyati = mesafeKatsayi * mesafe;

    desiFiyati = 7.75f + (desi * 0.90f);

    return ucret = desiFiyati + mesafeFiyati;
}


