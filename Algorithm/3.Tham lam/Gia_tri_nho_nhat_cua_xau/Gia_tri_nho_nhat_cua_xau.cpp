#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int K; cin >> K;
		string S; cin >> S;
		int Hz[26]; memset (Hz,0,sizeof(Hz));
		for (int i = 0 ; i < S.size() ; i++) Hz[S[i]-'A']++;
		priority_queue <int> hz;
		for (int i = 0 ; i < 26 ; i++) hz.push(Hz[i]);
		for (int i = 0 ; i < K ; i++){
			int tmp = hz.top(); hz.pop();
			hz.push(--tmp);
		}
		int kq = 0;
		while (hz.size()){
			kq = kq + hz.top()*hz.top(); hz.pop();
		}
		cout << kq << endl;
	}
	return 0;
}
