// demo_ext.cpp
#include <iostream>
#include <fstream>

extern "C" {

#include <ruby/ruby.h>
#include <ruby/encoding.h>
#include <stdio.h>

}

VALUE r_file_generate()
{
  std::ofstream out_file;
  out_file.open("./demo_data.dat");

  long output = 0;
  out_file << output;

  out_file.close();
  return Qnil;
}

VALUE r_file_increase()
{
  std::ifstream in_file;
  in_file.open("./demo_data.dat");

  long input;
  in_file >> input;
  in_file.close();

  std::ofstream out_file{"./demo_data.dat", std::ios_base::out};
  out_file << ++input;
  out_file.close();

  return Qnil;
}

VALUE r_file_read()
{
  std::ifstream in_file;
  in_file.open("./demo_data.dat");

  long input;
  in_file >> input;

  return LONG2NUM(input);
}

extern "C" {

void Init_demo_ext()
{
  rb_define_global_function(
    "test_file_generate", RUBY_METHOD_FUNC(r_file_generate), 0);
  rb_define_global_function(
    "test_file_increase", RUBY_METHOD_FUNC(r_file_increase), 0);
  rb_define_global_function(
    "test_file_read", RUBY_METHOD_FUNC(r_file_read), 0);
}

}