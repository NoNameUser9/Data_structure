#pragma once
// ReSharper disable once CppInconsistentNaming
namespace NNU9
{
    void swap(auto& a, auto& b) noexcept
    {
        const auto temp = b;
        b = a;
        a = temp;
    }
}