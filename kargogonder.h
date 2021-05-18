#ifndef KARGOGONDER_H
#define KARGOGONDER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class KargoGonder; }
QT_END_NAMESPACE

class KargoGonder : public QMainWindow
{
    Q_OBJECT

public:
    KargoGonder(QWidget *parent = nullptr);
    ~KargoGonder();

private slots:
    void on_checkBoxAgirliklaHesapla_stateChanged(int arg1);

    void on_pushButtonSehirEkle_clicked();

    void on_comboBoxGonderilecekSehir_currentIndexChanged(const QString &arg1);

    void on_tableWidgetSehirler_cellDoubleClicked(int row, int column);

    void on_tableWidgetSehirler_cellClicked(int row, int column);

    void on_pushButtonDesiHesapla_clicked();

    void on_pushButton_clicked();

    void on_pushButtonBilgiEkrani_clicked();

    void on_pushButtonUcretlendirmeBilgisi_clicked();

    void on_pushButtonUcretHesapla_clicked();

    void on_pushButtonKaydet_clicked();

    void on_groupBoxGonderiKayit_clicked();

    void on_pushButtonKaydet2_clicked();

private:
    Ui::KargoGonder *ui;
};
#endif // KARGOGONDER_H
