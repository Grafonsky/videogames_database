#ifndef TITLEVALIDATOR_H
#define TITLEVALIDATOR_H

#include <QValidator>

// ОБЪЯВЛЕНИЕ И ИНИЦИАЛИЗАЦИЯ ВАЛИДАТОРА
class titlevalidator : public QValidator
{
    Q_OBJECT

public:
    titlevalidator(QObject *parent);
    ~titlevalidator();
    QValidator::State validate(QString & input, int & pos) const;

private:

};

#endif // TITLEVALIDATOR_H
