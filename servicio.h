#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
//#include "trabajo.h"

typedef struct{
    int id;
    char descripcion[25];
    float precio;

} eServicio;

#endif // SERVICIO_H_INCLUDED

int mostrarServicios(eServicio vecServicio[], int tam);
int buscarServicio(int* pIndice, int id, eServicio vecServicio[], int tamS);
int cargarDescripcionServicio(int id, char descripcion[], eServicio vecServicio[], int tamS);
//int mostrarCostoBicicleta(eTrabajo vecTrabajos[], int tamT, eServicio vecServicio[], int tamS, eBicicleta vecBicicleta[], int tamB, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC);
