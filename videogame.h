#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "ui_videogame.h"
#include <QMessageBox>
#include "titlevalidator.h"
#include "game.h"
#include "gamedatabase.h"

// ОБЪЯВЛЕНИЕ И ИНИЦИАЛИЗАЦИЯ КЛАССА videogame
class videogame : public QMainWindow
{
    Q_OBJECT
    QString platform[4]; //объявление и инициализация переменной с платформой
    bool logaddchar; //объявление и инициализация флага записи доп описания
    QString str; //объявление и инициализация строки
    QString strprice; //объявление и инициализация перевода цены в строку


public:
    QString filename; //объявление и инициализация названия файла
    bool answersave;
    int N; //объявление и инициализация позиции в листе
    class gamedatabase database; //объявление и инициализация бд
    explicit videogame(QWidget *parent = nullptr, QFlag flags = 0);
    ~videogame();
    unsigned int id; //объявление и инициализация идентификатора

private:
// ФУНКЦИЯ ВЫВОДА НА ЭКРАН ДАННЫХ ОБ ОБЪЕКТЕ
    void outputgame(int M);

// ФУНКЦИЯ ВЫВОДА ОБЪЕКТА НА ЭКРАН
    void outputstr(int M);

// ФУНКЦИЯ ОЧИСТКИ ОБЪЕКТА
    void cleargame(int M);

// ФУНКЦИЯ СОРТИРОВКИ
    friend int sort(int Z,class vg mass[100],int sizemass);
    bool asksave();
    void closeEvent(QCloseEvent *event);

    Ui::videogameClass ui;
private slots:
    void sltitle(); //слот сохранения названия
    void slx1(); //слот платформы x1
    void slps4(); //слот платформы ps4
    void slpc(); //слот платформы pc
    void slmp(); //слот флага мп
    void slcrossplatform(); //слот флага кроссплатформы
    void slsplitscreen(); //слот флага спллитскрина
    void slotherspecs(); //слот сохранения доп описания
    void slavailability(); //слот флага наличия
    void slprice(); //слот сохранения цены
    void slcreate(); //слот создать
    void slremove(); //слот удалить
    void slgames(); //слот переключения между позициями в листе
    void slcreatefile(); //слот создания файла с объектами
    void slopenfile(); //слот открытия файла с объектами
    void slsavefile(); //слот сохранения файла с объектами
    void slsaveasfile(); //слот создания файла с объектами в кач-ве нового файла
};

#endif
