#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


/** \brief carga la descripcion del tipo de bicicleta
 *
 * \param id int id del tipo de bicicleta
 * \param descripcion[] char descripcion del tipo de bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \return int retorna 1 si no hay error
 *
 */
int cargarDescripcionTipo(int id, char descripcion[], eTipo vecTipo[], int tamT){
    int todoOk = 0;
    if(descripcion != NULL && vecTipo != NULL && tamT > 0){
        for(int i = 0 ; i < tamT ; i++){
            if(vecTipo[i].id == id){
                strcpy(descripcion, vecTipo[i].descripcion);
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief muestra los tipos de bicicleta existentes
 *
 * \param vecTipo[] eTipo vector tipo
 * \param tam int tamanio del vector tipo
 * \return int retorna 1 si no hay error
 *
 */
int mostrarTipos(eTipo vecTipo[], int tam){
    int todoOk = 0;

    if(vecTipo != NULL && tam > 0){
        printf("**** Lista de Tipos ****\n\n");
        printf("id\t descripcion\n");
        for(int i = 0; i < tam; i++){
            printf("%d\t %s\n", vecTipo[i].id, vecTipo[i].descripcion);
        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarTipo(int* pIndice, int id, eTipo vecTipo[], int tamT){
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vecTipo != NULL && tamT > 0){
        for(int i = 0 ; i < tamT ; i++){
            if(vecTipo[i].id == id){
                indice = i;
                break;
            }
        }

        *pIndice = indice;

        todoOk = 1;
    }

    return todoOk;
}
