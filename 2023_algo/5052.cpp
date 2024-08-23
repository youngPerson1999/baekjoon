#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Trie {
    bool finish;
    Trie* next[10];
    Trie() : finish(false) {
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
    ~Trie() {
        for (int i = 0; i < 10; i++)
            if (next[i])
                delete next[i];
    }
    void insert(string key) {
        if (key.size() == 0)
            finish = true;
        else {
            int curr = key[0] - '0';
            if (next[curr] == NULL)
                next[curr] = new Trie();
            next[curr]->insert(key.substr(1));
        }
    }
    bool find(string key) {
        Trie* curr = this;  // 현재 Trie 노드를 가리키는 포인터
        int size = key.size();
        for (int i = 0; i < size; i++)
        {
            int index = key[i] - '0';
            if (curr->next[index] == NULL) {
                return false; // Trie에서 문자열을 찾지 못함
            }
            curr = curr->next[index];
        }
        return true;  // 문자열의 끝까지 탐색한 후, finish 상태를 반환
    }
};

bool cmp_length(string a, string b) {
    return a.size() > b.size();
}

void program() {
    int n;
    cin >> n;
    vector<string> phone(n);
    for (int i = 0; i < n; i++) {
        cin >> phone[i];
    }
    sort(phone.begin(), phone.end(), cmp_length);
    Trie root;
    bool foundDuplicate = false;

    for (int i = 0; i < n; i++) {
        // cout<<phone[i]<<"\n";
        if (root.find(phone[i])) {
            foundDuplicate = true;
            break;
        }
        root.insert(phone[i]);
    }
    if (!foundDuplicate) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        program();
    return 0;
}
