#include <cstring>
#include "rlutil.h"
#include "Sala.h"
#include "ServicioVenta.h"
#include "ServicioCliente.h"
#include "ServicioEmpleado.h"
#include "ServicioFuncion.h"
#include "ServicioSala.h"
#include "ServicioPelicula.h"
#include "Venta.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Pelicula.h"
#include <cstdio>

using namespace std;


bool ServicioVenta::crearVenta(Venta v)
{
    v.SetIdVenta(contadorVentas() + 1);
    FILE* pVentas = fopen("Ventas.dat", "ab");
    if (pVentas == nullptr) return false;

    fwrite(&v, sizeof(Venta), 1, pVentas);

    fclose(pVentas);
    return true;
}


int ServicioVenta::contadorVentas()
{
    FILE* pVentas = fopen("Ventas.dat", "rb");
    if (pVentas == nullptr) return 0;

    fseek(pVentas, 0, SEEK_END);
    long fileSize = ftell(pVentas);
    fclose(pVentas);

    if (sizeof(Venta) == 0) return 0;

    return (int)(fileSize / sizeof(Venta));
}


Venta ServicioVenta::buscarPosicionVenta(int pos)
{
    Venta ven;
    FILE* archivoVentas = fopen("Ventas.dat", "rb");
    if (archivoVentas == nullptr) return ven;

    fseek(archivoVentas, pos * sizeof(Venta), SEEK_SET);
    fread(&ven, sizeof(Venta), 1, archivoVentas);

    fclose(archivoVentas);
    return ven;
}


bool ServicioVenta::listarVentas()
{
     system("cls");
    int cantVentas = contadorVentas();
    int cont = 0;

    if (cantVentas == 0)
    {
        cout << "No se encontraron registros" << endl;
        return false;
    }

    ServicioCliente serviCli;
    servicioPelicula serviPeli;
    ServicioSala serviSala;
    ServicioFuncion serviFun;
    ServicioEmpleado serviemple;
    Venta v;
    cout << endl;

    for (int i = 0; i < cantVentas; i++)
    {

        v = buscarPosicionVenta(i);
        cont++;


        Cliente cli = serviCli.buscarClientePorId(v.GetIdCliente());
        Empleado emple =serviemple.buscarEmpleadoPorId(v.GetIdEmpleado());
        Funcion fun = serviFun.buscarPosicionFuncion(v.GetIdFuncion());
        Sala sala = serviSala.buscarSala(fun.GetIdSala());
        Pelicula peli = serviPeli.buscarPeliculaPorId(fun.GetIdPelicula());

        cout << "---------------------------------------" << endl;
        cout << "VENTA N: " << v.GetIdVenta() << endl;

        cout << "CLIENTE: " << cli.getnombre() << " " << cli.getapellido() << " (ID: " << v.GetIdCliente() << ")" << endl;

        cout << "EMPLEADO: " << emple.getnombre() << " " << emple.getapellido() << " (ID: " << v.GetIdEmpleado() << ")" << endl;

        cout << "FUNCION ID: " << v.GetIdFuncion() << endl;
        cout << "PELICULA: " << peli.GetNombrePelicula() << endl;
        cout << "SALA: " << sala.GetNombreSala() << " (" << sala.GetTipoSala() << ")" << endl;

        cout << "FECHA/HORA: ";
        v.Getfecha().mostrarFecha();
        cout << " ";
        v.Getfecha().mostrarHora();
        cout << endl;

        cout << "ENTRADAS: " << v.GetCantidadEntradas() << endl;
        cout << "PRECIO UNITARIO (Base): $" << v.GetPrecio() << endl;


        cout << "TOTAL FINAL: $" << v.GetPrecioFinal() << endl;


        if (v.GetCantidadEntradas() > 0)
        {
            cout << "ASIENTOS: ";
            for (int j = 0; j < v.GetCantidadEntradas(); j++)
            {
                cout << "[" << v.GetNumeroAsiento()[j] << "] ";
            }
            cout << endl;
        }
        cout << "---------------------------------------" << endl;
    }


    if (cont == 0)
    {
        cout << endl << endl << endl;
        cout << "no hay registros para mostrar!!!" << endl;
    }

    return true;
}


Venta ServicioVenta::buscarVentaPorId(int idVenta)
{
    int cantidadRegistros = contadorVentas();

    for (int i = 0; i < cantidadRegistros; i++)
    {
        Venta v = buscarPosicionVenta(i);

        if (v.GetIdVenta() == idVenta)
        {
            return v;
        }
    }
    return Venta();
}




bool ServicioVenta::modificarVenta(Venta nuevaVenta, int pos)
{
    FILE* archivo = fopen("Ventas.dat", "rb+");
    if (archivo == nullptr) return false;

    fseek(archivo, pos * sizeof(Venta), SEEK_SET);


    bool ok = (fwrite(&nuevaVenta, sizeof(Venta), 1, archivo) == 1);

    fclose(archivo);
    return ok;
}




float ServicioVenta::PrecioVentaFinal(Venta venta)
{


    float baseUnitario = venta.GetPrecio();


    ServicioFuncion serviFun;
    int idFuncion = venta.GetIdFuncion();


    Funcion f = serviFun.buscarPorId(idFuncion);


    ServicioSala serviSala;
    int idSala= f.GetIdSala();
    Sala sala = serviSala.buscarSala(idSala);


    float multiplicadorSala = 1.0f;
    const char* tipoSala = sala.GetTipoSala();


    if (strcmp(tipoSala, "3D") == 0)
    {
        multiplicadorSala = 1.2f;
    }
    else if (strcmp(tipoSala, "4D") == 0)
    {
        multiplicadorSala = 1.5f;
    }
    // Si no coincide con "3D" o "4D", se mantiene en 1.0f (Estándar/Default).

    float precioFinalUnitario = baseUnitario * multiplicadorSala;
    return precioFinalUnitario * venta.GetCantidadEntradas();
}



float ServicioVenta::recaudacionMensual(int mes, int anio)
{

    float precioMensual=0.0f;
    Venta ven;

    int tam=  contadorVentas();

    for(int i=0; i<tam; i++)
    {
        ven= buscarPosicionVenta(i);

        if(ven.Getfecha().GetMes()== mes && ven.Getfecha().GetAnio()== anio)
        {
            precioMensual += ven.GetPrecioFinal();
        }
    }

    return precioMensual;
}


float* ServicioVenta::recaudacionAnual(int anio)
{

    float meses[12]= {};
    int mes=0;
    int tam= contadorVentas();


        for(int i=0; i< tam; i++)
        {

            Venta ven= buscarPosicionVenta(i);

              if(ven.Getfecha().GetAnio()== anio)
            {
                mes= ven.Getfecha().GetMes();

                meses[mes-1]+= ven.GetPrecioFinal();

            }


        }

    return meses;
}



float ServicioVenta::recaudacionXempleado(int id, int mes, int aniob)
{
    ServicioEmpleado serviEmple;
    Empleado emple= serviEmple.buscarEmpleadoPorId(id);

     int anio =aniob;
     int tamEmple= serviEmple.contadorEmpleados();
     float ventaMes=0.0f;

    int tamVenta= contadorVentas();


    for(int i=0; i< tamVenta; i++)
    {

     Venta ven= buscarPosicionVenta(i);

         if(ven.GetIdEmpleado()==id && ven.Getfecha().GetMes()== mes && ven.Getfecha().GetAnio()==anio){
                    ventaMes+= ven.GetPrecioFinal();
        }
    }

    return ventaMes;
}





float ServicioVenta::recaudacionPorFuncion(int idFuncion){
    int totalregistros = contadorVentas();

    if (totalregistros==0)return 0;

    int cantidadFiltrada=0;

    for (int i=0 ; i<totalregistros;i++){
        Venta v = buscarPosicionVenta(i);
        if(v.GetIdVenta()> 0 && v.GetIdFuncion()==idFuncion){
            cantidadFiltrada++;
        }
    }

    if (cantidadFiltrada== 0) return 0;

    Venta* listaVentas = new Venta[cantidadFiltrada];
    if (listaVentas==nullptr)return 0;
    int carga=0;
    for (int i=0;i<totalregistros;i++){
        Venta v = buscarPosicionVenta(i);
         if(v.GetIdVenta()> 0 && v.GetIdFuncion()==idFuncion){
            listaVentas[carga] = v;
            carga++;
        }

    }
    float totalrecaudado = 0.0;
    for (int i = 0; i<cantidadFiltrada;i++){
        totalrecaudado += PrecioVentaFinal(listaVentas[i]);
    }
    delete []listaVentas;
    return totalrecaudado;
}
