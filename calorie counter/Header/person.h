#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class person : public QObject
{
    Q_OBJECT
public:
    explicit person(QObject *parent = nullptr);
    double weight()const {return m_weight;}
    void setWeight(double weight);

signals:
    void weightChange();
private:
    double m_weight=0.0;

};

#endif // PERSON_H
