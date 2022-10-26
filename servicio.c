#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"


/** \brief muestra los servicios existentes
 *
 * \param vecServicio[] eServicio vector servicis
 * \param tam int tamanio del vector servicio
 * \return int retorna 1 si no hay error
 *
 */
int mostrarServicios(eServicio vecServicio[], int tam){
    int todoOk = 0;

    if(vecServicio != NULL && tam > 0){
        system("cls");
        printf("**** Lista de servicios ****\n\n");
        printf("id\t descripcion \tprecios\n");
        for(int i = 0; i < tam; i++){
            printf("%d\t %s \t $%.2f\n", vecServicio[i].id, vecServicio[i].descripcion, vecServicio[i].precio);
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief busca el servicio especificado
 *
 * \param pIndice int* entero indice
 * \param id int id servicio
 * \param vecServicio[] eServicio vector servicio
 * \param tamS int tamanio del vector servicio
 * \return int retorna 1 si no hay error
 *
 */
int buscarServicio(int* pIndice, int id, eServicio vecServicio[], int tamS){
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vecServicio != NULL && tamS > 0){
        for(int i = 0 ; i < tamS ; i++){
            if(vecServicio[i].id == id){
                indice = i;
                break;
            }
        }

        *pIndice = indice;

        todoOk = 1;
    }

    return todoOk;
}


/** \brief carga la descripcion del servicio
 *
 * \param id int id del servicio
 * \param descripcion[] char descripcion del servicio
 * \param vecServicio[] eServicio vector servicio
 * \param tamS int tamanio del vector servicio
 * \return int retorna 1 si no hay error
 *
 */
int cargarDescripcionServicio(int id, char descripcion[], eServicio vecServicio[], int tamS){
    int todoOk = 0;
    if(descripcion != NULL && vecServicio != NULL && tamS > 0){
        for(int i = 0 ; i < tamS ; i++){
            if(vecServicio[i].id == id){
                strcpy(descripcion, vecServicio[i].descripcion);
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief Muestra el costo por los trabajos a la bicicleta especificada
 *
 * \param vecTrabajos[] eTrabajo vector trabajo
 * \param tamT int tamanio del vector trabajo
 * \param vecServicio[] eServicio vector servicio
 * \param tamS int tamanio del vector servicio
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tamB int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamTi int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
/*int mostrarCostoBicicleta(eTrabajo vecTrabajos[], int tamT, eServicio vecServicio[], int tamS, eBicicleta vecBicicleta[], int tamB, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC){
    int todoOk = 0;
    int flag = 1;
    int idBicicleta;
    int validacionB;
    int vacio;
    float totalCosto = 0;

    validarHayBicicleta(&vacio, vecBicicleta, tamT);
    if(vecBicicleta != NULL && tamT > 0 && vacio != 1){
        system("cls");

        mostrarBicicletas(vecBicicleta, tamB, vecTipo, tamTi, vecColor, tamC);
        printf("Ingrese id de la bicicleta: ");
        scanf("%d", &idBicicleta);

        validarBicicleta(&validacionB, idBicicleta, vecBicicleta, tamB);
        if(validacionB == -1){
            printf("\nEse id de bicicleta no existe\n");
        }else{
            for(int i = 0 ; i < tamT ; i++){
                if(!vecTrabajos[i].isEmpty && vecTrabajos[i].idBicicleta == idBicicleta){
                    totalCosto = totalCosto + vecServicio[i].precio;
                    flag = 0;
                }
            }
            printf("\n\n");

            if(flag){
                printf("Esa bicicleta no tiene trabajos.\n\n");
            }else{
                printf("El costo total por esa bicicleta es de $%.2f", totalCosto);
            }
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}*/
