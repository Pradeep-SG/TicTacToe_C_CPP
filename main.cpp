#include <iostream>
using namespace std;

bool isValid(string str, char arr[][3]){
	if(str[1]!='-') return false;
	int x = str[0]-'0', y = str[2]-'0';
	if((x>=1) && (x<=3) && (y>=1) && (y<=3) && (arr[x-1][y-1]==' '))
		return true;
	return false;
}

bool isOver(char arr[][3]){
	for(int i=0, j=0; i<3; i++)
		if(arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]!=' ')
			return true;
	for(int i=0, j=0; j<3; j++)
		if(arr[i][j]==arr[i+1][j] && arr[i][j]==arr[i+2][j] && arr[i][j]!=' ')
			return true;	
	if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2] && arr[0][0]!=' ') return true;
	if(arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0] && arr[0][2]!=' ') return true;
	return false;
}
bool isDrawn(char arr[][3]){
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(arr[i][j]==' ') return false;
	return true;
}
playGame(string str, char arr[][3], char c){
	int x = str[0]-'0', y = str[2]-'0';
	arr[x-1][y-1] = c;	
}
printBoard(char arr[][3]){
	cout << "\n\n";
	cout << "  	    1  2  3" << endl;
	for(int i=0; i<3; i++){
		cout << "	" << i+1 << "  ";
		for(int j=0; j<3; j++){
			cout << arr[i][j];
			if(j<2) cout << " | ";
		}
		if(i<2) cout << endl << "	   ---------" << endl;
	}
	cout << "\n\n";
}

int main() {	
m:	char arr[3][3] = {{' ', ' ', ' '},
					  {' ', ' ', ' '},
					  {' ', ' ', ' '}};
	cout << "Note : 1-3 -> Top Right, 3-1 -> Bottom Left\n\n";
	string str;
	int count=0, play=1;
	char playXO=' ', c;
	
	printBoard(arr);
	while(true){
		if(count%2){
			play=2;
			playXO='O';
		}else{
			play=1;
			playXO='X';
		}
		count++;
		
n:		cout << "\nPlayer " << play << " : ";
		cin>>str;
		if(isValid(str, arr)){
			playGame(str, arr, playXO);
		} else{
			cout << "Can't move there bruh :(\n\n";
			goto n;
		}
		
		printBoard(arr);
		if(isOver(arr)){
			cout << "\nPlayer "<< play << " wins :)\n\nPress 'R' to start - ";
			cin>>c;
			if(c=='R' || c=='r') goto m;
			return 0;
		}
		if(isDrawn(arr)){
			cout << "\nMatch Drawn :|\n\nPress 'R' to retry - ";
			cin>>c;
			if(c=='R' || c=='r') goto m;
		}
	}
	return 0;
}
