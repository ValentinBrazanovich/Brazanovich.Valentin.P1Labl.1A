#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "validaciones.h"

/** \brief inicializa las bicicletas
 *
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio de la cantidad de bicicletas que puede haber
 * \return int retorna 1 si no hay error
 *
 */
int inicializarBicicletas(eBicicleta vecBicicleta[], int tam){
    int todoOk = 0;

    if(vecBicicleta != NULL && tam > 0){

        for(int i = 0 ; i < tam ; i++){
            vecBicicleta[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief da de alta una bicicleta
 *
 * \param pId int* indice de la bicicleta
 * \param vecBicicleta[] eBicicleta eBicicleta vector bicicleta
 * \param tam int tamanio de la cantidad de bicicletas que puede haber
 * \return intretorna 1 si no hay error
 *
 */
int altaBicicleta(int* pId, eBicicleta vecBicicleta[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int indice;
    eBicicleta auxBicicleta;

    if(pId != NULL && vecBicicleta != NULL && tam > 0){
        system("cls");
        printf("**** Alta Bicicletas ****\n\n");

        buscarLibre(&indice, vecBicicleta, tam);

        if(indice == -1){
            printf("No hay lugar en el sistema\n");
        }else{
            cargarBicicleta(&auxBicicleta, vecTipo, tamT, vecColor, tamC);

            auxBicicleta.id = *pId;

            vecBicicleta[indice] = auxBicicleta;

            todoOk = 1;
        }

        *pId = *pId + 1;
    }

    return todoOk;
}


/** \brief busca si hay un espacio libre en el vector bicicleta
 *
 * \param pIndice int* indice de la bicicleta
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio de el vector bicicleta
 * \return int retorna 1 si no hay error
 *
 */
int buscarLibre(int* pIndice, eBicicleta vecBicicleta[], int tam){
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vecBicicleta != NULL && tam > 0){
        for(int i = 0 ; i < tam ; i++){
            if(vecBicicleta[i].isEmpty){
                indice = i;
                break;
            }
        }
        *pIndice = indice;

        todoOk = 1;
    }

    return todoOk;
}



/** \brief carga una bicicleta
 *
 * \param pBicicleta eBicicleta* parametro tipo eBicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int cargarBicicleta(eBicicleta* pBicicleta, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int auxIdTipo;
    int auxIdColor;
    int validacionT;
    int validacionC;
    char auxMaterial;

    if(pBicicleta != NULL){
        printf("Ingrese marca: ");
        fflush(stdin);
        scanf("%s", pBicicleta->marca);

        mostrarTipos(vecTipo, tamT);
        printf("Ingrese id tipo: ");
        scanf("%d", &auxIdTipo);

        validarTipo(&validacionT, auxIdTipo, vecTipo, tamT);
        while(validacionT == -1){
            printf("\nReingresar id tipo: ");
            scanf("%d", &auxIdTipo);
            validarTipo(&validacionT, auxIdTipo, vecTipo, tamT);
        }
        pBicicleta->idTipo = auxIdTipo;

        mostrarColores(vecColor, tamC);
        printf("Ingrese id color: ");
        scanf("%d", &auxIdColor);

        validarColor(&validacionC, auxIdColor, vecColor, tamC);
        while(validacionC == -1){
            printf("\nReingresar id color: ");
            scanf("%d", &auxIdColor);
            validarColor(&validacionC, auxIdColor, vecColor, tamC);
        }
        pBicicleta->idColor = auxIdColor;
        system("cls");

        printf("Ingrese material (c - carbono, a - aluminio): ");
        fflush(stdin);
        scanf("%c", &auxMaterial);

        while(auxMaterial != 'c' && auxMaterial != 'a'){
            printf("\nReingresar material (c - carbono, a - aluminio): ");
            fflush(stdin);
            scanf("%c", &auxMaterial);
        }
        pBicicleta->material = auxMaterial;

        pBicicleta->isEmpty = 0;

        todoOk = 1;
    }else{
        printf("\nError al cargar bicicleta");
    }

    return todoOk;
}


/** \brief modifica una bicicleta elegida
 *
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int modificarBicicleta(eBicicleta vecBicicleta[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int idBicicleta;
    int indice;
    int nuevoTipo;
    int vacio;
    int validacionT;
    char nuevaMarca[20];
    char confirma;

    validarHayBicicleta(&vacio, vecBicicleta, tam);
    if(vecBicicleta != NULL && tam > 0 && vacio != 1){
        system("cls");
        printf("**** Modificar Bicicleta ****\n\n");

        mostrarBicicletas(vecBicicleta, tam, vecTipo, tamT, vecColor, tamC);

        printf("Ingrese id de la bicicleta a modificar: ");
        scanf("%d", &idBicicleta);

        buscarBicicleta(&indice, idBicicleta, vecBicicleta, tam);
        if(indice == -1){
            printf("No existe una bicicleta con id: %d\n", idBicicleta);
        }else{
            printf("\n\n");
            mostrarBicicleta(vecBicicleta[indice], vecTipo, tamT, vecColor, tamC);
            mostrarTipos(vecTipo, tamT);
            printf("Ingrese nuevo id tipo: ");
            scanf("%d", &nuevoTipo);

            validarTipo(&validacionT, nuevoTipo, vecTipo, tamT);
            while(validacionT == -1){
                printf("No existe ese tipo, reingresar id: ");
                scanf("%d", &nuevoTipo);
                validarTipo(&validacionT, nuevoTipo, vecTipo, tamT);
            }

            printf("Ingrese nuevo nombre de marca: ");
            scanf("%s", nuevaMarca);

            printf("Confirma modificacion?: ");
            fflush(stdin);
            confirma = getchar();

            if(confirma == 's'){
                vecBicicleta[indice].idTipo = nuevoTipo;
                strcpy(vecBicicleta[indice].marca, nuevaMarca);
                printf("Modificacion exitosa.\n");
            }else{
                printf("Se ha cancelado la modificacion.\n");
            }
        }

        todoOk = 1;
    }else{
        printf("\nNo hay bicicletas\n");
    }

    return todoOk;
}


/** \brief muestra las bicicletas en pantalla
 *
 * \param vecBicicletas[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int mostrarBicicletas(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int flag = 1;

    if(vecBicicletas != NULL && tam > 0){
        system("cls");

        printf("**** Lista de Bicicletas ****\n");
        printf("id   Marca      Tipo   Color   Material\n");
        for(int i = 0 ; i < tam ; i++){
            if(!vecBicicletas[i].isEmpty){
                mostrarBicicleta(vecBicicletas[i], vecTipo, tamT, vecColor, tamC);
                flag = 0;
            }
        }
        printf("\n\n");

        if(flag){
            printf("No hay bicicletas en el sistema.\n\n");
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief ordena las bicicletas segun tipo y marca
 *
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \return int retorna 1 si no hay error
 *
 */
int ordenarBicicletas(eBicicleta vecBicicleta[], int tam){
    int todoOk = 0;
    eBicicleta aux;

    if(vecBicicleta != NULL && tam > 0){
       for(int i = 0 ; i < tam  - 1 ; i++){
            for(int j = i + 1 ; j < tam ; j++){
                if(vecBicicleta[i].idTipo > vecBicicleta[j].idTipo && strcmp(vecBicicleta[i].marca, vecBicicleta[j].marca) > 0){
                    aux = vecBicicleta[i];
                    vecBicicleta[i] = vecBicicleta[j];
                    vecBicicleta[j] = aux;
                }
            }
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief muestra una bicicleta
 *
 * \param bicicleta eBicicleta tipo de dato bicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int
 *
 */
int mostrarBicicleta(eBicicleta bicicleta, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    char tipo[20];
    char color[20];

    if(vecTipo != NULL && tamT > 0 && vecColor != NULL && tamC > 0){
        cargarDescripcionTipo(bicicleta.idTipo, tipo, vecTipo, tamT);
        cargarDescripcionColor(bicicleta.idColor, color, vecColor, tamC);

        printf("%d    %1s    %5s     %2s   %c\n", bicicleta.id, bicicleta.marca, tipo, color, bicicleta.material);
        todoOk = 1;
    }

    return todoOk;
}


/** \brief busca una bicicleta en especifico
 *
 * \param pIndice int* indice a buscar
 * \param id int id de la bicicleta
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \return int retorna 1 si no hay error
 *
 */
int buscarBicicleta(int* pIndice, int id, eBicicleta vecBicicleta[], int tam){
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vecBicicleta != NULL && tam > 0){
        for(int i = 0 ; i < tam ; i++){
            if(!vecBicicleta[i].isEmpty && vecBicicleta[i].id == id){
                indice = i;
                break;
            }
        }

        *pIndice = indice;

        todoOk = 1;
    }

    return todoOk;
}


/** \brief da de baja una bicicleta
 *
 * \param vecBicicleta[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int bajaBicicleta(eBicicleta vecBicicleta[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    int vacio;

    validarHayBicicleta(&vacio, vecBicicleta, tam);
    if(vecBicicleta != NULL && tam > 0 && vacio != 1){
        system("cls");
        printf("**** Baja Bicicleta ****\n\n");

        mostrarBicicletas(vecBicicleta, tam, vecTipo, tamT, vecColor, tamC);

        printf("Ingrese id a dar de baja: ");
        scanf("%d", &id);

        buscarBicicleta(&indice, id, vecBicicleta, tam);
        if(indice == -1){
            printf("No existe una bicicleta con id: %d\n", id);
        }else{
            mostrarBicicleta(vecBicicleta[indice], vecTipo, tamT, vecColor, tamC);
            printf("Confirma baja?: ");
            fflush(stdin);
            confirma = getchar();

            if(confirma == 's'){
                vecBicicleta[indice].isEmpty = 1;
                printf("Baja exitosa.\n");

            }else{
                printf("Se ha cancelado la baja.\n");
            }
        }
        todoOk = 1;
    }else{
        printf("\nNo hay bicicletas\n");
    }

    return todoOk;

}


/** \brief Muestra bicicletas por el color especificado
 *
 * \param vecBicicletas[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector tamanio
 * \return int retorna 1 si no hay error
 *
 */
int mostrarBicicletasPorColor(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int flag = 1;
    int idColor;
    int validacionC;
    int vacio;

    validarHayBicicleta(&vacio, vecBicicletas, tam);
    if(vecBicicletas != NULL && tam > 0 && vacio != 1){
        system("cls");

        mostrarColores(vecColor, tamC);
        printf("Ingrese id del color: ");
        scanf("%d", &idColor);

        validarColor(&validacionC, idColor, vecColor, tamC);
        if(validacionC == -1){
            printf("\nEse id de color no existe\n");
        }
        printf("\n\n");

        if(validacionC != -1){
            printf("**** Lista de Bicicletas por Color****\n\n");
            printf("id   Marca      Tipo   Color   Material\n");
            for(int i = 0 ; i < tam ; i++){
                if(!vecBicicletas[i].isEmpty && vecBicicletas[i].idColor == idColor){
                    mostrarBicicleta(vecBicicletas[i], vecTipo, tamT, vecColor, tamC);
                    flag = 0;
                }
            }
            printf("\n\n");

            if(flag){
                printf("No hay bicicletas de ese color en el sistema.\n\n");
            }
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}


/** \brief muestra bicicletas por el tipo especificado
 *
 * \param vecBicicletas[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int mostrarBicicletasPorTipo(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int flag = 1;
    int idTipo;
    int validacionT;
    int vacio;

    validarHayBicicleta(&vacio, vecBicicletas, tam);
    if(vecBicicletas != NULL && tam > 0 && vacio != 1){
        system("cls");

        mostrarTipos(vecTipo, tamT);
        printf("Ingrese id del Tipo: ");
        scanf("%d", &idTipo);

        validarTipo(&validacionT, idTipo, vecTipo, tamT);
        if(validacionT == -1){
            printf("\nEse id de Tipo no existe\n");
        }
        printf("\n\n");

        if(validacionT != -1){
            printf("**** Lista de Bicicletas por Tipo****\n\n");
            printf("id   Marca      Tipo   Color   Material\n");
            for(int i = 0 ; i < tam ; i++){
                if(!vecBicicletas[i].isEmpty && vecBicicletas[i].idTipo == idTipo){
                    mostrarBicicleta(vecBicicletas[i], vecTipo, tamT, vecColor, tamC);
                    flag = 0;
                }
            }
            printf("\n\n");

            if(flag){
                printf("No hay bicicletas de ese tipo en el sistema.\n\n");
            }
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}


/** \brief Informa en pantalla si hay mas bicicletas de carbono o de aluminio
 *
 * \param vecBicicletas[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \return int retorna 1 si no hay error
 *
 */
int informarMasBicicletasCoA(eBicicleta vecBicicletas[], int tam){
    int todoOk = 0;
    int cantCarbono = 0;
    int cantAluminio = 0;
    int vacio;
    char material;
    int masBicicletas;
    char materialMasBicicletas[10];
    char carbono[10] = "carbono";
    char aluminio[10] = "aluminio";

    validarHayBicicleta(&vacio, vecBicicletas, tam);
    if(vecBicicletas != NULL && tam > 0 && vacio != 1){
        for(int i = 0 ; i < tam ; i++){
            material = vecBicicletas[i].material;
            switch(material){
            case 'c':
                cantCarbono++;
                break;

            case 'a':
                cantAluminio++;
                break;
            }
        }

        if(cantCarbono > cantAluminio){
            masBicicletas = cantCarbono;
            strcpy(materialMasBicicletas, carbono);
        }else{
            masBicicletas = cantAluminio;
            strcpy(materialMasBicicletas, aluminio);
        }

        printf("\n\nLa mayoria de bicicletas estan hechas de %s y son %d bicicletas\n", materialMasBicicletas, masBicicletas);

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}


/** \brief Muestra las bicicletas separadas por tipo
 *
 * \param vecBicicletas[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int mostrarBicicletasSeparadasPorTipo(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int vacio;
    int tipo = 1000;

    validarHayBicicleta(&vacio, vecBicicletas, tam);
    if(vecBicicletas != NULL && tam > 0 && vacio != 1){
        system("cls");

        printf("**** Lista de Bicicletas por Tipo****\n\n");
        printf("id   Marca      Tipo   Color   Material\n");
        for(int i = 0 ; i < tamT; i++){
            for(int j = 0; j < tam; j++){
                if(!vecBicicletas[j].isEmpty && vecBicicletas[j].idTipo == tipo){
                    mostrarBicicleta(vecBicicletas[j], vecTipo, tamT, vecColor, tamC);
                }
            }
            tipo++;
            printf("\n\n");
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}


/** \brief cuenta Bicicletas por Tipo y Color ingresado y los muestra en pantalla
 *
 * \param vecBicicletas[] eBicicleta vector bicicleta
 * \param tam int tamanio del vector bicicleta
 * \param vecTipo[] eTipo vector tipo
 * \param tamT int tamanio del vector tipo
 * \param vecColor[] eColor vector tipo
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int contarBicicletasPorTipoYColorIngresado(eBicicleta vecBicicletas[], int tam, eTipo vecTipo[], int tamT, eColor vecColor[], int tamC){
    int todoOk = 0;
    int flagTipo = 1;
    int flagColor = 1;
    int idTipo;
    int idColor;
    int validacionT;
    int validacionC;
    int vacio;
    int cantColor = 0;
    int cantTipo = 0;

    validarHayBicicleta(&vacio, vecBicicletas, tam);
    if(vecBicicletas != NULL && tam > 0 && vacio != 1){
        system("cls");

        mostrarTipos(vecTipo, tamT);
        printf("Ingrese id del Tipo: ");
        scanf("%d", &idTipo);

        validarTipo(&validacionT, idTipo, vecTipo, tamC);
        if(validacionT == -1){
            printf("\nEse id de Tipo no existe\n");
        }
        printf("\n\n");
        system("cls");

        mostrarColores(vecColor, tamC);
        printf("Ingrese id del color: ");
        scanf("%d", &idColor);

        validarColor(&validacionC, idColor, vecColor, tamC);
        if(validacionC == -1){
            printf("\nEse id de color no existe\n");
        }

        if(validacionT != -1){
            for(int i = 0 ; i < tam ; i++){
                if(!vecBicicletas[i].isEmpty && vecBicicletas[i].idTipo == idTipo){
                    cantTipo++;
                    flagTipo = 0;
                }
            }
            printf("\n\n\n");

            if(flagTipo){
                printf("No hay bicicletas de ese tipo en el sistema");
            }else{
                printf("Cantidad de bicicletas de ese tipo: %d\n", cantTipo);
            }
        }

        if(validacionC != -1){
            for(int i = 0 ; i < tam ; i++){
                if(!vecBicicletas[i].isEmpty && vecBicicletas[i].idColor == idColor){
                    cantColor++;
                    flagColor = 0;
                }
            }
            printf("\n\n");

            if(flagColor){
                printf("No hay bicicletas de ese color en el sistema.\n\n");
            }else{
                printf("Cantidad de bicicletas con ese color: %d\n\n\n", cantColor);
            }
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}


/** \brief Muestra el color o los colores mas elegidos
 *
 * \param vecBicicletas[] eBicicleta vector bicicleta
 * \param tam int tamanio vector bicicleta
 * \param vecColor[] eColor vector color
 * \param tamC int tamanio del vector color
 * \return int retorna 1 si no hay error
 *
 */
int mostrarColorConMasBicicletas(eBicicleta vecBicicletas[], int tam, eColor vecColor[], int tamC){
    int todoOk = 0;
    int cantGris = 0;
    int cantBlanco = 0;
    int cantAzul = 0;
    int cantNegro = 0;
    int cantRojo = 0;
    int color;
    int vacio;
    char descColor1[10];
    int mayorColor = -1;
    char descColor2[10];
    int cantColores[5];
    int idColor1;
    int idColor2;
    int dosColores;

    validarHayBicicleta(&vacio, vecBicicletas, tam);
    if(vecBicicletas != NULL && tam > 0 && vacio != 1){
        for(int i = 0 ; i < tam ; i++){
            color = vecBicicletas[i].idColor;
            switch(color){
            case 5000:
                cantGris++;
                break;

            case 5001:
                cantBlanco++;
                break;

            case 5002:
                cantAzul++;
                break;

            case 5003:
                cantNegro++;
                break;

            case 5004:
                cantRojo++;
                break;
            }
        }

        cantColores[0] = cantGris;
        cantColores[1] = cantBlanco;
        cantColores[2] = cantAzul;
        cantColores[3] = cantNegro;
        cantColores[4] = cantRojo;

        for(int i = 0; i < tamC; i++){
            if(cantColores[i] > mayorColor){
                mayorColor = cantColores[i];
                idColor1 = 5000 + i;
            }
        }

        for(int i = 0 ; i < tamC ; i++){
            if(vecColor[i].id == idColor1){
                strcpy(descColor1, vecColor[i].nombreColor);
                break;
            }
        }

         for(int i = 0; i < tamC; i++){
            if(cantColores[i] == mayorColor && vecColor[i].id != idColor1){
                mayorColor = cantColores[i];
                idColor2 = 5000 + i;
                dosColores = 1;
            }
        }

        for(int i = 0 ; i < tamC ; i++){
            if(vecColor[i].id == idColor2){
                strcpy(descColor2, vecColor[i].nombreColor);
                break;
            }
        }


        if(dosColores == 1){
            printf("\n\nLos colores con mas bicicletas son %s y %s con %d bicicletas\n", descColor1, descColor2, mayorColor);
        }else{
            printf("\n\nEl color con mas bicicletas es %s con %d bicicletas\n", descColor1, mayorColor);
        }

        todoOk = 1;
    }else{
        printf("\n\nNo hay bicicletas\n");
    }

    return todoOk;
}
