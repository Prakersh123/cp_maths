#include<bits/stdc++.h>
using namespace std;
bool solve(int i,int j,int id,int jd,int n,int m,vector<vector<char>> &arr)
{
	if(i==id && j==jd)
	{
		// print=true;
		arr[i][j]='1';
		return true;
	}
	if(i>=n || j>=m )
	return false;
	if(arr[i][j]=='X')
		return false;
			arr[i][j]='1';
		if(solve(i,j+1,id,jd,n,m,arr))
		return true;
		if(solve(i+1,j,id,jd,n,m,arr)) return true;
		arr[i][j]='0';
		return false;

}
int main() {

	int n,m;
	cin>>n>>m;
	vector<vector<char>> arr(n,vector<char>(m));
	// vector<vector<bool>> ans(n,vector<bool>(m));

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)	
				cin>>arr[i][j];
		if(solve(0,0,n-1,m-1,n,m,arr))
		{
			for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]=='1')
			cout<<arr[i][j]<<" ";
				else
				cout<<"0"<<" ";
			}
				cout<<"\n";
			}
		}
		else
		cout<<-1<<endl;

	return 0;
}