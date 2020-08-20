/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cc50.h>

#include "helpers.h"

#include <stdio.h>


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int array[], int n)
{
    // Primeiro metodo, verificar um por um
    // for (int i = 0; i < n; i++)
    //     if (array[i] == value)
    //         return true;
    // return false;

    // Segundo metodo, busca binaria
    int result = buscaBinaria(value, array, 0, n);
    if(result == 0)
        return false;
    return true;

}

int 
buscaBinaria(int value, int array[], int inicial, int final)
{
    int result = 0, n = 0;
    n = (final - inicial)/2 + inicial;

    if(value < array[0] || value > array[final - 1])
    {
        // printf("valor = %d , n = %d, array[n] = %d, inicial = %d, final = %d\n",value, n, array[n], inicial, final);
        // printf("value = %d, array[0] = %d, array[final] = %d\n", value, array[0], array[final]);
        return 0;
    }

    // printf("valor = %d , n = %d, array[n] = %d, inicial = %d, final = %d\n",value, n, array[n], inicial, final);
    
    if(array[n] == value){
        result = 1;
    }

    else if(array[n] < value)
    {
        result = buscaBinaria(value, array, n, final);
    }
    else
    {
       result = buscaBinaria(value, array, inicial, n);
    }

    // printf("Result = %d\n", result);
    return result;
}


/*
 * Sorts array of n values.  Returns true if
 * successful, else false.
 */

bool
sort(int values[], int n)
{
    // TODO: implement an O(n) sort

    int menor = values[0], posicao = 0;

    for(int i = 0; i < n; i++)
    {
        menor = values[i];
        int x = 0;
        for(int j = i; j < n; j++)
        {
            if(values[j] < menor){
                menor = values[j];
                posicao = j;
                x = 1;
            } 
        }
        if(x == 1)
        {
            values[posicao] = values[i];
            values[i] = menor;
        }
    }

    return true;
}
