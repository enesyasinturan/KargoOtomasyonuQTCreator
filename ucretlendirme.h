#ifndef UCRETLENDIRME_H
#define UCRETLENDIRME_H

#include <QMainWindow>

class ucretlendirme
{
public:
    float mesafeKatsayi;
    float mesafeFiyati;
    float desiFiyati;
    float ucret;
    ucretlendirme();
    float ucretHesapla(float mesafe, float desi);
};

#endif // UCRETLENDIRME_H
