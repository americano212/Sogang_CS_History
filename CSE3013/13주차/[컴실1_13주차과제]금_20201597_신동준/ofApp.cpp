/*

	ofxWinMenu basic example - ofApp.cpp

	Example of using ofxWinMenu addon to create a menu for a Microsoft Windows application.
	
	Copyright (C) 2016-2017 Lynn Jarvis.

	https://github.com/leadedge

	http://www.spout.zeal.co

    =========================================================================
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    =========================================================================

	03.11.16 - minor comment cleanup
	21.02.17 - rebuild for OF 0.9.8

*/
#include "ofApp.h"
#include <iostream>
#include <algorithm>
using namespace std;
//--------------------------------------------------------------
void ofApp::setup() {

	ofSetWindowTitle("Maze Example"); // Set the app name on the title bar
	ofSetFrameRate(15);
	ofBackground(255, 255, 255);
	// Get the window size for image loading
	windowWidth = ofGetWidth();
	windowHeight = ofGetHeight();
	isdfs = false;
	isbfs = false;
	isOpen = 0;
	// Centre on the screen
	ofSetWindowPosition((ofGetScreenWidth()-windowWidth)/2, (ofGetScreenHeight()-windowHeight)/2);

	// Load a font rather than the default
	myFont.loadFont("verdana.ttf", 12, true, true);

	// Load an image for the example
	//myImage.loadImage("lighthouse.jpg");

	// Window handle used for topmost function
	hWnd = WindowFromDC(wglGetCurrentDC());

	// Disable escape key exit so we can exit fullscreen with Escape (see keyPressed)
	ofSetEscapeQuitsApp(false);

	//
	// Create a menu using ofxWinMenu
	//

	// A new menu object with a pointer to this class
	menu = new ofxWinMenu(this, hWnd);

	// Register an ofApp function that is called when a menu item is selected.
	// The function can be called anything but must exist. 
	// See the example "appMenuFunction".
	menu->CreateMenuFunction(&ofApp::appMenuFunction);

	// Create a window menu
	HMENU hMenu = menu->CreateWindowMenu();

	//
	// Create a "File" popup menu
	//
	HMENU hPopup = menu->AddPopupMenu(hMenu, "File");

	//
	// Add popup items to the File menu
	//

	// Open an maze file
	menu->AddPopupItem(hPopup, "Open", false, false); // Not checked and not auto-checked
	
	// Final File popup menu item is "Exit" - add a separator before it
	menu->AddPopupSeparator(hPopup);
	menu->AddPopupItem(hPopup, "Exit", false, false);

	//
	// View popup menu
	//
	hPopup = menu->AddPopupMenu(hMenu, "View");

	bShowInfo = true;  // screen info display on
	menu->AddPopupItem(hPopup, "Show DFS",false,false); // Checked
	bTopmost = false; // app is topmost
	menu->AddPopupItem(hPopup, "Show BFS"); // Not checked (default)
	bFullscreen = false; // not fullscreen yet
	menu->AddPopupItem(hPopup, "Full screen", false, false); // Not checked and not auto-check

	//
	// Help popup menu
	//
	hPopup = menu->AddPopupMenu(hMenu, "Help");
	menu->AddPopupItem(hPopup, "About", false, false); // No auto check

	// Set the menu to the window
	menu->SetWindowMenu();

} // end Setup


//
// Menu function
//
// This function is called by ofxWinMenu when an item is selected.
// The the title and state can be checked for required action.
// 
void ofApp::appMenuFunction(string title, bool bChecked) {

	ofFileDialogResult result;
	string filePath;
	size_t pos;

	//
	// File menu
	//
	if(title == "Open") {
		if (isOpen) {
			freeMemory();
			isdfs = false;
			isbfs = false;
		}
		readFile();
	}
	if(title == "Exit") {
		freeMemory();
		ofExit(); // Quit the application
	}

	//
	// Window menu
	//
	if(title == "Show DFS") {
		//bShowInfo = bChecked;  // Flag is used elsewhere in Draw()
		if (isOpen)
		{
			maze_col = 1;
			maze_row = 1;
			visited.clear();
			vector<int> temp_vec;
			for (int i = 0; i < WIDTH; i++) {
				temp_vec.push_back(0);
			}
			for (int i = 0; i < HEIGHT; i++) {
				visited.push_back(temp_vec);
			}
			visited[1][1] = 1;
			/*
			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					cout << visited[i][j] << " ";
				}
				cout << endl;
			}
			*/
			DFS(maze_col, maze_row);

			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					cout << setw(2) << visited[i][j] << " ";
				}
				cout << endl;
			}
			isdfs = true;
			isbfs = false;
			bShowInfo = bChecked;
		}
		else
			cout << "you must open file first" << endl;
		
	}

	if(title == "Show BFS") {
		//doTopmost(bChecked); // Use the checked value directly
		if (isOpen) {
			maze_col = 1;
			maze_row = 1;
			visited.clear();
			vector<int> temp_vec;
			for (int i = 0; i < WIDTH; i++) {
				temp_vec.push_back(0);
			}
			for (int i = 0; i < HEIGHT; i++) {
				visited.push_back(temp_vec);
			}
			visited[1][1] = 1;
			BFS(maze_col, maze_row);
			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					cout << setw(2) << visited[i][j] << " ";
				}
				cout << endl;
			}
			isbfs = true;
			isdfs = false;
			bShowInfo = bChecked;
		}
		else
			cout << "you must open file first" << endl;
	}

	if(title == "Full screen") {
		bFullscreen = !bFullscreen; // Not auto-checked and also used in the keyPressed function
		doFullScreen(bFullscreen); // But als take action immediately
	}

	//
	// Help menu
	//
	if(title == "About") {
		ofSystemAlertDialog("ofxWinMenu\nbasic example\n\nhttp://spout.zeal.co");
	}

} // end appMenuFunction


//--------------------------------------------------------------
void ofApp::update() {

}


//--------------------------------------------------------------
void ofApp::draw() {

	char str[256];
	//ofBackground(0, 0, 0, 0);
	ofSetColor(100);
	ofSetLineWidth(5);
	int i, j;
	
	// TO DO : DRAW MAZE; 
	// 저장된 자료구조를 이용해 미로를 그린다.
	// add code here
	ofSetColor(ofColor::black);
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (input[j][i] == '-') {
				ofDrawLine(shift+length*(i + 1) / 2, shift + length*(j + 2) / 2, shift + length + length * (i + 1) / 2, shift + length*(j + 2) / 2);
			}
			if (input[j][i] == '|') {
				ofDrawLine(shift + length*(i + 2) / 2, shift + length*(j + 1) / 2, shift + length * (i + 2) / 2, shift + length+length*(j + 1) / 2);
			}
		}
	}
	if (isdfs)
	{
		ofSetColor(200);
		ofSetLineWidth(5);
		if (isOpen)
			dfsdraw();
		else
			cout << "You must open file first" << endl;
	}
	if (isbfs)
	{
		ofSetColor(200);
		ofSetLineWidth(5);
		if (isOpen)
			bfsdraw();
		else
			cout << "You must open file first" << endl;
	}
	if(bShowInfo) {
		// Show keyboard duplicates of menu functions
		sprintf(str, " comsil project");
		myFont.drawString(str, 15, ofGetHeight()-20);
	}

} // end Draw


void ofApp::doFullScreen(bool bFull)
{
	// Enter full screen
	if(bFull) {
		// Remove the menu but don't destroy it
		menu->RemoveWindowMenu();
		// hide the cursor
		ofHideCursor();
		// Set full screen
		ofSetFullscreen(true);
	}
	else { 
		// return from full screen
		ofSetFullscreen(false);
		// Restore the menu
		menu->SetWindowMenu();
		// Restore the window size allowing for the menu
		ofSetWindowShape(windowWidth, windowHeight + GetSystemMetrics(SM_CYMENU)); 
		// Centre on the screen
		ofSetWindowPosition((ofGetScreenWidth()-ofGetWidth())/2, (ofGetScreenHeight()-ofGetHeight())/2);
		// Show the cursor again
		ofShowCursor();
		// Restore topmost state
		if(bTopmost) doTopmost(true);
	}

} // end doFullScreen


void ofApp::doTopmost(bool bTop)
{
	if(bTop) {
		// get the current top window for return
		hWndForeground = GetForegroundWindow();
		// Set this window topmost
		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); 
		ShowWindow(hWnd, SW_SHOW);
	}
	else {
		SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		ShowWindow(hWnd, SW_SHOW);
		// Reset the window that was topmost before
		if(GetWindowLong(hWndForeground, GWL_EXSTYLE) & WS_EX_TOPMOST)
			SetWindowPos(hWndForeground, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); 
		else
			SetWindowPos(hWndForeground, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); 
	}
} // end doTopmost


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	// Escape key exit has been disabled but it can be checked here
	if(key == VK_ESCAPE) {
		// Disable fullscreen set, otherwise quit the application as usual
		if(bFullscreen) {
			bFullscreen = false;
			doFullScreen(false);
		}
		else {
			ofExit();
		}
	}

	// Remove or show screen info
	if(key == ' ') {
		bShowInfo = !bShowInfo;
		// Update the menu check mark because the item state has been changed here
		menu->SetPopupItem("Show DFS", bShowInfo);
	}

	if(key == 'f') {
		bFullscreen = !bFullscreen;	
		doFullScreen(bFullscreen);
		// Do not check this menu item
		// If there is no menu when you call the SetPopupItem function it will crash
	}

} // end keyPressed

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp	::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
bool ofApp::readFile()
{
	ofFileDialogResult openFileResult = ofSystemLoadDialog("Select .maz file");
	string filePath;
	size_t pos;
	// Check whether the user opened a file
	if (openFileResult.bSuccess) {
		ofLogVerbose("User selected a file");

		//We have a file, check it and process it
		string fileName = openFileResult.getName();
		//string fileName = "new.maz";
		printf("file name is %s\n", fileName);
		filePath = openFileResult.getPath();
		printf("Open\n");
		pos = filePath.find_last_of(".");
		if (pos != string::npos && pos != 0 && filePath.substr(pos + 1) == "maz") {

			ofFile file(fileName);

			if (!file.exists()) {
				cout << "Target file does not exists." << endl;
				return false;
			}
			else {
				cout << "We found the target file." << endl;
				isOpen = 1;
			}

			ofBuffer buffer(file);

			// Input_flag is a variable for indication the type of input.
			// If input_flag is zero, then work of line input is progress.
			// If input_flag is one, then work of dot input is progress.
			int input_flag = 0;

			// Idx is a variable for index of array.
			int idx = 0;

			// Read file line by line
			int cnt = 0;

			// TO DO
			// .maz 파일을 input으로 받아서 적절히 자료구조에 넣는다
			for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
				string line = *it;
				WIDTH = line.size();
				input.push_back(line);
				idx += 1;
				cout << line << endl;
			}
			HEIGHT = idx;
		}
		else {
			printf("  Needs a '.maz' extension\n");
			return false;
		}
		return true;
	}
	return false;
}
void ofApp::freeMemory() {
	input.clear();
	log.clear();
	stack.clear();
	visited.clear();
	//TO DO
	// malloc한 memory를 free해주는 함수
}

bool ofApp::DFS(int maze_col,int maze_row)//DFS탐색을 하는 함수{	
{
	stack.push_back(make_pair(maze_col, maze_row));
	visited[maze_col][maze_row] = 1;
	int check = 0;
	while (stack.size() != 0) {
		check = 0;
		maze_col = stack[stack.size() - 1].first;
		maze_row = stack[stack.size() - 1].second;
		if (stack[stack.size() - 1].first == HEIGHT - 2 && stack[stack.size() - 1].second == WIDTH - 2) {
			return true;
		}
		if (maze_col < HEIGHT - 2) {
			if (input[maze_col + 1][maze_row] == ' ' && visited[maze_col + 2][maze_row] == 0) {
				stack.push_back(make_pair(maze_col + 2, maze_row));
				check = 1;
				visited[maze_col + 2][maze_row] = 1;
				continue;
			}
		}
		if (maze_col > 1) {
			if (input[maze_col - 1][maze_row] == ' ' && visited[maze_col - 2][maze_row] == 0) {
				stack.push_back(make_pair(maze_col - 2, maze_row));
				check = 1;
				visited[maze_col - 2][maze_row] = 1;
				continue;
			}
		}
		if (maze_row < WIDTH - 2) {
			if (input[maze_col][maze_row + 1] == ' ' && visited[maze_col][maze_row + 2] == 0) {
				stack.push_back(make_pair(maze_col, maze_row + 2));
				check = 1;
				visited[maze_col][maze_row + 2] = 1;
				continue;
			}
		}
		if (maze_row > 1) {
			if (input[maze_col][maze_row - 1] == ' ' && visited[maze_col][maze_row - 2] == 0) {
				stack.push_back(make_pair(maze_col, maze_row - 2));
				check = 1;
				visited[maze_col][maze_row - 2] = 1;
				continue;
			}
		}
		if (check == 0) {
			stack.pop_back();
		}
	}
}
void ofApp::dfsdraw()
{	

	//TO DO 
	//DFS를 수행한 결과를 그린다. (3주차 내용)
	for (int i = 1; i < HEIGHT; i+=2) {
		for (int j = 1; j < WIDTH-2; j += 2) {
			if (visited[i][j] == 1 && visited[i][j + 2] == 1 && input[i][j + 1] == ' ') {
				ofDrawLine(shift + length / 2 + (j + 1)*length / 2, shift + length / 2 + (i + 1)*length / 2, shift + length / 2 + (j + 2 + 1)*length / 2, shift + length / 2 + (i + 1)*length / 2);
			}
		}
	}
	for (int i = 1; i < HEIGHT - 2; i += 2) {
		for (int j = 1; j < WIDTH; j += 2) {
			if (visited[i][j] == 1 && visited[i + 2][j] == 1 && input[i + 1][j] == ' ') {
				ofDrawLine(shift + length / 2 + (j + 1)*length / 2, shift + length / 2 + (i + 1)*length / 2, shift + length / 2 + (j + 1)*length / 2, shift + length / 2 + (i + 2 + 1)*length / 2);
			}
		}
	}
	ofSetColor(ofColor::red);
	for (int i = 0; i < stack.size() - 1; i++) {
		ofDrawLine(shift + length / 2 + (stack[i].second + 1)*length / 2, shift + length / 2 + (stack[i].first + 1)*length / 2, shift + length / 2 + (stack[i + 1].second + 1)*length / 2, shift + length / 2 + (stack[i + 1].first + 1)*length / 2);
		if (stack[i + 1].second == HEIGHT - 2 && stack[i + 1].first == WIDTH - 2) break;
	}
}

bool ofApp::BFS(int maze_col, int maze_row) {
	
	q.push(make_pair(maze_col, maze_row));
	visited[maze_col][maze_row] = 1;
	pair<int, int> temp;
	int visit_cnt = 1;
	while (q.empty() == false) {
		visit_cnt += 1;
		temp = q.front();
		q.pop();
		maze_col = temp.first;
		maze_row = temp.second;
		if (maze_col == HEIGHT - 2 && maze_row == WIDTH - 2) {
			return true;
		}
		if (maze_col < HEIGHT - 2) {
			if (input[maze_col + 1][maze_row] == ' ' && visited[maze_col + 2][maze_row] == 0) {
				visited[maze_col + 2][maze_row] = visit_cnt;
				q.push(make_pair(maze_col+2, maze_row));
			}
		}
		if (maze_col > 1) {
			if (input[maze_col - 1][maze_row] == ' ' && visited[maze_col - 2][maze_row] == 0) {
				visited[maze_col - 2][maze_row] = visit_cnt;
				q.push(make_pair(maze_col - 2, maze_row));
			}
		}
		if (maze_row < WIDTH - 2) {
			if (input[maze_col][maze_row + 1] == ' ' && visited[maze_col][maze_row + 2] == 0) {
				visited[maze_col][maze_row + 2] = visit_cnt;
				q.push(make_pair(maze_col, maze_row + 2));
			}
		}
		if (maze_row > 1) {
			if (input[maze_col][maze_row - 1] == ' ' && visited[maze_col][maze_row - 2] == 0) {
				visited[maze_col][maze_row - 2] = visit_cnt;
				q.push(make_pair(maze_col, maze_row - 2));
			}
		}
	}
	return 0;
}
void ofApp::bfsdraw() {
	for (int i = 1; i < HEIGHT; i += 2) {
		for (int j = 1; j < WIDTH - 2; j += 2) {
			if (visited[i][j] >= 1 && visited[i][j + 2] >= 1 && input[i][j + 1] == ' ') {
				ofDrawLine(shift + length / 2 + (j + 1)*length / 2, shift + length / 2 + (i + 1)*length / 2, shift + length / 2 + (j + 2 + 1)*length / 2, shift + length / 2 + (i + 1)*length / 2);
			}
		}
	}
	for (int i = 1; i < HEIGHT - 2; i += 2) {
		for (int j = 1; j < WIDTH; j += 2) {
			if (visited[i][j] >= 1 && visited[i + 2][j] >= 1 && input[i + 1][j] == ' ') {
				ofDrawLine(shift + length / 2 + (j + 1)*length / 2, shift + length / 2 + (i + 1)*length / 2, shift + length / 2 + (j + 1)*length / 2, shift + length / 2 + (i + 2 + 1)*length / 2);
			}
		}
	}
	ofSetColor(ofColor::red);
	int i, j;
	int nexti = HEIGHT - 2;
	int nextj = WIDTH - 2;
	int vec[4];
	while(1) {
		i = nexti;
		j = nextj;
		if (i == 1 && j == 1) break;
		//[up,down,right,left]
		for (int a = 0; a < 4; a++) {
			vec[a] = 1000000;
		}
		//up
		if (i > 1 && visited[i-2][j]!=0 && input[i-1][j]==' ') {
			vec[0] = visited[i - 2][j];
		}
		if (i < HEIGHT-2 && visited[i + 2][j] != 0 && input[i + 1][j] == ' ') {
			vec[1] = visited[i + 2][j];
		}
		if (j > 1 && visited[i][j-2] != 0 && input[i][j - 1] == ' ') {
			vec[2] = visited[i][j - 2];
		}
		if (j < WIDTH - 2 && visited[i][j + 2] != 0 && input[i][j + 1] == ' ') {
			vec[3] = visited[i][j + 2];
		}
		int smallest = vec[0];
		
		for (int i = 1; i < 4; ++i) {
			smallest = min(smallest, vec[i]);
		}
		if (vec[0] == smallest) {
			nexti = i - 2;
		}
		if (vec[1] == smallest) {
			nexti = i + 2;
		}
		if (vec[2] == smallest) {
			nextj = j - 2;
		}
		if (vec[3] == smallest) {
			nextj = j + 2;
		}
		ofDrawLine(shift + length / 2 + (j + 1)*length / 2, shift + length / 2 + (i + 1)*length / 2, shift + length / 2 + (nextj + 1)*length / 2, shift + length / 2 + (nexti + 1)*length / 2);
	}
}