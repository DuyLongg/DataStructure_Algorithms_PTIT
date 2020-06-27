#include <bits/stdc++.h>
#define ll long long
using namespace std;
// code tham khao cua anh buiminhptit
string S;
long a[20], b[20], st[20], n, t, x[20], xh[201], l, r = 0;
string rs[2049];

void update() {
	for (long i = 0; i < l; i++) xh[i] = 1;
	for (long i = 1; i <= n; i++)
	  if (x[i] == 0){
	  	xh[a[i]] = 0;
	  	xh[b[i]] = 0;
	  }
	r++;
	rs[r] = "";
	for (long i = 0; i < l; i++) if (xh[i]) rs[r] += S[i];
}

void Try(long i)
{
	for (long j = 0; j <= 1; j++){
		x[i] = j;
		if (i == n) update();
		else Try(i + 1);
	}
}
int main()
{
	cin >> S;
	n = t = 0;
	l = S.length();
	for (ll i = 0; i < l; i++){
		if (S[i] == '('){
		 	t++;
		  	st[t] = i;
		} else {
			if (S[i] == ')'){
	  			n++;
	 		    a[n] = st[t];
			    b[n] = i;
			 	t--;
		    }	
		}	
	}
	Try(1);
	r--;
	sort(rs + 1, rs + 1 + r);
	rs[0] = "*";
	for (long i = 1; i <= r; i++) {
		if (rs[i] != rs[i - 1]) cout << rs[i] << endl;
	}
	return 0;
}
