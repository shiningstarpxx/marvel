// COPYRIGHT (C) 2016 michaelpei
// Filename:  echo.cc
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

// ECHO <infile >outfile
// ECHO infile outfile

#include <fstream>
#include <iostream>

template<typename In, typename Out>
void Process(In& in, Out& out) {
  out << in.rdbuf();
}

int main(int argc, char* argv[]) {
  using namespace std;

  fstream in, out;
  if (argc > 1) in.open(argv[1], ios::in | ios::binary);
  if (argc > 2) out.open(argv[2], ios::out | ios::binary);

  Process(in.is_open() ? in : cin,
          out.is_open() ? out : cout);
  return 0;
}

