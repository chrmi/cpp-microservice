#include "logger_file.h"
#include "inc/utils.h"

#include <string>
#include <iostream>

namespace chrmi {
    LoggerFile::LoggerFile() {};

    LoggerFile::LoggerFile(const std::string &path) {
        this->path = path;
    };

    const std::string LoggerFile::LoggerFile::log() const {
        const auto time = chrmi::Utils::timestamp();

        const auto time_written = chrmi::Utils::write_file(this->path);

        return time_written;
    };

    const std::pair<const std::string, const std::string> 
        LoggerFile::LoggerFile::log(const std::string &msg) const {
            const auto time = chrmi::Utils::timestamp();

            const auto time_written = chrmi::Utils::write_file(
                    std::pair<const std::string, const std::string> {this->path, msg});

        return time_written;
    };
};
