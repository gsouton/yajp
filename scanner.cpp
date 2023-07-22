#include "scanner.h"
#include <cctype>
#include <exception>
#include <stdexcept>

Scanner::Scanner(std::string string)
    : string_(string), position_(string_.begin()), line_(0), column_(0) {}

Scanner::~Scanner() {}

void Scanner::skipSpaces() {
    while (position_ != string_.end() && std::isspace(*position_)) {
        if (*position_ == '\n') {
            line_++;
            column_ = 0;
        } else {
            column_++;
        }
        position_++;
    }
}

void Scanner::skip() {
    if (!eof())
        position_++;
}

void Scanner::satisfy(std::string str){
    for(char c: str){
        if(c != get()){
            throw std::runtime_error("Invalid token !");
        }
    }
}

bool Scanner::eof() { return position_ == string_.end(); }

std::string Scanner::munch(std::function<bool(char)> predicate) {
    std::string result = "";
    while (!eof() && predicate(*position_)) {
        result += *position_++;
    }
    return result;
}

char Scanner::get() {
    if (position_ == string_.end()) {
        throw std::runtime_error("No input left");
    } else {
        char character = *position_++;
        if (character == '\n') {
            line_++;
            column_ = 0;
        } else {
            column_++;
        }
        return character;
    }
}

char Scanner::look(){
    std::string::iterator last_position = position_;
    char c = get();
    position_ = last_position;
    return c;
}
