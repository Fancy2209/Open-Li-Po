#include <unistd.h>

void Sleep(int seconds) {
	usleep(seconds * 1000);
}
