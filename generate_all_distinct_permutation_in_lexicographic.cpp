#include <bits/stdc++.h>
using namespace std;
#define int long long 
map<string,int> mp;
void permutation_generate(int count,bool visited[],string s,int n,string ans)
{
        if(count==n)
        {
            mp.insert({ans,0});
            // cout<<ans<<endl;
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                permutation_generate(count+1,visited,s,n,ans+s[i]);
                visited[i]=false;
            }
        }

}




int32_t main()
{
    // freopen("input.txt","r",stdin);
	// freopen("out1","w",stdout);
    
	{

            string s;
            cin>>s;
            bool visited[s.length()]={false};
            permutation_generate(0,visited,s,s.length(),"");               
            for(auto x:mp)
            cout<<x.first<<endl;
    }
   
    return 0;
}