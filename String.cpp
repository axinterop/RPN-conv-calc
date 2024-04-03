#pragma once
#include "String.h"

String::String() : m_length(0), m_string()
{
    m_string = new char[1];
    m_string[0] = '\0';
}

String::String(char _char) : m_length(1)
{
    m_string = new char[2];
    m_string[0] = _char;
    m_string[1] = '\0';
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

String::String(const String& _string)
{
    char* buffer = new char[_string.m_length + 1];
    std::copy(_string.m_string, _string.m_string + _string.m_length, buffer);
    buffer[_string.m_length] = '\0';

    m_string = buffer;
    m_length = _string.m_length;
}

String::String(String&& _string) noexcept
{
    const auto buffer = _string.m_string;

    m_length = _string.m_length;
    m_string = buffer;

    _string.reset();
}

String::~String()
{
    delete[] m_string;
    m_string = nullptr;
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

char* String::asCString() const
{
    return m_string;
}

String::operator const char*() const
{
    return m_string;
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

bool String::starts_with(const String &_other, int n) const {
    if (!_other.m_string) return false;
    return strncmp(m_string, _other.m_string, n) == 0;
}

bool String::starts_with(const char *_chars, int n) const {
    if (!_chars) return false;
    return strncmp(m_string, _chars, n) == 0;
}


bool String::operator!=(const String &_other) const {
    return !(*this == _other);
}

bool String::operator!=(const char *_chars) const {
    return !(*this == _chars);
}

String& String::operator=(const String& _other)
{
    if (this != &_other) {
        char* buffer = new char[_other.m_length + 1];
        std::copy(_other.m_string, _other.m_string + _other.m_length + 1, buffer);

        std::swap(buffer, m_string);
        m_length = _other.m_length;

        delete[] buffer;
    }

    return *this;
}

String& String::operator=(String&& _other) noexcept
{
    if (this != &_other) {
        const auto buffer = _other.m_string;

        delete[] m_string;

        m_string = buffer;
        m_length = _other.m_length;

        _other.reset();
    }

    return *this;
}

String& String::operator+=(const String& _other)
{
    if (this != &_other)
    {
        auto totalLength = m_length + _other.m_length;
        char* buffer = new char[totalLength + 1];

        std::copy(m_string, m_string + m_length, buffer);
        std::copy(_other.m_string, _other.m_string + _other.m_length, buffer + m_length);
        buffer[totalLength] = '\0';

        std::swap(m_string, buffer);
        m_length = totalLength;

        delete[] buffer;
    }

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
    const auto totalLength = m_length + _other.m_length;
    char* buffer = new char[totalLength + 1];

    std::copy(m_string, m_string + m_length, buffer);
    std::copy(_other.m_string, _other.m_string + _other.m_length, buffer + m_length);
    buffer[totalLength] = '\0';

    return String(buffer);
}

String String::operator+(const char* _other) const
{
    const auto charLength = strlen(_other);
    const auto totalLength = m_length + charLength;
    char* buffer = new char[totalLength + 1];

    std::copy(m_string, m_string + m_length, buffer);
    std::copy(_other, _other + charLength, buffer + m_length);
    buffer[totalLength] = '\0';

    return String(buffer);
}

std::ostream& operator<<(std::ostream& _os, const String& _string)
{
    _os << _string.m_string;
    return _os;
}



