#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#define TAMB 100
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMTR 10


int menu();
int confirmarSalida(char* pVariable, char confirma, char rechaza);


int main(){
    int nextIdBicicleta = 1;
    int nextIdTrabajo = 2000;

    char salir = 'n';

    eBicicleta bicicletas[TAMB];
    eTrabajo trabajos[TAMT];

    eTipo tipos[TAMT] = {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };

    eColor colores[TAMC] = {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };

    eServicio servicios[TAMS] = {
        {20000, "Limpieza", 30},
        {20001, "Parche", 400},
        {20002, "Centrado", 500},
        {20003, "Cadena", 450}
    };



    inicializarBicicletas(bicicletas, TAMB);
    inicializarTrabajos(trabajos, TAMTR);

    hardcodearTrabajos(&nextIdTrabajo, trabajos, TAMTR, 4);


    do{
        switch(menu()){
        case 1:
            if(altaBicicleta(&nextIdBicicleta, bicicletas, TAMB, tipos, TAMT, colores, TAMC)){
                printf("Bicicleta agregada con exito\n");
            }else{
                printf("Ocurrio un problema durante el alta\n");
            }

            system("pause");
            break;

        case 2:
            modificarBicicleta(bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;

        case 3:
            bajaBicicleta(bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;

        case 4:
            mostrarBicicletas(bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;

        case 5:
            system("cls");
            mostrarTipos(tipos, TAMT);
            system("pause");
            break;

        case 6:
            mostrarColores(colores, TAMC);
            system("pause");
            break;

        case 7:
            mostrarServicios(servicios, TAMS);
            system("pause");
            break;

        case 8:
            altaTrabajo(&nextIdTrabajo, bicicletas, TAMB, trabajos, TAMTR, tipos, TAMT, colores, TAMC, servicios, TAMS);
            system("pause");
            break;

        case 9:
            mostrarTrabajos(trabajos, TAMTR, servicios, TAMS);
            system("pause");
            break;

        case 10:
            mostrarBicicletasPorColor(bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;

        case 11:
            mostrarBicicletasPorTipo(bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;

        case 12:
            informarMasBicicletasCoA(bicicletas, TAMB);
            system("pause");
            break;

        case 13:
            mostrarBicicletasSeparadasPorTipo(bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;

        case 14:
            contarBicicletasPorTipoYColorIngresado(bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;
        case 15:
            mostrarColorConMasBicicletas(bicicletas, TAMB, colores, TAMC);
            system("pause");
            break;
        case 16:
            mostrarTrabajosPorBicicleta(trabajos, TAMTR, servicios, TAMS, bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;
        case 17:
            //mostrarCostoBicicleta(trabajos, TAMTR, servicios, TAMS, bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;
        case 19:
            mostrarServiciosPorFecha(trabajos, TAMTR, servicios, TAMS, bicicletas, TAMB, tipos, TAMT, colores, TAMC);
            system("pause");
            break;
        case 20:
                confirmarSalida(&salir, 's', 'n');
            break;

        default:
            printf("Opcion invalida\n");
            system("pause");
        }
    }while(salir != 's');


    return 0;
}


/** \brief Se confirma si se quiere salir del codigo
 *
 * \param pVariable char* s o n
 * \param confirma char se confirma la salida
 * \param rechaza char se rechaza la salida
 * \return int 1 si no hay error
 *
 */
int confirmarSalida(char* pVariable, char confirma, char rechaza){
    int todoOk = 0;
    char rta;

    if(pVariable != NULL){
        printf("Esta seguro de que desea salir?: ");
        fflush(stdin);
        scanf("%c", &rta);
        rta = tolower(rta);

        if(rta == 's'){
            *pVariable = confirma;
        }else{
            *pVariable = rechaza;
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief despliega un menu de opciones
 *
 * \return int retorna la opcion ingresada
 *
 */
int menu(){
    int rta;

    system("cls");

    printf("*** Opciones ***\n\n");
    printf("1- Alta bicicleta\n");
    printf("2- Modificar bicicleta\n");
    printf("3- Baja bicicleta\n");
    printf("4- Listar bicicletas\n");
    printf("5- listar tipos\n");
    printf("6- Listar colores\n");
    printf("7- Listar servicios\n");
    printf("8- Alta trabajo\n");
    printf("9- Listar Trabajos\n");
    printf("10- Listar Bicicletas por Color\n");
    printf("11- Listar Bicicletas por Tipo\n");
    printf("12- Informar de que material hay mas bicicletas\n");
    printf("13- listar Bicicletas separadas por tipo\n");
    printf("14- Mostrar cantidad de bicicletas por color y tipo ingresado\n");
    printf("15- Mostrar color mas elegido por los clientes\n");
    printf("16- Mostrar trabajos realizados a una bicicleta\n");
    //printf("17- informar costo realizados a una bicicleta\n");
    printf("19- Mostrar servicios por fecha\n");

    printf("\n20- Salir.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &rta);

    return rta;
}




