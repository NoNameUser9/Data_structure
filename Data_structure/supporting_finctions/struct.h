#pragma once
#include <string>
#include <vector>
#include <iostream>

struct sort_type
{
    // ReSharper disable StringLiteralTypo
    inline static std::string deque_puf = "deque.push_front;";
    inline static std::string deque_pf = "deque.pop_front;";
    inline static std::string deque_pub = "deque.push_back;";
    inline static std::string deque_pb = "deque.pop_back;";
    inline static std::string list_puf = "list.push_front;";
    inline static std::string list_pb = "list.merge;";
    inline static std::string list_sort = "list.sort;";
    inline static std::string list_merge = "list.merge;";
    inline static std::string list_ins_aft = "list.insert_after;";
    inline static std::string list_u = "list.unique;";
    inline static std::string binary_search = "binary_search;";
    // ReSharper restore StringLiteralTypo
    std::string get_name()
    {
        return name_;
    }
    void set_name(const std::string& name)
    {
        name_ = name;
    }

private:
    std::string name_;
};

struct node_time
{
    node_time(){}
    explicit node_time(std::string _Sort_type): time_std_(0)
    {
        name_.set_name(_Sort_type);
    }
    node_time& operator=(const std::string& _Sort_type)
    {
        name_.set_name(_Sort_type);
        return *this;
    }
    void set_time_std(const unsigned long& time)
    {
        time_std_ = time;
    }
    void set_time_NNU9(const unsigned long& time)
    {
        time_NNU9_ = time;
    }
    unsigned long get_time_std()
    {
        return static_cast<unsigned long>(time_std_);
    }
    unsigned long get_time_NNU9()
    {
        return static_cast<unsigned long>(time_NNU9_);
    }
    std::string get_name()
    {
        return name_.get_name();
    }
private:
    double time_std_;
    double time_NNU9_;
    sort_type name_;
};

struct Table
{
    Table(const size_t& size_row, const size_t& size_col)
    {
        table_.resize(size_row);
        for (size_t i = 0; i < size_row; ++i)
            table_[i].resize(size_col);

        for (size_t i = 0; i < size_row; ++i)
        {
            for (size_t j = 0; j < size_col; ++j)
                table_[i][j] = ';';
            table_[i][size_col - 1] = ";\n";
        }
    }
    std::string& at(const size_t& pos_row, const size_t& pos_col)
    {
        if(pos_col > table_[0].size())
            throw std::runtime_error("\nOut of range!\n");
        if(pos_row > table_.size())
            throw std::runtime_error("\nOut of range!\n");
        
        return table_[pos_row][pos_col];
    }
    size_t row_size()
    {
        return table_.size();
    }
    size_t col_size()
    {
        return table_[0].size();
    }
private:
    std::vector<std::vector<std::string>> table_{0};
};
