#include <stdexcept>

#include "looped_queue.h"

template <typename USER_DATA_TYPE>
void looped_queue<USER_DATA_TYPE>::_push_back_empty_elem()
{
    std::shared_ptr<queue_node<USER_DATA_TYPE>> new_tail_node, old_tail_node;
    new_tail_node = std::make_shared<queue_node<USER_DATA_TYPE>>();

    old_tail_node = this->last_created_node;
    old_tail_node->set_next_node(new_tail_node);
    new_tail_node->set_next_node(this->first_created_node);
    this->last_created_node = new_tail_node;
}

template <typename USER_DATA_TYPE>
void looped_queue<USER_DATA_TYPE>::_constructor_template(size_t n)
{
    if (n < 2) {
        throw std::invalid_argument("looped_queue: queue size must be greater than 1");
    }
    this->first_created_node = std::make_shared<queue_node<USER_DATA_TYPE>>();

    this->first_created_node->set_first_node_flag(true);
    this->head_node = this->first_created_node;
    this->last_created_node = this->first_created_node;
    this->curr_node_for_data = this->first_created_node;
    this->curr_queue_size = n;
    for (size_t curr_new_elem_idx = 1; curr_new_elem_idx < this->curr_queue_size; curr_new_elem_idx++)
        this->_push_back_empty_elem();
}

template <typename USER_DATA_TYPE>
looped_queue<USER_DATA_TYPE>::looped_queue()
{
    this->_constructor_template(looped_queue::default_queue_size);
}

template <typename USER_DATA_TYPE>
looped_queue<USER_DATA_TYPE>::looped_queue(size_t n)
{
    this->_constructor_template(n);
}

template <typename USER_DATA_TYPE>
USER_DATA_TYPE looped_queue<USER_DATA_TYPE>::front()
{
    if (this->head_node->is_user_data_empty() == false)
    {
        throw std::out_of_range("looped_queue: head_node is empty");
    }
    return this->head_node->get_node_user_data();
}

template <typename USER_DATA_TYPE>
void looped_queue<USER_DATA_TYPE>::pop_front()
{
    if (this->head_node->is_user_data_empty() == false)
    {
        throw std::out_of_range("looped_queue: head_node is empty");
    }

    this->head_node->clear();
    this->head_node = this->head_node->get_next_node();
}

template <typename USER_DATA_TYPE>
void looped_queue<USER_DATA_TYPE>::push_back(USER_DATA_TYPE input_user_data)
{
    this->curr_node_for_data->set_node_user_data(input_user_data);
    this->curr_node_for_data = this->curr_node_for_data->get_next_node();
}

template <typename USER_DATA_TYPE>
void looped_queue<USER_DATA_TYPE>::push_back(std::unique_ptr<USER_DATA_TYPE> ptr_input_user_data)
{
    this->curr_node_for_data->set_node_user_data(std::move(ptr_input_user_data));
    this->curr_node_for_data = this->curr_node_for_data->get_next_node();
}

template <typename USER_DATA_TYPE>
looped_queue<USER_DATA_TYPE>::~looped_queue()
{
    this->last_created_node->set_next_node(nullptr);

    this->first_created_node = nullptr;
    this->last_created_node = nullptr;
    this->head_node = nullptr;
    this->curr_node_for_data = nullptr;
}