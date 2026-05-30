
#include <iostream>
#include "MisFunciones.h"
#include "rlutil.h"
#include <limits>
#include "Cliente.h"
#include "ServicioCliente.h"
#include "ServicioEmpleado.h"
#include "ServicioPelicula.h"
#include "ServicioSala.h"
#include "ServicioVenta.h"
#include "ServicioFuncion.h"

using namespace std;




void resultadoAccion(bool respuesta)
{

    if(respuesta)
    {
        rlutil::locate(5,26);
        cout<<" Se guardo correctamente!!! "<<endl;
        rlutil::msleep(1500);
    }
    else
    {
        rlutil::locate(5,26);
        cout<<" No se a pudido guardar intente nuevamente!! "<< endl;
        rlutil::msleep(1500);
    }



}




void marcoPantalla(int x, int y)
{
    rlutil::cls();
    int ancho=x;
    int alto=y;
    rlutil::setColor(4);
///esquina sup izq
    rlutil::locate(3,4);
    cout<<(char)201<<endl;

///lateral izq
    for(int i=0; i<alto; i++)
    {
        rlutil::locate(3,5+i);
        cout<<(char)186<<endl;

    }
///esquina inf izq

    rlutil::locate(3,alto+5);
    cout<<(char)200<<endl;



/// lineas superior inferior
    for(int i=0; i<ancho; i++)
    {

        rlutil::locate(4+i,4);
        cout<<(char)205<<endl;

        rlutil::locate(4+i,alto+5);
        cout<<(char)205<<endl;
        rlutil::msleep(4) ;

    }

    /// esquina inf derecha
    rlutil::locate(ancho+4,alto +5);
    cout<<(char)188<<endl;
    /// esquiina sup derecha
    rlutil::locate(ancho+4,4);
    cout<<(char)187<<endl;


    for(int i=0; i<alto; i++)
    {
        rlutil::locate(ancho+4,5+i);
        cout<<(char)186<<endl;
    }

}



void limpiarBuffer()
{
    cin.clear() ;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

}



///  genera id a partir del ultimo del archivo
int generacionId(int tipo){
    int cantidad;


    if(tipo==1)/// cliente
    {
        ServicioCliente servicli;

        cantidad = servicli.contadorClientes();

        if(cantidad ==0)
        {
            return 1;
        }

        Cliente cli = servicli.buscarPosicionCliente(cantidad-1);

        return cli.getidPersona()+1;

    }
    else

        if (tipo==2)/// empleado
        {
            ServicioEmpleado serviEmple;

            cantidad = serviEmple.contadorEmpleados();

            if(cantidad ==0)
            {
                return 1;
            }

            Empleado emple = serviEmple.buscarPosicionEmpleado(cantidad-1);

            return emple.getidPersona()+1;

        }
        else

            if(tipo==3) ///PELICULA
            {
                servicioPelicula servipeli;

                cantidad = servipeli.contadorPeliculas();

                if(cantidad ==0)
                {
                    return 1;
                }

                Pelicula peli = servipeli.buscarPosicionPelicula(cantidad-1);

                return peli.GetIdPelicula()+1;

            }
            else if(tipo== 4)   ///SALA
            {
                ServicioSala serviSal;

                cantidad = serviSal.contadorSalas();

                if(cantidad ==0)
                {
                    return 1;
                }

                Sala sal = serviSal.buscarPosicionSala(cantidad-1);

                return sal.GetIdSala()+1;

            }
            else if(tipo==5)      ///FUNCION
            {
                ServicioFuncion serviFun;

                cantidad = serviFun.contarFuncion();

                if(cantidad ==0)
                {
                    return 1;
                }

                Funcion fun = serviFun.buscarPosicionFuncion(cantidad-1);

                return fun.GetIdFuncion()+1;

            }
            else if(tipo==6)   ///VENTA
            {
                ServicioVenta serviVen;

                cantidad = serviVen.contadorVentas();

                if(cantidad ==0)
                {
                    return 1;
                }

                Venta ven = serviVen.buscarPosicionVenta(cantidad-1);

                return ven.GetIdVenta()+1;

            }



}



/// generacion de legajo
int generacionLegajo(){
    ServicioEmpleado serviEmple;

    int cantidad= serviEmple.contadorEmpleados();

    if(cantidad ==0){
        return 1501;
        }

     Empleado emple= serviEmple.buscarPosicionEmpleado(cantidad -1);

     return emple.get_numeroLegajo()+1;

}




/// validador de numeros
bool validarNumeros(const char* numero) {
    int len = strlen(numero);
    if (len == 0) return false;

    for (int i = 0; i < len; i++) {
        if (!isdigit(numero[i])) return false;
    }

    return true;
}

/// validar texto
bool validarTexto(const char* texto) {
    int len = strlen(texto);
    if (len == 0) return false;

    for (int i = 0; i < len; i++) {

        char c = texto[i];

        if (c == ' ') continue;

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z')) {
            continue;
        }

        return false; // NO es letra ni espacio
    }

    return true;
}


/// validar fecha

bool validaFecha(int dia, int mes, int anio ){

    if(anio >1900 && anio<2100) return true;

    int diaMes=0;

    switch (mes){
        case 1: case 3: case 5: case 7: case 8: case 10:
           diaMes =31;
        break;

        case 4: case 6: case 9:
            diaMes=30;
        break;
        case 2:
            diaMes=28;
        break;

        default:
           return false;
        break;
    }

    if(dia<1 || dia > diaMes) return false;

    return true;

}

/// validar hora
bool validarHora(int hora, int minuto){

    if(hora>=0 && hora<24){

        if(minuto>=0 && minuto<60){
            return true;
        }
    }
        return false;
 }


///



void convertidorHorario(const char* texto, int &hora, int &minuto)
{

    hora   = (texto[0] - '0') * 10 + (texto[1] - '0');
    minuto = (texto[3] - '0') * 10 + (texto[4] - '0');
}
