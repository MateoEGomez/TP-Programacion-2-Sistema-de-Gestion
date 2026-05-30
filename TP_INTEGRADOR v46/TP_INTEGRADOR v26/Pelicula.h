#pragma once


class Pelicula {
public:
    Pelicula();


    static const char* listaGenero[5];
    static const char* listaClasificacion[3];


    int GetIdPelicula();
    const char* GetNombrePelicula();
    const char* GetDirector();
    const char* GetClasificacion();
    bool GetActivo();
    const char* GetGenero();


    void SetIdPelicula(int);
    void SetNombrePelicula(const char*);
    void SetDirector(const char*);
    void SetClasificacion(int);
    void SetActivo(bool);
    void SetGenero(int);




private:
    int _idpelicula;
    char _nombrePelicula[50];
    char _director [100];
    char _clasificacion[30];
    bool _activo;
    char _genero[50];
};

