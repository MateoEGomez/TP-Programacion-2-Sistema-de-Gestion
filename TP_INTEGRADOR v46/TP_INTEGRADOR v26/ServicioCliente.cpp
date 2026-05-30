
#include <iostream>
#include <cstring>
#include "ServicioCliente.h"
#include "rlutil.h"


using namespace std;


ServicioCliente :: ServicioCliente ()
{

}

///crear/guardar cliente
bool ServicioCliente::guardarCliente(Cliente cli)
{
    FILE* archivoCliente = fopen ("Cliente.dat", "ab");
    if(archivoCliente != nullptr)
    {
        fwrite(&cli, sizeof(Cliente),1,archivoCliente);
        fclose (archivoCliente);
        return true;
    }
    else
    {
        return false;
    }

}


/// contador de registros Cliente.dat
int ServicioCliente::contadorClientes()
{

    FILE* archivoCliente = fopen ("Cliente.dat", "rb");

    if(archivoCliente != nullptr)
    {
        fseek(archivoCliente,0,SEEK_END);
        int cantidadDeRegistros = ftell(archivoCliente)/ sizeof(Cliente);
        fclose(archivoCliente);
        return cantidadDeRegistros;
    }
    else
    {
        return 0;
    }
}


/// buscar por posicion leer

Cliente ServicioCliente:: buscarPosicionCliente(int posicion)
{

    FILE* archivoCliente = fopen ("Cliente.dat", "rb");

    if(archivoCliente == nullptr)
    {
        return Cliente();
    }

    Cliente cli;

    fseek(archivoCliente, sizeof(cli)* posicion, SEEK_SET),
          fread(&cli, sizeof(Cliente),1, archivoCliente);
    fclose(archivoCliente);
    return cli;

}


/// modificar cliente
bool  ServicioCliente:: modificarCliente(Cliente cli, int posicion)
{

    FILE* archivoCliente = fopen ("Cliente.dat", "rb+");

    if(archivoCliente == nullptr)
    {
        return false;
    }

    fseek(archivoCliente, sizeof(Cliente)* posicion, SEEK_SET);
    bool ok = (fwrite(&cli, sizeof(Cliente), 1, archivoCliente)==1);
    fclose(archivoCliente);
    return ok;
}


 // baja logica cliente
bool ServicioCliente:: bajaCliente(int id)
{

    Cliente cli;

    int cantRegistros= contadorClientes();
    int posi=-1;

    /// se comprueba que hayan registros cargados
     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return false;
     }

    for(int i=0; i< cantRegistros; i++)
    {

        cli= buscarPosicionCliente(i);

        if(cli.getidPersona() == id)
        {
            posi= i;
            // comprobar si cierra el for
            break;
        }

    }

    if (posi == -1) {
    cout << "Cliente no encontrado." << endl;
    return false;
    }

    cli.setactivo(false);

    if (modificarCliente(cli, posi))
    {
        return true;
    }

    return false;

}



bool ServicioCliente::reactivarCliente(int id)
{

    Cliente cli;

    int cantRegistros= contadorClientes();
    int posi=-1;

    /// se comprueba que hayan registros cargados
     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return false;
     }

    for(int i=0; i< cantRegistros; i++)
    {
        cli= buscarPosicionCliente(i);

        if(cli.getidPersona() == id)
        {
            posi= i;
            // comprobar si cierra el for
            break;
        }

    }

    if (posi == -1) {
    cout << "Cliente no encontrado." << endl;
    return false;
    }

    cli.setactivo(true);

    if (modificarCliente(cli, posi))
    {
        return true;
    }

    return false;

}



bool ServicioCliente:: listarClientes(int activ){

    int cantRegistros= contadorClientes();
    int cont=0;

    if ( cantRegistros == 0){
        cout<< "no hay registros cargados"<< endl;
        return false;
     }

    Cliente cli;


    cout<<endl;

    for (int i=0; i < cantRegistros; i++){

           cli= buscarPosicionCliente(i);

           if(cli.getactivo()==activ){
            cont++;

           cout<<" id: "<< cli.getidPersona()<< endl;
           cout<<" dni: "<< cli.getdniPersona()<< endl;
           cout<<" email: "<< cli.get_email()<< endl;
           cout<<" nombre: "<< cli.getnombre()<< endl;
           cout<<" apellido: "<< cli.getapellido()<< endl;
           cout<<" es empleado : "<< (cli.getEsEmpleado()?"Si":"No")<< endl;
           cout<<" estado: "<< (cli.getactivo()?"Activo":"Inactivo")<< endl;

           cout<<"---------------------"<< endl;

           }
    }

            if(cont<1){

                cout<<endl<<endl<<endl;
                cout<< "no hay registros para mostrar!!!"<< endl;
                 rlutil::msleep(2000);
                 return false;
            }


          return true;


}



Cliente ServicioCliente::buscarClientePorId(int id){


    Cliente cli;

    int cantRegistros= contadorClientes();
    int posi=-1;


     if ( cantRegistros == 0){
        cout<<"no se encontraron registros"<< endl;
        return Cliente();
     }

    for(int i=0; i< cantRegistros; i++)
    {

        cli= buscarPosicionCliente(i);

        if(cli.getidPersona() == id)
        {
            posi= i;

            break;
        }

    }

    if (posi == -1) {
    return Cliente();
    }


    return buscarPosicionCliente(posi);

}

/// buscar por dni
bool ServicioCliente::buscarClientePorDni(int dni){

    Cliente cli;
    int cantRegistros= contadorClientes();


     if ( cantRegistros == 0){
        return false;
     }

    for(int i=0; i< cantRegistros; i++)
    {

        cli= buscarPosicionCliente(i);

        if(cli.getdniPersona() == dni)
        {
            return true;
        }

    }


    return false;

}

Cliente ServicioCliente::traerClientePorDni(int dni){

    Cliente cli;
    int cantRegistros= contadorClientes();


     if ( cantRegistros == 0){
        return Cliente();
     }

    for(int i=0; i< cantRegistros; i++)
    {

        cli= buscarPosicionCliente(i);

        if(cli.getdniPersona() == dni)
        {
            return cli;
        }

    }


    return Cliente();

}
