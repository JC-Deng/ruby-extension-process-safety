#include <iostream>

extern "C" {

#include <ruby/ruby.h>
#include <ruby/encoding.h>
#include <stdio.h>

}

class DemoResource
{
  private:
    int data = 0;
  
  public:
    void increase_data()
    {
      ++data;
    }

    int get_data()
    {
      return data;
    }
};

DemoResource demoResource;

VALUE r_test_func(VALUE self)
{
  std::cout << "Hello, Ruby C extensions!\n";

  demoResource.increase_data();

  std::cout << "Test CPP part.\n";
  std::cout << demoResource.get_data() << '\n';

  return Qnil;
}

extern "C" {

void Init_demo_ext()
{
  VALUE demo_ext = rb_define_class("Demo_ext", rb_cObject);

  rb_define_method(demo_ext, "test_func", RUBY_METHOD_FUNC(r_test_func), 0);
}

}