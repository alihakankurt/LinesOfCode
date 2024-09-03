#include <Result.hpp>

namespace loc
{
    auto Result::operator+=(const Result& other) -> Result&
    {
        Files += other.Files;
        Lines += other.Lines;
        Words += other.Words;
        Characters += other.Characters;
        return *this;
    }

    auto operator<<(std::ostream& os, const Result& result) -> std::ostream&
    {
        os << result.Files << " files, "
           << result.Lines << " lines, "
           << result.Words << " words, "
           << result.Characters << " characters";
        return os;
    }
}
