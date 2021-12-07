#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)

int n;//������Ŀ
int m;//����Ŀ
int graph[maxn][maxn];
int lowcost[maxn];//��i�����Ȩֵ
int closet[maxn];//�뼯��������ĵ�
int sum;

void prim(int s) { //����Ϊ��һ������
	rep(i, 1, n) {
		if (i == s)
			lowcost[i] = 0;
		else
			lowcost[i] = graph[s][i];
		closet[i] = s;
	}
	int minn ;
	int pos;//λ����Ϣ
	sum = 0;
	rep(i, 1, n) {
		minn = inf;
		rep(j, 1, n) {
			if (lowcost[j] != 0 && lowcost[j] < minn) {
				minn = lowcost[j];
				pos = j;
			}; //�ҵ���������ĵ�

		}
		if (minn == inf)
			break;
		sum += minn;
		lowcost[pos] = 0; //���뼯��
		rep(j, 1, n) {
			//���ڵ㼯���м������µĵ㣬����Ҫȥ���¡�
			if (lowcost[j] != 0 && graph[pos][j] < lowcost[j]) {
				lowcost[j] = graph[pos][j];
				closet[j] = pos; //�ı��붥��j�����Ķ�����š�
			}

		}
	}
	cout << sum << endl;

}

void print(int s) {
	//��ӡ��С��������
	int temp;
	rep(i, 1, n) {
		//����s��Ȼ���㣬�ʳ�ȥ���Ϊn-1���ߡ�
		if (i != s) {
			temp = closet[i];
			cout << temp << "->" << i << "��ȨֵΪ��" << graph[temp][i] << endl;
		}
	}
}

int main() {
	while (cin >> n >> m) {
		memset(graph, 100, sizeof(graph)); //��ʼ����
		int u, v, w; //��ʱ������
		rep(i, 1, m) {
			cin >> u >> v >> w;
			//��������ۣ�������������ͼΪ����
			graph[u][v] = graph[v][u] = w;
		}
		//��ȡ����㣬������Ĭ��ȡ1.
		prim(1);
		print(1);//��ӡ��С��������
	}


}