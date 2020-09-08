/***************************************************************************
 * fifteen.c
 *
 * CC50
 * Pset 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include "cc50.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define LIMIT 65536


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(int array[]);
void draw(int array[]);
bool move(char tile, int array[]);
bool won(int array[]);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    int array[d*d];
    // initialize the board
    init(array);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(array);

        // check for win
        if (won(array))
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        char tile = GetChar();

        // move if possible, else report illegality
        if (!move(tile, array))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
    clear();

    printf("Use as teclas para mover os numeros:\n");
    printf("a = ⬅\n");
    printf("d = ➡\n");
    printf("w = ⬆\n");
    printf("s = ⬇\n\n");


    usleep(3000000);
    printf("Precione enter para iniciar...");
    char a;
    scanf("%c", &a);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(int array[])
{
    int vetSize = d*d;

    // Adiciona no array todos os numeros de 1 ate n
    for(int i = 0; i < vetSize; i++)
    {
        array[i] = i+1;
    }

    srand(time(NULL));

    // printf("ORDEM ALEATORIA\n");
    
    // Embaralha o array aleatoriamente
    for(int i = 0; i < vetSize; i++)
    {
        int r = rand() % vetSize;

		int temp = array[i];
		array[i] = array[r];
		array[r] = temp;
    }

    for (int i = 0; i < vetSize; i++)
    {
        if(array[i] == vetSize)
        {
            array[i] = array[vetSize - 1];
            array[vetSize - 1] = vetSize;
        }
    }

    // printf("posicao = %d, array[posicao] = %d, array[vetSize - 1] = %d\n", posicao, array[posicao], array[vetSize - 1]);
    // usleep(2000000);
}


/* 
 * Prints the board in its current state.
 */

void
draw(int array[])
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if(array[i * d + j] == d*d)
                printf("__ ");
            else
                printf("%02d ", array[i * d + j]);
        }
        printf("\n");
    }
    printf("\n");
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(char tile, int array[])
{
    if(tile != 'a' && tile != 'A' && tile != 'd' && tile != 'D'
    && tile != 'w' && tile != 'W' && tile != 's' && tile != 's')
    {
        return false;
    }

    int vetSize = d*d, posicao = 0;
    for(int i = 0; i < vetSize; i++)
    {
        if(array[i] == vetSize)
            posicao = i;
    }

    if(tile == 'a' || tile == 'A')
    {
        if( !((posicao + 1) % d))
        {
            return false;
        }
        array[posicao] = array[posicao + 1];
        array[posicao + 1] = vetSize;
    }

    else if(tile == 'd' || tile == 'D')
    {
        if(posicao == 0){
            return false;
        }
        else if( !((posicao) % d))
        {
            return false;
        }
        array[posicao] = array[posicao - 1];
        array[posicao - 1] = vetSize;
    }

    else if(tile == 's' || tile == 'S')
    {
        if(posicao - d < 0){
            return false;
        }
        array[posicao] = array[posicao - d];
        array[posicao - d] = vetSize;
    }

    else if(tile == 'w' || tile == 'W')
    {
        if(posicao + d >= vetSize){
            return false;
        }
        array[posicao] = array[posicao +d];
        array[posicao + d] = vetSize;
    }
    
    
    return true;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(int array[])
{
    int menor = array[0];
    for(int i = 0; i < d*d; i++)
    {
        for(int j = i; j < d*d; j++)
        {
            if(array[j] < menor)
                return false;
        }
        menor = array[i];
    }
    return true;
}
