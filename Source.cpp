#include<iostream>
using namespace std;
int heuristic(int a[], int g[]);
int search(int elem, int g[]);
void expan(int I[], int G[],int c);
int findblA(int A[]);
int findblB(int B[]);
int *moveAUp(int init[], int g[], int b);
int *moveAdown(int init[], int g[], int b);
int *moveAright(int init[], int g[], int b);
int *moveAleft(int init[], int g[], int b);
int *moveBUp(int init[], int g[], int b);
int *moveBdown(int init[], int g[], int b);
int *moveBright(int init[], int g[], int b);
int *moveBleft(int init[], int g[], int b);
void check(int min, int state[],string s,int g[],int c);

int heuristic(int a[],int g[]) {
	int sumH = 0;
	int h = 0;
	for (int i = 0; i < 9; i++) {
		h = search(a[i], g);
		sumH+=abs(h-i);
	}
	return sumH;
}
int search(int elem, int g[]) {
	int x = 0;
	for (int i = 0; i < 9; i++) {
		if (g[i] == elem) {
			x=i;
			break;
		}
	
}
	return x;
}
void expan(int I[], int G[],int c) {
	c++;

	int indexA = 0;
	int indexB = 0;
	int state1[9];
	int state2[9];
	int state3[9];
	int state4[9];
	int state5[9];
	int state6[9];
	int state7[9];
	int state8[9];

	int hset[8] = { 0 };
	indexA=findblA(I);
	indexB=findblB(I);
	if ((heuristic(I, G) / 2)==0) {
		cout << "the initial state = the goal state and no expansion needed";
	}
	else {

	
	int* states1 = moveAUp(I, G, indexA);
	int* states2 = moveAdown(I, G, indexA);
	int* states3 = moveAright(I, G, indexA);
	int* states4 = moveAleft(I, G, indexA);
	int* states5 = moveBUp(I, G, indexB);
	int* states6 = moveBdown(I, G, indexB);
	int* states7 = moveBright(I, G, indexB);
	int* states8 = moveBleft(I, G, indexB);
	
	for (int i = 0; i < 9; i++) {
		state1[i] = states1[i];
	}
	for (int i = 0; i < 9; i++) {
		state2[i] = states2[i];
	}
	for (int i = 0; i < 9; i++) {
		state3[i] = states3[i];
	}
	for (int i = 0; i < 9; i++) {
		state4[i] = states4[i];
	}
	for (int i = 0; i < 9; i++) {
		state5[i] = states5[i];
	}
	for (int i = 0; i < 9; i++) {
		state6[i] = states6[i];
	}
	for (int i = 0; i < 9; i++) {
		state7[i] = states7[i];
	}
	for (int i = 0; i < 9; i++) {
		state8[i] = states8[i];
	}

	hset[0] = heuristic(state1, G)/2;
	hset[1] = heuristic(state2, G)/2;
	hset[2] = heuristic(state3, G)/2;
	hset[3] = heuristic(state4, G)/2;
	hset[4] = heuristic(state5, G)/2;
	hset[5] = heuristic(state6, G)/2;
	hset[6] = heuristic(state7, G)/2;
	hset[7] = heuristic(state8, G)/2;
	
	int min = hset[0];
	string s;
	for (int i = 0; i < 8; i++) {
		if (hset[i] < min) {
			min = hset[i];
		}
	}
	
	
	if (hset[0]==min) {
	    s= "Move blank A up" ;
		check(min,state1,s,G,c);
	}
	else if (hset[1] == min) {
		s = "Move blank A down";
		check(min, state2, s, G, c);
		
	}
    else if (hset[2] == min) {
		s="Move blank A right";
		check(min, state3, s, G, c);
	}

	else if (hset[3] == min) {
		s = "Move blank A left";
		check(min, state4, s, G, c);
	}
    else if (hset[4] == min) {
		s="Move blank B up";
		check(min, state5, s, G, c);
	}
    else if (hset[5] == min) {
		s= "Move blank B down";
		check(min, state6, s, G, c);
	}

    else if (hset[6] == min) {
		s="Move blank B right";
		check(min, state7, s, G, c);
	}

    else {
		s="Move blank B left";
		check(min, state8, s, G, c);
	}

}
}
int findblA(int A[]) {
	int x = 0;
	for (int i = 0; i < 9; i++) {
		if (A[i] == 'a'|| A[i] == 'A') {
			x = i;
			break;
		}
	}
	return x;
}
int findblB(int B[]) {
	int x = 0;
	for (int i = 0; i < 9; i++) {
		if (B[i] == 'b' || B[i] == 'B') {
			x = i;
			break;
		}
	}
	return x;
}
int *moveAUp(int init[], int g[], int b) {
	static int newa[9]={99,99,99,99,99,99,99,99,99};
	if (b == 0 || b == 1 || b == 2) {
		return newa;
	}
	else {
		int b2= b - 3;
		
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
		
		return newa;
	}
}
int *moveAdown(int init[], int g[], int b) {
	static int newa[9]={ 99,99,99,99,99,99,99,99,99 };
	if (b == 6 || b == 7 || b == 8) {
		return newa;
	}
	else {
		int b2 = b + 3;
		
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
		return newa;
	}
}
int *moveAright(int init[], int g[], int b) {
	static int newa[9]={ 99,99,99,99,99,99,99,99,99 };
	if (b == 2 || b == 5 || b == 8) {
		return newa;
	}
	else {
		int b2 = b + 1;
		
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
		
		return newa;
	}
}
int *moveAleft(int init[], int g[], int b) {
	static int newa[9] = { 99,99,99,99,99,99,99,99,99 };
	if (b == 0 || b == 3 || b == 6) {
		return newa;
	}
	else {
		int b2 = b - 1;
		
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
		
		return newa;
	}
}
int *moveBUp(int init[], int g[], int b) {
	static int newa[9] = { 99,99,99,99,99,99,99,99,99 };
	if (b == 0 || b == 1 || b == 2) {
		return newa;
	}
	else {
		int b2 = b - 3;
		
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
	
		return newa;
	}
}
int *moveBdown(int init[], int g[], int b) {
	static int newa[9] = { 99,99,99,99,99,99,99,99,99 };
	if (b == 6 || b == 7 || b == 8) {
		return newa;
	}
	else {
		int b2 = b + 3;
		
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
	
		return newa;
	}
}
int *moveBright(int init[], int g[], int b) {
	static int newa[9] = { 99,99,99,99,99,99,99,99,99 };
	if (b == 2 || b == 5 || b == 8) {
		return newa;
	}
	else {
		int b2 = b + 1;
		
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
		
		return newa;
	}
}
int *moveBleft(int init[], int g[], int b) {
	static int newa[9]={ 99,99,99,99,99,99,99,99,99 };
	if (b == 0 || b == 3 || b == 6) {
		return newa;
	}
	else {
		int b2 = b - 1;
		int swapel;
		for (int i = 0; i < 9; i++) {
			newa[i] = init[i];
		}
		swapel = newa[b];
		newa[b] = newa[b2];
		newa[b2] = swapel;
		
		return newa;
	}
}
void check(int min, int state[], string s, int g[], int c) {
	if (min == 0) {

		cout <<s;
		cout << endl;
		cout << "The number of states expanded is :" << c;
		exit(0);

	}
	else {

	cout << s << endl;
	expan(state, g, c);

	}
}

int main()
{
	int count=0;
	int a[9] = { 'A',2,1,4,3,7,5,'B',6};
	int g[9] = { 4,2,1,'A',7,'B',5,3,6};
	
	expan(a, g, count);

}






















