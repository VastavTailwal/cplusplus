#include "AVL.hpp"


Node* AVL::insert(Node* p, const int key)
{
    if(root == NULL)
    {
        root = new Node;
        root->data = key;
        return root;
    }
    if(p == NULL)
    {
        Node* temp = new Node;
        temp->data = key;
        return temp;
    }
    if(key < p->data)
    {
        p->left = insert(p->left, key);
    }
    else if(key > p->data)
    {
        p->right = insert(p->right, key);
    }
    else
    {
        throw "EXCEPTION :KEY ALREADY EXIST\n";
    }
    p->height = updateHeight(p);
    if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
        return rotateLL(p);
    if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return rotateLR(p);
    if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
        return rotateRR(p);
    if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
        return rotateRL(p);
    return p;
}


Node* AVL::rotateLL(Node* p)
{
    Node* pl = p->left;
    Node* plr = p->left->right;
    p->left = plr;
    pl->right = p;
    p->height = updateHeight(p);
    pl->height = updateHeight(pl);
    if(p == root)
    {
        root = pl;
    }
    return pl;
}


Node* AVL::rotateRR(Node* p)
{
    Node* pr = p->right;
    Node* prl = p->right->left;
    p->right = prl;
    pr->left = p;
    p->height = updateHeight(p);
    pr->height = updateHeight(pr);
    if(p == root)
    {
        root = pr;
    }
    return pr;
}


Node* AVL::rotateLR(Node* p)
{
    Node* pl = p->left;
    Node* plr = p->left->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    p->height = updateHeight(p);
    pl->height = updateHeight(pl);
    plr->height = updateHeight(plr);
    if(p == root)
    {
        root = plr;
    }
    return plr;
}


Node* AVL::rotateRL(Node* p)
{
    Node* pr = p->right;
    Node* prl = p->right->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->left = p;
    prl->right = pr;
    p->height = updateHeight(p);
    pr->height = updateHeight(pr);
    prl->height = updateHeight(prl);
    if(p == root)
    {
        root = prl;
    }
    return prl;
}


void AVL::inorder(Node* p)
{
    if(p != NULL)
    {
        inorder(p->left);
        cout<<p->data<<endl;
        inorder(p->right);
    }
    return;
}


int AVL::height(Node* p)
{
    if(p != NULL)
    {
        int x = height(p->left);
        int y = height(p->right);
        return x > y ? x + 1 : y + 1;
    }
    return 0;
}


int AVL::countNodes(Node* p)
{
    if(p != NULL)
    {
        int x = countNodes(p->left);
        int y = countNodes(p->right);
        return x + y + 1;
    }
    return 0;
}


int AVL::updateHeight(Node* p)
{
    int rightHeight = p && p->right ? p->right->height : 0;
    int leftHeight = p && p->left ? p->left->height : 0;
    return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
}


int AVL::balanceFactor(Node* p)
{
    int rightHeight = p && p->right ? p->right->height : 0;
    int leftHeight = p && p->left ? p->left->height : 0;
    return leftHeight - rightHeight;
}


Node* AVL::predecessor(Node* p)
{
    while(p && p->right)
    {
        p = p->right;
    }
    return p;
}


Node* AVL::successor(Node* p)
{
    while(p && p->left)
    {
        p = p->left;
    }
    return p;
}


Node* AVL::remove(Node* p, const int key)
{
    if(p == NULL)
    {
        return NULL;
    }
    if(p->left == NULL && p->right == NULL)
    {
        if(p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if(key < p->data)
    {
        p->left = remove(p->left, key);
    }
    else if(key > p->data)
    {
        p->right = remove(p->right, key);
    }
    else
    {
        if(height(p->left) > height(p->right))
        {
            Node* q = predecessor(p->left);
            p->data = q->data;
            p->left = remove(p->left, q->data);
        }
        else
        {
            Node* q = successor(p->right);
            p->data = q->data;
            p->right = remove(p->right, q->data);
        }
    }
    p->height = updateHeight(p);
    if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
        return rotateLL(p);
    if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return rotateLR(p);
    if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
        return rotateRR(p);
    if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
        return rotateRL(p);
    return p;
}