#pragma once

#include "scanner.h"

enum class TokenType {
    Curly_open,
    Curly_close,
    Colon,
    String,
    Number,
    Array_open,
    Array_close,
    Comma,
    Boolean,
    Null_type,
};

struct JsonToken {
    TokenType type;
    union {
        const char *string;
        bool boolean;
        u64 integer;
        f64 decimal;
    };

    std::string to_string() {
        std::string result = "";
        switch (type) {
        case TokenType::Curly_open:
            result = "{";
            break;
        case TokenType::Curly_close:
            result = "}";
            break;
        case TokenType::Colon:
            result = ":";
            break;
        case TokenType::Array_open:
            result = "[";
            break;
        case TokenType::Array_close:
            result = "]";
            break;
        case TokenType::String:
            result = string;
            break;
        case TokenType::Number:
            result = string;
            break;
        case TokenType::Comma:
            result = ",";
            break;
        case TokenType::Boolean:
            result = "boolean";
            break;
        case TokenType::Null_type:
            result = "nullptr";
            break;
        }
        return string;
    }
};

class JsonTokenizer : public Scanner {
  public:
    JsonTokenizer(std::string json_string);
    ~JsonTokenizer();
    JsonToken get_next_token();
  protected:
    std::string buffer_;

};
