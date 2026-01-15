#pragma once
#define AVL_MULTISET 0

template <typename K, typename V>
struct avl_node_t
{
    K key;
    V value;
    avl_node_t<K, V> *p, *l, *r;
    int64_t size;
    int64_t height;
    avl_node_t(const K& _key, const V& _value, avl_node_t<K, V>* _p = nullptr) : key(_key), value(_value), p(_p),
                                            l(nullptr), r(nullptr), size(1), height(0) {}
};

template <typename K, typename V, typename Cmp = std::less<K>>
struct avl_tree_t
{
    using node = avl_node_t<K, V>;
    avl_tree_t(Cmp &cmp) : root(nullptr), cmp(cmp) {}
    ~avl_tree_t() {
        while (size()) {
            erase(root);
        }
    }
    node *root;
    Cmp& cmp;
    constexpr int64_t sz(node *n) const { return n ? n->size : 0; }
    constexpr int64_t height(node *n) const
    {
        return n ? n->height : -1;
    }
    constexpr bool left_heavy(node *n) const
    {
        return n && height(n->l) > height(n->r);
    }
    constexpr bool right_heavy(node *n) const
    {
        return n && height(n->r) > height(n->l);
    }
    constexpr bool too_heavy(node *n) const
    {
        return n && myabs(height(n->l) - height(n->r)) > 1;
    }
    void delete_tree(node *n)
    {
        if (n)
        {
            delete_tree(n->l), delete_tree(n->r);
            delete n;
        }
    }
    node *&parent_leg(node *n)
    {
        if (!n->p)
            return root;
        if (n->p->l == n)
            return n->p->l;
        if (n->p->r == n)
            return n->p->r;
        assert(false);
    }
    void augment(node *n)
    {
        if (!n)
            return;
        n->size = 1 + sz(n->l) + sz(n->r);
        n->height = 1 + std::max(height(n->l), height(n->r));
    }
#define rotate_macro(l, r) \
    node *l = n->l;        \
    l->p = n->p;           \
    parent_leg(n) = l;     \
    n->l = l->r;           \
    if (l->r)              \
        l->r->p = n;       \
    l->r = n, n->p = l;    \
    augment(n), augment(l)
    void left_rotate(node *n) { rotate_macro(r, l); }
    void right_rotate(node *n) { rotate_macro(l, r); }
    void fix(node *n)
    {
        while (n)
        {
            augment(n);
            if (too_heavy(n))
            {
                if (left_heavy(n) && right_heavy(n->l))
                    left_rotate(n->l);
                else if (right_heavy(n) && left_heavy(n->r))
                    right_rotate(n->r);
                if (left_heavy(n))
                    right_rotate(n);
                else
                    left_rotate(n);
                n = n->p;
            }
            n = n->p;
        }
    }
    constexpr int64_t size() const { return sz(root); }
    node *lower_bound(const K &key) const
    {
        node *cur = root;
        node *best = nullptr;
        while (cur)
        {
            const auto c{cmp(key, cur->key)};
            if (c == std::weak_ordering::less)
            {
                best = cur;
                cur = cur->l;
            }
            else if(c == std::weak_ordering::greater)
            {
                cur = cur->r;
            }
            else {
                best = cur;
                break;
            }
        }
        if (best == nullptr) {
            std::cout << "No way!" << std::endl;
            return nullptr;
        }
        return best;
    }
    node *find(const K &key) const
    {
        node *res{lower_bound(key)};
        return (res && cmp(res->key, key) == std::weak_ordering::equivalent) ? res : nullptr;
    }
    node *insert(const K &key, const V& value)
    {
        node *prev = nullptr, **cur = &root;
        while (*cur)
        {
            prev = *cur;
            const auto c{cmp(key, (*cur)->key)};
            if (c == std::weak_ordering::less) {
                cur = &((*cur)->l);
            }
            else if (c == std::weak_ordering::greater) {
                cur = &((*cur)->r);
            }
            else {
                (*cur)->value = value;
                return *cur;
            }
        }
        node *n = new node(key, value, prev);
        *cur = n;
        fix(n);
        return n;
    }
    node* insert_at(node* at, const K& key, const V& value) {
        node** cur = &(at->l);
        node* prev = at;
        while (*cur) {
            prev = *cur;
            cur = &((*cur)->r);
        }
        node *n = new node(key, value, prev);
        *cur = n;
        fix(n);
        return n;
    }
    void erase(const K &key) { erase(find(key)); }
    void erase(node *n, bool free = true)
    {
        if (!n)
            return;
        if (!n->l && n->r)
            parent_leg(n) = n->r, n->r->p = n->p;
        else if (n->l && !n->r)
            parent_leg(n) = n->l, n->l->p = n->p;
        else if (n->l && n->r)
        {
            node *s = successor(n);
            erase(s, false);
            s->p = n->p, s->l = n->l, s->r = n->r;
            if (n->l)
                n->l->p = s;
            if (n->r)
                n->r->p = s;
            parent_leg(n) = s;
            fix(s);
            n->p = n->l = n->r = nullptr;
            assert(free);
            if (free) {
                delete n;
            }
            return;
        }
        else
            parent_leg(n) = nullptr;
        fix(n->p), n->p = n->l = n->r = nullptr;
        if (free) {
            delete n;
        }
    }
    void reverse_values(node *l, node *r) {
        while (l && r && l != r) {
            node* l_succ = successor(l);
            node* r_pred = predecessor(r);

            parent_leg(l) = r;
            parent_leg(r) = l;
            std::swap(l->l, r->l);
            std::swap(l->r, r->r);
            std::swap(l->p, r->p);
            std::swap(l->size, r->size);
            std::swap(l->height, r->height);
            if(l->l) l->l->p = l;
            if(l->r) l->r->p = l;
            if(r->l) r->l->p = r;
            if(r->r) r->r->p = r;
            assert(parent_leg(l) = l);
            assert(parent_leg(r) = r);
            if (l_succ == r) break;
            l = l_succ;
            r = r_pred;
        }
    }
    node *successor(node *n) const
    {
        if (!n)
            return nullptr;
        if (n->r)
            return nth(0, n->r);
        node *p = n->p;
        while (p && p->r == n)
            n = p, p = p->p;
        return p;
    }
    node *predecessor(node *n) const
    {
        if (!n)
            return nullptr;
        if (n->l)
            return nth(n->l->size - 1, n->l);
        node *p = n->p;
        while (p && p->l == n)
            n = p, p = p->p;
        return p;
    }
    node *nth(int n, node *cur = nullptr) const
    {
        if (!cur)
            cur = root;
        while (cur)
        {
            if (n < sz(cur->l))
                cur = cur->l;
            else if (n > sz(cur->l))
                n -= sz(cur->l) + 1, cur = cur->r;
            else
                break;
        }
        return cur;
    }
    int64_t count_less(node *cur)
    {
        int64_t sum = sz(cur->l);
        while (cur)
        {
            if (cur->p && cur->p->r == cur)
                sum += 1 + sz(cur->p->l);
            cur = cur->p;
        }
        return sum;
    }
    void clear()
    {
        delete_tree(root), root = nullptr;
    }
};

template <typename K, typename V, typename Cmp = std::less<K>>
using avl_map_t = avl_tree_t<K, V, Cmp>;
