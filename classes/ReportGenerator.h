#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
#include <vector>
#include "Component.h"  a// Asumiendo que Component es tu struct (o renómbralo a Articulo si es necesario)
#include "InventoryManager.h"

#include <QPrinter>  // Para PDF con Qt
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>  // Para renderizar texto en PDF

class ReportGenerator {
public:
    explicit ReportGenerator(InventoryManager& invManager);

    // Genera un reporte CSV con todos los componentes o una lista filtrada
    bool generateCSV(const std::string& filename, const std::vector<Component>& components = {}) const;

    // Genera un reporte PDF con todos los componentes o una lista filtrada
    bool generatePDF(const std::string& filename, const std::vector<Component>& components = {}) const;

private:
    InventoryManager& inventoryManager;

    // Helper para obtener todos los componentes si no se proporciona una lista
    std::vector<Component> getComponentsIfEmpty(const std::vector<Component>& components) const;
};

#endif // REPORTGENERATOR_H