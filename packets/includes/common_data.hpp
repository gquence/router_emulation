#pragma once

#include <string>

class common_data
{
public:
    common_data() {};
    bool        check_data_length() { return false; };
    virtual size_t      get_length() = 0;
    virtual const char *get_bytestring() = 0;
    virtual size_t      set(const std::string &) = 0;
    virtual ~common_data() {};
};
