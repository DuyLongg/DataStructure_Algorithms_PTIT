#include <bits/stdc++.h>
using namespace std;

int t,nums,diff,size_str;
string S,T,tmp;
string A[100000];
unordered_map <string, vector <string>> DSK; // luu danh sach ke
unordered_map <string, pair<int,int>> info; // info.first luu so do dai | info.second == 1 tuc la duyet xuoi | == 2 la duyet nguoc

void Creat(){
	for (int i = 1 ; i <= nums ; i++){
		for (int j = 0 ; j < size_str ; j++){
			string hop = A[i].substr(0,j) + '*' + A[i].substr(j+1,size_str);
			DSK[hop].push_back(A[i]);
		}
	}
}

int BFS (){
	// tao danh sach ke
	Creat();
	queue <string> Q;
	Q.push(S); Q.push(T);
	info[S].second = 1; // duyet xuoi
 	info[S].first  = 1; // do dai = 1
 	info[T].second = 2; // duyet nguoc
 	info[T].first  = 1; // do dai = 1
	while (!Q.empty()){
		tmp = Q.front(); Q.pop();
		if (info[tmp].second == 1){// duyet xuoi
			for (int i = 0 ; i < size_str ; i++){
				string hop = tmp.substr(0,i) + '*' + tmp.substr(i+1,size_str);
				for (int j = 0 ; j < DSK[hop].size() ; j++){
					if (info[DSK[hop][j]].second == 2) return info[tmp].first + info[DSK[hop][j]].first;
					if (info[DSK[hop][j]].second == 0){
						info[DSK[hop][j]].second = 1;
						info[DSK[hop][j]].first = info[tmp].first + 1;
						Q.push(DSK[hop][j]);					
					}
				}
			}
		} else { // info[tmp].second == 2 => duyet nguoc
			for (int i = 0 ; i < size_str ; i++){
				string hop = tmp.substr(0,i) + '*' + tmp.substr(i+1,size_str);
				for (int j = 0 ; j < DSK[hop].size() ; j++){
					if (info[DSK[hop][j]].second == 1) return info[tmp].first + info[DSK[hop][j]].first;
					if (info[DSK[hop][j]].second == 0){
						info[DSK[hop][j]].second = 2;
						info[DSK[hop][j]].first = info[tmp].first + 1;
						Q.push(DSK[hop][j]);
					}
				}
			}			
		}
	}
	return 0;
}

int main (){
	cin >> t;
	while (t--){
		DSK.clear(); info.clear();
		cin >> nums >> S >> T;
		bool coS = false; bool coT = false;
		for (int i = 1 ; i <= nums ; i++) {
			cin >> A[i];
			if (A[i] == S) coS = true;
			if (A[i] == T) coT = true;
		}
		size_str = A[1].size();
		if (coS == true && coT == true) cout << BFS() << endl;
		else cout << 0 << endl;
	}
	return 0;
}
