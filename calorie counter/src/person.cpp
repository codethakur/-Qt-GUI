#include "person.h"

person::person(QObject *parent)
    : QObject{parent}
{}

void person::setWeight(double weight)
{
    if(m_weight!=weight){
        m_weight = weight;
        emit weightChange();
    }
}
