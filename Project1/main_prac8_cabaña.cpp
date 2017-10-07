//Semestre 2012 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Ricardo Eduardo Martinez Jarquin**//
//*************											******//
//*************											******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture madera;
CTexture barda;
CTexture piso;
CTexture muro;
CTexture ventana;
CTexture viga;
CTexture puerta;
CTexture teja;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	madera.LoadTGA("madera.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	piso.LoadTGA("piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	barda.LoadBMP("barda.bmp");
	barda.BuildGLTexture();
	barda.ReleaseImage();

	muro.LoadBMP("muro.bmp");
	muro.BuildGLTexture();
	muro.ReleaseImage();

	ventana.LoadBMP("ventana.bmp");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();

	viga.LoadBMP("viga.bmp");
	viga.BuildGLTexture();
	viga.ReleaseImage();

	puerta.LoadTGA("puerta.tga");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	teja.LoadBMP("teja.bmp");
	teja.BuildGLTexture();
	teja.ReleaseImage();

}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}


void prisma1(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
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


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}
void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
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

		
		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 3.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 3.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}
void prisma2(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
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


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();
	
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 2.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 2.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}
void prisma3(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
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


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);    //modificacion
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);   //modificacion
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void Techo()
{
	glPushMatrix();
	//glDisable(GL_LIGHTING);

	//piso
	glBindTexture(GL_TEXTURE_2D, piso.GLindex);
	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0.0, 0);//1
	glTexCoord2f(1.0f, 0.0f); glVertex3f(20, 0.0, 0);//2
	glTexCoord2f(1.0f, 4.0f); glVertex3f(20, 0.0, -19);//3  
	glTexCoord2f(0.0f, 4.0f); glVertex3f(0, 0.0, -19); 
	glEnd();

	// Frente
	glBindTexture(GL_TEXTURE_2D, muro.GLindex);
	glBegin(GL_TRIANGLES);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0.0, 0);//1
	glTexCoord2f(0.0f, 8.0f); glVertex3f(20, 0.0, 0);//2
	glTexCoord2f(0.5f, 4.0f); glVertex3f(10, 5.0, 0);//3  
	glEnd();

	//Atras
	glTranslatef(0, 0, -19);
	glBindTexture(GL_TEXTURE_2D, muro.GLindex);
	glBegin(GL_TRIANGLES);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0.0, 0);//1
	glTexCoord2f(0.0f, 8.0f); glVertex3f(20, 0.0, 0);//2
	glTexCoord2f(0.5f, 4.0f); glVertex3f(10, 5.0, 0);//3  
	glEnd();

	//Techo
	glBindTexture(GL_TEXTURE_2D, teja.GLindex);
	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);//1
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10, 5.0, 0);//2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10, 5.0, 19);//3 
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 0.0, 19);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10, 5.0, 0);//1
	glTexCoord2f(1.0f, 0.0f); glVertex3f(20, 0.0, 0);//2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(20, 0.0, 19);//3 
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10, 5.0, 19);
	glEnd();

	//glEnable(GL_LIGHTING);
	glPopMatrix();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, -25 + pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	/*
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glScalef(20.0, 2.0, 20.0);  
			prisma(t_Ajedrez1.GLindex, madera.GLindex);
		glPopMatrix();
		
		//pata delantera derecha
		glPushMatrix();
		glTranslatef(-9, -6, 9);
		glScalef(2.0, 10.0, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//pata delantera derecha
		glPushMatrix();
		glTranslatef(9, -6, 9);
		glScalef(2.0, 10.0, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//pata tracera derecha
		glPushMatrix();
		glTranslatef(9, -6, -9);
		glScalef(2.0, 10.0, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//pata tracera izquierda
		glPushMatrix();
		glTranslatef(-9, -6, -9);
		glScalef(2.0, 10.0, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//bordes de la mesa
		//Izquierdo
		glPushMatrix();
		glTranslatef(-11, 0, 0);
		glScalef(2.0, 2.0, 20.0);
		glRotatef(-90, 0, 0, 1);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//derecho
		glPushMatrix();
		glTranslatef(11, 0, 0);
		glScalef(2.0, 2.0, 20.0);
		glRotatef(90, 0, 0, 1);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//delantero
		glPushMatrix();
		glTranslatef(0, 0, 11);
		glScalef(24.0, 2.0, 2.0);
		glRotatef(-90, 1, 0, 0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//posterior
		glPushMatrix();
		glTranslatef(0, 0, -11);
		glScalef(24.0, 2.0, 2.0);
		glRotatef(90, 1, 0, 0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//silla
		glPushMatrix();
		glTranslatef(20, -4, 0);
		glScalef(10.0, 2.0, 10.0);
		glRotatef(180, 1, 0, 0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//pata delantera izquierda
		glPushMatrix();
		glTranslatef(16, -9, 4);
		glScalef(2.0, 8, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();
		
		//pata delantera derecha
		glPushMatrix();
		glTranslatef(16, -9, -4);
		glScalef(2.0, 8, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//pata posterior derecha
		glPushMatrix();
		glTranslatef(24, -9, -4);
		glScalef(2.0, 8, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//pata posterior izquierda
		glPushMatrix();
		glTranslatef(24, -9, 4);
		glScalef(2.0, 8, 2.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();

		//respaldo

		glPushMatrix();
		glTranslatef(24, 2, 0);
		glRotatef(180, 1, 0, 0);
		glScalef(2.0, 10, 10.0);
		prisma(madera.GLindex, madera.GLindex);
		glPopMatrix();
		*/


//cabaña

//piso
	glPushMatrix();
		glTranslatef(0, -2, 0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(20.0, 2.0, 20.0);
		prisma(piso.GLindex, barda.GLindex);
	glPopMatrix();

//escaleras
	glPushMatrix();
		glTranslatef(0, -2.25, 10.55);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(5.0, 1.5, 1.0);
		prisma1(piso.GLindex, barda.GLindex);
			glPushMatrix();
				glTranslatef(0, -0.25, 1);
				glScalef(1.0, 0.5, 1.0);
				prisma1(piso.GLindex, barda.GLindex);
			glPopMatrix();
	glPopMatrix();

//Muro Izquierdo
	glPushMatrix();
		glTranslatef(-9.5, 4, -2.5);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 10.0, 15.0);
		prisma2(ventana.GLindex, muro.GLindex);
	glPopMatrix();

//Vigas exteriores
	glPushMatrix();
		glTranslatef(-9.5, 4.0, 8);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 10.0, 1.0);
		prisma3(muro.GLindex, viga.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(9.5, 4.0, -9.5);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 10.0, 1.0);
		prisma3(muro.GLindex, viga.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(9.5, 4.0, -1.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 10.0, 1.0);
		prisma3(muro.GLindex, viga.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(9.5, 4.0, 8);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 10.0, 1.0);
		prisma3(muro.GLindex, viga.GLindex);
	glPopMatrix();


//Muro Tracero
	glPushMatrix();
		glTranslatef(-1.5, 4, -9.5);
		glRotatef(180,0,1,0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(15.0, 10.0, 1.0);
		prisma2(muro.GLindex, ventana.GLindex);
	glPopMatrix();

//Muro Derecho
	glPushMatrix();
		glTranslatef(6.5, 4, -1.25);
		glRotatef(180, 0, 0, 1);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 10.0, 17.5);
		prisma2(ventana.GLindex, muro.GLindex);
	glPopMatrix();

//Muro Frente 5
	glPushMatrix();
		glTranslatef(4.0, 4, 8);
		glRotatef(180, 0, 0, 1);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(6.0, 10.0, 1.0);
		prisma2(muro.GLindex, ventana.GLindex);
	glPopMatrix();

//Muro Frente 1
	glPushMatrix();
		glTranslatef(1.25, 4, 6.0);
		glRotatef(180, 0, 1, 0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 10.0, 3.0);
		prisma2(ventana.GLindex, muro.GLindex);
	glPopMatrix();

//Muro frente 5
	glPushMatrix();
		glTranslatef(-6.5, 4, 4.75);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(5.0, 10.0, 0.5);
		prisma2(muro.GLindex, ventana.GLindex);
	glPopMatrix();

//Puerta
	glPushMatrix();
		glTranslatef(-1.5, 4, 4.75);
		glColor3f(1.0, 1.0, 0.0);
		glScalef(5.0, 10.0, 0.5);
		prisma3(puerta.GLindex, puerta.GLindex);
	glPopMatrix();


//Techo
	glPushMatrix();
		glTranslatef(-10, 9.01, 8.5);
		glColor3f(1.0, 1.0, 1.0);
		Techo();
	glPopMatrix();

//Barandal
	//BARANDAL 1
	glPushMatrix();
		glTranslatef(-9.75, 1.75, 6.25);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 0.5, 2.5);
		prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//soporte 1
	glPushMatrix();
	glTranslatef(-9.75, 0.25, 6.25);
	glRotatef(90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.5, 0.5, 2.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//BARANDAL 2
	glPushMatrix();
	glTranslatef(-9.75, 1.75, 9.25);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 1.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();
	
	//soporte 2
	glPushMatrix();
	glTranslatef(-9.75, 0.25, 9.75);
	glRotatef(90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.5, 0.5, 2.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//BARANDAL 3
	glPushMatrix();
	glTranslatef(-6.4, 1.75, 9.75);
	//glRotatef(90, 1,0,0);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(6.25, 0.5, 0.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//soporte 3
	glPushMatrix();
	glTranslatef(-7.0, 0.25, 9.75);
	glRotatef(90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.5, 0.5, 2.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//soporte 4
	glPushMatrix();
	glTranslatef(-3.52, 0.25, 9.75);
	glRotatef(90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.5, 0.5, 2.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//BARANDAL 4
	glPushMatrix();
	glTranslatef(6.25, 1.75, 9.75);
	//glRotatef(90, 1,0,0);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(7.5, 0.5, 0.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//soporte 5
	glPushMatrix();
	glTranslatef(2.75, 0.25, 9.75);
	glRotatef(90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.5, 0.5, 2.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//soporte 5
	glPushMatrix();
	glTranslatef(5.75, 0.25, 9.75);
	glRotatef(90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.5, 0.5, 2.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//soporte 6
	glPushMatrix();
	glTranslatef(9.75, 0.25, 9.75);
	glRotatef(90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.5, 0.5, 2.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//BARANDAL 5
	glPushMatrix();
	glTranslatef(9.75, 1.75, 9.25);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 1.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//BARANDAL 6
	glPushMatrix();
	glTranslatef(8, 1.75, -9.25);
	glRotatef(90,0,1,0);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 2.0);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//BARANDAL 7
	glPushMatrix();
	glTranslatef(9.75, 1.75, -5.25);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 7.5);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//BARANDAL 8
	glPushMatrix();
	glTranslatef(9.75, 1.75, 3.5);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 8.0);
	prisma3(madera.GLindex, madera.GLindex);
	glPopMatrix();

	glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 250.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}