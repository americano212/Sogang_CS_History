#include <stdio.h>
#include <time.h>

typedef struct {
	int hours;
	int minutes;
	int seconds;
} Time;

int main() {
	time_t timer;
	struct tm* t;
	Time *curTime;
	
	timer = time(NULL);
	t = localtime(&timer);
	printf("%d %d %d", t->tm_sec, t->tm_min, t->tm_hour);
	return 0;
}


