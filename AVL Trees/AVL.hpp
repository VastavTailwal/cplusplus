#pragma once


#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;
    int height = 1;
}*root = NULL;


class AVL
{
private:
    int updateHeight(Node*);
    int balanceFactor(Node*);
    Node* predecessor(Node*);
    Node* successor(Node*);
    Node* rotateLL(Node*);
    Node* rotateLR(Node*);
    Node* rotateRL(Node*);
    Node* rotateRR(Node*);
public:
    Node* insert(Node*, const int);
    int height(Node*);
    int countNodes(Node*);
    void inorder(Node*);
    Node* remove(Node*, const int);
};