//
//  main.cpp
//  DrawEllipse
//
//  Created by Hani on 12/11/17.
//  Copyright © 2017 HaniHaniehHanieh.Sahra. All rights reserved.
//
#include <OpenGL/gl3.h>
#include "stdlib.h"
#include "GLUT/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry)
{
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;
    void ellipsePlotPoints(int, int, int, int);
    
    /* Plot the initial point in each quadrant. */
    ellipsePlotPoints(xCenter, yCenter, x, y);
    
    /* Region 1 */
    p = round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while (px < py) {
        x++;
        px += twoRy2;
        if (p < 0)
            p += Ry2 + px;
        else {
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }
    
    /* Region 2 */
    p = round(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
    while (y > 0) {
        y--;
        py -= twoRx2;
        if (p > 0)
            p += Rx2 - py;
        else {
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }
}

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
    glVertex2f(xCenter + x, yCenter + y);
    glVertex2f(xCenter - x, yCenter + y);
    glVertex2f(xCenter + x, yCenter - y);
    glVertex2f(xCenter - x, yCenter - y);
    
}
void display(void){
    ellipseMidpoint(300, 250, 100, 150);
}
void init (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);    	// Clear the background set it to black
    glShadeModel(GL_FLAT);                 	// set the shading model to FLAT
}
// Function that resets the window, each time when the window size is changed
void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}
// Main entry point of the program
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);    // set up the window size
    glutCreateWindow("Ellipse");       // create the window  argv[0]
    init();                          // initialize the window
    glutDisplayFunc(display);        // call the display to draw the rectangles
    glutReshapeFunc(reshape);        // call the reshape function
				// (each time when the window size is changed)
    glutMainLoop();
    return 0;
}
