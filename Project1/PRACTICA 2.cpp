//Semestre 2018 - 1
// VERSION DE VISUAL STUDIO : 2015
//************** Alumno (s): Martinez Jarquin Ricardo Eduardo   
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar

	glPointSize(10.0f);						//tamaño del punto
	//glBegin(GL_POINTS);					//crea puntos
	//glBegin(GL_LINES);					// toma pares de puntos y crea las lineas
	//glBegin(GL_LINE_LOOP);                 //agrega las lineas necesarias para cerrar la figura dependiendo de los vertices
	//glBegin(GL_TRIANGLES);                   // toma solo tercia de vertices en imagen solida
	/*
	glBegin(GL_POLYGON);                       //toma en cuenta todos los vertices y lo pone en imagen solida
	glColor3f(0.5, 0.0 ,0.0);                          //color de los vertices
		glVertex3f(0.0f ,0.0f,-1.2f);        //v1
	glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-3.0f ,3.0f , -1.2f);     //v2
	glColor3f(0.0, 0.0, 1.0);
		glVertex3f(3.5f, 4.0f, -1.2f);       //v3
	glColor3f(0.3, 0.4, 0.8);
		glVertex3f(4.0f, -1.0f, -1.2f);      //v4
		glVertex3f(2.0f, -4.0f, -1.2f);      //v5
	glColor3f(0.9, 0.2, 0.3);
	   glVertex3f(13.5f, -3.0f, -1.2f);      //v6
	glEnd();
	*/
	/*
	glBegin(GL_LINE_LOOP);
	glVertex3f(1 ,1,-1.2);   //p0
	glColor3f(0.9, 0.2, 0.3);
	glVertex3f(1, 9, -1.2);  //p6
	glVertex3f(9, 9, -1.2);  //p2
	glVertex3f(9, 7, -1.2);  //p3
	glVertex3f(3,7, -1.2);  //p4
	glColor3f(0.0, 0.9, 0.0);
	glVertex3f(3, 3, -1.2);  //p5
	glVertex3f(9, 3, -1.2);  //p7
	glVertex3f(9, 1, -1.2);  //p1
	glEnd();
	

	// C con triangulos
	glTranslatef(0, -10, 0);

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1, 9, -1.2);  //p6
	glVertex3f(9, 9, -1.2);  //p2
	glVertex3f(9, 7, -1.2);  //p3
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(1, 9, -1.2);  //p6
	glVertex3f(9, 7, -1.2);  //p3
	glVertex3f(3, 7, -1.2);  //p4
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(1, 9, -1.2);  //p6
	glVertex3f(3, 7, -1.2);  //p4
	glVertex3f(1, 1, -1.2);   //p0
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(3, 3, -1.2);  //p5
	glVertex3f(3, 7, -1.2);  //p4
	glVertex3f(1, 1, -1.2);   //p0
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 1.0, 2.0);
	glVertex3f(3, 3, -1.2);  //p5
	glVertex3f(9, 3, -1.2);  //p7
	glVertex3f(1, 1, -1.2);   //p0
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 2.0, 8.0);
	glVertex3f(9, 1, -1.2);  //p1
	glVertex3f(9, 3, -1.2);  //p7
	glVertex3f(1, 1, -1.2);   //p0
	glEnd();
	*/

	//LETRA  c con trapecios

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1, 1, -1.2);   //p0
		glVertex3f(3, 3, -1.2);  //p5
		glVertex3f(3, 7, -1.2);  //p4
		glVertex3f(1, 9, -1.2);  //p6
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(1, 9, -1.2);  //p6
		glVertex3f(9, 9, -1.2);  //p2
		glVertex3f(9, 7, -1.2);  //p3
		glVertex3f(3, 7, -1.2);  //p4
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0, 0.0);
		glVertex3f(1, 1, -1.2);   //p0
		glVertex3f(9, 1, -1.2);  //p1
		glVertex3f(9, 3, -1.2);  //p7
		glVertex3f(3, 3, -1.2);  //p5
	glEnd();
	



	// LETRA R CON CONTORNO
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(14.0, 1.0, -1.2); //p0
		glVertex3f(14.0, 9.0, -1.2); //p1
		glVertex3f(23.0, 9.0, -1.2); //p5
		glVertex3f(23.0, 8.0, -1.2); //p6
		glVertex3f(17.0, 8.0, -1.2); //p7
		glVertex3f(17.0, 6.0, -1.2); //p3
		glVertex3f(17.0, 1.0, -1.2); //p4
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(23.0, 8.0, -1.2); //p6
		glVertex3f(20.0, 8.0, -1.2); //p8
		glVertex3f(20.0, 7.0, -1.2); //p9
		glVertex3f(17.0, 7.0, -1.2); //p10
		glVertex3f(17.0, 6.0, -1.2); //p3
		glVertex3f(23.0, 6.0, -1.2); //p11
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(17.0, 6.0, -1.2); //p3
		glVertex3f(18.5, 6.0, -1.2); //p12
		glVertex3f(23.0, 1.0, -1.2); //p13
		glVertex3f(20.0, 1.0, -1.2); //p14
	glEnd();



	// LETRA E CON POLIGONOS
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
		glVertex3f(28.0, 9.0, -1.2); //p1
		glVertex3f(37.0, 9.0, -1.2); //p2
		glVertex3f(37.0, 7.4, -1.2); //p3
		glVertex3f(31.0, 7.4, -1.2); //p4
		glVertex3f(31.0, 2.6, -1.2); //P5
		glVertex3f(31.0, 1.0, -1.2); //p6
		glVertex3f(28.0, 1.0, -1.2); //p0
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(31.0, 5.8, -1.2); //p7
		glVertex3f(37.0, 5.8, -1.2); //p8
		glVertex3f(37.0, 4.2, -1.2); //p9
		glVertex3f(31.0, 4.2, -1.2); //p10
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(31.0, 2.6, -1.2); //P5
		glVertex3f(37.0, 2.6, -1.2); //p11
		glVertex3f(37.0, 1.0, -1.2); //p12
		glVertex3f(31.0, 1.0, -1.2); //p6
	glEnd();




	// LETRA M CON CONTORNO
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 1.0);
		glVertex3f(42.0, 1.0, -1.2); //p0
		glVertex3f(42.0, 9.0, -1.2); //p1
		glVertex3f(45.0, 9.0, -1.2); //p2
		glVertex3f(46.5, 4.0, -1.2); //p3
		glVertex3f(48.0, 9.0, -1.2); //p4
		glVertex3f(51.0, 9.0, -1.2); //p5
		glVertex3f(51.0, 1.0, -1.2); //p6
		glVertex3f(48.0, 1.0, -1.2); //P7
		glVertex3f(48.0, 4.0, -1.2); //p8
		glVertex3f(46.5, 3.0, -1.2); //p9
		glVertex3f(45.0, 4.0, -1.2); //p10
		glVertex3f(45.0, 1.0, -1.2); //p11
	glEnd();
	


	// LETRA J CON POLIGONOS
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.7, 1.0);
		glVertex3f(56.0, 1.0, -1.2); //p0
		glVertex3f(62.0, 1.0, -1.2); //p1
		glVertex3f(62.0, 2.5, -1.2); //p2
		glVertex3f(59.0, 2.5, -1.2); //p3
		glVertex3f(59.0, 4.0, -1.2); //P4
		glVertex3f(56.0, 4.0, -1.2); //p5
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(62.0, 1.0, -1.2); //p1
		glVertex3f(65.0, 1.0, -1.2); //p6
		glVertex3f(65.0, 9.0, -1.2); //P7
		glVertex3f(62.0, 9.0, -1.2); //p8
		glVertex3f(62.0, 2.5, -1.2); //p2
	glEnd();



	// ESTRELLA DE 5 PICOS CON CUADRADOS

	glBegin(GL_QUADS);    //PICO 1 CENTRAL
	glColor3f(1.0, 1.0, -1.2);
		glVertex3f(33.0, -5.0, -1.2);
		glVertex3f(30.0, -15.0, -1.2);
		glVertex3f(33.0, -18.0, -1.2);
		glVertex3f(36.0, -15.0, -1.2);
	glEnd();

	glBegin(GL_QUADS);     //PICO DERECHO SUPERIOR
	glColor3f(1.0, 1.0, -1.2);
		glVertex3f(33.0, -18.0, -1.2);
		glVertex3f(36.0, -15.0, -1.2);
		glVertex3f(46.0, -15.0, -1.2);
		glVertex3f(37.0, -21.0, -1.2);
	glEnd();

	glBegin(GL_QUADS);     //PICO IZQUIERDO SUPERIOR
	glColor3f(1.0, 1.0, -1.2);
		glVertex3f(30.0, -15.0, -1.2);
		glVertex3f(33.0, -18.0, -1.2);
		glVertex3f(28.0, -21.0, -1.2);
		glVertex3f(20.0, -15.0, -1.2);
	glEnd();
	
	glBegin(GL_QUADS);      //PICO DERECHO INFERIOR
	glColor3f(1.0, 1.0, -1.2);
		glVertex3f(33.0, -18.0, -1.2);
		glVertex3f(37.0, -21.0, -1.2);
		glVertex3f(40.0, -31.0, -1.2);
		glVertex3f(33.0, -24.0, -1.2);
	glEnd();

	glBegin(GL_QUADS);    //PICO IZQUIERDO INFERIOR 
	glColor3f(1.0, 1.0, -1.2);
		glVertex3f(33.0, -18.0, -1.2);
		glVertex3f(28.0, -21.0, -1.2);
		glVertex3f(25.0, -31.0, -1.2);
		glVertex3f(33.0, -24.0, -1.2);
	glEnd();

	glFlush();
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

	// Ortogonal
	glOrtho(-5,70,-40,20,0.1,2);                      //(x minima, x maxima, y min, ymax)

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

