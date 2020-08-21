#include<bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int a[100001];
bool place(int a[],int n,int c,int min_sep){
    int last_cow=a[0];
    int cnt(1);
    for(int i=1;i<n;i++){
        if(a[i]-last_cow>=min_sep){
            last_cow=a[i];
            cnt++;
            if(cnt==c)return true;
        }
    }
    return false;  
}
int Ans(int n,int c){
    int s=0;
    int e=a[n-1]-a[0];
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        bool cows=place(a,n,c,mid);
        if(cows){
            ans=max(ans,mid);
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    //OJ;
    FIO;
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c; 
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<Ans(n,c)<<"\n";
    }
}