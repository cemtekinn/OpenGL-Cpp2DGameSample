#include <glut.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include "freeglut.h"
#include "MMSystem.h"
//Ekran boyutu
int genislik = 600;
int yukseklik = 400;
//Topun konumu (X,Y)
GLint X_Konum = 0;
GLint Y_Konum = 0;
//Topun yönü (X,Y)
GLint X_Yon = 1;
GLint Y_Yon = 1;

//Çubuklarý hareket ettirme
//Sol Çubuk
GLint SolCubuk = 150;

//Sað Çubuk
GLint SagCubuk = 150;

//Rastgele hareket etme
GLint RastgeleHiz = 0;

//Puanlama Deðiþkenleri
int SagSkor = 0;
int SolSkor = 0;
//Kalan haklar
int SagCan = 5;
int SolCan = 5;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(0, genislik, 0, yukseklik, 0, 1);
}
void top(int adým) {
	glColor3f(1, 1, 1);
	//X de hareket et
	if (X_Yon == 1) {
		//X deki toplam hareket
		X_Konum += 3;
		//Sað taraf
		if (X_Konum >= 340) {
			//Rastgele Hýz Oluþtur
			int RastgeleHiz = rand() % 9;
			std::cout << "\nY hiz:" << RastgeleHiz;
			adým = RastgeleHiz;
			//Yönü deðiþtir
			X_Yon = 0;
		}
	}
	else {
		X_Konum -= 3;
		//Sol taraf
		if (X_Konum <= -140) {
			//Rastgele Hýz Oluþtur
			int RastgeleHiz = rand() % 9;
			std::cout << "\nY hiz:" << RastgeleHiz << "\n";
			adým = RastgeleHiz;
			//Yönü deðiþtir
			X_Yon = 1;
		}
	}

	//Y'de hareket et
	if (Y_Yon == 1) {
		//Toplam Hareket
		Y_Konum += adým;
		//Yön deðiþtir
		if (Y_Konum >= 185) Y_Yon = 0;
	}
	else {
		Y_Konum -= adým;
		//Yönü deðiþtir
		if (Y_Konum <= -185) Y_Yon = 1;
	}

	glutPostRedisplay();
	glutTimerFunc(10, top, adým);
}
//Arayüz tasarýmý
void drawText(float x, float y, std::string text) {
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}
//Giriþ Ekraný
void mainDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 1);

	glRasterPos3f(150, 350, 0);

	char baslik[] = "1vs1 Topa Vurma Oyunu";
	for (int i = 0; i < strlen(baslik); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, baslik[i]);
	}

	glRasterPos3f(50, 300, 0);
	char metin0[] = "OYUN KURALLARI ";
	for (int i = 0; i < strlen(metin0); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin0[i]);
	}

	glRasterPos3f(50, 270, 0);
	char metin1[] = " -5 caniniz bulunmaktadir ";
	for (int i = 0; i < strlen(metin1); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin1[i]);
	}

	glRasterPos3f(50, 240, 0);
	char metin2[] = " -Topu karsiya gondermeniz ve rakibi yenmeniz gerekmektedir";
	for (int i = 0; i < strlen(metin2); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin2[i]);
	}

	glRasterPos3f(50, 210, 0);
	char metin3[] = " -Topa her dokunuldugunda topun hizi rastgele degismektedir";
	for (int i = 0; i < strlen(metin3); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin3[i]);
	}

	glRasterPos3f(50, 180, 0);
	char metin4[] = "OYNANIS: ";
	for (int i = 0; i < strlen(metin4); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin4[i]);
	}

	glRasterPos3f(50, 150, 0);
	char metin5[] = "Sol Oyuncu: W-S Tuslari | Sag Oyuncu:Yukari Ok-Asagi Ok ";
	for (int i = 0; i < strlen(metin5); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin5[i]);
	}

	glRasterPos3f(50, 120, 0);
	char metin[] = "E-CIKIS";
	for (int i = 0; i < strlen(metin); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin[i]);
	}

	glRasterPos3f(150, 40, 0);
	char metin6[] = "BASLAMAK ICIN X TUSUNA BASIN";
	for (int i = 0; i < strlen(metin6); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, metin6[i]);
	}
	glutSwapBuffers();
}
//Ekran
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	//Çizgi rengi
	glColor3f(1.0, 0.0, 1.0);
	//Çizgi Geniþliði
	glLineWidth(10.0);
	//Köþeler
	glBegin(GL_LINE_LOOP);
	glVertex2i(2, 2);		glVertex2i(599, 2);
	glVertex2i(599, 399);	glVertex2i(2, 399);
	glEnd();
	//Genel Çizgileri Çiz
	glBegin(GL_LINES);
	//Sol çubuk
	glVertex2i(50, SolCubuk);
	glVertex2i(50, SolCubuk + 150);
	//Sað Çubuk
	glVertex2i(550, SagCubuk);
	glVertex2i(550, SagCubuk + 150);
	glEnd();
	glPointSize(15.0);
	glBegin(GL_POINTS);
	//Top konumu
	glVertex2i(X_Konum + 200, Y_Konum + 200);
	glEnd();
	//HUD
	std::string _solSkor = std::to_string(SolSkor);
	std::string _sagSkor = std::to_string(SagSkor);
	std::string _solCan = std::to_string(SolCan);
	std::string _sagCan = std::to_string(SagCan);
	drawText(genislik / 2 - 189, yukseklik - 20, "SKOR[" + _solSkor + "]  [" + _solCan + "] KALAN CAN SOL | SAG KALAN CAN[" + _sagCan + "]  [" + _sagSkor + "]SKOR");

	if (SolCan == 0)
	{
		PlaySound(TEXT("kazanan.wav"), NULL, SND_ASYNC | SND_FILENAME);
		drawText((genislik / 2 - 30), (yukseklik / 2), "***Sag kazandi***");
	}
	if (SagCan == 0)
	{
		PlaySound(TEXT("kazanan.wav"), NULL, SND_ASYNC | SND_FILENAME);
		drawText((genislik / 2 - 30), (yukseklik / 2), "***Sol kazandi***");

	}
	glutSwapBuffers();
	drawText(genislik / 2, yukseklik - 100, "Test");

}
//Puanlama sistemi
void score(int t01) {
	//Puan Arttýr-Sað
	if ((X_Konum >= 340) && ((Y_Konum + 200) > (SagCubuk)) && ((Y_Konum + 200) < (SagCubuk + 150))) {
		SagSkor += 1;
		PlaySound(TEXT("carpma.wav"), NULL, SND_ASYNC | SND_FILENAME);

	}
	//Puan arttýr-Sol
	if ((X_Konum <= -139) && ((Y_Konum + 200) > (SolCubuk)) && ((Y_Konum + 200) < (SolCubuk + 150))) {
		SolSkor += 1;
		PlaySound(TEXT("carpma.wav"), NULL, SND_ASYNC | SND_FILENAME);
	}
	//Caný azalt-Sað için
	if ((X_Konum >= 340) && !(((Y_Konum + 200) > (SagCubuk)) && ((Y_Konum + 200) < (SagCubuk + 150)))) {
		if (SagCan > 0) {
			SagCan -= 1;
			PlaySound(TEXT("yanlisHamle.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
	}
	//Caný azalt-Sol Ýçin
	if ((X_Konum <= -139) && !(((Y_Konum + 200) > (SolCubuk)) && ((Y_Konum + 200) < (SolCubuk + 150)))) {
		if (SolCan > 0) {
			SolCan -= 1;
			PlaySound(TEXT("yanlisHamle.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
	}
	//Oyun sonu
	if (SolCan == 0 || SagCan == 0) {
		PlaySound(TEXT("kazanan.wav"), NULL, SND_ASYNC | SND_FILENAME);
		X_Konum = 0;
		Y_Konum = 0;

		X_Yon = 1;
		Y_Yon = 1;

		SolCubuk = 150;
		SagCubuk = 150;
	}
	glutPostRedisplay();
	glutTimerFunc(10, score, 5);
}
//Klavye Tuþlarý(Sað Oyuncu için)
void keyboardArrow(int tus, int x, int y) {
	switch (tus) {
	case GLUT_KEY_UP:
		if (SagCubuk < 250) 
		{
			SagCubuk += 10;	
			break;
		}
	case GLUT_KEY_DOWN:
		if (SagCubuk > 0)
		{
			SagCubuk -= 10;
			break;
		}
	}
	glutPostRedisplay();
}
 
//W-S tuþlarý ile Soldaki çubuðu hareket ettirme
void keyboardLetter(unsigned char tus, int x, int y) {

	switch (tus) {
	case 'w':
		//Toplam hareket sýnýrý
		if (SolCubuk < 250) {
			SolCubuk += 10;
		}
		break;
	case 's':
		if (SolCubuk > 0) {
			SolCubuk -= 10;
		}
		break;
	case 'e':
		exit(0);
		break;
	}
	glutPostRedisplay();

	if (tus == 'x') {
		glutDisplayFunc(display);
		glutTimerFunc(10, top, 1);
	}
}
int main(int argc, char** argv) {
	//Pencere özellikleri
	PlaySound(TEXT("arkaPlan.wav"), NULL, SND_ASYNC | SND_FILENAME);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(genislik, yukseklik);
	glutInitWindowPosition(100,100);
	glutCreateWindow("1vs1 Topa Vurma Oyunu");
	init();
	glutDisplayFunc(mainDisplay);
	//Ok Tuþlarý
	glutSpecialFunc(keyboardArrow);
	//W-S Tuþlarý
	glutKeyboardFunc(keyboardLetter);
	//Skor
	glutTimerFunc(9, score, 2);
	glutMainLoop();
	return 0;
}