#pragma once

#include "common_data.hpp"

class common_header : public common_data
{
public:
    common_header() {};
    virtual size_t      get_length() = 0;
    virtual void        set_payload_length(size_t) = 0;
    virtual size_t      get_payload_length() = 0;
    virtual const char *get_bytestring() = 0;
    virtual size_t      set(const std::string &) = 0;
    virtual ~common_header() {};
};
