#pragma once

#include <cstddef>
#include <iostream>

namespace loc
{
    struct Result
    {
        std::size_t Files{};
        std::size_t Lines{};
        std::size_t Words{};
        std::size_t Characters{};

        Result() = default;
        auto operator+=(const Result& other) -> Result&;
    };

    auto operator<<(std::ostream& os, const Result& result) -> std::ostream&;
}
