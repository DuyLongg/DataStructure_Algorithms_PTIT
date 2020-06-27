#include <bits/stdc++.h>
using namespace std;
 
int main (){
	string S;
	int val;
	vector <int> A;
	while (cin >> S){
		if (S == "push"){
			cin >> val;
			A.push_back(val);
		} else if (S == "pop" && A.size() > 0){
			A.pop_back();
		} else {
			if (A.size() == 0) cout << "empty";
			for (int i = 0 ; i < A.size() ; i++)
				cout << A[i] << " ";
			cout << endl;
		}
	}
	return 0;
}
