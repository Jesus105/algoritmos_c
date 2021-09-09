#include "TDA.h"

void makePersonas(){
    int i;

    for(i = 0; i<SIZE ; i++)
        personas[i].datos = datos[i];

}

int merge(int * array, int i, int j) {
  int pivote = array[i];
  int buffer;
  while (1) {
    while (array[i] < pivote) {
      i++;
    }
    while (array[j] > pivote) {
      j--;
    }
    if (i >= j) {

      return j;
    } 
    else{
        buffer = array[i];
        array[i] = array[j];
        array[j] = buffer;

        i++;
        j--;
    }
  }
}

void sort(int * array, int left, int right) {
  if (left < right) {
    int i = merge(array, left, right);
    sort(array, left, i);
    sort(array, i + 1, right);
  }
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

void Nombre(PERSONA * p_datos, int array_size){
    int i,j,pivote;

    int array[array_size];

    PERSONA aux;

    for(i = 0; i<array_size; i++)
        array[i] = (int) p_datos[i].datos.nombre[1];
    
    sort(array, 0, SIZE-1);

    for(i = 0; i < SIZE; i++)
        for(j = i; i<SIZE; j++)
            if(array[i] == (int) p_datos[j].datos.nombre[1]){
                aux = p_datos[i];
                p_datos[i] = p_datos[j];
                p_datos[j] = aux;
                break;
            }
}

void Telefono(PERSONA * p_datos, int array_size){
    int i,j;
    PERSONA aux;

    unsigned long array[array_size];
    unsigned long buffer;

    for(i = 0; i < array_size; i++)
        array[i] = p_datos[i].datos.telefono;



    for(i = 1; i<array_size; i++)
        for(j = 0; j < array_size - 1; j++){
            if(array[j]>array[j+1]){
                buffer = array[j];
                array[j] = array[j+1];
                array[j+1] = buffer;
            }
        }
  
    for(i = 0; i < SIZE; i++)
        for(j = i; i<SIZE; j++)
            if(array[i] == p_datos[j].datos.telefono){
                aux = p_datos[i];
                p_datos[i] = p_datos[j];
                p_datos[j] = aux;
                break;
            }
}

void Pais(PERSONA * p_datos, int array_size){
    int i,j,pivote;

    int array[array_size];

    PERSONA aux;

    for(i = 0; i<array_size; i++)
        array[i] = (int) p_datos[i].datos.pais[0];
    
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
            if(array[i] == (int) p_datos[j].datos.pais[0]){
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
        puts("[0] Salir del programa");
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

        case 3: 
            Nombre(personas, SIZE);
            printPersonas(personas);
            break;

        case 4:
            Telefono(personas, 122);
            printPersonas(personas);
            break;

        case 5: 
            Pais(personas, SIZE);
            printPersonas(personas);
            break;

        case 0:
            puts("Hasta luego");
            break;

        default:
            puts("Opcion no valida, seleccione una correcta");
            break;
        }

    }

    return 0;
}