#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "validaciones.h"



/** \brief inicializa el trabajo
 *
 * \param vecTrabajo[] eTrabajo vector trabajo
 * \param tam int tamanio del vector trabajo
 * \return int retorna 1 si no hay error
 *
 */
int inicializarTrabajos(eTrabajo vecTrabajo[], int tam){
    int todoOk = 0;

    if(vecTrabajo != NULL && tam > 0){
        for(int i = 0 ; i < tam ; i++){
            vecTrabajo[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief da de alta un trabajo
 *
 * \param pId int* id
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tamB int tamanio vector bicicleta
 * \param vecTrabajos[] eTrabajo vector trabajos
 * \param tamTR int tamanio vector trabajos
 * \param vecTrabajo[] eTrabajo vector trabajo
 * \param tamT int tamanio vector trabajo
 * \param vecTipo[] eTipo vector tipo
 * \param tamTi int tamanio vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio vector color
 * \return int retorna 1 si no hay error
 *
 */
int altaTrabajo(int* pId, eBicicleta vecBicicleta[], int tamB, eTrabajo vecTrabajos[], int tamTR, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC, eServicio vecServicio[], int tamS){
    int todoOk = 0;
    int indice;
    int vacio;

    eTrabajo auxTrabajo;

    validarHayBicicleta(&vacio, vecBicicleta, tamB);
    if(pId != NULL && vecBicicleta != NULL && tamB > 0 && vecTrabajos != NULL && tamTR > 0 && vecTipo != NULL && tamTi > 0 && vecColor != NULL && tamC > 0 && vacio != 1){
        system("cls");
        printf("****  ALTA TRABAJO  ****\n");

        buscarLibreTrabajo(&indice, vecTrabajos, tamTR);

        if(indice == -1){
            printf("no hay lugar en el sistema\n");
        }else{
            mostrarBicicletas(vecBicicleta, tamB, vecTipo, tamTi, vecColor, tamC);

            auxTrabajo.id = *pId;

            cargarTrabajo(&auxTrabajo, vecBicicleta, tamB, vecServicio, tamS);

            vecTrabajos[indice] = auxTrabajo;

            auxTrabajo.isEmpty = 0;

            todoOk = 1;
        }
        *pId = *pId + 1;

        todoOk = 1;
    }else{
        printf("\nNo hay bicicletas\n");
    }

    return todoOk;
}


/** \brief busca un espacio libre en vector trabajo
 *
 * \param pIndice int* indice
 * \param vecTrabajo[] eTrabajo vector trabajo
 * \param tam int tamanio del vector trabajo
 * \return int retorna 1 si no hay error
 *
 */
int buscarLibreTrabajo(int* pIndice, eTrabajo vecTrabajo[], int tam){
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vecTrabajo != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(vecTrabajo[i].isEmpty){
                indice = i;
                break;
            }
        }

        *pIndice = indice;
        todoOk = 1;

    }

    return todoOk;
}


/** \brief
 *
 * \param pTrabajo eTrabajo* parametro tipo eTrabajo
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecServicio[] eServicio vector servicio
 * \param tamS int tamanio del vector servicio
 * \return int retorna 1 si no hay error
 *
 */
int cargarTrabajo(eTrabajo* pTrabajo, eBicicleta vecBicicleta[], int tam, eServicio vecServicio[], int tamS){
    int todoOk = 0;
    int auxIdBicicleta;
    int auxIdServicio;
    int auxDia;
    int auxMes;
    int auxAnio;
    int validacionB;
    int validacionS;
    int validacionF;

    if(pTrabajo != NULL){
        printf("Ingrese id de bicicleta: ");
        scanf("%d", &auxIdBicicleta);

        validarBicicleta(&validacionB, auxIdBicicleta, vecBicicleta, tam);
        while(validacionB == -1){
            printf("\n\nId de bicicleta no existente, reingresar: ");
            scanf("%d", &auxIdBicicleta);
        }
        pTrabajo->idBicicleta = auxIdBicicleta;

        mostrarServicios(vecServicio, tamS);
        printf("Ingrese id de servicio: ");
        scanf("%d", &auxIdServicio);

        validarServicio(&validacionS, auxIdServicio, vecServicio, tamS);
        while(validacionS == -1){
            printf("\n\nId de servicio no existente, reingresar: ");
            scanf("%d", &auxIdServicio);
            validarServicio(&validacionS, auxIdServicio, vecServicio, tamS);
        }
        pTrabajo->idServicio = auxIdServicio;

        printf("Ingrese fecha: ");
        printf("\ndia: ");
        scanf("%d", &auxDia);

        printf("\nmes: ");
        scanf("%d", &auxMes);

        printf("\nanio: ");
        scanf("%d", &auxAnio);

        validacionF = validarFecha(auxDia, auxMes, auxAnio);
        while(validacionF != 1){
            printf("\n\nFecha incorrecta, reingresar: ");
            printf("\ndia: ");
            scanf("%d", &auxDia);

            printf("\nmes: ");
            scanf("%d", &auxMes);

            printf("\nanio: ");
            scanf("%d", &auxAnio);

            validacionF = validarFecha(auxDia, auxMes, auxAnio);
        }

        pTrabajo->fecha.dia = auxDia;
        pTrabajo->fecha.mes = auxMes;
        pTrabajo->fecha.anio = auxAnio;

        pTrabajo->isEmpty = 0;

        todoOk = 1;
    }

    return todoOk;
}


/** \brief Muestra los trabajos
 *
 * \param vecTrabajos[] eTrabajo vector trabajos
 * \param tam int tamanio del vector trabajos
 * \param vecServicio[] eServicio vector servicio
 * \param tamS int tamanio del vector servicio
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo vecTrabajos[], int tam, eServicio vecServicio[], int tamS){
    int todoOk = 0;
    int vacio;


    validarHayTrabajo(&vacio, vecTrabajos, tam);
    if(vecTrabajos != NULL && tam > 0 && vacio != 1){
        system("cls");

        printf("**** Lista de trabajos ****\n");
        printf("id   idBicicleta    Servicio   Fecha\n");
        for(int i = 0 ; i < tam ; i++){
            if(!vecTrabajos[i].isEmpty){
                mostrarTrabajo(vecTrabajos[i], vecServicio, tamS);
            }
        }

        todoOk = 1;
    }else{
            printf("\n\nNo hay trabajos en el sistema.\n\n");
    }

    return todoOk;
}


/** \brief muestra un trabajo
 *
 * \param trabajo eTrabajo tipo de dato eTrabajo
 * \param vecServicio[] eServicio vector servicio
 * \param tamS int tamanio del vector servicio
 * \return int retorna 1 si no hay error
 *
 */
int mostrarTrabajo(eTrabajo trabajo, eServicio vecServicio[], int tamS){
    int todoOk = 0;
    char servicio[20];

    if(trabajo.isEmpty == 0){
        cargarDescripcionServicio(trabajo.idServicio, servicio, vecServicio, tamS);

        printf("%d    %1d           %5s     %d/%d/%d\n", trabajo.id, trabajo.idBicicleta, servicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
        todoOk = 1;
    }

    return todoOk;
}


/** \brief hardcodea trabajos
 *
 * \param pId int* id del trabajo
 * \param vecTrabajo[] eTrabajo vector trabajo
 * \param tamTr int tamanio vector trabajo
 * \param cant int cantidad de trabajos que se hardcodearan
 * \return int retorna 1 si no hay error
 *
 */
int hardcodearTrabajos(int* pId, eTrabajo vecTrabajo[], int tamTr, int cant){
    int todoOk = 0;

    eTrabajo almacenTrabajo[] = {
        {2000, 1, 20000, {26, 6, 2022}, 0},
        {2001, 1, 20001, {26, 7, 2022}, 0},
        {2002, 1, 20003, {22, 6, 2022}, 0},
        {2003, 2, 20002, {12, 2, 2022}, 0}
    };


    if(vecTrabajo != NULL && tamTr > 0 && cant <= tamTr && cant <= 3){
        for(int i = 0 ; i < cant ; i++){
            vecTrabajo[i] = almacenTrabajo[i];
            *pId = *pId + 1;
        }
        todoOk = 1;
    }

    return todoOk;
}


/** \brief Muestra trabajos por la bicicleta especificada
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
int mostrarTrabajosPorBicicleta(eTrabajo vecTrabajos[], int tamT, eServicio vecServicio[], int tamS, eBicicleta vecBicicleta[], int tamB, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC){
    int todoOk = 0;
    int flag = 1;
    int idBicicleta;
    int validacionB;
    int vacio;

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
            printf("\n\n**** Lista de Trabajos por bicicleta****\n\n");
            printf("id   idBicicleta      idServicio   Fecha\n");
            for(int i = 0 ; i < tamT ; i++){
                if(!vecTrabajos[i].isEmpty && vecTrabajos[i].idBicicleta == idBicicleta){
                    mostrarTrabajo(vecTrabajos[i], vecServicio, tamS);
                    flag = 0;
                }
            }
            printf("\n\n");

            if(flag){
                printf("Esa bicicleta no tiene trabajos.\n\n");
            }
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}


int mostrarServiciosPorFecha(eTrabajo vecTrabajos[], int tamT, eServicio vecServicio[], int tamS, eBicicleta vecBicicleta[], int tamB, eTipo vecTipo[], int tamTi, eColor vecColor[], int tamC){
    int todoOk = 0;
    int flag = 1;
    int dia;
    int mes;
    int anio;
    int validacion;
    int vacio;

    validarHayBicicleta(&vacio, vecBicicleta, tamT);
    if(vecBicicleta != NULL && tamT > 0 && vacio != 1){
        system("cls");

        mostrarTrabajos(vecTrabajos, tamT, vecServicio, tamS);
        printf("Ingrese fecha del trabajo: ");
        printf("\nDia:");
        scanf("%d", &dia);
        printf("\nMes:");
        scanf("%d", &mes);
        printf("\nAnio:");
        scanf("%d", &anio);

        validacion = validarFecha(dia, mes, anio);
        if(validacion == 0){
            printf("\nEsa fecha no existe\n");
        }else{

            printf("\n\n**** Lista de servicios por fecha****\n\n");
            printf("id   descripcion      precio\n");
            for(int i = 0 ; i < tamT ; i++){
                if(!vecTrabajos[i].isEmpty && vecTrabajos[i].fecha.dia == dia && vecTrabajos[i].fecha.mes == mes && vecTrabajos[i].fecha.anio == anio){
                    printf("%d\t %s \t $%.2f\n", vecServicio[i].id, vecServicio[i].descripcion, vecServicio[i].precio);
                    flag = 0;
                }
            }
            printf("\n\n");

            if(flag){
                printf("Esa bicicleta no tiene trabajos.\n\n");
            }
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;

}







