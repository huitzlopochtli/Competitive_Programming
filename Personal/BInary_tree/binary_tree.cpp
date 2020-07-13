#include <iostream>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

class Btree
{
public:
    node *root;

    Btree();
    ~Btree();

    void insert(int key);
    node *search(int key);
    void destroy();
    int height(node *root);
    bool isBalanced(node *root);

private:
    void insert(int key, node *root);
    node *search(int key, node *root);
    void destroy(node *root);

};

int Btree::height(node *root)
{
    if (root == NULL)
        return -1;
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return lHeight > rHeight ? 1 + lHeight : 1 + rHeight;
}

bool Btree::isBalanced(node *root)
{
    if (root == NULL)
        return true;
    else
    {
        return (abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
}

Btree::Btree() { root = NULL; }

Btree::~Btree() { destroy(); }

void Btree::destroy(node *leaf)
{
    if (leaf != NULL)
    {
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
    }
}

void Btree::insert(int key, node *root)
{
    if (key < root->value)
    {
        if (root->left != NULL)
            insert(key, root->left);
        else
        {
            root->left = new node;
            root->left->value = key;
            root->left->left = NULL;
            root->left->right = NULL;
        }
    }
    else if (key > root->value)
    {
        if (root->right != NULL)
            insert(key, root->right);
        else
        {
            root->right = new node;
            root->right->value = key;
            root->right->left = NULL;
            root->right->right = NULL;
        }
    }
}

node *Btree::search(int key, node *root)
{
    if (root != NULL)
    {
        if (key == root->value)
            return root;
        else if (key < root->value)
            return search(key, root->left);
        else
            return search(key, root->right);
    }
    return NULL;
}

// Public methods
void Btree::insert(int key)
{
    if (root != NULL)
        insert(key, root);
    else
    {
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *Btree::search(int key)
{
    return search(key, root);
}

void Btree::destroy()
{
    destroy(root);
}

int main()
{
    int height;
    cin >> height;
    Btree btree = Btree();

    for (int i = 0; i < height; i++)
    {
        int c;
        cin >> c;
        btree.insert(c);
    }

    cout << (btree.isBalanced(btree.root) ? "true" : "false" ) << endl;
    return 0;
}