#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "fecha.h"
#include "servicio.h"

typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;

    int isEmpty;

} eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajos(eTrabajo vecTrabajo[], int tam);
int altaTrabajo(int* pId, eBicicleta vecBicicleta[], int tamB, eTrabajo vecTrabajoS[], int tamTR, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC, eServicio vecServicio[], int tamS);
int buscarLibreTrabajo(int* pIndice, eTrabajo vecTrabajo[], int tam);
int cargarTrabajo(eTrabajo* pTrabajo, eBicicleta vecBicicleta[], int tam, eServicio vecServicio[], int tamS);
int mostrarTrabajos(eTrabajo vecTrabajos[], int tam, eServicio vecServicio[], int tamS);
int mostrarTrabajo(eTrabajo trabajo, eServicio vecServicio[], int tamS);
int hardcodearTrabajos(int* pId, eTrabajo vecTrabajo[], int tamTr, int cant);
int mostrarTrabajosPorBicicleta(eTrabajo vecTrabajos[], int tamT, eServicio vecServicio[], int tamS, eBicicleta vecBicicleta[], int tamB, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC);
int mostrarServiciosPorFecha(eTrabajo vecTrabajos[], int tamT, eServicio vecServicio[], int tamS, eBicicleta vecBicicleta[], int tamB, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC);
