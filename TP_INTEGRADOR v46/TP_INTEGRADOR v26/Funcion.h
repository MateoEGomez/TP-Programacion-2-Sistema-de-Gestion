#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "Fecha.h"

class Funcion {

public:

Funcion ();
Funcion(int idFuncion, int idPelicula, int idSala, bool activa);
static const char* horarios[5];
static const int MAX_BUTACAS= 50;
void reservarAsientos(int* asientos, int cantidad);
int contadorAsientosDisponibles();
void reiniciarVasientosDisponibles(int bustacas);
bool asientoDisponible(int numeroAsiento);

//Getters
    int GetIdFuncion();
    int GetIdPelicula();
    int GetIdSala();
    bool GetActiva();
    int GetcantidadAsientos();
    int* GetAsientosDisponibles();

    Fecha GetFecha();

// Setters
    void SetIdFuncion(int funcion);
    void SetIdPelicula(int peli);
    void SetIdSala(int sala);
    void SetActiva(bool val);

    void SetCantidadAsientos(int cant);
    void setAsientosDisponibles(int cantidad);
    void SetFecha(Fecha);


private:
    int _idFuncion;
    int _idSala;
    int _idPelicula;
    int _cantidadAsientos; // trae cantidad de butacas de la sala
    Fecha _fecha;
    bool _activa;

   ///int* _asientosDisponibles;

    int _asientosdisponibles[MAX_BUTACAS];

       ///0 false
       ///  -1  no existe

       /// 1  disponible

};
