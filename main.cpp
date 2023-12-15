#include <bits/stdc++.h>
using namespace std;
int n,m;

struct droga{
    int gdzie;
    int dlugosc;
};
vector<vector<droga>> g;
vector<bool> odw;
vector<int> dj;
priority_queue<pair<int,int>> pq;
void odwiedz(int v) {
    odw[v]=1;
    for(int d=0;d<g[v].size();d++) {
        if(dj[g[v][d].gdzie]>dj[v]+g[v][d].dlugosc) {
            dj[g[v][d].gdzie]=dj[v]+g[v][d].dlugosc;
            pq.push({dj[g[v][d].gdzie],g[v][d].gdzie});
        }
    }
}
vector<int> djkikstra(int start) {
    vector<bool> odwp(n+7,0);
    odw=odwp;
    vector<int> djp(n+7,INFINITY);
    dj=djp;
    priority_queue<pair<int,int>> pqp;
    pq=pqp;
    dj[start]=0;
    pq.push({start,0});
    while(!pq.empty()) {
        auto x=pq.top();
        pq.pop();
        if(!odw[x.second]) {
            odwiedz(x.second);
        }
    }
    return dj;
}

int main() {
    cin>>n>>m;
    vector<droga> gp;
    vector<vector<droga>> gpp(n+7, gp);
    g=gpp;
    for(int d=0;d<m;d++) {
        droga x;
        int a,b,w;
        cin>>a>>b>>w;
        x.gdzie=b;
        x.dlugosc=w;
        gpp[a].push_back(x);
    }
    vector<int> wyn=djkikstra(1);
    for(auto x : wyn) {
        cout << x << " ";
    }
}
