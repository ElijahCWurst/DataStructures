#include "BST.h"

BST::BST() {
	root = nullptr;
}

bool BST::isEmpty() const {
	return root == nullptr;
}

void BST::inOrder() {
	BST::inOrder(root);
}

//This will be used to print out the results at the end
void BST::inOrder(BSTNode* node) {
	if (node != nullptr) {
		inOrder(node->left);
		node->info->print(); // I'm not entirely sure this is correct lol EDIT: I sure hope it is because I've been putting it in lots of places...
		inOrder(node->right);
	}
}

void BST::insert(Word* word, int verseNumber) {
	BSTNode* temp = root;
	BSTNode* prev = nullptr;
	while (temp != nullptr) { // This finds where the node belongs or adds a number if it's already there.
		prev = temp;
		if (word->name < temp->info->name) {
			temp = temp->left;
		}
		else if(word->name > temp->info->name) {
			temp = temp->right;
		}
		else if (word->name == temp->info->name) {
			temp->info->location.push_back(verseNumber);
			break;
		}
	}
	if (root == nullptr) {
		root = new BSTNode(word);
		word->location.push_back(verseNumber);
	}
	else if (word->name < prev->info->name) {
		prev->left = new BSTNode(word);
		word->location.push_back(verseNumber);
	}
	else if (word->name > prev->info->name) {
		prev->right = new BSTNode(word);
		word->location.push_back(verseNumber);
	}
}