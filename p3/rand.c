#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 459565
#define SIZE 10000

void ordenar_insercion(int * array, int array_size);
void ordenar_seleccion(int * array, int array_size);
void invertir_array(int * array, int array_size);

int main(int argc, const char ** argv ){

    int array[SIZE];
    int * pair = NULL;
    int * odd = NULL;
    int odd_counter = 0;
    int pair_counter = 0;

    for(int i = 0; i<SIZE; i++){
        array[i] = rand() % MAX;


        if(array[i]%2)
            odd_counter++;
    }

    pair_counter = SIZE - odd_counter;

    odd = (int *) calloc(odd_counter, sizeof(int));
    pair = (int *) calloc(pair_counter, sizeof(int));
    
    if(odd == NULL || pair == NULL){
        puts("ERROR: No se pudo reservar la memoria para contener a los arreglos");
        exit(1);
    }

    odd_counter = 0;
    pair_counter = 0;

    for(int i = 0; i<SIZE; i++){
        if(array[i]%2){
            odd[odd_counter] = array[i];
            odd_counter++;
        }
        else{
            pair[pair_counter] = array[i];
            pair_counter++;
        }
            
    }


    ordenar_insercion(pair, pair_counter);
    invertir_array(pair,pair_counter);

    ordenar_seleccion(odd, odd_counter);

    puts("Impares:");

    for(int i = 0; i<odd_counter; i++)
        printf("%d,", odd[i]);

    puts("\n");

    puts("Pares:");

    for(int i = 0; i<pair_counter; i++)
        printf("%d,", pair[i]);

    puts("\n");

    free(odd); 
    free(pair);

    return 0;

}



void ordenar_insercion(int * array, int array_size){
    int pivote,i,j;

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

void invertir_array(int * array, int array_size){
    int temporal, i, j;

    for(i = 0, j = array_size-1; i < (array_size/2); i++,j--){

        temporal = array[i];
        array[i] = array[j];
        array[j] = temporal;

    }
}

