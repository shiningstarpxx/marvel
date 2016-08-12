// Copyright (c) 2016, Tencent
// Filename:  read_file_test.cc
// Description:
// Created:  07/28/2016 10:14:07
// Author:  michaelpei (Pei Xingxin), michaelpei@tencent.com

#include "common/base/read_file.h"

#include <stdio.h>

int main(int argc, char** argv) {
  std::vector<std::vector<uint32_t> > matrix;
  LoadFileToMatrix("path_sum.data", 15, &matrix);

  for (uint32_t i = 0; i < matrix.size(); ++i) {
    for (uint32_t j = 0; j < matrix[i].size(); ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
