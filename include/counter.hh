#pragma once

namespace loc
{
    struct Result
    {
        int Files;
        int Lines;
        int Words;
        int Characters;

        Result() : Files(0), Lines(0), Words(0), Characters(0)
        {
        }

        auto operator+=(const Result& other) -> Result&
        {
            Files += other.Files;
            Lines += other.Lines;
            Words += other.Words;
            Characters += other.Characters;
            return *this;
        }
    };

    class Counter
    {
      public:
        Counter() = default;
        auto Count(const std::string& filename) -> Result;
        auto CountDirectory(const std::string& directory) -> Result;
    };
}
