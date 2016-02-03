#include <iostream>
using namespace std;
/*
Given a binary tree t and two elements of the tree, 
m and n, with m < n, find the lowest element of the tree 
(farthest from the root) that is an ancestor of both m and n.
*/
typedef struct BinaryTree{
    size_t* parent = NULL; 
    size_t* rhs = NULL;  
    size_t* lhs = NULL;  
}BT;

bool 
isAncestor(BT A, BT B){
    if(B == NULL) 
        return False;
    return (A = B || isancestor(A, B.parent))
}

BT 
lowestCommon(BT A,BT B){
    if(!A || !B)
        return;
    if(isAncestor(A, B)){
        return A;
    }
    else 
        return lowestCommon(A.parent, B)
}
int
main(void){
    BT binary;
    binary->rhs = A;
    binary->lhs = B;
    lowestCommon(A,B);
}