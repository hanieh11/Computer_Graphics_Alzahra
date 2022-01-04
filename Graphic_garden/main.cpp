//
//  main.cpp
//  graphicGarden
//
//  Created by Hani on 1/24/18.
//  Copyright © 2018 HaniHaniehHanieh.Sahra. All rights reserved.
//
#include <OpenGL/gl3.h>
#include "stdlib.h"
#include "GLUT/glut.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


struct screenpt {
    GLint x;
    GLint y;
};

GLsizei winWidth=1000, winHeight=800;
void init (void){
    glClearColor(1.0,1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment (screenpt pt1, screenpt pt2){
    glBegin(GL_LINES);
        glVertex2i(pt1.x, pt1.y);
        glVertex2i(pt2.x, pt2.y);
    glEnd();
}

void drawCurve (float x0 , float y0){
    const GLdouble twoPi=6.283185;
    const GLint a=175;
    
    GLfloat  theta, dtheta=1.0/float (a);
        screenpt curvept[2];
    
    glColor3f(0.0, 0.0, 0.0); //setting the color of curve
    
    curvept[0].x=x0; //setting initial curve position
    curvept[0].y=y0;
    
    
    theta=dtheta;
    while (theta< twoPi) {
       
         curvept[1].x=x0+70*cos(theta)*sin(2*theta);
         curvept[1].y=y0+70*sin(theta)*sin(2*theta);
        
        glColor3f(1.0, 0.0, 0.5);
        lineSegment(curvept[0], curvept[1]);
        
        curvept[0].x=curvept[1].x;
        curvept[0].y=curvept[1].y;
        theta +=dtheta;
    }
    glColor3f(0.0, 1.0, 0.0);
    curvept[0].x=x0;
    curvept[0].y=y0;
    curvept[1].x=x0;
    curvept[1].y=y0-80; // drawing the root line
    lineSegment(curvept[0], curvept[1]);

}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    float x=100 ;
    float y=150;
    
    glScaled (0.8, 1.2, 1);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(-648,160,0);
    glScaled (1, 1, 1);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(108,0,0);
    drawCurve(x,y);
    glTranslatef(-432,160,0);
    
    glScaled (1, 0.8, 1);
        drawCurve(x,y);
            glTranslatef(108,0,0);
        drawCurve(x,y);
                glTranslatef(108,0,0);
        drawCurve(x,y);
            glTranslatef(108,0,0);
        drawCurve(x,y);
            glTranslatef(-216,160,0);
    glScaled (1, 0.7, 1);
        drawCurve(x,y);
            glTranslatef(108,0,0);
    drawCurve(x,y);
    glFlush();
}

void reshape(GLint newWidth , GLint newHeight)
{
    //glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) newHeight, 0.0, (GLdouble) newHeight);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);    // set up the window position
    glutInitWindowSize(winWidth, winHeight); //set up window size
    glutCreateWindow("Garden");       // create the window  argv[0]
    
    init();                          // initialize the window
    glutDisplayFunc(display);        // call the display to draw the rectangles
    glutReshapeFunc(reshape);        // call the reshape function
				// (each time when the window size is changed)
    glutMainLoop();
    return 0;
}
