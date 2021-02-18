// Trabalho 2
// Disciplina de Analise de Algoritmo - EACH 2/2020
// Aluna: Bruna Ferreira dos Santos

#include <bits/stdc++.h>

#define V1 123112512.00
#define EPS 1e-9
using namespace std;

struct point{
	int x, y, r;

	point() {x = y = r = 0;}
	point(int _x, int _y, int _r) : x(_x), y(_y), r(_r){}

};
int n;
double valor[105];
vector<vector<pair<double, int> > > pontos;
double dist(point &a, point &b)
{
	return (hypot(a.x - b.x, a.y - b.y));
}

void dijkstra(int s)
{
	for (int i = 0 ; i < n ; ++i) valor[i] = V1;

	valor[s] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int> > , greater<pair<double, int> > > q;
	q.push(make_pair(0., s));

	while (!q.empty())
	{
		pair<double, int> u = q.top(); q.pop();

		int v = u.second;

		if (u.first - valor[v] > EPS) continue;

		for (int i = 0 ; i < pontos[v].size(); ++i)
		{
			int v2 = pontos[v][i].second;
			if (valor[v2] - (valor[v] + pontos[v][i].first) > EPS)
			{
				valor[v2] = valor[v] + pontos[v][i].first;
				q.push(make_pair(valor[v2], v2));
			}
		}
	}
}
int main()
{
	point input[105];
	int x,y,r;
	int a1, a2;
	int queries;
	int linha = 1;
	while (1)
	{
	    //inteiro não negativo
	    //n = número de antenas disponíveis para interconexão na rede
		scanf("%d", &n);
		if (!n) return 0;

		pontos.clear();
		pontos.assign(n, vector<pair<double, int> > ());
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d %d", &x, &y, &r);
			input[i] = (point(x, y, r));
		}
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n; ++j)
			{
				double d = dist(input[i], input[j]);
				if (input[i].r - d > EPS)
					pontos[i].push_back(make_pair(d, j));
			}
		}
		scanf("%d", &queries);
		while (queries--)
		{
			scanf("%d %d", &a1, &a2);
			--a1, --a2;

			dijkstra(a1);

			if (fabs(valor[a2] - V1) < EPS)
				printf("-1\n");
			else printf("%d\n", (int)(valor[a2]));
		}
	}
}
