#include <filesystem>
#include <fstream>
#include <counter.hh>

auto loc::Counter::Count(const std::string& filename) -> Result
{
    std::ifstream file(filename);
    if (!file.is_open())
        return Result();

    Result result;
    result.Files = 1;

    std::string line;

    while (std::getline(file, line))
    {
        result.Lines++;
        result.Characters += line.size();

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
                result.Words++;
            }
        }
    }

    file.close();
    return result;
}

auto loc::Counter::CountDirectory(const std::string& directory) -> Result
{
    Result result;
    std::filesystem::recursive_directory_iterator it(directory);
    std::filesystem::recursive_directory_iterator end;

    while (it != end)
    {
        if (std::filesystem::is_regular_file(it->path()))
            result += Count(it->path());

        ++it;
    }

    return result;
}
