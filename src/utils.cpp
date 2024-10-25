#include "utils.hpp"

#ifdef __APPLE__
    // This helps determine which type of Apple device we are compiling for
    // TARGET_OS_MAC and TARGET_OS_IPHONE are the important ones
    #include <TargetConditionals.h>
#endif

#include <iostream>


namespace LCode::Utils
{
void check_platform(std::ostream & os)
{
    #ifndef NDEBUG
        os << "[Compiled in Debug Mode.]\n";
    #endif

    #ifdef TEMPLATE_SEPARATE_COMPILATION
        os << "[Template Class Separate Compilation is active.]\n";
    #endif

    #if defined(__unix__) || defined(__linux__)
        os << "[Linux build detected.]\n";
    #elif defined(_WIN32)
        os << "[Windows build detected.]\n";
    #elif defined(__APPLE__) && defined(TARGET_OS_MAC)
        os << "[Mac OS build detected.]\n";
    #endif   
}

void list_cmd_args(const int & argc, char ** const & argv, bool force_print, std::ostream & os)
{
    if (argc > 1 || force_print)
    {
        os << "Command line arguments given:\n";
        for (int i = !force_print; i < argc; ++i)
        {
            os << '"' << argv[i] << "\"\n";
        }
    }
}
}