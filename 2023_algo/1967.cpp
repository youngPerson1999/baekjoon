#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// typedef struct node{
//     int num;
//     vector<int> weights;
//     vector<struct node*> children;
//     vector<int> maxs;
// } NODE;

// typedef struct tree{
//     NODE *root;
// } TREE;

// NODE *make_node(int n){
//     NODE *tmp = new NODE;
//     tmp->num = n;
//     return tmp;
// }

// NODE *dfs(NODE *curr, int num){
//     if(curr == nullptr)
//         return nullptr;
//     if(curr->num == num)
//         return curr;
//     int size = curr->weights.size();
//     for (int i = 0; i < size; i++){
//         NODE *tmp = dfs(curr->children[i], num);
//         if(tmp != nullptr)
//             return tmp;
//     }
//     return nullptr;
// }

// int weight_dfs(NODE *curr, int num){
//     if(curr == nullptr || curr->children.size() == 0)
//         return 0;
//     int all_max = 0, size = curr->children.size();
//     for (int i = 0; i < size; i++){
//         int tmp_max = weight_dfs(curr->children[i], num) + curr->weights[i];
//         all_max = tmp_max > all_max ? tmp_max : all_max;
//         if(curr->num == num){
//             curr->maxs.push_back(tmp_max);
//         }
//     }
//     if(curr->num == num){
//         sort(curr->maxs.rbegin(), curr->maxs.rend());
//         if (curr->maxs.size() > 1)
//             return curr->maxs[0] + curr->maxs[1];
//         else if(curr->maxs.size() == 0)
//             return 0;
//         else
//             return curr->maxs[0];
//     }
//     return all_max;
// }

// void preorder(NODE * curr){
//     if(curr==nullptr)
//         return;
//     cout << curr->num << "->";
//     int size = curr->children.size();
//     for (int i = 0; i < size; i++){
//         preorder(curr->children[i]);
//     }
// }

// int main()
// {
//     int n, p, c, w;
//     cin >> n;
//     if(n==1){
//         cout << 0<<"\n";
//         return 0;
//     }
//     TREE *tree = new TREE;
//     tree->root = nullptr;
//     for (int i = 1; i < n; i++)
//     {
//         cin >> p >> c >> w;
//         NODE *p_node = dfs(tree->root, p);
//         if (p_node == nullptr)   //부모노드가 없을떄 == root가 없을때
//         {
//             tree->root = make_node(p);
//             tree->root->weights.push_back(w);
//             tree->root->children.push_back(make_node(c));
//         }
//         else{   //부모노드는 있음
//             p_node->weights.push_back(w);
//             p_node->children.push_back(make_node(c));
//         }
//     }
//     // preorder(tree->root);
//     int max = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         NODE *curr = dfs(tree->root, i);
//         if(curr == nullptr && curr->children.size() == 0)
//             continue;
//         int tmp = weight_dfs(curr, i);
//         max = tmp > max ? tmp : max;
//     }
//     cout << max << "\n";
//     return 0;
// }

int n;
vector<vector<pair<int, int> > > tree;
vector<bool> visited;
int sol = 0;
void dfs(int s, int v){
    // cout<<" s: " << s << ", v: "<<v;
    if(v > sol)
        sol = v;
    visited[s] = true;
    int size = tree[s].size();
    for (int i = 0; i < size; i++){
        pair<int, int> t = tree[s][i];
        if (!visited[t.first]){
            dfs(t.first, v + t.second);
        }
    }
}
int main()
{
    cin >> n;
    tree.resize(n);
    visited.resize(n, false);
    int p, c, w;
    for (int i = 1; i < n; i++)
    {
        cin >> p >> c >> w;
        tree[p - 1].push_back(make_pair(c - 1, w));
        tree[c - 1].push_back(make_pair(p - 1, w));
    }
    for (int i = 0; i < n; i++)
    {
        fill_n(visited.begin(), n, false);
        dfs(i, 0);
    }
    cout << sol <<"\n";
    return 0;
}