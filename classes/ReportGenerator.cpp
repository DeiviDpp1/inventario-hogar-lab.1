#include "ReportGenerator.h"
#include <QFile>
#include <QTextStream>

bool ReportManager::generateCSV(const QVector<Component>& list, const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    QTextStream out(&file);

    out << "ID,Name,Type,Quantity,Min,Max,Location,PurchaseDate\n";

    for (const Component& c : list) {
        out << c.id_component << ","
            << c.name << ","
            << c.type << ","
            << c.quantity << ","
            << c.MinQuantity << ","
            << c.MaxQuantity << ","
            << c.location << ","
            << c.purchase_date << "\n";
    }

    file.close();
    return true;
}
