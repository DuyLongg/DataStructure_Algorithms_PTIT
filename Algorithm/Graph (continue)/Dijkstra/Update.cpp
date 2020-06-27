#include <bits/stdc++.h>
#define ll long long
#define oo 100000000
#define ii pair<ll, ll>
using namespace std;

ll T,N,M,u,v,c,s;
bool dachon[100005];
ll DP[100005]; // D[v] la so duong di ngan nhat tu 1 toi v
unordered_map<ll, vector<ii>> Box;

bool ktra (int u, int v, int c){
	for (int i = 0 ; i < Box[u].size() ; i++){
		if (Box[u][i].first == v){
			if (Box[u][i].second < c) {
				Box[u][i].second = c;
				for (int j = 0 ; j < Box[i].size() ; j++){
					if (Box[i][j].first == u){
						Box[i][j].second = c;
					}
				}
			}
			return true;
		} 
	}
	return false;
}

void Input(){
	memset(dachon,false,sizeof(dachon)); // tat ca cac dinh deu chua duoc co dinh
	cin >> N >> M >> s; // N dinh M canh
	for (int i = 1 ; i <= N ; i++) DP[i] = 1;
	for (int i = 1 ; i <= M ; i++){
		cin >> u >> v >> c;
		if (ktra(u,v,c)) continue;
		Box[u].push_back({v,c}); // canh uv co gia tri c
		Box[v].push_back({u,c});
	}
}

bool operator > (const ii &A, const ii &B){
	return A.second > B.second;
}

void Dijkstra(){
	ll dinh[N+1]; // dinh[i] luu do dai duong di ngan nhat tu 1 den i
	for (int i = 1 ; i <= N ; i++) dinh[i] = oo;
	dinh[s] = 0; // khoang cach tu dinh 1 den chinh no = 0;
	priority_queue <ii, vector<ii>, greater<ii>> PQ; // de luu dinh va do dai duong di ngan nhat toi no
	PQ.push({s,0}); // {v,c} v la ten dinh va c la do dai duong di ngan nhat tu dinh 1 den dinh dinh c
	while (!PQ.empty()){
		ii key = PQ.top(); PQ.pop();
		if (dachon[key.first] == true) continue; // neu da duoc co dinh thi bo qua
		dachon[key.first] = true;
		// cap nhat chi phi toi cac dinh ke
		for (int i = 0 ; i < Box[key.first].size() ; i++){
			int Vke = Box[key.first][i].first;
			if (dinh[Vke] > dinh[key.first] + Box[key.first][i].second) {
				dinh[Vke] = dinh[key.first] + Box[key.first][i].second;
				PQ.push({Vke, dinh[Vke]}); // cap nhat do dai duong di ngan nhat tu dinh 1 toi dinh Vke
			}
		}
	}
	for (int i = 1 ; i <= N ; i++) cout << dinh[i] << " ";
	cout << endl;
}

int main (){
	cin >> T;
	while (T--){
		Box.clear();
		Input();
		Dijkstra();	
	}
	return 0;
}

