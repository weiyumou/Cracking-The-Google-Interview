//
//  main.cpp
//  Cracking The Google Interview
//
//  Created by Yumou Wei on 21/12/16.
//  Copyright © 2016 Ubique. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include "bst.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    
    srand(100);
    const int SIZE = 10;
    const int RANGE = 100;
    
    BSTNode *root = nullptr;

    vector<int> nums;
    
    for(int i = 0; i < SIZE; ++i){
        nums.push_back(rand() % RANGE);
    }
    
    for(auto num : nums){
        BSTNode *node = new BSTNode(num);
        insertNode(root, node);
    }
    
    inOrderWalk(root);
    cout << endl;
    
    BSTNode *min = minimum(root);
    BSTNode *succ = successor(min);
    
    if(min){
        cout << min->key << ',';
    }
    while(succ){
        cout << succ->key << ',';
        succ = successor(succ);
    }
    cout << endl;
    
    stack<int> keys;
    BSTNode *max = maximum(root);
    BSTNode *pred = predecessor(max);
    
    if(max){
        keys.push(max->key);
    }
    
    while(pred){
        keys.push(pred->key);
        pred = predecessor(pred);
    }
    
    while(!keys.empty()){
        cout << keys.top() << ',';
        keys.pop();
    }
    cout << endl;
    
    deleteNode(root, root->right->left->left);
    inOrderWalk(root);
    
    cout << endl;
    return 0;
}

