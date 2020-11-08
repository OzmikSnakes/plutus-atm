#ifndef CASHCONTROLLER_H
#define CASHCONTROLLER_H
#include "Nominal.h"
#include "QMap"
#include "QSet"
class CashController
{
    CashController();
    QMap<Nominal,int> map;

public:

   static CashController& getInstance(){
       static CashController * _instance = 0;
       if ( _instance == 0 ) {
           _instance = new CashController();
       }
       return *_instance;
   }

    bool withdrawCash(unsigned int);
    QList<Nominal> nominalsAvailable();
    QString nominalsAvailableString();
    bool canWithdraw(int amount);
    int putNominal(Nominal, int amount);
};

#endif // CASHCONTROLLER_H
