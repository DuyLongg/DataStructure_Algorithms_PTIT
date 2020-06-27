#include <bits/stdc++.h>
using namespace std;

long long T,N;
string s1,s2;

int main (){
	cin >> T;
	while (T--){
		s1 = "";
		cin >> N;
		for (int i = 1 ; i <= N ; i++){
			cin >> s2;
			s1 = s1 + s2;
		}
		sort (s1.begin(),s1.end());
		cout << s1[0] << " ";
		for (int i = 1 ; i < s1.size() ; i++){
			if (s1[i] != s1[i-1]) cout << s1[i] << " ";
		} cout << endl;
	}
	return 0;
}
