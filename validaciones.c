#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"



/** \brief Valida si el id del tipo ingresado existe
 *
 * \param validado int* es 1 si el tipo ingresado existe y -1 si no
 * \param idTipo int id del tipo
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \return int retorna 1 si no hay error
 *
 */
int validarTipo(int* validado, int idTipo, eTipo vecTipo[], int tamT){
    int indiceT;
    int todoOk;

    buscarTipo(&indiceT, idTipo, vecTipo, tamT);
    if(indiceT == -1){
        *validado = indiceT;
    }else{
        *validado = 1;
        todoOk = 1;
    }

    return todoOk;
}


/** \brief Valida si el di del color ingresado existe
 *
 * \param validado int* es 1 si el tipo ingresado existe y -1 si no
 * \param idColor int id del color
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int validarColor(int* validado, int idColor, eColor vecColor[], int tamC){
    int indiceC;
    int todoOk;

    buscarColor(&indiceC, idColor, vecColor, tamC);
    if(indiceC == -1){
        *validado = indiceC;
    }else{
        *validado = 1;
        todoOk = 1;
    }

    return todoOk;
}


/** \brief Valida si el id de la bicicleta ingresada existe
 *
 * \param validado int* es 1 si el tipo ingresado existe y -1 si no
 * \param idBicicleta int id del color
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tamB int tamanio del vector bicicleta
 * \return int retorna 1 si no hay error
 *
 */
int validarBicicleta(int* validado, int idBicicleta, eBicicleta vecBicicleta[], int tamB){
    int indiceB;
    int todoOk;

    buscarBicicleta(&indiceB, idBicicleta, vecBicicleta, tamB);
    if(indiceB == -1){
        *validado = indiceB;
    }else{
        *validado = 1;
        todoOk = 1;
    }

    return todoOk;
}


/** \brief valida si existen bicicletas en el vector bicicleta
 *
 * \param pVacio int* es 1 si no hay bicicletas
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \return int retorna 1 si no hay error
 *
 */
int validarHayBicicleta(int* pVacio, eBicicleta vecBicicleta[], int tam){
    int todoOk = 0;
    int vacio = 0;

    if(pVacio != NULL && vecBicicleta != NULL && tam > 0){
        for(int i = 0 ; i < tam ; i++){
            if(vecBicicleta[i].isEmpty){
                vacio++;
            }
        }

        if(vacio == tam){
            *pVacio = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief
 *
 * \param validado int* valida si el id del servicio ingresado existe
 * \param idServicio int id del servicio
 * \param vecServicio[] eServicio vector servicio
 * \param tamS int tamanio del vector servicio
 * \return int retorna 1 si no hay error
 *
 */
int validarServicio(int* validado, int idServicio, eServicio vecServicio[], int tamS){
    int indiceS;
    int todoOk;

    buscarServicio(&indiceS, idServicio, vecServicio, tamS);
    if(indiceS == -1){
        *validado = indiceS;
    }else{
        *validado = 1;
        todoOk = 1;
    }

    return todoOk;
}


/** \brief Valida si la fecha ingresada es correcta
 *
 * \param valorDia int dia
 * \param valorMes int mes
 * \param valorAnio int anio
 * \return int retorna 1 si no hay error
 *
 */
int validarFecha(int valorDia, int valorMes, int valorAnio){
    int todoOk = 0;
	int fechaCorrecta = 0;


    if(valorAnio > 2021 && valorAnio < 2024){
        if(valorMes > 0 && valorMes < 13){
            switch(valorMes){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if(valorDia > 0 && valorDia < 32){
                        fechaCorrecta = 1;
                    }
                    break;

                case 4:
                case 6:
                case 9:
                case 11:
                    if(valorDia > 0 && valorDia < 31){
                        fechaCorrecta = 1;
                    }
                    break;

                case 2:
                    if(valorDia > 0 && valorDia < 30){
                        fechaCorrecta = 1;
                    }
                    break;
            }
        }
    }

    if(fechaCorrecta){
        todoOk = 1;
    }

    return todoOk;
}


/** \brief Valida si hay trabajo
 *
 * \param pVacio int* es 1 si no hay trabajos
 * \param vecTrabajo[] eTrabajo vector trabajo
 * \param tam int tamanio vector trabajo
 * \return int retorna 1 si no hay error
 *
 */
int validarHayTrabajo(int* pVacio, eTrabajo vecTrabajo[], int tam){
    int todoOk = 0;
    int vacio = 0;

    if(pVacio != NULL && vecTrabajo != NULL && tam > 0){
        for(int i = 0 ; i < tam ; i++){
            if(vecTrabajo[i].isEmpty){
                vacio++;
            }
        }

        if(vacio == tam){
            *pVacio = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


