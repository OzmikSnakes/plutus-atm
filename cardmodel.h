#ifndef CARDMODE_H
#define CARDMODE_H

#include <QObject>

class CardModel:public QObject
{
    Q_OBJECT;
public:
    CardModel();
};

#endif // CARDMODE_H
/*


#ifndef CARDMODEL_H
#define CARDMODEL_H

#include <assert.h>
#include <QJsonObject>
#include <QObject>


class CardModel : public QObject
{
    Q_OBJECT

public:
    static const QString kKeyCard;
    static const QString kKeyPIN;
    static const QString kKeyURL;
    static const QString kKeyBallance;
    static const int kNotFound = -1;


    CardModel();

    const QString cardId() const {
        assert(_object[kKeyCard].isString());
        return _object[kKeyCard].toString();
    }

    const QString pinNumString() const {
        assert(_object[kKeyPIN].isString());
        return _object[kKeyPIN].toString();
    }

    void setPinNumString(const QString &pin) {
        _object[kKeyPIN] = pin;
    }

    const QString urlString() const {
        assert(_object[kKeyURL].isString());
        return _object[kKeyURL].toString();
    }

    int ballance() const {
//        assert(_object[kKeyBallance].isInt());
        return _object[kKeyBallance].toInt();
    }

    void setBallance(int ballance) {
        _object[kKeyBallance] = ballance;
    }

    void save();

private slots:
    void setBallanceSlot(int ballance);

private:
    QJsonObject _object;
};

#endif // CARDMODEL_H
*/
