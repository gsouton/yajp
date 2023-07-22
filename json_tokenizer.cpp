#include "json_tokenizer.h"
#include <exception>
#include <stdexcept>

JsonTokenizer::JsonTokenizer(std::string json_string) : Scanner(json_string) {}
JsonTokenizer::~JsonTokenizer() {}

JsonToken JsonTokenizer::get_next_token() {
    skipSpaces();
    char character = get();
    if (character == '{') {
        return {TokenType::Curly_open, "{"};
    } else if (character == '}') {
        return {TokenType::Curly_close, "}"};
    } else if (character == ':') {
        return {TokenType::Colon, ":"};
    } else if (character == ',') {
        return {TokenType::Comma, ","};
    } else if (character == '[') {
        return {TokenType::Array_open, "["};
    } else if (character == ']') {
        return {TokenType::Array_close, "]"};
    } else if (character == 'n') {
        satisfy(std::string("ull"));
        return {TokenType::Null_type, "null"};
    } else if (character == 't') {
        satisfy(std::string("rue"));
        return {TokenType::Boolean, "true"};
    } else if (character == 'f') {
        satisfy(std::string("alse"));
        return {TokenType::Boolean, "false"};
    } else if (character == '"') {
        buffer_.clear();
        char next_char = get();
        while (next_char != '"') {
            buffer_ += next_char;
            next_char = get();
        }
        return {TokenType::String, buffer_.c_str()};
    } else if (std::isdigit(character)) {
        buffer_.clear();
        buffer_ += character;
        while (!eof() && std::isdigit(look())) {
            buffer_ += get();
        }
        return {TokenType::String, std::move(buffer_.c_str())};
    }
    throw std::runtime_error("Invalid Token in json_string");
    skipSpaces();
}
