#include <iostream>
#include <filesystem>
#include <counter.hh>

int main(int argc, char** argv)
{
    loc::Counter counter;
    loc::Result result;

    for (int i = 0; i < argc; i++)
    {
        if (std::filesystem::is_directory(argv[i]))
        {
            result += counter.CountDirectory(argv[i]);
            continue;
        }

        result += counter.Count(argv[i]);
    }

    std::cout << "Files: " << result.Files << std::endl;
    std::cout << "Lines: " << result.Lines << std::endl;
    std::cout << "Words: " << result.Words << std::endl;
    std::cout << "Characters: " << result.Characters << std::endl;
    return 0;
}
