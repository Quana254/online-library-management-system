#pragma once
#include <iostream>
#define ASSERT_TRUE(c) do{ if(!(c)){ std::cerr<<"[FAIL] "<<__FILE__<<":"<<__LINE__<<" "<<#c<<"\n"; return false; } }while(0)
#define ASSERT_EQ(a,b) ASSERT_TRUE((a)==(b))
inline void report(const char* name, bool ok){ std::cout<<(ok?"[PASS] ":"[FAIL] ")<<name<<"\n"; }
