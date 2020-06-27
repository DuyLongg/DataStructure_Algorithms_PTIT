#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,H[100005];

ll DT_max (){
	stack <ll> A;
	ll DT_max = 0;
	ll DT_tmp,cur_bar;
	ll i = 0;
	while (i < N){
		if (A.empty() || H[A.top()] <= H[i]) A.push(i++);
		else {
			cur_bar = A.top();
			A.pop();
			DT_tmp = H[cur_bar] * (A.empty() ? i : i-A.top()-1);
			DT_max = max (DT_max, DT_tmp);
		}
	}
	while (!A.empty()){
		cur_bar = A.top();
		A.pop();
		DT_tmp = H[cur_bar] * (A.empty() ? i : i-A.top()-1);
		DT_max = max (DT_max,DT_tmp);
	}
	return DT_max;
}

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0 ; i < N ; i++) cin >> H[i];
		cout << DT_max() << endl;
	}
	return 0;
}
