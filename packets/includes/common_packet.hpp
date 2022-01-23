#pragma once

#pragma once

#include <memory>
#include <string_view>

#include "common_data.hpp"
#include "common_header.hpp"
#include "common_footer.hpp"

#include "null_ptr_exception.h"

class common_packet : public common_data
{
protected:
    std::unique_ptr<common_header> header_data;
    std::unique_ptr<common_footer> footer_data;
    std::unique_ptr<common_data>   payload;
    std::string                    curr_bytestring;
public:
    common_packet();
    common_packet(std::unique_ptr<common_header> in_header,
                  std::unique_ptr<common_footer> in_footer,
                  std::unique_ptr<common_data>   in_payload);
    virtual size_t      get_length() override;
    virtual const char *get_bytestring() override;
    virtual size_t      set(const std::string &src_bytestring) override;
    virtual ~common_packet();
};

common_packet::common_packet()
{
}

common_packet::common_packet(std::unique_ptr<common_header> in_header,
              std::unique_ptr<common_footer> in_footer,
              std::unique_ptr<common_data>   in_payload)
{
    if (static_cast<bool>(in_header) == false)
        throw null_ptr_exception(__FILE__, __LINE__, __FUNCTION__,
                "common_packet::common_packet in_header cannot be nullptr");
    if (static_cast<bool>(in_footer) == false)
        throw null_ptr_exception(__FILE__, __LINE__, __FUNCTION__,
                "common_packet::common_packet in_footer cannot be nullptr");
    if (static_cast<bool>(in_payload) == false)
        throw null_ptr_exception(__FILE__, __LINE__, __FUNCTION__,
                "common_packet::in_payload in_payload cannot be nullptr");

    this->header_data = std::move(in_header);
    this->footer_data = std::move(in_footer);
    this->payload = std::move(in_payload);
}