// COPYRIGHT (C) 2016 michaelpei
// Filename:  inheritance_test.cc
// Description: virtual vs Non-virtual
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

class Base {
 public:
  void Init();

  void Finish();

  virtual AfterInit();
  virtual AfterFinish();
};
