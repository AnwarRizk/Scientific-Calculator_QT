//#include <bits/stdc++.h>
#include <QVector>
#include "calculator.h"
#include "ui_calculator.h"
#define ll long long
using namespace std;

QString n1, n2, n, ans; ///////////////////////////////////////////

ll GCD(ll a, ll b){
    return (!b ? a : GCD(b, a % b));
}
ll LCM(ll a, ll b){
    return a / GCD(a, b) * b;
}
ll nPr(ll n, ll r){
    if(n < r)  return -1;
    QVector < ll > factroial(n + 1, 1);
    for(int i = 1; i <= n; i++) factroial[i] = factroial[i - 1] * i;
    return factroial[n] / factroial[n - r];
}
ll nCr(ll n, ll r){
  if(n < r)  return -1;
  ll p = 1, k = 1;
  if (n - r < r) r = n - r;
  // condition for minimum choose
  if(n < 1) return 0;
  while (r){
    p *= n, k *= r;
    ll m = GCD(p, k);
    p /= m, k /= m, n--, r--;
  }
  return p;
}
ll factorial(ll n){
    if(n == 1)  return 1;
    return n * factorial(n - 1);
}
QString to_binary(ll n){
  QString binary;
  while(n){
    binary += (n % 2 ? "1" : "0");
    n /= 2;
  }
  reverse(binary.begin(), binary.end());
  return binary;
}

bool is_int(QString s){
    for(auto& i : s){
        if(i == '.') return false;
    }
    return true;
}

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_NUM_1_textChanged(){
    n1 = ui -> NUM_1 -> toPlainText();
}

void Calculator::on_NUM_2_textChanged(){
    n2 = ui -> NUM_2 -> toPlainText();
}

void Calculator::on_number_textChanged(){
    n = ui -> number -> toPlainText();
}

void Calculator::on_add_clicked(){
    double res = n1.toDouble() + n2.toDouble();
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_sub_clicked(){
    double res = n1.toDouble() - n2.toDouble();
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_mult_clicked(){
    double res = n1.toDouble() * n2.toDouble();
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_div_clicked(){
    double res = n1.toDouble() / n2.toDouble();
    if(n2 == '0')   ans = "Can't Divide By Zero !!";
    else            ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_rem_clicked(){
    if(n2 == '0')   ans = "Can't Divide By Zero !!";
    else {
       ll res = n1.toLongLong() % n2.toLongLong();
       ans = QString::number(res);
    }
    ui -> RESULT -> setText(ans);
}

void Calculator::on_pow_clicked(){

    if(!is_int(n1) || !is_int(n2)){
        double res = pow(n1.toDouble(), n2.toDouble());
        ans = QString::number(res);
        ui -> RESULT -> setText(ans);
    }
    else {
        ll res = pow(n1.toLongLong(), n2.toLongLong());
        ans = QString::number(res);
        ui -> RESULT -> setText(ans);
    }
}

void Calculator::on_gcd_clicked(){
    ll res = GCD(n1.toLongLong(), n2.toLongLong());
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_lcm_clicked(){
    ll res = LCM(n1.toLongLong(), n2.toLongLong());
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_nPr_clicked(){
    ll res = nPr(n1.toLongLong(), n2.toLongLong());
    ans = QString::number(res);
    if(res == -1) ui -> RESULT -> setText("مينفعش ال r تبقى اكبر من ال n");
    else ui -> RESULT -> setText(ans);
}

void Calculator::on_nCr_clicked(){
    ll res = nCr(n1.toLongLong(), n2.toLongLong());
    ans = QString::number(res);
    if(res == -1) ui -> RESULT -> setText("مينفعش ال r تبقى اكبر من ال n");
    else ui -> RESULT -> setText(ans);
}

void Calculator::on_log10_clicked(){
    double res = log10(n.toDouble());
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_log2_clicked(){
    double res = log2(n.toDouble());
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_sqrt_clicked(){
    double res = sqrt(n.toDouble());
    ans = QString::number(res);
    ui -> RESULT -> setText(ans);
}

void Calculator::on_fact_clicked(){
    ll res = factorial(n.toLongLong());
    ans = QString::number(res);
    if(n.toInt() > 25)   ans = "too big to calculate !";
    ui -> RESULT -> setText(ans);
}

void Calculator::on_binary_clicked(){
    ans = to_binary(n.toLongLong());
    ui -> RESULT -> setText(ans);
}

void Calculator::on_Equal_clicked(){
    ui -> RESULT -> setText(ans);
}












