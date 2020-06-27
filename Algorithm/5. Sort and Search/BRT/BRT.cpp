#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector <int> a;
		int tmp;
		for (int i = 0 ; i < N ; i++) {
			cin >> tmp;
			a.push_back(tmp);
		}
		sort (a.begin(),a.end());
		int hieu_min = 1000000000, soluong = 0; 
		for (int i = 0 ; i < N-1 ; i++){
			int hieu = a[i+1]-a[i];
			if (hieu < hieu_min) {
				hieu_min = hieu;
				soluong = 1;
			} else if (hieu == hieu_min) soluong++;
		}
		cout << hieu_min << " " << soluong << endl;
	}
	return 0;
}
