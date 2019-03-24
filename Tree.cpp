#include <iostream>
#include <cstdlib>
#include "Tree.hpp"
#include <stdexcept>

using namespace std;

//Constracor
ariel::Tree::Tree(){
    rootValue = NULL;
}
//Create a new leaf to the tree
ariel::Tree::node* ariel::Tree::createLeaf(int data){
    node* n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}
//Accepts as input number i and put it in 
//the appropiate place in the tree
void ariel::Tree::insert(int data){
    insertPrivate(data, rootValue);
}
//Auxiliary function to insert function
void ariel::Tree::insertPrivate(int data, node* ptr){
    //checks if the root is null
    if(rootValue == NULL){
        rootValue = createLeaf(data);
    }
    else if(data < ptr->data){
        if(ptr->left != NULL){
            insertPrivate(data, ptr->left);
        }
        else{
            ptr->left=createLeaf(data);
        }
    }
    else if(data > ptr->data){
        if(ptr->right != NULL){
            insertPrivate(data, ptr->right);
        }
        else{
            ptr->right=createLeaf(data);
        }
    }
    //throw exception if the data is in the tree
    else{
        throw std::invalid_argument( "The data is already in the tree\n" );
    }
}
//Prints the tree inorder
void ariel::Tree::print(){
    printPrivate(rootValue);
    cout << "\n";
}
//Auxiliary function to print function
void ariel::Tree::printPrivate(node* ptr){
    if(rootValue != NULL){
        //left
        if(ptr->left != NULL){
            printPrivate(ptr->left);
        }
        //parent
        cout << ptr->data <<" ";
        //right
        if(ptr->right != NULL){
            printPrivate(ptr->right);
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );
    }
}
// Return the node with the data
ariel::Tree::node* ariel::Tree::returnNode(int data){
    return returnNodePrivate(data, rootValue);
}
//Auxiliary function to returnNode function
ariel::Tree::node* ariel::Tree::returnNodePrivate(int data, node* ptr){
    if(ptr != NULL){
        if(ptr->data==data){
            return ptr;
        }
        else{
            if(data < ptr->data){
                return returnNodePrivate(data, ptr->left);
            }
            else{
                return returnNodePrivate(data, ptr->right);
            }
        }
    }
    else{
        return NULL;
    }
}

//Checks if the tree contains certain data
bool ariel::Tree::contains(int data){
    bool flag = containsPrivate(data, rootValue);
    return flag;
}
//Auxiliary function to contains function
bool ariel::Tree::containsPrivate(int data, node* ptr){
    if(ptr != NULL){
        if(ptr->data==data){
            return true;
        }
        else{
            if(data < ptr->data){
                return returnNodePrivate(data, ptr->left);
            }
            else{
                return returnNodePrivate(data, ptr->right);
            }
        }
    }
    else{
        return false;
    }
}

//Return the right child of the node with the data
int ariel::Tree::right(int data){
    node* ptr = returnNode(data);
    if(ptr != NULL){
        if(ptr->right==NULL){
            throw std::invalid_argument( "The data is not in the tree\n" );
            return -1;
        }
        else{
            return ptr->right->data;
        }
    }
    //throw exception if the data is not in the tree
    else{
        throw std::invalid_argument( "The data is not in the tree\n" );
        return -1;
    }
}
//Return the left child of the node with the data
int ariel::Tree::left(int data){
    node* ptr = returnNode(data);
    if(ptr != NULL){
        if(ptr->left==NULL){
            throw std::invalid_argument( "The data is not in the tree\n" );
            return -1;
        }
        else{
            return ptr->left->data;
        }
    }
    //throw exception if the data is not in the tree
    else{
        throw std::invalid_argument( "The data is not in the tree\n" );
        return -1;
    }

}

//Return the root value
int ariel::Tree::root(){
    if (rootValue == NULL){
        throw std::invalid_argument( "The data is not in the tree\n" );
        return -1;
    }
    else{
       return rootValue->data;
    }
}

//Find the smallest data in the tree
int ariel::Tree::findSmallest(){
    return findSmallestPrivate(rootValue);
}

//Auxiliary function to findSmallest function
int ariel::Tree::findSmallestPrivate(node* ptr){
     //checks if the root is null, if true the tree is empty
    if(rootValue == NULL){
        throw std::invalid_argument( "The data is not in the tree\n" );
        return -1;
    }
    else{
        if(ptr->left != NULL){
            return findSmallestPrivate(ptr->left);
        }
        else{
            return ptr->data;
        }
    }
}

//Return the size of the tree
int ariel::Tree::size(){
    return sizePrivate(rootValue);
}

int ariel::Tree::sizePrivate(node* ptr){
  if(ptr == NULL){
      return 0;
  }
  else{
      return (sizePrivate(ptr->left) +1+ sizePrivate(ptr->right));
  }
}
// Return the data of the parent
int ariel::Tree::parent(int data){
    return parentPrivate(data, rootValue);
}

//Auxiliary function to parent function
int ariel::Tree::parentPrivate(int data, node* ptr){
    if(rootValue != NULL && contains(data)){
        if(rootValue->data != data){
            if(data < ptr->data){
                if(ptr->left->data == data){
                    return ptr->data;
                }
                else{
                    return parentPrivate(data, ptr->left);
                }
            }
            else{
                if(ptr->right->data == data){
                    return ptr->data;
                }
                else{
                    return parentPrivate(data, ptr->right);
                }
            }
        }
        else{
            throw std::invalid_argument( "No parent, the data belong to the root\n" );
            return -1;
        }
    }
    else{
        throw std::invalid_argument( "The data was not found in the tree\n" );
        return -1;
    }
}

//Remove a node with the data from the tree
void ariel::Tree::remove(int data){
   removePrivate(data, rootValue);
}
//Auxiliary function to remove function
void ariel::Tree::removePrivate(int data, node* parent){
     //checks if the root is null, if true the tree is empty
    if(rootValue != NULL){
        if(rootValue->data == data){
            removeRoot();
        }
        else{
            if(data < parent->data && parent->left != NULL){
                if(parent->left->data == data){
                    removeMatch(parent, parent->left, true);
                }
                else{
                    removePrivate(data, parent->left);
                }
            }
            else if(data > parent->data && parent->right != NULL){
                if(parent->right->data == data){
                    removeMatch(parent, parent->right, false);
                }
                else{
                    removePrivate(data, parent->right);
                }
            }
            else{
                throw std::invalid_argument( "The data was not found in the tree\n" );  
            } 
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );  
    }
}
//Auxiliary function to remove function
void ariel::Tree::removeRoot(){
     //checks if the root is null, if true the tree is empty
    if(rootValue != NULL){
        node* delPtr = rootValue;
        int smallestInRightSubTree;

        // Case 0 - 0 Children
        if(rootValue->left == NULL && rootValue->right == NULL){
            rootValue = NULL;
            delete delPtr;
        }

        // Case 1 - 1 Child
        else if(rootValue->left == NULL && rootValue->right != NULL){
            rootValue = rootValue->right;
            delPtr->right = NULL;
            delete delPtr;
        }
        else if(rootValue->left != NULL && rootValue->right == NULL){
            rootValue = rootValue->left;
            delPtr->left = NULL;
            delete delPtr;
        }

        //Case 2 - 2 Children
        else{
            smallestInRightSubTree = findSmallestPrivate(rootValue->right);
            removePrivate(smallestInRightSubTree, rootValue);
            rootValue->data = smallestInRightSubTree;
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );  
    }
}


//Auxiliary function to remove function
void ariel::Tree::removeMatch(node* parent, node* match, bool left){
    //checks if the root is null, if true the tree is empty
    if(rootValue != NULL){
        node* delPtr;
        int matchData = match->data;
        int smallestInRightSubTree;

        //Case 0 - 0 children
        if(match->left == NULL && match->right == NULL){
            delPtr = match;
            if(left == true){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            delete delPtr;
        }

        //Case 1 - 1 Child
        else if(match->left == NULL && match->right != NULL){
            if(left == true){
                parent->left = match->right;
            }
            else{
                parent->right = match->right;
            }
            match->right = NULL;
            delPtr = match;
            delete delPtr;
        }

        else if(match->left != NULL && match->right == NULL){
            if(left == true){
                parent->left = match->left;
            }
            else{
                parent->right = match->left;
            }
            match->left = NULL;
            delPtr = match;
            delete delPtr;
        }
        //Case 2 - 2 children
        else{
            smallestInRightSubTree = findSmallestPrivate(match->right);
            removePrivate(smallestInRightSubTree, match);
            match->data = smallestInRightSubTree;
        }

    }
    //if the tree is null cant remove
    else{
        throw std::invalid_argument( "The tree is empty\n" );  
    }
}