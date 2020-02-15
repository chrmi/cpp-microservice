#pragma once

namespace chrmi 
{
    class Logger
    {
    public:
        Logger() {}
        std::pair<const std::string, const std::string> log(const std::string);
    };
}
