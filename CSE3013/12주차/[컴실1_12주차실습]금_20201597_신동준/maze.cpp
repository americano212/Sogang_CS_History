#include<iostream>
#include <time.h>
#include <algorithm>
#include <cstdio>
using namespace std;
int WIDTH, HEIGHT;
int n, m;
int **check;
char **Maze;

void MakeBoard(){
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(i % 2 == 0) {
                if(j % 2 == 0) Maze[i][j] = '+';
                else Maze[i][j] = '-';
            }
            else {
                if(j % 2 == 0) Maze[i][j] = '|';
                else Maze[i][j] = ' ';
            }
        }
    }
    check = (int **)malloc(sizeof(int *)*m);
    for(int i = 0; i < m; i++){
    	check[i] = (int *)malloc(sizeof(int)*n);
	}
	
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
        	check[i][j] = i * n + j;
		}
    }
}

void MakeFile(){
    FILE *fp;
    fp = fopen("new.maz", "w");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++){
        	fprintf(fp, "%c", Maze[i][j]);
        	cout << Maze[i][j];
		}
        fprintf(fp, "\n");
        cout << endl;
    }
    fclose(fp);
}

void MakeOne(int MAX, int MIN){
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(check[i][j] == MAX){
            	check[i][j] = MIN;
			}
        }
    }
}


void MakeMaze(){
    int flag;
	int small, big;

    for(int i = 0; i < m-1; i++) {
        for(int j = 0; j < n-1; j++) {
            if(check[i][j] != check[i][j+1]) {
                if(rand()%2 == 1) {
                    MakeOne(max(check[i][j], check[i][j+1]), min(check[i][j], check[i][j+1]));
                    Maze[i*2+1][(j+1)*2] = ' ';
                }
            }
        }

        flag = 0;
        for(int j = 0; j < n; j++) {
            if(rand()%2 == 1) {
                check[i+1][j] = check[i][j];
                Maze[(i+1)*2][j*2+1] = ' ';
                flag = 1; 
            }
            if(check[i][j+1] != check[i][j]) {
                if(flag == 0) {
                    check[i+1][j] = check[i][j];
                    Maze[(i+1)*2][j*2+1] = ' ';
                }
                flag = 0;
            }
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(check[m-1][i] != check[m-1][i+1]) {
            MakeOne(max(check[m-1][i], check[m-1][i+1]), min(check[m-1][i], check[m-1][i+1]));
            Maze[HEIGHT-2][(i+1)*2] = ' ';
            
        }
    }
}



int main(){
	cout << "Width : ";
	cin >> n;
	cout << "Height : ";
	cin >> m;
    WIDTH = 2 * n + 1;
    HEIGHT = 2 * m + 1;

    Maze = (char**)malloc(sizeof(char*)*HEIGHT);
    for(int i = 0; i < HEIGHT; i++){
    	Maze[i] = (char*)malloc(sizeof(char)*WIDTH);
	}
        

    srand(time(NULL));
    MakeBoard();
    MakeMaze();
    MakeFile();

    return 0;
}



