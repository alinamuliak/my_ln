#ifndef MYCAT_CONFIG_FILE_H
#define MYCAT_CONFIG_FILE_H

#include <boost/program_options.hpp>
#include <string>
#include <exception>
#include <stdexcept>

class OptionsParseException : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

bool file_exist(const std::string &f_name);

class command_line_options_t {
public:
    command_line_options_t();
    command_line_options_t(int ac, char **av);

    //! Explicit is better than implicit:
    command_line_options_t(const command_line_options_t&) = default;
    command_line_options_t& operator=(const command_line_options_t&) = delete;
    command_line_options_t(command_line_options_t&&) = default;
    command_line_options_t& operator=(command_line_options_t&&) = delete;
    ~command_line_options_t() = default;

    [[nodiscard]] std::string get_sourse() const { return src; };
    [[nodiscard]] std::string get_destination() const { return dst; };

    [[nodiscard]] bool is_soft_link() const { return symblink; };

    void parse(int ac, char **av);
private:
    std::string src;
    std::string dst;
    bool symblink = false;

    boost::program_options::variables_map var_map{};
    boost::program_options::options_description opt_conf{
            "Config File Options:\n\tmy_ln [--soft|--hard|--help] source dest\n"};
};

#endif //MYCAT_CONFIG_FILE_H

