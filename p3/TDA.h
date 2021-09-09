#ifndef TDA_H_
#define TDA_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 33

typedef struct 
{
    int ID;
    char Titulo[50];
    float alto;
    float ancho;
    char fuente[50];
} LIBRO;

LIBRO lib_array[33]={{1,"Anécdota de un día",8.5,3.18,"Tahoma black"},
                    {2,"Burros Blancos",7.5,0.74,"Agency"},
                    {3,"Cien años y uno mas",6.5,0.3,"Abscissa"},
                    {4,"Diamantes y dados",5.5,0.14,"HP Simplified"},
                    {5,"El avestrus",4.5,0.58,"Arial"},
                    {6,"El cuento",3.5,0.46,"Calibri"},
                    {7,"Elefantes",2.5,1.46,"Impact"},
                    {8,"Fiestas",1.5,1.9,"Alanis hand"},
                    {9,"Gatoman",0.5,2.34,"Jasmine UPC"},
                    {10,"Hipopotamos en su habitat",0.5,2.78,"Latha"},
                    {11,"Italia, un nuevo mundo",1.5,3.22,"Kaiti"},
                    {12,"Juanacatlan, pueblo magico",2.5,3.66,"Nyala"},
                    {13,"Kids, where are them?",3.5,4.1,"Verdana"},
                    {14,"La niña",4.5,4.54,"Tahoma"},
                    {15,"Metafisica",5.5,4.98,"Modern"},
                    {16,"Nuevos horizontes",6.5,5.42,"Univers"},
                    {17,"Osos polares",7.5,5.86,"Yu Gothic"},
                    {18,"Pato Hood",8.5,6.3,"Ravie"},
                    {19,"Poblaciones vulnerables",9.5,6.74,"OCRB"},
                    {20,"Quo duo",10.5,7.18,"Selawik"},
                    {21,"Robin Hood",11.5,7.62,"Perpetua"},
                    {22,"Significado de la vida",12.5,8.06,"Times"},
                    {23,"Soberanos",13.5,8.5,"Webdings"},
                    {24,"Trasatlantico",14.5,8.94,"Sweet Pea"},
                    {25,"Trasportes en el futuro",15.5,9.38,"Bell MT"},
                    {26,"Trotamundos",16.5,9.82,"Ebrima"},
                    {27,"Uvas para el vino",17.5,10.26,"Mangal"},
                    {28,"Verduras y frutas",18.5,10.7,"Cambria"},
                    {29,"Viajando ando",19.5,11.14,"Dotum"},
                    {30,"Walter Cross, ¿Quién fue?",20.5,11.58,"Papyrus"},
                    {31,"Xcaret, un lugar magico",21.5,12.02,"Arial Black"},
                    {32,"Yardas",22.5,12.46,"Georgia"},
                    {33,"Zapato Viejo",23.5,12.9,"French script"}};



void ordenar_insercion(float *, int);
void ordenar_seleccion(int * array, int array_size);
void invertir_array(LIBRO *, int);
void alto(LIBRO *);
void ancho(LIBRO *);
void fuente(LIBRO *);
void titulo(LIBRO *);
void ID(LIBRO *);
void imprimir(LIBRO *);

#endif /* TDA_H_*/