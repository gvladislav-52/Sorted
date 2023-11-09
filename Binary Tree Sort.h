#ifndef WORK_BINARY_TREE_SORT_H
#define WORK_BINARY_TREE_SORT_H
#include <iostream>
using std::cout;

class Binary_Tree_Sort
{
private:
    struct Node
    {
        int date;
        Node * left;
        Node * right;

        Node (int value): date(value), left(nullptr), right(nullptr) {}
    };

public:
    Node * root;

    Binary_Tree_Sort():root(nullptr) {}

    Node * add(Node * root, int value)
    {
        if(root == nullptr) return new Node(value);

        if(value < root->date)
            root->left = add(root->left, value);
        else
            root->right = add(root->right,value);
        return root;
    }

    void add (int value)
    {
        root = add(root, value);
    }

    void print(Node * root)
    {
        if(root != nullptr)
        {
            print(root->left);
            std::cout << root->date << " ";
            print(root->right);
        }
    }

    void print()
    {
        print(root);
    }
};


#endif //WORK_BINARY_TREE_SORT_H
