#include<cstdio>

#include<cstring>

#include<vector>

#include<algorithm>

#include<queue>

using namespace std;

typedef struct node

{

int v,tol;

node(int vv = 0,int tt = 0): v(vv),tol (tt){}

bool operator < (const node & t) const

{

return tol > t.tol;

}

}node;

const int maxn = 3e5 + 5;

// Topological sorting judgment ring

// Memory search for points with zero insight

vector<int> G[maxn];

int in[maxn],in_tsp[maxn];// in degree

int dp[maxn][26];// Record dp results

bool vis[maxn];// tag array

bool TPS(int sum)

{

priority_queue<node> q;

for(int i = 0;i < sum; ++i)

{

q.push(node(i,in[i]));

in_tsp[i] = in[i];

}

node p;

while(!q.empty() && sum)

{

p = q.top();

q.pop();

int x = p.v;

if(p.tol > 0) return false;

if(vis[x]) continue;

vis[x] = true;

int len = G[x].size();

for(int i = 0;i < len; ++i)

{

int u = G[x][i];

if(!vis[u]) q.push(node(u,--in_tsp[u]));

}

--sum;

}

return true;

}

void DFS(int x)

{

int len = G[x].size();

int tp[26] = {0};

for(int i = 0;i < len; ++i)

{

int u = G[x][i];

if(!vis[u])

{

vis[u] = true;

DFS(u);

}

for(int j = 0;j < 26; ++j) tp[j] = max(tp[j],dp[u][j]);

}

for(int i = 0;i < 26; ++i) dp[x][i] += tp[i];

}

int main()

{

int x,y;

int n,m;

scanf("%d %d",&n,&m);

for(int i = 0;i < n; ++i)

{

vis[i] = false;

in[i] = 0;

for(int j = 0;j < 26; ++j) dp[i][j] = 0;

}

char p;

getchar();

for(int i = 0;i < n; ++i) dp[i][getchar() - 'a'] = 1;

for(int i = 0;i < m; ++i)

{

scanf("%d %d",&x,&y);

G[x - 1].push_back(y - 1);

in[y - 1]++;

}

int ans = -1;

if(TPS(n))

{

memset(vis,false,sizeof(vis));

for(int i = 0;i < n; ++i)

{

if(!in[i])

{

vis[i] = true;

DFS(i);

for(int j = 0;j < 26; ++j) ans = max(ans,dp[i][j]);

}

}

}

printf("%d\n",ans);

return 0;

}