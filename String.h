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
    int to_int() const;
    String substr(int start, int len) const;


    //Bracket Operator overloads
    char operator[](int _index) const;
    char& operator[](int _index);

    //Compare
    bool operator==(const String& _other) const;
    bool operator==(const char* _chars) const;
    bool operator!=(const String& _other) const;
    bool operator!=(const char* _chars) const;


    //Copy Assignment Operator
    String& operator=(String _other);


    //Add Operators
    String& operator+=(const String& _other);
    String& operator+=(const char* _other);
    String operator+(const String& _other) const;
    String operator+(const char* _other) const;
    String operator+(const int N) const;

    friend void swap(String& first, String& second) noexcept;

    //Stream Operator
    friend std::ostream& operator<<(std::ostream& _os, const String& _string);
private:
    std::size_t m_length{};
    char* m_string{};
};

#endif //PROJECT1_STRING_H
