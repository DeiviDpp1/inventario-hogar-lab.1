#ifndef COMPONENT_H
#define COMPONENT_H

//Clase Articulo
#include <string>

class Articulo{
public:

// Dejamos los Atributos en publico ya que es encesario modificar informacion sobre los mismos frecuentemente, especificamente la cantidad
// de articulos disponibles en inventario.

    int id_articulo;
    std::string name;
    std::string type;
    int quantity;
    std::string location;
    std::string purchase_date;

    Articulo(){}

    Articulo(int id_articulo, const std::string& name, const std::string& type, int quantity, const std::string& location, const std::string& purchase_date)
        : id_articulo(id), name(name), type(type), quantity(quantity), location(location), purchase_date(purchase_date)

// Los string al ser limitantes no cambiantes se les añade & para evitar esstos cambios de memoria innecesarios

};