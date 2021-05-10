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

template <class T>
struct trie {
  struct node {
    map<T, node*> children;
    int prefixes, words;
    node() { prefixes = words = 0; } 
    ~node() { iter(it, children) delete it->second; } };
  node* root;
  trie() : root(new node()) {  }
  ~trie() { delete root; }
  template <class I>
  void insert(I begin, I end) {
    node* cur = root;
    while (true) {
      cur->prefixes++;
      if (begin == end) { cur->words++; break; }
      else {
        T head = *begin;
        typename map<T, node*>::const_iterator it;
        it = cur->children.find(head);
        if (it == cur->children.end()) {
          pair<T, node*> nw(head, new node());
          it = cur->children.insert(nw).first;
        } begin++, cur = it->second; } } }
  template<class I>
  int countMatches(I begin, I end) {
    node* cur = root;
    while (true) {
      if (begin == end) return cur->words;
      else {
        T head = *begin;
        typename map<T, node*>::const_iterator it;
        it = cur->children.find(head);
        if (it == cur->children.end()) return 0;
        begin++, cur = it->second; } } }
  template<class I>
  int countPrefixes(I begin, I end) {
    node* cur = root;
    while (true) {
      if (begin == end) return cur->prefixes;
      else {
        T head = *begin;
        typename map<T, node*>::const_iterator it;
        it = cur->children.find(head);
        if (it == cur->children.end()) return 0;
        begin++, cur = it->second; } } }
  template<class I>
  int uniquePrefixLength(I begin, I end) {
    node* cur = root;
    int res = 0;
    while (true) {
      if (begin == end || cur->prefixes == 1) return res;
      else {
        T head = *begin;
        typename map<T, node*>::const_iterator it;
        it = cur->children.find(head);
        if (it == cur->children.end()) return -1;
        begin++, res++, cur = it->second; } } } };

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> text(n);
    set<string> words;
    rep(i,0,n)
    {
        cin >> text[i];
        words.insert(text[i]);
    }
    trie<char> dict;
    string s;
    iter(it, words) dict.insert(it->begin(), it->end());

    int sm = 0;
    rep(i,0,n)
    {
        int full = text[i].size();
        int reduced = dict.uniquePrefixLength(text[i].begin(), text[i].end());
        if(reduced == -1) reduced = full; // word not in dictionary, write it out fully
        else if(reduced < full) reduced++; // write proper prefix and press tab
        // else just write the word fully
        sm += max(0, full - reduced);
    }

    cout << sm << endl;

    return 0;
}
