#pragma once

#include <memory>

#include "queue_node.h"

template <typename USER_DATA_TYPE>
class looped_queue
{
private:
    std::shared_ptr<queue_node<USER_DATA_TYPE>> first_created_node;
    std::shared_ptr<queue_node<USER_DATA_TYPE>> last_created_node;
    std::shared_ptr<queue_node<USER_DATA_TYPE>> head_node;
    std::shared_ptr<queue_node<USER_DATA_TYPE>> curr_node_for_data;

    static const size_t     default_queue_size = 10000;
    size_t                  curr_queue_size;

    void _push_back_empty_elem();
    void _constructor_template(size_t n);
public:
    looped_queue();
    looped_queue(size_t n);
    USER_DATA_TYPE front();
    void pop_front();
    void push_back(USER_DATA_TYPE input_user_data);
    void push_back(std::unique_ptr<USER_DATA_TYPE> ptr_input_user_data);
    ~looped_queue();
};
