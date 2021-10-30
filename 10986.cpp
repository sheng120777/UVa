#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inf 1e9
#define maxn 100005

vector<pair<int,int>>graph[maxn];
int dis[maxn];
bool gone[maxn]={false};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        for(int i=0;i<maxn;i++){
            graph[i].clear();
        }
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        for(int i=0;i<m;i++){
            int a,b,w;
            cin>>a>>b>>w;
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
        memset(dis,0x3f,sizeof(dis));
        memset(gone,false,sizeof(gone));
        dis[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            auto now=pq.top();
            pq.pop();
            int v=now.second;
            if(gone[v]){
                continue;
            }
            gone[v]=true;
            for(auto next:graph[v]){
                int u=next.first;
                int k=next.second;
                if(dis[u]>dis[v]+k){
                    dis[u]=dis[v]+k;
                    pq.push({dis[u],u});
                }
            }
        }
        cout<<"Case #"<<i<<": ";
        if(dis[t]==0x3f3f3f3f3f3f3f3f){
            cout<<"unreachable"<<endl;
        }
        else{
            cout<<dis[t]<<endl;
        }
    }
}
