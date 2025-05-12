#include <iostream>
#include "stack.h"




// functions

    // print out tree in-order traversal 

    void inOrder(TreeNode* node){
        if(node == nullptr){
            return;
        }

        inOrder(node->left_child);

        std::cout << node->val << " " ;

        inOrder(node->right_child);

        return;
    }

    // print out tree pre-order traversal

    void preOrder(TreeNode *node){
        if(node == nullptr){
            return;
        }

        std::cout << node->val << " ";

        preOrder(node->left_child);


        preOrder(node->right_child);
        
        return;
    }

    // print out tree post-order traversal

    void postOrder(TreeNode *node){
        if(node == nullptr){
            return;
        }

        postOrder(node->left_child);

        postOrder(node->right_child);

        std::cout << node->val << " " ;
        
        return;
    }

    TreeNode * postOrderStack(TreeNodeStack *stackp, TreeNode *node){



        if(node == nullptr){
            return nullptr ;
        }

        stackp->push(postOrderStack(stackp,node->left_child));

        stackp->push(postOrderStack(stackp,node->right_child));

        
        return node;
        

        
    }


    // search for node value

    bool searchNode(TreeNode *root,int val){

        if (root->val == val){
            // if root val is equal to val
            std::cout << "Found: " << root->val << std::endl; 
            return true;
        }
        TreeNodeStack stack;
        postOrderStack(&stack,root);


        while(!stack.isEmpty()){
            TreeNode * currentNode =stack.pop();

            if(currentNode->val == val){
                std::cout << "Found: " << currentNode->val << std::endl; 
                return true;
            }
        }

        std::cout<< "Not found" << std::endl;
        return false;

    }



    




int main()
{

    TreeNode root(1);
    TreeNode Node2(2);
    TreeNode Node3(3);
    TreeNode Node4(4);
    TreeNode Node5(5);


    

    root.left_child = &Node2;
    root.right_child = &Node3;

    Node2.left_child = &Node4;
    Node2.right_child = &Node5;

    std::cout << "In Order ";
    inOrder(&root);
    std::cout << std::endl ;
    std::cout << "pre Order ";
    preOrder(&root);
    std::cout << std::endl ;
    std::cout << "post Order ";
    postOrder(&root);
    std::cout << std::endl;

    searchNode(&root,5);


    
    return 0 ;
}