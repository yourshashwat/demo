/*
2. Create and rotate a triangle about the origin and a fixed point.

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
	vector<pair<int,int>> P;
	P.push_back({100,100});
	P.push_back({500,100});
	P.push_back({300,350});
    glBegin(GL_LINE_LOOP);        // start drawing lines
    /*
    for(auto &p: P){
    	glVertex2f(p.first, p.second);
    }
    
    glEnd();  
    
    glBegin(GL_LINE_LOOP);        // start drawing lines
    
    for(auto &p: P){
    	double x = p.first * cos(Degree(120)) - p.second * sin(Degree(120));
		double y = p.first * sin(Degree(120)) + p.second * cos(Degree(120));
    	glVertex2f(x,y);
    }
    
    glEnd();  
    
    glBegin(GL_LINE_LOOP);        // start drawing lines
    
    for(auto &p: P){
    	double x = p.first * cos(Degree(210)) - p.second * sin(Degree(210));
		double y = p.first * sin(Degree(210)) + p.second * cos(Degree(210));
    	glVertex2f(x,y);
    }
    
    glEnd();
    */
    
    for(int i=0; i<=360; i+=50){
    
    glBegin(GL_LINE_LOOP);        // start drawing lines
    
    for(auto &p: P){
    	double x = p.first * cos(Degree(i)) - p.second * sin(Degree(i));
		double y = p.first * sin(Degree(i)) + p.second * cos(Degree(i));
    	glVertex2f(x,y);
    }
    
    glEnd();
    }
    
    
    glFlush();                    // show drawing on screen
}

// Initial settings
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
    gluOrtho2D(-500, 600, -500, 500); // 2D coordinate system
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

