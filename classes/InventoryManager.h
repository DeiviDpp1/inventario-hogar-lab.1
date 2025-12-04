#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Component.h"
#include <Qvector>
#include <QString>
#include "DataBaseManager.h"

class InventoryManager {

public:
    explicit InventoryManager(DatabaseManager& dbManager);

    bool addComponenet(int id_component, const QString& name, const QString type, int quantity, int MinQuantity, int MaxQuantity, const QString location, const QString& purchase_date);
    bool removeComponent_byId(int id_component);
    bool removeComponent_byName(const QString& name);

    bool updateQuantity_byId(int id_component, int quantity);
    bool updateQuantity_byName(const QString& name, int quantity);


private:
    DatabaseManager& dbmanager;


};

#endif // INVENTORYMANAGER_H
