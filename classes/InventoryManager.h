#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <QVector>
#include "Component.h"
#include "DatabaseManager.h"

class InventoryManager {
public:
    explicit InventoryManager(DatabaseManager* db);

    // --- Operaciones básicas ---
    bool addComponent(const Component& comp);
    bool removeComponent(int id);
    bool updateComponent(const Component& comp);

    // --- Manejo de inventario ---
    bool increaseQuantity(int id, int amount);
    bool decreaseQuantity(int id, int amount);
    bool setQuantity(int id, int newQuantity);

    QVector<Component> getAll();
    Component getById(int id);

private:
    DatabaseManager* db;  // dependencia
};

#endif // INVENTORYMANAGER_H
