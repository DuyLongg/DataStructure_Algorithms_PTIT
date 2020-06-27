#include <iostream>
using namespace std;

int n;
int cot[10];
int cheotrai[10*2-1];
int cheophai[10*2-1];
int dem = 0;
void Try (int i){
	for (int j = 0 ; j < n ; j++){
		if(cot[j] == 0 && cheophai[i+j] == 0 && cheotrai[n-1-i+j] == 0){
			cot[j] = 1;		
			cheophai[i+j] = 1;
			cheotrai[n-1-i+j] = 1;
			if (i==n-1) dem++;
			else Try(i+1);
			cot[j] = 0;
			cheophai[i+j] = 0;
			cheotrai[n-1-i+j] = 0;
		}
	}
}

int main (){
	cin >> n;
	Try (0);
	cout << dem << endl;	
	return 0;
}

