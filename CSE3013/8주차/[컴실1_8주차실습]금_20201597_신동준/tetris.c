#include "tetris.h"

static struct sigaction act, oact;
int size_rank;
int main(){
	int exit=0;

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	size_rank = createRankList();
	srand((unsigned int)time(NULL));

	while(!exit){
		clear();
		switch(menu()){
		case MENU_PLAY: play(); break;
		case MENU_RANK: rank(); break;
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

	recRoot = (RecNode*)malloc(sizeof(RecNode));
	recRoot->lv = 0;
	recRoot->score = 0;
	memcpy(recRoot->f,field,sizeof(field));


	recommend(recRoot);
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
	DrawRecommend(recommendY, recommendX, blockID, recommendR);
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

	recRoot = (RecNode*)malloc(sizeof(RecNode));
	recRoot->lv = 0;
	recRoot->score = 0;
	memcpy(recRoot->f,field,sizeof(field));

	recommend(recRoot);
}

int AddBlockToField(char f[HEIGHT][WIDTH],int currentBlock,int blockRotate, int blockY, int blockX){
	int cnt=0;
	for(int i=0; i < 4; i++) {
		for(int j=0; j < 4; j++) {
			if(block[currentBlock][blockRotate][i][j] == 1) {
				if(0 <= blockY+i && blockY+i < HEIGHT && 0 <= blockX+j && blockX+j < WIDTH) {
					f[blockY+i][blockX+j] = 1;
					if(blockY+i == HEIGHT-1)
						cnt++;
					else if(f[blockY+i+1][blockX+j] != 0)
						cnt++;
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



int createRankList(){
	FILE* f_rank;
	f_rank = fopen("rank.txt","rt");
	int rank_num=0;
	int score;
	char name[NAMELEN];
	L = (linkedList *)malloc(sizeof(linkedList));
	L->size = 0;
	L->head = NULL;
	L->tail = NULL;

	if (f_rank==NULL){
		f_rank = fopen("rank.txt","wt");
		fprintf(f_rank,"0\n");
	}
	else{
		fscanf(f_rank, "%d", &rank_num);
		for (int i=0; i<rank_num;i++){
			fscanf(f_rank, "%s%d", name, &score);
			node *newNode = (node *)malloc(sizeof(node));
			strcpy(newNode->name,name);
			newNode->score = score;
			newNode->next = NULL;
			if(L->head == NULL && L->tail == NULL){
				 L->head = L->tail = newNode;
			}
			else {
		        L->tail->next = newNode;
		        L->tail = newNode;
		    }
			L->size += 1;
		}
		fclose(f_rank);
		RANK_CHANGE = 0;
	}
	return L->size;
}

void rank(){
	int command;
	int x, y;
	char name[NAMELEN];
	int num;
	do {
		clear();
		printw("1. list ranks from X to Y\n");
		printw("2. list ranks by a specific name\n");
		printw("3. delete a specific rank\n");
		command = wgetch(stdscr);
	} while(!('1' <= command && command <= '3'));
	echo();
	switch(command) {
		case '1':
			printw("X: ");
			scanw("%d", &x);
			printw("Y: ");
			scanw("%d", &y);
			noecho();

			if(x < 1 || x > size_rank) {
				x = 1;
			}
			if(y < 1 || y > size_rank) {
				y = size_rank;
			}
			printw(" rank |       name       |   score   \n");
			printw("-------------------------------------\n");
			if(x > y) {
				printw("\nsearch failure: no rank in the list\n");
			}
			else {
				node *temp = (node *)malloc(sizeof(node));
				temp->next = L->head;
				for(int i=0;i<x;i++){
					temp = temp->next;
				}
				for(int i = 0; i < y-x+1; i++) {
					printw(" %4d | %-17s| %-10d\n", i+x, temp->name, temp->score);
					temp = temp->next;
				}
			}
			break;
		case '2':
			printw("input the name: ");
			scanw("%s", name);
			printw(" rank |       name       |   score   \n");
			printw("-------------------------------------\n");
			int check_user = 0;
			node *temp = (node *)malloc(sizeof(node));
			temp->next = L->head;
			for(int i=0;i<size_rank;i++){
				if(strcmp(name, temp->name) == 0) {
					printw(" %4d | %-17s| %-10d\n", i+1, temp->name, temp->score);
					check_user = 1;
				}
				temp = temp->next;
			}
			if(!check_user) {
				printw("\nsearch failure: no name in the list\n");
			}
			break;
		case '3':
			printw("input the rank: ");
			scanw("%d", &num);
			node *tmp = (node *)malloc(sizeof(node));
			node *pre_temp = (node *)malloc(sizeof(node));
			if (num < L->size +1 && num >0){
				tmp->next = L->head;
				for(int i=0;i<num;i++){
					pre_temp = tmp;
					tmp = tmp->next;
				}
				pre_temp->next = tmp->next;
				RANK_CHANGE = 1;
				L->size -= 1;
				writeRankFile();
			}
			else{
				printw("search failure: the rank is not in the list\n");
			}
			break;
	}
	noecho();
	getch();
}

void writeRankFile(){
	FILE *f_rank;
	if (!RANK_CHANGE) return;

	f_rank = fopen("rank.txt", "wt");
	fprintf(f_rank, "%d\n", L->size);
	node *temp = (node *)malloc(sizeof(node));
	temp->next = L->head;
	temp = temp->next;
	for(int i=0;i<L->size;i++){
		fprintf(f_rank, "%s %d\n", temp->name, temp->score);
		temp = temp->next;
		if (temp==NULL) break;
	}
	fclose(f_rank);
}

void newRank(int score){
	char name[NAMELEN];
	int y;
	int rank;
	clear(); echo();
	printw("your name: ");
	scanw("%s", name);
	noecho();
	node *newNode = (node *)malloc(sizeof(node));
	newNode->score = score;
	strcpy(newNode->name,name);

	node *temp = (node *)malloc(sizeof(node));
	temp = L->head;
	for (int i=0;i<L->size;i++){
		if (temp->next->score <= newNode->score){
			newNode->next = temp->next;
			temp->next = newNode;
			break;
		}
		temp = temp->next;
	}
	L->size += 1;
	RANK_CHANGE = 1;
	size_rank+=1;
	writeRankFile();
}

void DrawRecommend(int y, int x, int blockID,int blockRotate){
	// user code
	int under_pos = y;
	while(CheckToMove(field, nextBlock[0], blockRotate, ++under_pos, x));
	under_pos-=1;
	DrawBlock(under_pos, x, blockID, blockRotate, 'R');
}

int recommend(RecNode *root){
	int max = 0;
	int child_num = 0;
	if(root->lv == BLOCK_NUM) return 0;
	for(int rot=0;rot<4;rot++){
		for(int x=-2;x<WIDTH+3;x++){
			int y= -1;
			if(!CheckToMove(root->f,nextBlock[root->lv],rot,y,x)) continue;
			root->c[child_num] = (RecNode*)malloc(sizeof(RecNode));
			memcpy(root->c[child_num]->f,root->f,sizeof(root->f));

			root->c[child_num]->lv = root->lv+1;
			root->c[child_num]->score = 0;

			while(CheckToMove(root->c[child_num]->f,nextBlock[root->lv],rot,++y,x));
			int plus_score = AddBlockToField(root->c[child_num]->f,nextBlock[root->lv],rot,--y,x);

			root->c[child_num]->score = root->score+DeleteLine(root->c[child_num]->f);
			root->c[child_num]->score += plus_score;
			root->c[child_num]->score += recommend(root->c[child_num]);

			if(root->c[child_num]->score > max){
				max = root->c[child_num]->score;

				if(root->c[child_num]->lv == 1){
					recommendX = x;recommendY = y;recommendR = rot;
					recommendblock = nextBlock[root->lv];
				}
			}
			child_num++;
		}
	}
	return max;
}

void recommendedPlay(){
	// user code
}
