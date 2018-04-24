#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

int status = 0;

void init()
{
	//Initialise Ortho and clear previous color.
	glClearColor(1.0,1.0,1.0,1.0);
	gluOrtho2D(0,1000,0,1000);
}

void special(int key, int x, int y)
{
	switch(key)    // Switch case for key pressed.
	{
		case GLUT_KEY_UP :	status = 0;    // Status is updated.
							glutPostRedisplay();    // PostReDisplay for marking the current window as needing to be redisplayed.
							break;
		
		case GLUT_KEY_DOWN : status = 1;
							 glutPostRedisplay();
							 break;
	}
}

// Display a sample string.
void renderBitmapString(float x, float y, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
	glColor3f(0,0,0);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
} 

void display_paper()
{
	// First draw the paper and then draw the border.
	// Paper polygon - colored white.
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(320,725);
	glVertex2f(680,725);
	glVertex2f(680,950);
	glVertex2f(320,950);
	glEnd();
	// Draw the border with black lines.
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(320,725);
	glVertex2f(680,725);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(680,725);
	glVertex2f(680,950);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(680,950);
	glVertex2f(320,950);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(320,950);
	glVertex2f(320,725);
	glEnd();
	
	// Draw some sample lines in the paper.
	glBegin(GL_LINES);
	glVertex2f(330,930);
	glVertex2f(670,930);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(330,830);
	glVertex2f(670,830);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(330,745);
	glVertex2f(670,745);
	glEnd();
}

void display_base()
{
	// top base base
	glColor3f(0.2,0.3,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(250,750);
	glVertex2f(750,750);
	glVertex2f(900,400);
	glVertex2f(100,400);
	glEnd();
	
	// front base
	glColor3f(0.3,0.6,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(100,400);
	glVertex2f(100,200);
	glVertex2f(900,200);
	glVertex2f(900,400);
	glEnd();
	
	//Front paper out polygon
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(300,200);	
	glVertex2f(700,200);
	glVertex2f(700,250);
	glVertex2f(300,250);
	glEnd();
	
	// Front paper flap
	glColor3f(0.5,0.6,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(300,200);
	glVertex2f(700,200);
	glVertex2f(800,100);
	glVertex2f(200,100);
	glEnd();
	
	// Back Paper insert space
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(300,750);
	glVertex2f(700,750);
	glVertex2f(725,700);
	glVertex2f(275,700);
	glEnd();
	
	// Back flap
	glColor3f(0.5,0.6,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(300,750);
	glVertex2f(700,750);
	glVertex2f(700,900);
	glVertex2f(300,900);
	glEnd();

	// Draw the base legs.
	glColor3f(0.7, 0.5, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(120,200);
	glVertex2f(120,170);
	glVertex2f(140,170);
	glVertex2f(140,200);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(860,200);
	glVertex2f(860,170);
	glVertex2f(880,170);
	glVertex2f(880,200);
	glEnd();
}

void display_buttons()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.2, 0.3);
	glVertex2f(800,350);
	glColor3f(0.2, 1.2, 0.4);
	glVertex2f(850, 350);
	glColor3f(0.6, 0.3, 0.9);
	glVertex2f(850, 375);
	glColor3f(0.4, 0.2, 0.8);
	glVertex2f(800, 375);
	glEnd();

	// Draw borders...
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(800,350);
	glVertex2f(850, 350);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(850, 350);
	glVertex2f(850, 375);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(850, 375);
	glVertex2f(800, 375);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(800, 375);
	glVertex2f(800,350);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	display_base();
	display_buttons();
	glColor3f(0.0, 0.0, 0.0);
	renderBitmapString(360, 300, "PRINT PRINTERS");
	display_paper();
	// Paper translation by keys.
	if(status == 0)    // Paper up.
	{
		glTranslatef(0, 0, 0);    // Since the original coordinates of the paper is what is written, no translation for paper up.
		display_paper();
		glTranslatef(0, 0, 0);
	}
	else if (status == 1)    // Paper down
	{
		glTranslatef(0, -700, 0);    //Paper is pushed to the bottom of the printer paper out using appropriate translations.
		display_paper();
		glTranslatef(0, 700, 0);
		renderBitmapString(400, 150, "Document");
	}
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Printer");
	glutSpecialFunc(special);    // Special Function is used for reading keys.
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
