#include <iostream>
using namespace std;

int N;// so xau
string xau[10];
int FOPT = 10000000;
int xet[10];

void Nhap_xau(){
	for (int i = 0 ; i < N ; i++){
		cin >> xau[i];
	}
}

int lap(int j_moi, int j_cu){
	// so sanh voi xau[i-1]
	int sll = 0;
	for (int i = 0 ; i < xau[j_moi].length() ; i++){
		for (int j = 0 ; j < xau[j_cu].length() ; j++){
			if (xau[j_moi][i]==xau[j_cu][j]) {
				sll++;
				break;
			}
		}
	}
	return sll;
}

int sll_step[10] = {0};
void Try (int i, int j_cu){
	for (int j = 0 ; j < N ; j++){
		if (xet[j]) continue;
		xet[j] = 1;
		if (i>=2) sll_step[i] = sll_step[i-1] + lap(j,j_cu);
		if (i==N && sll_step[i] < FOPT) FOPT = sll_step[i];
		else Try (i+1,j);
		xet[j] = 0;
	}
}

int main (){
	cin >> N;
	Nhap_xau();
	Try(1,0);
	cout << FOPT << endl;
	return 0;
}
