#include <iostream>
using namespace std;


template <class T>
binTree<T>::treeNode::treeNode(T in_data){
    this->data = T(in_data);
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}


template <class T>
T binTree<T>::treeNode::get_data() const{
    return this->data;
}


template <class T>
binTree<T>::binTree(){
    this->root = NULL;
    this->count = 0;
}


template <class T>
void binTree<T>::insert(const T &val){
    if(!this->root) {
        this->root = new treeNode(val);
        this->count += 1;
        return;
    }
    if(this->exists(val)) return;
    treeNode * currentNode = this->root;
    while( (val < currentNode->get_data() && currentNode->left!=NULL) ||
           (val > currentNode->get_data() && currentNode->right!=NULL)  ){
        if (val < currentNode->get_data()) currentNode = currentNode->left; 
        else currentNode = currentNode->right;  
    }
    treeNode * newNode = new treeNode(val);
    if (val < currentNode->get_data()){
        currentNode->left = newNode;
        newNode->parent = currentNode;
        this->count += 1;
    }
    else { 
        currentNode->right = newNode;
        newNode->parent = currentNode;
        this->count += 1;
    }
}


template <class T>
bool binTree<T>::exists(const T &val) const{
    treeNode * currentNode = this->root;
    bool result = false;
    while(currentNode!=NULL){
        if(val == currentNode->get_data()){
            result = true;
            break;
        } 
        else if (val < currentNode->get_data()) currentNode = currentNode->left;
        else currentNode = currentNode->right;
    }
    return result;
}


template <class T>
int binTree<T>::size() const{
    return this->count;
}


/*find next node in traverse by current and prev node*/
template <class T>
typename binTree<T>::treeNode * binTree<T>::traverse_next(treeNode * currentNode, treeNode * previousNode) const{
    treeNode * nextNode = NULL;

    /*case1. walk down*/
    if(previousNode == NULL || previousNode->left == currentNode || previousNode->right == currentNode){
        if(currentNode->left != NULL) nextNode = currentNode->left;
        else if(currentNode->left == NULL && currentNode->right != NULL) nextNode = currentNode->right;
        /*begin walk up*/
        else if(currentNode->left == NULL && currentNode->right == NULL) nextNode = currentNode->parent;
    }

    /*case2. walk up from left*/
    else if(currentNode->left == previousNode){
        if(currentNode->right != NULL) nextNode = currentNode->right;
        /*begin walk up*/
        else if(currentNode->right == NULL) nextNode = currentNode->parent;
    }

    /*case3. walk up from right, in this case, next step can only walk up*/
    else if(currentNode->right == previousNode) nextNode = currentNode->parent;

    return nextNode;
 }
  

/*determine if a visit is a preorder output*/
template <class T>
bool binTree<T>::is_preorder(treeNode * currentNode, treeNode * previousNode) const{
    bool result = false;
    /*in preorder, all and only walk down case output the node*/
    if(previousNode == NULL || previousNode->left == currentNode || previousNode->right == currentNode){
        result = true;
    }
    return result;
}


/*determine if a visit is a inorder output*/
template <class T>
bool binTree<T>::is_inorder(treeNode * currentNode, treeNode * previousNode) const{

    bool result = false;

    /*case1. walk down to node with no left child*/
    if(currentNode->left == NULL && 
      (previousNode == NULL || previousNode->left == currentNode || previousNode->right == currentNode) ){
        result = true;
    }

    /*case2. walk up from left*/
    else if(currentNode->left == previousNode) result = true;
    
    return result;
}


/*determine if a visit is a postorder output*/
template <class T>
  bool binTree<T>::is_postorder(treeNode * currentNode, treeNode * previousNode) const{

    bool result = false;

    /*case1. walk down to leaf*/
    if(previousNode == NULL || previousNode->left == currentNode || previousNode->right == currentNode){
      if(currentNode->left == NULL && currentNode->right == NULL) result = true;
    }

    /*case2. walk up from right*/
    else if(currentNode->right == previousNode) result = true;
    
    /*case3. walk up from left to node which have no right child*/
    else if(currentNode->left == previousNode){
      if(currentNode->right == NULL) result = true;
    }

    return result;
  }


template <class T>
void binTree<T>::preorder(T * arr, int ARRAY_SIZE) const{
    if(ARRAY_SIZE < this->count) return;
    if(this->root == NULL) return;

    treeNode * currentNode = this->root;
    treeNode * previousNode = NULL;
    int visitCounter = 0;

    while(visitCounter < this->count){      
        if(this->is_preorder(currentNode,previousNode)){
            arr[visitCounter] = currentNode->get_data();
            visitCounter += 1;
        }
        treeNode * nextNode = this->traverse_next(currentNode,previousNode);
        previousNode = currentNode;
        currentNode = nextNode;
    }
}


template <class T>
void binTree<T>::inorder(T * arr, int ARRAY_SIZE) const{
    if(ARRAY_SIZE < this->count) return;
    if(this->root == NULL) return;

    treeNode * currentNode = this->root;
    treeNode * previousNode = NULL;
    int visitCounter = 0;

    while(visitCounter < this->count){
        if(this->is_inorder(currentNode,previousNode)){
            arr[visitCounter] = currentNode->get_data();
            visitCounter += 1;
        }
        treeNode * nextNode = this->traverse_next(currentNode,previousNode);
        previousNode = currentNode;
        currentNode = nextNode;
    }
}


template <class T>
void binTree<T>::postorder(T * arr, int ARRAY_SIZE) const{
    if(ARRAY_SIZE < this->count) return;
    if(this->root == NULL) return;

    treeNode * currentNode = this->root;
    treeNode * previousNode = NULL;
    int visitCounter = 0;

    while(visitCounter < this->count){
        if(this->is_postorder(currentNode,previousNode)){
            arr[visitCounter] = currentNode->get_data();
            visitCounter += 1;
        }
        treeNode * nextNode = this->traverse_next(currentNode,previousNode);
        previousNode = currentNode;
        currentNode = nextNode;
    }
}