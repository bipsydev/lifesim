#include <iostream>

namespace LCode::Utils
{
void check_platform(std::ostream & desired_ostream = std::cout);
void list_cmd_args(const int & argc, char ** const & argv,
                   bool force_print = false,
                   std::ostream & desired_ostream = std::cout);
}