//Semestre 2017 - 2
//******************************************************************//
//******************************************************************//
//************** Alumno (s): Martinez Jarquin Ricardo Eduardo  *****//
//*************	                                              ******//
//*************	 Grurpo: 05							          ******//
//******************************************************************//
#include "Main.h"


float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;

float angleX = 0.0f;
float angleY = 0.0f;

int screenW = 0.0;
int screenH = 0.0;

float movhombro = 0.0f;
float movcodo = 0.0f;
float movindi1 = 0.0f;
float movindi2 = 0.0f;
float movpulgar1 = 0.0f;
float movpulgar2 = 0.0f;
float movmedio1 = 0.0f;
float movmedio2 = 0.0f;
float movmeñi1 = 0.0f;
float movmeñi2 = 0.0f;

//GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
//GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	
	//Configuracion luz
	/*glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	*/
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void prismaB(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		
	glTranslatef(transX, transY, transZ);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	
	
	// Pecho
	glPushMatrix();
		glScalef(6.0, 5.0, 1.0);
		prisma(); 
	glPopMatrix();
	
	// Cuello
	glPushMatrix();
		glTranslatef(0.0, 3.0, 0.0);
		glPushMatrix();
			glScalef(0.5, 1.0, 1.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			prisma(); 
		glPopMatrix();

		// Cabeza
		glTranslatef(0.0, 2.0, 0.0);
		glScalef(2.0, 3.0, 1.0);
		prisma();  
	glPopMatrix();

	// Hombro Derecho
	glPushMatrix();
		glTranslatef(3.5, 1.75, 0.0);
		glScalef(1.0, 1.5, 1.0);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		prisma();
	glPopMatrix();

	// Hombro Izquierdo
	glPushMatrix();
		glTranslatef(-4.0, 1.75, 0.0);
		glScalef(2.0, 1.5, 1.0);
		glRotatef(180.0, 0.0, 0.0, 0.0);
		prisma();
	glPopMatrix();
	
	// Brazo Derecho
	glPushMatrix();                           // Cuenta desde el origen (0,0)
	
	// Antebrazo
		glTranslatef(4.5, 2.5, 0.0);           // Punto de rotacion del hombro
		glRotatef(movhombro, 1.0, 0.0, 0.0);   // Movienmiento del hombro sobre el eje X desde -190° hasta 10° 
		glTranslatef(0.0, -1.25, 0.0);         // Centro del prisma A
		glPushMatrix();                        // Cuenta desde el centro del prisma A
			glScalef(1.0, 2.5, 1.0);
			glColor3f(0.0, 1.0, 0.0);
			prismaB();                         // Prisma A
		glPopMatrix();

	// Brazo
		glTranslatef(0.0, -1.25, 0.0);         // Punto de rotación del codo entre A y B 
		glRotatef(movcodo, 1.0, 0.0, 0.0);     // Rotacion del codo sobre eje X  0° a 90° y de 90° a 0°
		glTranslatef(0.0, -1.0, 0.0);          // Centro del prisma B
		glPushMatrix();
			glScalef(1.0, 2.0, 1.0);
			glColor3f(0.1, 0.0, 0.5);
			prismaB();                          // Prisma B
		glPopMatrix();
		
	// Dedo Indice
	glPushMatrix();                            // Regresamos al centro del prisma B
		glTranslatef(0.35, -1.0, 0.375);       // Punto de rotación del dedo indice1 entre B y C
		glRotatef(movindi1, 0.0, 0.0, 1.0);    // Rotacion del pulgar de sobre eje Z  50° > 0° < -90°
		glTranslated(0.0, -0.375, 0.0);        // Centro de Prisma C
		glPushMatrix();
			glScalef(0.3, 0.75, 0.25);
			glColor3f(0.1, 0.5, 0.1);
			prismaB();                         //  Prisma C
		glPopMatrix();
		
		glTranslatef(0.0, -0.375, 0.0);        //Punto de rotación del dedo medio2 entre C y D
		glRotatef(movindi2, 0.0, 0.0, 1.0);    // Rotacion del dedo indice2 sobre eje Z  50° > 0° < -90°
		glTranslated(0.0, -0.5, 0.0);          // Centro de Prisma D
		glScalef(0.3,1.0, 0.25);
		glColor3f(0.1, 0.5, 0.1);
		prismaB();                            // Prisma D
	glPopMatrix();
	
	// Dedo Pulgar
	glPushMatrix();                            // Regresamos al centro del prisma B
		glTranslatef(-0.35, -1.0, 0.375);      // Punto de rotación del dedo pulgar entre B y E
		glRotatef(movpulgar1, 0.0, 0.0, 1.0);  // Rotacion del pulgar de sobre eje Z de 0° a 90°
		glTranslated(0.0, -0.375, 0.0);        // Centro de Prisma E
		glPushMatrix();
			glScalef(0.3, 0.75, 0.25);
			glColor3f(0.2, 0.5, 0.7);
			prismaB();                           //  Prisma E
		glPopMatrix();

		glTranslatef(0.0, -0.375, 0.0);         //Punto de rotación del dedo pulgar2 entre E y F
		glRotatef(movpulgar2, 0.0, 0.0, 1.0);   // Rotacion del pulgar de sobre eje Z de 0° a 90°
		glTranslated(0.0, -0.375, 0.0);         // Centro de Prisma F
		glScalef(0.3, 0.75, 0.25);
		glColor3f(0.2, 0.5, 0.2);
		prismaB();                              // Prisma F
	glPopMatrix();
	
	// Dedo Medio
	glPushMatrix();                            // Regresamos al centro del prisma B
		glTranslatef(0.35, -1.0, 0.0);         // Punto de rotación del dedo medio1 entre B y G
		glRotatef(movmedio1, 0.0, 0.0, 1.0);   // Rotacion del pulgar de sobre eje Z de 0° a 90°
		glTranslated(0.0, -0.5, 0.0);          // Centro de Prisma G
		glPushMatrix();
			glScalef(0.3, 1.0, 0.25);
			glColor3f(1.0, 0.5, 0.0);
			prismaB();                          //  Prisma G
		glPopMatrix();

		glTranslatef(0.0, -0.5, 0.0);          //Punto de rotación del dedo medio2 entre G y H
		glRotatef(movmedio2, 0.0, 0.0, 1.0);   // Rotacion del pulgar de sobre eje Z de 0° a 90°
		glTranslated(0.0, -0.75, 0.0);         // Centro de Prisma H
		glScalef(0.3, 1.5, 0.25);
		glColor3f(1.0, 0.5, 0.0);
		prismaB();                             // Prisma H
	glPopMatrix();
	
	// Dedo Meñique
	glPushMatrix();                         // Regresamos al centro del prisma B
		glTranslatef(0.35, -1.0, -0.375);          // Punto de rotación del dedo meñique1 entre B y I
		glRotatef(movmeñi1, 0.0, 0.0, 1.0);   // Rotacion del mañique de sobre eje Z de 0° a 90°
		glTranslated(0.0, -0.5, 0.0);           // Centro de Prisma I
		glPushMatrix();
			glScalef(0.3, 1.0, 0.25);
			glColor3f(0.5, 0.0, 0.0);
			prismaB();                          //  Prisma I
		glPopMatrix();

		glTranslatef(0.0, -0.5, 0.0);          //Punto de rotación del dedo meñique2 entre I y J
		glRotatef(movmeñi2, 0.0, 0.0, 1.0);  // Rotacion del meñique de sobre eje Z de 0° a 90°
		glTranslated(0.0, -0.5, 0.0);         // Centro de Prisma J
		glScalef(0.3, 1.0, 0.25);
		glColor3f(0.5, 0.0, 0.0);
		prismaB();                             // Prisma J
	glPopMatrix();
	
	glPopMatrix();
	
	// Brazo Izquierdo
	glPushMatrix();
	glTranslatef(-4.5, -1.5, 0.0);
	glScalef(1.0, 6.0, 1.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();
	
	// Cadera
	glPushMatrix();
	glTranslatef(0, -3.0, 0.0);
	glScalef(6.0, 1.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prisma();
	glPopMatrix();

	// Pierna Izquierda
	glPushMatrix();
	glTranslatef(-2.0, -6.5, 0.0);
	glScalef(2.0, 6.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 1.0);
	prisma();
	glPopMatrix();

	// Pierna Derecha
	glPushMatrix();
	glTranslatef(2.0, -6.5, 0.0);
	glScalef(2.0, 6.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 1.0);
	prisma();
	glPopMatrix();

	// Zapato Derecho
	glPushMatrix();
	glTranslatef(2.35, -10.25, 0.0);
	glScalef(2.75, 1.5, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prisma();
	glPopMatrix();
	
	// Zapato Izquierdo
	glPushMatrix();
	glTranslatef(-2.35, -10.25, 0.0);
	glScalef(2.75, 1.5, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prisma();
	glPopMatrix();
	
	// Empuñadura
	glPushMatrix();
	glTranslatef(-6.0, -5.0, 0.0);
	glScalef(4.75, 1.0, 1.0);
	glRotatef(180.0, 0.0, 1.0, 1.0);
	prisma();
	glPopMatrix();
	
	// Pico
	glPushMatrix();
	glTranslatef(-7.87, -5.0, 0.0);
	glScalef(0.75, 2.0, 1.0);
	glRotatef(180.0, 0.0, 1.0, 1.0);
	prisma();
	glPopMatrix();


	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'd':
		case 'D':
			transX -=0.3f;
			break;
		case 'a':
		case 'A':
			transX += 0.3f;
			break;
		case 'w':
		case 'W':
			transY -= 0.3f;
			break;
		case 's':
		case 'S':
			transY += 0.3f;
			break;
		case 'e':
		case 'E':
			transZ -= 0.3f;
			break;
		case 'q':
		case 'Q':
			transZ += 0.3f;
			break;
		case '1':
			if (-190 < movhombro )
				movhombro -= 2.0;
			break;
		case '2':
			if (movhombro < 0)
				movhombro += 2.0;
			break;
		case '3':
			if (-90 < movcodo)
				movcodo -= 2.0;
			break;
		case '4':
			if (movcodo < 0)
				movcodo += 2.0;
			break;
		case '5':
			if (movindi1 >= -50)
				movindi1 -= 2.0;

			if (50 >= movpulgar1)
				movpulgar1 += 2.0;

			if (movmedio1 >= -50)
				movmedio1 -= 2.0;

			if (movmeñi1 >= -50)
				movmeñi1 -= 2.0;
			break;

		case '6':
			if (movindi1 < 0)
				movindi1 += 2.0;

			if (movpulgar1 >= 0)
				movpulgar1 -= 2.0;

			if (movmedio1 < 0)
				movmedio1 += 2.0;

			if (movmeñi1 < 0)
				movmeñi1 += 2.0;
			break;

		case '7':
			if (movindi2 >= -50)
				movindi2 -= 2.0;

			if (50 >= movpulgar2)
				movpulgar2 += 2.0;

			if (movmedio2 >= -50)
				movmedio2 -= 2.0;

			if (movmeñi2 >= -50)
				movmeñi2 -= 2.0;
			break;

		case '8':
			if (movindi2 < 0)
				movindi2 += 2.0;

			if (movpulgar2 >= 0)
				movpulgar2 -= 2.0;

			if (movmedio2 < 0)
				movmedio2 += 2.0;

			if (movmeñi2 < 0)
				movmeñi2 += 2.0;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}