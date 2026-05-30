
#pragma once
#include <string>


 void resultadoAccion(bool respuesta);

 void marcoPantalla(int x, int y);

 void limpiarBuffer();

 int generacionId(int tipo);

 bool validarNumeros(const char* numero);

 bool validarTexto(const char* texto);

bool validaFecha(int dia, int mes, int anio);

int generacionLegajo();

bool validarHora( int hora, int minuto);

void convertidorHorario(const char* texto, int &hora, int &minuto);
