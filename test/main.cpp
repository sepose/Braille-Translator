// 간단한 CLI 데모: 인자로 받은 점자(UTF-8) 문자열을 한글로 변환해 출력.
//   ./braille_conv "⠈⠣"
#include "braille_conv.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "usage: " << argv[0] << " <점자 UTF-8 문자열>\n";
        return 1;
    }
    std::cout << braille::conv(argv[1]) << "\n";
    return 0;
}
