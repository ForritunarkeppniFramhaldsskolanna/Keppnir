#include <bits/stdc++.h>
#pragma GCC target("arch=sandybridge")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
using namespace std;
// template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

struct Node
{
    vector<Node*> children;
    int id;
    Node(int id)
    {
        this->id = id;
        this->children = vector<Node*>();
    }
    ~Node() 
    {
        iter(it, children)
        {
            if(*it) delete *it;
        }
    }
};

int n, m;
vi preorder, inorder, postorder;
vvi children;
vector<bool> vis;

int pre_at = 0;
int post_at = 0;
int make_tree()
{
   vis[preorder[pre_at]] = true;
   int val = preorder[pre_at];
   while(!vis[postorder[post_at]])
   {
       pre_at++;
       children[val].push_back(make_tree());
   }
   post_at++;
   return val;
}



int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    preorder.assign(n, 0);
    inorder.assign(m, 0);
    postorder.assign(n, 0);
    vis.assign(n+1, false);
    children.assign(n+1, vi(0));

    rep(i,0,n) cin >> preorder[i];
    rep(i,0,m) cin >> inorder[i];
    rep(i,0,n) cin >> postorder[i];
    
    make_tree();

    rep(i,1,n+1)
    {
        cout << i << ":";
        rep(j,0,children[i].size())
        {
            cout << " " << children[i][j];
        }
        cout << endl;
    }

    return 0;
}
