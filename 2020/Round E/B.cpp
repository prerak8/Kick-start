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
void solve()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n==1)
    {
        if(a==1 && b==1 && 1==c)
        {
            d(1)
        } 
        else
        {
            d("IMPOSSIBLE")
        }
    }
    else if(n==2)
    {
        a-=c;
        b-=c;
        if(a+b+c==n)
        {
            fpi(1,a,1) cout<<1<<" ";
            fpi(1,c,1) cout<<2<<" ";
            fpi(1,b,1) cout<<1<<" ";
            br;
        }
        else
        {
            d("IMPOSSIBLE")
        }
    }
    else
    {
        a-=c;
        b-=c;
        if(a+b+c<=n)
        {
            if(b!=0)
            {
                int extra = n - (a+b+c);
                fpi(1,a,1) cout<<2<<" ";
                fpi(1,c,1) cout<<3<<" ";
                fpi(1,extra,1) cout<<1<<" ";
                fpi(1,b,1) cout<<2<<" ";
                br;
            }
            else if(a!=0)
            {
                int extra = n - (a+b+c);
                fpi(1,a,1) cout<<2<<" ";
                fpi(1,extra,1) cout<<1<<" ";
                fpi(1,c,1) cout<<3<<" ";
                fpi(1,b,1) cout<<2<<" ";
                br;
            }
            else if(c>=2)
            {
                int extra = n - (a+b+c);
                cout<<3<<" ";
                fpi(1,extra,1) cout<<1<<" ";
                fpi(1,c-1,1) cout<<3<<" ";
                br;
            }
            else
            {
                d("IMPOSSIBLE")
            }
        }
        else
        {
            d("IMPOSSIBLE")
        }
    }
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