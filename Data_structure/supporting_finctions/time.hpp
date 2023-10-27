#pragma once
#include <chrono>

namespace NNU9
{
    class time
    {
    public:
        auto start()
        {
            start_ = std::chrono::system_clock::now();
        }

        auto end()
        {
            end_ = std::chrono::system_clock::now();
        }

        [[nodiscard]] auto difference() const
        {
            return std::chrono::nanoseconds(end_ - start_);
        }
    private:
        std::chrono::time_point<std::chrono::system_clock> start_;
        std::chrono::time_point<std::chrono::system_clock> end_;
    };
}
