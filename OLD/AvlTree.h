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
 * FileName	: AvlTree.h
 * Content	: struct 1 | class 1
 * Test info : Not-yet
 *
 * !Remark!
 * AVL Tree implementation as a C++ class.
 * All comments are made with consideration
 * that the reader has prior knowledge of "AVL Tree"
 * The code follows the style guide - CSE3210.
 *
 * struct 1 - Node
 *   !Members(5)
 *     int key
 *     Node* left
 *     Node* right
 *     Node* parent
 *     int height
 *
 * class 1 - AvlTree
 *   !Members(1)
 *     Node* root_
 *
 *   !Methods(6 public | 4 private)
 *     public
 *       Node* root()
 *         ~ Getter of the member "root_".
 *
 *       Node* AvlSearchNode(Node* node, int k)
 *         ~ Return pointer of the node with key of "k".
 *
 *       void AvlInsertNode(int k, Node* &node)
 *         ~ Inset a node with key of "k".
 *         ~ "root_" may be changed.
 *
 *       void AvlDeleteNode(int k)
 *         ~ Delete a node with key of "k".
 *         ~ "root_" may be changed.
 *
 *       int AvlDepth(Node* node, int k, int d)
 *         ~ Return depth("d") of the node with key of "k".
 *         ~ Return 0 if tree do not have a node with key of "k"
 *
 *       int AvlHeight(Node* node);
 *         ~ Return height of the node.
 *
 *     + Constructor(1)
 *       AvlTree()
 *         ~ Create an empty "AVL Tree".
 *
 *     private
 *       int AvlBalanceFactor(Node* node)
 *         ~ Return the "Balance Factor".
 *
 *       void AvlRebalance(Node* &node, int x)
 *         ~ Rebalance the "AVL Tree", depending on the "Balance Factor"
 *
 *       Node* RightRotation(Node* node)
 *         ~ Do right rotation to balance the "AVL Tree"
 *         ~ Submethod for AvlRebalance()
 *
 *       Node* LeftRotation(Node* node)
 *         ~ Do left rotation to balance the "AVL Tree"
 *         ~ Submethod for AvlRebalance()
 */

#pragma once
#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	Node* parent;
	int height;
};

class AvlTree {
public:
	AvlTree();

	Node* root();
	Node* AvlSearchNode(Node* node, int k);
	void AvlInsertNode(int k, Node*& node);
	void AvlDeleteNode(int k);
	int AvlDepth(Node* node, int k, int d);
	int AvlHeight(Node* node);

private:
	int AvlBalanceFactor(Node* node);
	void AvlRebalance(Node*& node, int x);
	Node* RightRotation(Node* node);
	Node* LeftRotation(Node* node);

	Node* root_;
};
