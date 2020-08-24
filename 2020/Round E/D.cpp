#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < (int)v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
const int inf = (int)10e17;
#define mem(a,b) memset(a,b,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define br cout<<'\n'
#define de(x) cout << (#x) << " : " << (x) << end1l;
#define fni(x,y,z) for(int i=(int)x;i>=(int)y;i-=(int)z)
#define fnj(x,y,z) for(int j=(int)x;j>=(int)y;j-=(int)z)
#define fpi(x,y,z) for(int i=(int)x;i<=(int)y;i+=(int)z)  
#define fpj(x,y,z) for(int j=(int)x;j<=(int)y;j+=(int)z)
#define fpk(x,y,z) for(int k=(int)x;k<=(int)y;k+=(int)z)  
#define fnk(x,y,z) for(int k=(int)x;k>=(int)y;k-=(int)z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end1())
#define maxn 1000005
const int mod = 1000000007; 
int modexp(int x,int y) 
{ 
    int res = 1;
    x = x % mod; 
    if (x == 0) return 0;
    while (y > 0) 
    {
        if (y & 1LL) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
}
int invmod(int n)
{
    return modexp(n,mod-2);
}
struct node
{
    int r,e,tot;
};
bool cc(node a,node b)
{
    return a.tot<b.tot;
}
void solve()
{
    int n,m,s,r;
    cin>>n>>m>>s>>r;
    int dist[n+1][n+1],dp[n+1][s+1];
    fpi(1,n,1) fpj(1,n,1) dist[i][j] = inf;
    fpi(1,n,1) dist[i][i] = 0;
    fpi(1,n,1) fpj(1,s,1) dp[i][j] = inf;
    fpi(1,m,1)
    {
        int a,b;
        cin>>a>>b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    fpi(1,n,1)
    {
        int a,b;
        cin>>a;
        fpj(1,a,1)
        {
            cin>>b;
            dp[i][b] = 0;
        }
    }
    std::vector<int> v[r+1];int product[r+1];
    fpi(1,r,1)
    {
        int a;
        cin>>a;
        fpj(1,a,1)
        {
            int b;
            cin>>b;
            v[i].pb(b);
        }
        cin>>product[i];
    }
    fpi(1,n,1)
    {
        fpj(1,n,1)
        {
            fpk(1,n,1)
            {
                dist[j][k] = min(dist[j][i]+dist[i][k],dist[j][k]);
            }
        }
    }
    // br;
    // fpi(1,n,1)
    // {
    //     fpj(1,n,1) cout<<dist[i][j]<<" ";
    //     cout<<endl;
    // }
    fpi(1,n+1,1)
    {
        fpj(1,n,1)
        {
            fpk(1,r,1)
            {
                for(int w = 1;w<=r;w++)
                {
                    int ans = 0;
                    for(int ing : v[w])
                    {
                        ans+=dp[j][ing];
                    }
                    dp[j][product[w]] = min(dp[j][product[w]],ans);
                }
            }
            fpk(1,n,1)
            {
                for(int w=1;w<=s;w++)
                {
                    dp[k][w] = min(dp[j][w] + dist[j][k],dp[k][w]);
                }
            }
        }
    }
    int ans = inf;
    fpi(1,n,1) ans = min(ans,dp[i][1]);
    if(ans<(int)1e12) d(ans)
    else d(-1)
}   
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    cout<<setprecision(12);
    int t=1;
    cin>>t;
    for(int i = 1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}