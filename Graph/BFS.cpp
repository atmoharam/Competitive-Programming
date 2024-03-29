#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IO {ios::sync_with_stdio(0); cin.tie(0);};
const ll template_array_size = 1e6 + 4265;
vector<ll> Graph[template_array_size];
bool visited[template_array_size];
ll distancee[template_array_size];
ll parent[template_array_size];
ll n , m , u ,v  , s;

void printPath(ll node){
    if(parent[node] == -1){
        cout << node << ' ';
        return;
    }
    printPath(parent[node]);
    cout << node << ' ';
}
signed main() {
    IO

    cin >> n >> m >> s;
    while (m--){
        cin >> u >> v ;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    queue<ll> q ;
    q.push(1);
    visited[1] = true;
    parent[1] = - 1 ;

    while (! q.empty()){
        ll node = q.front();
        q.pop() ;
        for(ll child : Graph[node]){
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
                distancee[child] = distancee[node] + 1 ;
                parent[child] = node ;
            }
        }
    }
    cout << distancee[s]<<'\n';
    printPath(s);

    return 0 ;
}
