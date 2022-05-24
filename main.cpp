#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

//Описание класса комплексных чисел
class Complex
{
private:
    double _re, _im;
	
public:
    Complex() {
        double x, y;
        x = (rand() % 100 + 1.) /10. - 10.1;
        y = (rand() % 20 + 1.) / 10. - 2.1;//
        _re = x; _im = y;
    }

    Complex(double r, double i) {//Конструктор комплексного числа
        _re = r; _im = i;
    }
    Complex(double r) { //Конструктор мнимого числа
        _re = r; _im = 0;
    }

    //Действительная часть
    double Real() {
        return _re;
    }
    //Мнимая часть
    double Imag() {
        return _im;
    }
    //Модуль числа
    double Modul() {

        return sqrt(_re * _re + _im * _im);
    }
    //Сопряженная часть
    double Imconj() {
        return -_im;
    }
    //Аргумент
    double Argument()
    {
        return atan2(_im, _re);
    }
    //Возведение в степень
    Complex Power(int n) {
        return Complex(pow(Modul(), n) * cos(n * Argument()), pow(Modul(), n) * sin(n * Argument()));
    }
    double  RePower(int n) {
        return pow(Modul(), n) * cos(n * Argument());
    }
    double  ImPower(int n) {
        return pow(Modul(), n) * sin(n * Argument());
    }
	Complex Division(Complex p1, Complex p2) {
    double re, im;
    re = (p1.Real() * p2.Real() + p1.Imag() * p2.Imag()) / (pow(p2.Real(), 2) + pow(p2.Imag(), 2));
    im = (p1.Imag() * p2.Real() - p1.Real() * p2.Imag()) / (pow(p2.Real(), 2) + pow(p2.Imag(), 2));
    return Complex(re, im);
	}
//Сложение комплексных чисел
	Complex Add(Complex p1, Complex p2) {
    double re, im;
    re = p1.Real() + p2.Real();
    im = p1.Imag() + p2.Imag();
    return Complex(re, im);
	}
// Разность комплексных чисел
	Complex Difference(Complex p1, Complex p2) {
    double re, im;
    re = p1.Real() - p2.Real();
    im = p1.Imag() - p2.Imag();
    return Complex(re, im);
	}
//Умножение комплексных чисел
Complex Cross(Complex p1, Complex p2) {
    double re, im;
    re = p1.Real() * p2.Real() - p1.Imag() * p2.Imag();
    im = p1.Real() * p2.Imag() + p1.Imag() * p2.Real();
    return Complex(re, im);
	}
void Find_Poles(int n) {
	int i, j, count, Root;

    Complex p[n], Z0, Z;
    count = 0;
    Root = 0;

    while (count < 120) {
        count = count + 1;
        for (i = 0; i < n; i++) {
           Z0 = Complex(0);
            for (j = 0; j < n+1; j++) {
                if (j != i) Z0 = Add(Z0, Division(Complex(1), Add(Difference(p[i],p[j]), Complex(0.000001))));
            }
           Z = Division(Polynom(p[i]), Difference(Cross(Polynom(p[i]), Z0), D_Polynom(p[i])));
			p[i] = Add(p[i], Z);
			if (p[i].Real() > 0)  p[i] = Complex (-1 * p[i].Real(), p[i].Real());
           }
       }

      }
	
};
