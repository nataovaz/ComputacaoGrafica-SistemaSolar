

#include <GL/glut.h>
#include <iostream>
#include "primitiva.h"

#include <math.h>

#include "texture.h"

//Constantes para movimentação da câmera com a setinha
GLfloat roll = 0, pitch = 0, yaw = 0;

//Inicializa as constantes com 0, para que seja passado como parâmetro das funções de textura
unsigned int g_TextureSol = 0;
unsigned int g_TextureMerc = 0;
unsigned int g_TextureVen = 0;
unsigned int g_TextureTerr = 0;
unsigned int g_TextureLua = 0;
unsigned int g_TextureMarte = 0;
unsigned int g_TextureJupiter = 0;
unsigned int g_TextureSat = 0;
unsigned int g_TextureAnel = 0;



void textura(void) {
    // enable texturing
    glEnable(GL_TEXTURE_2D);

    // tell openGL to generate the texture coords for a sphere map
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

    // enable automatic texture coordinate generation
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

}


void materiais(void) {

    glPushMatrix();
    GLfloat mat_diff[] = { 100.0, 100.0, 100.0, 0.0 };
    GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat shininess[] = { 2.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glPopMatrix();
}

void display()
{
    glClearColor(0.0, 0.15, 0.25, 1.0); // cor de fundo
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60.0f, 1.0f, 0.1f, 200.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 25.0,  //10.0, 10.0, 25.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);


    //Habilita iluminação
    glEnable(GL_LIGHTING); // Usa parâmetro da iluminação para calcular a cor do vértice do objeto.
    glEnable(GL_LIGHT0); // Inclui a fonte de luz i na equação de iluminação.
    glEnable(GL_COLOR_MATERIAL);

    //Cria de Luz Ambiente
    GLfloat ambient_color[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_color);


    //Fonte de Luz Pontual (x, y, z, 1)
    GLfloat point_pos[] = { 0.0, 0.0, 10.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, point_pos);

     //Fonte de Luz Spot
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45);
    GLfloat spot_dir[] = { 0.0, 10.0, 10.0, 1.0 }; //{-1.0, -1.0, -0.1}
    glLightfv(GL_LIGHT0, GL_POSITION, spot_dir);

    ////Parâmetros da fonte luminosa
    GLfloat light_ambient[] = { 0.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    GLfloat light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);


    ///Parâmetro do material
    GLfloat mat_diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 25.0);

    //Função para gerar o chão do cenário
    draw_floor();


    //Funções para rotacionar os objetos de acordo com as constantes
    glPushMatrix();
    glRotatef(roll, 1, 0, 0);  // Up and down arrow keys
    glRotatef(pitch, 0, 1, 0);  // Right/left arrow keys
    glRotatef(yaw, 0, 0, 1);  // q/w


    
    //Funções para habilitar os geradores de texturas.
    glEnable(GL_TEXTURE_2D);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

    
    //Função para gerar as estrelas do cenário que acompanham os planetas
    draw_stars();

    //Código capaz de aplicar a textura do sol, em bmp, e mapear todo o sólido esférico com a texture
    glBindTexture(GL_TEXTURE_2D, g_TextureSol);
    g_TextureSol = LoadTexture("sol.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(10, 0, -40.0);
    draw_sphere(12.0, 50, 50);
    glPopMatrix();


    //Código capaz de aplicar a textura do mercúrio, em bmp, e mapear todo o sólido esférico com a texture
    glBindTexture(GL_TEXTURE_2D, g_TextureMerc);
    g_TextureMerc = LoadTexture("merc.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(30, 0, -20.0);
    draw_sphere(2.0, 50, 50);
    glPopMatrix();


    

    //Código capaz de aplicar a textura do venus, em bmp, e mapear todo o sólido esférico com a texture
    glBindTexture(GL_TEXTURE_2D, g_TextureVen);
    g_TextureVen = LoadTexture("venus.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(70, 0, -13.0);
    draw_sphere(2.4, 50, 50);
    glPopMatrix();


    //Código capaz de aplicar a textura do planeta terra, em bmp, e mapear todo o sólido esférico com a texture
    glScalef(2.0, 2.0, 2.0);
    glBindTexture(GL_TEXTURE_2D, g_TextureTerr);
    g_TextureTerr = LoadTexture("terra.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(50, 0, 4);
    draw_sphere(5.0, 50, 50);
    glPopMatrix();


    //Código capaz de aplicar a textura do planeta marte, em bmp, e mapear todo o sólido esférico com a texture
    glBindTexture(GL_TEXTURE_2D, g_TextureMarte);
    g_TextureMarte = LoadTexture("marte.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(40, 0, 20);
    draw_sphere(4.0, 50, 50);
    glPopMatrix();

    
    //Código capaz de aplicar a textura do planeta jupiter, em bmp, e mapear todo o sólido esférico com a texture
    glBindTexture(GL_TEXTURE_2D, g_TextureJupiter);
    g_TextureJupiter = LoadTexture("jupiter.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(20, 0, 30);
    draw_sphere(8.0, 50, 50);
    glPopMatrix();



//Gera o planeta saturno, com a função pronta SolidSphere e a textura do planeta saturno, na posição (-5,0,30)
    glBindTexture(GL_TEXTURE_2D, g_TextureSat);
    g_TextureSat = LoadTexture("saturno.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-5, 0, 30.0);
    glutSolidSphere(5.0, 50, 50);
    glPopMatrix();


//Gera o anel de saturno, com a textura dos aneis de saturno, gerando na posição(-5,0,30)
//Vale ressaltar que, na elaboração do anel de saturno, há uma rotação de 60º para trazer realismo
    glBindTexture(GL_TEXTURE_2D, g_TextureSat);
    g_TextureAnel = LoadTexture("anel.bmp", true);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-5, 0, 30.0);
    glRotatef(60, 9, 8, 5);
    glutSolidTorus(1.0, 10.0, 19, 11);
    glPopMatrix();


    //Gera a chaleira na posição -27,0,27, em ordem após jupiter
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-27, 0, 27);
    glutSolidTeapot(8.0);
    glPopMatrix();


     //Gera um buraco negro emcima da câmera, com a função que plota um disco
    glScalef(2.0, 2.0, 2.0);
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0, 10, 0);
    glRotatef(80, 10, 0, 6);
    drawFilledCircle(10, 10, 5);
    glPopMatrix();
    

    //Gera a cubo na posição -40,0,20, em ordem após a chaleira
    glPushMatrix();
    glTranslatef(-40, 0, 20);
    glColor3f(0.7f, 0.3f, 0.0f);
    glutSolidCube(5.0);
    glPopMatrix();

    //Gera a cone na posição -40,0,20, em ordem após a chaleira
    glPushMatrix();
    glTranslatef(-40, 0, 5);
    glColor3f(0.2f, 0.3f, 0.6f);
    glutSolidCone(5.0,10.0,30,30);
    glPopMatrix();
 

    
    //Após realizar todo o display, desabilita as dunções de textura
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();

    glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y)
{
    switch (key) {

    case GLUT_KEY_LEFT:  pitch -= 5;  break;
    case GLUT_KEY_RIGHT:  pitch += 5;  break;
    case GLUT_KEY_UP:  roll -= 5;  break;
    case GLUT_KEY_DOWN:  roll += 5;  break;
    default: std::cout << "Keyboard " << key << std::endl;
    }

    glutPostRedisplay();
}

//Função especial para mover o cenário com as setinhas
void special_keys(int key, int x, int y)
{
    switch (key) {

    case GLUT_KEY_LEFT:  pitch -= 5;  break;
    case GLUT_KEY_RIGHT:  pitch += 5;  break;
    case GLUT_KEY_UP:  roll -= 5;  break;
    case GLUT_KEY_DOWN:  roll += 5;  break;
    default: std::cout << "Special key " << key << std::endl;
    }

    glutPostRedisplay();
}

//Função que permite a aplicação ser recursiva em seu tamanho
void reshapeFunc(int w, int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho(-4, 4, -4 * (GLfloat)h / (GLfloat)w, 4 * (GLfloat)h / (GLfloat)w, -4.0, 4.0);
    else
        glOrtho(-4 * (GLfloat)w / (GLfloat)h, 4 * (GLfloat)w / (GLfloat)h, -4, 4, -4, 4.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Trabalho prático");
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(300, 100);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_keys);
    glutReshapeFunc(reshapeFunc);

    
   
    glutMainLoop();

    system("pause");

    return 0;
}
