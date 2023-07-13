#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void reshape(int, int);
void init();
void timer(int);

// shapes functions
void cube(GLenum);

// Global variables
float x_position = -9.95;
float y_position = 0.0;
float z_position = 0.0;

int state = 1; // flag da func timer


int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 800); // Tamanho da janela

    glutCreateWindow("Projeto CG"); // Nome da janela
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // Viewport
    glutTimerFunc(0, timer, 0); // Animação
    init();

    glutMainLoop(); // Loop da janela
}

// Cor do background
void init(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.07, 0.13, 0.17, 1.0);
}

// O que aparece na tela
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    cube(GL_LINE_LOOP);

    glutSwapBuffers(); // Esvazia os Buffers
}

// Animação small circle
void timer(int ){
    glutPostRedisplay();
    glutTimerFunc(1000/90, timer, 0); // 90 frames por segundo

    // posição da figura
    switch(state){
        //ida
        case 1:
            if(x_position < 7.944)
                x_position += 0.1;

            else
                state = -1;

            break;
        // volta
        case -1:
            if(x_position > -9.95)
                x_position -= 0.1;

            else
                state = 1;

            break;
    }

}

// Config da viewport
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D((GLdouble) -10, (GLdouble) 10, (GLdouble) -10, (GLdouble) 10);
    glMatrixMode(GL_MODELVIEW);
}

// cubo
void cube(GLenum mode){
    glBegin(mode); // Inicio da renderização e tipo

    glVertex3f(x_position,  y_position + 1.0, z_position);
    glVertex3f(x_position + 2.0, y_position + 1.0, z_position);
    glVertex3f(x_position + 2.0, y_position - 1.0, z_position);
    glVertex3f(x_position, y_position - 1.0, z_position);

    glEnd(); // Fim da rederização
}
