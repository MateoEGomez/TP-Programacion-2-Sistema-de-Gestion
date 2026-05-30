#include <iostream>
#include "Pantallas.h"
#include "rlutil.h"
#include <limits>
#include "Fecha.h"
#include "Cliente.h"
#include "Empleado.h"
#include "MisFunciones.h"
#include "ServicioEmpleado.h"
#include "ServicioPelicula.h"
#include "ServicioFuncion.h"
#include "ServicioCliente.h"
#include "ServicioVenta.h"
#include "Pelicula.h"
#include "Sala.h"
#include "ServicioSala.h"
#include "cstring"

using namespace std;

Pantallas:: Pantallas()
{

}



void Pantallas::avisoError()
{
    rlutil::locate(5,26);
    cout<<"Eleccion incorrecta intente nuevamente!!!! "<<endl;

    rlutil::msleep(1000);
    rlutil::locate(5,26);
    cout<<"                                               "<<endl;

}



void Pantallas::marcoPantalla(int x, int y)
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



int Pantallas::menuPrincipal()
{
    int aux;
    rlutil:: cls();
    marcoPantalla(60,20) ;

    ///contenido
    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"MENU PRINCIPAL "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- Ventas "<<endl;
    rlutil::locate(15,14);
    cout<<"2- Administracion "<<endl;
    rlutil::locate(15,16);
    cout<<"3- Informes "<<endl;
    rlutil::locate(15,18);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>>aux;

    return aux;

}




/// menu principal

int Pantallas::menuVentas()
{
    int aux;

    rlutil:: cls();

    marcoPantalla(60,20);

    ///contenido
    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"MENU VENTAS "<<endl;

    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- Ventas de entradas "<<endl;
    rlutil::locate(15,14);
    cout<<"2- Listar ventas "<<endl;
    rlutil::locate(15,16);
    cout<<"3- Buscar Venta por id "<<endl;
    rlutil::locate(15,18);
    cout<<"4- Modificar Venta "<<endl;
    rlutil::locate(15,20);
    cout<<"5- Listar Funciones "<<endl;
    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}



int Pantallas::menuAdmin()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU ADMINISTRACION "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- Administrar cliente  "<<endl;
    rlutil::locate(15,14);
    cout<<"2- Administrar empleado  "<<endl;
    rlutil::locate(15,16);
    cout<<"3- Administrar pelicula  "<<endl;
    rlutil::locate(15,18);
    cout<<"4- Administrar Sala "<<endl;
    rlutil::locate(15,20);
    cout<<"5- Administrar funciones"<<endl;
    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;
}



int Pantallas::menuInformes()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU INFORMES "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,12);
    cout<<"1- RECAUDACION MENSUAL "<<endl;
    rlutil::locate(15,14);
    cout<<"2- RECAUDACION ANUAL "<<endl;
    rlutil::locate(15,16);
    cout<<"3- RECAUDACION POR FUNCION "<<endl;
    rlutil::locate(15,18);
    cout<<"4- RECAUDACION POR EMPLEADO "<<endl;
    rlutil::locate(15,20);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}



/// sub menu


int Pantallas::menuAdministrarCliente()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU CLIENTE "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar cliente nuevo  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar clientes  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar cliente "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar cliente "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar cliente "<<endl;

    rlutil::locate(15, 20);
    cout<<"6- reactivar cliente"<< endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}


int Pantallas::menuAdministrarEmpleado()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU EMPLEADO "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar empleado nuevo  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar empleado  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar empleado "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar empleados "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar empleado "<<endl;

    rlutil::locate(15, 20);
    cout<<"6- reactivar empleado "<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;

}


int Pantallas::menuAdministrarSala()
{
    int aux;
    rlutil::cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU SALA "<<endl;

    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar sala nueva"<<endl;

    rlutil::locate(15,12);
    cout<<"2- Listar salas"<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar sala"<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar sala"<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar sala"<<endl;

    rlutil::locate(15,20);
    cout<<"6- Reactivar sala"<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir"<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin >> aux;

    return aux;
}



/// 2do sub-sub menu

///cliente empleado OK

Cliente  Pantallas::pAgregarCliente()
{

    limpiarBuffer();
    Cliente cli;
    ServicioCliente serviCli;

    int conta2, idcliente;
    char aux[50]= {};
    idcliente= generacionId(1);

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"Crear Cliente "<<endl;

    //id

    rlutil::locate(15,10);
    cout <<"Id: "<< idcliente;


    //apellido
    conta2=0;

    do
    {
        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Apellido: ";
        rlutil::locate(26,12);
        cin.getline(aux,50);

        if(!(validarTexto(aux)))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";
            conta2++;
            aux[0] = '\0';
            rlutil::locate(26,12);
            cout << "                  ";
        }
        else
        {
            break;
        }

    }
    while(!(validarTexto(aux))&& conta2<3);

    if(conta2==3)
    {
        rlutil::locate(25,26);
        cout << "se han ingresado varias veces mal se cancela la operacion";
        rlutil::msleep(1500);
        rlutil::locate(25,26);
        cout << "                                                          ";
        return Cliente();
    }

    cli.setapellido(aux) ;


    //nombre
    conta2=0;
    aux[0] = '\0';

    do
    {
        rlutil::locate(15,14);
        cout<<"Nombre: ";
        rlutil::locate(23,14);
        cin.getline(aux,50);


        if(!(validarTexto(aux)))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";
            conta2++;
            aux[0] = '\0';
            rlutil::locate(23,14);
            cout << "                    ";
        }
        else
        {
            break;
        }

    }
    while(!(validarTexto(aux))&& conta2<3);

    if(conta2==3)
    {
        rlutil::locate(25,26);
        cout << "se han ingresado varias veces mal se cancela la operacion";
        rlutil::msleep(1500);
        rlutil::locate(25,26);
        cout << "                                                          ";
        return Cliente();
    }

    cli.setnombre(aux);


    /// dni
    conta2=0;
    aux[0] = '\0';

    do
    {
        rlutil::locate(15,16);
        cout <<"DNI: ";
        rlutil::locate(20,16);
        cin.getline(aux,50);


        if(!(validarNumeros(aux)))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(20,16);
            cout << "                            ";
            conta2++;
            aux[0] = '\0';
        }
        else
        {
            break;
        }

    }
    while(conta2<3);

    if(conta2==3)
    {
        rlutil::locate(25,26);
        cout << "se han ingresado varias veces mal se cancela la operacion";
        rlutil::msleep(1500);
        rlutil::locate(25,26);
        cout << "                                                          ";
        return Cliente();
    }


    if(serviCli.buscarClientePorDni(atoi(aux)))
    {
        rlutil::locate(5,26);
        cout<<"el dni ingresado ya esta registrado revise  y vuelva a intentar";
        rlutil::msleep(1500);

        rlutil::locate(5,26);
        cout<<"                                                                 ";
        return Cliente();
    }


    cli.setdniPersona(atoi(aux));


    ///correo
    conta2=0;
    aux[0]='\0';

    rlutil::locate(15,18);
    cout <<"Email: ";
    rlutil::locate(22,18);
    cin.getline(aux, 50);
    cli.set_email(aux);





    cli.setactivo(true);
    cli.setEsEmpleado(false);
    cli.setidPersona(idcliente);





    // guardar
    do
    {

        aux[0]='\0';

        rlutil::locate(15,22);
        cout <<"1:Guardar 0:Salir/Cancelar";

        rlutil::locate(5,26);
        cout<<"Eleccion: ";
        cin.getline(aux,50);

        if(validarNumeros(aux))
        {

            int num= atoi(aux);
            if(num==1)
            {

                rlutil::locate(25,26);
                serviCli.guardarCliente(cli);
                cout <<"se guardo corretamente!!";
                rlutil::msleep(1500);
                return cli;

            }
            else if(num==0)
            {
                rlutil::locate(25,26);
                cout <<"Guardo cancelado!!";
                rlutil::msleep(1500);
                return Cliente();
            }
            else
            {
                rlutil::locate(25,26);
                cout <<"eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout <<"                          ";
            }


        }
        else
        {
            rlutil::locate(25,26);
            cout <<"eleccion incorrecta";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout <<"                     ";


        }

    }
    while(conta2<3);

}


/// empleado OK

Empleado  Pantallas::pAgregarEmpleado()
{
    ServicioEmpleado serviemple;

    Empleado emple;

    int conta2,legajo,idEmple, respuesta;
    char aux[50]= {};

    idEmple=generacionId(2);

    limpiarBuffer();

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"Crear Empleado "<<endl;


    rlutil::locate(15,10);
    cout<<"ID: "<< idEmple;


    //apellido
    conta2=0;

    do
    {
        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Apellido: ";
        rlutil::locate(26,12);
        cin.getline(aux,50);

        if(!(validarTexto(aux)))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";
            rlutil::locate(26,12);
            cout << "                    ";
            conta2++;
            aux[0] = '\0';
        }
        else
        {
            break;
        }

    }
    while(!(validarTexto(aux))&& conta2<3);

    if(conta2==3)
    {
        rlutil::locate(25,26);
        cout << "se han ingresado varias veces mal se cancela la operacion";
        rlutil::msleep(1500);
        rlutil::locate(25,26);
        cout << "                                                          ";
        return Empleado();
    }
    emple.setapellido(aux);

    //nombre
    conta2=0;
    aux[0] = '\0';

    do
    {
        rlutil::locate(15,14);
        cout<<"Nombre: ";
        rlutil::locate(26,14);
        cin.getline(aux,50);


        if(!(validarTexto(aux)))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";
            rlutil::locate(26,14);
            cout << "                           ";
            conta2++;
            aux[0] = '\0';
        }
        else
        {
            break;
        }

    }
    while(!(validarTexto(aux))&& conta2<3);

    if(conta2==3)
    {
        rlutil::locate(25,26);
        cout << "se han ingresado varias veces mal se cancela la operacion";
        rlutil::msleep(1500);
        rlutil::locate(25,26);
        cout << "                                                          ";
        return Empleado();
    }

    emple.setnombre(aux);


    /// dni
    conta2=0;
    aux[0] = '\0';

    do
    {
        rlutil::locate(15,16);
        cout <<"DNI: ";
        rlutil::locate(26,16);
        cin.getline(aux,50);


        if(!(validarNumeros(aux)))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(26,16);
            cout << "                    ";
            conta2++;
            aux[0] = '\0';
        }
        else
        {
            break;
        }

    }
    while(conta2<3);

    if(conta2==3)
    {
        rlutil::locate(25,26);
        cout << "se han ingresado varias veces mal se cancela la operacion";
        rlutil::msleep(1500);
        rlutil::locate(25,26);
        cout << "                                                          ";
        return Empleado();
    }



    if(serviemple.buscarEmpleadoPorDni(atoi(aux)))
    {
        rlutil::locate(5,26);
        cout<<"el dni ingresado ya esta registrado revise  y vuelva a intentar";
        rlutil::msleep(1500);

        rlutil::locate(5,26);
        cout<<"                                                                 ";
        return Empleado();
    }


    emple.setdniPersona(atoi(aux));

    ///legajo

    legajo= generacionLegajo();
    rlutil::locate(15,18);
    cout <<"numero de Legajo: ";
    rlutil::locate(33,18);
    cout << legajo;

    emple.setactivo(true);

    emple.set_numeroLegajo(legajo);

    emple.setEsEmpleado(true);

    emple.setidPersona(idEmple);

    // guardar
    conta2=0;

    do
    {

        rlutil::locate(15,22);
        cout <<"1:Guardar 0:Salir/Cancelar";

        rlutil::locate(5,26);
        cout<<"eleccion:";
        cin.getline(aux,50);

        if(validarNumeros(aux))
        {

            int num= atoi(aux);
            if(num==1)
            {

                rlutil::locate(16,26);
                serviemple.guardarEmpleado(emple);
                cout <<"se guardo corretamente!!";
                rlutil::msleep(1500);
                return emple;

            }
            else if(num==0)
            {
                rlutil::locate(16,26);
                cout <<"Guardo cancelado!!";
                rlutil::msleep(1500);
                return Empleado();
            }


        }
        else
        {
            rlutil::locate(15,26);
            cout <<"eleccion incorrecta";
            rlutil::msleep(1500);
            rlutil::locate(15,26);
            cout <<"                     ";
            conta2++;

        }



    }
    while(conta2<3);



}




void Pantallas::pBuscarClienteId()
{

    int aux;
    ServicioCliente servicli;
    Cliente cli;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Buscar Cliente "<<endl;

    rlutil::locate(15,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(30,10);
    cin>> aux;

    cli= servicli.buscarClientePorId(aux);

    if(cli.getidPersona()>0)
    {

        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Apellido: "<<cli.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);

        rlutil::locate(15,14);
        cout<<"Nombre: "<< cli.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(15,16);
        cout <<"DNI: "<< cli.getdniPersona()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(15,18);
        cout <<"Email: "<< cli.get_email()<<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(15,20);
        cout <<"Es Empleado: "<<(cli.getEsEmpleado()? "si" : "no" )<<endl;
        rlutil::msleep(500);

        rlutil::locate(15,22);
        cout <<"Es Activo: "<<(cli.getactivo()? "si" : "no")<<endl;
        rlutil::msleep(500);


        rlutil::locate(5,26);
        cout<<"presione cualquier tecla para continuar....."<< endl;
        rlutil::anykey();

    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
    }


}


void Pantallas::pBuscarEmpleadoId()
{

    int aux;
    ServicioEmpleado serviemple;
    Empleado emple;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Buscar Empleado "<<endl;

    rlutil::locate(15,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(30,10);
    cin>> aux;

    emple= serviemple.buscarEmpleadoPorId(aux);

    if(emple.getidPersona()>0)
    {

        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Apellido: "<<emple.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);

        rlutil::locate(15,14);
        cout<<"Numero legajo: "<< emple.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(15,16);
        cout<<"Nombre: "<< emple.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(15,18);
        cout <<"DNI: "<< emple.getdniPersona()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(15,20);
        cout <<"Activo "<< (emple.getactivo()? "si" : "no") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(15,22);
        cout <<"Es Empleado: "<<(emple.getEsEmpleado()?"si" : "no" ) <<endl;
        rlutil::msleep(500);

        rlutil::locate(15,24);
        cout <<"Es Administrador: "<<(emple.get_admin()?"si" : "no" ) <<endl;
        rlutil::msleep(500);




        rlutil::locate(5,26);
        cout <<"Precione cualquier tecla para continuar..... ";
        rlutil::anykey();

    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
    }


}


void Pantallas::pEliminarCliente()
{
    limpiarBuffer();
    ServicioCliente servicli;

    char aux[5];
    int cont=0, eleccion;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Eliminacion CLIENTE "<<endl;
    do
    {
        rlutil::setColor(15);
        rlutil::locate(15,10);
        cout<<"Indique el id a eliminar: "<<endl;

        rlutil::locate(41,10);
        cin.getline(aux, 5) ;

        if (!validarNumeros(aux))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            continue;
        }
        else if (servicli.buscarClientePorId(atoi(aux)).getidPersona() == -1)
        {


            rlutil::locate(25,26);
            cout << "no se encontro el id";
            rlutil::msleep(1500);
            cont++;
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            continue;
        }

        break;  //id encontrado

    }
    while (cont < 3);














    rlutil::locate(15,18);
    cout<<"1- guardar    0- cancelar"<<endl;


    do
    {
        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {

            servicli.bajaCliente(atoi(aux));
            rlutil::locate(25,26);
            cout<<"Eliminacion exitosa ";
            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {

            rlutil::locate(25,26);
            cout<<"Eliminacion cancelada "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


void Pantallas::pEliminarEmpleado()
{
    limpiarBuffer();
    ServicioEmpleado serviEmple ;
    char aux[5];
    int cont=0, eleccion;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Eliminacion Empleado "<<endl;
    do
    {
        rlutil::setColor(15);
        rlutil::locate(15,10);
        cout<<"Indique el id a eliminar: "<<endl;

        rlutil::locate(41,10);
        cin.getline(aux,5);

        if (!validarNumeros(aux))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            continue;
        }

        else if (serviEmple.buscarEmpleadoPorId(atoi(aux)).getidPersona() == -1)

        {
            rlutil::locate(25,26);
            cout << "no se encontro el id";
            rlutil::msleep(1500);
            cont++;
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            continue;
        }

        break;  //id encontrado

    }
    while (cont < 3);


    rlutil::locate(15,18);
    cout<<"1- guardar    0- cancelar"<<endl;


    do
    {

        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {
            serviEmple.bajaEmpleado(atoi(aux));
            rlutil::locate(25,26);
            cout<<"Eliminacion exitosa ";
            rlutil::msleep(1500);

        }
        else if (eleccion ==0)
        {
            rlutil::locate(25,26);
            cout<<"Eliminacion cancelada "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


bool Pantallas::pModificarCliente()
{
    limpiarBuffer();

    int cont=0;
    char nombre[50], apellido[50], email[50], dni[12],aux[5];


    ServicioCliente servicli;
    Cliente cli;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Modificar Cliente "<<endl;

    do
    {
        rlutil::locate(10,10);
        cout<<"Indique el id: "<<endl;
        rlutil::locate(25,10);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            cli= servicli.buscarClientePorId(atoi(aux));

            if(cli.getidPersona()>0 && cli.getactivo()==true )
            {

                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "id incorrecto intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                  ";
                rlutil::locate(41,10);
                cout << "     ";
                rlutil::locate(25,10);
                cout << "     ";
                cont++;


            }



        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            rlutil::locate(25,10);
            cout << "     ";
            continue;
        }

    }
    while(cont<3);


    if(cli.getidPersona()>0)
    {


        rlutil::setColor(15);
        rlutil::locate(10,12);
        cout <<"Apellido: "<<cli.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);


        rlutil::locate(10,14);
        cout<<"Nombre: "<< cli.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(10,16);
        cout <<"DNI: "<< cli.getdniPersona()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(10,18);
        cout <<"Email: "<< cli.get_email()<<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(10,20);
        cout <<"Es Empleado: "<<(cli.getEsEmpleado()?"si": "no") <<endl;
        rlutil::msleep(500);

        rlutil::locate(10,22);
        cout <<"Es Activo: "<<(cli.getactivo()? "si" : "no")<<endl;
        rlutil::msleep(500);



    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);

    }

    /// modificacion



    rlutil::setColor(15);
    rlutil::locate(40,12);
    cout<<"Apellido: ";
    cin.getline(apellido,50);
    if(strlen(apellido)>0)
    {
        cli.setapellido(apellido) ;
    }

    rlutil::locate(40,14);
    cout<<"Nombre: ";
    cin.getline(nombre,50);
    if (strlen(nombre)>0)
    {
        cli.setnombre(nombre);
    }


    rlutil::locate(40,16);
    cout <<"DNI: ";
    cin.getline(dni,12);
    if(strlen(dni)>0)
    {
        cli.setdniPersona(atoi(dni));
    }


    rlutil::locate(40,18);
    cout <<"Email: ";
    cin.getline(email,50);
    if(strlen(email)>0)
    {
        cli.set_email(email);
    }


    rlutil::locate(40,20);
    cout <<"item no editable" <<endl;

    rlutil::locate(40,22);
    cout <<"item no editable" <<endl;


    aux[0]='\0';
    cont=0;

    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            if(atoi(aux)==1)
            {

                return servicli.modificarCliente(cli, cli.getidPersona()-1);
            }
            else if(atoi(aux)==0)
            {
                return false;
            }
            else
            {

                rlutil::locate(35,26);
                cout<<"eleccion incorrecta!!!!";
                rlutil::msleep(1500);
                rlutil::locate(30,26);
                cont++;
                cout<<"                                       ";

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            continue;
        }

    }
    while(cont<3);


}


bool Pantallas::PModificarEmpleado()
{

    limpiarBuffer();

    int  nLegajo, cont=0;
    char nombre[50], apellido[50], edad[4], dni[12],admin[4],aux[5];



    ServicioEmpleado serviEmple;
    Empleado emple;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Modificar Empleado "<<endl;

    do
    {
        rlutil::locate(10,10);
        cout<<"Indique el id: "<<endl;
        rlutil::locate(25,10);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {
            emple= serviEmple.buscarEmpleadoPorId(atoi(aux));

            if(emple.getidPersona()>0 && emple.getactivo()==true )
            {

                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "id incorrecto intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                  ";
                rlutil::locate(41,10);
                cout << "     ";
                rlutil::locate(25,10);
                cout << "     ";
                cont++;
            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            rlutil::locate(25,10);
            cout << "     ";
            continue;
        }

    }
    while(cont<3);


    if(emple.getidPersona()>0)
    {


        rlutil::setColor(15);
        rlutil::locate(10,12);
        cout <<"Apellido: "<<emple.getapellido()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);

        rlutil::locate(10,14);
        cout<<"Nombre: "<< emple.getnombre()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(10,16);
        cout <<"DNI: "<< emple.getdniPersona()<<endl;
        //rlutil::locate(emple16);
        rlutil::msleep(500);

        rlutil::locate(10,18);
        cout <<"Es Empleado: "<<(emple.getEsEmpleado()?"si" : "no" ) <<endl;
        rlutil::msleep(500);

        rlutil::locate(10,20);
        cout <<"numero Legajo "<< emple.get_numeroLegajo() <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(10,22);
        cout <<"Activo: "<<( emple.getactivo()? "si" : "no") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);

        rlutil::locate(10,24);
        cout <<"es administrador: "<< (emple.get_admin()?"si" :"no") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);


    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);

    }

    /// modificacion



    rlutil::setColor(15);
    rlutil::locate(40,12);
    cout<<"Apellido: ";
    cin.getline(apellido,50);
    if(strlen(apellido)>0)
    {
        emple.setapellido(apellido) ;
    }

    rlutil::locate(40,14);
    cout<<"Nombre: ";
    cin.getline(nombre,50);
    if (strlen(nombre)>0)
    {
        emple.setnombre(nombre);
    }


    rlutil::locate(40,16);
    cout <<"DNI: ";
    cin.getline(dni,12);
    if(strlen(dni)>0)
    {
        emple.setdniPersona(atoi(dni));
    }

    rlutil::locate(40,18);
    cout <<"item no editable ";

    rlutil::locate(40,20);
    cout <<"item no editable ";

    rlutil::locate(40,22);
    cout <<"item no editable ";

    rlutil::locate(40,24);
    cout <<"item no editable ";

    aux[0]='\0';
    cont=0;


    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            if(atoi(aux)==1)
            {

                return serviEmple.modificarEmpleado(emple, emple.getidPersona()-1);

            }
            else if(atoi(aux)==0)
            {
                return false;
            }
            else
            {

                rlutil::locate(35,26);
                cout<<"eleccion incorrecta!!!!";
                rlutil::msleep(1500);
                rlutil::locate(30,26);
                cout<<"                                       ";
            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;

        }
    }
    while(cont <3);

}



void Pantallas::pReactivarCliente()
{
    int num, eleccion;
    ServicioCliente servicli;
    rlutil::cls();

    ///lista todos los que estan inactivos

    if(!servicli.listarClientes(0))
    {
        return;
    }

    /// pedimos el id a reactivar
    cout<<"indique el Id del usuario que quiere reactivar: ";
    cin>> num;
    cout<<endl<<endl;

    /// preguntamos que quiere hacer

    cout<<"1- confirmar    0- cancelar"<<endl<< endl;


    do
    {

        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion == 1)
        {
            if(servicli.reactivarCliente(num))
            {
                cout << "                    Reactivacion exitosa!!! ";
            }
            else
            {
                cout << "                    ID incorrecto ";
            }

            rlutil::msleep(1500);
        }
        else if (eleccion == 0)
        {
            cout<<"                    re-Activacion cancelada!!! "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }


    }
    while(eleccion <0 || eleccion>1);

}




void Pantallas:: pReactivarEmpleado()
{

    int num, eleccion;
    ServicioEmpleado serviEmple;
    rlutil::cls();

    ///lista todos los que estan inactivos

    if(!serviEmple.listarEmpleados(0))
    {

        return;
    }

    /// pedimos el id a reactivar
    cout<<"indique el Id del empleado que quiere reactivar: ";
    cin>> num;
    cout<<endl<<endl;

    /// preguntamos que quiere hacer

    cout<<"1- confirmar    0- cancelar"<<endl<< endl;


    do
    {

        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {

            if(serviEmple.reactivarEmpleado(num))
            {
                cout<<"                Reactivacion exitosa!!! ";
            }
            else
            {
                cout<<"                   ID incorrecto ";
            }

            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {


            cout<<"                 reactivacion  cancelada!!! "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


/// PELICULAS

int Pantallas::menuAdminPeliculas()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU PELICULAS "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar pelicula nueva  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar peliculas  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar pelicula "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar pelicula "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar pelicula "<<endl;

    rlutil::locate(15,20);
    cout<<"6- reactivar pelicula"<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;
}



///agregar pelicula
Pelicula Pantallas::pAgregarPelicula ()
{
    limpiarBuffer();
    Pelicula peli;
    servicioPelicula servipeli;

    int idPelicula, numero, eleccion, conta2=0;
    char aux[50];


    marcoPantalla(60,20);

    rlutil::setColor(4);

    rlutil::locate(30,8);
    cout<<"Agregar Pelicula "<<endl;
    rlutil::setColor(15);



    idPelicula= generacionId(3);
    rlutil::locate(15,10);
    cout <<"id: "<< idPelicula;

    do
    {
        rlutil::locate(15,12);
        cout <<"Nombre: ";

        cin.getline(aux, 50);

        if((validarTexto(aux)))
        {

            if(servipeli.buscarPeliculaPorNombre(aux).GetIdPelicula()<1)
            {
                peli.SetNombrePelicula(aux) ;
                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "la pelicula ya existe";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                                          ";
                return Pelicula();
            }
        }
        else
        {

            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";
            conta2++;
            aux[0] = '\0';
            rlutil::locate(23,12);
            cout << "                           ";
        }

        if(conta2==3)
        {
            rlutil::locate(5,26);
            cout << "Se han ingresado demasiados intentos invalidos. operacion cancelada";
            rlutil::msleep(1500);
            rlutil::locate(5,26);
            cout << "                                                                      ";
            return Pelicula();
        }

    }
    while(conta2<3);

    /// clasificacion
    conta2=0;
    aux[0]='\0';

    int tam= sizeof(Pelicula::listaClasificacion)/ sizeof(Pelicula::listaClasificacion[0]);

    do
    {
        rlutil::locate(15,14);
        cout<<"Clasificacion: ";

        rlutil::locate(25,26);
        for(int i=0; i<tam; i++)
        {
            cout<<i+1<<":"<<Pelicula::listaClasificacion[i]<<" ";
        }

        rlutil::locate(30,14);
        cin.getline(aux, 50);

        if(validarNumeros(aux))
        {
            numero = atoi(aux); ///casteo

            if (numero > 0 && numero <= tam)
            {
                peli.SetClasificacion(numero-1);
                break;

            }
            else
            {
                rlutil::locate(25,26);
                cout<<"eleccion incorrecta!!!!                               ";

                rlutil::msleep(1500);
                rlutil::locate(24,26);
                cout<<"                                                       ";
                rlutil::locate(30,14);
                cout<<"                   ";
                conta2++;
            }

        }
        else
        {
            rlutil::locate(25,26);
            cout<<"eleccion invalida";
            rlutil::msleep(1500);
            rlutil::locate(24,26);
            cout<<"                                                       ";
            rlutil::locate(30,14);
            cout<<"                   ";
            conta2++;
        }



    }
    while(conta2<3);


    if(conta2==3)
    {
        rlutil::locate(5,26);
        cout << "Se han ingresado demasiados intentos invalidos. operacion cancelada";
        rlutil::msleep(1500);
        rlutil::locate(5,26);
        cout << "                                                                      ";
        return Pelicula();
    }



    rlutil::locate(25,26);
    cout<<"                                                         ";


    ///genero
    conta2=0;
    aux[0]='\0';
    tam=0;

    tam = sizeof(Pelicula::listaGenero) / sizeof(Pelicula::listaGenero[0]);

    do
    {
        rlutil::locate(15,16);
        cout<<"Genero: ";

        rlutil::locate(25,26);
        for(int i=0; i< tam; i++)
        {
            cout<<i+1<<":"<<Pelicula::listaGenero[i]<<" ";
        }

        rlutil::locate(23,16);
        cin.getline(aux,50);

        if(validarNumeros(aux))
        {

            numero = atoi(aux); /// castea a entero

            if (numero > 0 && numero <= tam)
            {
                peli.SetGenero(numero-1);
                break;

            }
            else
            {
                rlutil::locate(25,26);
                cout<<"eleccion incorrecta!!!!                           ";

                rlutil::msleep(1500);
                rlutil::locate(24,26);
                cout<<"                                                ";
                rlutil::locate(23,16);
                cout<<"       ";
                conta2++;

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout<<"solo puede ingresar numeros!!!!                           ";

            rlutil::msleep(1500);
            rlutil::locate(24,26);
            cout<<"                                                ";
            rlutil::locate(23,16);
            cout<<"       ";
            conta2++;

        }


        if(conta2==3)
        {
            rlutil::locate(5,26);
            cout << "Se han ingresado demasiados intentos invalidos. operacion cancelada";
            rlutil::msleep(1500);
            rlutil::locate(5,26);
            cout << "                                                                       ";
            return Pelicula();
        }


    }
    while(conta2<3);





    /// director
    conta2 =0;
    aux[0]='\0';


    rlutil::locate(25,26);
    cout<<"                                                         ";

    do
    {
        rlutil::locate(15,18);
        cout << "Director: ";
        rlutil::locate(25,18);

        cin.getline(aux, 50);

        if(validarTexto(aux))
        {

            peli.SetDirector(aux);
            break;

        }
        else
        {
            rlutil::locate(25,26);
            cout<<"ingrese solo texto!!!!                           ";

            rlutil::msleep(1500);
            rlutil::locate(24,26);
            cout<<"                                                ";
            rlutil::locate(23,16);
            cout<<"       ";
            conta2++;

        }


    }
    while(conta2<3);

    if(conta2==3)
    {
        rlutil::locate(5,26);
        cout << "Se han ingresado demasiados intentos invalidos. operacion cancelada";
        rlutil::msleep(1500);
        rlutil::locate(5,26);
        cout << "                                                                     ";
        return Pelicula();
    }

    ///


    peli.SetActivo(true);

    peli.SetIdPelicula(idPelicula);


    // guardar
    aux[0]='\0';

    rlutil::locate(15,22);
    cout<<"1- guardar    0- cancelar "<<endl;


    do
    {
        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin.getline(aux,3);

        if(validarNumeros(aux))
        {
            eleccion= atoi(aux);

            if(eleccion== 1)
            {

                servipeli.guardarPelicula(peli);
                rlutil::locate(25,26);
                cout<<"Guardado exitoso!! ";
                rlutil::msleep(1500);
                return peli;

            }

            else if (eleccion ==0)
            {

                rlutil::locate(25,26);
                cout<<"operacion cancelada "<<endl;
                rlutil::msleep(1500);
                return Pelicula();
            }
            else
            {
                rlutil::locate(25,26);
                cout << "eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                    ";
                rlutil::locate(15,26);
                cout << "  ";
            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "se debe ingresar solo numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            rlutil::locate(15,26);
            cout << "  ";
            eleccion =2;
        }



    }
    while(eleccion <0 || eleccion>1);


}






void Pantallas:: pBuscarPeliculaId()
{

    servicioPelicula servipeli;
    Pelicula peli;

    int aux;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Buscar Pelicula "<<endl;

    rlutil::locate(15,10);
    cout<<"Indique el id: "<<endl;
    rlutil::locate(30,10);
    cin>> aux;

    peli= servipeli.buscarPeliculaPorId(aux);

    if(peli.GetIdPelicula()>0)
    {

        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout <<"Nombre: "<<peli.GetNombrePelicula()<<endl;
        rlutil::msleep(500);


        rlutil::locate(15,14);
        cout<<"Clasificacion: "<< peli.GetClasificacion()<<endl;
        rlutil::msleep(500);

        rlutil::locate(15,16);
        cout<<"Genero: "<< peli.GetGenero()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);


        rlutil::locate(15,18);
        cout <<"Director: "<< peli.GetDirector()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(15,20);
        cout <<"Estado "<< (peli.GetActivo()? "Activo" : "Inactivo") <<endl;
        //rlutil::locate(26,18);
        rlutil::msleep(500);


    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
    }

    rlutil::locate(5,26);
    cout<<"presione cualquier tecla para continuar....."<< endl;
    rlutil::anykey();

    rlutil::anykey();

}



bool Pantallas::pModificarPelicula()
{


    limpiarBuffer();

    int cont=0;
    char nombrePelicula[50], director[100], aux[5],clasi[5], genero[5];




    servicioPelicula serviPeli;
    Pelicula peli;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Modificar Pelicula "<<endl;

    do
    {


        rlutil::locate(10,10);
        cout<<"Indique el id: "<<endl;
        rlutil::locate(25,10);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            peli= serviPeli.buscarPeliculaPorId(atoi(aux));

            if(peli.GetIdPelicula()>0 && peli.GetActivo()==true )
            {

                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "id incorrecto intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                  ";
                rlutil::locate(41,10);
                cout << "     ";
                rlutil::locate(25,10);
                cout << "     ";
                cont++;


            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            rlutil::locate(25,10);
            cout << "     ";
            continue;
        }

    }
    while(cont<3);


    if(peli.GetIdPelicula()>0)

    {


        rlutil::setColor(15);
        rlutil::locate(10,12);
        cout <<"Nombre: "<<peli.GetNombrePelicula()<<endl;
        //rlutil::locate(26,12);
        rlutil::msleep(500);


        rlutil::locate(10,14);
        cout<<"Director: "<< peli.GetDirector()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(10,16);
        cout <<"Clasificacion "<< peli.GetClasificacion()<<endl;
        //rlutil::locate(emple16);
        rlutil::msleep(500);

        ///GENERO
        rlutil::locate(10,18);
        cout <<"Genero "<< peli.GetGenero()<<endl;
        rlutil::msleep(500);


        rlutil::locate(10,20);
        cout <<"Estado: "<<(peli.GetActivo()?"Activo": "Inactivo") <<endl; ///ACTIVO
        rlutil::msleep(500);


    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);


    }

    /// modificacion

    cont=0;
    do
    {
        rlutil::setColor(15);
        rlutil::locate(40,12);
        cout<<"Nombre: ";
        cin.getline(nombrePelicula,50);

        if(validarTexto(nombrePelicula))
        {
            if(strlen(nombrePelicula)>0)
            {
                peli.SetNombrePelicula(nombrePelicula) ;
                break;
            }
        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(48,12);
            cout << "                   ";
            cont++;

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }


    }
    while(cont<3);

/// director
    cont=0;
    do
    {
        rlutil::locate(40,14);
        cout<<"Director: ";
        cin.getline(director,100);

        if(validarTexto(director))
        {


            if (strlen(director)>0)
            {
                peli.SetDirector(director);
                break;
            }


        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }

    }
    while(cont<3);


    /// clasificacion
    rlutil::locate(40,16);
    cout <<"Clasificacion: ";
    do
    {

        int tam= sizeof(Pelicula::listaClasificacion)/ sizeof(Pelicula::listaClasificacion[0]);

        rlutil::locate(25,26);
        for(int i=0; i<tam; i++)
        {

            cout<<i+1<<"-"<< Pelicula::listaClasificacion[i]<<" ";
        }

        rlutil::locate(55,16);
        cin.getline(clasi,5);

        if(validarNumeros(clasi))
        {

            if(atoi(clasi)>0 && atoi(clasi) <=tam )
            {
                peli.SetClasificacion(atoi(clasi)-1);
                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "id incorrecto intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                  ";
                rlutil::locate(41,10);
                cout << "     ";
                rlutil::locate(25,10);
                cout << "     ";
                cont++;
            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            rlutil::locate(25,10);
            cout << "     ";

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }

    }
    while(cont<3);




    ///genero

    cont=0;

    rlutil::locate(40,18);
    cout <<"Genero: ";


    do
    {
        int tam2 = sizeof(Pelicula::listaGenero) / sizeof(Pelicula::listaGenero[0]);

        rlutil::locate(15,26);
        for(int i=0; i<tam2; i++)
        {

            cout<<i+1<<"-"<< Pelicula::listaGenero[i]<<" ";
        }


        rlutil::locate(48,18);
        cin.getline(genero,5);

        if(validarNumeros(genero))
        {
            if (atoi(genero)>0 && atoi(genero) <=tam2)
            {

                peli.SetGenero(atoi(genero)-1);
                break;

            }
            else
            {
                rlutil::locate(25,26);
                cout << "opcion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                  ";
                rlutil::locate(15,26);
                cout << "                                         ";
                rlutil::locate(48,18);
                cout << "     ";
                cont++;


            }


        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            rlutil::locate(25,10);
            cout << "     ";

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }

    }
    while(cont<3);

    rlutil::locate(15,26);
    cout << "                                                  ";

    rlutil::locate(40,20);
    cout <<"item no editable";



    aux[0]='\0';
    cont=0;

    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            if(atoi(aux)==1)
            {


                return  serviPeli.modificarPelicula(peli, peli.GetIdPelicula()-1);
            }
            else if(atoi(aux)==0)
            {
                return false;
            }
            else
            {

                rlutil::locate(35,26);
                cout<<"eleccion incorrecta!!!!";
                rlutil::msleep(1500);
                rlutil::locate(30,26);
                cont++;
                cout<<"                                       ";

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;

        }

    }
    while(cont<3);
}





void Pantallas::pEliminarPelicula()
{
    limpiarBuffer();
    servicioPelicula servipeli;
    char aux[5];
    int cont=0, eleccion;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"Eliminacion Pelicula "<<endl;

    do
    {
        rlutil::setColor(15);
        rlutil::locate(15,10);
        cout<<"Indique el id a eliminar: "<<endl;

        rlutil::locate(41,10);
        cin.getline(aux,5);

        if (!validarNumeros(aux))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            continue;
        }
        else if (servipeli.buscarPeliculaPorId(atoi(aux)).GetIdPelicula() == -1)
        {
            rlutil::locate(25,26);
            cout << "no se encontro el id";
            rlutil::msleep(1500);
            cont++;
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            continue;
        }

        break;  //id encontrado

    }
    while (cont < 3);


    rlutil::locate(15,18);
    cout<<"1- guardar    0- cancelar"<<endl;


    do
    {

        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {
            servipeli.bajaPelicula(atoi(aux));
            rlutil::locate(25,26);
            cout << " eliminacion exitosa!!!";
            rlutil::msleep(1500);

        }
        else if (eleccion ==0)
        {
            rlutil::locate(25,26);
            cout << " Eliminacion cancelada";
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);


}





void Pantallas::pReactivarPelicula()
{

    int num, eleccion;
    servicioPelicula servipeli;
    rlutil::cls();

    ///lista todos los que estan inactivos

    if(!servipeli.listarPelicula(0))
    {

        return;
    }

    /// pedimos el id a reactivar
    cout<<"indique el Id del usuario que quiere reactivar: ";
    cin>> num;
    cout<<endl<<endl;



    cout<<"1- confirmar    0- cancelar"<<endl<< endl;


    do
    {

        cout <<"Eleccion: ";
        cin>> eleccion;


        if(eleccion== 1)
        {

            servipeli.reactivarPelicula(num);

            cout<<"                    Reactivacion exitosa!!! ";
            rlutil::msleep(1500);

        }

        else if (eleccion ==0)
        {


            cout<<"                    reactivacion  cancelada!!! "<<endl;
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while(eleccion <0 || eleccion>1);

}


///SALAS


Sala Pantallas::pAgregarSala()
{
    ServicioSala servisala;
    Sala sal;

    int num, conta2=0, idSala, eleccion;

    char aux[50];

    idSala= generacionId(4);


    limpiarBuffer();
    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout<<"Crear Sala"<<endl;

    ///idSala

    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout <<"ID: "<< idSala;


    /// nombre sala
    do
    {
        rlutil::locate(15,12);
        cout <<"Nombre:";
        rlutil::locate(26,12);
        cin.getline(aux,50);

        if(validarTexto(aux))
        {

            if(servisala.buscarSalaPorNombre(aux).GetIdSala()<1 )
            {

                sal.SetNombreSala(aux);
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout << "la sala ya existe revise y  vuelva a intentar";
                rlutil::msleep(1500);
                rlutil::locate(5,26);
                cout << "                                                          ";
                return Sala();

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";

            conta2++;
            aux[0] = '\0';
            rlutil::locate(26,12);
            cout<<"            " ;
        }

        if(conta2==3)
        {
            rlutil::locate(5,26);
            cout << "Se han ingresado demasiados intentos invalidos. operacion cancelada";
            rlutil::msleep(1500);
            rlutil::locate(5,26);
            cout << "                                                                      ";
            return Sala();
        }

    }
    while(conta2<3);



    /// tipo de sala

    conta2=0;
    aux[0]='\0';

    do
    {
        rlutil::locate(15,14);
        cout<<"Tipo de sala: ";

        rlutil::locate(25,26);

        for(int i=0; i<3; i++)
        {
            cout<< i+1 << ":" << Sala::listaTipoSala[i] << "  ";
        }

        int tam= (sizeof(Sala::listaTipoSala)/ sizeof(Sala::listaTipoSala[0]));


        rlutil::locate(30,14);
        cin.getline(aux, 10);

        if(validarNumeros(aux))
        {


            int numero= atoi(aux);
            if(numero>0 && numero<=tam)
            {

                sal.SetTipoSala(numero-1);
                break;
            }

            else
            {
                rlutil::locate(25,26);
                cout << "                                                    ";
                rlutil::locate(5,26);
                cout << "eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(5,26);
                cout << "                                                          ";
                rlutil::locate(30,14);
                cout<<"            " ;
                conta2++;
            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";

            conta2++;
            aux[0] = '\0';
            rlutil::locate(30,14);
            cout<<"            " ;
        }


        if(conta2==3)
        {
            rlutil::locate(5,26);
            cout << "Se han ingresado demasiados intentos invalidos. operacion cancelada";
            rlutil::msleep(1500);
            rlutil::locate(5,26);
            cout << "                                                                      ";
            return Sala();

        }
    }
    while(conta2<3);




    ///capacidad de butacas
    conta2=0;
    aux[0]='\0';

    do
    {
        rlutil::locate(15,16);
        cout <<"Capacidad: ";
        rlutil::locate(26,16);
        cin.getline(aux,10);



        if(validarNumeros(aux))
        {

            int capacidad= atoi(aux);
            sal.SetCapacidadSala(capacidad);
            break;

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";

            conta2++;
            aux[0] = '\0';
            rlutil::locate(30,14);
            cout<<"            " ;
            rlutil::locate(26,16);
            cout<<"            " ;
        }

        if(conta2==3)
        {
            rlutil::locate(5,26);
            cout << "Se han ingresado demasiados intentos invalidos. operacion cancelada";
            rlutil::msleep(1500);
            rlutil::locate(5,26);
            cout << "                                                                      ";
            return Sala();

        }


    }
    while(conta2<3);


    sal.SetActivo(true);
    sal.SetIdSala(idSala);


    // guardar
    conta2=0;
    aux[0]='\0';

    rlutil::locate(15,22);
    cout<<"1- guardar    0- cancelar "<<endl;


    do
    {
        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin.getline(aux,3);

        if(validarNumeros(aux))
        {
            eleccion= atoi(aux);

            if(eleccion== 1)
            {

                servisala.crearSala(sal);
                rlutil::locate(25,26);
                cout<<"Guardado exitoso!! ";
                rlutil::msleep(1500);
                return sal;

            }

            else if (eleccion ==0)
            {

                rlutil::locate(25,26);
                cout<<"operacion cancelada "<<endl;
                rlutil::msleep(1500);
                return Sala();
            }
            else
            {
                rlutil::locate(25,26);
                cout << "eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                          ";

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "se debe ingresar solo numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            eleccion =-1;
        }



    }
    while(eleccion != 0 && eleccion != 1);
}






void Pantallas::pBuscarSalaPorId()
{
    int aux;
    ServicioSala serviSala;
    Sala sala;

    marcoPantalla(60, 20);

    rlutil::setColor(4);
    rlutil::locate(25, 8);
    cout << "Buscar Sala" << endl;

    rlutil::setColor(15);
    rlutil::locate(15, 10);
    cout << "Indique el id: ";
    rlutil::locate(30, 10);
    cin >> aux;

    sala = serviSala.buscarSala(aux);

    if (sala.GetIdSala() > 0)
    {

        rlutil::setColor(15);

        rlutil::locate(15, 12);
        cout << "Nombre: " << sala.GetNombreSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(15, 14);
        cout << "Tipo: " << sala.GetTipoSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(15, 16);
        cout << "Capacidad: " << sala.GetCapacidadSala() << endl;
        rlutil::msleep(500);

        rlutil::locate(15, 18);
        cout << "Estado: " << (sala.GetActivo() ? "Activo" : "Inactivo") << endl;
        rlutil::msleep(500);

        rlutil::locate(5,26);
        cout<<"presione cualquier tecla para continuar....."<< endl;
        rlutil::anykey();
    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15, 16);
        cout << "El ID buscado es incorrecto!!" << endl;
        rlutil::msleep(2000);
    }
}













/// funciones

int Pantallas::menuAdministrarFuncion()
{
    int aux;
    rlutil:: cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout<<"MENU FUNCION "<<endl;
    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"1- Agregar Funcion  "<<endl;
    rlutil::locate(15,12);
    cout<<"2- Listar Funciones  "<<endl;

    rlutil::locate(15,14);
    cout<<"3- Modificar Funcion "<<endl;

    rlutil::locate(15,16);
    cout<<"4- Buscar Fucion "<<endl;

    rlutil::locate(15,18);
    cout<<"5- Eliminar Funcion "<<endl;

    rlutil::locate(15, 20);
    cout<<"6- reactivar Funcion "<<endl;

    rlutil::locate(15,22);
    cout<<"0- Salir "<<endl;

    rlutil::locate(5,26);
    cout <<"Eleccion: ";
    cin>> aux;

    return aux;
}




/// agregar funcion

Funcion Pantallas::pAgregarFuncion()
{

    ServicioFuncion servifun;
    Funcion fun;


    bool tem;
    int idfuncion, conta2=0, hora, minutos;
    char dia[5], mes[5], anio[5],aux[50];

    limpiarBuffer();
    marcoPantalla(60,22);

    rlutil::setColor(4);
    rlutil::locate(30,8);
    cout << "Crear Funcion" << endl;



    // Id Funcion

    idfuncion = generacionId(5);

    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout<<"ID FUNCION: ";
    rlutil::setColor(4);
    cout<< idfuncion;
    fun.SetIdFuncion(idfuncion);



    // Id sala
    conta2=0;
    ServicioSala serviSala;
    Sala sala;
    do
    {
        rlutil::setColor(15);
        rlutil::locate(15,12);
        cout << "ID Sala: ";
        rlutil::locate(26,12);

        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            sala = serviSala.buscarSala(atoi(aux));

            if(sala.GetIdSala()>0)
            {
                fun.SetIdSala(atoi(aux));
                fun.SetCantidadAsientos(sala.GetCapacidadSala());
                fun.setAsientosDisponibles(sala.GetCapacidadSala());
                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "No se encontro la Sala intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                         ";
                rlutil::locate(26,12);
                cout << "                      ";
                conta2++;

            }

        }

        else
        {

            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros intente nuevamente";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            conta2++;
        }

        if(conta2==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return Funcion();
        }

    }
    while(conta2 < 3);





    // ID PELICULA
    conta2=0;
    aux[0]='\0';

    servicioPelicula servipeli;
    Pelicula peli;
    do
    {
        rlutil::locate(15,14);
        cout << "ID Pelicula: ";
        rlutil::locate(29,14);
        cin.getline(aux, 5);

        if(validarNumeros(aux))
        {
            peli = servipeli.buscarPeliculaPorId(atoi(aux));


            if(peli.GetIdPelicula()>0)
            {
                fun.SetIdPelicula(atoi(aux));
                break;

            }
            else
            {

                rlutil::locate(25,26);
                cout << "No se encontro la pelicula intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                              ";
                conta2++;
            }


        }
        else
        {

            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros intente nuevamente";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            conta2++;
            //continue;
        }

        if(conta2==3)

        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return Funcion();
        }



    }
    while(conta2 < 3);

    // FECHA
    Fecha f;
    conta2=0;
    do
    {
        rlutil::locate(15,16);
        cout << "Dia: ";

        rlutil::locate(22,16);
        cin.getline(dia,5);

        rlutil::locate(28,16);
        cout << "Mes: ";

        rlutil::locate(33,16);
        cin.getline(mes,5);

        rlutil::locate(38,16);
        cout << "Anio: ";

        rlutil::locate(44,16);
        cin.getline(anio,5);

        if (validarNumeros(dia) && validarNumeros(mes)&& validarNumeros(anio))
        {
            if( !validaFecha( atoi(dia), atoi(mes), atoi(anio)))
            {
                rlutil::locate(25,26);
                cout<<" fecha mal ingresado intente nuevamente";
                rlutil::locate(25,26);
                cout<<"                                        ";
                rlutil::locate(22,16);
                cout<<"      ";
                rlutil::locate(33,16);
                cout<<"      ";
                rlutil::locate(44,16);
                cout<<"      ";
                conta2++;

            }
            else
            {
                f.SetDia(atoi(dia));
                f.SetMes(atoi(mes));
                f.SetAnio(atoi(anio));
                break;
            }
        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros intente nuevamente";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            conta2++;
            rlutil::locate(22,16);
            cout<<"      ";
            rlutil::locate(33,16);
            cout<<"      ";
            rlutil::locate(44,16);
            cout<<"      ";

        }

        if(conta2==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return Funcion();
        }

    }
    while (conta2<3);


    /// hora
    conta2=0;
    aux[0]='\0';

    int tam= sizeof(Funcion::horarios)/sizeof(Funcion::horarios[0]);


    do
    {
        rlutil::locate(15,18);
        cout << "Hora funcion: ";

        rlutil::locate(5,28);
        for(int i=0; i<tam; i++)
        {
            cout<<i+1<<"="<<Funcion::horarios[i]<<" // ";
        }

        rlutil::locate(29,18);
        cin.getline(aux,5);


        if(validarNumeros(aux))
        {

            int eleccion= atoi(aux);

            if(eleccion>0 && eleccion <= tam)
            {

                convertidorHorario(Funcion::horarios[eleccion-1], hora, minutos);
                Funcion funAux =fun;
                f.SetMinuto(minutos);
                f.SetHora(hora);
                funAux.SetFecha(f);

                if(!servifun.comprobarFechaHora(funAux))
                {

                    fun.SetFecha(f);
                    break;
                }
                else
                {

                    rlutil::locate(25,26);
                    cout << "Horario no disponible";
                    rlutil::msleep(1500);
                    rlutil::locate(25,26);
                    cout << "                                               ";
                    conta2++;
                    rlutil::locate(5,26);
                    cout << "                                                                        ";
                }

            }
            else
            {
                rlutil::locate(25,26);
                cout << "eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                               ";
                conta2++;
                rlutil::locate(5,26);
                cout << "                                                                        ";
            }






        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros intente nuevamente";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            conta2++;
            rlutil::locate(5,26);
            cout << "                                                                        ";
        }



        if(conta2==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return Funcion();
        }

    }
    while(conta2<3);


    // estado y id

    fun.SetActiva(true);
    fun.SetIdFuncion(idfuncion);




    // guardar

    aux[0]='\0';
    int eleccion2;
    rlutil::locate(15,22);
    cout<<"1- guardar    0- cancelar "<<endl;


    do
    {
        rlutil::locate(5,26);
        cout <<"Eleccion: ";
        cin.getline(aux,3);

        if(validarNumeros(aux))
        {
            eleccion2= atoi(aux);

            if(eleccion2== 1)
            {

                servifun.crearFuncion(fun);
                rlutil::locate(25,26);
                cout<<"Guardado exitoso!! ";
                rlutil::msleep(1500);
                return fun;

            }

            else if (eleccion2 ==0)
            {

                rlutil::locate(25,26);
                cout<<"operacion cancelada "<<endl;
                rlutil::msleep(1500);
                return Funcion();
            }
            else
            {
                rlutil::locate(25,26);
                cout << "eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                          ";

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "se debe ingresar solo numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            eleccion2 =-1;
        }



    }
    while(eleccion2 != 0 && eleccion2 != 1);


}


/// eliminar funcion

void Pantallas::pEliminarFuncion()
{

    limpiarBuffer();
    ServicioFuncion servifun;
    char aux[5];
    int eleccion, cont = 0;
    rlutil::cls();

    marcoPantalla(60,20);
    rlutil::setColor(4);
    rlutil::locate(25,8);
    cout << "Eliminacion Funcion " << endl;


    do
    {
        rlutil::setColor(15);
        rlutil::locate(15,10);
        cout << "Indique el id a eliminar: "<<endl;

        rlutil::locate(41,10);
        cin.getline(aux,5);

        if (!validarNumeros(aux))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            continue;
        }
        else if (servifun.buscarPorId(atoi(aux)).GetIdFuncion() == -1)
        {
            rlutil::locate(25,26);
            cout << "no se encontro el id";
            rlutil::msleep(1500);
            cont++;
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            continue;
        }

        break;  //id encontrado

    }
    while (cont < 3);


    rlutil::locate(15,18);
    cout << "1- guardar    0- cancelar";

    do
    {

        rlutil::locate(5,26);
        cout << "Eleccion: ";
        cin >> eleccion;

        if (eleccion == 1)
        {
            servifun.bajaFuncion(atoi(aux));
            rlutil::locate(25,26);
            cout << " eliminacion exitosa!!!";
            rlutil::msleep(1500);
        }
        else if (eleccion == 0)
        {
            rlutil::locate(25,26);
            cout << " se cancelo operacion!!!";
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while (eleccion < 0 || eleccion > 1);
}


void Pantallas::pReactivarFuncion()
{

    limpiarBuffer();
    ServicioFuncion servifun;
    rlutil::cls();
    if(!servifun.listarFunciones(0))
    {

        return;
    }



    char aux[5];
    int eleccion, cont = 0;


    cout << "Reactivar Funcion " << endl;

    do
    {

        cout << "Indique el id a reactivar: ";


        cin.getline(aux,5);

        if (!validarNumeros(aux))
        {

            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";

            continue;
        }
        else if (servifun.buscarPorId(atoi(aux)).GetIdFuncion() == -1)
        {
            rlutil::locate(25,26);
            cout << "no se encontro el id";

            continue;
        }

        break;  //id encontrado

    }
    while (cont < 3);



    cout << endl<<"1- guardar    0- cancelar";

    do
    {


        cout <<endl<< "Eleccion: ";
        cin >> eleccion;

        if (eleccion == 1)
        {
            servifun.reactivarFuncion(atoi(aux));

            cout << " reactivacion exitosa!!!";
            rlutil::msleep(1500);
        }
        else if (eleccion == 0)
        {

            cout << " se cancelo operacion!!!";

            return;
        }
        else
        {
            avisoError();
        }

    }
    while (eleccion < 0 || eleccion > 1);
}



void Pantallas::pEliminarSala()
{
    limpiarBuffer();
    ServicioSala servisala;
    char aux[5];
    int eleccion, cont = 0;
    rlutil::cls();

    marcoPantalla(60, 20);
    rlutil::setColor(4);
    rlutil::locate(25, 8);
    cout << "Eliminacion Sala" << endl;



    do
    {
        rlutil::setColor(15);
        rlutil::locate(15, 10);
        cout << "Indique el id a eliminar: " << endl;

        rlutil::locate(41,10);
        cin.getline(aux,5);

        if (!validarNumeros(aux))
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            continue;
        }
        else if (servisala.buscarSala(atoi(aux)).GetIdSala() == -1)
        {
            rlutil::locate(25,26);
            cout << "no se encontro el id";
            rlutil::msleep(1500);
            cont++;
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            continue;
        }

        break;  //id encontrado

    }
    while (cont < 3);

    rlutil::locate(15,18);
    cout << "1- guardar    0- cancelar";

    do
    {

        rlutil::locate(5,26);
        cout << "Eleccion: ";
        cin >> eleccion;

        if (eleccion == 1)
        {
            servisala.eliminarSala(atoi(aux));
            rlutil::locate(25,26);
            cout << " eliminacion exitosa!!!";
            rlutil::msleep(1500);
        }
        else if (eleccion == 0)
        {
            rlutil::locate(25,26);
            cout << " se cancelo operacion!!!";
            rlutil::msleep(1500);
            return;
        }
        else
        {
            avisoError();
        }

    }
    while (eleccion < 0 || eleccion > 1);


}


void Pantallas::pReactivarSala()
{

    limpiarBuffer();
    ServicioSala servisala;
    rlutil::cls();
    if(!servisala.listarSalas(0))
    {

        return;
    }

    char aux[5];
    int eleccion, cont=0;
    cout<<endl<<endl;
    cout << "Reactivar Sala " << endl;

    do
    {

        cout << "Indique el id a reactivar: ";


        cin.getline(aux,5);

        if (!validarNumeros(aux))
        {

            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";

            continue;
        }
        else if (servisala.buscarSala(atoi(aux)).GetIdSala() == -1)
        {
            rlutil::locate(25,26);
            cout << "no se encontro el id";

            continue;
        }

        break;

    }
    while (cont < 3);

    cout << endl<<"1- guardar    0- cancelar";

    do
    {


        cout <<endl<< "Eleccion: ";
        cin >> eleccion;
        if (eleccion == 1)
        {
            servisala.reactivarSala(atoi(aux));

            cout << " reactivacion exitosa!!!";
            rlutil::msleep(1500);
        }
        else if (eleccion == 0)
        {

            cout << " se cancelo operacion!!!";

            return;
        }
        else
        {
            avisoError();
        }

    }
    while (eleccion < 0 || eleccion > 1);


}


/////////////

bool Pantallas::pModificarSala()
{
    limpiarBuffer();

    bool salaUsada;
    int cont=0;
    char nombreSala[50], activo[5],tipoSala[5],capacidadSala[5], aux[5];


    ServicioSala serviSala;
    Sala sala;

    marcoPantalla(60, 20);

    rlutil::setColor(4);
    rlutil::locate(25, 8);
    cout << "Modificar Sala " << endl;


    do
    {

        rlutil::locate(10, 10);
        cout << "Indique el id: " << endl;
        rlutil::locate(25, 10);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {
            sala = serviSala.buscarSala(atoi(aux));

            if(sala.GetIdSala()>0 && sala.GetActivo()==true)
            {

                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "id no encontrado";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                  ";
                rlutil::locate(41,10);
                cout << "     ";
                rlutil::locate(25,10);
                cout << "     ";
                cont++;


            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            rlutil::locate(25,10);
            cout << "     ";

        }
        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }



    }
    while(cont<3);


    rlutil::setColor(15);
    rlutil::locate(10, 12);
    cout << "Nombre: " << sala.GetNombreSala() << endl;
    rlutil::msleep(500);

    rlutil::locate(10, 14);
    cout << "Activo: " << sala.GetActivo() << endl;
    rlutil::msleep(500);

    rlutil::locate(10, 16);
    cout << "Tipo Sala: " << sala.GetTipoSala() << endl;
    rlutil::msleep(500);

    rlutil::locate(10, 18);
    cout << "Capacidad sala: " << sala.GetCapacidadSala() << endl;
    rlutil::msleep(500);




    ServicioFuncion servifun;
    salaUsada= servifun.salaUsada(atoi(aux));


    ///modificando

    cont=0;
    rlutil::setColor(15);

    do
    {
        rlutil::locate(40, 12);
        cout << "Nombre: ";
        cin.getline(nombreSala, 50);

        if(validarTexto(nombreSala))
        {

            if (strlen(nombreSala) > 0)
            {
                sala.SetNombreSala(nombreSala);
                break;
            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar letras";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(48,12);
            cout << "                   ";
            cont++;

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }
    }
    while(cont<3);




    cont=0;

    do
    {

        rlutil::locate(40, 14);
        cout << "Activo: ";
        rlutil::locate(25, 26);
        cout<<"  0=NO , 1=SI";
        rlutil::locate(48, 14);
        cin.getline(activo,5);

        if(validarNumeros(activo))
        {

            int num=atoi(activo);

            if(num==1)
            {

                sala.SetActivo(1);
                break;

            }
            else if (num==0)
            {
                sala.SetActivo(0);
                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "eleccion incorrecta";
                rlutil::msleep(2000);
                rlutil::locate(25,26);
                cout << "                            ";
                cont++;
            }

        }
        else
        {

            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(2000);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(48, 14);
            cout<<"   ";
            cont++;
        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            return false;
        }
    }
    while(cont<3);




    rlutil::locate(25, 26);
    cout<<"                         ";

    /// tipo sala
    cont=0;

    do
    {
        rlutil::locate(40, 16);
        cout << "Tipo de sala: ";


        int tam = (sizeof(Sala::listaTipoSala) / sizeof(Sala::listaTipoSala[0]));

        rlutil::locate(25, 26);
        for(int i=0; i<tam; i++)
        {

            cout<<i+1<<":"<<Sala::listaTipoSala[i]<<" ";
        }

        rlutil::locate(54, 16);
        cin.getline(tipoSala,5);


        if(validarNumeros(tipoSala))
        {


            if (atoi(tipoSala) > 0 && atoi(tipoSala) <= tam)
            {
                sala.SetTipoSala(atoi(tipoSala) - 1);
                break;
            }
            else
            {

                rlutil::locate(25, 26);
                cout<<"                              "  ;


                rlutil::locate(25, 26);
                cout<<"eleccion incorrecta";
                rlutil::msleep(2000);
                rlutil::locate(25, 26);
                cout<<"                        ";
                rlutil::locate(54, 16);
                cout<<"            ";
                cont++;
            }



        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }

    }
    while(cont<3);


    rlutil::locate(25, 26);
    cout<<"                            " ;


    ///capacidad
    cont=0;

    if(!salaUsada)
    {


        do
        {

            rlutil::locate(40, 18);
            cout << "Capacidad: ";
            cin.getline(capacidadSala, 5);


            if(validarNumeros(capacidadSala))
            {
                int capacidad= atoi(capacidadSala);
                if (capacidad >0 && capacidad < 101)
                {
                    sala.SetCapacidadSala(capacidad);
                    break;
                }
                else
                {
                    rlutil::locate(25,26);
                    cout << "Capacidad debe ser entre 1 y 100";
                    rlutil::msleep(1500);
                    rlutil::locate(25,26);
                    cout << "                                ";
                    cont++;
                }


            }
            else
            {
                rlutil::locate(25,26);
                cout << "solo puede ingresar numeros";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                            ";
                rlutil::locate(41,10);
                cout << "     ";
                cont++;

            }

            if(cont==3)
            {
                rlutil::locate(25,26);
                cout << "se han ingresado varias veces mal se cancela la operacion";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                                          ";
                return false;
            }

        }
        while(cont<3);

    }
    else
    {

        rlutil::locate(40, 18);
        cout << "item no editable";
    }

    /////

    aux[0]='\0';
    cont=0;

    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            if(atoi(aux)==1)
            {


                return  serviSala.modificarSala(sala, sala.GetIdSala() - 1);
            }
            else if(atoi(aux)==0)
            {
                return false;
            }
            else
            {

                rlutil::locate(35,26);
                cout<<"eleccion incorrecta!!!!";
                rlutil::msleep(1500);
                rlutil::locate(30,26);
                cout<<"                    ";
                cont++;

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;

        }

    }
    while(cont<3);
}



void Pantallas::pBuscarFuncionId()
{
    limpiarBuffer();

    servicioPelicula servipeli;
    ServicioSala servisala;

    int cont=0;
    char aux[5];
    ServicioFuncion servifun;
    Funcion fun;

    marcoPantalla(60,20);

    rlutil::setColor(4);
    rlutil::locate(25,6);
    cout<<"Buscar Funcion "<<endl;

    do
    {
        rlutil::locate(10,8);
        cout<<"Indique el id : "<<endl;
        rlutil::locate(26,8);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            fun= servifun.buscarPorId(atoi(aux));
            break;

        }
        else
        {
            rlutil::setColor(15);
            rlutil::locate(15,16);
            cout<<"solo puede ingresar numero!!"<< endl;
            rlutil::msleep(2000);
            rlutil::locate(15,16);
            cout<<"                             ";
            cont++;
        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(2000);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return;
        }

    }
    while(cont<3);

    if(fun.GetIdFuncion()>0)
    {

        rlutil::setColor(15);
        rlutil::locate(15,10);
        cout <<"Sala: "<< servisala.buscarSala(fun.GetIdSala()).GetNombreSala() <<endl;

        rlutil::msleep(500);

        rlutil::locate(15,12);
        cout<<"Pelicula: "<< servipeli.buscarPeliculaPorId(fun.GetIdPelicula()).GetNombrePelicula()<<endl;
        //rlutil::locate(26,14);
        rlutil::msleep(500);

        rlutil::locate(15,14);
        cout <<"Cantidad Butacas: "<< fun.GetcantidadAsientos()<<endl;
        //rlutil::locate(26,16);
        rlutil::msleep(500);

        rlutil::locate(15,16);
        cout <<"Hora: ";
        fun.GetFecha().mostrarHora();
        cout<< endl;
        rlutil::msleep(500);

        rlutil::locate(15,18);
        cout <<"Fecha: ";
        fun.GetFecha().mostrarFecha();
        cout<<endl;
        rlutil::msleep(500);

        rlutil::locate(15,20);
        cout <<"Asientos diponibles: "<<fun.contadorAsientosDisponibles()<<endl;
        rlutil::msleep(500);

        rlutil::locate(15,22);
        cout <<"activo:"<<(fun.GetActiva()? "si": "No")<<endl;
        rlutil::msleep(500);



        rlutil::locate(5,26);
        cout<<"presione cualquier tecla para continuar....."<< endl;
        rlutil::anykey();

    }
    else
    {
        rlutil::setColor(15);
        rlutil::locate(15,16);
        cout<<"El id buscado es incorrecto!!"<< endl;
        rlutil::msleep(2000);
    }


}



bool Pantallas::pModificarFuncion()
{


    limpiarBuffer();

    servicioPelicula servipeli;
    ServicioSala servisala;


    int cont=0;
    char aux[5];
    ServicioFuncion servifun;
    Funcion fun;

    marcoPantalla(62,20);

    rlutil::setColor(4);
    rlutil::locate(25,6);
    cout<<"modificar Funcion "<<endl;

    do
    {


        rlutil::locate(10,8);
        cout<<"Indique id de funcion: "<<endl;
        rlutil::locate(33,8);
        cin.getline(aux,5);


        if(validarNumeros(aux))
        {
            fun= servifun.buscarPorId(atoi(aux));

            if(fun.GetIdFuncion()>0 && fun.GetActiva()==true )
            {

                break;
            }
            else
            {
                rlutil::locate(25,26);
                cout << "id incorrecto intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                  ";
                rlutil::locate(41,8);
                cout << "     ";
                rlutil::locate(33,8);
                cout << "     ";
                cont++;


            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,8);
            cout << "     ";
            cont++;
            rlutil::locate(33,8);
            cout << "     ";

        }


        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false ;
        }


    }
    while(cont<3);

    ///mostrar

    rlutil::setColor(15);
    rlutil::locate(15,10);
    cout <<"Id Sala: "<< fun.GetIdSala()<<endl;

    rlutil::msleep(500);

    rlutil::locate(15,12);
    cout<<"Id Pelicula: "<< fun.GetIdPelicula()<<endl;
    //rlutil::locate(26,14);
    rlutil::msleep(500);

    rlutil::locate(15,14);
    cout <<"Cantidad Butacas: "<< fun.GetcantidadAsientos()<<endl;
    //rlutil::locate(26,16);
    rlutil::msleep(500);


    rlutil::locate(15,16);
    cout <<"Fecha: ";
    fun.GetFecha().mostrarFecha();
    cout<<endl;
    rlutil::msleep(500);


    rlutil::locate(15,18);
    cout <<"Hora: ";
    fun.GetFecha().mostrarHora();
    cout<< endl;
    rlutil::msleep(500);



    rlutil::locate(15,20);
    cout <<"activo:"<<(fun.GetActiva()? "si": "No")<<endl;
    rlutil::msleep(500);


// modificar
    bool usado;

    int asientosDisponibles = fun.contadorAsientosDisponibles();

    if( asientosDisponibles == fun.GetcantidadAsientos())
    {

        usado = false;
    }
    else
    {
        usado = true;
    }


    cont=0;
    aux[0]='\0';

    if(!usado)
    {


        do
        {
            rlutil::setColor(15);
            rlutil::locate(40,10);
            cout<<"Id Sala: ";
            cin.getline(aux,5);

            if(validarNumeros(aux))
            {
                Sala sala= servisala.buscarSala(atoi(aux));

                if(sala.GetIdSala()>0 && sala.GetActivo()== true)
                {
                    fun.SetIdSala(atoi(aux));
                    fun.reiniciarVasientosDisponibles(sala.GetCapacidadSala());
                    fun.SetCantidadAsientos(sala.GetCapacidadSala());
                    break;
                }
                else
                {
                    rlutil::locate(25,26);
                    cout << "id incorrecto intente nuevamente";
                    rlutil::msleep(1500);
                    rlutil::locate(25,26);
                    cout << "                                  ";
                    rlutil::locate(49,10);
                    cout << "     ";
                    cont++;
                }

            }
            else
            {
                rlutil::locate(25,26);
                cout << "solo puede ingresar numeros";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                            ";
                rlutil::locate(49,10);
                cout << "                   ";
                cont++;

            }

            if(cont==3)
            {
                rlutil::locate(25,26);
                cout << "se han ingresado varias veces mal se cancela la operacion";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                                          ";
                return false;
            }


        }
        while(cont<3);

    }
    else
    {

        rlutil::setColor(15);
        rlutil::locate(40,10);
        cout<<"Id Sala: Item no editable";
    }

/// pelicula

    cont=0;
    aux[0]='\0';


    do
    {
        rlutil::locate(40,12);
        cout<<"Id pelicula: ";
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            Pelicula peli= servipeli.buscarPeliculaPorId(atoi(aux));
            if(peli.GetIdPelicula()>0 && peli.GetActivo()== true)
            {

                fun.SetIdPelicula(atoi(aux));
                break;

            }
            else
            {
                rlutil::locate(25,26);
                cout << "id incorrecto intente nuevamente";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                 ";
                rlutil::locate(53,12);
                cout << "     ";
                cont++;
            }


        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                           ";
            rlutil::locate(53,12);
            cout << "         ";
            cont++;

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false ;
        }

    }
    while(cont<3);


///  cantidad butacas



    rlutil::locate(40,14);
    cout<<"Cantidad Butacas: "<< fun.GetcantidadAsientos();

/// Fecha
    char dia[5], mes[5], anio[5];
    Fecha f;
    cont=0;
    do
    {

        rlutil::msleep(600);
        rlutil::locate(40,16);
        cout<<"dia:";
        cin.getline(dia,5);
        rlutil::locate(46,16);
        cout<<" mes:";
        cin.getline(mes,5);
        rlutil::locate(53,16);
        cout<<" anio:";
        cin.getline(anio,5);

        if(validarNumeros(dia)&&validarNumeros(mes)&& validarNumeros(anio))
        {

            if( !validaFecha( atoi(dia), atoi(mes), atoi(anio)))
            {
                rlutil::locate(25,26);
                cout<<" fecha mal ingresado intente nuevamente";
                rlutil::locate(25,26);
                cout<<"                                        ";
                rlutil::locate(22,16);
                cout<<"      ";
                rlutil::locate(33,16);
                cout<<"      ";
                rlutil::locate(44,16);
                cout<<"      ";
                cont++;

            }
            else
            {
                f.SetDia(atoi(dia));
                f.SetMes(atoi(mes));
                f.SetAnio(atoi(anio));
                break;
            }
        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros intente nuevamente";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            cont++;
            rlutil::locate(22,16);
            cout<<"      ";
            rlutil::locate(33,16);
            cout<<"      ";
            rlutil::locate(44,16);
            cout<<"      ";

        }

        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }

    }
    while (cont<3);



/// Hora
    cont=0;
    aux[0]='\0';
    int hora, minuto;

    int tam= sizeof(Funcion::horarios) / sizeof(Funcion::horarios[0]);

    do
    {
        rlutil::locate(15,26);
        for(int i=0; i< tam; i++)
        {

            cout<<i +1 <<"/"<<Funcion::horarios[i]<<" ";
        }


        rlutil::locate(40,18);
        cout<<"Hora: ";
        cin.getline(aux,5);

        if (validarNumeros(aux))
        {

            int num = atoi(aux);

            if(num>0 && num<=tam)
            {

                convertidorHorario(Funcion::horarios[num-1], hora, minuto);
                Funcion funAux =fun;
                f.SetMinuto(minuto);
                f.SetHora(hora);
                funAux.SetFecha(f);

                if(!servifun.comprobarFechaHora(funAux))
                {

                    fun.SetFecha(f);
                    break;
                }
                else
                {

                    rlutil::locate(5,26);
                    cout << "                                                                        ";
                    rlutil::locate(25,26);
                    cout << "Horario no disponible";
                    rlutil::msleep(1500);
                    rlutil::locate(25,26);
                    cout << "                                               ";
                    cont++;
                    rlutil::locate(46,18);
                    cout<<"   ";

                }


            }
            else
            {
                rlutil::locate(5,26);
                cout << "                                                                        ";
                rlutil::locate(25,26);
                cout << "eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout << "                                               ";
                cont++;
                rlutil::locate(46,18);
                cout<<"   ";
            }

        }
        else
        {
            rlutil::locate(5,26);
            cout << "                                                                        ";
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros intente nuevamente";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                               ";
            cont++;
            rlutil::locate(46,18);
            cout<<"   ";
        }



        if(cont==3)
        {
            rlutil::locate(25,26);
            cout << "se han ingresado varias veces mal se cancela la operacion";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                                                          ";
            return false;
        }

    }
    while(cont<3);


    rlutil::locate(5,26);
    cout << "                                                                        ";


/// Activo

    rlutil::locate(40,20);
    cout<<"Activo: item no editable ";



/// guardar

    aux[0]='\0';
    cont=0;

    do
    {

        rlutil::locate(5,26);
        cout<<" 1-Guardar  0-Cancelar: ";

        rlutil::locate(30,26);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            if(atoi(aux)==1)
            {
                return  servifun.modificarFuncion( fun.GetIdFuncion()-1, fun);
            }
            else if(atoi(aux)==0)
            {
                rlutil::locate(25,26);
                cout<<"la operacion fue cancelada" ;
                rlutil::msleep(2000);
                return false ;
            }
            else
            {

                rlutil::locate(35,26);
                cout<<"eleccion incorrecta!!!!";
                rlutil::msleep(1500);
                rlutil::locate(30,26);
                cont++;
                cout<<"                                       ";
                rlutil::locate(5,26);
                cout << "                                                                        ";

            }

        }
        else
        {
            rlutil::locate(25,26);
            cout << "solo puede ingresar numeros";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout << "                            ";
            rlutil::locate(41,10);
            cout << "     ";
            cont++;
            rlutil::locate(5,26);
            cout << "                                                                        ";

        }

    }
    while(cont<3);



}


///venta





Venta Pantallas::pAgregarVenta()
{

    rlutil::cls();
    limpiarBuffer();

    ServicioVenta serviven;
    ServicioFuncion serviFun;
    ServicioCliente serviCli;
    ServicioEmpleado serviemple;
    ServicioSala servisala;
    servicioPelicula servipeli;

    Cliente cli;
    Funcion fun;
    Venta nuevaVenta;

    int cont=0;
    char dniCliente[10], idFuncion[5], cantidadEntradas[5], aux[5];

    rlutil::cls();
    rlutil::locate(25, 6);
    cout << "--- CREAR NUEVA VENTA ---" << endl;

/// cliente

    do
    {
        rlutil::locate(5, 8);
        cout << "Ingrese DNI Cliente: ";
        cin.getline(dniCliente,10);


        if (validarNumeros(dniCliente))
        {

            cli= serviCli.traerClientePorDni(atoi(dniCliente));

            if(cli.getidPersona()>0 && cli.getactivo()==true)
            {

                nuevaVenta.SetIdCliente(cli.getidPersona());
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"Cliente no encontrado, debe crear usuario primero";
                rlutil::msleep(2000);
                return Venta();

            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"ingrese solo numero";
            rlutil::msleep(2000);
            cont++;
            rlutil::locate(5,26);
            cout<<"                    ";
            rlutil::locate(21, 8);
            cout << "   ";
        }

        if(cont==3)
        {

            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mal, operacion cancelada";
            rlutil::msleep(2000);
            return Venta();

        }

    }
    while(cont<3);

    rlutil::locate(36, 8);


    cout<<endl<<endl;



// mostrar cliente
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(85,6);
    cout<<"--Detalle de venta-- ";
    rlutil::setBackgroundColor(rlutil::BLACK);

    rlutil::locate(70,8);
    cout << "Cliente: "<< serviCli.buscarClientePorId(nuevaVenta.GetIdCliente()).getnombre();


/// Empleado

    cont=0;


    Empleado emple = serviemple.empleadoRandom() ;

    if(emple.getidPersona()>0)
    {
        nuevaVenta.SetIdEmpleado(emple.getidPersona());
    }
    else
    {
        cout<<"no se encontraron empleados";
        rlutil::msleep(2000);
        return Venta();
    }

    rlutil::msleep(600);
    rlutil::locate(5,10);
    cout<<"Id Empleado: "<<nuevaVenta.GetIdEmpleado();

    rlutil::locate(20,10);

    cout<<endl;

    /// mostrar empleado
    rlutil::locate(70,9);
    cout<<"Empleado "<< emple.getnombre();




    /// funcion

    cont=0;
    do
    {
        rlutil::msleep(600);
        rlutil::locate(5,12);
        cout<<"Id Funcion: ";
        cin.getline(idFuncion,5);


        if (validarNumeros(idFuncion))
        {


            fun= serviFun.buscarPorId(atoi(idFuncion));

            if(fun.GetIdFuncion()>0 && fun.GetActiva()==true)
            {

                nuevaVenta.SetIdFuncion(fun.GetIdFuncion());

                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"funcion no encontrada, intente nuevamente";
                rlutil::msleep(2000);
                cont++;

            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"ingrese solo numero";
            rlutil::msleep(2000);
            cont++;
            rlutil::locate(21, 8);
            cout << "   ";
        }

        if(cont==3)
        {

            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mal, operacion cancelada";
            rlutil::msleep(2000);
            return Venta();

        }

    }
    while(cont<3);



    cout<<endl<<endl;


    /// mostrar funcion
    rlutil::msleep(500);
    rlutil::locate(70,10);
    cout<<"Pelicula: "<< servipeli.buscarPeliculaPorId(fun.GetIdPelicula()).GetNombrePelicula() ;

    rlutil::msleep(500);
    rlutil::locate(70,11);
    cout<<"Sala: "<< servisala.buscarSala(fun.GetIdSala()).GetNombreSala();

    rlutil::msleep(500);
    rlutil::locate(70,12);
    cout<<"Fecha: ";
    fun.GetFecha().mostrarFecha();

    rlutil::msleep(500);
    rlutil::locate(70,13);
    cout<<"Hora funcion: ";
    fun.GetFecha().mostrarHora();

    rlutil::msleep(500);
    rlutil::locate(70,14);
    cout<<"tipo Sala: "<< servisala.buscarSala(fun.GetIdSala()).GetTipoSala();

    rlutil::msleep(500);
    rlutil::locate(70,15);
    cout<<"Clasificacion: "<< servipeli.buscarPeliculaPorId(fun.GetIdPelicula()).GetClasificacion();

    rlutil::msleep(500);
    rlutil::locate(70,16);
    cout<<"Genero: "<<servipeli.buscarPeliculaPorId(fun.GetIdPelicula()).GetGenero();

    /// cantidad de entradas

    cont=0;
    do
    {
        rlutil::locate(5,14);
        cout<<"Cantidad de entradas: ";
        cin.getline(cantidadEntradas,5);



        if(validarNumeros(cantidadEntradas))
        {

            int disponibles= fun.contadorAsientosDisponibles();

            if(atoi(cantidadEntradas)>0 && atoi(cantidadEntradas)<= Venta::MAX_ASIENTOS)
            {

                if(atoi(cantidadEntradas)<=disponibles )
                {
                    nuevaVenta.SetCantidadEntradas(atoi(cantidadEntradas));


                    break;

                }
                else
                {

                    rlutil::locate(5,26);
                    cout<<"la cantidad de entradas excede a los disponibles, elija nuevamente";
                    rlutil::msleep(2000);
                    cont++;
                    rlutil::locate(5,26);
                    cout<<"                                                                  ";
                    rlutil::locate(27,14);
                    cout<<"           ";
                    continue;

                }

            }
            else
            {

                rlutil::locate(5,26);
                cout<<"modifique la cantidad ingresada";
                rlutil::msleep(2000);
                cont++;
                rlutil::locate(5,26);
                cout<<"                                                                  ";
                rlutil::locate(27,14);
                cout<<"           ";
                continue;



            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"ingrese solo numero";
            rlutil::msleep(2000);
            cont++;
            rlutil::locate(27,14);
            cout<<"           ";

        }
        if(cont==3)
        {

            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mal, operacion cancelada";
            rlutil::msleep(2000);
            return Venta();

        }

    }
    while(cont<3);


///  mostrar cantidad entradas
    rlutil::msleep(500);
    rlutil::locate(70,17);
    cout<<"Entradas: "<< nuevaVenta.GetCantidadEntradas();


///mostrar asientos disponibles

    rlutil::locate(15,30);



    rlutil::setColor(4);
    cout<< "X";
    rlutil::setColor(15);
    cout<<":ocupado  ";
    rlutil::setColor(2);
    cout<< "0";
    rlutil::setColor(15);
    cout<<":disponible";



    rlutil::locate(3,28);


    int* asientosdispo= fun.GetAsientosDisponibles();

    for (int j = 0; j < fun.GetcantidadAsientos(); j++)
    {

        if(asientosdispo[j]==0)
        {
            cout<<"[";
            rlutil::setColor(4);
            cout<< "X";
            rlutil::setColor(15);
            cout<<"]";

        }
        else if(asientosdispo[j]==1)
        {
            cout<<"[";
            rlutil::setColor(2);
            cout<< j+1;
            rlutil::setColor(15);
            cout<<"]";

        }

    }
    cout << endl;





///pedir asientos

    int cantEntradas= nuevaVenta.GetCantidadEntradas();


    int* eleccionAsiento = new int[cantEntradas];

    if(eleccionAsiento == nullptr)
    {
        cout<< " no se pudo reserver memoria";
        return Venta();
    }

    for(int j = 0; j < cantEntradas; j++)
    {
        eleccionAsiento[j] = -1;
    }


    cont=0;
    int numAsiento, contador=0;


    do
    {
        bool repetido=false;
        rlutil::locate(5,16);
        cout<<"indique numero de asiento " <<contador+1<<": ";
        rlutil::locate(34,16);
        cin.getline(aux,5);

        if(validarNumeros(aux))
        {

            numAsiento= atoi(aux);

            if( numAsiento>0 && numAsiento  <= fun.GetcantidadAsientos() )
            {


                for(int i=0; i<nuevaVenta.GetCantidadEntradas(); i++)
                {


                    if( eleccionAsiento[i]== numAsiento)
                    {

                        repetido= true;

                    }
                }


                if(repetido)
                {

                    rlutil::locate(5,30);
                    cout<<" asiento repetido " ;
                    rlutil::msleep(2000);
                    rlutil::locate(5,30);
                    cout<<"                       " ;
                    rlutil::locate(34,16);
                    cout<<"  " ;
                    cont++;

                }
                else if(fun.asientoDisponible(numAsiento))

                {

                    eleccionAsiento[contador]= numAsiento;
                    contador++;
                    rlutil::locate(34,16);
                    cout<<"  " ;

                }
                else
                {

                    rlutil::locate(5,26);
                    cout<<" asiento ocupado " ;
                    rlutil::msleep(2000);
                    rlutil::locate(5,26);
                    cout<<"                       " ;
                    rlutil::locate(34,16);
                    cout<<"  " ;
                    cont++;

                }



            }
            else
            {

                rlutil::locate(5,30);
                cout<<" fuera de rango " ;
                rlutil::msleep(2000);
                rlutil::locate(5,30);
                cout<<"                       " ;
                rlutil::locate(34,16);
                cout<<"  " ;
                cont++;

            }


        }
        else
        {

            rlutil::locate(5,30);
            cout<<"solo ingrese numero" ;
            rlutil::msleep(2000);
            rlutil::locate(5,30);
            cout<<"                       " ;
            rlutil::locate(34,16);
            cout<<"  " ;
            cont++;

        } //else primer if

        if(cont==3)
        {

            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mal, operacion cancelada";
            rlutil::msleep(2000);
            return Venta();

        }

    }
    while(contador < cantEntradas);


    nuevaVenta.SetNumeroAsiento(cantEntradas, eleccionAsiento);


    ///mostrar asientos


    rlutil::msleep(500);
    rlutil::locate(70,17);
    cout<<"asientos seleccionados: ";

    for(int i=0; i< nuevaVenta.GetCantidadEntradas(); i++)
    {

        cout<<"["<< eleccionAsiento[i]<<"] ";
    }
    delete[] eleccionAsiento;



    rlutil::locate(15,30);
    cout<<"                                       ";
    rlutil::locate(3,28);
    cout<<"                                                                                              ";


///Fecha actual


    Fecha fec;
    fec.fechaActual();
    nuevaVenta.Setfecha(fec);


// mostrar fecha actual

    rlutil::msleep(500);
    rlutil::locate(70,18);
    cout<<"Fecha actual: ";
    nuevaVenta.Getfecha().mostrarFecha();
    cout<<" ";
    nuevaVenta.Getfecha().mostrarHora();




/// precio total

    float total = serviven.PrecioVentaFinal(nuevaVenta);

    nuevaVenta.SetPrecioFinal(total);
    rlutil::locate(5,18);
    cout<< "precio unitarios bruto: "<<nuevaVenta.GetPrecio();

    rlutil::locate(5,20);
    cout<< "Total a pagar: "<<total;



/// mostrar precio final
    rlutil::msleep(500);
    rlutil::locate(70,19);
    cout << "TOTAL FINAL: $" << total << endl;




    // guardar/ confirmar venta
    cont=0 ;
    do
    {

        aux[0]='\0';

        rlutil::locate(15,22);
        cout <<"1:confirmar 0:Salir/Cancelar";

        rlutil::locate(5,26);
        cout<<"Eleccion: ";
        cin.getline(aux,50);

        if(validarNumeros(aux))
        {

            int num= atoi(aux);
            if(num==1)
            {
                serviven.crearVenta(nuevaVenta);
                fun.reservarAsientos(eleccionAsiento, nuevaVenta.GetCantidadEntradas());
                int posi= serviFun.buscarPosicionPorId(nuevaVenta.GetIdFuncion());
                serviFun.modificarFuncion(posi,fun);

                rlutil::locate(25,26);
                cout <<"se guardo corretamente!!";
                rlutil::msleep(1500);
                return nuevaVenta;

            }
            else if(num==0)
            {
                rlutil::locate(25,26);
                cout <<"se cancelado la operacion!!";
                rlutil::msleep(1500);
                return Venta();
            }
            else
            {
                rlutil::locate(25,26);
                cout <<"eleccion incorrecta";
                rlutil::msleep(1500);
                rlutil::locate(25,26);
                cout <<"                          ";
                cont++ ;
            }


        }
        else
        {
            rlutil::locate(25,26);
            cout <<"eleccion incorrecta";
            rlutil::msleep(1500);
            rlutil::locate(25,26);
            cout <<"                     ";


        }

    }
    while(cont<3);

}










void Pantallas::pBuscarVentaId()
{

    ServicioVenta serviVen;

    ServicioCliente serviCli;

    ServicioFuncion serviFun;

    servicioPelicula serviPeli;

    ServicioSala serviSala;

    ServicioEmpleado serviEmple;



    char aux[50];

    int conta2 = 0;



    rlutil::cls();

    rlutil::locate(30, 3);

    cout << "--- BUSCAR VENTA POR ID ---" << endl;



    int idVenta;





    do
    {

        rlutil::locate(30, 5);

        cout << "Ingrese ID de la Venta a buscar:         ";

        rlutil::locate(63, 5);

        cin.ignore();

        cin.getline(aux, 50);



        if (!validarNumeros(aux))
        {

            rlutil::locate(30, 7);

            cout << "Error: Solo numeros.";

            rlutil::msleep(1000);

            rlutil::locate(30, 7);

            cout << "                    ";

            conta2++;

        }
        else
        {

            break;

        }

    }
    while (conta2 < 3);



    if (conta2 == 3) return;



    idVenta = atoi(aux);



    Venta venta = serviVen.buscarVentaPorId(idVenta); //



    if (venta.GetIdVenta() <= 0)
    {

        rlutil::locate(30, 9);

        cout << "No se encontro ninguna venta con el ID: " << idVenta;

        rlutil::anykey();

        return;

    }



    Cliente cli = serviCli.buscarClientePorId(venta.GetIdCliente());

    Funcion fun = serviFun.buscarPorId(venta.GetIdFuncion()); //





    Pelicula peli;

    Sala sala;

    if (fun.GetIdFuncion() > 0)
    {

        peli = serviPeli.buscarPeliculaPorId(fun.GetIdPelicula()); //

        sala = serviSala.buscarSala(fun.GetIdSala());              //

    }



    Empleado emple = serviEmple.buscarEmpleadoPorId(venta.GetIdEmpleado()); //





    rlutil::cls();

    rlutil::locate(30, 3);

    cout << "--- DETALLE DE VENTA #" << venta.GetIdVenta() << " ---" << endl;



    rlutil::locate(30, 5);

    cout << "CLIENTE:   " << cli.getnombre() << " " << cli.getapellido() << " (DNI: " << cli.getdniPersona() << ")" << endl;



    rlutil::locate(30, 6);

    cout << "EMPLEADO:  " << emple.getnombre() << " " << emple.getapellido() << endl;



    rlutil::locate(30, 8);

    cout << "PELICULA:  " << peli.GetNombrePelicula() << endl;



    rlutil::locate(30, 9);

    cout << "SALA:      " << sala.GetNombreSala() << " (" << sala.GetTipoSala() << ")" << endl;



    rlutil::locate(30, 10);

    cout << "FECHA:     ";

    venta.Getfecha().mostrarFecha();

    cout << "  HORA: ";

    venta.Getfecha().mostrarHora();

    cout << endl;



    rlutil::locate(30, 12);

    cout << "CANTIDAD ENTRADAS: " << venta.GetCantidadEntradas() << endl;



    rlutil::locate(30, 13);

    cout << "ASIENTOS: ";

    int* asientos = venta.GetNumeroAsiento();

    for(int i=0; i < venta.GetCantidadEntradas(); i++)
    {

        cout << "[" << asientos[i] + 1 << "] ";

    }

    cout << endl;



    rlutil::locate(30, 15);

    float total = venta.GetPrecioFinal();

    cout << "TOTAL ABONADO: $" << total << endl;



    rlutil::locate(30, 18);

    cout << "Presione una tecla para volver...";

    rlutil::anykey();

}




bool Pantallas::pModificarVenta()
{

    ServicioVenta serviVen;

    ServicioCliente serviCli;

    ServicioFuncion serviFun;

    char aux[50];

    int conta2 = 0;



    rlutil::cls();

    rlutil::locate(30, 3);

    cout << "--- MODIFICAR VENTA COMPLETA ---" << endl;



    int idVenta;

// Verificacion ID venta

    do
    {

        rlutil::locate(30, 5);

        cout << "Ingrese ID de la Venta a modificar:      ";

        rlutil::locate(66, 5);

        cin.getline(aux, 50);

        cin.ignore();



        if (!validarNumeros(aux))
        {

            rlutil::locate(30, 7);

            cout << "Error: Solo numeros.";

            rlutil::msleep(1000);

            rlutil::locate(30, 7);

            cout << "                     ";

            conta2++;

        }
        else
        {

            break;

        }

    }
    while (conta2 < 3);



    if (conta2 == 3) return false;



    idVenta = atoi(aux);



    int cantVentas = serviVen.contadorVentas();

    int posVenta = -1;

    Venta venta;



    for(int i=0; i<cantVentas; i++)
    {

        Venta v = serviVen.buscarPosicionVenta(i);

        if(v.GetIdVenta() == idVenta)
        {

            venta = v;

            posVenta = i;

            break;

        }

    }



    if (posVenta == -1)
    {

        rlutil::locate(30, 8);

        cout << "Error: Venta no encontrada.";

        rlutil::msleep(2000);

        return false;

    }

// info anterior

    rlutil::locate(30, 8);

    cout << "Venta Actual -> Cliente ID: " << venta.GetIdCliente()

         << " | Func ID: " << venta.GetIdFuncion()

         << " | Entradas: " << venta.GetCantidadEntradas() << endl;



    bool huboCambios = false;





    rlutil::locate(30, 10);

    cout << "Desea modificar el Cliente? (S/N): ";

    char opc;

    cin >> opc;

    cin.ignore();

// dni nuevo

    if (toupper(opc) == 'S')
    {

        conta2 = 0;

        aux[0] = '\0';

        rlutil::locate(30, 12);

        cout << "Ingrese NUEVO DNI del Cliente: ";



        int nuevoDni;

        do
        {

            rlutil::locate(60, 12);

            cin.getline(aux, 50);

            if (!validarNumeros(aux))
            {

                conta2++;

            }
            else
            {

                break;

            }

        }
        while (conta2 < 3);



        if (conta2 < 3)
        {

            nuevoDni = atoi(aux);

            int cant = serviCli.contadorClientes();

            int id = -1;



            for(int i=0; i<cant; i++)
            {

                Cliente c = serviCli.buscarPosicionCliente(i);

                if(c.getdniPersona() == nuevoDni)
                {

                    id = c.getidPersona();

                    break;

                }

            }



            if(id != -1)
            {

                venta.SetIdCliente(id);

                huboCambios = true;

                rlutil::locate(30, 14);

                cout << "Cliente actualizado correctamente.";

            }
            else
            {

                rlutil::locate(30, 14);

                cout << "Error: Cliente no encontrado. Se mantiene el anterior.";

            }

        }

    }



// nueva funcion

    rlutil::locate(30, 16);

    cout << "Desea cambiar Funcion/Asientos? (S/N): ";

    cin >> opc;

    cin.ignore();



    if (toupper(opc) == 'S')
    {

        rlutil::cls();

        rlutil::locate(30, 3);

        cout << "--- CAMBIO DE FUNCION / ASIENTOS ---" << endl;



        int idViejo = venta.GetIdFuncion();

        int posVieja = serviFun.buscarPosicionPorId(idViejo);

        Funcion viejaFuncion = serviFun.buscarPosicionFuncion(posVieja);



        int nuevoId;



        rlutil::locate(30, 20);

        cout << "Ingrese ID de la NUEVA Funcion (puede ser la misma): ";

        cin >> nuevoId;

        cin.ignore();



        int nuevaPos = serviFun.buscarPosicionPorId(nuevoId);

        if (nuevaPos == -1)
        {

            rlutil::locate(30, 22);

            cout << "Funcion invalida. Se cancela modificacion de asientos.";

            rlutil::msleep(2000);

            return false;

        }



        Funcion nuevaFuncion = serviFun.buscarPosicionFuncion(nuevaPos);



        int* viejosAsientos = venta.GetNumeroAsiento();

        int* viejosAsientosFuncion = viejaFuncion.GetAsientosDisponibles();



        // devuelve los asientos viejos a desocupados

        for (int i = 0; i < venta.GetCantidadEntradas(); i++)
        {

            int aux = viejosAsientos[i];

            if(aux >= 0 && aux < viejaFuncion.GetcantidadAsientos())
            {

                viejosAsientosFuncion[aux] = 1;

            }

        }



        if (idViejo != nuevoId)
        {

            serviFun.modificarFuncion(posVieja, viejaFuncion);

        }
        else
        {

            nuevaFuncion = viejaFuncion;

        }



        rlutil::cls();

        rlutil::locate(30, 3);

        cout << "--- SELECCION DE NUEVOS ASIENTOS ---" << endl;

        cout << "Capacidad: " << nuevaFuncion.GetcantidadAsientos() << endl;



        int cantidadNueva;

        cout << "Ingrese Nueva Cantidad de Entradas: ";

        cin >> cantidadNueva;



        venta.SetIdFuncion(nuevoId);

        venta.SetCantidadEntradas(cantidadNueva);

        int* asientosVenta = venta.GetNumeroAsiento();

        int* nuevosAsientosFuncion = nuevaFuncion.GetAsientosDisponibles();



        for (int i = 0; i < cantidadNueva; i++)
        {

            int asientoIngresado;

            cout << "Asiento " << i + 1 << ": ";

            cin >> asientoIngresado;



            int asientoaux = asientoIngresado - 1;



            if (nuevosAsientosFuncion[asientoaux] == 0)
            {

                cout << "Error: Ocupado!" << endl;

                i--;
                continue;

            }

            bool repetido = false;

            for(int k=0; k<i; k++)
            {

                if(asientosVenta[k] == asientoaux) repetido=true;

            }

            if(repetido)
            {

                cout << "Repetido!" << endl;
                i--;
                continue;

            }



            asientosVenta[i] = asientoaux;

        }



        nuevaFuncion.reservarAsientos(asientosVenta, cantidadNueva);

        serviFun.modificarFuncion(nuevaPos, nuevaFuncion);



        huboCambios = true;

        rlutil::locate(30, 25);

        cout << "Asientos actualizados y reservados.";

        rlutil::msleep(1000);

    }



// verifiacion de guardado de ventas

    if (huboCambios)
    {

        Fecha f;

        f.fechaActual();

        venta.Setfecha(f);



        if (serviVen.modificarVenta(venta, posVenta))
        {

            rlutil::locate(30, 27);

            cout << "VENTA GUARDADA EXITOSAMENTE.";

            rlutil::msleep(1500);

            return true;

        }
        else
        {

            rlutil::locate(30, 27);

            cout << "Error al guardar en Ventas.dat";

            rlutil::msleep(1500);

            return false;

        }

    }
    else
    {

        rlutil::locate(30, 27);

        cout << "No hubo cambios para guardar.";

        rlutil::msleep(1500);

        return false;

    }

}




void Pantallas::pInformeVentasPorMes()
{
    limpiarBuffer();
    rlutil::cls();
    int cont=0;
    char mes[5], anio[5];
    ServicioVenta serviven;

    do
    {
        cout<<"ingrese mes en numero: ";
        cin.getline(mes,5);
        if(validarNumeros(mes))
        {

            if(atoi(mes)>0 && atoi(mes)<13 )
            {
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"fuera de rango";
                cont++;
                rlutil::locate(5,26);
                cout<<"                            ";
            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"solo debe ingresar numeros ";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";

        }

        if(cont==3)
        {
            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mas, se cancela la operacion";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";
            return;
        }


    }
    while(cont<3);

    // anio
    cont=0;

    do
    {
        cout<<"ingrese anio: ";
        cin.getline(anio,5);
        if(validarNumeros(anio))
        {

            if(atoi(anio)>2019 && atoi(anio)<2026 )
            {
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"fuera de rango";
                cont++;
                rlutil::locate(5,26);
                cout<<"                            ";
            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"solo debe ingresar numeros ";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";

        }

        if(cont==3)
        {
            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mas, se cancela la operacion";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";
            return;
        }


    }
    while(cont<3);



    float recaudacion= serviven.recaudacionMensual(atoi(mes), atoi(anio));



    cout<<"la recaducacion del mes " << atoi(mes)<< " del anio " << atoi(anio)<<" es:"<< recaudacion<<"$";

     rlutil::anykey();
}


void Pantallas::pInformeVentasPorAnio()
{
    rlutil::cls();
    ServicioVenta serviven;
    char anio[5], mes[5];
    int cont=0;


      do
    {
        cout<<"ingrese anio: ";
        cin.getline(mes,5);
        if(validarNumeros(mes))
        {

            if(atoi(mes)>0 && atoi(mes)<13 )
            {
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"fuera de rango";
                cont++;
                rlutil::locate(5,26);
                cout<<"                            ";
            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"solo debe ingresar numeros ";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";

        }

        if(cont==3)
        {
            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mas, se cancela la operacion";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";
            return;
        }


    }
    while(cont<3);




    do
    {
        cout<<"ingrese anio: ";
        cin.getline(anio,5);
        if(validarNumeros(anio))
        {

            if(atoi(anio)>2019 && atoi(anio)<2026 )
            {
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"fuera de rango";
                cont++;
                rlutil::locate(5,26);
                cout<<"                            ";
            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"solo debe ingresar numeros ";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";

        }

        if(cont==3)
        {
            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mas, se cancela la operacion";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";
            return;
        }


    }
    while(cont<3);


    const char* mes2[12]= {"enero","febrero","marzo"," abril","mayo","junio","julio","agostos","septiembre","octubre","noviembre","diciembre"};

    float* reca= serviven.recaudacionAnual(atoi(anio));

    cout<<"la recaudacion del año "<< atoi(anio)<<"es:";
    for(int i=0; i<13; i++)
    {

        cout<<mes2[i]<< ":"<<reca[i]<<"$"<< endl;
    }



    rlutil::anykey();

}



void Pantallas::pInformeVentasPorFuncion()
{
    rlutil::cls();
    limpiarBuffer();

    ServicioVenta serviVen;
    ServicioFuncion serviFun;
    servicioPelicula serviPeli;
    ServicioSala serviSala;


    Funcion fun;

    char idFuncion[10];
    int cont = 0;
    int id = -1;
    float recaudacionTotal;

    cout << "--- RECAUDACION POR FUNCION ---";


    do
    {
        rlutil::msleep(600);
        rlutil::locate(15, 8);
        cout << "Ingrese ID de la Funcion: ";

        rlutil::locate(42, 8);
        cin.getline(idFuncion, 5);

        if (validarNumeros(idFuncion))
        {


            fun = serviFun.buscarPorId(atoi(idFuncion));

            if(fun.GetIdFuncion() > 0)
            {

                id = fun.GetIdFuncion();
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout << "Funcion no encontrada, intente nuevamente";
                rlutil::msleep(2000);
                rlutil::locate(5,26);
                cout << "                                         ";
                cont++;
                rlutil::locate(42, 8);
                cout << "    ";
            }

        }
        else
        {
            rlutil::locate(5,26);
            cout << "Ingrese solo numeros";
            rlutil::msleep(2000);
            rlutil::locate(5,26);
            cout << "                    ";
            cont++;
            rlutil::locate(42, 8);
            cout << "    ";
        }

        if(cont==3)
        {
            rlutil::locate(5,26);
            cout << "Se ingreso varias veces mal, operacion cancelada";
            rlutil::msleep(2000);
            return;
        }

    }
    while(cont < 3);


    Pelicula peli = serviPeli.buscarPeliculaPorId(fun.GetIdPelicula());
    Sala sala = serviSala.buscarSala(fun.GetIdSala());

    rlutil::locate(15, 10);
    cout << "Pelicula: " << peli.GetNombrePelicula();
    rlutil::locate(15, 11);
    cout << "Sala:     " << sala.GetNombreSala();
    rlutil::locate(15, 12);
    cout << "Fecha:    ";
    fun.GetFecha().mostrarFecha();

    recaudacionTotal = serviVen.recaudacionPorFuncion(id);

    rlutil::locate(15, 15);
    cout << "---------------------------------------";

    rlutil::locate(15, 17);
    cout << "TOTAL RECAUDADO:    $ " << recaudacionTotal;

    rlutil::locate(15, 19);
    cout << "---------------------------------------";

    rlutil::locate(20, 25);
    cout << "Presione cualquier tecla para volver...";
    rlutil::anykey();
}




void Pantallas::pInformeVentasPorEmpleado()
{
    limpiarBuffer();
     rlutil::cls();
    char id[5],mes[5], anio[5];
    int cont=0;
    ServicioEmpleado serviemple;

    do{
        cout<<"ingrese Id empleado: ";
        cin.getline(id,5);
        if(validarNumeros(id))
        {

        if(atoi(id)>0)
            {

                if( serviemple.buscarEmpleadoPorId(atoi(id)).getidPersona()>0)
                {

                    break;
                }
                else
                {
                    rlutil::locate(5,26);
                    cout<<"id no encontrado";
                    cont++;
                    rlutil::locate(5,26);
                    cout<<"         ";
                }



            }
            else
            {

                rlutil::locate(5,26);
                cout<<"fuera de rango";
                cont++;
                rlutil::locate(5,26);
                cout<<"         ";
            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"solo debe ingresar numeros ";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";

        }

        if(cont==3)
    {
        rlutil::locate(5,26);
            cout<<"se ingreso varias veces mas, se cancela la operacion";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";
            return;
        }


    }
    while(cont<3);

    //mes
    cont=0;

      do
    {
        cout<<"ingrese mes: ";
        cin.getline(mes,5);
        if(validarNumeros(mes))
        {

            if(atoi(mes)>0 && atoi(mes)<13 )
            {
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"fuera de rango";
                cont++;
                rlutil::locate(5,26);
                cout<<"                            ";
            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"solo debe ingresar numeros ";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";

        }

        if(cont==3)
        {
            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mas, se cancela la operacion";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";
            return;
        }


    }
    while(cont<3);


    //anio
    cont=0 ;

    do
    {
        cout<<"ingrese anio: ";
        cin.getline(anio,5);
        if(validarNumeros(anio))
        {

            if(atoi(anio)>2019 && atoi(anio)<2026 )
            {
                break;

            }
            else
            {
                rlutil::locate(5,26);
                cout<<"fuera de rango";
                cont++;
                rlutil::locate(5,26);
                cout<<"                            ";
            }


        }
        else
        {

            rlutil::locate(5,26);
            cout<<"solo debe ingresar numeros ";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";

        }

        if(cont==3)
        {
            rlutil::locate(5,26);
            cout<<"se ingreso varias veces mas, se cancela la operacion";
            cont++;
            rlutil::locate(5,26);
            cout<<"                            ";
            return;
        }


    }
    while(cont<3);



    ServicioVenta serviven;

    float recaudacion= serviven.recaudacionXempleado(atoi(id), atoi(mes), atoi(anio));

    cout<<"la recaudacion del mes es de: "<< recaudacion<<"$";
    rlutil::anykey();


}
