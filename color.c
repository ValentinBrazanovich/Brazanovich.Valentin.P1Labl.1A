#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

/** \brief carga la descripcion del color de bicicleta
 *
 * \param id int id del color de bicicleta
 * \param descripcion[] char descripcion del color de bicicleta
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int cargarDescripcionColor(int id, char descripcion[], eColor vecColor[], int tamC){
    int todoOk = 0;
    if(descripcion != NULL && vecColor != NULL && tamC > 0){
        for(int i = 0 ; i < tamC ; i++){
            if(vecColor[i].id == id){
                strcpy(descripcion, vecColor[i].nombreColor);
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief muestra los colores existentes
 *
 * \param vecColor[] eColor vector color
 * \param tam int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int mostrarColores(eColor vecColor[], int tam){
    int todoOk = 0;

    if(vecColor != NULL && tam > 0){
        system("cls");
        printf("**** Lista de colores ****\n\n");
        printf("id\t descripcion\n");
        for(int i = 0; i < tam; i++){
            printf("%d\t %s\n", vecColor[i].id, vecColor[i].nombreColor);
        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarColor(int* pIndice, int id, eColor vecColor[], int tamC){
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vecColor != NULL && tamC > 0){
        for(int i = 0 ; i < tamC ; i++){
            if(vecColor[i].id == id){
                indice = i;
                break;
            }
        }

        *pIndice = indice;

        todoOk = 1;
    }

    return todoOk;
}
