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