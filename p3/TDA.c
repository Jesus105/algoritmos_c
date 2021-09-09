#include "TDA.h"

void ordenar_insercion(float * array, int array_size){
    float pivote;
    int i,j;

    for( i = 1; i<array_size; i++){
        pivote = array[i];
        j = i-1;

        while(j>=0 && array[j] >pivote){
            array[j+1] = array[j];
            j--;
        }    

        array[j+1]=pivote;
    }

}

void ordenar_seleccion(int * array, int array_size){

    int buffer; 

    for(int i = 0; i<array_size - 1; i++ )
        for(int j = i+1; j<array_size; j++)
            if(array[i] > array[j]){
                buffer = array[i];
                array[i] = array[j];
                array[j] = buffer;
            }
}

void invertir_array(LIBRO * array, int array_size){
    LIBRO temporal; 
    int i, j;

    for(i = 0, j = array_size-1; i < (array_size/2); i++,j--){

        temporal = array[i];
        array[i] = array[j];
        array[j] = temporal;

    }
}


void alto(LIBRO * libros){
    float array[SIZE];
    LIBRO buffer;

    for(int i = 0; i<SIZE; i++){
        array[i] = libros[i].alto;
    }

    ordenar_insercion(array, SIZE);

    for(int i = 0; i < SIZE; i++)
        for(int j = i; i<SIZE; j++)
            if(array[i] == libros[j].alto){
                buffer = libros[i];
                libros[i] = libros[j];
                libros[j] = buffer;
                break;
            }

}

void titulo(LIBRO * libros){
    int array[SIZE];
    LIBRO buffer;
    int comparacion;

    for(int i = 0; i<SIZE; i++){
        array[i] = (int) libros[i].Titulo[0];
    }
    ordenar_seleccion(array, SIZE);

    for(int i = 0; i < SIZE; i++)
        for(int j = i; i<SIZE; j++){
            comparacion = (int) libros[j].Titulo[0];
            if(array[i] == comparacion){
                buffer = libros[i];
                libros[i] = libros[j];
                libros[j] = buffer;
                break;
            }
        }
}

void ancho(LIBRO * libros){
    float array[SIZE];
    LIBRO buffer;

    for(int i = 0; i<SIZE; i++){
        array[i] = libros[i].ancho;
    }

    ordenar_insercion(array, SIZE);

    for(int i = 0; i < SIZE; i++)
        for(int j = i; i<SIZE; j++)
            if(array[i] == libros[j].ancho){
                buffer = libros[i];
                libros[i] = libros[j];
                libros[j] = buffer;
                break;
            }
}

void fuente(LIBRO * libros){
    int array[SIZE];
    LIBRO buffer;
    int comparacion;

    for(int i = 0; i<SIZE; i++){
        array[i] = (int) libros[i].fuente[0];
    }
    ordenar_seleccion(array, SIZE);

    for(int i = 0; i < SIZE; i++)
        for(int j = i; i<SIZE; j++){
            comparacion = (int) libros[j].fuente[0];
            if(array[i] == comparacion){
                buffer = libros[i];
                libros[i] = libros[j];
                libros[j] = buffer;
                break;
            }
        }
}

void ID(LIBRO * libros){
    int array[SIZE];
    LIBRO buffer;

    for(int i = 0; i<SIZE; i++){
        array[i] = (int) libros[i].ID;
    }
    ordenar_seleccion(array, SIZE);

    for(int i = 0; i < SIZE; i++)
        for(int j = i; i<SIZE; j++){
            if(array[i] == libros[j].ID){
                buffer = libros[i];
                libros[i] = libros[j];
                libros[j] = buffer;
                break;
            }
        }
}

void imprimir(LIBRO * libros){
    printf("ID || Titulo || Alto || Ancho || Fuente \n");
    
    for(int i = 0; i < SIZE; i++)
        printf("%d %s, %1.2f, %1.2f, %s\n", libros[i].ID, libros[i].Titulo, libros[i].alto, libros[i].ancho, libros[i].fuente);
    
}


void main(int argc, const char ** argv){

    int usr_select = 1;
    int orden = 0;


    puts("Bienvenido al programa");

    while(usr_select){
        puts("Seleccione una opción");
        puts("[1] Mostrar resultados por dimensiones (alto)");
        puts("[2] Mostrar resultados por titulo de la pagina");
        puts("[3] Mostrar resultados por dimensiones (ancho)");
        puts("[4] Mostrar resultados por tipo de fuente");
        puts("[5] Mostrar resultados por ID");
        puts("[0] Salir del programa");
        scanf("%d", &usr_select);

        puts("Ingrese 1 si quiere que sea en orden descendente");
        puts("Ingrese 0 si quiere que sea en orden ascendente");
        scanf("%d", &orden);
        
        switch (usr_select)
        {
            case 1:
                alto(lib_array);
                
                if(orden)
                    invertir_array(lib_array, SIZE);
                

                imprimir(lib_array);
                break;

            case 2:
                titulo(lib_array);
            
                if(orden)
                    invertir_array(lib_array, SIZE);
            
                imprimir(lib_array);
                break;
            
            case 3:
                ancho(lib_array);
                
                if(orden)
                    invertir_array(lib_array, SIZE);
                

                imprimir(lib_array);

                break;

            case 4: 
                fuente(lib_array);
            
                if(orden)
                    invertir_array(lib_array, SIZE);
        
                imprimir(lib_array);
                break;

            case 5: 
                ID(lib_array);

                if(orden)
                    invertir_array(lib_array, SIZE);
        
                imprimir(lib_array);
                break;

            case 0: 
                puts("Hasta la proxima");
                break;

            default:
                puts("Ingrese un valor correcto");
                break;
        }
    }
}