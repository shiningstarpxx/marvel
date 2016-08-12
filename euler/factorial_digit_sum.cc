// COPYRIGHT (C) 2016 michaelpei
// Filename:  factorial_digit_num.cc
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include <stdint.h>
#include <stdio.h>
#include <vector>

void Multi(uint32_t n, std::vector<uint32_t>* data) {
  uint32_t advance = 0;
  for (size_t i = 0; i < data->size(); ++i) {
    uint32_t tmp = data->at(i) * n + advance;
    advance = tmp / 10;
    (*data)[i] = tmp % 10;
  }
  while (advance != 0) {
    data->push_back(advance % 10);
    advance /= 10;
  }
}

int main(int argc, char** argv) {
  std::vector<uint32_t> data;
  data.push_back(1);

  for (uint32_t i = 2; i < 101; ++i) {
    Multi(i, &data);
  }

  uint32_t sum = 0;
  for (size_t i = 0; i < data.size(); ++i) {
    sum += data[i];
  }
  printf("the sum is %d\n", sum);
  return 0;
}

