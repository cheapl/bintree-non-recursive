#ifndef BIN_TREE_H
#define BIN_TREE_H

template <class T>
class binTree {
private:
  
    class treeNode {
    private:
        T data;
    public:
        treeNode * left;
        treeNode * right;
        treeNode * parent;
        treeNode(T);
        T get_data() const;
    };
    treeNode * root;
    int count;

public:
    binTree();

    void insert(const T &val);
    bool exists(const T &val) const;
    int size() const;

    treeNode * traverse_next(treeNode *, treeNode *) const;
    
    bool is_preorder(treeNode *, treeNode *) const;
    bool is_inorder(treeNode *, treeNode *) const;
    bool is_postorder(treeNode*, treeNode*) const;

    void preorder(T *, int) const;
    void inorder(T *, int) const;
    void postorder(T *, int) const;
};

#include "bintree.hpp"

#endif
