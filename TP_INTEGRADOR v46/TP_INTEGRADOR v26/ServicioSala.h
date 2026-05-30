#pragma once
#include <string>
#include "Sala.h"

class ServicioSala{

public:
    ServicioSala();

    bool crearSala(Sala s);

    int contadorSalas ();

    bool listarSalas (int activo);

    Sala buscarPosicionSala (int pos);

    Sala buscarSala(int idsala);

    bool modificarSala(Sala s , int pos);

    bool eliminarSala(int id);

    bool reactivarSala(int id);

    Sala buscarSalaPorNombre(const char* nombreSala);


};

