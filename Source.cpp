/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

 /*
  * robot.c
  * This program shows how to composite modeling transformations
  * to draw translated and rotated hierarchical models.
  * Interaction:  pressing the s and e keys (shoulder and elbow)
  * alters the rotation of the robot arm.
  */

#include <stdlib.h>
#include <glut.h>
#include <math.h>
#define PI 3.14

double eye[] = { 0.0, 0.0, 5.0 };
double center[] = { 0.0, 0.0, 0.0 };
double up[] = { 0.0, 1.0, 0.0 };


static int shoulder_r = -45, shoulder_r2 = 0, shoulder_l2 = 0, elbow_r = 0,shoulder_l=45,elbow_l=0,all_right_leg=-90, all_right_leg2 =0,lower_right_leg=0, all_left_leg = 90, all_left_leg2 = 0, lower_left_leg = 0, fingerBase = 0, fingerUp = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0,
        1.0,
        1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}




void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2],
        center[0], center[1], center[2],
        up[0], up[1], up[2]);
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
   // glScalef(1.0, 1.0, 1.0);
    //glTranslatef(0.0, 0.0, 0.0);
    ////////////////////////////////////
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);     // face
    glutWireSphere(0.3, 8.0, 8.0);
    glPopMatrix();
    //////////////////////////////////////
    glPushMatrix();
    glScalef(0.8, 1.2, 0.4);  // body
    glutWireCube(1);
    glPopMatrix();
    //////////////////////////////////////
    //Right leg
    /////////////////////////////////////
    // upper leg
    glPushMatrix();
    glTranslatef(0.3, -0.6, 0.0);
    glRotatef((GLfloat)all_right_leg, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)all_right_leg2, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.4);
    glutWireCube(1.0);
    glPopMatrix();
    //lower leg
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)lower_right_leg, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.4);
    glutWireCube(1.0);
    glPopMatrix();
    //shoes
    glTranslatef(0.7,0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.3, 0.6);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////////////////////////
    //left leg
    ////////////////////////////////////

    glPushMatrix();
    glTranslatef(-0.3, -0.6, 0.0);
    glRotatef((GLfloat)all_left_leg, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)all_left_leg2, 0.0, 1.0, 0.0);
    glTranslatef(-0.3, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.4);
    glutWireCube(1.0);
    glPopMatrix();
    //lower leg
    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef((GLfloat)lower_left_leg, 0.0, 1.0, 0.0);
    glTranslatef(-0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.4);
    glutWireCube(1.0);
    glPopMatrix();
    //shoes
    glTranslatef(-0.7, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.3, 0.6);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();




   
    /////////////////////////////////////////////


    // RIGHT ARM WITH FINGERS 

    //////////////////////////////////////

    glPushMatrix();
    glTranslatef(0.4, 0.5, 0.0);
    glRotatef((GLfloat)shoulder_r, 0.0, 0.0, 1.0);
  
    glRotatef((GLfloat)shoulder_r2, 1.0, 0.0, 0.0);
    glTranslatef(0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)elbow_r, 0.0, 1.0, 0.0);
    glTranslatef(0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    

    //fingers

    glPushMatrix();///// first push

    //Draw finger flang 1 
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 1 
   // glTranslatef(0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix(); ///// first pop

    
    //////////////

    glPushMatrix();

    //finger 2 

    glTranslatef(0.4, 0.0, 0.2);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 2
    //glTranslatef(0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    
    ///////////////////////////////////////
    glPushMatrix();
    //finger 3

    glTranslatef(0.4, 0.0, -0.2);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 3
    //glTranslatef(0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////
    

    glPushMatrix();
    //finger 4

    glTranslatef(0.4, -0.1, -0.1);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 4
   // glTranslatef(0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    //////////////////////////////////

    //LEFT ARM WITH FINGERS

    /////////////////////////////////
    glPushMatrix();
    glTranslatef(-0.4, 0.5, 0.0);
    glRotatef((GLfloat)shoulder_l, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)shoulder_l2, 1.0, 0.0, 0.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(-0.4, 0.0, 0.0);
    glRotatef((GLfloat)elbow_l, 0.0, 1.0, 0.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.3);
    glutWireCube(1.0);
    glPopMatrix();

    //fingers

    glPushMatrix();///// first push

    //Draw finger flang 1 
    glTranslatef(-0.4, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 1 
    //glTranslatef(-0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix(); ///// first pop


    //////////////

    glPushMatrix();

    //finger 2 

    glTranslatef(-0.4, 0.0, 0.2);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 2
    //glTranslatef(-0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////////
    glPushMatrix();
    //finger 3

    glTranslatef(-0.4, 0.0, -0.2);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 3
   // glTranslatef(-0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////

    glPushMatrix();
    //finger 4

    glTranslatef(-0.4, -0.1, -0.1);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 4
   // glTranslatef(-0.1, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////////////






    ////////////////////////
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}


static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}


void rotatePoint(double a[], double theta, double p[])
{

    double temp[3];
    temp[0] = p[0];
    temp[1] = p[1];
    temp[2] = p[2];

    temp[0] = -a[2] * p[1] + a[1] * p[2];
    temp[1] = a[2] * p[0] - a[0] * p[2];
    temp[2] = -a[1] * p[0] + a[0] * p[1];

    temp[0] *= sin(theta);
    temp[1] *= sin(theta);
    temp[2] *= sin(theta);

    temp[0] += (1 - cos(theta)) * (a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
    temp[1] += (1 - cos(theta)) * (a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
    temp[2] += (1 - cos(theta)) * (a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

    temp[0] += cos(theta) * p[0];
    temp[1] += cos(theta) * p[1];
    temp[2] += cos(theta) * p[2];

    p[0] = temp[0];
    p[1] = temp[1];
    p[2] = temp[2];

}


void crossProduct(double a[], double b[], double c[])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
    double norm;
    norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    norm = sqrt(norm);
    a[0] /= norm;
    a[1] /= norm;
    a[2] /= norm;
}

// Rotation about vertical direction
void lookRight()
{
    rotatePoint(up, PI / 4, eye);
}

void lookLeft()
{
    rotatePoint(up,  -PI / 4, eye);
    
}

void lookUp()
{
    double horizontal[3];
    double look[] = { center[0] - eye[0], center[1] - eye[1], center[2] - eye[2] };
    crossProduct(up, look, horizontal);
    normalize(horizontal);
    rotatePoint(horizontal, PI / 4, eye);
    rotatePoint(horizontal, PI / 4, up);
}

void lookDown()
{
    double horizontal[3];
    double look[] = { center[0] - eye[0], center[1] - eye[1], center[2] - eye[2] };
    crossProduct(up, look, horizontal);
    normalize(horizontal);
    rotatePoint(horizontal, -PI / 4, eye);
    rotatePoint(horizontal, -PI / 4, up);
}

void moveForward()
{
    double look[3];
    look[0] = center[0] - eye[0];
    look[1] = center[1] - eye[1];
    look[2] = center[2] - eye[2];
    float speed = 0.2;
    eye[0] += look[0] * speed;
    eye[1] += look[1] * speed;
    eye[2] += look[2] * speed;

    center[0] += look[0] * speed;
    center[1] += look[1] * speed;
    center[2] += look[2] * speed;
}

void moveBackword()
{
    double look[3];
    look[0] = center[0] - eye[0];
    look[1] = center[1] - eye[1];
    look[2] = center[2] - eye[2];
    float speed = -0.2;
    eye[0] += look[0] * speed;
    eye[1] += look[1] * speed;
    eye[2] += look[2] * speed;

    center[0] += look[0] * speed;
    center[1] += look[1] * speed;
    center[2] += look[2] * speed;
}


void reset()
{
    double e[] = { 0.0, 0.0, 5.0 };
    double c[] = { 0.0, 0.0, 0.0 };
    double u[] = { 0.0, 1.0, 0.0 };
    for (int i = 0; i < 3; i++)
    {
        eye[i] = e[i];
        center[i] = c[i];
        up[i] = u[i];
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':

        if (shoulder_r < 90) {
            shoulder_r = (shoulder_r + 5) % 360;
            glutPostRedisplay();
        }

        break;
    case 'S':
        if (shoulder_r >= -110 && shoulder_r <= 110) {
            shoulder_r = (shoulder_r - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'o':

        if (shoulder_r2 >= -100 && shoulder_r2 < 90) {
            shoulder_r2 = (shoulder_r2 + 5) % 360;
            glutPostRedisplay();
        }

        break;
    case 'O':
        if (shoulder_r2 > -95 && shoulder_r2 <= 95) {
            shoulder_r2 = (shoulder_r2 - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'c':

        if (shoulder_l2 <= 100 && shoulder_l2 >= -100) {
            shoulder_l2 = (shoulder_l2 + 5) % 360;
            glutPostRedisplay();
        }

        break;
    case 'C':
        if (shoulder_l2 <= 105 && shoulder_l2 >= -95) {
            shoulder_l2 = (shoulder_l2 - 5) % 360;
            glutPostRedisplay();
        }

        break;
    case 'Z':

        if (shoulder_l <= 105) {
            shoulder_l = (shoulder_l + 5) % 360;
            glutPostRedisplay();
        }

        break;
    case 'z':
        if (shoulder_l >= -85 && shoulder_l <= 110) {
            shoulder_l = (shoulder_l - 5) % 360;
            glutPostRedisplay();
        }

        break;


    case 'e':
        if (elbow_r < 120) {
            elbow_r = (elbow_r + 5) % 360;
            glutPostRedisplay();
        }




        break;
    case 'E':

        if (elbow_r <= 120 && elbow_r >= -120) {
            elbow_r = (elbow_r - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'P':
        if (elbow_l < 120) {
            elbow_l = (elbow_l + 5) % 360;
            glutPostRedisplay();
        }


        break;
    case 'p':

        if (elbow_l <= 120 && elbow_l >= -120) {
            elbow_l = (elbow_l - 5) % 360;
            glutPostRedisplay();
        }

        break;
        /*  case 'f':
              if (fingerBase < 10) {
                  fingerBase = (fingerBase + 5) % 360;
                  glutPostRedisplay();
              }

              break;
          case 'F':
              if (fingerBase <= 10 && fingerBase > -10) {
                  fingerBase = (fingerBase - 5) % 360;
                  glutPostRedisplay();
              }

              break;*/
    case 'l':
        if (all_left_leg <= 120 && all_left_leg >= 10) {
            all_left_leg = (all_left_leg - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'L':
        if (all_left_leg < 120) {
            all_left_leg = (all_left_leg + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'M':
        if (all_left_leg2 <= 100 && all_left_leg2 > -60) {
            all_left_leg2 = (all_left_leg2 - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'm':
        if (all_left_leg2 < 100) {
            all_left_leg2 = (all_left_leg2 + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'n':
        if (all_right_leg2 >= -95 && all_right_leg2 <= 65) {
            all_right_leg2 = (all_right_leg2 - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'N':
        if (all_right_leg2 <60) {
            all_right_leg2 = (all_right_leg2 + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'R':
        if (all_right_leg <= 0 && all_right_leg >= -120) {
            all_right_leg = (all_right_leg - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'r':
        if (all_right_leg <= -10) {
            all_right_leg = (all_right_leg + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'g':
        if (lower_right_leg <= 120 && lower_right_leg >= -120) {
            lower_right_leg = (lower_right_leg - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'G':
        if (lower_right_leg < 90) {
            lower_right_leg = (lower_right_leg + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'A':
        if (lower_left_leg <= 125 && lower_left_leg >= -85) {
            lower_left_leg = (lower_left_leg - 5) % 360;
            glutPostRedisplay();
        }

        break;

    case 'a':
        if (lower_left_leg <= 120) {
            lower_left_leg = (lower_left_leg + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'f':
        moveForward();
        glutPostRedisplay();
        break;
     
    
    case 'b':
        moveBackword();
        glutPostRedisplay();
        break;

    case 'j':
        reset();
        glutPostRedisplay();
        break;
            /*
        case 'g':
            if (fingerUp < 10) {
                fingerUp = (fingerUp + 5) % 360;
                glutPostRedisplay();

            }
            break;
            /**
        case 'G':
            if (fingerUp <= 10 && fingerUp > -110) {
                fingerUp = (fingerUp - 5) % 360;
                glutPostRedisplay();

            }
            break;*/

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}


void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        lookLeft();
        break;
    case GLUT_KEY_RIGHT:
        lookRight();
        break;
    case GLUT_KEY_UP:
        lookUp();
        break;
    case GLUT_KEY_DOWN:
        lookDown();
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    
    glutReshapeFunc(reshape);
    
   // glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}