#pragma once

#include <Result.hpp>

#include <filesystem>

namespace loc
{
    class Counter
    {
      public:
        Counter() = default;

      public:
        static auto Count(int argc, const char* argv[]) -> Result;

      private:
        auto CountFile(const std::filesystem::path& filename) -> Result;
        auto CountDirectory(const std::filesystem::path& directory) -> Result;
    };
}
