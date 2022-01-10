#pragma once

#include <exception>
#include <string>
#include <string_view>

class null_ptr_exception : public std::exception {
    const std::string msg = "null_ptr_exception";
	std::string file;
    std::string func;
    std::string info;
    int         line;

    public:
    null_ptr_exception(const char* file_, int line_, const char* func_, const char* info_ = "");
    virtual const char* what();
    std::string_view get_file();
    int get_line();
	std::string_view get_func();
    std::string_view get_info();
};