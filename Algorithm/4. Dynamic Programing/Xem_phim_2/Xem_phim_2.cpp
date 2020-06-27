#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C,N;
vector <int> Wei;
int step[101] = {0};
int FOPT = 0;

void Nhap_Wei (){
	int temp;
	for (int i = 0 ; i < N ; i++){
		cin >> temp;
		Wei.push_back(temp);
	}
}

void Try (int i, int j_cu){
	for (int j = j_cu+1 ; j < N ; j++){
		step[i] = step[i-1] + Wei[j];
		if (j < N-1 && step[i] + Wei[j+1] <= C) Try (i+1,j);
		else {
 			if (step[i] <= C && step[i] > FOPT) {
				FOPT = step[i];
			}
		}
	}
}

int main (){
	cin >> C >> N;
	Nhap_Wei();
	sort (Wei.begin(), Wei.end());
	Try (1,-1);
	cout << FOPT << endl;
	return 0;
}
