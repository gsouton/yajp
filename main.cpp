#include <iostream>
#include <string>
#include "json_tokenizer.h"
#include "scanner.h"

int main(void){
    std::string input = "";
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    JsonTokenizer scanner(input);
    while(!scanner.eof()){
        JsonToken token = scanner.get_next_token();
        std::cout << token.to_string() << std::endl;
    }
    return 0;
}

