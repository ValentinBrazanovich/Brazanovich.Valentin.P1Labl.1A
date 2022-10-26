#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];

} eColor;

#endif // COLOR_H_INCLUDED


int cargarDescripcionColor(int id, char descripcion[], eColor vecColor[], int tamC);
int mostrarColores(eColor vecColor[], int tam);
int buscarColor(int* pIndice, int id, eColor vecColor[], int tamC);
