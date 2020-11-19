#pragma once
#include "Nominal.h"
#include "QMap"
#include "QSet"


class CashControllerImpl
{
    QMap<Nominal,int> map;

public:
    CashControllerImpl();
    QMap<Nominal,int> withdrawCash(unsigned int);
    QList<Nominal> nominalsAvailable();
    QString nominalsAvailableString();
    QMap<Nominal,int> canWithdraw(int amount);
    int putNominal(Nominal, int amount);

    QString convertFromMap(QMap<Nominal,int>);

};


class CashController {
public:
   static CashController& getInstance() {
           static CashController * _instance = 0;
           if ( _instance == 0 ) {
               _instance = new CashController();
           }
           return *_instance;

  }
    QMap<Nominal,int> withdrawCash(unsigned int i){return impl->withdrawCash(i);}
    QList<Nominal> nominalsAvailable(){return impl->nominalsAvailable();}
    QString nominalsAvailableString(){return impl->nominalsAvailableString();}
    QMap<Nominal,int> canWithdraw(int amount){return impl->canWithdraw(amount);}
    int putNominal(Nominal n, int amount){return impl->putNominal(n, amount);}


    QString convertFromMap(QMap<Nominal,int> m){return impl->convertFromMap(m);}

private:
    CashController():impl(new CashControllerImpl()){};
    CashControllerImpl* impl;
};