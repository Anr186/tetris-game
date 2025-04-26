#define CTEST_MAIN
#define CTEST_SEGFAULT
#define __STDC_FORMAT_MACROS
#include "../thirdparty/ctest.h"
#include <iostream>
#include <string>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
