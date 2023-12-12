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
 * FileName  : Settable.h
 * Content   : class 1
 * Test info : Not-yet
 *
 * !Remark!
 * Class interface for Set and other Settable datatypes.
 * The code follows the style guide - CSE3210.
 */

#ifndef OSAP_HDR_SETTABLE_H_
#define OSAP_HDR_SETTABLE_H_

template<typename TYPE_KEY>
class Settable {
public:
  virtual int Get_size() = 0;
  virtual int Return_Depth(TYPE_KEY x) = 0;
  virtual TYPE_KEY Return_Minimum(TYPE_KEY x) = 0;
  virtual TYPE_KEY Return_Maximum(TYPE_KEY x) = 0;
  virtual void Do_Insert(TYPE_KEY x) = 0;
  virtual void Do_Erase(TYPE_KEY x) = 0;
};

#endif
