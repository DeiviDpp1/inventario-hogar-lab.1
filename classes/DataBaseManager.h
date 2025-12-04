#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "Component.h"

class DatabaseManager {
public:
    // Constructor: recibe la ruta del archivo .db
    explicit DatabaseManager(const QString& dbPath);

    // Destructor
    ~DatabaseManager();

    // Abre la base de datos y crea la tabla si no existe
    bool open();

    // Cierra la conexión
    void close();

    // Operaciones CRUD
    bool insertComponent(const Component& comp);
    bool updateComponent(const Component& comp);
    bool deleteComponent(int id);

    QVector<Component> getAllComponents();
    Component getComponentById(int id);  // Cambié a devolver por valor
    QVector<Component> searchComponents(const QString& condition = "");

private:
    QString dbPath;
    QSqlDatabase db;

    // Crea la tabla si no existe
    bool createTable();
};

#endif // DATABASEMANAGER_H

