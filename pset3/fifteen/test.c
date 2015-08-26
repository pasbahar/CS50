/***************************************************************************
 * fifteen.c by Bruce Snipes 2012-08-20
 *
 * Computer Science 50
 * Problem Set 3
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

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define BLANK 2424

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
string s;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
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

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("Congratulations, you are a winner!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
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
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{

int i = d*d-1;

    // set up the values on the board in descending order
    for (int k = 0; k < d; k++)
    {    
        for (int j = 0; j < d; j++, i--)
        {
        board[k][j] = i; 
        }   
    }

    // give the zero tile the value of BLANK
    if (board[d-1][d-1] == 0)
        board[d-1][d-1] = BLANK;

    // if dimension, d, is even, reverse the values of the last 
    // two tiles 1 and 2, that is when the number of tiles is odd
    if (d % 2 == 0)
    {
        int temp        = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = temp;   
    }


}



/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
    // create board with dimensions given by user
       
    printf("\n\n\n");
   
    // this sets up the rows
    for (int i = 0; i < d; i++)
    {
        // this fills the numbers in the rows
        for (int j = 0; j < d; j++)
            if (board[i][j] == BLANK && j != d-1)
                    printf("   _");
                    
            else if (board[i][j] == BLANK && j == d-1)
                printf("   _\n\n");
                    
            else if (j == d-1)
            {
                printf("  %2d  \n\n", board[i][j]);
            }
            
            else
            {
                printf("  %2d", board[i][j]);
            }
            
    }
    

    
    printf("\n");
}



/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
    // swap values of blank and tile
              
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] == tile)
                {
                   
                    if (board[i][j-1] == BLANK)
                    {
                        int temp = tile;
                        board[i][j] = BLANK;
                        board[i][j-1] = temp;
                        return true;
                    }
                    
                    if (board[i][j+1] == BLANK)
                    {
                        int temp = tile;
                        board[i][j] = BLANK;
                        board[i][j+1] = temp;
                        return true;
                    }
                    
                    if (board[i-1][j] == BLANK)
                    {
                        int temp = tile;
                        board[i][j] = BLANK;
                        board[i-1][j] = temp;
                        return true;
                    }
                    
                    if (board[i+1][j] == BLANK)
                    {
                        int temp = tile;
                        board[i][j] = BLANK;
                        board[i+1][j] = temp;
                        return true;
                    }
                    
                }   
                 
            }        
        
        }    
    
    
    return false;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
    // check if all values are in ascending order
    int old = 0;
    int k   = 0;
    
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                
                if (board[i][j] < old)
                {
                    return false;
                }
                else if (board[i][j] > old)
                {
                    k += 1;
                    if ( k == d * d)
                    {
                        return true;
                    }    
                }
 
                 old = board[i][j]; 
            }   
                         
        }        
                
                
                    
    
    return false;
}







