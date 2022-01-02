#include<vector>
#include<cmath>

#include <GL/freeglut.h>

//Constante float PI, para definir objetos esféricos
const float M_PI = 3.14159265359;


void draw_floor()
{
    const double sideLen = 50.0;
    const double y = -50.0;
    const int n = 10;
    int i, j;

    glPushMatrix();
    glTranslatef(-50.0, 2.0, -50.0);
    glTranslated(-sideLen * float(n) / 2.0f, y, 100.0f);
    for (j = 0; j < n; ++j) {
        for (i = 0; i < n; ++i) {
            if ((i ^ j) & 1) {
                glColor4d(0.0, 0.0, 1.0, 1.0);
            }
            glBegin(GL_QUADS);
            glVertex3d(i * sideLen, 0.0, -j * sideLen);
            glVertex3d(i * sideLen + sideLen, 0.0, -j * sideLen);
            glVertex3d(i * sideLen + sideLen, 0.0, -j * sideLen + sideLen);
            glVertex3d(i * sideLen, 0.0, -j * sideLen + sideLen);
            glEnd();
        }
    }
    glPopMatrix();
}



void draw_sphere(float r, int lats, int longs) {
    int i, j;

    for (i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double)(i + 1) / lats);
        double z0 = sin(lat0);
        double zr0 = cos(lat0);

        double lat1 = M_PI * (-0.5 + (double)i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= longs; j++) {
            double lng = 2 * M_PI * (double)(j + 1) / longs;
            double x = cos(lng);
            double y = sin(lng);

            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(r * x * zr0, r * y * zr0, r * z0);
            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(r * x * zr1, r * y * zr1, r * z1);
        }
        glEnd();
    }
}


void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {

    int i;
    int triangleAmount = 20; //# números de triangulos utilizados para a formação do disco

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // centro do círculo
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

//Função geradora do sólido Icosaedro com a cor amarela, 
//para trazer a impressão das estrelas no espaço
void draw_stars() {
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(-5, 10, 30);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(20, -15, 30);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(40, 15, 20);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(50, -15, 4);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(50, 15, 4);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(70, 10, -13);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0, 15, -30);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(30, 7, -30);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(-40, -15, -30);
    glScalef(1, 1, 1);
    glutSolidIcosahedron();
    glPopMatrix();
}