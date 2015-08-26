
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
    

    // ensure valid dimensions
    d = atoi(argv[1]);
   
    // initialize the board
    init();

    
    // that's all folks
    return 0;
}



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







