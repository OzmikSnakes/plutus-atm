#ifndef FROMJSONCONVERTER_H
#define FROMJSONCONVERTER_H

template <class T> class FromJsonConverter
{
public:
    virtual T fromJson() = 0;
};

#endif // FROMJSONCONVERTER_H
