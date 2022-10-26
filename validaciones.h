#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "servicio.h"
#include "trabajo.h"

#endif // VALIDACIONES_H_INCLUDED



int validarTipo(int* validado, int idTipo, eTipo vecTipo[], int tamT);
int validarColor(int* validado, int idColor, eColor vecColor[], int tamC);
int validarBicicleta(int* validado, int idBicicleta, eBicicleta vecBicicleta[], int tamB);
int validarServicio(int* validado, int idServicio, eServicio vecServicio[], int tamS);
int validarFecha(int valorDia, int valorMes, int valorAnio);

int validarHayBicicleta(int* pVacio, eBicicleta vecBicicleta[], int tam);
int validarHayTrabajo(int* pVacio, eTrabajo vecTrabajo[], int tam);

