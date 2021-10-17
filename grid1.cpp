#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;

lli n, m;
lli arr[1005][1005];
lli dp[1005][1005];

lli rec(lli x, lli y){
	// base case
	if (x==n-1 && y==m-1)
	{
		return arr[x][y];
	}

	if (dp[x][y]!=-1)
	{
		return dp[x][y];
	}

	lli ans = -10;
	if (x<n-1)
	{
		ans = max(ans, arr[x][y] + rec(x+1, y));
	}
	if (y<m-1)
	{
		ans = max(ans, arr[x][y] + rec(x, y+1));
	}
	return (dp[x][y] = ans);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli t;
    cin>>t;

    while(t--){
    	memset(dp,-1,sizeof(dp));
    	cin>>n>>m;
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			cin>>arr[i][j];
    		}
    	}

    	cout<<rec(0,0)<<"\n";
    }

}