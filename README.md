# inventario-hogar-lab.1
Gestor de inventario para componentes electrónicos en hogar o laboratorio, usando C++/Qt5 y SQLite.
# Gestor de Inventario para Hogar o Laboratorio

Este proyecto es una aplicación de escritorio desarrollada en C++ con Qt5 y SQLite, orientada a dispositivos de bajo consumo como Raspberry Pi. Permite gestionar componentes electrónicos o dispositivos del hogar/laboratorio.

## Características
- Registro de componentes: nombre, tipo, cantidad, ubicación, fecha de adquisición.
- Búsqueda y filtrado por texto.
- Exportación de inventario a CSV y PDF.
- Interfaz gráfica con Qt5.
- Base de datos local en SQLite.

## Requisitos
- Sistema operativo Linux (Ubuntu, Debian, Raspberry Pi OS)
- Qt5 (`qtbase5-dev`, `qttools5-dev-tools`)
- SQLite (`libqt5sql5-sqlite`)
- Git y compilador (`build-essential`)

## Instalación
```bash
sudo apt update
sudo apt install -y build-essential qtbase5-dev qttools5-dev-tools libqt5sql5 libqt5printsupport5 libqt5sql5-sqlite git
