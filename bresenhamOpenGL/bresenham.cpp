//Algoritma Bresenham
//Team : Gacha ampas (modifikasi)

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void bresenham(void);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 300; //lebar window
int window_height = 400; //tinggi windows

//  judul window
char *title_window = "Algoritma Garis Bresenham";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window agar ditengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //ukuran window 
	glutInitWindowPosition(window_x, window_y); //posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); //display RGB dan double buffer
	glutCreateWindow(title_window); //pemangilan judul window

	
	init(); //jalankan fungsi init 
	glutDisplayFunc(display); //  set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(1.1, 1.1, 1.1, 1.1); //warna background 
	glColor3f(0.0, 1.1, 1.1); //warna titik
	glPointSize(3.0); //ukuran titik
	glMatrixMode(GL_PROJECTION); //mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	bresenham(); //jalankan fungsi bresenham
	glutSwapBuffers(); //swap buffer 
}

void bresenham(void) {
	int x1, y1, x2, y2, x, y, dx, dy, xend, p, duady, duadydx;
	//tentukan titik awal dan akhir
	x1 = 10;
	y1 = 10;
	x2 = 500;
	y2 = 400;
	x = x1;
	y = y1;

	//hitung dx dan dy
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	
	//hitung p 
	p = 2 * dy - dx; //P = untuk Posisi awal
	duady = 2 * dy;
	duadydx = 2 * (dy - dx);
	
	//tentukan titik awal dan akhir
	if (x1 > x2) {
		x = x2;
		y = y2;
		xend = x1;
	}
	else
	{
		x = x1;
		y = y1;
		xend = x2;
	}

	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y);

	//perulangan untuk menggambar titik-titik 
	while (x < xend) {
		x++;
		if (p < 0) {
			p += duady;
		}
		else
		{
			if (y1 > y2) {
				y--;
			}
			else y++;
		
			p += duadydx;
		}
		glVertex2i(x, y);
	}

	glEnd();
	glFlush();
}

