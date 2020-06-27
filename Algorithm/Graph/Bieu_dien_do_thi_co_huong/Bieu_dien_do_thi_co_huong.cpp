#include <bits/stdc++.h>
using namespace std;

int T,V,E,col1,col2;

int main (){
	cin >> T;
	while (T--){
		unordered_map <int, vector<int>> A;
		cin >> V >> E;
		for (int i = 1 ; i <= E ; i++){
			cin >> col1 >> col2;
			A[col1].push_back(col2);
		}
		for (int i = 1 ; i <= V ; i++){
			cout << i << ": ";
			for (int j = 0 ; j < A[i].size() ; j++){
				cout << A[i][j] << " ";
			} cout << endl;
		}
	}
	return 0;
}
