#pragma once

#include "common_data.hpp"

class common_footer : public common_data
{
public:
    common_footer() {};
    virtual size_t      get_length() = 0;
    virtual const char *get_bytestring() = 0;
    virtual size_t      set(const std::string &) = 0;
    virtual ~common_footer() {};
};

