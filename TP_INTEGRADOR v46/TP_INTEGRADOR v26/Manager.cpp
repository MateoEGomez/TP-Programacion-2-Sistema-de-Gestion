
#include <iostream>
#include "Manager.h"
#include "Cliente.h"
#include "rlutil.h"
#include "MisFunciones.h"
#include "ServicioCliente.h"
#include "Empleado.h"
#include "ServicioEmpleado.h"
#include "Pantallas.h"
#include "ServicioSala.h"
#include "Sala.h"
#include "Pelicula.h"
#include "ServicioPelicula.h"
#include "ServicioFuncion.h"
#include "Venta.h"
#include "ServicioVenta.h"

using namespace std;

//cliente

void Manager:: m_crearCliente(){

    Pantallas panta;
    Cliente cli;

    cli= panta.pAgregarCliente();

}

void Manager::m_listarClientes(){

    ServicioCliente servi;

    rlutil::cls();
    servi.listarClientes(1);

    limpiarBuffer();
    rlutil::anykey();

}

void Manager::m_eliminarCliente(){

    Pantallas panta;
    panta.pEliminarCliente();


}

void Manager::m_buscarClienteId(){

    Pantallas panta;
    panta.pBuscarClienteId();


}

void Manager::m_modificarCliente(){
    ServicioCliente servicli;
    Pantallas panta;
    if(panta.pModificarCliente())
    {
        rlutil::locate(30,26);
        cout<<"modificado correctamente!!! "<<endl;
        rlutil::msleep(2000);
    }
    else
    {
        rlutil::locate(30,26);
        cout<<" operacion cancelada"<< endl;
        rlutil::msleep(2000);
    }
}

void Manager::m_reactivarCliente(){

    Pantallas panta;

    panta.pReactivarCliente();


}


/// empleado
void Manager::m_crearEmpleado(){

    Pantallas panta;
    Empleado emple;

    emple=panta.pAgregarEmpleado();

}

void Manager::m_listarEmpleados(){

    limpiarBuffer();
    ServicioEmpleado serviEmple;
    rlutil::cls();

    serviEmple.listarEmpleados(1);


    rlutil::anykey();

}

void Manager::m_eliminarEmpleado(){

    Pantallas panta;
    panta.pEliminarEmpleado();
}

//falta completar buscar
void Manager::m_buscarEmpleadoId(){
    Pantallas panta;
    panta.pBuscarEmpleadoId();


}

void Manager::m_modificarEmpleado(){
    ServicioEmpleado serviEmple;
    Pantallas panta;
    if(panta.PModificarEmpleado())
    {

        rlutil::locate(30,26);
        cout<<"modificado correctamente!!! "<<endl;
        rlutil::msleep(2000);
    }
    else
    {
        rlutil::locate(30,26);
        cout<<" no se pudo completar la modificacion"<< endl;
        rlutil::msleep(2000);
    }

}

void Manager::m_reactivarEmpleado(){

    Pantallas panta;

    panta.pReactivarEmpleado();

}

///pelicula



void Manager::m_crearPelicula(){

    Pantallas panta;
   // Pelicula peli;

    panta.pAgregarPelicula();

    //servicioPelicula serviPeli;

    /// muestro mesaje segun el resultado
    //resultadoAccion(serviPeli.guardarPelicula(peli));  ///

}


void Manager::m_listarPelicula(){
    limpiarBuffer();
    servicioPelicula serviPeli;

    rlutil::cls();
    serviPeli.listarPelicula(1);

    rlutil::anykey();
}

void Manager::m_buscarPeliculaId(){

    Pantallas panta;
    panta.pBuscarPeliculaId();

}


void Manager::m_modificarPelicula(){

    ServicioCliente servicli;
    Pantallas panta;
    if(panta.pModificarPelicula())
    {
        rlutil::locate(30,26);
        cout<<"modificado correctamente!!! "<<endl;
        rlutil::msleep(2000);
    }
    else
    {
        rlutil::locate(30,26);
        cout<<" no se pudo completar la modificacion"<< endl;
        rlutil::msleep(2000);
    }

}



void Manager::m_eliminarPelicula(){

    Pantallas panta;
    panta.pEliminarPelicula();

}


 void Manager::m_reactivarPelicula(){

    Pantallas panta;

    panta.pReactivarPelicula();

}


 void Manager::m_reservarAsientos(){
     ServicioFuncion serv;

    int idFuncion = 1;   // ← PRUEBA DIRECTA

    // 1. Buscar la función real
    Funcion fun = serv.buscarPorId(idFuncion);

    if (fun.GetIdFuncion() == -1) {
        cout << "La funcion con ID 1 no existe" << endl;
        return;
    }

    // 2. Asientos de prueba
    int seleccionados[3] = {10, 11, 13};

    // 3. Reservar
    fun.reservarAsientos(seleccionados, 3);

    int posi= serv.buscarPosicionPorId(1);

    // 4. Guardar cambios
    serv.modificarFuncion(posi,fun);

    cout << "Asientos reservados correctamente en la funcion ID 1" << endl;

    rlutil::msleep(1500);

 }





/// sala



void Manager::m_crearsala() {
    Pantallas panta;
    Sala sal = panta.pAgregarSala();



}



void Manager::m_listarSalas(){

    limpiarBuffer();
    ServicioSala serviSala;
    rlutil::cls();

    serviSala.listarSalas(1);


    rlutil::anykey();

}



void Manager::m_buscarSalaPorId(){

          Pantallas panta;
          panta.pBuscarSalaPorId();

          rlutil::anykey();
}


 void Manager::m_modificarSala() {
    ServicioSala serviSala;
    Pantallas panta;

    if (panta.pModificarSala()) {
        rlutil::locate(30, 26);
        cout << "Modificado correctamente!!!" << endl;
        rlutil::msleep(2000);
    } else {
        rlutil::locate(30, 26);
        cout << "operacion cancelada" << endl;
        rlutil::msleep(2000);
    }
}


void Manager::m_eliminarSala() {
    Pantallas panta;
    panta.pEliminarSala();
}


void Manager::m_reactivarSala(){
    Pantallas panta;
    panta.pReactivarSala();
}




///funcion

  void Manager::m_agregarFuncion(){
        Pantallas panta;
        Funcion fun = panta.pAgregarFuncion();
  }



 void Manager::m_listarFunciones() {

     limpiarBuffer();
    ServicioFuncion serviFun;

    rlutil::cls();
    serviFun.listarFunciones(1);

    rlutil::anykey();


 }


 void Manager::m_eliminarFuncion(){
    Pantallas panta;
    panta.pEliminarFuncion();
 }

 void Manager::m_reactivarFuncion() {
    Pantallas panta;
    panta.pReactivarFuncion();

 }


  void Manager::m_buscarFuncionId(){

    Pantallas panta;
    panta.pBuscarFuncionId();
  }


  void Manager::m_modificarFuncion(){
    Pantallas panta;
    panta.pModificarFuncion();
  }



 /// ventas
void Manager::m_agregarVenta() {

    Pantallas panta;
    Venta ven = panta.pAgregarVenta() ;


}


 void Manager::m_listarVentas(){

      ServicioVenta venta;
      venta.listarVentas();
      rlutil::anykey();

 }

 void Manager::m_modificarVenta() {

    Pantallas panta;

    panta.pModificarVenta();

 }

 void Manager::m_buscarVentaPorId() {

    Pantallas panta;

    panta.pBuscarVentaId();

}



void Manager::m_InformeVentasPorFuncion(){
    Pantallas panta;
    panta.pInformeVentasPorFuncion();

}

 void Manager::m_InformeVentasPorAnio(){
    Pantallas panta;
    panta.pInformeVentasPorAnio();
 }

 void Manager::m_InformeVentasPorMes(){
 Pantallas panta;
    panta.pInformeVentasPorMes();
 }

 void Manager::m_InformeVentasPorEmpleado(){
    Pantallas panta;
    panta.pInformeVentasPorEmpleado();
 }


