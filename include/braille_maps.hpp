#pragma once
#include <map>
#include <string>
#include <vector>

namespace braille
{

// 점자 한 칸(코드포인트) -> 자모/단어 매핑.
// 원본 파이썬 dict 는 보통 1코드포인트 키지만, '⠸⠎' 같은 2코드포인트
// 키도 일부 존재한다. 그런 키는 원본 conv() 안에서도 단일 문자 인덱싱으로만
// 조회되므로(예: Str[i] in some_dict) 실제로는 도달 불가능한 항목이며,
// 아래 맵 생성 시 별도 보관하고 본문에 주석으로 남긴다.
using BrailleMap = std::map<char32_t, std::u32string>;

extern const BrailleMap braille_dict_Start;
extern const BrailleMap braille_double_dict_Start;
extern const BrailleMap braille_dict_Middle;
extern const BrailleMap braille_dict_Middle_Plus;
extern const BrailleMap braille_dict_End;
extern const BrailleMap braille_dict_Type_1;
extern const BrailleMap braille_dict;
extern const BrailleMap Type_1_dict;
extern const BrailleMap Type_1_Middle_Plus_dict;
extern const BrailleMap Type_1_double_dict;
extern const BrailleMap Type_Junc_1_dict;
extern const BrailleMap Type_Junc_1_dict_End;
extern const BrailleMap Type_Num_dict;
extern const BrailleMap Type_Num_Exc_dict;
extern const BrailleMap Type_Giho_dict;
extern const BrailleMap Type_C_dict;
extern const std::vector<char32_t> Type_C_list;

// 아래는 원본에서 2코드포인트 키(예: "⠸⠎", ".⠦")였던 항목.
// conv() 로직에서 단일 문자 인덱싱(Str[i])으로만 조회되므로 원본에서도
// 이 딕셔너리 경로로는 도달하지 않는다 (대신 conv()가 ⠸+⠎ 조합을 직접 if문으로 처리).
extern const std::u32string braille_dict_Type_1__2838_280e; // key="⠸⠎" -> "것"
extern const std::u32string Type_1_dict__2838_280e;         // key="⠸⠎" -> "것"
extern const std::u32string Type_1_double_dict__2838_280e;  // key="⠸⠎" -> "껏"
extern const std::u32string Type_Giho_dict__002e_2826;      // key=".⠦" -> "?."

} // namespace braille
