#pragma once
#include "Pelicula.h"
#include "Venta.h"
#include "Sala.h"
#include "Funcion.h"
#include "Cliente.h"
class ServicioVenta{
public:

    bool crearVenta(Venta v);
    int contadorVentas();
    Venta buscarPosicionVenta(int pos);
    bool listarVentas();
    Venta buscarVentaPorId(int idVenta);


    bool modificarVenta(Venta nuevaVenta, int pos);

    bool asignarAsientos(Funcion funcion, Venta venta);

    float CalcularPrecioTotal(int idVenta);

    float PrecioVentaFinal(Venta venta);


    float recaudacionMensual(int mes, int anio);

    float* recaudacionAnual(int anio);

    float recaudacionXempleado(int id, int mes, int aniob);

    float recaudacionPorFuncion(int idFuncion);



};
