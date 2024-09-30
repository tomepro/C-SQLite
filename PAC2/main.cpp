#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *errMsg = nullptr;

    // Abrir (o crear) una base de datos
    if (sqlite3_open("test.db", &db)) {
        std::cerr << "No se puede abrir la base de datos" << std::endl;
        return 1;
    }

    // Crear una tabla
    const char *sqlCreateTable = 
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL);";
    
    if (sqlite3_exec(db, sqlCreateTable, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Error al crear la tabla: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Insertar datos
    const char *sqlInsert = "INSERT INTO users (name) VALUES ('Alice');";
    if (sqlite3_exec(db, sqlInsert, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Error al insertar: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Consultar datos
    const char *sqlSelect = "SELECT * FROM users;";
    sqlite3_exec(db, sqlSelect, [](void*, int argc, char **argv, char **) {
        for (int i = 0; i < argc; i++) {
            std::cout << (argv[i] ? argv[i] : "NULL") << " ";
        }
        std::cout << std::endl;
        return 0;
    }, nullptr, &errMsg);

    if (errMsg) {
        std::cerr << "Error en la consulta: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    
     // Esperar a que el usuario presione Enter antes de cerrar
    std::cout << "Presiona Enter para cerrar..." << std::endl;
    std::cin.ignore();  // Ignorar el salto de línea anterior
    std::cin.get();     // Esperar a que el usuario presione Enter


    // Cerrar la base de datos
    sqlite3_close(db);
    return 0;
}