// DatabaseManager.h
#pragma once
#include <string>
#include <vector>
#include <sqlite3.h>
#include "Component.h"     // struct Component { int id; std::string name, type, location; int quantity; std::string purchase_date; };

class DatabaseManager {
public:
    // Constructor: recibe la ruta del archivo .db
    explicit DatabaseManager(const std::string& dbPath);
    
    // Destructor: cierra la conexión automáticamente
    ~DatabaseManager();

    // Abre la base de datos y crea la tabla si no existe
    bool open();

    // Cierra la conexión (se llama automáticamente al destruir)
    void close();

    // Operaciones CRUD puras (solo SQL, sin lógica de negocio)
    bool insertComponent(const Component& comp);
    bool updateComponent(const Component& comp);
    bool deleteComponent(int id);
    std::vector<Component> getAllComponents();
    Component* getComponentById(int id);                        // devuelve puntero o nullptr
    std::vector<Component> search(const std::string& sqlQuery); // para búsquedas avanzadas

private:
    std::string dbPath;
    sqlite3* db = nullptr;   // puntero a la conexión SQLite

    // Función auxiliar para ejecutar queries sin resultado
    bool execute(const std::string& sql);
    
    // Callback estático obligatorio de SQLite (necesario para SELECT)
    static int callback(void* data, int argc, char** argv, char** colName);
};