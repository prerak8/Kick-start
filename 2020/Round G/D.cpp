#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
#define br cout<<endl
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define d(x) cout<<x<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000000000;
#define maxn 1000005
#define mod 998244353
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define f(i,n) for(int i=1;i<=n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i+=1)
#define fn(i,k,n) for(int i=k;i>=n;i-=1)
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<endl;}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
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
long double fdp[5005][5005];
void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    fp(i,1,n) cin>>a[i];
    if(n==2)
    {
        d(a[1]+a[2])
        return;
    }
    long double pre[n+1];
    pre[0] = 0;
    fp(i,1,n) {pre[i] = pre[i-1]; pre[i]+=a[i];}
    long double dp[n+1];
    dp[1] = 1;
    dp[2] = 1;
    fp(i,3,n)
    {
        dp[i] = 0;
        fp(j,1,i-1) dp[i]+=dp[j]*dp[i-j];
    }
    fp(i,1,n) fp(j,1,n) fdp[i][j] = 0;
    unordered_map<int,double> m;
    fp(i,1,n)
    {
        fdp[i][i] = 0;
        if(i>=2) fdp[i-1][i] = a[i-1] + a[i];
        long double suf = fdp[i-1][i];
        fn(j,i-2,1)
        {
            fdp[j][i] = (pre[i] - pre[j-1]);
            // d(i<<" "<<j)
            // d(fdp[j][i]<<" "<<(pre[i] - pre[j-1])<<" "<<dp[i-j+1])
            // fp(k,j,i-1)
            // {
            //     // d(j<<" "<<k<<" "<<fdp[j][k])
            //     // d(k+1<<" "<<i<<" "<<fdp[k+1][i])
            //     fdp[j][i]+=(fdp[j][k] + fdp[k+1][i])*(1.0/(i-j));
            // }
            fdp[j][i]+=(m[j] + suf)*(1.0/(i-j));
            suf+=fdp[j][i];
            // d("final")
            // d(j<<" "<<i<<" "<<fdp[j][i])
        }
        fn(j,i-1,1)
        {
            m[j]+=fdp[j][i];
        }
    }
    // fp(i,1,n)
    // {
    //     fp(j,1,i) d(j<<" "<<i<<" "<<fdp[j][i])
    // }
    d(fdp[1][n])
}
int32_t main()
{
   IOS;
//   #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin); 
//     freopen("output.txt", "w", stdout); 
//     #endif
   int t=1;
    cin>>t;
    cout << std::setprecision(20);
   fp(i,1,t)
   {
       cout<<"Case #"<<i<<": ";
       solve();
   }
   #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
