#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

#include "fraction.h"
#include "avl_tree.h"
#include "common.h"
#include "vec2.h"
#include "segment2.h"

using namespace std;

using int_t = int64_t;
using edge_t = pair<int_t, int_t>;
using edge_list_t = vector<edge_t>;
using adj_list_t = vector<edge_list_t>;

template <typename T>
struct graph_t {
    vector<vec2_t<T>> points{};
    adj_list_t adj{};
    int_t add_vertex(const vec2_t<T>& p) {
        points.push_back(p);
        adj.emplace_back();
        return ssize(points) - 1;
    }
    void add_edge(int_t from, int_t to, int_t label) {
        adj[from].emplace_back(to, label);
        adj[to].emplace_back(from, label);
    }
};

template <typename T>
struct bentley_ottman_t {
    struct event_t {
        vec2_t<T> point;
        segment2_t<T> segment;
        std::weak_ordering operator<=>(const event_t& other) const = default;
    };

    struct line_cmp_t {
        weak_ordering operator()(const vec2_t<T>& a, const vec2_t<T>& b) const {
            return a == b ? weak_ordering::equivalent : (a < b ? weak_ordering::less : weak_ordering::greater);
        }
    };

    struct sweep_cmp_t {
        vec2_t<T> sweep_point;
        map<segment2_t<T>, int64_t>& seg_id_map;
        sweep_cmp_t(const vec2_t<T>& sweep_point, map<segment2_t<T>, int64_t>& seg_id_map) : sweep_point(sweep_point), seg_id_map(seg_id_map) {}
        weak_ordering operator()(const segment2_t<T>& a, const segment2_t<T>& b) const {
            using wo = weak_ordering;
            if (a == b) return wo::equivalent;
            T res = 0;
            if (sweep_point == a.p) res = b.ccw(sweep_point);
            else if (sweep_point == b.p) res = a.ccw(sweep_point);
            else assert(false);
            if (res != 0 || a.is_trivial() || b.is_trivial()) {
                return res != 0 ? (res < 0 ? wo::less : wo::greater) : wo::equivalent;
            }
            res = b.ccw(a.q);
            if (res == 0) {
                const auto id_res{ seg_id_map.at(a) - seg_id_map.at(b) };
                return id_res != 0 ? (id_res < 0 ? wo::less : wo::greater) : wo::equivalent;
            }
            return res < 0 ? wo::less : wo::greater;
        }
    };

    using segment_queue_t = priority_queue<event_t, vector<event_t>, greater<event_t>>;
    using x_structure_t = avl_map_t<vec2_t<T>, void*, line_cmp_t>;
    using y_structure_t = avl_map_t<segment2_t<T>, void*, sweep_cmp_t>;
    using x_node = typename x_structure_t::node;
    using y_node = typename y_structure_t::node;

    map<segment2_t<T>, int64_t> seg_id_map{};
    line_cmp_t line_cmp{};
    sweep_cmp_t sweep_cmp;
    vector<segment2_t<T>> segments;
    x_structure_t x_structure;
    y_structure_t y_structure;
    segment_queue_t segment_queue{};
    graph_t<T> graph{};
    map<segment2_t<T>, int64_t> last_vertex{};
    segment2_t<T> next_segment;
    int_t vertex{ 0 };

    bentley_ottman_t(const vector<segment2_t<T>>& segs) : sweep_cmp({}, seg_id_map), segments(segs), x_structure(line_cmp), y_structure(sweep_cmp) {
        initialize();
        sweep();
    }

    void initialize() {
        T infinity = T(1);
        for (int_t i = 0; i < ssize(segments); i++) {
            auto& [p1, p2]{ segments[i] };
            while (myabs(p1.x) >= infinity || myabs(p2.x) >= infinity || myabs(p1.y) >= infinity || myabs(p2.y) >= infinity) {
                infinity *= 2;
            }
            if (p2 < p1) swap(p2, p1);
            x_node* it1 = x_structure.insert(p1, nullptr);
            x_node* it2 = x_structure.insert(p2, nullptr);
            if (it1 == it2) continue;
            segment_queue.push({p1, segments[i]});
            seg_id_map[segments[i]] = i;
        }
        segment2_t<T> lower_sentinel{ {-infinity, -infinity}, {infinity, -infinity} };
        segment2_t<T> upper_sentinel{ {-infinity, infinity}, {infinity, infinity} };
        y_structure.cmp.sweep_point = lower_sentinel.p;
        y_structure.insert(upper_sentinel, nullptr);
        y_structure.insert(lower_sentinel, nullptr);
        vec2_t final_point{ infinity, infinity };
        segment_queue.push({final_point, {final_point, final_point }});
        next_segment = segment_queue.top().segment;
    }

    void sweep() {
        while (x_structure.size()) {
            x_node* event = x_structure.nth(0);
            y_structure.cmp.sweep_point = event->key;
            vertex = graph.add_vertex(y_structure.cmp.sweep_point);
            handle_event(event);
            x_structure.erase(event);
        }
    }

    void handle_event(const x_node* event) {
        // Handle passing and ending segments
        y_node* sit = static_cast<y_node*>(event->value);
        if (sit == nullptr) sit = y_structure.find({y_structure.cmp.sweep_point, y_structure.cmp.sweep_point});
        y_node* sit_succ = nullptr;
        y_node* sit_pred = nullptr;
        y_node* sit_first = nullptr;
        if (sit != nullptr) {
            // Determine passing and ending segments
            while (sit->value == event || sit->value == y_structure.successor(sit)) {
                sit = y_structure.successor(sit);
            }
            sit_succ = y_structure.successor(sit);

            bool overlapping = false;
            do {
                overlapping = false;
                const segment2_t<T> s{ sit->key };
                const auto other_vertex{ last_vertex[s] };
                graph.add_edge(other_vertex, vertex, seg_id_map[s]);
                // Ending segment
                if (y_structure.cmp.sweep_point == s.q) {
                    y_node* it = y_structure.predecessor(sit);
                    if (it->value == sit) {
                        overlapping = true;
                        it->value = sit->value;
                    }
                    y_structure.erase(sit);
                    sit = it;
                }
                // Passing segment
                else {
                    if (sit->value != y_structure.successor(sit)) {
                        sit->value = nullptr;
                    }
                    last_vertex[s] = vertex;
                    sit = y_structure.predecessor(sit);
                }
            } while(sit->value == event || overlapping || sit->value == y_structure.successor(sit));
            sit_pred = sit;
            sit_first = y_structure.successor(sit_pred);

            // Reverse passing sements
            sit = sit_first;
            while (sit != sit_succ) {
                y_node* sub_first = sit;
                y_node* sub_last = sub_first;
                while (sub_last->value == y_structure.successor(sub_last)) {
                    sub_last = y_structure.successor(sub_last);
                }
                if (sub_first != sub_last) {
                    y_structure.reverse_values(sub_first, sub_last);
                }
                sit = y_structure.successor(sub_first);
            }
            if (sit_first != sit_succ) {
                y_structure.reverse_values(y_structure.successor(sit_pred), y_structure.predecessor(sit_succ));
            }
        }

        // Insert starting segments
        while (y_structure.cmp.sweep_point == next_segment.p) {
            y_node* s_sit = y_structure.lower_bound(next_segment);
            y_node* p_sit = y_structure.predecessor(s_sit);
            segment2_t<T> s = s_sit->key;
            if (s.ccw(next_segment.p) == 0 && s.ccw(next_segment.q) == 0) {
                sit = y_structure.insert_at(s_sit, next_segment, s_sit);
            }
            else {
                sit = y_structure.insert_at(s_sit, next_segment, nullptr);
            }
            s = p_sit->key;
            if (s.ccw(next_segment.p) == 0 && s.ccw(next_segment.q) == 0) {
                p_sit->value = sit;
            }
            x_structure.insert(next_segment.q, sit);
            last_vertex[next_segment] = vertex;
            if (sit_succ == nullptr) {
                sit_succ = s_sit;
                sit_pred = p_sit;
            }

            segment_queue.pop();
            next_segment = segment_queue.top().segment;
        }

        // Compute intersections
        if (sit_pred) {
            sit_pred->value = nullptr;
            compute_intersection(sit_pred);
            sit = y_structure.predecessor(sit_succ);
            if (sit != sit_pred) {
                compute_intersection(sit);
            }
        }
    }


    void compute_intersection(y_node* sit_a) {
        const y_node* sit_b = y_structure.successor(sit_a);
        const auto& a{ sit_a->key };
        const auto& b{ sit_b->key };
        const auto [intersection_type, intersection]{ a.intersect(b) };
        if (intersection_type == intersection_t::one) {
            const auto new_point{ get<vec2_t<T>>(intersection) };
            if (y_structure.cmp.sweep_point < new_point) {
                sit_a->value = x_structure.insert(new_point, sit_a);
            }
        }
    }
};

template <typename T>
graph_t<T> bentley_ottman(const vector<segment2_t<T>>& segments) {
    return bentley_ottman_t{ segments }.graph;
}

int_t mex_sorted(const vector<int_t>& values) {
    int_t res = 0;
    for (auto x : values) {
        if (res == x) res++;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int_t n;
    cin >> n;
    vector<segment2_t<float>> roads(n);
    for (auto& [p, q] : roads) {
        cin >> p.x >> p.y >> q.x >> q.y;
    }

    const auto res { bentley_ottman(roads) };


    vector<pair<int_t, int_t>> color(size(res.adj), {-1, -1});
    vector<int_t> cur_color(n, -1);
    vector<pair<pair<int_t, int_t>, pair<int_t, int_t>>> output;
    string color_name{ "rygb" };
    for (int_t i = 0; i < ssize(res.adj); i++) {
        vector<int_t> connected_roads;
        for (const auto& [j, segment_index] : res.adj[i]) {
            connected_roads.push_back(segment_index);
        }
        ranges::sort(connected_roads);
        const auto un{ ranges::unique(connected_roads) };
        connected_roads.erase(un.begin(), un.end());
        assert(ssize(connected_roads) <= 2);
        if (ssize(connected_roads) > 1) {
            const auto seg_a { connected_roads.front() };
            const auto seg_b { connected_roads.back() };
            if (cur_color[seg_a] == cur_color[seg_b]) {
                if (cur_color[seg_a] == -1 || cur_color[seg_a] == 1) {
                    cur_color[seg_a] = 0;
                    cur_color[seg_b] = 2;
                }
                else {
                    cur_color[seg_a] = 1;
                    cur_color[seg_b] = 1;
                }
            }
            else if (cur_color[seg_a] == 0 || cur_color[seg_b] == 2) {
                cur_color[seg_a] = 2;
                cur_color[seg_b] = 0;
            }
            else if (cur_color[seg_a] == 2 || cur_color[seg_b] == 0) {
                cur_color[seg_a] = 0;
                cur_color[seg_b] = 2;
            }
            else if (cur_color[seg_a] == -1 || cur_color[seg_b] == 1) {
                cur_color[seg_a] = 0;
                cur_color[seg_b] = 2;
            }
            else if (cur_color[seg_a] == 1 || cur_color[seg_b] == -1) {
                cur_color[seg_a] = 0;
                cur_color[seg_b] = 2;
            }
            else {
                cerr << cur_color[seg_a] << " " << cur_color[seg_b] << endl;
                cerr << ssize(connected_roads) << endl;
                assert(false);
            }
            color[i] = {cur_color[seg_a], cur_color[seg_b]};
            output.emplace_back(pair{seg_a, seg_b}, color[i]);
        }
    }

    cout << ssize(output) << "\n";
    for (const auto& [segments, col] : output) {
        cout << segments.first + 1 << " " << segments.second + 1 << " "
             << color_name[col.first] << " " << color_name[col.second] << '\n';
    }

    return 0;
}
