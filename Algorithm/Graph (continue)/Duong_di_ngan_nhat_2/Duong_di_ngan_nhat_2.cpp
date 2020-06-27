#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define oo 1000000000000
#define ii pair<ll, ll>
using namespace std;

ll N,M,u,v,c;
bool dachon[100005];
ll DP[100005]; // D[v] la so duong di ngan nhat tu 1 toi v
unordered_map<ll, vector<ii>> Box;

void Input(){
	memset(dachon,false,sizeof(dachon)); // tat ca cac dinh deu chua duoc co dinh
	cin >> N >> M; // N dinh M canh
	for (ll i = 1 ; i <= N ; i++) DP[i] = 1;
	for (ll i = 1 ; i <= M ; i++){
		cin >> u >> v >> c;
		Box[u].push_back({v,c}); // canh uv co gia tri c
		Box[v].push_back({u,c});	
	}
}

void Dijkstra(){
	ll dinh[N+1]; // dinh[i] luu do dai duong di ngan nhat tu 1 den i
	for (ll i = 1 ; i <= N ; i++) dinh[i] = oo;
	dinh[1] = 0; // khoang cach tu dinh 1 den chinh no = 0;
	priority_queue <ii, vector<ii>, greater<ii>> PQ; // de luu dinh va do dai duong di ngan nhat toi no
	PQ.push({0,1}); // {c,v} v la ten dinh va c la do dai duong di ngan nhat tu dinh 1 den dinh v
	while (!PQ.empty()){
		ii key = PQ.top(); PQ.pop();
		if (dachon[key.second] == true) continue; // neu da duoc co dinh thi bo qua
		dachon[key.second] = true;
	//	cout << "Dinh cha = " << key.second << endl;
		// cap nhat chi phi toi cac dinh ke
		for (ll i = 0 ; i < Box[key.second].size() ; i++){
	//		cout << "Size = " << Box[key.second].size() << endl; 
			ll Vke = Box[key.second][i].first;
	//		cout << "dinh con = " << Vke << endl;
			if (dinh[Vke] > dinh[key.second] + Box[key.second][i].second) {
				dinh[Vke] = dinh[key.second] + Box[key.second][i].second;
				PQ.push({dinh[Vke],Vke}); // cap nhat do dai duong di ngan nhat tu dinh 1 toi dinh Vke
				DP[Vke] = DP[key.second]; // so duong di ngan nhat tu 1 den Vke = so duong di ngan nhat tu 1 toi key.first (dinh lien truoc cua Vke tren duong di ngan nhat)
			} else if (dinh[Vke] == dinh[key.second] + Box[key.second][i].second) {
	//			cout << "dinh[" << Vke << "] = " << dinh[Vke] << endl;
				DP[Vke] += DP[key.second];
	//			cout << "DP[" << Vke << "] = " << DP[Vke] << endl;
				// so luong duong di ngan nhat tu 1 den Vke = so luong duong di ngan nhat tu 1 den Vke cu + so duong di tu 1 cho den key.first (dinh lien truoc Vke tren duong di)
			}
		}
	}
	cout << dinh[N] << " " << DP[N];
}

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Input();
	Dijkstra();
	return 0;
}

