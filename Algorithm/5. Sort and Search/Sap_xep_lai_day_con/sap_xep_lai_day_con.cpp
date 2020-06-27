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
		for (int i = 0 ; i < N ; i++){
			cin >> tmp;
			a.push_back(tmp);
		}
		vector <int> c (a);
		sort(c.begin(),c.end());
		int i=0,j=N-1;
		while (i < N) {
			if (a[i] == c[i]) i++;
			else break;
		}
		while (j >= 0) {
			if (a[j] == c[j]) j--;
			else break;
		}
		if (i==N && j==-1) cout << "YES" << endl;
		else cout << j-i+1 << endl;
	}
	return 0;
}
