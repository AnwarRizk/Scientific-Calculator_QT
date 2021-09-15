#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:

    void on_NUM_1_textChanged();
    void on_NUM_2_textChanged();
    void on_number_textChanged();

    void on_add_clicked();
    void on_sub_clicked();
    void on_mult_clicked();
    void on_div_clicked();
    void on_rem_clicked();
    void on_pow_clicked();
    void on_gcd_clicked();
    void on_lcm_clicked();
    void on_nPr_clicked();
    void on_nCr_clicked();

    void on_log10_clicked();
    void on_log2_clicked();
    void on_sqrt_clicked();
    void on_fact_clicked();
    void on_binary_clicked();

    void on_Equal_clicked();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H

















