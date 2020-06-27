#include <bits/stdc++.h>
using namespace std;

int L[10] = {3,0,2,7,4,1,6,8,5,9}, // xoay trai theo chieu kim dong ho
    R[10] = {0,4,1,3,8,5,2,7,9,6}, // xoay phai theo chieu kim dong ho
    RD[10] = {0,2,6,3,1,5,9,7,4,8},// xoay trai nguoc chieu kim dong ho
    LD[10] = {1,5,2,0,4,8,6,3,7,9};// xoay phai nguoc chieu kim dong ho
string BD = "",			  // trang thai dau vao
	   CS = "1238004765"; // trang thai chuan
string luffy,X,tmp;

void Input(){
	char tmp;
	for (int i = 1 ; i <= 10 ; i++){
		cin >> tmp;
		BD = BD + tmp;
	} 
}

string xoay (string A, int B[]){
	tmp = "";
	for (int i = 0 ; i <= 9 ; i++){
		tmp = tmp + A[B[i]];
	}
	return tmp;
}

int BFS (){
	if (BD == CS) return 0;
	queue <string> Q;
	unordered_map <string, pair<int,int>> U;
	U[BD] = {0,1}; // 0 hay U[BD].first la so buoc bien doi | 1 la dau hieu de quay theo chieu kim dong ho
	U[CS] = {0,2}; // 0 la so buoc bien doi | 2 la dau hieu quay nguoc kim dong ho
	Q.push(BD); Q.push(CS);
	while (!Q.empty()){
		luffy = Q.front(); Q.pop();
		if (U[luffy].second == 1){
			X = xoay(luffy,L);
			if (U[X].second == 2) return U[luffy].first + 1 + U[X].first; // xoay nguoc va xuoi gap nhau
			if (U[X].second == 0){ // day la node moi
				Q.push(X);
				U[X].first = U[luffy].first + 1; 	
				U[X].second = 1;
			}
			X = xoay(luffy,R);
			if (U[X].second == 2) return U[luffy].first + 1 + U[X].first; // xoay nguoc va xuoi gap nhau
			if (U[X].second == 0){ // node moi
				Q.push(X);
				U[X].first = U[luffy].first + 1;	
				U[X].second = 1;		
			}			
		} else {// luffy.first.second == 2
			X = xoay(luffy,LD);
			if (U[X].second == 1) return U[luffy].first + 1 + U[X].first; // xoay nguoc va xuoi gap nhau
			if (U[X].second == 0){ // node moi
				Q.push(X);
				U[X].first = U[luffy].first + 1; 	
				U[X].second = 2;;
			}
			if (U[X].second == 1) return U[luffy].first + 1 + U[X].first; // xoay nguoc va xuoi gap nhau
			X = xoay(luffy,RD);
			if (U[X].second == 0){
				Q.push(X);
				U[X].first = U[luffy].first + 1;	
				U[X].second = 2;		
			}	
		}
	}
}

int main (){
	Input();
	cout << BFS();
	return 0;
}
