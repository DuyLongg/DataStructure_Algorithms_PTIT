#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,C;
vector <int> W;
int FOPT = -1;
int W_max = 0;

void Nhap_W (){
	for (int i = 0 ; i < N ; i++){
		int b;
		cin >> b;
		W.push_back(b);
	}
}

void Try (int i, int t){
	for (int j = t+1 ; j < N ; j++){
		W_max = W_max + W[j];
		if (j <= N-2 && W_max + W[j+1] <= C) Try (i+1,j);
		else{
			if (W_max <= C && W_max > FOPT) FOPT = W_max;
		} 
		W_max = W_max - W[j];
	}
}

int main (){
	cin >> C >> N;
	Nhap_W ();
	sort (W.begin(), W.end());
	Try (0,-1);
	cout << FOPT << endl;
	return 0;
}
