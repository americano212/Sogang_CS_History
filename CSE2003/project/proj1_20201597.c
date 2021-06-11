#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <termios.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

int b[25][40], time_out, game_over, n, m;
int birdp_x,birdp_y;
int rand1_15;
int keyboard = -1;
int score = 0;
int i,j,temp_val=0,jump_check=0;
void init(){
	n = 25, m = 40;
	time_out = game_over = 0;

	/* user code */
	birdp_x = m/4;
	birdp_y = n/2;

	/* init board */
	for (i=0;i<25;i++){
		for (j=0; j<40; j++){
			b[i][j] = 32;
		}
	}
	b[birdp_y][birdp_x] = 64;
}

void draw_board(){
	system("clear");
	/* user code */
	printf("    Score : \033[31m%d\033", score);
	printf("\n\n\n");
	for (i=0;i<25;i++){
		for (j=0;j<40;j++){
			if (b[i][j] == 64){
				printf("\033[34m%c\033[0m",b[i][j]);
			}
			else{
				printf("\033[32m%c\033[0m",b[i][j]);
			}
		}
		printf("\n");
	}
}

void Do(int sig) {
	/* processor call this function for every 0.2 sec */
	score = (temp_val-19)/25;
	/* user code */
	if (temp_val%25 == 0){
		srand(time(NULL));
		rand1_15 = rand() % 14 + 1;
	}
	/* update board b[25][40] */
	for (i=0;i<25;i++){
		for(j=0;j<39;j++){
			b[i][j] = b[i][j+1];
			if (b[i][j] == 64){
				b[i][j] = 32;
			}
		}
	}


	if (temp_val%25 > 14 && temp_val%25 < 25){
		for (i=0;i<25;i++){
			b[i][39] = 43;
		}
		for (i=rand1_15;i<rand1_15+10;i++){
			b[i][39] = 32;
		}
	}
	else{
		for (i=0;i<25;i++){
			b[i][39] = 32;
		}
	}
	
	/* update bird position*/
	if (keyboard != -1){
		if (jump_check == 1){
			birdp_y -= 1;
		}
		else{
			birdp_y -= 2;
			jump_check = 1;
		}
	}
	else {
		birdp_y += 1;
		jump_check = 0;
	}

	/* if game over */ 
	if (birdp_y > 24 || birdp_y < 0){
		game_over = 1;
	}
	if (b[birdp_y][birdp_x] == 43){
		game_over = 1;
	}
	// game over = 1;
	b[birdp_y][birdp_x] = 64;
	temp_val++;
	/* do not erase this code */
	time_out = 0;
}

int getch(void)
{
	char   ch;
	int   error;
	static struct termios Otty, Ntty;

	fflush(stdout);
	tcgetattr(0, &Otty);
	Ntty = Otty;
	Ntty.c_iflag = 0;
	Ntty.c_oflag = 0;
	Ntty.c_lflag &= ~ICANON;
#if 1
	Ntty.c_lflag &= ~ECHO;
#else
	Ntty.c_lflag |= ECHO;
#endif
	Ntty.c_cc[VMIN] = 0;
	Ntty.c_cc[VTIME] = 1;

#if 1
#define FLAG TCSAFLUSH
#else
#define FLAG TCSANOW
#endif

	if (0 == (error = tcsetattr(0, FLAG, &Ntty)))
	{
		error = read(0, &ch, 1);
		error += tcsetattr(0, FLAG, &Otty);
	}

	return (error == 1 ? (int)ch : -1);
}


int GetCommand() {
	int ch = getch();

	switch (ch)
	{
	case 'd':
	case 'D': return 0;
	case 'w':
	case 'W': return 1;
	case 'a':
	case 'A': return 2;
	case 's':
	case 'S': return 3;
	default: return -1;
	}

	return -1;
}


int main() {
	int command = -1;
	srand(time(NULL));
	static struct sigaction act, oact;
	act.sa_handler = Do;
	sigaction(SIGALRM, &act, NULL);
	init();
	draw_board();

	do {

		if (time_out == 0) {
			ualarm(200000, 0); /* 20,000 = 0.2 sec, call Do function */
			time_out = 1;
		}
		
		command = GetCommand();
		/* user code */
		keyboard = command;
		draw_board();
	} while (!game_over);

	system("clear");
	printf("game over!\n");
}
