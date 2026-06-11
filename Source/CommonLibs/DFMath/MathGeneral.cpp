#include <math.h>

float Square(float value) {
	return value * value;
}
bool Equal(float arg1, float arg2, float arg3) {
	float temp = Square(arg1 - arg2);
	return Square(arg3) >= temp;
}

int ABSMAX(int num1, int num2) {
	if(abs(num2) < abs(num1)) {
		num2 = num1;
	}
	return num2;
}

float Lerp(float num1, float num2, float num3) {
	return num3 * num2 + (1.0 - num3) * num1;
}

float SineRad(float num) {
	return sinf(num);
}
