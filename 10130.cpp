#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inf 1e12

int cost[1005];
int weight[1005];
int dp[1005];

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>cost[i]>>weight[i]; 
        }
        int m;
        cin>>m;
        int cnt=0;
        while(m--){
            int v;
            cin>>v;
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++){
                for(int j=v;j>0;j--){
                    if(j-weight[i]>=0){
                        dp[j]=max(dp[j],dp[j-weight[i]]+cost[i]);
                    }
                }
            }
            cnt+=dp[v];
        }
        cout<<cnt<<endl;
    }
}
