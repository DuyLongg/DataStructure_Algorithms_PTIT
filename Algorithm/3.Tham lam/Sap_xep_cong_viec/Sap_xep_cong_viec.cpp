#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector <int> c;
		while (N--){
			int a,b;
			cin >> a >> b;
			c.push_back(b*10+a);
		}
		sort(c.begin(),c.end());
		int so_cv = 1,j = 0;
		for (int i = 1 ; i < c.size() ; i++){
			if (c[i]%10 > c[j]/10){
				so_cv++;
				j = i;
			}
		}
		cout << so_cv << endl;
	}
	return 0;
}
