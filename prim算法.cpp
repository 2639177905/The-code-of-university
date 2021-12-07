#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)

int n;//顶点数目
int m;//边数目
int graph[maxn][maxn];
int lowcost[maxn];//离i最近的权值
int closet[maxn];//离集合中最近的点
int sum;

void prim(int s) { //参数为第一个顶点
	rep(i, 1, n) {
		if (i == s)
			lowcost[i] = 0;
		else
			lowcost[i] = graph[s][i];
		closet[i] = s;
	}
	int minn ;
	int pos;//位置信息
	sum = 0;
	rep(i, 1, n) {
		minn = inf;
		rep(j, 1, n) {
			if (lowcost[j] != 0 && lowcost[j] < minn) {
				minn = lowcost[j];
				pos = j;
			}; //找到距离最近的点

		}
		if (minn == inf)
			break;
		sum += minn;
		lowcost[pos] = 0; //加入集合
		rep(j, 1, n) {
			//由于点集合中加入了新的点，我们要去更新。
			if (lowcost[j] != 0 && graph[pos][j] < lowcost[j]) {
				lowcost[j] = graph[pos][j];
				closet[j] = pos; //改变与顶点j相连的顶点序号。
			}

		}
	}
	cout << sum << endl;

}

void print(int s) {
	//打印最小生成树。
	int temp;
	rep(i, 1, n) {
		//等于s自然不算，故除去这个为n-1条边。
		if (i != s) {
			temp = closet[i];
			cout << temp << "->" << i << "边权值为：" << graph[temp][i] << endl;
		}
	}
}

int main() {
	while (cin >> n >> m) {
		memset(graph, 100, sizeof(graph)); //初始化。
		int u, v, w; //临时变量。
		rep(i, 1, m) {
			cin >> u >> v >> w;
			//视情况而论，我这里以无向图为例。
			graph[u][v] = graph[v][u] = w;
		}
		//任取根结点，我这里默认取1.
		prim(1);
		print(1);//打印最小生成树。
	}


}