#pragma once

#include <string>

int  check_hierarchy(char op);
bool is_operator(char c);
bool is_operand(char c);
std::string convert_infix_to_postfix(const std::string& in);
