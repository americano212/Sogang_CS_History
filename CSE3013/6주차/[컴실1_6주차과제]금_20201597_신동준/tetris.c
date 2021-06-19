#include "tetris.h"

static struct sigaction act, oact;

int main(){
	int exit=0;

	initscr();
	noecho();
	keypad(stdscr, TRUE);

	srand((unsigned int)time(NULL));

	while(!exit){
		clear();
		switch(menu()){
		case MENU_PLAY: play(); break;
		case MENU_EXIT: exit=1; break;
		default: break;
		}
	}

	endwin();
	system("clear");
	return 0;
}

void InitTetris(){
	for(int i=0;i<HEIGHT;i++)
		for(int j=0;j<WIDTH;j++)
			field[i][j]=0;

	nextBlock[0]=rand()%7;
	nextBlock[1]=rand()%7;
	nextBlock[2]=rand()%7;

	blockRotate=0;
	blockY=-1;
	blockX=WIDTH/2-2;
	score=0;
	gameOver=0;
	timed_out=0;

	DrawOutline();
	DrawField();
	DrawBlockWithFeatures(blockY,blockX,nextBlock[0],blockRotate);
	DrawNextBlock(nextBlock);
	PrintScore(score);
}

void DrawOutline(){
	/* 블럭이 떨어지는 공간의 테두리를 그린다.*/
	DrawBox(0,0,HEIGHT,WIDTH);
	/* next block을 보여주는 공간의 테두리를 그린다.*/
	move(2,WIDTH+10);
	printw("NEXT BLOCK");
	for(int i = 0; i < 2; i++)
		DrawBox(3+i*6, WIDTH+10, 4, 8);

	/* score를 보여주는 공간의 테두리를 그린다.*/
	move(15,WIDTH+10);
	printw("SCORE");
	DrawBox(16,WIDTH+10,1,8);
}

int GetCommand(){
	int command;
	command = wgetch(stdscr);
	switch(command){
	case KEY_UP:
		break;
	case KEY_DOWN:
		break;
	case KEY_LEFT:
		break;
	case KEY_RIGHT:
		break;
	case ' ':	/* space key*/
		/*fall block*/
		break;
	case 'q':
	case 'Q':
		command = QUIT;
		break;
	default:
		command = NOTHING;
		break;
	}
	return command;
}

int ProcessCommand(int command){
	int ret=1;
	int drawFlag=0;
	switch(command){
	case QUIT:
		ret = QUIT;
		break;
	case KEY_UP:
		if((drawFlag = CheckToMove(field,nextBlock[0],(blockRotate+1)%4,blockY,blockX)))
			blockRotate=(blockRotate+1)%4;
		break;
	case KEY_DOWN:
		if((drawFlag = CheckToMove(field,nextBlock[0],blockRotate,blockY+1,blockX)))
			blockY++;
		break;
	case KEY_RIGHT:
		if((drawFlag = CheckToMove(field,nextBlock[0],blockRotate,blockY,blockX+1)))
			blockX++;
		break;
	case KEY_LEFT:
		if((drawFlag = CheckToMove(field,nextBlock[0],blockRotate,blockY,blockX-1)))
			blockX--;
		break;
	default:
		break;
	}
	if(drawFlag) DrawChange(field,command,nextBlock[0],blockRotate,blockY,blockX);
	return ret;
}

void DrawField(){
	for(int j=0;j<HEIGHT;j++){
		move(j+1,1);
		for(int i=0;i<WIDTH;i++){
			if(field[j][i]==1){
				attron(A_REVERSE);
				printw(" ");
				attroff(A_REVERSE);
			}
			else{
				printw(".");
			}
		}
	}
}


void PrintScore(int score){
	move(17,WIDTH+11);
	printw("%8d",score);
}

void DrawNextBlock(int *nextBlock){
	for(int k = 1; k < 3; k++) {
		for(int i = 0; i < 4; i++ ){
			move(4+i+(k-1)*6,WIDTH+13);
			for(int j = 0; j < 4; j++ ){
				if( block[nextBlock[k]][0][i][j] == 1 ){
					attron(A_REVERSE);
					printw(" ");
					attroff(A_REVERSE);
				}
				else{
					printw(" ");
				}
			}
		}
	}
}

void DrawBlock(int y, int x, int blockID,int blockRotate,char tile){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			if(block[blockID][blockRotate][i][j]==1 && i+y>=0){
				move(i+y+1,j+x+1);
				if (tile=='.'){
					printw("%c",tile);
				}
				else{
					attron(A_REVERSE);
					printw("%c",tile);
					attroff(A_REVERSE);
				}

			}
		}
	move(HEIGHT,WIDTH+10);
}

void DrawShadow(int y, int x, int blockID,int blockRotate){
	char tile = '/';
	int under_pos = y;
	while(CheckToMove(field, nextBlock[0], blockRotate, under_pos+1, x)){
		under_pos+=1;
	}

	DrawBlock(under_pos, x, blockID, blockRotate, '/');
}

void DrawBlockWithFeatures(int y, int x, int blockID,int blockRotate) {
	DrawShadow(y, x, blockID, blockRotate);
	DrawBlock(y, x, blockID, blockRotate, ' ');
}

void DrawBox(int y,int x, int height, int width){
	int i,j;
	move(y,x);
	addch(ACS_ULCORNER);
	for(i=0;i<width;i++)
		addch(ACS_HLINE);
	addch(ACS_URCORNER);
	for(j=0;j<height;j++){
		move(y+j+1,x);
		addch(ACS_VLINE);
		move(y+j+1,x+width+1);
		addch(ACS_VLINE);
	}
	move(y+j+1,x);
	addch(ACS_LLCORNER);
	for(i=0;i<width;i++)
		addch(ACS_HLINE);
	addch(ACS_LRCORNER);
}

void play(){
	int command;
	clear();
	act.sa_handler = BlockDown;
	sigaction(SIGALRM,&act,&oact);
	InitTetris();
	do{
		if(timed_out==0){
			alarm(1);
			timed_out=1;
		}

		command = GetCommand();
		if(ProcessCommand(command)==QUIT){
			alarm(0);
			DrawBox(HEIGHT/2-1,WIDTH/2-5,1,10);
			move(HEIGHT/2,WIDTH/2-4);
			printw("Good-bye!!");
			refresh();
			getch();

			return;
		}
	}while(!gameOver);

	alarm(0);
	getch();
	DrawBox(HEIGHT/2-1,WIDTH/2-5,1,10);
	move(HEIGHT/2,WIDTH/2-4);
	printw("GameOver!!");
	refresh();
	getch();
	newRank(score);
}

char menu(){
	printw("1. play\n");
	printw("2. rank\n");
	printw("3. recommended play\n");
	printw("4. exit\n");
	return wgetch(stdscr);
}

int CheckToMove(char f[HEIGHT][WIDTH],int currentBlock,int blockRotate, int blockY, int blockX){
	int x,y;
	for(int i=0; i < 4; i++){
		for(int j=0; j < 4; j++){
			if(block[currentBlock][blockRotate][i][j]==1) {
				x = blockX+j;
				y = blockY+i;
				if((0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)==0) {
					return 0;
				}
				if(f[y][x]==1) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void DrawChange(char f[HEIGHT][WIDTH],int command,int currentBlock,int blockRotate, int blockY, int blockX){
	int under_pos = blockY;
    if (command==KEY_UP){
		under_pos = blockY;
		while(CheckToMove(field, nextBlock[0], (blockRotate+3)%4, under_pos+1, blockX)){
			under_pos+=1;
		}
		DrawBlock(under_pos, blockX, currentBlock, (blockRotate+3)%4,'.');
		DrawBlock(blockY, blockX, currentBlock, (blockRotate+3)%4,'.');
	}
    if (command==KEY_DOWN){
		DrawBlock(blockY-1, blockX, currentBlock, blockRotate,'.');
	}
    if (command==KEY_LEFT){
		under_pos = blockY;
		while(CheckToMove(field, nextBlock[0], blockRotate, under_pos+1, blockX+1)){
			under_pos++;
		}

		DrawBlock(under_pos, blockX+1, currentBlock, blockRotate,'.');
		DrawBlock(blockY, blockX+1, currentBlock, blockRotate,'.');
	}
    if (command==KEY_RIGHT){
		under_pos = blockY;
		while(CheckToMove(field, nextBlock[0], blockRotate, under_pos+1, blockX-1)){
			under_pos++;
		}

		DrawBlock(under_pos, blockX-1, currentBlock, blockRotate,'.');
		DrawBlock(blockY, blockX-1, currentBlock, blockRotate,'.');
	}

    DrawBlockWithFeatures(blockY, blockX, currentBlock, blockRotate);
}

void BlockDown(int sig){
	int plus_scr;
	if(CheckToMove(field, nextBlock[0], blockRotate, blockY+1, blockX)==1) {
		blockY+=1;
		DrawChange(field, KEY_DOWN, nextBlock[0], blockRotate, blockY, blockX);
	}

	else {
		plus_scr= AddBlockToField(field, nextBlock[0], blockRotate, blockY, blockX);
		score += plus_scr;
		if(blockY==-1) {
			gameOver = 1;
		}

		else {
			score += DeleteLine(field);
			for(int i=0; i<2; i++) {
				nextBlock[i] = nextBlock[i+1];
			}
			nextBlock[2] = (rand()+7)%7;
			DrawNextBlock(nextBlock);
			blockX = WIDTH/2-2;
			blockY = -1;

			blockRotate = 0;
			PrintScore(score);
		}
		DrawField();
	}

	timed_out = 0;
}

int AddBlockToField(char f[HEIGHT][WIDTH],int currentBlock,int blockRotate, int blockY, int blockX){
	int cnt=0;
	for(int i=0; i < 4; i++) {
		for(int j=0; j < 4; j++) {
			if(block[currentBlock][blockRotate][i][j] == 1) {
				if(0 <= blockY+i && blockY+i < HEIGHT && 0 <= blockX+j && blockX+j < WIDTH){
					f[blockY+i][blockX+j] = 1;
					if (blockY+i+1 == HEIGHT){
						cnt+=1;
					}
				}
			}
		}
	}
	return cnt * 10;
}

int DeleteLine(char f[HEIGHT][WIDTH]){
	int cnt = 0;
	int full;

	for(int i= 0; i < HEIGHT; i++) {
		full = 1;
		for(int j= 0; j < WIDTH; j++) {
			if(f[i][j] == 0) {
				full = 0;
				break;
			}
		}
		if(full==1) {
			cnt+=1;
			for(int k=i-1; k >= 0; k--) {
				for(int j= WIDTH; j > 0; j--) {
					f[k+1][j] = f[k][j];
				}
			}
		}
	}

	return cnt*cnt*100;
}



void createRankList(){
	// user code
}

void rank(){
	// user code
}

void writeRankFile(){
	// user code
}

void newRank(int score){
	// user code
}

void DrawRecommend(int y, int x, int blockID,int blockRotate){
	// user code
}

int recommend(RecNode *root){
	int max=0; // 미리 보이는 블럭의 추천 배치까지 고려했을 때 얻을 수 있는 최대 점수

	// user code

	return max;
}

void recommendedPlay(){
	// user code
}
