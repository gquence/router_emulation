#pragma once

#include <memory>

template <typename USER_DATA_TYPE>
class queue_node
{
private:
    std::unique_ptr<USER_DATA_TYPE> user_data;
    std::shared_ptr<queue_node>     next;
public:
    queue_node();
    queue_node(USER_DATA_TYPE input_user_data);

    bool    is_user_data_empty();
    void    clear();
    void    set_node_user_data(USER_DATA_TYPE input_user_data);
    void    set_node_user_data(std::unique_ptr<USER_DATA_TYPE> ptr_input_user_data);
    USER_DATA_TYPE       get_node_user_data();

    void  set_next_node(std::shared_ptr<queue_node> ptr_to_next_node);
    std::shared_ptr<queue_node<USER_DATA_TYPE>>   get_next_node();
    ~queue_node();
};