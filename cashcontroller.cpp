#include "cashcontroller.h"
#include "Nominal.h"

#include <QList>




CashController::CashController(){
    map[Nominal(20)]=20;
    map[Nominal(10)] =100;
    map[Nominal(100)]=0;
    map[Nominal(200)]=200;
    map[Nominal(500)]=50;
    }


bool CashController::withdrawCash(unsigned int){
return false;
}
QList<Nominal> CashController::nominalsAvailable(){    
    return map.keys();
}
QString CashController::nominalsAvailableString(){
    QList<Nominal> n  = map.keys();
    QString string;

    for(int i=0; i<n.size(); i++)
 {
        if(map[n[i]]!=0){
 string += QString::number(n[i].getValue());
 if(i<n.size()-1)
 string += "," ;
        }}
    return string;
}

bool CashController::canWithdraw(int amount){

QMapIterator<Nominal,int> iterator(map);
iterator.toBack();

while(iterator.hasPrevious()){

Nominal nom= iterator.previous().key();

int nominal = nom.getValue();
int am = iterator.value();
int rest =amount;

if(amount>nominal){
    int n  =rest / nominal;
    if(am>=n)
        rest -= n*nominal;
    else
        rest -= am*nominal;
}
if(rest == 0) return true;
}
return false;
}
int CashController::putNominal(Nominal n, int amount){
    if (map.contains(n))
       map[n] +=amount;
    else
        map[n]=amount;
    return 1;
}
