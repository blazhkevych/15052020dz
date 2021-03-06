﻿ДОМАШНЯ РОБОТА
Курс : Основи програмування на мові С++
Тема : Бітові операції.
Завдання Розробити функції для конвертації кольору RGB в цілий тип даних, та навпаки.Прототипи функцій :
unsigned int RgbToUInt(int r, int g, int b);
RGB UIntToRgb(unsigned int x);
/*
Завдання Розробити функції для конвертації кольору RGB в цілий тип даних, та навпаки.
Прототипи функцій :
unsigned int RgbToUInt(int r, int g, int b);
RGB UIntToRgb(unsigned int x);
RGB це користувацький тип даних, який зберігає три кольори :
червоний, зелений, синій. Продемонструвати роботу функцій.
*/
#include <iostream>
struct Color {
	unsigned int R = 0;
	unsigned int G = 0;
	unsigned int B = 0;
};
using namespace std;
void DtoB(unsigned int d) { // виводить в двійковій
	if (d < 1) return;
	DtoB(d / 2);
	cout << d % 2;
}
unsigned int RgbToUInt(int r, int g, int b) { // приймає 3 кольори і запаковує їх в одну в змінну
	/*
	r = десяткове "255", двійкове - "1111 1111"
	g = десяткове "254", двійкове - "1111 1110"
	b = десяткове "253", двійкове - "1111 1101"
	*/
	unsigned int rgb = 0;		// 0000 0000 0000 0000 0000 0000 0000 0000 // розмір unsigned int 4 байти (32 біти)
	rgb = r;					// 0000 0000 0000 0000 0000 0000 1111 1111 // десяткове "255", двійкове - "1111 1111"
	rgb = rgb << 8;				// 0000 0000 0000 0000 1111 1111 0000 0000 // після зміщення вліво на 8 біт
	rgb = rgb | g;				// 0000 0000 0000 0000 1111 1111 0000 0000 // rgb
								// 0000 0000 0000 0000 0000	0000 1111 1110 // десяткове "254", двійкове - "1111 1110"
								// 0000 0000 0000 0000 1111 1111 1111 1110 // після операції "або" ( "|" )
	rgb = rgb << 8;				// 0000 0000 0000 0000 1111 1111 1111 1110 // rgb
								// 0000 0000 1111 1111 1111 1110 0000 0000 // після зміщення вліво на 8 біт
	rgb = rgb | b;				// 0000 0000 1111 1111 1111 1110 0000 0000 // rgb
								// 0000 0000 0000 0000 0000 0000 1111 1101 // десяткове "253", двійкове - "1111 1101"
								// 0000 0000 1111 1111 1111 1110 1111 1101 // після операції "або" ( "|" )
	return rgb;					// 0000 0000 1111 1111 1111 1110 1111 1101 // результат роботи функції (в двійковій), в десятковій (16776957)
}
Color RGBUIntToRgb(unsigned int x, Color& col) { // розпаковує три кольори з 1єї змінної та повертає 3 кольори
	col.R = x >> 16;			// 0000 0000 1111 1111 1111 1110 1111 1101 // x
								// 0000 0000 0000 0000 0000 0000 1111 1111 // після зміщення вправо на 16 біт // r = десяткове "255", двійкове - "1111 1111"
	col.G = x >> 8;				// 0000 0000 1111 1111 1111 1110 1111 1101 // x
								// 0000 0000 0000 0000 1111 1111 1111 1110 // після зміщення вправо на 8 біт
	col.G = col.G << 24 >> 24;	// 1111 1110 0000 0000 0000 0000 0000 0000 // після зміщення вліво на 24 біт 
								// 0000 0000 0000 0000 0000 0000 1111 1110 // після зміщення вправо на 24 біт // g = десяткове "254", двійкове - "1111 1110"
	col.B = x << 24 >> 24;		// 0000 0000 1111 1111 1111 1110 1111 1101 // x
								// 1111 1101 0000 0000 0000 0000 0000 0000 // після зміщення вліво на 24 біт, 
								// 1111 1101 0000 0000 0000 0000 0000 0000 // після зміщення вправо на 24 біт, // b = десяткове "253", двійкове - "1111 1101"
	return col;
}
int main()
{
	cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << " bytes (" << sizeof(unsigned int) * 8 << " bits)" << endl; // розмір unsigned int 4 байти (32 біти)
	Color col;
	unsigned int x = RgbToUInt(255, 15, 16);
	cout << "RgbToUInt in decimal = " << x << endl;
	cout << "RgbToUInt in binary = ";
	DtoB(x);
	cout << endl;
	RGBUIntToRgb(x, col);
	cout << "\nR" << endl;
	cout << "R in decimal = " << col.R << endl;
	cout << "R in binary = ";
	DtoB(col.R);
	cout << "\n\nG";
	cout << "\nG in decimal = " << col.G << endl;
	cout << "G in binary = ";
	DtoB(col.G);
	cout << "\n\nB";
	cout << "\nB in decimal = " << col.B << endl;
	cout << "B in binary = ";
	DtoB(col.B);
}


RGB це користувацький тип даних, який зберігає три кольори : червоний, зелений, синій.Продемонструвати роботу функцій.

