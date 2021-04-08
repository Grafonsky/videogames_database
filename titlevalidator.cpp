#include "titlevalidator.h"

titlevalidator::titlevalidator(QObject *parent)
    : QValidator(parent)
{

}

titlevalidator::~titlevalidator()
{

}

QValidator::State titlevalidator::validate( QString & input, int & pos) const
{
    QString string=QString("йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890 :_"); //допустимые символы в строке названия
    if(input.isEmpty()==false)
    {
        if(input.at(0).isLetter ()==false) //проверка
        {
            return QValidator::Invalid; //возврат недействительной строки

        }
        if(pos>0&&string.contains(input.at(pos-1))==false) //проверка
        {
            return QValidator::Invalid; //возврат недействительной строки
        }
    }
    return QValidator::Acceptable; //возврат действительной строки
}
