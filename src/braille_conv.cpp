#include "braille_conv.hpp"
#include "braille_maps.hpp"
#include "jamo_compose.hpp"
#include "utf8_util.hpp"

namespace braille
{

namespace
{

// std::u32string 전역 치환 (Python str.replace 와 동일)
void replace_all(std::u32string &s, const std::u32string &from, const std::u32string &to)
{
    if (from.empty())
        return;
    size_t pos = 0;
    while ((pos = s.find(from, pos)) != std::u32string::npos)
    {
        s.replace(pos, from.size(), to);
        pos += to.size();
    }
}

char32_t Ch(const std::u32string &Str, long long idx)
{
    long long n = static_cast<long long>(Str.size());
    if (idx < 0)
        idx += n;
    if (idx < 0 || idx >= n)
        return U'\0';
    return Str[static_cast<size_t>(idx)];
}

std::u32string dget(const BrailleMap &m, char32_t key, const std::u32string &def = U"")
{
    auto it = m.find(key);
    return it != m.end() ? it->second : def;
}

bool has(const BrailleMap &m, char32_t key)
{
    return m.find(key) != m.end();
}

bool has(const std::vector<char32_t> &v, char32_t key)
{
    for (char32_t c : v)
        if (c == key)
            return true;
    return false;
}

std::u32string conv_u32(std::u32string Str)
{
    Str = U"⠀⠀⠀" + Str + U"⠀⠀⠀";

    // 기호 점자 번역
    replace_all(Str, U"⠤", U"-");
    replace_all(Str, U"⠈⠔", U"~");
    replace_all(Str, U"⠦⠆", U"[");
    replace_all(Str, U"⠰⠴", U"]");
    replace_all(Str, U"⠐⠂", U":");
    replace_all(Str, U"⠦⠄", U"(");
    replace_all(Str, U"⠰⠦", U"『");
    replace_all(Str, U"⠴⠆", U"』");
    replace_all(Str, U"⠐⠦", U"「");
    replace_all(Str, U"⠴⠂", U"」");

    // 받침 점자 대체
    replace_all(Str, U"⠒⠴", U"ㄶ");
    replace_all(Str, U"⠁⠁", U"ㄲ");
    replace_all(Str, U"⠁⠄", U"ㄳ");
    replace_all(Str, U"⠒⠅", U"ㄵ");
    replace_all(Str, U"⠂⠁", U"ㄺ");
    replace_all(Str, U"⠂⠢", U"ㄻ");
    replace_all(Str, U"⠂⠃", U"ㄼ");
    replace_all(Str, U"⠂⠄", U"ㄽ");
    replace_all(Str, U"⠂⠦", U"ㄾ");
    replace_all(Str, U"⠂⠲", U"ㄿ");
    replace_all(Str, U"⠂⠴", U"ㅀ");
    replace_all(Str, U"⠃⠄", U"ㅄ");

    int countEqual = 0;
    std::u32string newstr;
    long long i = 0;
    long long j = 0;

    // 아래 while 본문은 의도적으로 "여러 개의 독립된 if" 로 되어 있고
    // else-if 체인이 아니다 (원본과 동일). 즉 한 번의 바깥 루프 반복 안에서
    // 여러 분기가 연달아 실행될 수 있으며, 맨 끝의 i++ 도 continue 가 없는 한
    // 항상 추가로 한 번 더 실행된다. 원본 동작을 그대로 보존하기 위해
    // 구조를 바꾸지 않았다.
    while (i < static_cast<long long>(Str.size()))
    {

        if (Ch(Str, i) == U'⠒')
        {
            j = i;
            while (Ch(Str, j) == U'⠒')
            {
                j += 1;
                countEqual += 1;
                if (countEqual > 5)
                {
                    i = j;
                }
            }
            countEqual = 0;
        }

        if (Ch(Str, i) == U'⠼')
        {
            i += 1;
            while (true)
            {
                if (Ch(Str, i) == U' ' || Ch(Str, i) == U'⠀')
                {
                    i += 1;
                    break;
                }
                else
                {
                    if (has(Type_Num_dict, Ch(Str, i)))
                    {
                        newstr += dget(Type_Num_dict, Ch(Str, i));
                        i += 1;
                    }
                    else
                    {
                        if (has(braille_dict_Middle, Ch(Str, i)))
                        {
                            newstr += U"ㅇ";
                        }
                        break;
                    }
                }
            }
        }

        if (Ch(Str, i) == U'⠐')
        {
            if (has(Type_Junc_1_dict, Ch(Str, i + 1)))
            {
                newstr += dget(braille_dict_Start, Ch(Str, i));
                i += 1;
            }
            else
            {
                newstr += dget(Type_Giho_dict, Ch(Str, i));
                i += 1;
            }
        }

        if (Ch(Str, i) == U'⠲' &&
            (Ch(Str, i + 1) == U' ' || Ch(Str, i + 1) == U'⠀' ||
             Ch(Str, i + 1) == U'\n' || has(Type_Num_dict, Ch(Str, i - 1))))
        {
            newstr += U".";
            i += 1;
        }

        if (Ch(Str, i) == U'⠸' && Ch(Str, i + 1) == U'⠎')
        {
            if (Ch(Str, i - 1) == U'⠠')
            {
                // 원본: Type_1_double_dict.get(Str[i+1], "")  — 여기서 Str[i+1]은
                // 단일 문자 '⠎' 뿐이다. 그런데 Type_1_double_dict 안에서 "껏"은
                // 2글자 키 "⠸⠎" 에 매달려 있고 단일 키 '⠎' 항목은 없으므로,
                // 원본에서도 이 분기는 실제로는 항상 빈 문자열만 추가한다
                // (의도는 "껏"이었을 가능성이 높지만 실제 동작은 그렇지 않음).
                // 동작을 그대로 재현하기 위해 의미 추측 없이 동일한 조회를 수행한다.
                newstr += dget(Type_1_double_dict, Ch(Str, i + 1));
                i += 2;
            }
            else
            {
                i += 2;
                newstr += U"것";
            }
        }

        if (Ch(Str, i) == U'⠁' && has(Type_C_dict, Ch(Str, i + 1)))
        {
            if (Ch(Str, i + 2) == U' ' || Ch(Str, i + 2) == U'⠀')
            {
                i += 1;
                newstr += dget(Type_C_dict, Ch(Str, i));
                i += 1;
            }
        }

        if (Ch(Str, i) == U'⠠' &&
            (has(braille_double_dict_Start, Ch(Str, i + 1)) || has(Type_1_double_dict, Ch(Str, i + 1))))
        {
            if (has(braille_dict_Middle, Ch(Str, i + 2)))
            {
                if (Ch(Str, i + 3) == U'⠌')
                {
                    newstr += dget(braille_double_dict_Start, Ch(Str, i + 1)) +
                              dget(braille_dict_Middle, Ch(Str, i + 2)) + U"ㅆ";
                    i += 4;
                }
                else
                {
                    newstr += dget(braille_double_dict_Start, Ch(Str, i + 1)) +
                              dget(braille_dict_Middle, Ch(Str, i + 2));
                    i += 3;
                }
            }
            else if (has(Type_Junc_1_dict, Ch(Str, i + 2)))
            {
                newstr += dget(braille_double_dict_Start, Ch(Str, i + 1));
                i += 2;
            }
            else
            {
                newstr += dget(Type_1_double_dict, Ch(Str, i + 1));
                i += 2;
            }
            continue;
        }

        if (has(Type_1_dict, Ch(Str, i)))
        {
            if (has(braille_dict_Start, Ch(Str, i)) && Ch(Str, i + 1) == U'⠌')
            {
                newstr += dget(Type_1_dict, Ch(Str, i)) + U"ㅆ";
                i += 2;
                continue;
            }

            if (Ch(Str, i) == U'⠌' && has(braille_dict_Middle, Ch(Str, i - 1)))
            {
                newstr += U"ㅆ";
            }
            else if (!has(braille_dict_Start, Ch(Str, i - 1)) && has(braille_dict_Middle, Ch(Str, i)))
            {
                char32_t prev = Ch(Str, i - 1);
                if (prev == U'⠜' || prev == U'⠧' || prev == U'⠏' || prev == U'⠍')
                {
                    if (Ch(Str, i) == U'⠗')
                    {
                        if (!newstr.empty())
                            newstr.pop_back();
                        newstr += dget(braille_dict_Middle_Plus, prev);
                        i += 1;
                        continue;
                    }
                }
                newstr += dget(Type_1_dict, Ch(Str, i));
                i += 1;
                continue;
            }
            else if (!has(braille_dict_Middle, Ch(Str, i + 1)) && !has(Type_Junc_1_dict, Ch(Str, i + 1)))
            {
                if (!has(Type_Junc_1_dict, Ch(Str, i)))
                {
                    newstr += dget(Type_1_dict, Ch(Str, i));
                }
                else
                {
                    if (has(braille_dict_Start, Ch(Str, i - 1)))
                    {
                        newstr += dget(Type_Junc_1_dict, Ch(Str, i));
                    }
                    else
                    {
                        newstr += dget(Type_1_dict, Ch(Str, i));
                    }
                }
            }
            else if (has(braille_dict_End, Ch(Str, i - 1)) && has(braille_dict_Middle, Ch(Str, i)))
            {
                newstr += dget(Type_1_dict, Ch(Str, i));
            }
            else if (has(braille_dict_End, Ch(Str, i - 1)) && !has(braille_dict_Middle, Ch(Str, i + 1)))
            {
                if (!has(braille_dict_Type_1, Ch(Str, i + 1)))
                {
                    newstr += dget(Type_1_dict, Ch(Str, i));
                }
                else
                {
                    newstr += dget(braille_dict, Ch(Str, i));
                }
            }
            else if (has(braille_dict, Ch(Str, i)))
            {
                newstr += dget(braille_dict, Ch(Str, i));
            }
            else if (has(braille_dict_Middle, Ch(Str, i)) && Ch(Str, i + 1) == U'⠤' && Ch(Str, i + 2) == U'⠌')
            {
                newstr += dget(braille_dict_Middle, Ch(Str, i));
                i += 2;
                continue;
            }
            else if (has(braille_dict_Start, Ch(Str, i)) && has(Type_Junc_1_dict, Ch(Str, i + 1)))
            {
                newstr += dget(braille_dict_Start, Ch(Str, i)) + dget(Type_Junc_1_dict, Ch(Str, i + 1));
                i += 2;
                continue;
            }
            else
            {
                if (has(braille_dict_Start, Ch(Str, i - 1)) && has(Type_Junc_1_dict, Ch(Str, i)))
                {
                    newstr += dget(Type_Junc_1_dict, Ch(Str, i));
                }
                else
                {
                    newstr += dget(Type_1_dict, Ch(Str, i));
                }
            }
        }
        else if (has(braille_dict, Ch(Str, i)))
        {
            newstr += dget(braille_dict, Ch(Str, i));
        }
        else
        {
            newstr += Ch(Str, i);
        }

        i += 1;
    }

    newstr = join_jamos(newstr);

    replace_all(newstr, U"셩", U"성");
    replace_all(newstr, U"쎵", U"썽");
    replace_all(newstr, U"졍", U"정");
    replace_all(newstr, U"쪙", U"쩡");
    replace_all(newstr, U"쳥", U"청");

    return newstr;
}

} // anonymous namespace

std::string conv(const std::string &input_utf8)
{
    std::u32string in32 = utf8_to_utf32(input_utf8);
    std::u32string out32 = conv_u32(in32);
    return utf32_to_utf8(out32);
}

} // namespace braille
