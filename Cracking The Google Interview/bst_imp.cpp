//
//  bst_imp.cpp
//  Cracking The Google Interview
//
//  Created by Yumou Wei on 21/12/16.
//  Copyright © 2016 Ubique. All rights reserved.
//

#include "bst.h"
#include <iostream>
using namespace std;

void inOrderWalk(BSTNode *root){
    if(!root){
        return;
    }
    inOrderWalk(root->left);
    cout << root->key << ',';
    inOrderWalk(root->right);
}

void insertNode(BSTNode *&root, BSTNode *node){
    
    if(!root){
        root = node;
        return;
    }
    BSTNode *curr = root, *prev = root;
    while(curr){
        prev = curr;
        if(node->key < curr->key){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    node->parent = prev;
    if(node->key < prev->key){
        prev->left = node;
    }else{
        prev->right = node;
    }
}

void deleteNode(BSTNode *&root, BSTNode *node){
    if(!node){
        return;
    }
    
    if(!node->left){
        transplant(root, node, node->right);
    }else if(!node->right){
        transplant(root, node, node->left);
    }else{
        BSTNode *min = minimum(node->right);
        if(min->parent != node){
            transplant(root, min, min->right);
            min->right = node->right;
            min->right->parent = min;
        }
        transplant(root, node, min);
        min->left = node->left;
        min->left->parent = min;
    }
    
}

void transplant(BSTNode *&root, BSTNode *r_node, BSTNode *node){
    BSTNode *p = r_node->parent;
    
    if(!p){
        root = node;
        return;
    }
    
    if(p->left == r_node){
        p->left = node;
    }else{
        p->right = node;
    }
    
    if(node){
        node->parent = p;
    }
}

BSTNode *maximum(BSTNode *root){
    while(root && root->right){
        root = root->right;
    }
    return root;
}
BSTNode *minimum(BSTNode *root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

BSTNode *successor(BSTNode *node){
    if(!node){
        return nullptr;
    }else if(node->right){
        return minimum(node->right);
    }
    BSTNode *p = node->parent;
    while(p && p->right == node){
        node = p;
        p = p->parent;
    }
    return p;
}
BSTNode *predecessor(BSTNode *node){
    if(!node){
        return nullptr;
    }else if(node->left){
        return maximum(node->left);
    }
    BSTNode *p = node->parent;
    while(p && p->left == node){
        node = p;
        p = p->parent;
    }
    return p;
}
