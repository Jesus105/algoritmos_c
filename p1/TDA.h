#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{

    int noCilindros;
    int maxRPM;
    float volumen;
    char combustible[20];

} MOTOR;

typedef struct{

    char tipo[20];
    int noVelocidades;
    int noEmbragues;

} TRANSMISION;

typedef struct{
    MOTOR motor;
    TRANSMISION transmision;
    char marca[20];
    char modelo[20];
    int anio;
    int kilometraje;

} AUTO;

void crearTDA(AUTO*, MOTOR, TRANSMISION, char *, char *, int, int);

void destruirTDA(AUTO *);

void imprimirTDA(AUTO *);

void copiarTDA(AUTO *, AUTO *);

void test(int, const char **);
