#include "InventoryManager.h"

InventoryManager::InventoryManager(DatabaseManager* db)
    : db(db)
{
}

// ---------------------- CRUD --------------------------

bool InventoryManager::addComponent(const Component &comp) {
    return db->insertComponent(comp);
}

bool InventoryManager::removeComponent(int id) {
    return db->deleteComponent(id);
}

bool InventoryManager::updateComponent(const Component &comp) {
    return db->updateComponent(comp);
}

// ----------------- Manejo de cantidades ----------------

bool InventoryManager::increaseQuantity(int id, int amount) {
    Component c = db->getComponentById(id);
    if (c.id_component == 0) return false; // no existe

    c.quantity += amount;
    return db->updateComponent(c);
}

bool InventoryManager::decreaseQuantity(int id, int amount) {
    Component c = db->getComponentById(id);
    if (c.id_component == 0) return false;

    if (c.quantity - amount < 0)
        return false; // no permitir inventario negativo

    c.quantity -= amount;
    return db->updateComponent(c);
}

bool InventoryManager::setQuantity(int id, int newQuantity) {
    Component c = db->getComponentById(id);
    if (c.id_component == 0) return false;

    c.quantity = newQuantity;
    return db->updateComponent(c);
}

// ---------------------- Lecturas -----------------------

QVector<Component> InventoryManager::getAll() {
    return db->getAllComponents();
}

Component InventoryManager::getById(int id) {
    return db->getComponentById(id);
}
