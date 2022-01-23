#include "common_packet.hpp"

size_t
common_packet::get_length()
{
    return header_data->get_length() + payload->get_length() + footer_data->get_length();
};

const char *
common_packet::get_bytestring()
{
    curr_bytestring.append(header_data->get_bytestring());
    curr_bytestring.append(payload->get_bytestring());
    curr_bytestring.append(footer_data->get_bytestring());
    return curr_bytestring.c_str();
};

size_t
common_packet::set(const std::string &src_bytestring)
{
    std::string_view ptr_to_bytestring_start = src_bytestring;
    size_t           tmp_read_bytes_amount = 0,
                     all_read_bytes = 0;

    tmp_read_bytes_amount = header_data->set(ptr_to_bytestring_start.data());
    all_read_bytes += tmp_read_bytes_amount;
    ptr_to_bytestring_start = ptr_to_bytestring_start.substr(tmp_read_bytes_amount);
    tmp_read_bytes_amount = payload->set(ptr_to_bytestring_start.data());
    all_read_bytes += tmp_read_bytes_amount;
    ptr_to_bytestring_start = ptr_to_bytestring_start.substr(tmp_read_bytes_amount);
    tmp_read_bytes_amount = footer_data->set(ptr_to_bytestring_start.data());
    all_read_bytes += tmp_read_bytes_amount;
    curr_bytestring.assign(src_bytestring, 0, all_read_bytes);
    return all_read_bytes;
}