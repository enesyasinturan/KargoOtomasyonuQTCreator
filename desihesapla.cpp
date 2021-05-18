#include "desihesapla.h"
#include <cmath>

desiHesapla::desiHesapla()
{
    this->en = 0.0;
    this->boy = 0.0;
    this->yukseklik = 0.0;
    this->agirlik = 0.0;
    this->sonuc = 0.0;
}

float desiHesapla::desiHesaplama(float boy, float en, float yukseklik, float agirlik)
{
    sonuc = (boy * en * yukseklik)/3000;

    if(sonuc <= agirlik)
        return agirlik;
    else if(agirlik < sonuc)
        return sonuc;
}


