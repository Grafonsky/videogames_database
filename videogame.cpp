#include "videogame.h"
#include "QTextCodec"

videogame::videogame(QWidget *parent, QFlag flags) :
    QMainWindow(parent, flags),
    ui(*new Ui::videogameClass)
{
    ui.setupUi(this);
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    QValidator *ev=new titlevalidator(this);

    ui.title->setValidator(ev); //подключение валидатора к строке с названием
    ui.gbgame->setEnabled(false); //деактивация блока с данными
    ui.remove->setEnabled(false); //деактивация кнопки удалить
    ui.price->setSuffix(" ₽"); //добавление знака валюты в виджет с ценой
    ui.price->setMaximum(99999); //установка максимального значения цены

    connect(ui.title,    SIGNAL(editingFinished ()), this, SLOT(sltitle())); //виджет названия + слот sltitle
    connect(ui.rbtnX1,    SIGNAL(clicked()), this, SLOT(slx1())); //виджет радиокнопки x1 + слот slx1
    connect(ui.rbtnPS4,    SIGNAL(clicked()), this, SLOT(slps4())); //виджет радиокнопки ps4 + слот slps4
    connect(ui.rbtnPC,    SIGNAL(clicked()), this, SLOT(slpc())); //виджет радиокнопки pc + слот slpc
    connect(ui.flagmp,    SIGNAL(clicked()), this, SLOT(slmp())); //виджет флага мп + слот slmp
    connect(ui.flagcrossplatform,    SIGNAL(clicked()), this, SLOT(slcrossplatform())); //виджет флага кроссплатформы  + слот slcrossplatform
    connect(ui.flagsplit,    SIGNAL(clicked()), this, SLOT(slsplitscreen())); //виджет флага сплитскрина + слот slsplitscreen
    connect(ui.otherspecs,    SIGNAL(textChanged ()), this, SLOT(slotherspecs())); //виджет доп описания + слот slotherspecs
    connect(ui.flagavailability,    SIGNAL(clicked()), this, SLOT(slavailability())); //виджет флага наличия + слот slavailability
    connect(ui.price,    SIGNAL(editingFinished ()), this, SLOT(slprice())); //виджет цены + слот slprice
    connect(ui.List,    SIGNAL(currentRowChanged(int)), this, SLOT(slgames())); //изменение тек позиции в листе  + слот slgames
    connect(ui.add,     SIGNAL(clicked()), this, SLOT(slcreate())); //виджет кнопки создать + слот slcreate
    connect(ui.remove,     SIGNAL(clicked()), this, SLOT(slremove())); //виджет кнопки удалить + слот slremove
    connect(ui.create, SIGNAL(triggered()), this, SLOT(slcreatefile())); //виджет выпадающего меню>>создать + слот slcreatefile
    connect(ui.open, SIGNAL(triggered()), this, SLOT(slopenfile())); //виджет выпадающего меню>>открыть + слот slopenfile
    connect(ui.save, SIGNAL(triggered()), this, SLOT(slsavefile())); //виджет выпадающего меню>>сохранить + слот slsavefile
    connect(ui.saveas, SIGNAL(triggered()), this, SLOT(slsaveasfile())); //виджет выпадающего меню>>сохранить как  + слот slsaveasfile

    logaddchar=false; //запис доп описания разрешена

// ЗАПОЛНЕНИЕ МАССИВА С ПЛАТФОРМАМИ
    platform[0].append(""); //нет
    platform[1].append("X1"); //x1
    platform[2].append("PS4"); //ps4
    platform[3].append("PC"); //pc

    unsigned int id; //объявление и инициализация идентификатора
    answersave=false;
}

// ДЕСТРУКТОР
videogame::~videogame()
{

}

// СЛОТ НАЗВАНИЯ
void videogame::sltitle()
{
    outputstr(N); //выводим строку в листе
    N=ui.List->currentRow(); //установка текущей позиции
    id=ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    int pos = database.update(id,QString("title"),ui.title->displayText()); //обновление в бд
    outputstr(N); //выводим измененую строку в листе
    outputgame(pos); //выводим данные об объекте в правую часть программы
    ui.List->setCurrentRow(pos); //установка выделенного объекта в листе
}

// СЛОТ ПЛАТФОРМЫ X1
void videogame::slx1()
{
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    int pos=database.update(id,QString("platform"),QString("1")); //обновление в бд
    ui.List->setCurrentRow(pos); //установка выделенного объекта в листе
    outputstr(N); //выводим строку в листе
    outputgame(ui.List->currentRow()); //выводим данные об объекте в правую часть программы
}

// СЛОТ ПЛАТФОРМЫ PS4
void videogame::slps4()
{
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    int pos=database.update(id,QString("platform"),QString("2")); //обновление в бд
    ui.List->setCurrentRow(pos); //установка выделенного объекта в листе
    outputstr(N); //выводим строку в листе
    outputgame(ui.List->currentRow()); //выводим данные об объекте в правую часть программы
}

// СЛОТ ПЛАТФОРМЫ PC
void videogame::slpc()
{
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    int pos=database.update(id,QString("platform"),QString("3")); //обновление в бд
    ui.List->setCurrentRow(pos); //установка выделенного объекта в листе
    outputstr(N); //выводим строку в листе
    outputgame(ui.List->currentRow()); //выводим данные об объекте в правую часть программы
}

// СЛОТ ФЛАГА МП
void videogame::slmp()
{
    outputstr(N); //выводим строку в листе
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    if(ui.flagmp->isChecked()==true) //проверка - если флаг установлен
        int pos=database.update(id,QString("mp"),QString("true")); //да - обновление в бд
    else
        int pos=database.update(id,QString("mp"),QString("false")); //нет - обновление в бд
}

// СЛОТ ФЛАГА КРОССПЛАТФОРМЫ
void videogame::slcrossplatform()
{
    outputstr(N); //выводим строку в листе
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    if(ui.flagcrossplatform->isChecked()==true) //проверка - если флаг установлен
        int pos=database.update(id,QString("crossplatform"),QString("true")); //да - обновление в бд
    else
        int pos=database.update(id,QString("crossplatform"),QString("false")); //нет - обновление в бд
}

// СЛОТ ФЛАГА СПЛИТСКРИНА
void videogame::slsplitscreen()
{
    outputstr(N); //выводим строку в листе
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    if(ui.flagsplit->isChecked()==true) //проверка - если флаг установлен
        int pos=database.update(id,QString("splitcreen"),QString("true")); //да - обновление в бд
    else
        int pos=database.update(id,QString("splitcreen"),QString("false")); //нет - обновление в бд
}

// СЛОТ ДОП ОПИСАНИЯ
void videogame::slotherspecs()
{
    if(ui.List->currentRow()>=0) //проверка - если запись не пустая
        N=ui.List->currentRow();//установка текущей позиции
    if(logaddchar==false)//проверка - если считывание разрешено
    {
        N=ui.List->currentRow(); //установка текущей позиции
        int pos=database.update(id,QString("otherspecs"),ui.otherspecs->toPlainText()); //обновление в бд
    }
    logaddchar=false; //разрешаем запись
}

// СЛОТ ФЛАГА НАЛИЧИЯ
void videogame::slavailability()
{
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    int pos;
    if(ui.flagavailability->isChecked()==true) //проверка - если флаг установлен
    {
        ui.price->setEnabled(true); //делаем виджет цены активным
        pos=database.update(id,QString("availability"),QString("true")); //обновление в бд
    }
    else
    {
        ui.price->setEnabled(false); //делаем виджет цены неактивным
        pos=database.update(id,QString("availability"),QString("false")); //обновление в бд
    }
    outputstr(pos); //выводим измененую строку в листе
}

// СЛОТ ЦЕНЫ
void videogame::slprice()
{
    outputstr(N); //выводим строку в листе
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    int pos=database.update(id,QString("price"),QString::number(ui.price->value())); //обновление в бд
    outputstr(N); //выводим измененую строку в листе
    outputgame(pos); //выводим данные об объекте в правую часть программы
    ui.List->setCurrentRow(pos); //установка выделенного объекта в листе
}

// СЛОТ КНОПКИ СОЗДАТЬ
void videogame::slcreate()
{
    N=ui.List->count(); //определение числа объектов
    ui.gbgame->setEnabled(true); //активация блока с данными
    ui.flagavailability->setChecked(false); //обнуление значения с флага наличия
    ui.price->setEnabled(false); //деактивация виджета с ценой
    ui.remove->setEnabled(true); //активация кнопки удалить
    str.clear(); //очищение строки вывода
    class vg help; //присоединение класса vg
    ui.List-> addItem(str); //добавление объекта в лист
    id=database.append(help).id; //соотнесение идентификатора
    ui.List->item(N)->setData(Qt::UserRole,id); //запись идентификатора
    ui.List->setCurrentRow(0); //установка выделенного объекта в листе
    outputstr(N); //вывод строки
    outputgame(0); //выводим данные об объекте в правую часть программы
}

// СЛОТ КНОПКИ УДАЛИТЬ
void videogame::slremove()
{
    N=ui.List->currentRow(); //установка текущей позиции
    id = ui.List->item(N)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
    int  thispos=ui.List->currentRow(); //определение индекса объекта
    int all=ui.List->count(); //общее кол-во записей
    database.remove(id); //удаление идентификатора
    delete ui.List->item(N); //удаление объекта из листа
    if(database.list().size()==0) //проверка - если лист пуст
        database.clear(); //бд очищается
    N=ui.List->currentRow(); //установка текущей позиции
    if(N<0) //проверка - если объектов нет
    {
        N=0; //индекс равен 0
        ui.gbgame->setEnabled(false); //деактивация блока с данными
        ui.remove->setEnabled(false); //деактивация кнопки удалить
    }
}

// СЛОТ ИЗМЕНЕНИЯ ТЕКУЩЕЙ ПОЗИЦИИ
void videogame::slgames()
{
    outputgame(ui.List->currentRow()); //выводим данные об объекте в правую часть программы
    N=ui.List->currentRow(); //установка текущей позиции
}

// ВЫВОД ДАННЫХ ОБ ОБЪЕКТЕ
void videogame::outputgame(int M)
{
    if(M!=-1) //проверка - если выделен текущий объект
    {
        id = ui.List->item(M)->data(Qt::UserRole).toUInt(); //присваивание идентификатора
        class vg help=*database.record(id); //соединение класса vg с бд
        logaddchar=true;
        ui.title->setText(help.title); //соотнесение названия
        if(help.platform!=0) //проверка - соотнесение платформы
        {
            if(help.platform==1) //x1
            {
                ui.rbtnX1->setChecked (true); //радиокнопка нажата
            }
            if(help.platform==2) //ps4
            {
                ui.rbtnPS4->setChecked (true); //радиокнопка нажата
            }
            if(help.platform==3) //pc
            {
                ui.rbtnPC->setChecked (true); //радиокнопка нажата
            }
        }
        ui.flagmp->setChecked(help.flagmp); //соотнесение флага мп
        ui.flagcrossplatform->setChecked(help.flagcrossplatform); //соотнесение флага кроссплатформы
        ui.flagsplit->setChecked(help.flagsplitcreen); //соотнесение флага сплитскрина
        ui.otherspecs->setPlainText(help.otherspecs); //соотнесение доп описания
        ui.flagavailability->setChecked(help.flagavailability); //соотнесение флага наличия
        if(help.flagavailability==false) //проверка - если игра не имеется в наличии
        {
            ui.price->setEnabled(false); //деактивация виджета цены
            ui.price->setValue(help.price); //соотнесение цены
        }
        else //имеется
        {
            ui.price->setEnabled(true); //активация виджета цены
            ui.price->setValue(help.price); //соотнесение цены
        }
    }
    else
    {
        ui.title->setText(QString("")); //вывод нулевого названия
        ui.flagmp->setChecked(false); //вывод нулевого флага
        ui.flagcrossplatform->setChecked(false); //вывод нулевого флага
        ui.flagsplit->setChecked(false); //вывод нулевого флага
        ui.otherspecs->setPlainText(QString("")); //вывод нулевого описания
        ui.flagavailability->setChecked(false); //вывод нулевого флага
        ui.price->setEnabled(false); //вывод нулевой цены
    }
}

// ВЫВОД СТРОКИ
void videogame::outputstr(int M)
{
    QList<unsigned int> helplist=database.list(); //объявление и инициализация листа
    QList<unsigned int>::const_iterator pos=helplist.begin(); //объявление и инициализация итератора
    if(helplist.size()!=0)
        for(int i=0;i<helplist.size();i++)
        {
            id=*pos;
            ui.List->item(i)->setData(Qt::UserRole,id);
            str.clear();
            strprice.clear();
            if(database.record(id)->platform!=0)
                strprice.setNum(database.record(id)->price);
            str.append(database.record(id)->title).append("\t").append(platform[database.record(id)->platform]).append("\t").append(strprice + " ₽"); //компонуем строку
            ui.List->item(i)->setText(str); //добавляем объект
            pos++;
        }
    M=ui.List->currentRow();
}

// СЛОТ СОЗДАНИЯ ФАЙЛА С ДАННЫМИ
void videogame::slcreatefile()
{
    if(database.havechange==true)
    {
        answersave=asksave();
    }
    answersave=false;
    database.havechange=false;
    filename.clear();
    database.clear();
    ui.List->clear();
    ui.price->setEnabled(false);
    ui.gbgame->setEnabled(false);
    ui.remove->setEnabled(false);
    slsaveasfile();
}

// СЛОТ ОТКРЫТИЯ ФАЙЛА С ДАННЫМИ
void videogame::slopenfile()
{
    if(database.havechange==true)
    {
        answersave=asksave();
    }
    answersave=false;
    database.havechange=false;
    QVector <struct rcd> vector;
    vector.clear();
    int i=0;
    filename = QFileDialog::getOpenFileName(this, QString("Открыть"),QString(), QString("База данных видеоигр (*.gamedb);;Все файлы(*.*)")); //
    database.load(filename);
    ui.List->clear();
    vector=database.records();
    while(i<vector.size())
    {
        id=vector.value(i).id;
        str.clear();
        strprice.clear();
        if(vector.value(i).platform!=0)
            strprice.setNum(vector.value(i).price);
        str.append(vector.value(i).title).append("\t").append(platform[vector.value(i).platform]).append("\t").append(strprice);//компонуем строку
        ui.List-> addItem(str);
        ui.List->item(i)->setData(Qt::UserRole,id);
        i++;
    }
    if(vector.size()==0)
    {
        ui.gbgame->setEnabled(false);
        ui.remove->setEnabled(false);
    }
    else
    {
        ui.gbgame->setEnabled(true);
        ui.remove->setEnabled(true);
    }
    ui.List->setCurrentRow(0);
    answersave=false;
    database.havechange=false;
}

// СЛОТ СОХРАНЕНИЯ ФАЙЛА С ДАННЫМИ
void videogame::slsavefile()
{
    if(filename.isEmpty())
        filename =  QFileDialog::getSaveFileName(this, QString("Сохранить"), QString(),QString("Файлы (*.gamedb)"));
    database.save(filename);
    answersave=false;
    database.havechange=false;
}

// СЛОТ СОХРАНЕНИЯ ФАЙЛА С ДАННЫМИ В КАЧ-ВЕ НОВОГО ФАЙЛА
void videogame::slsaveasfile()
{
    filename =  QFileDialog::getSaveFileName(this, QString("Сохранить как"), QString(),QString("Файлы (*.gamedb)"));
    database.save(filename);
    database.havechange=false;
}

// ВОПРОС О СОХРАНЕНИИ ФАЙЛА
bool videogame::asksave()
{
    QMessageBox box;
    box.setText(QString("Сохранить изменения в базе данных?"));
    box.setIcon (QMessageBox::Question );
    QPushButton *yes=box.addButton(QString("Да"),QMessageBox::YesRole);
    QPushButton *no=box.addButton(QString("Нет"),QMessageBox::NoRole);
    box.exec();
    if(box.clickedButton()==yes) // Если нажали "да"
        {
            slsavefile();
            return true;
        }
    else
        return false;
}

// КЛОЗ-ИВЕНТ В СЛУЧАЕ ВНЕСЕНИЯ ИЗМЕНЕНИЙ
void videogame::closeEvent(QCloseEvent *event)
{
    if(database.havechange==true)
    {
        answersave=asksave();
    }
    answersave=false;
    database.havechange=false;
}
