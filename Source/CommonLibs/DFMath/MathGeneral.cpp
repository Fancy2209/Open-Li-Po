float Square(float value) {
	return value * value;
}
bool Equal(float arg1, float arg2, float arg3) {
	float temp = Square(arg1 - arg2);
	return Square(arg3) >= temp;
}
