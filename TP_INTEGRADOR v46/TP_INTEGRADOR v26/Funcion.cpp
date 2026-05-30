#include <iostream>
#include <cstring>
#include "Funcion.h"
using namespace std;


const char* Funcion::horarios[5]={"12:00","14:30","17:00","19:30","22:00"} ;

Funcion::Funcion()
{
    _idFuncion = 0;
    _idSala = 0;
    _idPelicula = 0;
    _cantidadAsientos = 0;
    _activa = false;
    for (int i = 0; i < MAX_BUTACAS; i++) {
    _asientosdisponibles[i] = -1;
    }
}


//Getters
int Funcion::GetIdFuncion()
{
    return _idFuncion;
}
int Funcion::GetIdPelicula()
{
    return _idPelicula;
}
int Funcion::GetIdSala()
{
    return _idSala;
}
bool Funcion::GetActiva()
{
    return _activa;
}

int Funcion::GetcantidadAsientos()
{
    return _cantidadAsientos;
}




Fecha Funcion::GetFecha(){
    return _fecha;
}


//Setters
void Funcion::SetIdFuncion(int idFuncion)
{
    _idFuncion = idFuncion;
}

void Funcion::SetIdPelicula(int idPelicula)
{
    _idPelicula = idPelicula;
}

void Funcion::SetIdSala(int idSala)
{
    _idSala = idSala;
}


void Funcion::SetActiva(bool activa)
{
    _activa = activa;
}

void Funcion::SetCantidadAsientos(int cantAsientos)
{
    _cantidadAsientos= cantAsientos;
}


void Funcion::SetFecha(Fecha fecha){
        _fecha = fecha;

}



int* Funcion::GetAsientosDisponibles() {
    return _asientosdisponibles;
}


 void Funcion::setAsientosDisponibles(int cantidad){

      for(int i=0; i< cantidad; i++){

        _asientosdisponibles[i]=1;
      }
 }


void Funcion::reservarAsientos(int* asientos, int cantidad){


     for(int i=0;i<cantidad;i++){

        int asientoActual= asientos[i]-1;

        if (asientoActual >= 0 && asientoActual < _cantidadAsientos){

           _asientosdisponibles[asientoActual]=0;

         }


    }

    cout<<"reservado correcto";
}




int Funcion::contadorAsientosDisponibles(){

    int cant=0;

    for (int i=0; i< GetcantidadAsientos(); i++){

         if( _asientosdisponibles[i]==1) cant++;
    }

     return cant;
}

void Funcion::reiniciarVasientosDisponibles(int butacas){

     for (int i = 0; i < MAX_BUTACAS; i++) {
    _asientosdisponibles[i] = -1;
    }

    for(int i=0; i< butacas; i++){

        _asientosdisponibles[i]=1;
      }

}

bool Funcion::asientoDisponible(int numeroAsiento){
     int num=   numeroAsiento-1;

    if(numeroAsiento<0 || numeroAsiento>_cantidadAsientos){

            return false ;
     }
    bool resp=   _asientosdisponibles[num]==1;

    return   resp;

}
