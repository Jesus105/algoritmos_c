#include "TDA.h"

void makePersonas(){
    int i;

    for(i = 0; i<SIZE ; i++)
        personas[i].datos = datos[i];

}

void printPersonas(PERSONA * p_datos){

    DATO data[SIZE];
    int i = 0;
    
    
    for(i = 0; i<SIZE; i++){
        data[i] = p_datos[i].datos; 
    }

    puts("País || Nombre || Estatura || Telefono");

    for(i = 0; i<SIZE; i++)
        printf("%s , %s , %1.2f , %lu\n",data[i].pais, data[i].nombre, data[i].altura, data[i].telefono);

}

void Altura(PERSONA * p_datos, int array_size){

    int i,j;
    PERSONA aux;

    float buffer;

    float array[array_size];

    for(i = 0; i<array_size; i++)
        array[i] = p_datos[i].datos.altura;


    for(i = 0; i<array_size - 1; i++ )
        for(j = i+1; j<array_size; j++)
            if(array[i] > array[j]){
                buffer = array[i];
                array[i] = array[j];
                array[j] = buffer;
            }

    for(i = 0; i < SIZE; i++)
        for(j = i; i<SIZE; j++)
            if(array[i] == p_datos[j].datos.altura){
                aux = p_datos[i];
                p_datos[i] = p_datos[j];
                p_datos[j] = aux;
                break;
            }
}

void Pais(PERSONA * p_datos, int array_size){
    int i,j,pivote;

    int array[array_size];

    for(i = 0; i<array_size; i++)
        array[i] = (int) p_datos[i].datos.pais;
    
    for( i = 1; i<array_size; i++){
        pivote = array[i];
        j = i-1;

        while(j>=0 && array[j] >pivote){
            array[j+1] = array[j];
            j--;
        }    

        array[j+1]=pivote;
    }

    for(i = 0; i < SIZE; i++)
        for(j = i; i<SIZE; j++)
            if(array[i] == (int) p_datos[j].datos.pais){
                aux = p_datos[i];
                p_datos[i] = p_datos[j];
                p_datos[j] = aux;
                break;
            }

    
}

int main(int argc, const char ** argv){

    makePersonas();

    int usr_option = 1;

    puts("Bienvenido al programa!");

    while(usr_option){ 
        puts("Ingrese una opcion: ");
        puts("[1] Mostrar el arreglo desordenado");
        puts("[2] Ordenar lista de personas por altura");
        puts("[3] Ordenar listade personas por la segunda letra del nombre");
        puts("[4] Ordenar lista de personas por número de teléfono");
        puts("[5] Ordenar lista de personas por paísde origen");
        scanf("%d", &usr_option);


        switch (usr_option)
        {
        case 1:
            printPersonas(personas);
            break;
        
        case 2: 
            Altura(personas, SIZE);
            printPersonas(personas);
            break;

        default:
            puts("Opcion no valida, seleccione una correcta");
            break;
        }

    }

    return 0;
}