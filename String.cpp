#include "String.h"

String::String()
        : m_length{0}, m_string{new char[1]{}}
{
}

String::String(char c)
        : m_length{1}, m_string{new char[2]{c}}
{
}

String::String(const String& _string)
        : m_length{_string.m_length}, m_string{new char[m_length + 1]}
{
    std::copy(_string.m_string, _string.m_string + _string.m_length, m_string);
    m_string[m_length] = '\0';
}

String::String(const char* _string)
{
    if(!_string)
    {
        m_length = 0;
        m_string = new char[0];
    }
    else
    {
        m_length = strlen(_string);
        m_string = new char[m_length + 1];

        std::copy(_string, _string + m_length, m_string);
        m_string[m_length] = '\0';
    }
}

String::String(String&& _string) noexcept
    : String{}
{
    swap(*this, _string);
}

String::~String()
{
    delete[] m_string;
}

void String::reset()
{
    m_length = 0;
    m_string = nullptr;
}

size_t String::length() const
{
    return m_length;
}



char String::operator[](int _index) const
{
    if(_index < 0 || _index >= m_length)
    {
        throw std::out_of_range("String index out of bounds!");
    }
    return m_string[_index];
}

char& String::operator[](int _index)
{
    if (_index < 0 || _index >= m_length)
    {
        throw std::out_of_range("String index out of bounds!");
    }
    return m_string[_index];
}

bool String::operator==(const String& _other) const
{
    if (!_other.m_string) return false;
    return strcmp(m_string, _other.m_string) == 0;
}

bool String::operator==(const char* _chars) const
{
    if (!_chars) return false;
    return strcmp(m_string, _chars) == 0;
}


bool String::operator!=(const String &_other) const {
    return !(*this == _other);
}

bool String::operator!=(const char *_chars) const {
    return !(*this == _chars);
}

String& String::operator=(String _other) {
    swap(*this, _other);
    return *this;

}

String& String::operator+=(const String& _other)
{
    *this = *this + _other;
    return *this;
}

String& String::operator+=(const char* _other)
{
    const auto charLength = strlen(_other);
    const auto totalLength = m_length + charLength;
    char* buffer = new char[totalLength + 1];

    std::copy(m_string, m_string + m_length, buffer);
    std::copy(_other, _other + charLength, buffer + m_length);
    buffer[totalLength] = '\0';

    std::swap(m_string, buffer);
    m_length = totalLength;

    delete[] buffer;

    return *this;
}

String String::operator+(const String& _other) const
{
    String result;
    result.m_length = m_length + _other.m_length;
    result.m_string = new char[result.m_length + 1];
    std::copy(m_string, m_string + m_length, result.m_string);
    std::copy(_other.m_string, _other.m_string + _other.m_length, result.m_string);
    result[result.m_length] = '\0';
    return result;
}

String String::operator+(const char* _other) const
{
    const auto charLength = strlen(_other);
    const auto totalLength = m_length + charLength;
    char* buffer = new char[totalLength + 1];

    std::copy(m_string, m_string + m_length, buffer);
    std::copy(_other, _other + charLength, buffer + m_length);
    buffer[totalLength] = '\0';

    String r = String(buffer);
    delete[] buffer;
    return r;
}

String String::operator+(const int N) const
{
    char t[3];
    sprintf(t, "%d", N);
    return *this + t;
}

std::ostream& operator<<(std::ostream& _os, const String& _string)
{
    _os << _string.m_string;
    return _os;
}

int String::to_int() const {
    return atoi(m_string);
}

String String::substr(int start, int len) const {
    char* des = new char[len + 1];
    strncpy(des, m_string + start, len);
    des[len] = '\0';

    String r = String(des);
    delete[] des;
    return r;
}

void swap(String &first, String &second) noexcept {
    std::swap(first.m_length, second.m_length);
    std::swap(first.m_string, second.m_string);
}



