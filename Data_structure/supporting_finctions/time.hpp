#pragma once
#include <chrono>
#include <iostream>
#include <unordered_map>

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
            // std::chrono::duration_cast<auto, std::ratio<1, 1000>>(end_ - start_);
            // std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_);
            std::stringstream ss;
            const auto int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ - start_);
            const std::chrono::duration<long, std::nano> int_usec = int_ms;
            ss << int_usec.count();
            // return std::stoi(ss.str());
            return int_usec.count();
        }
        

        // int main(int argc, char *argv[]) {
        //     if (argc != 3) {
        //         std::cerr << "Usage: duration num ms|s|m|h\n";
        //         return 1;
        //     }
        //     auto duration = parseDuration(argv[1], argv[2], std::chrono::milliseconds{1500});
        //     std::cout << "That's " << duration.count() << '\n';
    private:
        std::chrono::time_point<std::chrono::system_clock> start_;
        std::chrono::time_point<std::chrono::system_clock> end_;
    };
}
