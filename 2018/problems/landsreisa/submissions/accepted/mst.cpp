#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<double, double> dd;

const ll INF = (1LL<<60);
const double pi = acos(-1);
const double EPS = 1e-9;

#define MAXN 10000

int n;
dd points[MAXN];

double dist(dd a, dd b)
{
    double difx = a.first - b.first, dify = a.second - b.second;
    return sqrt(difx*difx + dify*dify);
}

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(vector<double> &key, vector<bool> &mstSet)
{
   // Initialize min value
   double min = INFINITY;
   int min_index;
 
   for (int v = 0; v < n; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}

vector<vi> primMST()
{
    vector<vi> adj(n);
    vector<double> key(n);   // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(n);  // To represent set of vertices not yet included in MST
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++)
        key[i] = INFINITY, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
 
    // The MST will have V vertices
    for (int count = 0; count < n-1; count++)
    {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < n; v++)
        {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (mstSet[v] == false && dist(points[u],points[v]) < key[v])
                adj[u].push_back(v), adj[v].push_back(u), key[v] = dist(points[u], points[v]);
        }
    }
     
    return adj;
}

bool vis[MAXN];
void dfs(vector<vi> &adj, int at, vi &res)
{
    vis[at] = true;
    res.push_back(at);
    iter(it, adj[at])
    {
        if(vis[*it]) continue;
        dfs(adj, *it, res);
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> n;
    rep(i,0,n)
    {
        cin >> points[i].first >> points[i].second;
    }
    vector<vi> tree = primMST();
    vi res;
    dfs(tree, 0, res);
    double length = 0;
    rep(i,0,n)
    {
        cout << res[i] << " ";
        length += dist(points[res[i]], points[res[(i+1)%n]]);
    }
    //cout << endl << "Length: " << length << endl;
}
