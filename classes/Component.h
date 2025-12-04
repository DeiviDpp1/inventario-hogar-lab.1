#ifndef COMPONENT_H
#define COMPONENT_H

#include <Qstring>
class Component{
public:

    int id_component;
    QString name;
    QString type;
    int quantity;
    QString location;
    QString purchase_date;

    Component(){}
    Component(int id_articulo, const QString& name, const QString type, int quantity, const QString location, const QString& purchase_date);
};

#endif // COMPONENT_H
