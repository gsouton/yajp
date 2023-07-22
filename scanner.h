#pragma once

#include <iostream>
#include <string>
#include <functional>

#include <ctype.h>

#include "types.h"


class Scanner {
  public:
    Scanner(std::string string);
    ~Scanner();

    /**
     * Returns true if no input is left
     */
    bool eof();
    /**
     * Consume characters and return the next token
     */
    char get();
    std::string munch(std::function<bool(char)> predicate);
    void skipSpaces();
    void skip();
    void satisfy(std::string str);
    char look();

  protected:
    std::string string_;
    std::string::iterator position_;
    u32 line_;
    u32 column_;
};
