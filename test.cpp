#include <iostream>
#include "bintree.h"

using namespace std;

int main()
{
    binTree<int> tree;
    int nums[] = {3, 2 , -1 , 1 , 8 , 4 , 6,  5 , 9, -2};
    for(int i = 0; i < sizeof(nums) / sizeof(int); i++){
        tree.insert(nums[i]);
        cout<<"Inserted "<<nums[i]<<endl;
    }

    const int ARRAY_SIZE = 32;
    int arr[ARRAY_SIZE];

    cout << "\nPreorder:" << endl;
    tree.preorder(arr,ARRAY_SIZE);
    for(int i = 0; i < tree.size(); i++){
        cout<<" "<< arr[i];
    }

    cout << "\nInorder:" << endl;
    cout<<endl;
        tree.inorder(arr,ARRAY_SIZE);
    for(int i = 0; i < tree.size(); i++){
        cout<<" "<< arr[i];
    }

    cout << "\nPostorder:" << endl;
    cout<<endl;
        tree.postorder(arr,ARRAY_SIZE);
    for(int i = 0; i < tree.size(); i++){
        cout<<" "<< arr[i];
    }
    cout<<endl;
}