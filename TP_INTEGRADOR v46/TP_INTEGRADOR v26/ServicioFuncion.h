
#pragma once
#include "Funcion.h"

class ServicioFuncion{




public:
    bool crearFuncion(Funcion fun);
    int contarFuncion();
    Funcion buscarPosicionFuncion(int pos);
    int buscarPosicionPorId(int id);
    bool listarFunciones(int activo);
    bool bajaFuncion(int id);
    bool reactivarFuncion(int id);


    Funcion buscarPorId(int idFuncion);

    bool modificarFuncion(int pos, Funcion funModi);


    bool comprobarFechaHora(Funcion funNueva);

    bool salaUsada(int idSala);


};
