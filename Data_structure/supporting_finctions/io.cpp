#include "io.h"
#include <iostream>
#include <fstream>

void write_vec(node_time* vec, Table& table, const std::string& path)
{

    for (size_t i = 1; i < table.row_size() - 1; ++i)
    {
        size_t j = 0;
        for (; j < table.row_size(); ++j)
            if (vec[j].get_name() == table.at(i, 0))
                break;
        
        table.at(i, 1) = std::to_string(vec[j].get_time_std()) + ';';
        table.at(i, 2) = std::to_string(vec[j].get_time_NNU9()) + ";\n";
    }
    
    // ReSharper disable once IdentifierTypo
    std::fstream fout_str(path, std::fstream::trunc|std::fstream::out);
    if(!fout_str.is_open())
    {
        std::cout << "the file isn't opened(str)!\n";
        return;
    }
    for (size_t i = 0; i < table.row_size(); ++i)
    {
        std::string str;
        for(size_t j = 0; j < table.col_size(); ++j)
        {
            str += table.at(i, j);
        }
        
        fout_str.write(str.c_str(), static_cast<std::streamsize>(str.size()));
    }
    
    fout_str.close();
}

void read_vec(Table& a, const std::string& path)
{
    std::string line; 
    std::fstream fin(path, std::fstream::in);
    if(!fin.is_open())
    {
        std::cout << "\nthe file isn't opened to read(str)!\n";
        return;
    }
        
    for(size_t i = 0; i < a.row_size(); ++i)
    {
        getline(fin, line);
        size_t j = 0, jj = 0;
        for(auto itl = line.begin(); itl != line.end(); ++j, ++jj, ++itl)
        {
            std::string ts;
            for(size_t ii = 0; !(itl == line.end() || line.at(jj) == ';'); ++ii, ++jj, ++itl)
                ts += line[jj];

            if(a.col_size()-1 == j)
                a.at(i, j) = ts + ";\n";
            else
                a.at(i, j) = ts + ';';
                
            if(itl == line.end())
            {
                --jj; --itl;
            }
        }
    }
    
    fin.close();
}
