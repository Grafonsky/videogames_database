#ifndef AAA_GAME_H
#define AAA_GAME_H

#include <QDataStream>
#include <QBitmap>

// ОБЪЯВЛЕНИЕ И ИНИЦИАЛИЗАЦИЯ КЛАССА vg
class vg
{
public:
    QString title; //объявление и инициализация строки с названием
    int platform; //объявление и инициализация переменной с платформой
    bool flagmp; //объявление и инициализация флага о наличии мультиплеера
    bool flagcrossplatform; //объявление и инициализация флага о наличии кроссплатформы
    bool flagsplitcreen; //объявление и инициализация флага о наличии сплитскрина
    QString otherspecs; //объявление и инициализация строки с доп описанием
    bool flagavailability; //объявление и инициализация флага о наличии
    int price; //объявление и инициализация переменной с ценой
    unsigned int id; //объявление и инициализация переменной с идентификатором

// ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР РАВЕНСТВА
    bool operator==(const vg &other)
    {
        if(platform==other.platform)
            if(price==other.price)
                if(true==(title==other.title))
                    return true;
                else
                    return false;
            else
                return false;
        else
            return false;
    }

// ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР НЕРАВЕНСТВА
    bool operator!=(const vg &other)
    {
        if(*this==other)
            return false;
        else
            return true;
    }

// ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР БОЛЬШЕ ЛИБО РАВНО
    bool operator>=(const vg &other)
    {
        if(platform>=other.platform)
            if(price>=other.price)
                if(true==(title>=other.title))
                    return true;
                else
                    if(price>other.price||platform>other.platform)
                        return true;
                    else
                        return false;
            else
                if(platform>other.platform)
                    return true;
                else
                    return false;
        else
            return false;
    }

// ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР МЕНЬШЕ
        bool operator<(const vg &other)
        {
            if(*this>=other==true)
                return false;
            else
                return true;
        }

//ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР МЕНЬШЕ ЛИБО РАВНО
        bool operator<=(const vg &other)
        {
            if(platform<=other.platform)
                if(price<=other.price)
                    if(true==(title<=other.title))
                        return true;
                    else
                        if(price<other.price||platform<other.platform)
                            return true;
                        else
                            return false;
                else
                    if(platform<other.platform)
                        return true;
                    else
                        return false;
            else
                return false;
        }

// ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР БОЛЬШЕ
        bool operator>(const vg &other)
        {
            if(*this<=other==true)
                return false;
            else
                return true;
        }

// КЛАСС ЗАПИСИ/ЧТЕНИЯ ДАННЫХ ИЗ ПОТОКА
        friend QDataStream &operator<<(QDataStream &file ,const vg &vg)
        {
        file << vg.title << vg.platform << vg.flagmp << vg.flagcrossplatform << vg.flagsplitcreen << vg.otherspecs << vg.flagavailability << vg.price << vg.id;
        return file;
        }
        friend QDataStream &operator>>(QDataStream &file,vg &vg)
    {
        file >> vg.title >> vg.platform >> vg.flagmp >> vg.flagcrossplatform >> vg.flagsplitcreen >> vg.otherspecs >> vg.flagavailability >> vg.price >> vg.id;
        return file;
    }
};

#endif
