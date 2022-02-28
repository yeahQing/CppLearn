#include <iostream>
/* 预处理指令 pargma */

#ifdef __linux__
#pragma message("__linux__")
#endif

#ifdef __GNUC__
#pragma message("__GNUC__")
#endif

#ifdef __x86_64__
#pragma message("_M_X64 macro activated!")
#endif

#ifdef _WIN64
#pragma message("_WIN64 macro activated!")
#endif

int main(int argc, char const *argv[])
{
    std::cout << "EE" << std::endl;
    return 0;
}
