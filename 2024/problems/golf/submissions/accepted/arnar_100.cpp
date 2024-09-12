#include <bits/stdc++.h>
using namespace std;
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

#define AVL_MULTISET 0
template <class T>
struct avl_tree {
  struct node {
    T item; node *p, *l, *r;
    size_t size, height;
    node(const T &_item, node *_p = NULL) : item(_item), p(_p),
    l(NULL), r(NULL), size(1), height(0) { } };
  avl_tree() : root(NULL) { }
  node *root;
  inline size_t sz(node *n) const { return n ? n->size : 0ULL; }
  inline int64_t height(node *n) const {
    return n ? n->height : -1; }
  inline bool left_heavy(node *n) const {
    return n && height(n->l) > height(n->r); }
  inline bool right_heavy(node *n) const {
    return n && height(n->r) > height(n->l); }
  inline bool too_heavy(node *n) const {
    return n && abs(height(n->l) - height(n->r)) > 1LL; }
  void delete_tree(node *n) { if (n) {
    delete_tree(n->l), delete_tree(n->r); delete n; } }
  node*& parent_leg(node *n) {
    if (!n->p) return root;
    if (n->p->l == n) return n->p->l;
    if (n->p->r == n) return n->p->r;
    assert(false); }
  void augment(node *n) {
    if (!n) return;
    n->size = 1 + sz(n->l) + sz(n->r);
    n->height = 1 + max(height(n->l), height(n->r)); }
  #define rotate(l, r) \
    node *l = n->l; \
    l->p = n->p; \
    parent_leg(n) = l; \
    n->l = l->r; \
    if (l->r) l->r->p = n; \
    l->r = n, n->p = l; \
    augment(n), augment(l)
  void left_rotate(node *n) { rotate(r, l); }
  void right_rotate(node *n) { rotate(l, r); }
  void fix(node *n) {
    while (n) { augment(n);
      if (too_heavy(n)) {
        if (left_heavy(n) && right_heavy(n->l))
          left_rotate(n->l);
        else if (right_heavy(n) && left_heavy(n->r))
          right_rotate(n->r);
        if (left_heavy(n)) right_rotate(n);
        else left_rotate(n);
        n = n->p; }
      n = n->p; } }
  inline size_t size() const { return sz(root); }
  node* find(const T &item) const {
    node *cur = root;
    while (cur) {
      if (cur->item < item) cur = cur->r;
      else if (item < cur->item) cur = cur->l;
      else break; }
    return cur; }
  node* lower_bound(const T& item) const {
    node *cur = root;
    node *res = nullptr;
    while (cur) {
      if (cur->item < item) cur = cur->r;
      else if (item < cur->item) res = cur, cur = cur->l;
      else return cur; }
    return res;
  }
  node* insert(const T &item) {
    node *prev = NULL, **cur = &root;
    while (*cur) {
      prev = *cur;
      if ((*cur)->item < item) cur = &((*cur)->r);
#if AVL_MULTISET
      else cur = &((*cur)->l);
#else
      else if (item < (*cur)->item) cur = &((*cur)->l);
      else return *cur;
#endif
    }
    node *n = new node(item, prev);
    *cur = n, fix(n); return n; }
  void erase(const T &item) { erase(find(item)); }
  void erase(node *n, bool free = true) {
    if (!n) return;
    if (!n->l && n->r) parent_leg(n) = n->r, n->r->p = n->p;
    else if (n->l && !n->r)
      parent_leg(n) = n->l, n->l->p = n->p;
    else if (n->l && n->r) {
      node *s = successor(n);
      erase(s, false);
      s->p = n->p, s->l = n->l, s->r = n->r;
      if (n->l) n->l->p = s;
      if (n->r) n->r->p = s;
      parent_leg(n) = s, fix(s);
      return;
    } else parent_leg(n) = NULL;
    fix(n->p), n->p = n->l = n->r = NULL;
    if (free) delete n; }
  node* successor(node *n) const {
    if (!n) return NULL;
    if (n->r) return nth(0, n->r);
    node *p = n->p;
    while (p && p->r == n) n = p, p = p->p;
    return p; }
  node* predecessor(node *n) const {
    if (!n) return NULL;
    if (n->l) return nth(n->l->size-1, n->l);
    node *p = n->p;
    while (p && p->l == n) n = p, p = p->p;
    return p; }
  node* nth(size_t n, node *cur = NULL) const {
    if (!cur) cur = root;
    while (cur) {
      if (n < sz(cur->l)) cur = cur->l;
      else if (n > sz(cur->l))
        n -= sz(cur->l) + 1, cur = cur->r;
      else break;
    } return cur; }
  size_t count_less(node *cur) {
    size_t sum = sz(cur->l);
    while (cur) {
      if (cur->p && cur->p->r == cur) sum += 1 + sz(cur->p->l);
      cur = cur->p;
    } return sum; }
  void clear() { delete_tree(root), root = NULL; } };

int main()
{
    ios_base::sync_with_stdio(false);

    size_t n, q;
    cin >> n >> q;
    vector<string> names(n);
    vector<int64_t> score(n);
    unordered_map<string, size_t> name_to_ind;
    name_to_ind.max_load_factor(0.5);
    avl_tree<pair<int64_t, size_t>> ordering;

    for (auto& name : names) {
        cin >> name;
        ordering.insert({0LL, name_to_ind.size()});
        name_to_ind[name] = name_to_ind.size();
    }

    for (size_t i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '!') {
            size_t change_count;
            cin >> change_count;
            for (size_t j = 0; j < change_count; j++) {
                string name;
                int64_t change;
                cin >> name >> change;
                const auto ind{ name_to_ind.find(name)->second };
                auto* correct_node{ ordering.find({score[ind], ind}) };
                ordering.erase(correct_node);
                score[ind] += change;
                ordering.insert({score[ind], ind});
            }
        }
        else {
            string name;
            cin >> name;
            const auto ind{ name_to_ind.find(name)->second };
            auto* leftmost_node{ ordering.lower_bound({score[ind], 0}) };
            cout << ordering.count_less(leftmost_node) + 1 << " " << score[ind] << endl;
        }
    }

    return 0;
}
