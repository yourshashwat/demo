/*
3.Reflect a line first about the x-axis and then about the y-axis.

*/


#include <GL/glut.h>   // GLUT library
#include <iostream>   // for input/output
#include <bits/stdc++.h>

using namespace std;

double Degree(double angle) {
    double radians = angle * 3.14 / 180.0;
    return radians;
}

// This function draws on the window
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	glColor3f(1.0, 1.0, 1.0);
	
	glBegin(GL_LINE_STRIP);        // start drawing lines
    
    glVertex2f(-500,0);
    glVertex2f(500,0);
    glEnd();
    glBegin(GL_LINE_STRIP);
     glVertex2f(0,-500);
    glVertex2f(0,500);
    glEnd();
    
    glBegin(GL_LINE_STRIP);        // start drawing lines
    
    glVertex2f(100,100);
    glVertex2f(300,400);
    glEnd();
    
    glBegin(GL_LINE_STRIP);        // start drawing lines
    
    glVertex2f(100,-100);
    glVertex2f(300,-400);
    glEnd();
    
    glBegin(GL_LINE_STRIP);        // start drawing lines
    
    glVertex2f(-100,-100);
    glVertex2f(-300,-400);
    glEnd();
    
    glFlush();                    // show drawing on screen
}

// Initial settings
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
    gluOrtho2D(-600, 600, -600, 600); // 2D coordinate system
}

int main(int argc, char** argv)
{
    // Take input from user

    glutInit(&argc, argv);                    // start GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 1200);             // window size
    glutCreateWindow("My First OpenGL Program");

    init();                                   // call init
    glutDisplayFunc(display);                 // call display
    glutMainLoop();                           // keep window open

    return 0;
}

