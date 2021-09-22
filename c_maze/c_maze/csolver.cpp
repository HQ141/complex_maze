#include<iostream>
#include<fstream>
using namespace std;
#include"dsa.h"
#define s 9
int func(bool arr[s][s], int i, int j, DSA<int >* ptr, DSA<bool >* barr);
bool fun(DSA<int >*, DSA<bool >*, int, int,int ,int);
int main() {
	ifstream file;
	file.open("tre.txt", ios::in);

	DSA<int >* ptr = new DSA<int>[s];
	for (int i = 0; i < s; i++)
		ptr[i] = DSA<int>();

	DSA<bool >* barr = new DSA<bool>[s];
	for (int i = 0; i < s; i++)
		barr[i] = DSA<bool>();
	bool maze[s][s];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			//maze[i][j] = rand() % 2;
			file >> maze[i][j];
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	//cout << endl << endl;
	func(maze, 0, 0, ptr,barr);
	/*for (int i = 0; i < s; i++) {
		int temp = ptr[i].get_size();
		for (int j = 0; j < temp; j++)
			cout << ptr[i][j]<< " ";
		cout << endl;
	}
	cout << endl << endl;*/
	fun(ptr,barr, 0, 0,-1,-1);
}
int func(bool arr[s][s], int i, int j, DSA<int >* ptr, DSA<bool >* barr) {
	if (i == s)
		return 0;
	bool a = 0;
	if (arr[i][j] == 1) {
		ptr[i].push(j);
		barr[i].push(a);
	}
	if (j == s - 1)
		return func(arr, i + 1, 0, ptr,barr);
	return func(arr, i, j + 1, ptr,barr);
}
bool fun(DSA<int >* ptr, DSA<bool >* barr, int i, int j,int pi,int pj){
	cout << "At " << i << " " << ptr[i][j] << endl;
	if (i == s - 1 && ptr[i][j] == s - 1) {
		cout << "Reached Destination" << endl;
		return 1;
	}
	barr[i][j] = true;
	bool p = false;
	if (j + 1 < ptr[i].get_size())
		if (ptr[i][j] + 1 == ptr[i][j + 1])
			if (barr[i][j + 1] == false)
			p= fun(ptr,barr, i, j + 1,i,j);
	if (j - 1 > -1)
	if (!p)
			if (ptr[i][j] - 1 == ptr[i][j - 1])
				if (barr[i][j - 1] == false) 
				p = fun(ptr, barr,i, j - 1,i,j);
	if(!p)
		if (i != s - 1){
		int x;
		bool t = false;
		int temp = ptr[i + 1].get_size();
		for (x = 0; x < temp; x++) {
			if (ptr[i + 1][x] == ptr[i][j]) {
				t = true;
				break;
			}
			if (ptr[i + 1][x] > ptr[i][j])break;
		}
		if (t)
			if (barr[i + 1][x] == false)
			p= fun(ptr, barr,i + 1, x,i,j);
	}
	if(!p)
	if (i != 0){
		int x;
		bool t = false;
		int temp = ptr[i - 1].get_size();
		for (x = 0; x < temp; x++) {
			if (ptr[i - 1][x] == ptr[i][j]) {
				t = true;
				break;
			}
			if (ptr[i - 1][x] > ptr[i][j])break;
		}
		if (t) {
			if (barr[i - 1][x] == false)
			p = fun(ptr, barr, i - 1, x, i, j);
		}
	}
	if (!p) { cout << "Retreat:At " << i << " " << ptr[i][j] << endl; return p; }
	return p;

}