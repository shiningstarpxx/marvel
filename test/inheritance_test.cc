// COPYRIGHT (C) 2016 michaelpei
// Filename:  inheritance_test.cc
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include <stdio.h>
// #include "third_party/glog/logging.h"

class Base {
 public:
  void Init() {
    printf("In base init()\n");
    AfterInit();
    Finish();
  }
  void Finish() {
    printf("In base Finish()\n");
    AfterFinish();
  }

  virtual void AfterInit() {
    printf("In base AfterInit()\n");
  }
  virtual void AfterFinish() {
    printf("In base AfterFinish()\n");
  }

};

class Sub : public Base {
 public:
  void Init() {
    printf("In Sub Init()\n");
    Base::Init();
  }
  void Finish() {
    printf("In Sub Finish()\n");
  }

  virtual void AfterInit() {
    printf("In Sub AfterInit()\n");
  }
  virtual void AfterFinish() {
    printf("In Sub AfterFinish()\n");
  }
};

int main() {
  Base base;
  base.Init();
  printf("++++++++++++++++++++\n");
  Sub sub;
  sub.Init();
  return 0;
}
