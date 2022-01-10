#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <string_view>
#include <exception>
#include "null_ptr_exception.h"
#include "looped_queue.h"
#include <vector>

typedef struct  s_optional_8021Q_tag
{
    std::uint16_t TPID;
        #define TPID_FOR_8021Q 0x8100
    std::uint16_t TCI;
        #define PCP_MASK 0xE000
        #define DEI_MASK 0x1000
        #define VID_MASK 0x0FFF
}               t_optional_8021Q_tag;

union u_packet_802_3_header
{
    struct s_packet_802_3_header_fields
    {
        char preamble[7];
        char start_frame_delimiter;
        char mac_dest[6];
        char mac_src[6];
        std::uint16_t ethertype_or_length;
    }       packet_802_3_header_fields;
    char    packet_802_3_header_bytes[sizeof(s_packet_802_3_header_fields)];
};

int main()
{
    try
    {
        std::cout << sizeof(u_packet_802_3_header) << std::endl;
        throw null_ptr_exception(__FILE__, __LINE__, __FUNCTION__, "тупень");
    }
    catch (null_ptr_exception &ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}