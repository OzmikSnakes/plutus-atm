#include "cashcontroller.h"
#include "Nominal.h"

#include <QList>
#include <QSet>




CashControllerImpl::CashControllerImpl(){
    map[Nominal(20)]=20;
    map[Nominal(10)] =10;
    map[Nominal(100)]=0;
    map[Nominal(200)]=200;
    map[Nominal(500)]=50;
    }


QMap<Nominal, int> CashControllerImpl::withdrawCash (unsigned int amount){
    QMap <Nominal, int> r = canWithdraw(amount);
if(r.empty()) return r;

QMapIterator<Nominal,int> iterator(r);
while (iterator.hasNext()) {
    Nominal key  = iterator.next().key();
    map[key]-=iterator.value();

}
return r;
}

QList<Nominal> CashControllerImpl::nominalsAvailable(){
    return map.keys();
}
QString CashControllerImpl::nominalsAvailableString(){
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

QMap<Nominal,int> CashControllerImpl::canWithdraw(int amount){
    QMap <Nominal, int> result;

    QMapIterator<Nominal,int> iterator(map);
    iterator.toBack();
    unsigned int rest =amount;

    while(iterator.hasPrevious()){

    Nominal nom= iterator.previous().key();

    unsigned int nominal = nom.getValue();
    int am = iterator.value();

    if(rest>=nominal){
        int n  =rest / nominal;
        if(am>=n){
            rest -= n*nominal;
            result[Nominal(nominal)]=n;
        }
            else{
           if (am>0){
            rest -= am*nominal;
            result[Nominal(nominal)]=am;}
        }
        }
    if(rest == 0) return result;
    }
    result.clear();
    return result;

}

QString CashControllerImpl::convertFromMap(QMap<Nominal,int> map){

    QMapIterator<Nominal,int> iterator(map);
    QString result="";
    while(iterator.hasNext()){

    Nominal nom= iterator.next().key();

    int nominal = nom.getValue();
    int amount = iterator.value();

    result+=QString::number(nominal);
    result+=" грн, ";
    result+=QString::number(amount);
    result+=" купюр\n";

    }
    return result;
}



int CashControllerImpl::putNominal(Nominal n, int amount){
    if (map.contains(n))
       map[n] +=amount;
    else
        map[n]=amount;
    return 1;
}
