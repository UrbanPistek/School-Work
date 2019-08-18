// Urban Pistek (20802700) and Julia Baribeau (20792386)

#include <iostream>
#include "lab3_binary_search_tree.hpp"

using namespace std;

//Imrpovement: Add a search function to return a pointer to a node with a certain value 
//Check if you need to add BinarySearchTree:: in front of TaskItem objects 

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree(){
	root = NULL; 
	size = 0;
}

// PURPOSE: Explicit destructor of the class BinarySearchTree
BinarySearchTree::~BinarySearchTree(){}

// PURPOSE: Returns the number of nodes in the tree
unsigned int BinarySearchTree::get_size() const{
	return size;
}

// PURPOSE: Returns the maximum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::max() const{
	if(root == NULL)
		return BinarySearchTree::TaskItem(-1, "N/A");	
	TaskItem* curr = root;
	while(curr->right != NULL){
		curr = curr->right;
	}
	return *curr;
}

// PURPOSE: Returns the minimum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const{
	if(root == NULL)
		return BinarySearchTree::TaskItem(-1, "N/A");	
	TaskItem* curr = root;
	while(curr->left != NULL){
		curr = curr->left;
	}
	return *curr;
}

int BinarySearchTree::getDepth(TaskItem* curr) const{
	if(curr == NULL){
		return 0; 
	}
	else{
		int leftDepth = getDepth(curr->left);
		int rightDepth = getDepth(curr->right);
		
		if(leftDepth > rightDepth){
			return (leftDepth) + 1;
		}
		else{
			return (rightDepth + 1); 
		}
	}
}

// PURPOSE: Returns the tree height
unsigned int BinarySearchTree::height() const{
	return getDepth(root) - 1; 
}

//Helper function for print()
void BinarySearchTree::inorder_traversal(TaskItem* curr) const{
	if(curr == NULL){
		return;  
	}
	else{
		inorder_traversal(curr->left);//Iterate recursivly left
		cout << curr->priority << endl;//return curr; //Visit Root Node 
		inorder_traversal(curr->right);//Iterate recursivly right  
	}
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const{ 
	inorder_traversal(root);
}

// PURPOSE: Returns true if a node with the value val exists in the tree
// otherwise, returns false
bool BinarySearchTree::exists(BinarySearchTree::TaskItem val) const{ 
	if(size == 0){
		return false; 
	}
	else if(root->priority == val.priority){
		return true; 
	}
	else{
		TaskItem* curr = root;  
		while(curr != NULL){
			if(curr->priority > val.priority){
				curr = curr->left;  
			}
			else if(curr->priority < val.priority){
				curr = curr->right;  
			}
			else if(curr->priority == val.priority){
				return true; 
			}
			else{
				return false; 
			}
		}	
	}
	return false; 
}

// PURPOSE: Optional helper function that returns a pointer to the root node
BinarySearchTree::TaskItem *BinarySearchTree::get_root_node()
{
	return NULL;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem **BinarySearchTree::get_root_node_address()
{
	return NULL;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node
int BinarySearchTree::get_node_depth(BinarySearchTree::TaskItem *n) const
{
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert(BinarySearchTree::TaskItem val){
	TaskItem* curr = root; 
	TaskItem* next = root; 
	bool is_inserted = false; 
	
	if(exists(val)){
		return false;
	}
	else if(size == 0){
		root = new TaskItem(val);
		val.right = NULL; 
		val.left = NULL; 
		++size;
		return true;  
	}
	else if(size == 1){//Add size = 1 case 
		if(val.priority < curr->priority){
			root->left = new TaskItem(val); 
			val.right = NULL; 
			val.left = NULL;
			++size; 
			return true; 
		}
		else{
			root->right = new TaskItem(val); 
			val.right = NULL; 
			val.left = NULL; 
			++size;
			return true;	
		}
	}
	else{
		while(is_inserted != true){
			if(next != NULL && val.priority < next->priority){
				curr = next; 
				next = next->left;
			}
			else if (next != NULL && val.priority > next->priority){
				curr = next; 
				next = next->right; 
			}
			else{
				is_inserted = true; 
			}		
		}
		if(curr->right == NULL && curr->left == NULL){//No child nodes 
			if(val.priority < curr->priority){//Left
				curr->left = new TaskItem(val); 
				++size; 
				return true; 
			}
			else{//Right
				curr->right = new TaskItem(val); 
				++size; 
				return true; 
			}
		}
		else if(curr->right == NULL || curr->left == NULL){//One child node 
			if(val.priority < curr->priority){//left
				if(curr->left != NULL){
					val.left = curr->left; 
					val.right = NULL; 
					curr->left = new TaskItem(val); 
					++size; 
					return true; 
				}
				else{
					curr->left = new TaskItem(val); 
					++size; 
					return true; 
				}
			}
			else{//Right
				if(curr->right != NULL){
					val.right = curr->right; 
					val.left = NULL; 
					curr->right = new TaskItem(val); 
					++size; 
					return true; 
				}
				else{
					curr->right = new TaskItem(val); 
					++size; 
					return true; 
				}
			}
		}
		else{//Two child nodes 
			if(val.priority < curr->priority){//left
				val.left = curr->left; 
				val.right = NULL; 
				curr->left = new TaskItem(val); 
				++size; 
				return true;
			}
			else{//Right
				val.right = curr->right; 
				val.left = NULL; 
				curr->right = new TaskItem(val); 
				++size; 
				return true;
			}
		}
	}
	return false; 
}

// PURPOSE: Removes the node with the value val from the tree
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove(BinarySearchTree::TaskItem val){
	if(exists(val) == false){
		return false; 
	}
	else if(size == 0){//Case 0: Empty Tree
		return false; 
	} 
	else if(size == 1){
		delete root; 
		root = NULL;
		size = 0;
		return true;  
	}
	else{ 
	TaskItem* curr = root;
	TaskItem* parent = root;
	//Find Value
	while(curr->priority != val.priority){
		if(val.priority < curr->priority){
			parent = curr; 
			curr = curr->left;  
		}
		else{
			parent = curr; 
			curr = curr->right; 
		}
	}
	//Case 1: Removing Leaf Node
	if(curr->left == NULL && curr->right == NULL){
		if(curr->priority < parent->priority){
			parent->left = NULL;
			delete curr;
			--size;
			return true; 
		}
		else{
			parent->right = NULL;
			delete curr; 
			--size;
			return true;
		}
	}
	//Case 2: Node with One Child
	else if((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)){//Possibly double check 
		if(curr->priority < parent->priority){ //if(parent->left != NULL){  if(curr->priority < parent->priority){
		 if(curr == parent){
			root = parent->left;
			delete curr;
			//delete parent; 
		 	--size;
		 	return true;
		 }
		else if(curr->left != NULL){ 
		 	parent->left = curr->left;
		 	delete curr;
		 	--size;
		 	return true; 
		 }
		 else{
		 	parent->left = curr->right;
		 	delete curr;
		 	--size;
		 	return true; 
		 }	 
		}
		else if(curr->priority > parent->priority){
		if(curr == parent){ 
		 	root = curr->right;
			delete curr;
		 	//delete parent;
		 	--size;
		 	return true;
		 }
		else if(curr->left != NULL){
		 	parent->right = curr->left;
		 	delete curr;  
		 	--size;
		 	return true; 
		 }
		 else{
		 	parent->right = curr->right;
		 	delete curr; 
		 	--size;
		 	return true; 
		 }
		}
		else{
			if(parent->right == NULL){
			root = parent->left;
			delete curr;
			//delete parent; 
		 	--size;
		 	return true;
			}
			else{ 
		 	root = curr->right;
			delete curr;
		 	//delete parent;
		 	--size;
		 	return true;	
			}
		}
	}
	//Case 3: Node with 2 Childern
	//Use successor for swap 
	else if(curr->left != NULL && curr->right != NULL){   
	//To Find Min Value Node	
	TaskItem* min = curr->right;
	TaskItem* min_parent = curr->right;
	
	while(min->left != NULL){
		min_parent = min;
		min = min->left; 
	}		
		if(min->right == NULL && min->left == NULL){
			curr->priority = min->priority; 
			if(curr->right == min){
				curr->right = NULL;
				delete min;
				--size; 
				return true; 
			}
			else{
				min_parent->left = NULL; 
				delete min;
				--size; 
				return true; 		
			}  
		}
		else{//min->left == NULL && min->right != NULL){
			if(min == min_parent){
				curr->priority = min->priority; 
				curr->right = min->right;
				
				delete min;
				//delete min_parent; 
				--size; 
				return true; 
			}
			else{
				curr->priority = min->priority;
				min_parent->right = min->right; 
				delete min; 
				--size;
				return true; 
			}
		}
	}
}
}
