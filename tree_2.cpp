#include <iostream>

class BaseTree{
public:
  int val;
  BaseTree* right;
  BaseTree* left;
  BaseTree(){
  right = NULL;
  left = NULL;
  }
  BaseTree* createNodes(int);
};

BaseTree* BaseTree::createNodes(int value){
  BaseTree* newNode=new BaseTree();

  if(newNode){
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = value;
  }
  return newNode;
}

void displayTree(BaseTree* root){

  if(root==nullptr){
    std::cout << "empty !!!" <<std::endl;
    return;
  }
  std::cout << "value : " <<root->val << std::endl;
  std::cout <<"left node : ";
  displayTree(root->left);
  std::cout <<"Right node : ";
  displayTree(root->right);
  std::cout <<"next level \n" ;
}

bool insertNode(BaseTree** rootPtr, int value){
  BaseTree* root = *rootPtr;
  if(root==NULL){
    (*rootPtr) = root->createNodes(value);
    return true;
  }
  if(value == root->val){
    //node exists
    return false;
  }
  if (value < root->val){
    return insertNode(&(root->left),value);
  }else{
    return insertNode(&(root->right),value);
  }
}

bool findNode(BaseTree* root,int value){
  if (root == NULL) {
    return false;
  }
  if(root->val == value){
    return true;
  }
  if (value < root->val){
    return findNode(root->left,value);
  }else {
    return findNode(root->right, value);
  }
}


// min with recursion
int minTree(BaseTree* root){
  if (root==NULL){
    std::cout << "Tree is empty !!! " << std::endl;
    return -1;
  }else if (root->left==NULL){
    return root->val;
  }
  return minTree(root->left);
}

// max without recursion
int maxTree(BaseTree* root){
  if (root==NULL){
    std::cout << "Tree is empty !!! " << std::endl;
    return -1;
  }
  BaseTree* currentNode= root;
  while(currentNode->right!=NULL){
    currentNode = currentNode->right;
  }
  return currentNode->val;
}

int main(){
BaseTree* temp;
BaseTree* temp2;
BaseTree* n1 = temp->createNodes(15);
BaseTree* n2 = temp->createNodes(10);
BaseTree* n3 = temp->createNodes(20);
BaseTree* n4 = temp->createNodes(8);
BaseTree* n5 = temp->createNodes(12);
BaseTree* n6 = temp->createNodes(17);
BaseTree* n7 = temp->createNodes(25);

n1->left = n2;
n1->right = n3;
n2->left = n4;
n2->right = n5;
n3->left = n6;
n3->right =n7;

displayTree(n1);
insertNode(&n1, 60);
displayTree(n1);
insertNode(&n1, 15);
displayTree(n1);

if(findNode(n1,15)){
 std::cout<< "Node has been found"  << std::endl;
}else{
  std::cout<< "Node has not been found"  << std::endl;
}


std::cout << " Min : " << minTree(n1) <<std::endl;
std::cout << " Max: " << maxTree(n1) <<std::endl;
delete n1;
delete n2;
delete n3;
delete n4;
delete n5;
delete n6;
delete n7;


return 0;

}
