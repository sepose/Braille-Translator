#include "jamo_compose.hpp"
#include <array>

namespace braille
{

namespace
{

// 초성 19개 (U+3131 호환 자모 기준)
constexpr std::array<char32_t, 19> CHO = {
    U'ㄱ', U'ㄲ', U'ㄴ', U'ㄷ', U'ㄸ', U'ㄹ', U'ㅁ', U'ㅂ', U'ㅃ', U'ㅅ',
    U'ㅆ', U'ㅇ', U'ㅈ', U'ㅉ', U'ㅊ', U'ㅋ', U'ㅌ', U'ㅍ', U'ㅎ'};

// 중성 21개
constexpr std::array<char32_t, 21> JUNG = {
    U'ㅏ', U'ㅐ', U'ㅑ', U'ㅒ', U'ㅓ', U'ㅔ', U'ㅕ', U'ㅖ', U'ㅗ', U'ㅘ',
    U'ㅙ', U'ㅚ', U'ㅛ', U'ㅜ', U'ㅝ', U'ㅞ', U'ㅟ', U'ㅠ', U'ㅡ', U'ㅢ', U'ㅣ'};

// 종성 28개 (0번 = 받침 없음)
constexpr std::array<char32_t, 28> JONG = {
    0, U'ㄱ', U'ㄲ', U'ㄳ', U'ㄴ', U'ㄵ', U'ㄶ', U'ㄷ', U'ㄹ', U'ㄺ',
    U'ㄻ', U'ㄼ', U'ㄽ', U'ㄾ', U'ㄿ', U'ㅀ', U'ㅁ', U'ㅂ', U'ㅄ', U'ㅅ',
    U'ㅆ', U'ㅇ', U'ㅈ', U'ㅊ', U'ㅋ', U'ㅌ', U'ㅍ', U'ㅎ'};

int cho_index(char32_t c)
{
    for (size_t i = 0; i < CHO.size(); ++i)
        if (CHO[i] == c)
            return static_cast<int>(i);
    return -1;
}
int jung_index(char32_t c)
{
    for (size_t i = 0; i < JUNG.size(); ++i)
        if (JUNG[i] == c)
            return static_cast<int>(i);
    return -1;
}
int jong_index(char32_t c)
{
    for (size_t i = 0; i < JONG.size(); ++i)
        if (JONG[i] == c)
            return static_cast<int>(i);
    return -1;
}

} // anonymous namespace

std::u32string join_jamos(const std::u32string &s)
{
    std::u32string out;
    out.reserve(s.size());

    size_t i = 0;
    const size_t n = s.size();

    while (i < n)
    {
        int ci = cho_index(s[i]);
        int ji = (i + 1 < n) ? jung_index(s[i + 1]) : -1;

        if (ci >= 0 && ji >= 0)
        {
            // 초성 + 중성 확정. 종성 후보 확인.
            int jongIdx = 0; // 받침 없음
            size_t consumed = 2;

            if (i + 2 < n)
            {
                int candidateJong = jong_index(s[i + 2]);
                if (candidateJong > 0)
                {
                    // 후보 자음이 초성으로도 쓰일 수 있고, 그 다음이 또 중성이면
                    // 다음 음절의 초성으로 양보한다 (받침으로 가져오지 않음).
                    bool candidateAlsoCho = cho_index(s[i + 2]) >= 0;
                    bool nextIsJung = (i + 3 < n) && (jung_index(s[i + 3]) >= 0);

                    if (!(candidateAlsoCho && nextIsJung))
                    {
                        jongIdx = candidateJong;
                        consumed = 3;
                    }
                }
            }

            char32_t syllable = static_cast<char32_t>(
                0xAC00 + (ci * 21 + ji) * 28 + jongIdx);
            out.push_back(syllable);
            i += consumed;
            continue;
        }

        // 결합 대상이 아니면 그대로 통과
        out.push_back(s[i]);
        ++i;
    }

    return out;
}

} // namespace braille
