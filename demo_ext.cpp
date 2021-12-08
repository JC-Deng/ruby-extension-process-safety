#include <iostream>

extern "C" {

#include <ruby/ruby.h>
#include <ruby/encoding.h>
#include <stdio.h>

}

VALUE r_test_func(VALUE self)
{
  std::cout << "Hello, Ruby C extensions!\n";

  return Qnil;
}

extern "C" {

void Init_demo_ext()
{
  VALUE demo_ext = rb_define_class("Demo_ext", rb_cObject);

  rb_define_method(demo_ext, "test_func", RUBY_METHOD_FUNC(r_test_func), 0);
}

}