//PAT A1053

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MAX 100
using namespace std;

typedef struct Node
{
    int w;
    vector<int> child;
} node;

int N;
int M;
int S;
node n[MAX];
vector<int> path;

bool cmp(int a, int b)
{
    return n[a].w > n[b].w;
}

void DFS(int root, int sum)
{
    int w = n[root].w;
    path.push_back(w);
    sum += w;
    if (n[root].child.empty() && sum == S)
    {
        for (int i = 0; i < path.size() - 1; ++i)
        {
            cout << path[i] << " ";
        }
        cout << path[path.size() - 1] << endl;
    }
    for (int i = 0; i < n[root].child.size(); ++i)
    {
        DFS(n[root].child[i], sum);
    }
    path.pop_back();
}

int main()
{
    //freopen("E:/in.txt", "r", stdin);
    cin >> N >> M >> S;
    for (int i = 0; i < N; ++i)
    {
        cin >> n[i].w;
        n[i].child.clear();
    }

    int temp = 0, num = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> temp >> num;
        n[temp].child.resize(static_cast<unsigned int>(num));
        for (int j = 0; j < num; ++j)
        {
            cin >> n[temp].child[j];
        }
        sort(n[temp].child.begin(), n[temp].child.end(), cmp);
    }
    DFS(0, 0);
    return 0;
}