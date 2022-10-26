#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];

} eTipo;

#endif // TIPO_H_INCLUDED


int cargarDescripcionTipo(int id, char descripcion[], eTipo vecTipo[], int tamT);
int mostrarTipos(eTipo vecTipo[], int tam);
int buscarTipo(int* pIndice, int id, eTipo vecTipo[], int tamT);
