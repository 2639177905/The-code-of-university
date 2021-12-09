#include<bits/stdc++.h>
#include<string>
using namespace std;
#define maxn 100
#define inf 0x3f3f3f3f
#define rep(i,a,n) for(int i=a;i<=n;i++)
int graph[maxn][maxn];
void initgraph(int m,int n)
{	
	memset(graph,inf,sizeof(graph));
	rep(i,1,n)
	graph[i][i]=0;
	int u,v,w;
	rep(i,1,m)
	{	cin>>u>>v>>w;
		graph[u][v]=graph[v][u]=w;
	}
}
void floyd(int n)
{
	rep(i,1,n)
	rep(j,1,n)
	rep(k,1,n)
	{
		if((graph[i][k]+graph[k][j])<graph[i][j])
		{
			graph[i][j]=graph[j][i]=graph[i][k]+graph[k][j];
		}
	}
}
int main()
{	
	int n,m;
	cin>>n>>m;
	
	initgraph(m,n);
	floyd(n);
	rep(i,1,n)
	{
	rep(j,1,n)
	{
		
	cout<<graph[i][j]<<" ";}
	cout<<endl;}
}
