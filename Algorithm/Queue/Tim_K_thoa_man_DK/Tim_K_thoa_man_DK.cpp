#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,L,R,OK[6];

void PT (ll tmp){
	memset(OK,0,sizeof(OK));
	while (tmp != 0){
		OK[tmp%10]++;
		tmp = tmp/10;
	}
}

int main (){
	cin >> T;
	while (T--){
		cin >> L >> R;
		queue <ll> A;
		for (int i = 1 ; i <= 5 ; i++) A.push(i);
		ll count = 0;
		while (A.front() <= R){
			ll tmp = A.front();
			if (tmp >= L) count++;
			A.pop();
			PT (tmp);
			for (int i = 0 ; i <= 5 ; i++){
				if (OK[i] == 0) A.push(tmp*10+i);
			}
		}
		cout << count << endl;
	}
	return 0;
}
