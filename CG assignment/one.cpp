/*
1. A 5-meter ladder is initially standing upright against a wall. Its bottom end is at (0,0), and its top end is at (0,5). 

 a.  Now, the ladder undergoes the following transformations:. It is tilted 30◦ counterclockwise around its bottom end (0,0).

 b. Then, the entire ladder is moved (translated) so that its bottom end is now at (3,2).

 Apply necessary transformations and obtain the desired final figure.
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
    
    glVertex2f(0, 0);
    glVertex2f(0, 200); 
    
    
    
       
    glEnd();  
    /*                    // stop drawing
    glBegin(GL_LINE_STRIP);        
    glVertex2f(100, 0);
    int x= 100* cos(Degree(30)) - 200* sin(Degree(30));
    
    int y= 100* sin(Degree(30)) + 200* cos(Degree(30));
	glVertex2f(x,y);
	glEnd();
	*/
	
	glBegin(GL_LINE_STRIP);        
    glVertex2f(0, 0);
    int x= 0* cos(Degree(30)) - 200* sin(Degree(30));
    
    int y= 0* sin(Degree(30)) + 200* cos(Degree(30));
	glVertex2f(x,y);
	glEnd();
    glBegin(GL_LINE_STRIP);        
    glVertex2f( 150,100);
    
	glVertex2f(x+150,y+100);
	glEnd();
    glFlush();                    // show drawing on screen
}

// Initial settings
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
    gluOrtho2D(-500, 500, -500, 500); // 2D coordinate system
}

int main(int argc, char** argv)
{
    // Take input from user

    glutInit(&argc, argv);                    // start GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);             // window size
    glutCreateWindow("My First OpenGL Program");

    init();                                   // call init
    glutDisplayFunc(display);                 // call display
    glutMainLoop();                           // keep window open

    return 0;
}

