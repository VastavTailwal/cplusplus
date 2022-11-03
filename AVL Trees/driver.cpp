#include "AVL.cpp"


int main()
{
    AVL tree;
    tree.insert(root, 34);
    tree.insert(root, 53);
    tree.insert(root, 84);
    tree.insert(root, 3);
    tree.insert(root, 33);
    tree.insert(root, 67);
    tree.insert(root, 12);
    tree.insert(root, 13);
    tree.remove(root, 33);
    tree.remove(root, 34);
    tree.inorder(root);
    cout<<"Height :"<<tree.height(root)<<endl;
    cout<<"Nodes :"<<tree.countNodes(root)<<endl;
    cout<<"Root nodes's data :"<<root->data<<endl;
    return 0;
}