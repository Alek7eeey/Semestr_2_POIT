#include <iostream>
using namespace std;

float n1(float x)
{
	return pow(x, 3) + 3 * x - 1;
}


float n2(float x) 
{
	return exp(3)-4;
}

float function_for_dihatomy_method(float a, float b, float(*func)(float)) {   //а - перва€ координата по иксу, котора€ ближе к минус бесконечности
																              //b - втора€ переменна€ по иксу, котора€ ближе к плюс бесконечности
																              //func - функци€, котора€ содержит функцию, от которой мы берем интеграл
	float x = a, e = 0.001;

	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		
		if (func(x) * func(a) <= 0)
		{
			b = x;
		}

		else
			a = x;
	}
	return x;
}

void main() {
	
	setlocale(LC_ALL, "Rus");

	cout << function_for_dihatomy_method(0, 2, n1) << endl;
	cout << function_for_dihatomy_method(1, 2, n2);
	cout << endl;
	
}