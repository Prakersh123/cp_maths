#include <bits/stdc++.h>
using namespace std;
#define int long long 



void subset_generate(int i,int n,string str,string ans)
{
    if(i==n)
    {
        cout<<ans<<" ";
        return ;
    }
    subset_generate(i+1,n,str,ans+str[i-1]);
    subset_generate(i+1,n,str,ans);

}
 

int32_t main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
    string s;
        cin>>s;
        subset_generate(1,s.length(),s,"");
    }
   
    return 0;
}