#pragma once
#include <string>

namespace braille
{

// 점자 코드(브라유 유니코드 시퀀스, UTF-8)를 한글 텍스트(UTF-8)로 변환한다.
// 원본 파이썬 conv() 함수를 그대로 포팅한 것이며, 내부 제어 흐름(분기 순서,
// continue 위치 등)을 의도적으로 그대로 유지했다 — 즉 원본에 있던 동작(버그성
// 동작 포함)도 동일하게 재현한다. 별도로 동작을 "개선"하지 않았다.
std::string conv(const std::string &input_utf8);

} // namespace braille
