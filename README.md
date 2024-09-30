# Proyecto de C++ con SQLite

Este proyecto es una aplicación simple en C++ que utiliza SQLite para gestionar una base de datos de usuarios. Permite abrir o crear una base de datos, definir una tabla de usuarios, insertar un registro y consultar todos los usuarios existentes. Es un ejemplo básico que demuestra cómo interactuar con una base de datos utilizando SQLite en C++.

## Explicación del Código

Este proyecto en C++ utiliza SQLite para gestionar una base de datos de usuarios. A continuación, se describe brevemente el funcionamiento del código:

1. **Inclusión de Bibliotecas**: Se incluyen las bibliotecas necesarias para la entrada/salida (`<iostream>`) y para trabajar con SQLite (`<sqlite3.h>`).

2. **Apertura de la Base de Datos**: Se intenta abrir (o crear) una base de datos llamada `test.db`. Si no se puede abrir, se muestra un mensaje de error y el programa finaliza.

3. **Creación de la Tabla**: Se define una consulta SQL para crear una tabla llamada `users`, que contiene un campo `id` (clave primaria autoincremental) y un campo `name`.

4. **Inserción de Datos**: Se inserta un registro en la tabla con el nombre "Alice".

5. **Consulta de Datos**: Se realiza una consulta para seleccionar todos los registros de la tabla `users`, y se muestran los resultados en la consola.

6. **Manejo de Errores**: Se incluyen controles de error para la apertura de la base de datos, la creación de la tabla, la inserción de datos y la consulta.

7. **Esperar al Usuario**: Antes de cerrar la base de datos, el programa solicita al usuario que presione Enter para finalizar, lo que permite revisar los resultados.

8. **Cierre de la Base de Datos**: Finalmente, se cierra la conexión a la base de datos.
