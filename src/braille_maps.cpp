#include "braille_maps.hpp"

namespace braille
{

const BrailleMap braille_dict_Start = {
    {U'⠈', U"ㄱ"},
    {U'⠉', U"ㄴ"},
    {U'⠊', U"ㄷ"},
    {U'⠐', U"ㄹ"},
    {U'⠑', U"ㅁ"},
    {U'⠘', U"ㅂ"},
    {U'⠠', U"ㅅ"},
    {U'⠨', U"ㅈ"},
    {U'⠰', U"ㅊ"},
    {U'⠋', U"ㅋ"},
    {U'⠓', U"ㅌ"},
    {U'⠙', U"ㅍ"},
    {U'⠚', U"ㅎ"},
};

const BrailleMap braille_double_dict_Start = {
    {U'⠈', U"ㄲ"},
    {U'⠊', U"ㄸ"},
    {U'⠘', U"ㅃ"},
    {U'⠠', U"ㅆ"},
    {U'⠨', U"ㅉ"},
};

const BrailleMap braille_dict_Middle = {
    {U'⠣', U"ㅏ"},
    {U'⠜', U"ㅑ"},
    {U'⠎', U"ㅓ"},
    {U'⠱', U"ㅕ"},
    {U'⠥', U"ㅗ"},
    {U'⠬', U"ㅛ"},
    {U'⠍', U"ㅜ"},
    {U'⠩', U"ㅠ"},
    {U'⠪', U"ㅡ"},
    {U'⠕', U"ㅣ"},
    {U'⠗', U"ㅐ"},
    {U'⠝', U"ㅔ"},
    {U'⠌', U"ㅖ"},
    {U'⠧', U"ㅘ"},
    {U'⠽', U"ㅚ"},
    {U'⠏', U"ㅝ"},
    {U'⠺', U"ㅢ"},
};

const BrailleMap braille_dict_Middle_Plus = {
    {U'⠜', U"ㅒ"},
    {U'⠧', U"ㅙ"},
    {U'⠏', U"ㅞ"},
    {U'⠍', U"ㅟ"},
};

const BrailleMap braille_dict_End = {
    {U'⠁', U"ㄱ"},
    {U'⠒', U"ㄴ"},
    {U'⠔', U"ㄷ"},
    {U'⠂', U"ㄹ"},
    {U'⠢', U"ㅁ"},
    {U'⠃', U"ㅂ"},
    {U'⠄', U"ㅅ"},
    {U'⠶', U"ㅇ"},
    {U'⠅', U"ㅈ"},
    {U'⠆', U"ㅊ"},
    {U'⠖', U"ㅋ"},
    {U'⠦', U"ㅌ"},
    {U'⠲', U"ㅍ"},
    {U'⠴', U"ㅎ"},
};

const BrailleMap braille_dict_Type_1 = {
    {U'⠹', U"억"},
    {U'⠾', U"언"},
    {U'⠞', U"얼"},
    {U'⠡', U"연"},
    {U'⠳', U"열"},
    {U'⠻', U"영"},
    {U'⠭', U"옥"},
    {U'⠷', U"온"},
    {U'⠿', U"옹"},
    {U'⠛', U"운"},
    {U'⠯', U"울"},
    {U'⠵', U"은"},
    {U'⠮', U"을"},
    {U'⠟', U"인"},
};

const BrailleMap braille_dict = {
    {U'⠈', U"ㄱ"},
    {U'⠉', U"ㄴ"},
    {U'⠊', U"ㄷ"},
    {U'⠐', U"ㄹ"},
    {U'⠑', U"ㅁ"},
    {U'⠘', U"ㅂ"},
    {U'⠠', U"ㅅ"},
    {U'⠨', U"ㅈ"},
    {U'⠰', U"ㅊ"},
    {U'⠋', U"ㅋ"},
    {U'⠓', U"ㅌ"},
    {U'⠙', U"ㅍ"},
    {U'⠚', U"ㅎ"},
    {U'⠣', U"ㅏ"},
    {U'⠜', U"ㅑ"},
    {U'⠎', U"ㅓ"},
    {U'⠱', U"ㅕ"},
    {U'⠥', U"ㅗ"},
    {U'⠬', U"ㅛ"},
    {U'⠍', U"ㅜ"},
    {U'⠩', U"ㅠ"},
    {U'⠪', U"ㅡ"},
    {U'⠕', U"ㅣ"},
    {U'⠗', U"ㅐ"},
    {U'⠝', U"ㅔ"},
    {U'⠌', U"ㅖ"},
    {U'⠧', U"ㅘ"},
    {U'⠽', U"ㅚ"},
    {U'⠏', U"ㅝ"},
    {U'⠺', U"ㅢ"},
    {U'⠁', U"ㄱ"},
    {U'⠒', U"ㄴ"},
    {U'⠔', U"ㄷ"},
    {U'⠂', U"ㄹ"},
    {U'⠢', U"ㅁ"},
    {U'⠃', U"ㅂ"},
    {U'⠄', U"ㅅ"},
    {U'⠶', U"ㅇ"},
    {U'⠅', U"ㅈ"},
    {U'⠆', U"ㅊ"},
    {U'⠖', U"ㅋ"},
    {U'⠦', U"ㅌ"},
    {U'⠲', U"ㅍ"},
    {U'⠴', U"ㅎ"},
};

const BrailleMap Type_1_dict = {
    {U'⠫', U"ㄱㅏ"},
    {U'⠉', U"ㄴㅏ"},
    {U'⠊', U"ㄷㅏ"},
    {U'⠑', U"ㅁㅏ"},
    {U'⠘', U"ㅂㅏ"},
    {U'⠇', U"ㅅㅏ"},
    {U'⠨', U"ㅈㅏ"},
    {U'⠋', U"ㅋㅏ"},
    {U'⠓', U"ㅌㅏ"},
    {U'⠙', U"ㅍㅏ"},
    {U'⠚', U"ㅎㅏ"},
    {U'⠣', U"ㅇㅏ"},
    {U'⠜', U"ㅇㅑ"},
    {U'⠎', U"ㅇㅓ"},
    {U'⠱', U"ㅇㅕ"},
    {U'⠥', U"ㅇㅗ"},
    {U'⠬', U"ㅇㅛ"},
    {U'⠍', U"ㅇㅜ"},
    {U'⠩', U"ㅇㅠ"},
    {U'⠪', U"ㅇㅡ"},
    {U'⠕', U"ㅇㅣ"},
    {U'⠗', U"ㅇㅐ"},
    {U'⠝', U"ㅇㅔ"},
    {U'⠌', U"ㅇㅖ"},
    {U'⠧', U"ㅇㅘ"},
    {U'⠽', U"ㅇㅚ"},
    {U'⠏', U"ㅇㅝ"},
    {U'⠺', U"ㅇㅢ"},
    {U'⠹', U"억"},
    {U'⠾', U"언"},
    {U'⠞', U"얼"},
    {U'⠡', U"연"},
    {U'⠳', U"열"},
    {U'⠻', U"영"},
    {U'⠭', U"옥"},
    {U'⠷', U"온"},
    {U'⠿', U"옹"},
    {U'⠛', U"운"},
    {U'⠯', U"울"},
    {U'⠵', U"은"},
    {U'⠮', U"을"},
    {U'⠟', U"인"},
};

const BrailleMap Type_1_Middle_Plus_dict = {
    {U'⠜', U"ㅇㅒ"},
    {U'⠧', U"ㅇㅙ"},
    {U'⠏', U"ㅇㅞ"},
    {U'⠍', U"ㅇㅟ"},
};

const BrailleMap Type_1_double_dict = {
    {U'⠫', U"ㄲㅏ"},
    {U'⠊', U"ㄸㅏ"},
    {U'⠘', U"ㅃㅏ"},
    {U'⠇', U"ㅆㅏ"},
    {U'⠨', U"ㅉㅏ"},
};

const BrailleMap Type_Junc_1_dict = {
    {U'⠣', U"ㅏ"},
    {U'⠜', U"ㅑ"},
    {U'⠎', U"ㅓ"},
    {U'⠱', U"ㅕ"},
    {U'⠥', U"ㅗ"},
    {U'⠬', U"ㅛ"},
    {U'⠍', U"ㅜ"},
    {U'⠩', U"ㅠ"},
    {U'⠪', U"ㅡ"},
    {U'⠕', U"ㅣ"},
    {U'⠗', U"ㅐ"},
    {U'⠝', U"ㅔ"},
    {U'⠌', U"ㅖ"},
    {U'⠧', U"ㅘ"},
    {U'⠽', U"ㅚ"},
    {U'⠏', U"ㅝ"},
    {U'⠺', U"ㅢ"},
    {U'⠹', U"ㅓㄱ"},
    {U'⠾', U"ㅓㄴ"},
    {U'⠞', U"ㅓㄹ"},
    {U'⠡', U"ㅕㄴ"},
    {U'⠳', U"ㅕㄹ"},
    {U'⠻', U"ㅕㅇ"},
    {U'⠭', U"ㅗㄱ"},
    {U'⠷', U"ㅗㄴ"},
    {U'⠿', U"ㅗㅇ"},
    {U'⠛', U"ㅜㄴ"},
    {U'⠯', U"ㅜㄹ"},
    {U'⠵', U"ㅡㄴ"},
    {U'⠮', U"ㅡㄹ"},
    {U'⠟', U"ㅣㄴ"},
};

const BrailleMap Type_Junc_1_dict_End = {
    {U'⠹', U"ㅓㄱ"},
    {U'⠾', U"ㅓㄴ"},
    {U'⠞', U"ㅓㄹ"},
    {U'⠡', U"ㅕㄴ"},
    {U'⠳', U"ㅕㄹ"},
    {U'⠻', U"ㅕㅇ"},
    {U'⠭', U"ㅗㄱ"},
    {U'⠷', U"ㅗㄴ"},
    {U'⠿', U"ㅗㅇ"},
    {U'⠛', U"ㅜㄴ"},
    {U'⠯', U"ㅜㄹ"},
    {U'⠵', U"ㅡㄴ"},
    {U'⠮', U"ㅡㄹ"},
    {U'⠟', U"ㅣㄴ"},
};

const BrailleMap Type_Num_dict = {
    {U'⠁', U"1"},
    {U'⠃', U"2"},
    {U'⠉', U"3"},
    {U'⠙', U"4"},
    {U'⠑', U"5"},
    {U'⠋', U"6"},
    {U'⠛', U"7"},
    {U'⠓', U"8"},
    {U'⠊', U"9"},
    {U'⠐', U","},
    {U'⠚', U"0"},
    {U'⠤', U"-"},
    {U'-', U"-"},
};

const BrailleMap Type_Num_Exc_dict = {
    {U'⠉', U"ㄴ"},
    {U'⠊', U"ㄷ"},
    {U'⠑', U"ㅁ"},
    {U'⠋', U"ㅋ"},
    {U'⠓', U"ㅌ"},
    {U'⠙', U"ㅍ"},
    {U'⠚', U"ㅎ"},
    {U'⠛', U"운"},
};

const BrailleMap Type_Giho_dict = {
    {U'⠲', U"."},
    {U'⠖', U"!"},
    {U'⠦', U"\""},
    {U'⠴', U"\""},
    {U'⠐', U","},
};

const BrailleMap Type_C_dict = {
    {U'⠎', U"그래서"},
    {U'⠉', U"그러나"},
    {U'⠒', U"그러면"},
    {U'⠢', U"그러므로"},
    {U'⠝', U"그런데"},
    {U'⠥', U"그리고"},
    {U'⠱', U"그리하여"},
};

const std::vector<char32_t> Type_C_list = {
    U'⠎',
    U'⠉',
    U'⠒',
    U'⠢',
    U'⠝',
    U'⠥',
    U'⠱',
};

const std::u32string braille_dict_Type_1__2838_280e = U"것"; // original key was "⠸⠎"
const std::u32string Type_1_dict__2838_280e = U"것";         // original key was "⠸⠎"
const std::u32string Type_1_double_dict__2838_280e = U"껏";  // original key was "⠸⠎"
const std::u32string Type_Giho_dict__002e_2826 = U"?.";      // original key was ".⠦"

} // namespace braille
