#pragma once
#include <stdexcept>
#include <string>

namespace braille
{

// UTF-8 std::string -> UTF-32 std::u32string
// 점자(U+2800대), 한글 자모/완성형(U+3100~U+D7A3)은 전부 BMP(U+0000~U+FFFF)
// 범위이므로 1~3바이트 시퀀스만 처리하면 충분하다. (4바이트 서로게이트 영역은
// 이 데이터셋에서 등장하지 않으므로 다루지 않음)
inline std::u32string utf8_to_utf32(const std::string &s)
{
    std::u32string out;
    out.reserve(s.size());
    size_t i = 0;
    while (i < s.size())
    {
        unsigned char c0 = static_cast<unsigned char>(s[i]);
        char32_t cp;
        size_t len;
        if (c0 < 0x80)
        {
            cp = c0;
            len = 1;
        }
        else if ((c0 & 0xE0) == 0xC0)
        {
            cp = c0 & 0x1F;
            len = 2;
        }
        else if ((c0 & 0xF0) == 0xE0)
        {
            cp = c0 & 0x0F;
            len = 3;
        }
        else if ((c0 & 0xF8) == 0xF0)
        {
            cp = c0 & 0x07;
            len = 4;
        }
        else
        {
            throw std::runtime_error("utf8_to_utf32: invalid leading byte");
        }

        if (i + len > s.size())
            throw std::runtime_error("utf8_to_utf32: truncated sequence");

        for (size_t k = 1; k < len; ++k)
        {
            unsigned char ck = static_cast<unsigned char>(s[i + k]);
            if ((ck & 0xC0) != 0x80)
                throw std::runtime_error("utf8_to_utf32: invalid continuation byte");
            cp = (cp << 6) | (ck & 0x3F);
        }
        out.push_back(cp);
        i += len;
    }
    return out;
}

// UTF-32 std::u32string -> UTF-8 std::string
inline std::string utf32_to_utf8(const std::u32string &s)
{
    std::string out;
    out.reserve(s.size() * 3);
    for (char32_t cp : s)
    {
        if (cp < 0x80)
        {
            out.push_back(static_cast<char>(cp));
        }
        else if (cp < 0x800)
        {
            out.push_back(static_cast<char>(0xC0 | (cp >> 6)));
            out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
        else if (cp < 0x10000)
        {
            out.push_back(static_cast<char>(0xE0 | (cp >> 12)));
            out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
            out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
        else
        {
            out.push_back(static_cast<char>(0xF0 | (cp >> 18)));
            out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
            out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
            out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
    }
    return out;
}

} // namespace braille
