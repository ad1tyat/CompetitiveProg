#include <bits/stdc++.h>
using namespace std;

//From Handbook: https://cses.fi/book.pdf
/********************************************************************/
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPR(i,a,b) for(ll i=b-1;i>=a;i--)
#define forr(i,n) for(ll i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define DB pop_back
#define mp make_pair
#define MT make_tuple
#define V(a) vector<a>
#define vi vector<ll>
#define endl '\n'
#define ce(ele) cout<<ele<<' '
#define cs(ele) cout<<ele<<'\n'
#define CASE(t) ll t; cin>>t; while(t--)
/********************************************************************/
const double pi = 3.1415926535;
const int max = 1e3 + 5;


//dfs
vector<ll>  adj[max];
bool visited[max];


//bfs
queue<int> q;
//bool visited[N];
ll distance[N];
/********************************************************************/
//FAST IO//
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int s) {
	if (visited[s])
		return;
	//process node s
	//CODE HERE:




	for (auto u : adj[s])
		dfs(u);
}
void bfs() {
	visited[x] = true;
	distance[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		// process node s
		//CODE HERE:




		for (auto u : adj[s]) {
			if (visited[u]) continue;
			visited[u] = true;
			distance[u] = distance[s] + 1;
			q.push(u);
		}
	}
}

ll bellman_ford(ll src, ll dest) {
	//O(Edges*Vertices)
	//WORST: O(n^3) //complete graph
	//Average : O(n^2)
	//cant be used if negative cycle is their
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[src] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a] + w);
		}
	}
	return distance[dest];
	//distance[destination] gives distance between node src and destination
}
ll dijkstra(ll src, ll dest) {
	//O(Vertices^2)
	//Worst Case: O(N^2);
	//Cant be used if negative weights are their
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[src] = 0;
	q.push({0, src});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				q.push({ -distance[b], b});
			}
		}
	}
	return distance[dest];
	//distance[destination] gives distance between node src and destination

}

void floyd_warshall() {
	//Complexity O(n^3)
	//But all distances from any source to any dest are found
	//NEED ADJACENCY MATRIX
	//Initialization
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) distance[i][j] = 0;
			else if (adj[i][j]) distance[i][j] = adj[i][j];
			else distance[i][j] = INF;
		}
	}
	//Algo
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				distance[i][j] = min(distance[i][j],
				                     distance[i][k] + distance[k][j]);
			}
		}
	}

}
/********************************************************************/
int main() {
	FAST();

	return 0;
}
