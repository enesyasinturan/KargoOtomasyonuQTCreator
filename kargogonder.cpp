#include "kargogonder.h"
#include "ui_kargogonder.h"
#include <QString>
#include <QMessageBox>
#include "desihesapla.h"
#include "ucretlendirme.h"

KargoGonder::KargoGonder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KargoGonder)
{
    ui->setupUi(this);

    ui->lineEditGonderenNumara->setInputMask(" (999) 999 9999");
    ui->lineEditAliciNumara->setInputMask(" (999) 999 9999");

}

KargoGonder::~KargoGonder()
{
    delete ui;
}


int j = 0;
void KargoGonder::on_pushButtonSehirEkle_clicked()
{
    ui->tableWidgetSehirler->insertRow(j);
    ui->tableWidgetSehirler->setItem(j,0,new QTableWidgetItem(ui->comboBoxSehirler->currentText()));
    ui->tableWidgetSehirler->setItem(j,1,new QTableWidgetItem(ui->spinBoxMesafe->text()));

    j++;
}


void KargoGonder::on_tableWidgetSehirler_cellClicked(int row, int column)
{
    QList<QTableWidgetItem *> item = *new QList<QTableWidgetItem *>;
    item.append(ui->tableWidgetSehirler->selectedItems());
    ui->lineEditGonderilecekSehir->setText(item[0]->text());
    ui->lineEditGonderilecekMesafe->setText(item[1]->text());
}

void KargoGonder::on_pushButtonDesiHesapla_clicked()
{
    desiHesapla desiNesnesi;
    float boy = ui->spinBoxBoy->value();
    float en = ui->spinBoxEn->value();
    float yukseklik = ui->spinBoxYukseklik->value();
    float agirlik = ui->doubleSpinBoxKg->value();

    float sonuc = desiNesnesi.desiHesaplama(boy,en,yukseklik,agirlik);
    QString yazi;
    ui->labelDesi->setText(yazi.setNum(sonuc));
}

void KargoGonder::on_pushButtonBilgiEkrani_clicked()
{
    QMessageBox::information(this,"Desi Hesaplama Hakkında",
                             "Ücrete Esas Ağırlık: Gönderilerinizin fiyatlandırılmasında kullanılan değerdir.\n\n"
"İlk olarak gönderinin hacmi hesaplanır.\n"
"Hacim Formülü: {En (cm) x Boy (cm) x Yükseklik (cm)} / 1.000\n\n"
"Gönderi hacmi üçe bölünür ve ağırlık ile karşılaştırılır.\n\n"
"Hangisi büyük ise 'Ücrete Esas Ağırlık' olarak kullanılır.\n"
"________________________________________________________________\n\n"
"Örneğin kargomuz 30x40x20 boyutlarında ve 9 kilo ağırlığında olsun.\n\n"
"Hacim sonucu 24 çıkar ve bu sonucu 3'e bölüp ağırlık ile karşılaştırırsak, "
"ağırlık değeri daha büyük olduğundan ücreti hesaplamak için kullanınan 'Ücrete Esas Ağırlık' 9 olarak alınır.");
}

void KargoGonder::on_pushButtonUcretlendirmeBilgisi_clicked()
{
    QMessageBox::information(this,"Ücretlenme Hakkında",
"Ücretlendirme için iki aşama gereklidir.\n\n\n"


"Birinci Aşama - Mesafe Fiyatlandırılması\n"

"_________________________________________\n\n"
"Farklı şehirler arasındaki gönderiler, "
"iki şehir merkezi arasındaki karayolu mesafesi (km) kullanılarak HAT mesafelerini oluşturur.\n\n"
"1 - 200 km : Yakın Hat\n"

"201- 600 km : Kısa Hat\n"

"601 - 1000 km : Orta Hat\n"

"1.000 km üzeri : Uzun Hat\n\n"
"Bu hatlar üzerinden mesafe çarpanları verilir.\n"
"Yakın Hat: 0,06\n"
"Kısa Hat: 0,05\n"
"Orta Hat: 0,04\n"
"Uzun Hat: 0,03\n\n"
"Bu mesafe çarpanları, kargonun gidecek mesafesiyle çarpılır ve bir ücret elde edilir.\n\n\n"
"İkinci Aşama - Desi Fiyatlandırılması\n"
"______________________________________\n\n"
"İlk desi fiyatı 7,75 TL'dir. Bundan sonraki her desi için bu ücrete 0,90 TL ilave edilir.\n\n"
"Bu iki fiyatlandırma toplanarak ana ücrete ulaşır.\n\n\n"
"Örneğin 4 desilik, 700 km yol gidecek kargomuz olsun. Mesafelendirmeye göre bu 'Orta Hat' olarak geçer ve çarpanı 0,04 olur.\n"
"İlk fiyatlandırma 700 x 0,04 = 28 TL olarak bulunur.\n\n"
"İkinci fiyatlandırma, desi başlangıç fiyatı 7,75 ve her desi için 0,90 TL eklersek 11,35 TL fiyat çıkar.\n\n"
"Ücret = Mesafe + Desi = 28 + 11,35 => 39,35 TL");
}

void KargoGonder::on_pushButtonUcretHesapla_clicked()
{
    if(ui->lineEditGonderilecekMesafe->text().isEmpty() == true ||
            ui->labelDesi->text().isEmpty() == true)
        QMessageBox::critical(this,"Boş Alan Hatası","Ücreti hesaplamadan önce lütfen şehir seçimi ve desi hesabı yapınınız.");

    else
    {
        float mesafe;
        float desi;
        float sonuc;

        QString str1;
        QString str2;
        QString str3;

        str1 = ui->lineEditGonderilecekMesafe->text();
        mesafe = str1.toFloat();


        str2 = ui->labelDesi->text();
        desi  = str2.toFloat();

        ucretlendirme ucretNesnesi;
        sonuc = ucretNesnesi.ucretHesapla(mesafe, desi);


        ui->lineEditUcret->setText(str3.setNum(sonuc));
    }
}

int p = 0;
void KargoGonder::on_pushButtonKaydet_clicked()
{

}

//if(ui->lineEditAliciAdSoyad->text().isEmpty() == true ||
//        ui->lineEditAliciAdres->text().isEmpty() == true ||
//        ui->lineEditAliciNumara->text().isEmpty() == true ||
//        ui->lineEditGonderenAdSoyad->text().isEmpty() == true ||
//        ui->lineEditGonderenAdres->text().isEmpty() == true ||
//        ui->lineEditGonderenNumara->text().isEmpty() == true ||
//        ui->lineEditUcret->text().isEmpty() == true)
//    QMessageBox::critical(this,"Boş Alan Hatası","Gönderici ve alıcı bilgileri boş geçilemez.");

//else
//{
//    ui->tableWidgetGonderiKayit->insertRow(p);
//    ui->tableWidgetGonderiKayit->setItem(p,0,new QTableWidgetItem(ui->labelGonderenAdSoyad->text()));
//    ui->tableWidgetGonderiKayit->setItem(p,1,new QTableWidgetItem(ui->labelGonderenNumara->text()));
//    ui->tableWidgetGonderiKayit->setItem(p,2,new QTableWidgetItem(ui->labelGonderenAdres->text()));

//    ui->tableWidgetGonderiKayit->setItem(p,3,new QTableWidgetItem(ui->labelAliciAdSoyad->text()));
//    ui->tableWidgetGonderiKayit->setItem(p,4,new QTableWidgetItem(ui->labelAliciNumara->text()));
//    ui->tableWidgetGonderiKayit->setItem(p,5,new QTableWidgetItem(ui->labelAliciAdres->text()));

//    ui->tableWidgetGonderiKayit->setItem(p,6,new QTableWidgetItem(ui->comboBoxOdemeTuru->currentText()));
//    ui->tableWidgetGonderiKayit->setItem(p,7,new QTableWidgetItem(ui->lineEditUcret->text()));
//    p++;
//}


void KargoGonder::on_pushButtonKaydet2_clicked()
{
    if(ui->lineEditAliciAdSoyad->text().isEmpty() == true ||
            ui->lineEditAliciAdres->text().isEmpty() == true ||
            ui->lineEditAliciNumara->text().isEmpty() == true ||
            ui->lineEditGonderenAdSoyad->text().isEmpty() == true ||
            ui->lineEditGonderenAdres->text().isEmpty() == true ||
            ui->lineEditGonderenNumara->text().isEmpty() == true
            )
        QMessageBox::critical(this,"Boş Alan Hatası","Gönderici ve alıcı bilgileri boş geçilemez.");

    else if(ui->lineEditAliciAdSoyad->text().isEmpty() == true ||
            ui->lineEditAliciAdres->text().isEmpty() == true ||
            ui->lineEditAliciNumara->text().isEmpty() == true ||
            ui->lineEditGonderenAdSoyad->text().isEmpty() == true ||
            ui->lineEditGonderenAdres->text().isEmpty() == true ||
            ui->lineEditGonderenNumara->text().isEmpty() == true ||
            ui->lineEditUcret->text().isEmpty() == true)
        QMessageBox::critical(this,"Boş Alan Hatası","Lütfen kaydetmeden önce ücret hesaplayınız.");

    else
    {
        ui->tableWidgetGonderiKayit->insertRow(p);
        ui->tableWidgetGonderiKayit->setItem(p,0,new QTableWidgetItem(ui->lineEditGonderenAdSoyad->text()));
        ui->tableWidgetGonderiKayit->setItem(p,1,new QTableWidgetItem(ui->lineEditGonderenNumara->text()));
        ui->tableWidgetGonderiKayit->setItem(p,2,new QTableWidgetItem(ui->lineEditGonderenAdres->text()));

        ui->tableWidgetGonderiKayit->setItem(p,3,new QTableWidgetItem(ui->lineEditGonderilecekSehir->text()));
        ui->tableWidgetGonderiKayit->setItem(p,4,new QTableWidgetItem(ui->lineEditGonderilecekMesafe->text()));

        ui->tableWidgetGonderiKayit->setItem(p,5,new QTableWidgetItem(ui->lineEditAliciAdSoyad->text()));
        ui->tableWidgetGonderiKayit->setItem(p,6,new QTableWidgetItem(ui->lineEditAliciNumara->text()));
        ui->tableWidgetGonderiKayit->setItem(p,7,new QTableWidgetItem(ui->lineEditAliciAdres->text()));

        ui->tableWidgetGonderiKayit->setItem(p,8,new QTableWidgetItem(ui->comboBoxOdemeTuru->currentText()));
        ui->tableWidgetGonderiKayit->setItem(p,9,new QTableWidgetItem(ui->lineEditUcret->text()));

        //Temizle
        ui->lineEditGonderenAdSoyad->setText("");
        ui->lineEditGonderenNumara->setText("");
        ui->lineEditGonderenAdres->setText("");

        ui->lineEditAliciAdSoyad->setText("");
        ui->lineEditAliciNumara->setText("");
        ui->lineEditAliciAdres->setText("");

        ui->lineEditGonderilecekSehir->setText("");
        ui->lineEditGonderilecekMesafe->setText("");

        ui->spinBoxBoy->setValue(0);
        ui->spinBoxEn->setValue(0);
        ui->spinBoxYukseklik->setValue(0);
        ui->doubleSpinBoxKg->setValue(0.0);

        ui->labelDesi->setText("");

        ui->lineEditUcret->setText("");


        p++;
    }
}
