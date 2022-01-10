#include "null_ptr_exception.h"

null_ptr_exception::null_ptr_exception(const char* file_,
                        int line_, const char* func_,
                        const char* info_) : std::exception(),
	file (file_),
	func (func_),
	info (info_),
	line (line_)
{}

const char*			null_ptr_exception::what()  { return msg.c_str(); }
std::string_view    null_ptr_exception::get_file() { return file; }
int                 null_ptr_exception::get_line() { return line; }
std::string_view    null_ptr_exception::get_func() { return func; }
std::string_view    null_ptr_exception::get_info() { return info; }