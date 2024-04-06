#ifndef PROJECT1_STRING_H
#define PROJECT1_STRING_H

#include <ostream>
#include <cstring>

class String
{
public:
    String();
    String(char _char);
    String(const char* _string);

    //Copy Constructor
    String(const String& _string);

    //Move Constructor
    String(String&& _string) noexcept;

    ~String();

    void reset();
    size_t length() const;
    char* asCString() const;

    //Cast to const char
    operator const char* () const;

    //Bracket Operator overloads
    char operator[](int _index) const;
    char& operator[](int _index);

    //Compare
    bool operator==(const String& _other) const;
    bool operator==(const char* _chars) const;
    bool operator!=(const String& _other) const;
    bool operator!=(const char* _chars) const;

    bool starts_with(const String& _other, int n) const;
    bool starts_with(const char* _chars, int n) const;

    //Copy Assignment Operator
    String& operator=(const String& _other);

    //Move Assignment Operator
    String& operator=(String&& _other) noexcept;

    //Add Operators
    String& operator+=(const String& _other);
    String& operator+=(const char* _other);
    String operator+(const String& _other) const;
    String operator+(const char* _other) const;
    String operator+(const int N) const;

    //Stream Operator
    friend std::ostream& operator<<(std::ostream& _os, const String& _string);
private:
    std::size_t m_length{};
    char* m_string{};
};

#endif //PROJECT1_STRING_H
