#include "Cliente.h"
#include "Empleado.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Venta.h"

#pragma once

class Pantallas
{
public:
    Pantallas ();

    void marcoPantalla(int x, int y);
    void avisoError();
   // void limpiarBuffer();

    /// principal

    int menuPrincipal();

    /// menu
    int menuVentas();
    int menuAdmin();
    int menuInformes();

    /// 1er sub menu
    int menuAdministrarCliente();
    int menuAdministrarEmpleado();
    int menuAdminPeliculas();
    int menuAdministrarSala();
    int menuAdministrarFuncion();

    /// 2do sub-sub menu


    Cliente pAgregarCliente();
    void pEliminarCliente();
    void pBuscarClienteId();
    bool pModificarCliente();
    void  pReactivarCliente();


    Empleado pAgregarEmpleado();
     void pEliminarEmpleado();
     void pBuscarEmpleadoId();
     bool PModificarEmpleado();
     void pReactivarEmpleado();


    ///PELICULA
    Pelicula pAgregarPelicula();
    void pBuscarPeliculaId();
    bool pModificarPelicula();
    void pEliminarPelicula();
    void pReactivarPelicula();


    //salas

    Sala pAgregarSala();
    void pBuscarSalaPorId();

    void pEliminarSala();

    bool pModificarSala();
    void pReactivarSala();

    //funcion

    Funcion pAgregarFuncion();

    void pEliminarFuncion();
    void pReactivarFuncion();
    void pBuscarFuncionId();
    bool pModificarFuncion();


    //venta

    Venta pAgregarVenta();
    void pBuscarVentaId();
    bool pModificarVenta();



    //informes

    void pInformeVentasPorAnio();

    void pInformeVentasPorMes();

    void pInformeVentasPorFuncion() ;

    void pInformeVentasPorEmpleado();

};










