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
 * FileName  : Node.h
 * Content   : struct 1
 * Test info : Not-yet
 *
 * !Remark!
 * The code follows the style guide - CSE3210.
 */

#ifndef OSAP_HDR_NODE_H_
#define OSAP_HDR_NODE_H_

template<typename TYPE_KEY>
struct Node {
  TYPE_KEY key;
  Node* parent;
  Node* left;
  Node* right;

  // int height;
};

#endif
