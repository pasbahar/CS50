//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);


int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);
    
    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 50;

    // keep playing until game over
    double bdx = drand48()/10;
    double bdy = drand48()/10;
    while (lives > 0 && bricks > 0)
    {
        // TODO
       //move paddle

    
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
           if (getEventType(event) == MOUSE_MOVED)
            {
            double x;
                // ensure circle follows top cursor
                x = getX(event)-getWidth(paddle)/2;
                if (getX(event)>=400-getWidth(paddle)/2)
                x = 400-getWidth(paddle);
                if (getX(event)<=getWidth(paddle)/2)
                x = 0;
                
                  
                setLocation(paddle, x, 580);
            }
         }
    
    // Move ball
    move(ball,bdx,bdy);
        // bounce off edges
        // left or right
        if ((getX(ball) + getWidth(ball) >= WIDTH) || getX(ball) <= 0)
            bdx = -bdx;
        // top
        else if ( getY(ball) <= 0)
            bdy = -bdy;
        else if ( (getY(ball) + getHeight(ball) >= HEIGHT))
            {
              lives--;
             setLocation(ball, 190, 290); 
             waitForClick();  
            }
           
  
  
  GObject object = detectCollision(window, ball);
        
        if (object!=NULL && object!=label)
            bdy = -bdy;
     
        
         if (object!=NULL && object!=paddle && object!=label)
              {
                points--;
                removeGWindow(window, object);
              }
              
  GLabel initScoreboard(GWindow window);
  
  updateScoreboard(window, label, points);
         
                
                
    }      

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    string brickColors[] = {"RED","ORANGE","YELLOW","BLUE","GREEN"};
    int colorIndex = 0;
    int x;
    int y=20;
    for (int i=0; i<5; i++)
     {
      x=0;
      for (int j=0; j<10; j++)
        {
            GRect brick = newGRect(x,y,38,10);
            x=x+40;
            setColor(brick,brickColors[colorIndex]);
            setFilled(brick, true);
            add(window, brick);
        }
      colorIndex++;
      y=y+12;
     }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    int x = (WIDTH / 2) - RADIUS;
    int y = (HEIGHT / 2) - RADIUS;
    GOval ball = newGOval(x, y, RADIUS*2, RADIUS*2);
    setFilled(ball, true);

    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect(160, 580, 80, 10);
    setFilled(paddle, true);

    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    // count down from 50 to 0
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
