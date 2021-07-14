#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
class Node {
public:
    string str;
    unordered_map<char, Node *> map;
    unordered_map<char, int> unique_table;
    int maxUnique;
    Node(string s) {
        maxUnique = 0;
        str = s;
        for (char chr : str) {
            unique_table[chr]++;
            maxUnique = max(maxUnique, unique_table[chr]);
        }
    }

    Node(Node *node, char chr) {
        str = node->str;
        str.push_back(chr);
        unique_table = node->unique_table;
        unique_table[chr]++;
        maxUnique = max(maxUnique, unique_table[chr]);
    }
};

class Tree {
public:
    char End = '*';
    Node *root;
    int maxUnique = 0;
    int minLength = 0;
    int maxLength = 0;
    unordered_map<string, int> ans;
    int max_ans = 0;
    bool satisfy (Node *node) {
        string str = node->str;
        return (str.size() >= minLength) && 
        (str.size() <= maxLength) && 
        (node->maxUnique <= maxUnique);
    }

    Tree(int minLength, int maxLength, int maxUnique) {
        root = new Node("");
        this->minLength = minLength;
        this->maxLength = maxLength;
        this->maxUnique = maxUnique;
    }

    void insert(string str) {
        Node *ptr = root;
        for (char chr : str) {
            if (ptr->map.end() == ptr->map.find(chr)) {
                ptr->map[chr] = new Node(ptr, chr);
                ptr = ptr->map[chr];
            }
            else {
                ptr = ptr->map[chr];
            }
            if (satisfy(ptr)) {
                ans[ptr->str] = 1;
                max_ans = max(max_ans, ptr->maxUnique);
            }
        }
        ptr->map[End] = nullptr;
        
    }
};
int getMaxOccurences(string components, int minLength, int maxLength, int maxUnique) {
    Tree *tree = new Tree(minLength, maxLength, maxUnique);
    for (int i = 0; i < components.size(); i++) {
        string substring = string(components.begin() + i, components.end());
        tree->insert(substring);
    }
    return tree->max_ans;
}

int main() {
    cout << getMaxOccurences("abcde", 2, 4, 26) << "\n";
}