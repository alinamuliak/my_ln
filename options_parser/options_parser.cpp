// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <filesystem>
#include <iostream>
#include "options_parser.h"

namespace po = boost::program_options;

command_line_options_t::command_line_options_t() {
    opt_conf.add_options()
        ("help,h",
                "Show help message")
        ("soft,s",
                "Soft link creation")
        ("hard,h", "Hard link creation")
        ;
}

command_line_options_t::command_line_options_t(int ac, char **av):
        command_line_options_t() // Delegate constructor
{
    parse(ac, av);
}

void command_line_options_t::parse(int ac, char **av) {
    try {
        po::parsed_options parsed = po::command_line_parser(ac, av).options(opt_conf).allow_unregistered().run();
        po::store(parsed, var_map);
        auto files = po::collect_unrecognized(parsed.options, po::include_positional);
        if (var_map.count("help")) {
            std::cout << opt_conf << std::endl;
            exit(EXIT_SUCCESS);
        }

        if (var_map.count("soft")) {
            if (var_map.count("hard")) {
                std::cerr << "Specify one link type: soft of hard!" << std::endl;
                exit(EXIT_FAILURE);
            }
            symblink = true;
        }
        if (files.size() > 2) {
            std::cerr << opt_conf << std::endl;
            exit(EXIT_FAILURE);
        }

        src = files[0];
        dst = files[1];
        if (!file_exist(src)) {
            std::cerr <<"File '" << src << "' not found!" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (file_exist(dst)) {
            std::cerr <<"File '" << dst << "' already exists!" << std::endl;
            exit(EXIT_FAILURE);
        }

        po::notify(var_map);
    } catch (std::exception &ex) {
        throw OptionsParseException(ex.what()); // Convert to our error type
    }
}

bool file_exist(const std::string &f_name) {
    if (std::filesystem::exists(f_name)) {
        return true;
    }
    return false;
}