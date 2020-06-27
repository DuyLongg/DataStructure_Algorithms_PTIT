#include <iostream>
using namespace std;

int n;// so thanh pho
int c[15][15];
int FOPT = 1000000000;
int c_min = 1000000000;
int fee = 0;
int check[15] = {0};
void Input_fee (){
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++){
			cin >> c[i][j];
			if (c[i][j] < c_min && i!=j) c_min = c[i][j];
		}
	}
}

void Branch_and_Bound (int i, int Citys){
	check[i] = 1;
	for (int j = 0 ; j < n ; j++){
		if (check[j] == 1) continue;
		fee = fee + c[i][j];
		if (Citys == n && fee + c[j][0] < FOPT) FOPT = fee + c[j][0];
		else if (fee + c_min < FOPT) Branch_and_Bound (j, Citys+1);
		fee = fee - c[i][j];
	}
	check[i] = 0;
}

int main (){
	cin >> n;
	Input_fee();
	Branch_and_Bound(0,2);
	cout << FOPT << endl;
	return 0;
}
