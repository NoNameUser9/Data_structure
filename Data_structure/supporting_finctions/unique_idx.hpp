#pragma once

namespace NNU9
{
    inline void unique_idx(size_t& idx_count, size_t* idx_ptr_ptr_node)
    {
        //unique idx
        for (size_t i = 0; i < idx_count - 1; ++i)
            for (auto i2 = i + 1; i2 < idx_count; ++i2)
                if (idx_ptr_ptr_node[i] == idx_ptr_ptr_node[i2])
                    idx_ptr_ptr_node[i2] = 0;
                
        //slide idx
        for (size_t i = 0; i < idx_count; ++i)
            while (idx_ptr_ptr_node[i] == 0)
            {
                for (auto i2 = i; i2 < idx_count; ++i2)
                    idx_ptr_ptr_node[i2] = idx_ptr_ptr_node[i2 + 1];
                --idx_count;
            }
    }
}
