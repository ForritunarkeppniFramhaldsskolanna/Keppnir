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
    Node *left, *right;
    int id;
    Node(int id)
    {
        this->id = id;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node() 
    {
        if(left) delete left;
        this->left = NULL;
        if(right) delete right;
        this->right = NULL;
    }
};

int n, m;
vi preorder, inorder, postorder;
vvi children;

void make_tree(Node *&curr, int lo, int hi)
{
   if(lo > hi) return;
   rep(i,0,n)
   {
       if(lo <= preorder[i] && preorder[i] <= hi)
       {
           curr = new Node(preorder[i]);
           make_tree(curr->left, lo, preorder[i]-1);
           make_tree(curr->right, preorder[i]+1, hi);
           if(curr->left) children[curr->id].push_back(curr->left->id);
           if(curr->right) children[curr->id].push_back(curr->right->id);
           break;
       }
   }
}



int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    preorder.assign(n, 0);
    inorder.assign(m, 0);
    postorder.assign(n, 0);
    children.assign(n+1, vi(0));
    rep(i,0,n) cin >> preorder[i];
    rep(i,0,m) cin >> inorder[i];
    rep(i,0,n) cin >> postorder[i];
    
    Node* root = NULL;
    make_tree(root, 1, n);

    rep(i,1,n+1)
    {
        cout << i << ":";
        rep(j,0,size(children[i]))
        {
            cout << " " << children[i][j];
        }
        cout << endl;
    }

    return 0;
}
