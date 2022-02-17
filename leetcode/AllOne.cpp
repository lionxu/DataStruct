#include <string>
#include <list>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Node {
public:
    int val;
    unordered_set<string> keys;
    explicit Node(int val) : val(val) { keys.clear(); }
};

class AllOne {
public:
    AllOne() = default;

    void inc(const string& key) {
        list<Node>::iterator next_node;

        if (key2iterator.find(key) != key2iterator.end()) {
            auto current_node = key2iterator[key];

            next_node = next(current_node, 1);

            if (next_node == nodes.end() || next_node->val > current_node->val + 1) {
                next_node = nodes.insert(next_node, Node(current_node->val + 1));
            }

            current_node->keys.erase(key);
            if (current_node->keys.empty()) {
                nodes.erase(current_node);
            }
        } else {
            next_node = nodes.begin();
            if (nodes.empty() || nodes.begin()->val != 1) {
                next_node = nodes.insert(nodes.begin(), Node(1));
            }
        }

        next_node->keys.insert(key);
        key2iterator[key] = next_node;
    }

    void desc(const string& key) {
        if (key2iterator.find(key) != key2iterator.end()) {
            auto current_node = key2iterator[key];
            if (current_node->val > 1) {
                auto last_node = next(current_node, - 1);
                if (current_node == nodes.begin() || last_node->val < current_node->val - 1) {
                    last_node = nodes.insert(current_node, Node(current_node->val - 1));
                }
                last_node->keys.insert(key);
                key2iterator[key] = last_node;
            } else {
                key2iterator.erase(key);
            }

            current_node->keys.erase(key);
            if (current_node->keys.empty()) {
                nodes.erase(current_node);
            }
        }
    }

    string getMaxKey() {
        return nodes.empty() ? "" : *(nodes.rbegin()->keys.begin());
    }

    string getMinKey() {
        return nodes.empty() ? "" : *(nodes.begin()->keys.begin());
    }

private:
    unordered_map<string, list<Node>::iterator> key2iterator;
    list<Node> nodes;
};

int main() {
    auto* allOne = new AllOne();
    allOne->inc("hello");
    allOne->inc("hello");

    cout << allOne->getMaxKey() << endl;
    cout << allOne->getMinKey() << endl;

    allOne->inc("leet");
    cout << allOne->getMaxKey() << endl;
    cout << allOne->getMinKey() << endl;

    return 0;
}
