//
//  bst.h
//  Cracking The Google Interview
//
//  Created by Yumou Wei on 21/12/16.
//  Copyright © 2016 Ubique. All rights reserved.
//

#ifndef bst_h
#define bst_h

class BSTNode{
public:
    int key;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;
    BSTNode(int value) : key(value), left(nullptr),
        right(nullptr), parent(nullptr) {};
};

void insertNode(BSTNode *&root, BSTNode *node);
void deleteNode(BSTNode *&root, BSTNode *node);
void transplant(BSTNode *&root, BSTNode *r_node, BSTNode *node);
void inOrderWalk(BSTNode *root);
BSTNode *maximum(BSTNode *root);
BSTNode *minimum(BSTNode *root);
BSTNode *successor(BSTNode *node);
BSTNode *predecessor(BSTNode *node);
#endif /* bst_h */
