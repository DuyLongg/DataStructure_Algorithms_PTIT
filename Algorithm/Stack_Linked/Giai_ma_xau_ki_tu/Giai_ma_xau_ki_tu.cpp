#include <bits/stdc++.h>
using namespace std;

int T;
string S;

string giai_ma (string S){
	stack <int> so;
	stack <char> kitu;
	string tmp,ans;
	tmp = ans = "";
	int N = S.length();
	for (int i = 0 ; i < N ; i++){
		int heso = 0;
		if (S[i] >= '0' && S[i] <= '9'){
			while (S[i] >= '0' && S[i] <= '9'){
				heso = heso * 10 + S[i] - '0';
				i++;
			}
			i--;
			so.push(heso);
		} else if (S[i] == ']'){
			tmp = ""; heso = 0;
			if (!so.empty()){
				heso = so.top(); so.pop();
			} 
			while (!kitu.empty() && kitu.top() != '['){
				tmp = kitu.top() + tmp; kitu.pop();
			}
			kitu.pop();
			for (int i = 0 ; i < heso ; i++) ans = ans + tmp;
			for (int i = 0 ; i < ans.length() ; i++) kitu.push(ans[i]);
			ans = "";
		} else if (S[i] == '['){
			if (i == 0 || (S[i-1] < '0' || S[i-1] > '9')) {
				so.push(1);
				kitu.push(S[i]);
			} else kitu.push(S[i]);
		} else kitu.push(S[i]);
	}
	while (!kitu.empty()){
		ans = kitu.top() + ans; kitu.pop(); 
	}
	return ans;
}

int main (){
	cin >> T;
	while (T--){
		cin >> S;
		cout << giai_ma(S) << endl;
	}
	return 0;
}
