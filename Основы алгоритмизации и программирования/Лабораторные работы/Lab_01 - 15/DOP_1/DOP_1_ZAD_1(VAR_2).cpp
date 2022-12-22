
#include <iostream>
using namespace std;

float n1(float x)
{
	return pow(x, 3) + x - 3;
}
float n2(float x) {
	return pow(cos(x), 3);
}


float function_for_dihatomy_method(float a, float b, float(*func)(float)) {
																  
																  
	float x = a, e = 0.001;

	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (func(x) * func(a) <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

int main() {

	cout << function_for_dihatomy_method(0, 2, n1) << endl;
	cout << function_for_dihatomy_method(2, 3, n2)<<endl;

	return 0;
}