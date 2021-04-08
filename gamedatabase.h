#include <QVector>
#include <QFile>
#include <QFileDialog>
#include "game.h"

// ОБЪЯВЛЕНИЕ И ИНИЦИАЛИЗАЦИЯ СТРУКТУРЫ ЗАПИСИ В СТРОКУ
struct rcd
{
    QString title; //объявление и инициализация строки с названием
    int platform; //объявление и инициализация переменной с платформой
    int price; //объявление и инициализация переменной с ценой
    int id; //объявление и инициализация переменной с идентификатором
};

// ОБЪЯВЛЕНИЕ И ИНИЦИАЛИЗАЦИЯ КЛАССА С БД
class gamedatabase
{

private:
    QHash<unsigned int, class vg> bd; //объявление и инициализация бд с помощью qhash
    unsigned int maxid; //объявление и инициализация переменной maxid
    QList<unsigned int> sortedids; //объявление и инициализация отсортированного списка
public:
    bool havechange;
    vg append(class vg &record)
    {
        if(bd.empty()==true)
            maxid=0; //если БД пуста, id нового объекта будет равно 0
        record.id=++maxid; //id ув на 1 при добавлении нового объекта
        bd[record.id]=record; //запись id в БД
        bd[maxid].title=""; //обнуление названия
        bd[maxid].platform=0; //обнуление платформы
        bd[maxid].flagmp=false; //обнуление флага мп
        bd[maxid].flagcrossplatform=false; //обнуление флага кроссплатформы
        bd[maxid].flagsplitcreen=false; //обнуление флага сплитскрина
        bd[maxid].otherspecs=""; //обнуление доп описания
        bd[maxid].flagavailability=false; //обнуление флага наличия
        bd[maxid].price=0; //обнуление цены
        sortedids.append(maxid); //добавление объекта в отсортированный список
        havechange=true; //объявление и инициализация переменной для клоз-ивента
        int pos=sorted(maxid);
        return record;
    }

// ФУНКЦИЯ УДАЛЕНИЯ ОБЪЕКТА
    void remove(unsigned int id)
    {
        bool good=sortedids.removeOne(id);
        int ok=bd.remove(id);
        havechange=true;
    }

// ФУНКЦИЯ ОБНОВЛЕНИЯ ДАННЫХ ОБ ОБЪЕКТЕ
    int update(unsigned int id,const QString & name, const QString & value)
    {
        int posrec=0; //обнуление текущей позиции
        QList<unsigned int>::iterator pos=sortedids.begin(); //объявление и инициализация итератора отсортированного списка
        while(pos!=sortedids.end()&&*pos!=id)
        {
            posrec++;
            pos++;
        }
        //обновление названия
        if(name=="title")
        {
            bd[id].title.clear();
            bd[id].title.append(value);
            posrec=sorted(id);
        }
        //обновление платформы
        if(name=="platform")
        {
            bd[id].platform=value.toInt();
            posrec=sorted(id);
        }
        //обновление флага о наличии мп
        if(name=="mp")
        {
            if(value=="true")
                bd[id].flagmp=true;
            else
                bd[id].flagmp=false;
        }
        //обновление флага о наличии кроссплатформы
        if(name=="crossplatform")
        {
            if(value=="true")
                bd[id].flagcrossplatform=true;
            else
                bd[id].flagcrossplatform=false;
        }
        //обновление флага о наличии сплитскрина
        if(name=="splitcreen")
        {
            if(value=="true")
                bd[id].flagsplitcreen=true;
            else
                bd[id].flagsplitcreen=false;
        }
        //обновление доп описания
        if(name=="otherspecs")
        {
            bd[id].otherspecs=value;
        }
        //обновление флага о наличии
        if(name=="availability")
        {
            if(value=="true")
                bd[id].flagavailability=true;
            else
                bd[id].flagavailability=false;
        }
        //обновление цены
        if(name=="price")
        {
            bd[id].price=value.toInt();
            posrec=sorted(id);
        }
        havechange=true;
    return posrec;
    }
// ЗАПИСЬ
    const class vg *record(unsigned int id)
    {
        return &bd[id];
    }
// ВОЗВРАТ ЗНАЧЕНИЯ ИЗ ОТСОРТИРОВАННОГО СПИСКА
    const QList<unsigned int> list()
    {
        return sortedids;
    }
// СОРТИРОВКА
    int sorted(unsigned int id)
    {
        int Z=0;
        int i=0;
        QList<unsigned int>::iterator pos=sortedids.begin();
        while(pos!=sortedids.end()&&*pos!=id)
        {
            Z++;
            pos++;
        }

        int ret=Z;
        bool stop=false;//условие выхода из цикла
        if(Z!=0)//если объект не первый
        {
            i=0;
            pos=sortedids.begin();
            while(pos!=sortedids.end()&&stop!=true)//перебираем объекты
            {
                if(true==bd[*pos]>bd[id]&&i-1<Z) //если объект нужно поставить выше данного
                {
                    stop=true;
                    sortedids.move(Z,i);
                    ret=i;
                    i++;
                }
                if(true==bd[*pos]<bd[id]&&i-1>=Z) //если объект нужно поставить ниже данного
                {
                    pos=sortedids.end();
                    pos--;
                    for(int k=sortedids.size();k>i&&stop!=true;k--)
                    {
                        if(true==bd[*pos]<bd[id])
                        {
                            stop=true;
                            sortedids.move(Z,k-1);
                            ret=k-1;
                            i++;
                        }
                        pos--;
                    }
                }
                pos++;
                i++;
            }
        }
        else
            if(sortedids.size()!=1) //если нет ни одного объекта
            {
                pos=sortedids.begin();
                for(i=sortedids.size();i>=1&&stop!=true;i--)
                {
                    if(true==bd[*pos]<bd[id])
                    {
                        stop=true;
                        sortedids.move(Z,i);
                        ret=i;
                        i++;
                    }
                    pos++;
                }
            }
        return ret;
    }

//СТРОКА В ЛИСТЕ
    const QVector<struct rcd> records()
    {
        struct rcd string;
        QVector <struct rcd> vector;
        QList<unsigned int>::iterator pos=sortedids.begin();
        while(pos!=sortedids.end())
        {
            string.title=bd[*pos].title;
            string.platform=bd[*pos].platform;
            string.price=bd[*pos].price;
            string.id=bd[*pos].id;
            vector.append(string);
            pos++;
        }
        return vector;
    }

//СОХРАНЕНИЕ
    void save(QString filename)
    {
        QFile file(filename);
        if(file.open(QIODevice::WriteOnly))
        {
            QDataStream output(&file);
            output << bd<<maxid<<sortedids;
        }
    }

//ОТКРЫТЬ
    void load(QString filename)
    {
        if(QFile::exists(filename))
        {
            QFile file(filename);
            if(file.open(QIODevice::ReadOnly))
            {
                QDataStream input(&file);
                input >>bd>>maxid>>sortedids;
            }
        }
    }

//ОЧИСТИТЬ
    void clear()
    {
        bd.clear();
        sortedids.clear();
    }
};
