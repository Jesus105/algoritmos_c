#include "TDA.h"

void crearTDA (AUTO* pointer, MOTOR motor, TRANSMISION transmision, char *marca, char *modelo, int anio, int kilometraje){
    pointer -> motor = motor;
    pointer -> transmision = transmision;
    strcpy(pointer -> marca, marca);
    strcpy(pointer -> modelo, modelo);
    pointer -> anio = anio;
    pointer -> kilometraje = kilometraje;
}

void destruirTDA(AUTO * pointer){
    free(pointer);
}

void imrimirTDA(AUTO * pointer){
    printf("El auto es un %s %s del anio %d con %d kilometros. \n", pointer->marca, pointer->modelo, pointer->anio, pointer->kilometraje);
    printf("El motor tiene %d cilindros, un volumen de %1.1f,  un max de %d RPM, y usa %s\n", pointer->motor.noCilindros, pointer->motor.volumen, pointer->motor.maxRPM, pointer->motor.combustible);
    printf("La trasmision tiene %d embragues, es de tipo %s, con %d velocidades\n", pointer->transmision.noEmbragues, pointer->transmision.tipo, pointer->transmision.noVelocidades);
    
}

void copiarTDA(AUTO * source, AUTO * dest){
    dest ->motor = source -> motor;
    dest ->transmision = source -> transmision;
    dest -> anio = source -> anio;
    dest -> kilometraje = source -> kilometraje;

    strcpy(dest -> marca, source -> marca);
    strcpy(dest -> modelo, source -> modelo);

}

void test(int argc, const char ** argv){

    AUTO * pointerAuto = NULL;

    pointerAuto = (AUTO * ) malloc(sizeof(AUTO));

    if(pointerAuto == NULL){
        puts("ERROR: no se pudo almacenar la memoria correctamente. ");
        exit(1);
    }

    AUTO * newPointer = NULL;

    newPointer = (AUTO * ) malloc(sizeof(AUTO));

    if(newPointer == NULL){
        puts("ERROR: no se pudo almacenar la memoria correctamente. ");
        exit(1);
    }

    MOTOR motor;
    strcpy(motor.combustible, "Gasolina");
    motor.maxRPM = 6500;
    motor.noCilindros = 8;
    motor.volumen = 5.0;

    TRANSMISION transmision;
    transmision.noEmbragues = 1;
    transmision.noVelocidades = 5;
    strcpy(transmision.tipo, "Manual");

    int userOpt = 1;

    while (userOpt)
    {
        puts("Seleccione una opción: ");
        puts("[1] Crear TDA");
        puts("[2] Destruir TDA");
        puts("[3] Imprimir TDA");
        puts("[4] Copiar TDA");
        puts("[0] Salir del programa");

        scanf("%d", &userOpt);


        switch (userOpt)
        {
        case 0:
            puts("Hasta pronto");
            break;

        case 1:
            crearTDA(pointerAuto, motor, transmision, "Ford", "Mustang", 1968, 150000);
            puts("TDA creado");
            break;
        
        case 2: 
            destruirTDA(pointerAuto);
            puts("TDA eliminado");
            break;

        case 3: 
            imrimirTDA(pointerAuto);
            break;

        case 4:

            copiarTDA(pointerAuto, newPointer);

            puts("TDA copiado");
            break;

        default:

            puts("Opcion no valida");
            break;
        }

    }
    
}