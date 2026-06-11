unsigned int Align8(unsigned int num) {
	if((num & 7) != 0) {
		num = ((num >> 3) + 1) * 8;
	}
	return num;
}

unsigned int Align16(unsigned int num) {
	if ((num & 0xf) != 0) {
		num = ((num >> 4) + 1) * 0x10;
	}
	return num;
}

unsigned int Align32(unsigned int num) {
	if ((num & 0x1f) != 0) {
		num = ((num >> 5) + 1) * 0x20;
	}
	return num;
}

unsigned int AlignPowerOfTwo(unsigned int num1, unsigned int num2) {
	if ((num2 - 1 & num1) != 0) {
		num1 = (num1 / num2 + 1) * num2;
	}
	return num1;
}
