/*
Copyright 2023 New_York_Cheesecake

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/*
 * FileName  : Set.cc
 * Content   : function 9
 * Test info : Not-yet
 *
 * !Remark!
 * All comments are made with consideration
 * that the reader has prior knowledge of "AVL Tree"
 * The code follows the style guide - CSE3210.
 */

#include "Set.h"

Set::Set() {}

void Set::Minimum(int x) {
	// 1 : set depth and root
	int depth = 0;
	Node* node = root();

	// 2 : find the node with the same key as x
	while (node->key != x)
	{
		// 2 - 1 : key of current node is greater than target key
		if (node->key > x)
		{
			node = node->left;
		}
		// 2 - 2 : key of current node is less than target key
		else if (node->key < x)
		{
			node = node->right;
		}
		depth++;
	}

	// 3 : Go left until there is no left node
	while (node->left != NULL)
	{
		node = node->left;
		depth++;
	}

	// 4 : Print node key value and depth
	cout << node->key << " " << depth << "\n";
}

void Set::Maximum(int x) {
	// 1 : set depth and root node
	int depth = 0;
	Node* node = root();

	// 2 : find the node with the same key as x
	while (node->key != x)
	{
		// 2 - 1 : key of current node is greater than target key
		if (node->key > x)
		{
			node = node->left;
		}
		// 2 - 2 : key of current node is less than target key
		else if (node->key < x)
		{
			node = node->right;
		}
		depth++;
	}

	// 3 : Go left until there is no right node
	while (node->right != NULL)
	{
		node = node->right;
		depth++;
	}

	// 4 : Print node key value and depth
	cout << node->key << " " << depth << "\n";
}

void Set::Empty() {
	// 1 : Print 1 if size is 0
	if (size == 0)
	{
		cout << "1\n";
	}
	// 2 : Print 0 if size is not 0
	else
	{
		cout << "0\n";
	}
}

void Set::Size() {
	// 1 : Print size
	cout << size << "\n";
}

void Set::Find(int x) {
	// 1 : Use AvlDepth funcion to print depth
	cout << AvlDepth(root(), x, 0) << "\n";
}

void Set::Insert(int x) {
	// 1 : Plus size
	size++;

	// 2 : Set root node
	Node* node = root();
	
	// 3 : Insert node
	AvlInsertNode(x, node);

	// 4 : Use AvlDepth funcion to print depth
	cout << AvlDepth(node, x, 0) << "\n";
}

void Set::Rank(int x) {

}

void Set::Erase(int x) {

}
