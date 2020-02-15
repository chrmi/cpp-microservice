#include "stdafx.h"

#include <chrono> 
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>

#include <iostream>
#include <fstream>

#include "logger.h"

namespace chrmi
{
    std::string timestamp()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%X");
        return ss.str();
    }

    std::pair<const std::string, const std::string> Logger::log(const std::string msg) {
        const std::string ts = timestamp();

        std::ofstream log_file;
        log_file.open ("./logs/cppsvc_" + ts + ".log");
        log_file << "\nMessage: " + msg + ", Time: " + ts << std::endl;
        log_file.close();

        return std::make_pair(msg, ts);
    }
}
