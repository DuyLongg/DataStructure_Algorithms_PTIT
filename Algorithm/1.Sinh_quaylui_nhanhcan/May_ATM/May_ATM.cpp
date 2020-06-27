#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,S;
vector <int> t;
int soto = 31;
int tong[30];
	
inline void Try (int i, int r){
	for (int j = r+1 ; j < n ; j++){
		if (i==0) tong[i] = t[j];
		else tong[i] = tong[i-1] + t[j];
		if (tong[i] == S) {
			if (i+1 < soto) soto = i+1;
		}
		if (tong[i] + t[j+1] <= S && j < n-1) Try (i+1,j);
	}
}

int main (){
	cin >> n >> S;
	int b;
	for (int i = 0 ; i < n ; i++){
		cin >> b;
		t.push_back(b);
	}
	sort (t.begin(), t.end());
	reverse(t.begin(),t.end());
	Try (0,-1);
	if (soto == 31) cout << -1 << endl;
	else cout << soto << endl;
	return 0;
}
