// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <unistd.h>
#include "options_parser.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {
    command_line_options_t command_line_options{argc, argv};
    auto src = command_line_options.get_sourse();
    auto dst = command_line_options.get_destination();
    if (command_line_options.is_soft_link()) {
        if (symlink(src.c_str(), dst.c_str()) != 0) {
            cerr << "Cannot create soft link:(" << endl;
            return errno;
        }
    } else {
        if (link(src.c_str(), dst.c_str()) != 0) {
            cerr << "Cannot create hard link:(" << endl;
            return errno;
        }
    }
    return EXIT_SUCCESS;
}
