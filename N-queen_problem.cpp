#include <bits/stdc++.h>
using namespace std;
#define int long long 
map<string,int> mp;


//-1 in the output indicate that the queen is placed at this position
bool solve(int n,vector<vector<int>> &arr,int N)
{
    if(n==N)
    {
        return true;
    }
    

    for(int i=0;i<N;i++)
    {
        if(arr[n][i]==0)
        {
            arr[n][i]=-1;
            for(int j=0;j<N;j++)
            {
                if(arr[n][j]==0)
                arr[n][j]=n+1;
            }
             for(int j=0;j<N;j++)
            {
                if(arr[j][i]==0)
                arr[j][i]=n+1;
            }
            int p=n,q=i;
            while(p<N && q<N)
            {
                if(arr[p][q]==0)
                arr[p][q]=n+1;
                p++;
                q++;
            }
            p=n,q=i;
            while(p>=0 && q>=0)
            {
             if(arr[p][q]==0)
                arr[p][q]=n+1;
                p--;
                q--;   
            }

            p=n,q=i;
            while(p>=0 && q<N)
            {
                    if(arr[p][q]==0)
                arr[p][q]=n+1;
                p--;
                q++;   
            }
            p=n,q=i;
            while(p<N && q>=0)
            {
                    if(arr[p][q]==0)
                arr[p][q]=n+1;
                p++;
                q--;   
            }
           
            bool ans=solve(n+1,arr,N);
                if(ans==true)
                return true;

                 for(int j=0;j<N;j++)
            {
                if(arr[n][j]==n+1)
                arr[n][j]=0;
            }
             for(int j=0;j<N;j++)
            {
                if(arr[j][i]==n+1)
                arr[j][i]=0;
            }
             p=n,q=i;
            while(p<N && q<N)
            {
                if(arr[p][q]==n+1)
                arr[p][q]=0;
                p++;
                q++;
            }
            p=n,q=i;
            while(p>=0 && q>=0)
            {
             if(arr[p][q]==n+1)
                arr[p][q]=0;
                p--;
                q--;   
            }
            p=n,q=i;
            while(p>=0 && q<N)
            {
                    if(arr[p][q]==n+1)
                arr[p][q]=0;
                p--;
                q++;   
            }
            p=n,q=i;
            while(p<N && q>=0)
            {
                    if(arr[p][q]==n+1)
                arr[p][q]=0;
                p++;
                q--;   
            }
            arr[n][i]=0;
    
        }
    }
    return false;
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
            vector<vector<int>> arr(n,vector<int>(n,0));
            if(solve(0,arr,n))  {   
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    cout<<arr[i][j]<<" ";
            cout<<endl;}
            }
            else
            cout<<-1<<endl;
            cout<<endl;
    }
   
    return 0;
}