#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "tipo.h"
#include "color.h"

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material;

    int isEmpty; // 1 si esta vacio

} eBicicleta;

#endif // BICICLETA_H_INCLUDED


int inicializarBicicletas(eBicicleta vecBicicleta[], int tam);
int altaBicicleta(int* pId, eBicicleta vecBicicleta[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int cargarBicicleta(eBicicleta* pBicicleta, eTipo vecTipo[], int tam, eColor vecColor[], int tamC);
int buscarLibre(int* pIndice, eBicicleta vecBicicleta[], int tam);
int modificarBicicleta(eBicicleta vecBicicleta[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int mostrarBicicletas(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int mostrarBicicleta(eBicicleta bicicleta, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int buscarBicicleta(int* pIndice, int id, eBicicleta vecBicicleta[], int tam);
int bajaBicicleta(eBicicleta vecBicicleta[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int ordenarBicicletas(eBicicleta vecBicicleta[], int tam);
int mostrarBicicletasPorColor(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int mostrarBicicletasPorTipo(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int informarMasBicicletasCoA(eBicicleta vecBicicletas[], int tam);
int mostrarBicicletasSeparadasPorTipo(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int contarBicicletasPorTipoYColorIngresado(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC);
int mostrarColorConMasBicicletas(eBicicleta vecBicicletas[], int tam, eColor vecColor[], int tamC);
