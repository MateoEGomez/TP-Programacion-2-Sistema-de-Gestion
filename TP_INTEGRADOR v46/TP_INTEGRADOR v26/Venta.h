#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Cliente.h"
#include "Fecha.h"



class Venta {


public:
    static const int MAX_ASIENTOS = 10;
    Venta();

    int GetIdVenta() ;
    int GetIdCliente();
    int GetIdFuncion();
    int GetCantidadEntradas();
    float GetPrecio() ;
    int* GetNumeroAsiento();
    int GetIdEmpleado();
    Fecha Getfecha();
    float GetPrecioFinal();

    void SetIdVenta(int idventa);
    void SetIdCliente(int idCliente);
    void SetIdFuncion(int idFuncion);
    void SetCantidadEntradas(int cantidadEntradas);
    void SetPrecio(float precio);
    void SetIdEmpleado(int idEmple);

    void SetNumeroAsiento(int cantidadEntradas, int* asientos);

    void Setfecha(Fecha);
    void SetPrecioFinal(float precioFin);

private:
    int _idventa;
    int _idCliente;
    int _idFuncion;
    int _cantidadEntradas;
    int _idEmpleado;

    int _numeroAsiento[MAX_ASIENTOS];

    float _precio;
    float _precioFinal;
    Fecha _fecha ;
};

