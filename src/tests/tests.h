#ifndef TESTS_H
#define TESTS_H
#include <iostream>
#include <cassert>
#define BEGIN_TEST(s) do{std::cerr << "beginning " << s << " test...\n";}while(0)
#define END_TEST(s) do{std::cerr << "test " << s << " success!\n";}while(0)
#endif
