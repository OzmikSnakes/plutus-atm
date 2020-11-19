#pragma once
#include <QString>


class Nominal{
  int value;
public:
  Nominal(int val){value =val;};
  QString toQString(){
      return QString(value);
  }

    int  getValue()const{return value;};
  //  inline bool operator< (const Nominal& n1){
    //  return this->value< n1.getValue();
    //};

};


inline bool operator<(const Nominal& n,const Nominal& n1){
 return n.getValue()< n1.getValue();
}
