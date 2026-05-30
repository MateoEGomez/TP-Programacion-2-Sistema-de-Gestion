#include <iostream>
#include <cstring>
#include "Venta.h"
#include "rlutil.h"
#include "Pelicula.h"
#include "Sala.h"
using namespace std;

Venta::Venta() {
    _idventa=-1;
    _idCliente=0;
    _idFuncion=0;
    _cantidadEntradas=0;
    _precio=1500;
    for (int i = 0; i < MAX_ASIENTOS; i++) {
        _numeroAsiento[i] = -1;
    }
}


void Venta::SetIdVenta(int idVenta) {
    _idventa = idVenta;
}

int Venta::GetIdVenta(){
    return _idventa;
}


void Venta::SetIdCliente(int idCliente){
    _idCliente = idCliente;
}
int Venta::GetIdCliente(){
    return _idCliente;
}


int Venta::GetIdFuncion(){
    return _idFuncion;
}
void Venta::SetIdFuncion(int idfuncion) {
        _idFuncion = idfuncion;
}


void Venta::SetCantidadEntradas(int cantidadEntradas) {

        _cantidadEntradas = cantidadEntradas;

}

int Venta::GetCantidadEntradas() {
    return _cantidadEntradas;
}

float Venta::GetPrecio(){
    return _precio;
}

void Venta::SetPrecio(float precio){
    _precio = precio;
}


void Venta::SetNumeroAsiento(int cantidadEntradas,int* asientos ){

    for (int i = 0; i < cantidadEntradas; i++) {
        _numeroAsiento[i] = asientos[i];
    }
}


int* Venta::GetNumeroAsiento(){
    return _numeroAsiento;
}


 int Venta::GetIdEmpleado(){
    return _idEmpleado;
 }

 void Venta::SetIdEmpleado(int idEmple){

        _idEmpleado = idEmple;

 }

 void Venta::Setfecha(Fecha fe){
    _fecha = fe;
 }

 Fecha Venta::Getfecha(){
    return _fecha;
 }


void Venta::SetPrecioFinal(float precioFin){

  _precioFinal = precioFin;
}

float Venta::GetPrecioFinal(){
    return _precioFinal;
}
