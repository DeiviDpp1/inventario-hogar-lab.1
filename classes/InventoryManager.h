// InventoryManager.h
#include "DatabaseManager.h"
#include "Component.h"
#include <vector>
#include <string>

class InventoryManager {
public:
    // Recibe una referencia al DatabaseManager (composición)
    explicit InventoryManager(DatabaseManager& dbManager);

    // Lógica de NEGOCIO (aquí está toda la inteligencia)
    bool addComponent(const std::string& name, 
                      const std::string& type, 
                      int quantity, 
                      const std::string& location,
                      const std::string& purchaseDate = "");

    bool removeComponent(int id);
    bool updateQuantity(int id, int newQuantity);         // permite cantidades negativas para ajustes
    bool moveComponent(int id, const std::string& newLocation);

    // Búsquedas con lógica real
    std::vector<Component> searchByName(const std::string& partialName);
    std::vector<Component> searchByType(const std::string& type);
    std::vector<Component> getLowStock(int threshold = 10) const;
    std::vector<Component> getComponentsByLocation(const std::string& location);

    // Reportes y estadísticas
    void exportToCSV(const std::string& filename) const;
    void exportToPDF(const std::string& filename) const;   // usando alguna librería sencilla
    int getTotalItems() const;
    int getTotalTypes() const;

private:
    DatabaseManager& dbManager;   // NO es dueño, solo usa

    // Validaciones de negocio
    bool isValidQuantity(int qty) const { return qty >= 0; }
    bool isValidName(const std::string& name) const { return !name.empty() && name.length() <= 100; }
};