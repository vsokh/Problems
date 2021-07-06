#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define nl "\n"

#define imx INT_MAX
#define lmx LLONG_MAX
#define imn INT_MIN
#define lmn LLONG_MIN

#define ff first
#define ss second
#define pb push_back

#define pri(i) printf("%d\n", i)
/* #define pri(i) printf("%lld\n", i) */
#define prij(i,j) printf("%lld %lld\n", i, j)

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vi vector<int>
#define si set<int>
#define pi pair<int, int>

#define setp(x) fixed<<setprecision(x)

int n, k;
int pre[2005];

void solve()
{
	scanf("%d", &n);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		pre[i]=(pre[i-1]^a);
	}
	bool y=!pre[n];
	printf("pre[n]: %d\n",pre[n]);
	printf("y: %d\n",y);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			y|=(pre[i]==(pre[j]^pre[i]) && pre[i]==(pre[n]^pre[j]));
			printf("i:%d y:%d\n",i,y);
		}
	}
	y?yes:no;
}

int main()
{
	int t = 0;
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}

