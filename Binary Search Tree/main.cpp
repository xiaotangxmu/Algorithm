#include <iostream>
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node
{
    Node *lchild;
    Node *rchild;
    char data;
} node;

node *create(queue<char> &q)
{
    if (q.empty())
        return NULL;
    char c = q.front();
    q.pop();
    if (c == '#')
        return NULL;
    node *n = new node;
    n->data = c;
    n->lchild = create(q);
    n->rchild = create(q);
    return n;
}

void order(node *n)
{
    if (!n)
        return;
    cout << n->data << " ";
    order(n->lchild);
    order(n->rchild);
}

node *findleftmax(node *root)
{
    root = root->lchild;
    while (root->rchild)
        root = root->rchild;
    return root;
}

node *findrightmin(node *root)
{
    root=root->rchild;
    while (root->lchild)
        root = root->lchild;
    return root;
}

void deleteNode(node *&root, char c)
{
    if (!root)
        return;
    if (root->data == c)
    {
        if (!root->lchild && !root->rchild)
        {
            node *temp = root;
            root = NULL;
            delete (temp);
            return;
        }
        if (root->lchild)
        {
            node* t = findleftmax(root);
            root->data = t->data;
            deleteNode(root->lchild,t->data);
        }
        else if (root->rchild)
        {
            node* t = findrightmin(root);
            root->data = t->data;
            deleteNode(root->rchild,t->data);
        }
    }
    else if (root->data > c)
        deleteNode(root->lchild, c);
    else
        deleteNode(root->rchild, c);
}

int main()
{
    queue<char> q;
    string data;
    cin >> data;
    for (int i = 0; i < data.size(); ++i)
    {
        q.push(data[i]);
    }

    node *root = create(q);
    order(root);
    cout<<endl;
    deleteNode(root,'g');
    order(root);
    return 0;
}