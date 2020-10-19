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
int mod = (int)(1e9 + 7);
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
//#define f(i,n) for(int i=1;i<=n;i++)
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
// vector<int> edge[maxn];
// void ipgraph(int n,int m) {
//     fp(i,1,n) edge[i].clear();
//     if(m==0) return;
//    fp(i,1,m) {
//        int a,b;
//        cin>>a>>b;
//        edge[a].pb(b);
//        edge[b].pb(a);
//    } 
// }
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
//////////////////////////////////////////////////////////////////////////////////
// l,r -> [1,n]
int pre[maxn];
int a[maxn];
int sz;
int w,n;
int getSum(int lo,int up,int val)
{   
    int l = lower_bound(a+1,a+2*w+1,lo)-a;
    int r = upper_bound(a+1,a+2*w+1,up)-a;
    r--;
    sz = r - l + 1;
    return pre[r] - pre[l-1] - sz*(val); 
}
int get(int val)
{
    int next = val + n/2;
    int ans = 0;
    ans+=getSum(val,next,val);
    ans+=n*(w-sz);
    ans-=getSum(next+1,val+n-1,val);
    return ans;
}
void solve()
{
    cin>>w>>n;
    fp(i,1,w) cin>>a[i];
    sort(a+1,a+w+1);
    fp(i,w+1,2*w) a[i] = a[i-w] + n;
    pre[0] = 0;
    fp(i,1,2*w) {pre[i] = pre[i-1] ;pre[i]+=a[i];}
    int ans = inf;
    fp(i,1,w)
    {
        ans = min(ans,get(a[i]));
    }
    d(ans)
}
int32_t main()
{
   IOS;     
   
    std::cout << std::setprecision(20);
   int t=1;
    cin>>t;
   fp(i,1,t)
   {
       cout<<"Case #"<<i<<": ";
       solve();
   }
}