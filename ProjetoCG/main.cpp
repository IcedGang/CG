#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void reshape(int, int);
void init();

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 800); // Tamanho da janela

    glutCreateWindow("Projeto CG"); // Nome da janela
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // Viewport
    init();

    glutMainLoop(); // Loop da janela
}

// Cor do background
void init(){
    glClearColor(0.07, 0.13, 0.17, 1.0);
}

// O que aparece na tela
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON); // Inicio da renderização e tipo

    glVertex2f(0.0, 5.0);
    glVertex2f(-4.0, 3.0);
    glVertex2f(-4.0, -3.0);
    glVertex2f(0.0, -5.0);
    glVertex2f(4.0, -3.0);
    glVertex2f(4.0, 3.0);

    glEnd(); // Fim da rederização
    glFlush(); // Esvazia os Buffers
}

// Config da viewport
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLdouble) -10, (GLdouble) 10, (GLdouble) -10, (GLdouble) 10);
    glMatrixMode(GL_MODELVIEW);
}

