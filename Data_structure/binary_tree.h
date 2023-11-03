#pragma once
#include <iostream>

template<class T>
struct Node
{
    T data;
    Node* left;
    Node* right;
    
    Node(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template<class T>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = nullptr;
    }

    Node<T>* get_root()
    {
        return root;
    }

    void insert(int value)
    {
        if (root == nullptr)
            root = new Node<T>(value);
        else
            insertRecursive(root, value);
    }

    void insertRecursive(Node<T>* currentNode, int value) {
        if (value < currentNode->data)
            if (currentNode->left == nullptr)
                currentNode->left = new Node<T>(value);
            else
                insertRecursive(currentNode->left, value);
        else
            if (currentNode->right == nullptr)
                currentNode->right = new Node<T>(value);
            else
                insertRecursive(currentNode->right, value);
    }

    bool search(int value)
    {
        return searchRecursive(root, value);
    }

private:

    bool searchRecursive(Node<T>* currentNode, int value)
    {
        if (currentNode == nullptr)
            return false;
        if (currentNode->data == value)
            return true;
        if (value < currentNode->data)
            return searchRecursive(currentNode->left, value);
        return searchRecursive(currentNode->right, value);
    }
    Node<T>* root;
};
