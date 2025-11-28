#include <QApplication>
#include "ui/MainWindow.h"
#include "core/DatabaseManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    DatabaseManager db("inventory.db");
    if (!db.connect()) return 1;
    db.initSchema("data/schema.sql");

    MainWindow w(&db);
    w.setWindowTitle("Gestor de Inventario");
    w.resize(900, 600);
    w.show();
    return app.exec();
}
