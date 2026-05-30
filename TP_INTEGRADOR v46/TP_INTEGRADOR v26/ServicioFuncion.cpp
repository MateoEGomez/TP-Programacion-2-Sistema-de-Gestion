
#include <iostream>
#include "ServicioFuncion.h"
#include <cstdio>
#include "rlutil.h"
#include "Funcion.h"
#include <iomanip>

using namespace std;


bool ServicioFuncion::crearFuncion(Funcion fun)
{

    FILE* archivo = fopen("Funcion.dat", "ab");
    if (archivo == nullptr) return false;

    fwrite(&fun, sizeof(Funcion), 1, archivo);

    fclose(archivo);
    return true;
}


int ServicioFuncion::contarFuncion()
{
    FILE* archivo = fopen("Funcion.dat", "rb");
    if (archivo == nullptr) return 0;

    Funcion fun;
    int cont = 0;

    while ( fread(&fun, sizeof(Funcion), 1, archivo) == 1 )
    {
        cont++;
    }

    fclose(archivo);
    return cont;

}



Funcion ServicioFuncion::buscarPosicionFuncion(int pos)
{
    Funcion fun;

    FILE* archivoFuncion = fopen("Funcion.dat", "rb");
    if (archivoFuncion == nullptr) return fun;

    fseek(archivoFuncion, sizeof(Funcion) * pos, SEEK_SET);

    fread(&fun, sizeof(Funcion), 1, archivoFuncion);

    fclose(archivoFuncion);
    return fun;
}



 int ServicioFuncion::buscarPosicionPorId(int id)
{
    FILE* archivo = fopen("Funcion.dat", "rb");
    if (archivo == nullptr) return -1;

    Funcion fun;
    int pos = 0;

    while (fread(&fun, sizeof(Funcion), 1, archivo) == 1)
    {
        if (fun.GetIdFuncion() == id)
        {
            fclose(archivo);
            return pos;
        }
        pos++;
    }

    fclose(archivo);
    return -1;
}




bool ServicioFuncion::listarFunciones(int estado)
{
    int cantFunciones = contarFuncion();
    int cont = 0;

    if (cantFunciones == 0)
    {
        cout << "No se encontraron registros" << endl;
        return false;
    }

    Funcion fun;
    cout<<endl;

    for (int i = 0; i < cantFunciones; i++)
    {
        fun = buscarPosicionFuncion(i);

        if (fun.GetActiva() == estado)
        {
            cont++;

            cout<<endl;
            cout << "ID Funcion: "   << fun.GetIdFuncion()   << endl;
            cout << "ID Pelicula: "  << fun.GetIdPelicula()  << endl;
            cout << "ID Sala: "      << fun.GetIdSala()      << endl;
            cout << "Cantidad de asientos: " << fun.GetcantidadAsientos() << endl;

            cout << "Fecha: ";
            fun.GetFecha().mostrarFecha();
            cout << endl;
            cout << "Hora: ";

            fun.GetFecha().mostrarHora();
            cout << endl;
            cout << "Estado: " << (fun.GetActiva() ? "Activo" : "Inactivo") << endl;


            int libres = 0;


            int* asientos = fun.GetAsientosDisponibles();


            for (int h = 0; h < fun.GetcantidadAsientos(); h++)
            {
                if (asientos[h] == 1) libres++;
            }

            cout << "Asientos disponibles: " << libres << endl;

            cout << "[PANTALLA]" << endl << endl;

            rlutil::setColor(4);
            cout<< "X";
            rlutil::setColor(15);
            cout<<":ocupado  ";
            rlutil::setColor(2);
            cout<< "0";
            rlutil::setColor(15);
            cout<<":disponible";

            cout << endl << endl;
            setfill(' ');
            int aux=0;

            cout<<endl;

            for (int j = 0; j < fun.GetcantidadAsientos(); j++)
            {

                if(asientos[j]==0)
                {
                    cout<<"[";
                    rlutil::setColor(4);
                    cout<< "X";
                    rlutil::setColor(15);
                    cout<<"]";

                }
                else if(asientos[j]==1)
                {
                    cout<<"[";
                    rlutil::setColor(2);
                    cout<< j+1;
                    rlutil::setColor(15);
                    cout<<"]";

                }

            }
            cout << endl;


            cout << "---------------------------" << endl;
        }
    }

    if (cont < 1)
    {
           cout<<endl<<endl<<endl;
            cout<< "no hay registros para mostrar!!!"<< endl;
            rlutil::msleep(2000);
            return false;
    }

    return true;
}


bool ServicioFuncion::bajaFuncion(int id)
{
    Funcion fun;
    int tam = contarFuncion();
    int posi = -1;

    if(tam == 0){
        cout<<"no se encontraron registros"<< endl;
        rlutil::msleep(1500);
        return false;
    }

    for(int i=0; i < tam; i++)
    {
        fun = buscarPosicionFuncion(i);

        if (fun.GetIdFuncion() == id)
        {
            posi = i;
            break;
        }
    }

    // Si no lo encontró
    if(posi == -1){
        cout << "no se encontro funcion" << endl;
        rlutil::msleep(1500);
        return false;
    }

    // Marcar inactivo
    fun.SetActiva(false);

    // Guardar cambios
    return modificarFuncion(posi, fun);
}




bool ServicioFuncion::reactivarFuncion(int id)
{
    Funcion fun;
    int tam = contarFuncion();
    int posi = -1;

    if (tam == 0){
        cout << "no se encontraron registros" << endl;
        return false;
    }

    for(int i = 0; i < tam; i++)
    {
        fun = buscarPosicionFuncion(i);

        if (fun.GetIdFuncion() == id)
        {
            posi = i;
            break;
        }
    }

    if(posi == -1){
        cout << "no se encontro funcion" << endl;
        rlutil::msleep(1500);
        return false;
    }

    fun.SetActiva(true);

    return modificarFuncion(posi, fun);
}




Funcion ServicioFuncion::buscarPorId(int idFuncion)
{
    int cantRegistros = contarFuncion();
    int posi=-1;
    Funcion fun;

    if (cantRegistros == 0)
    {
        cout<<"no se encontraron registros"<< endl;
        return Funcion();
    }

    for (int i = 0; i < cantRegistros; i++)
    {
        fun = buscarPosicionFuncion(i);

        if (fun.GetIdFuncion() == idFuncion)
        {
            posi=i;
            break;
        }
    }


    if(posi==-1){
        return Funcion();
    }

    return buscarPosicionFuncion(posi);
}



bool ServicioFuncion::modificarFuncion(int posi, Funcion funModi)
{

    FILE* archivoFuncion = fopen("Funcion.dat", "rb+");

    if ( archivoFuncion == nullptr) return false;

    fseek(archivoFuncion,sizeof(Funcion)*posi,SEEK_SET);

    bool aux= (fwrite(&funModi, sizeof(Funcion),1,archivoFuncion)==1);

    fclose(archivoFuncion);
    return aux;

};


bool ServicioFuncion::comprobarFechaHora(Funcion fNueva){

    int cant = contarFuncion();

    for(int i = 0; i < cant; i++)
    {
        Funcion f = buscarPosicionFuncion(i);

        if(f.GetIdSala() == fNueva.GetIdSala() &&
           f.GetFecha().GetDia() == fNueva.GetFecha().GetDia() &&
           f.GetFecha().GetMes() == fNueva.GetFecha().GetMes() &&
           f.GetFecha().GetAnio() == fNueva.GetFecha().GetAnio() &&
           f.GetFecha().GetHora() == fNueva.GetFecha().GetHora() &&
           f.GetFecha().GetMinuto() == fNueva.GetFecha().GetMinuto())
        {
            return true; // ocupado
        }
    }

    return false; //libre

    }



bool ServicioFuncion::salaUsada(int idSala){

    int cant= contarFuncion() ;


       if(cant==0){
            return false;
       }

        for(int i=0; i<cant; i++){

            Funcion fun= buscarPosicionFuncion(i);

            if(fun.GetIdSala()== idSala){

                return true;
            }

        }




        return false;


}









