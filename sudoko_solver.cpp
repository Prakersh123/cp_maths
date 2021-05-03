#include <bits/stdc++.h>
using namespace std;
#define int long long 
map<string,int> mp;
// long long  count=0;

//-1 in the output indicate that the queen is placed at this position
bool row_confirm(vector<vector<int>> arr,int x,int i,int j)
{
    for(int q=0;q<9;q++)
    {
        if(x==arr[i][q])    
        {
            return false;
        }
    }
    for(int q=0;q<9;q++)
    {
        if(x==arr[q][j])
        return false;
    }
    return true;
}
bool solve(int n,int j,vector<vector<int>> & arr,vector<vector<bool>> &visited,int N)
{
           if(j>=N)
           {
               j=j%9;
               n++;
           } 
           if(n==N)
           {
               return true;
           }
           
           
           
          if(arr[n][j]==0) {
                    int index_visit=(n/3)*3+j/3;

                for(int x=1;x<=9;x++)
                {
                    if(visited[index_visit][x]==false)
                    {
                        if(row_confirm(arr,x,n,j)==true)
                        {
                               arr[n][j]=x;
                               visited[index_visit][x]=true; 

                               if(solve(n,j+1,arr,visited,N))
                               {
                                   return true;
                               }
                               else
                               {
                               arr[n][j]=0;
                               visited[index_visit][x]=false; 
                               }
                        }
                            
                    }
                }
                return false;

            }
            return solve(n,j+1,arr,visited,N);
        
}


int32_t main()
{
    freopen("input.txt","r",stdin);
	freopen("out1","w",stdout);
    int t;
    cin>>t;
    while(t--){

            int n;
            cin>>n;
            n=n*n;
            vector<vector<int>> arr(n,vector<int>(n,0));
            vector<vector<bool>> ans(n,vector<bool>(n+1,0));
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {    
                    cin>>arr[i][j];
                    if(arr[i][j]!=0)
                    {int index_visi= (i/3)*3+j/3;

                    ans[index_visi][arr[i][j]]=true;}
                }
            
            solve(0,0,arr,ans,n);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<arr[i][j]<<" ";
                
                }
                cout<<endl;
            }
    }
   
    return 0;
}