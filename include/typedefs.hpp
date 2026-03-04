#pragma once
#include <string>


#define P(f, x) f->x
#define TO_STRING(x) #x

namespace solv
{
    typedef std::vector<double (*)(double, std::vector<double>)> SysOfDeq;

    typedef struct
    {

        double x{};
        double y{};
        double xfin{};
        double (*deqs)(double, double);

    } Deq;

    typedef struct
    {

        double x{};
        std::vector<double> y;
        double xfin{};
        SysOfDeq deqs;
    } MDeq;
} // namespace solv
