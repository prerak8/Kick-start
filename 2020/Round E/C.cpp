#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < (int)v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
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
const int inf = (int)10e17;
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
    int n;
    cin>>n;
    node a[n+1];
    int ftot = 0;
    fpi(1,n,1)
    {
        cin>>a[i].e>>a[i].r;
        a[i].tot = a[i].e + a[i].r;
        ftot+=a[i].e;
    }
    int ans1 = 0,ans2 = ftot,extra = 0,ctotal = ftot,removed = 0;
    priority_queue<pair<int,int>> pq;
    fpi(1,n,1)
    {
        if(a[i].tot<=ctotal)
        {
            extra+=a[i].e;
            pq.push({a[i].tot,a[i].e});
        }
        else
        {
            removed++;
            extra-=a[i].e;
            ctotal-=a[i].e;
            while(!pq.empty() && pq.top().F>ctotal)
            {
                ctotal-=pq.top().S;
                extra-=2*pq.top().S;
                pq.pop();
                removed++;
            }
        }
        if(ftot+extra>ans2)
        {
            ans2 = ftot + extra;
            ans1 = removed;
        }
    }
    sort(a+1,a+n+1,cc);
    fni(n,1,1)
    {
        if(a[i].tot<=ftot)
        {
            d(n-i<<" INDEFINITELY")
            return ;
        }
        ftot-=a[i].e;
    }
    d(ans1<<" "<<ans2)
}   

int32_t main()
{
    IOS;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout); 
    // #endif
    cout<<setprecision(12);
    int t=1;
    cin>>t;
    for(int i = 1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    // #ifndef LOCAL_DEFINE
    // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
}