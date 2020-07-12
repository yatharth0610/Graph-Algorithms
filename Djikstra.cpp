/**
 * Djikstra is one of the most famous algorithm for finding shortest
 * path from one node to other nodes. However, in this implementation
 * since we're only going from a starting node to an ending node we 
 * can employ an optimization to stop early once we've visited all the
 * neighbouring nodes.
 *
 * Author : Yatharth Goswami
 * Github ID : yatharth0610
 * Email : yatharthgoswami15@gmail.com
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;
const int MAXM = 1010;
const int INF = 1e9 + 7;

struct Edge {
  int v, w;
  // constructor
  Edge(int tv, int tw)
  {
    v = tv, w = tw;
  }
};
int n, m;
int dist[MAXN];
bool vis[MAXN];
vector<Edge> e[MAXN];

void init()
{
  for (int i = 0; i < MAXN; i++)
  {
    e[i].clear();
    dist[i] = INF;
  }
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    // building graph
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      
      e[u].push_back(Edge(v, w));
      e[v].push_back(Edge(u, w));
    }
    int start, end;
    scanf("%d%d", &start, &end);
    
    // dijkstra + priority_queue optimized
    priority_queue<pair<int, int> > Q;      // first int is point index, second int is priority
    dist[start] = 0;
    Q.push(make_pair(start, 0));
    
    while (!Q.empty())
    {
      int cur = Q.top().first;
      Q.pop();
      
      if (vis[cur]) {
      	continue;
	  }
	  vis[cur] = 1;
      
      // foreach the edges of point `cur`
      for (unsigned int i = 0; i < e[cur].size(); i++)
      {
        int v = e[cur][i].v, w = e[cur][i].w;
        if (dist[v] > dist[cur] + w) {
          dist[v] = dist[cur] + w;
          Q.push(make_pair(v, -dist[v]));    
        }
      } 
    }
    
    if (dist[end] == INF) {
      printf("-1\n");
    } else {
      printf("%d\n", dist[end]);
    }
  
  return 0;
}