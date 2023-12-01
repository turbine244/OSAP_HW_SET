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
 * FileName	: Set.h
 * Content	: class 1
 * Test info : Not-yet
 *
 * !Remark!
 * AVL Tree implementation as a C++ class.
 * All comments are made with consideration
 * that the reader has prior knowledge of "AVL Tree"
 * The code follows the style guide - CSE3210.
 *
 * class 1 - Set
 *   !Members(1)
 *     int size
 *
 *   !Methods(8 public)
 *     public
 *       void Minimum(int x)
 *         ~ Print the key and depth of the node with
 *           the minimum key in the subtree where x is the root.
 *
 *       void Maximum(int x)
 *         ~ Print the key and depth of the node with
 *           the maximum key in the subtree where x is the root.
 *
 *       void Empty()
 *         ~ Print 1 if tree is empty.
 *         ~ Print 0 if tree is not empty.
 *
 *       void Size()
 *         ~ Print size of tree.
 *
 *       void Find(int x)
 *         ~ Print depth of node with key of "x".
 *         ~ Print 0 if tree do not have a node with key of "k".
 *
 *       void Insert(int x)
 *         ~ Insert node with key of "k" and print depth of node
 * 
 *       void Rank(int x)
 * 
 *       void Erase(int x)
 *
 *     + Constructor(1)
 *       Set()
 *         ~ Create an empty "AVL Tree".
 
 */
#pragma once
#include "AvlTree.h"

class Set : public AvlTree {
public:
	Set();

	void Minimum(int x);
	void Maximum(int x);
	void Empty();
	void Size();
	void Find(int x);
	void Insert(int x);
	void Rank(int x);
	void Erase(int x);

private:
	int size = 0;
};
