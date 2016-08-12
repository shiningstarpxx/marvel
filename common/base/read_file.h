// Copyright (c) 2016, Tencent
// Filename:  read_file.h
// Description:
// Created:  07/27/2016 17:39:58
// Author:  michaelpei (Pei Xingxin), michaelpei@tencent.com
#ifndef COMMON_BASE_READ_FILE_H_
#define COMMON_BASE_READ_FILE_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void LoadFileToMatrix(
    const std::string& file_name,
    uint32_t demision,
    std::vector<std::vector<uint32_t> >* matrix) {
  std::ifstream in(file_name);
  std::string line;
  while (getline(in, line)) {
    std::vector<uint32_t> tmp(demision, 0);
    uint32_t index = 0;
    uint32_t number;
    std::stringstream ss(line);
    while (ss >> number) {
      tmp[index++] = number;
    }
    matrix->push_back(tmp);
  }
  in.close();
  return;
}

void LoadFileToVector(
    const std::string& file_name,
    std::vector<uint32_t>* matrix);

#endif  // COMMON_BASE_READ_FILE_H_
