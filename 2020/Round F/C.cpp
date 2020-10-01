#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
#define br cout<<endl
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define d(x) cout<<x<<endl;
#define de(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000000000;
#define maxn 1000005
#define mod (int)(1e9+7)
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define f(i,n) for(int i=1;i<=n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i+=1)
#define fn(i,k,n) for(int i=k;i>=n;i-=1)
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<endl;}
int modexp(int x,int y) {
   int res = 1;
   x = x % mod;
   while (y > 0){
       if (y & 1LL)
           res = (res*x) % mod;
       y = y>>1;
       x = (x*x) % mod;  
   }
   return res;
}
int invmod(int a) {
    return modexp(a,mod-2);
}
vector<int> edge[maxn];
void ipgraph(int n,int m) {
    fp(i,1,n) edge[i].clear();
    if(m==0) return;
   fp(i,1,m) {
       int a,b;
       cin>>a>>b;
       edge[a].pb(b);
       edge[b].pb(a);
   } 
}
/*
void dfs(int node,int p)
{
    for(int u : edge[node]) 
    {
        if(u!=p)
        {
            dfs(u,node);
        }
    }
}
*/
///////////////////////////////////////////////////////////////////////////////////
int cantMove;int vis[37];
int ans,cntA,cntB,moveA,moveB;
//turn 
int minMax(int a,int b,int turn)
{
    int tans = - inf;
    if(turn==1) tans = inf;
    //d(a<<" "<<b<<" "<<turn<<" "<<cntA<<" "<<cntB)
    if(turn==0)
    {
        int flag = 0;
        for(int u : edge[a])
        {
            if(vis[u]==0 && u!=b)
            {
                flag = 1;
                cntA++;
                vis[u] = 1;
                tans = max(minMax(u,b,1),tans);
                vis[u] = 0;
                cntA--;
            }
        }
        if(flag==0)
        {
            moveA++;
            if(moveA && moveB)
            {
                tans = (cntA-cntB);
            }
            else tans = minMax(a,b,1);
            moveA--;
        }
    }
    else
    {
        int flag = 0;
        for(int u : edge[b])
        {
            if(vis[u]==0 && u!=a)
            {
                flag = 1;
                cntB++;
                vis[u] = 1;
                tans = min(tans,minMax(a,u,0));
                vis[u] = 0;
                cntB--;
            }
        }
        if(flag==0)
        {
            moveB++;
            if(moveA && moveB)
            {
                //d(a<<" ok "<<b<<" "<<turn<<" "<<cntA<<" "<<cntB)
                tans = (cntA-cntB);
            }
            else tans = minMax(a,b,0);
            moveB--;
        }
    }
    return tans;
}
void solve()
{
    int s,a,b,c,d,C;
    cin>>s>>a>>b>>c>>d>>C;
    int od = 1;
    fp(i,1,36){ edge[i].clear();vis[i] = 0;}
    ans = -inf;cntA = 1;cntB = 1;cantMove = 0;
    moveA = 0;
    moveB = 0;
    fp(i,1,s)
    {
        int pre = (i-1)*(i-1) + 1;
        int now = i*i;
        fp(j,pre+1,now)
        {
            edge[j].pb(j-1);
            edge[j-1].pb(j);
        }
        fp(j,1,od)
        {
            if(j&1 && i!=s)
            {
                edge[pre+j-1].pb(i*i+j+1);
                edge[i*i+j+1].pb(pre+j-1);
            }
        }
        od+=2;
    }
    fp(i,1,C)
    {
        int a,b;
        cin>>a>>b;
        vis[(a-1)*(a-1) + b] = 1;
    }
    vis[(a-1)*(a-1) + b] = 1;
    vis[(c-1)*(c-1) + d] = 1;
    // fp(i,1,9)
    // {
    //     d("noe "<<i)
    //     pv(edge[i]);
    // }
    d(minMax((a-1)*(a-1) + b,(c-1)*(c-1) + d,0))
}
int32_t main()
{
   IOS;
   
   int t=1;
    cin>>t;
   fp(i,1,t)
   {
       cout<<"Case #"<<i<<": ";
       solve();
   }
}