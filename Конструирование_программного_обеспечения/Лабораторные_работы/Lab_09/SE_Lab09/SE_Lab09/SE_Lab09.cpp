#include <iostream>
using namespace std;

namespace call_1 {
	int defaultparm(int a, int b, int c, int k = 2, int f = 3)
	{
		return (a + b + c + k + f) / 5;
	}
}

namespace call_2 {
	int defaultparm(int a, int b, int c, int d, int e, int k = 2, int f = 3)
	{
		return (a + b + c + d + e + k + f) / 7;
	}
}

void main()
{

	call_1::defaultparm(5, 6, 4);
	
	call_2::defaultparm(5, 6, 4, 3, 1);

} 