#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#define endl '\n'

#include <queue>
#include <functional>

using namespace std;
int node_cnt;
int edge_cnt=-1;
priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
vector<int> parent;

int simpleFind(int i) {
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}

vector<int> split(string input, char delimiter) {
	vector<int> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(atoi(temp.c_str()));
	}

	return answer;
}

int main(int argc, char *argv[]) {
	if (argv[1] == NULL) {
		cout << "usage: ./hw3 input_filename" << endl;
		return 0;
	}
	clock_t start, end; double result;
	
	FILE* input = fopen(argv[1], "r");
	if (!input) {
		cout << "The input file does not exist." << endl;
		return 0;
	}
	char line[255];
	int line_cnt = 0;
	while (fgets(line, sizeof(line), input) != NULL) {
		string tmp(line);
		if (edge_cnt != line_cnt-1) {
			tmp.erase(find(tmp.begin(), tmp.end(), '\n'));
		}
		
		if (line_cnt == 0) {
			node_cnt = atoi(tmp.c_str());
		}
		else if (line_cnt == 1) {
			edge_cnt = atoi(tmp.c_str());
		}
		else {
			vector<int> result = split(tmp, ' ');
			vector<int> new_result;
			new_result.push_back(result[2]);
			new_result.push_back(result[0]);
			new_result.push_back(result[1]);
			pq.push(new_result);
		}
		line_cnt++;
	}
	
	for (int i = 0; i < node_cnt; i++) {
		parent.push_back(-1);
	}
	FILE* output = fopen("hw3_result.txt", "w");
	start = clock();
	vector<int> get;
	int n = 0;
	int sum = 0;
	while (!pq.empty()) {
		get = pq.top();
		if ((simpleFind(get[1]) != simpleFind(get[2]))) {
			sum += get[0];
			parent[simpleFind(get[2])] = get[1];
			fprintf(output, "%d %d %d\n", get[1], get[2], get[0]);
			n += 1;
		}
		pq.pop();
		if (n == node_cnt - 1) break;
	}
	fprintf(output, "%d\n",sum);
	if (n == node_cnt - 1) {
		fprintf(output, "CONNECTED\n");
	}
	else {
		fprintf(output, "DISCONNECTED\n");
	}
	end = clock();
	result = (double)(end - start);
	cout << "output written to hw3_result.txt" << endl;
	cout << "running time : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl;
}