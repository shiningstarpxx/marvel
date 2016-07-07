// COPYRIGHT (C) 2016 michaelpei
// Filename:  class_register.h
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#ifndef COMMON_BASE_CLASS_REGISTER_H_
#define COMMON_BASE_CLASS_REGISTER_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <map>
#include <string>
#include <vector>

#include "third_party/gflags/gflags.h"

template <typename BaseName>
class ClassRegistry {
 public:
  typedef BaseName* (*Creator)();
  typedef BaseName* (*Singleton)();

 private:
  typedef ClassInfo {
    Creator creator;
    Singleton singleton;
  } ClassInfo;
  typedef std::map<std::string, ClassInfo> ClassMap;

 public:
  ClassRegistry(){}
  ~ClassRegistry(){}

  void AddCreator(const std::string& entry_name,
                  Creator creator,
                  Singleton singleton = NULL) {
    typename ClassMap::iterator it = creator_map_.find(entry_name);
    if (it != creator_map_.end()) {
      fprintf(stderr, "register class name %s conflict. Possibilities: "
                      "Duplicated class definition "
                      "Same source file is linked ",
                      entry_name.c_str());
    }
    ClassInfo& info = creator_map_[entry_name];
    info.creator = creator;
    info.singleton = singleton;
    creator_names_.push_back(entry_name);
  }

  size_t CreatorSize() const {
    return creator_names_.size();
  }

  const std::string& CreatorName(size_t i) const {
    CHECK(i < creator_names_.size());
    return creator_names_[i];
  }

  BaseName* CreatorObject(const std::string& entry_name) const {
    typename ClassMap::const_iterator it = creator_map_.find(entry_name);
    if (creator_map_.end() == it) {
      return NULL;
    }
    return (*(it->second.creator))();
  }

  BaseName* GetSingleton(const std::string& entry_name) const {
    typename ClassMap::const_iterator it = creator_map_.find(entry_name);
    if (creator_map_.end() == it) {
      return NULL;
    }
    return (*(it->second.singleton))();
  }

 private:
  std::vector<std::string> creator_names_;
  ClassMap creator_map_;
};

#endif  // COMMON_BASE_CLASS_REGITER_H_
