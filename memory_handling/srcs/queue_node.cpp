#include "queue_node.h"

template <typename USER_DATA_TYPE>
queue_node<USER_DATA_TYPE>::queue_node()
{
    this->next = nullptr;
    this->user_data = nullptr;
    this->first_node_flag = false;
}

template <typename USER_DATA_TYPE>
queue_node<USER_DATA_TYPE>::queue_node(USER_DATA_TYPE input_user_data)
{
    this->next = nullptr;
    this->first_node_flag = false;
    this->user_data = std::make_unique<USER_DATA_TYPE>();
    *(this->user_data) = input_user_data;
}

template <typename USER_DATA_TYPE>
bool    queue_node<USER_DATA_TYPE>::is_user_data_empty()
{
    return static_cast<bool>(this->user_data);
}

template <typename USER_DATA_TYPE>
void    queue_node<USER_DATA_TYPE>::clear()
{
    this->user_data = nullptr;
}

template <typename USER_DATA_TYPE>
void    queue_node<USER_DATA_TYPE>::set_node_user_data(USER_DATA_TYPE input_user_data)
{
    if (this->is_user_data_empty() == false)
        this->user_data = std::make_unique<USER_DATA_TYPE>();
    *(this->user_data) = input_user_data;
}

template <typename USER_DATA_TYPE>
void    queue_node<USER_DATA_TYPE>::set_node_user_data(std::unique_ptr<USER_DATA_TYPE> ptr_input_user_data)
{
    this->user_data = std::move(ptr_input_user_data);
}

template <typename USER_DATA_TYPE>
USER_DATA_TYPE       queue_node<USER_DATA_TYPE>::get_node_user_data()
{
    return *this->user_data;
}

template <typename USER_DATA_TYPE>
void           queue_node<USER_DATA_TYPE>::set_next_node(std::shared_ptr<queue_node> ptr_to_next_node)
{
    this->next = std::move(ptr_to_next_node);
}

template <typename USER_DATA_TYPE>
std::shared_ptr<queue_node<USER_DATA_TYPE>>   queue_node<USER_DATA_TYPE>::get_next_node()
{
    return this->next;
}

template <typename USER_DATA_TYPE>
queue_node<USER_DATA_TYPE>::~queue_node()
{
    this->next = nullptr;
    this->user_data = nullptr;
}