#include "stdafx.h"

#include <chrono> 
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>

#include <iostream>
#include <fstream>

#include "Logger.h"

string timestamp()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%X");
    return ss.str();
}

void Logger::log(const string msg) {
    const std::string ts = timestamp();

    std::cout << "\nMessage: " << msg << "\nTime: " << ts << '\n';

    ofstream myfile;
    myfile.open ("/home/me/logs/cppsvc_" + ts + ".log");
    myfile << "\n" << msg;
    myfile.close();
}
