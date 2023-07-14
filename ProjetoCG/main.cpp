// Pra rodar no windows precisa dessa lib
#include <windows.h>

// Libs do OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/*
    Discentes: Kauan Souza Teles e Vítor Coutinho Lima

*/

// Protótipo das Funções
void display();
void reshape(int, int);
void init();
void anitmation(int);

// Função da figura
void square(GLenum);

// Váriavéis Globlais
float x_position = -9.95; // começa na borda esquerda
float y_position = 0.0; // no meio da janela

// Flags da função animation
int state = 1;
int st = 1;
int st2 = 1;

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 800); // Tamanho da janela

    glutCreateWindow("Projeto CG"); // Nome da janela
    glutDisplayFunc(display);

    glutReshapeFunc(reshape); // Viewport
    glutTimerFunc(0, anitmation, 0); // Animação

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

    glTranslatef(x_position, y_position, 0.0);
    square(GL_LINE_LOOP);

    glutSwapBuffers(); // Esvazia os Buffers
}

// Animação
void anitmation(int){
    glutPostRedisplay();
    glutTimerFunc(1000/90, anitmation, 0); //60 frames por segundo

    // posição da figura
    switch(state){
        //ida
        case 1:
            if(x_position < 9){
                x_position += 0.1;

                switch (st){
                    case 1:
                        if(y_position < 9)
                            y_position += 0.1;
                        else
                            st = -1;

                        break;

                    case -1:
                        if(y_position >= 0)
                            y_position -= 0.1;
                        else
                            st = 1;

                        break;
                }
            }
            else
                state = -1;

        break;
        // volta
        case -1:
            if(x_position > -9){
                x_position -= 0.1;

                switch (st2){
                    case 1:
                        if(y_position > -9)
                            y_position -= 0.1;
                        else
                            st2 = -1;

                        break;

                    case -1:
                        if(y_position <= 0)
                            y_position += 0.1;
                        else
                            st2 = 1;

                        break;
                }

            }
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

    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

// Quadrado
void square(GLenum mode){

    glBegin(mode); // Inicio da renderização e tipo

    glVertex2f(-1.0,  1.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);

    glEnd(); // Fim da rederização
}
