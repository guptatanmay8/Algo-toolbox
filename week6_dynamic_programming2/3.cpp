#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define sz(a) (int)(a.size())
#define pb push_back
#define all(c) c.begin(),c.end()
#define tr(it,a,c) for(auto it=c.begin()+a;it!=c.end();it++)
#define fr(i,a,n)   for(int i=a;i<n;i++)
#define present(c,x) (c.find(x)!=c.end()) //for set/map etc.
#define cpresent(c,x) (find(all(c),x)!=c.end())
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vp;
int N=100001;
int mod=1e9+7;


int min(int a,int b){if(a<b) return a; else return b;}
int max(int a,int b){if(a>b) return a; else return b;}
int power(int a,int b){int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int p, int q){if(p%q==0) return q; else{return gcd(q,p%q);}} 
bool comp(int a, int b) 
{ 
    return (a > b); 
}

bool comp1(pi a, pi b)
{
    if(a.first==b.first)return a.second<b.second;
    else return a.first>b.first;
}

template<typename T> 
istream& operator>>(istream& in, vector<T>& v)
{
    for (T& x : v) in >> x; return in;
}

template<typename T> 
ostream& operator<<(ostream& out, vector<T>& v)
{
    for (T& x : v) out << x<<" "; return out;
}

// template<typename T>
int sum1(vector<int>& v)
{
    int sum=0;
    // for(auto x: v)sum+=x;
    fr(i,0,v.size())sum+=v[i];
    return sum;
}





 void solve()
{
	string str;
    cin>>str;
    stringstream ss(str);
    char ch;
    vi v;
    // v.pb(0);
    int f=0;
    vector<char> op;
    while(ss>>ch)
    {
        if(f==0)
        {
            v.pb(ch-'0');
            f=1;
        }
        else
        {
            op.pb(ch);
            f=0;
        }
    }
    int n=v.size();
    // cout<<v;
    // fr(i,0,op.size())cout<<op[i]<<" ";
    vvi M(n+1,vi(n+1,0));
    vvi m(n+1,vi(n+1,0));
    fr(j,1,n+1)
    {
        M[j][j]= v[j-1];
        m[j][j]= v[j-1];
    }
    // fr(i,0,n+1)
    // {
    //     fr(j,0,n+1)
    //     {
    //         cout<<M[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    fr(s,1,n)
    {
        fr(i,1,n-s+1)
        {
            int j=i+s;
            int m1=-1e9,m2=1e9;
            fr(k,i,j)
            {
                int a = M[i][k];
                int b = m[i][k];
                int c= M[k+1][j];
                int d= m[k+1][j];
                // cout<<a<<b<<c<<d;
                char c1=op[k-1];
                if(c1=='+')
                {
                    // v.pb(a+c);
                    // v.pb(a+d);
                    // v.pb(b+c);
                    // v.pb(b+d);
                    m1= max(m1,a+c);
                    m2 = min(m2,b+d);
                }
                else if(c1=='-')
                {
                    m1= max(m1,a-d);
                    m2= min(m2,b-c);

                }
                else if(c1=='*')
                {
                    m1=max(m1,a*c);
                    m1=max(m1,a*d);
                    m1=max(m1,b*d);
                    m1=max(m1,b*c);
                    m2=min(m2,a*c);
                    m2=min(m2,b*c);
                    m2=min(m2,a*d);
                    m2=min(m2,b*d);
                }

            }
            M[i][j]=m1;
            m[i][j]=m2;
            

        }
        
    }
    cout<<M[1][n];


}

signed main()
{
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    // int t;
    // cin>>t;
    // while(t--)
    // {
    //     solve();
    //     cout<<endl;
    // }
    solve();
    return 0;   
}   