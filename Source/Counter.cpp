#include <Counter.hpp>

#include <iostream>
#include <fstream>

namespace loc
{
    auto Counter::Count(int argc, const char* argv[]) -> Result
    {
        Result result{};
        Counter counter{};
        for (int argi = 1; argi < argc; argi += 1)
        {
            if (std::filesystem::is_directory(argv[argi]))
            {
                result += counter.CountDirectory(argv[argi]);
            }
            else if (std::filesystem::is_regular_file(argv[argi]))
            {
                result += counter.CountFile(argv[argi]);
            }
            else
            {
                std::cerr << "Invalid path: " << argv[argi] << std::endl;
            }
        }

        return result;
    }

    auto Counter::CountFile(const std::filesystem::path& filename) -> Result
    {
        auto file = std::ifstream{filename};
        if (!file.is_open())
            return Result{};

        Result result{};
        result.Files = 1u;

        std::string line;
        while (std::getline(file, line))
        {
            if (line.empty())
                continue;

            result.Lines += 1u;
            result.Characters += line.length();

            bool inWord = false;
            for (auto c : line)
            {
                if (std::isspace(c))
                {
                    inWord = false;
                }
                else if (!inWord)
                {
                    inWord = true;
                    result.Words += 1u;
                }
            }
        }

        file.close();
        return result;
    }

    auto Counter::CountDirectory(const std::filesystem::path& directory) -> Result
    {
        Result result{};

        for (auto& entry : std::filesystem::recursive_directory_iterator{directory})
            if (std::filesystem::is_regular_file(entry.path()))
                result += CountFile(entry.path());

        return result;
    }
}
