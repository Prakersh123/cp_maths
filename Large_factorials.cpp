#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ff      first
#define ss      second
#define pb      push_back
#define int     long  long int 
#define mp      make_pair
#define pii     pair<ilsnt,int>
#define vi      vector<int>
#define mii     map<int,int>
#define pqi     priority_queue<int>
#define pqd     priority_queue<int,vi,greator<int>>
#define mod     1000000007 //1e9+7
#define inf     1e18
#define ps(x,y)     fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define test(t)     int t; cin>>t; while(t--)
#define setbits(x)      __builtin_popcountint(x);
#define zrobits(x)      __builtin_ctzint(x)          //it gives no of zeros before first set bit in right
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());//used for shuffling an array

#define input(arr,n)     for(int i=0;i<n;i++) cin>>arr[i]
#define output(arr,n)       for(int i=0;i<n;i++) cout<<arr[i]<<" ";
// typedef tree<int,nuint_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// #define ONLINE_JUDGE


void solve_by_prakersh_arya()
{

    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        test(t)
        {

                int n;
                cin>>n;
                int arr[200]={0};
                arr[0]=1;
                int j;
                int non=0;
                for(int i=2;i<=n;i++)
                {
                    int sum=arr[0]*i;
                    j=0;
                    for(;j<=non;)
                    {
                    
                        arr[j++]=sum%10;
                        // cout<<arr[j-1]<<endl;
                        sum=arr[j]*i+sum/10;
                    }
                    while(sum)
                    {
                        arr[j]=sum%10;
                        sum=sum/10;
                        j++;
                        non++;
                    }
                }
                for(int k=non;k>=0;k--)
                cout<<arr[k];
                cout<<endl;
        }
}




int32_t main()
{
    solve_by_prakersh_arya();
    return 0;
}