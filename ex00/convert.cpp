#include "ScalarConverter.hpp"
#include <cerrno>
#include <climits>
                                                  
bool stringToInt(const std::string& s, int& out)
{
	char* end;
	errno = 0;
	long val = std::strtol(s.c_str(), &end, 10);

	if (*end != '\0' || errno == ERANGE || val < INT_MIN || val > INT_MAX)
		return false;

	out = static_cast<int>(val);
	return true;
}                          

bool stringToDouble(const std::string& s, double& out)
{
	char* end;
	errno = 0;
	out = std::strtod(s.c_str(), &end);

	if (*end != '\0' || errno == ERANGE)
		return false;

	return true;
}

bool stringToFloat(const std::string& s, float& f)
{
	char* end;
    errno = 0;
    f = std::strtof(s.c_str(), &end);

    if (*end != '\0' && std::string(end) != "f")
        return false;
    if (errno == ERANGE)
        return false;

    return true;
}




bool intToChar(int i, char& c)
{
	if (i < 0 || i > 127)
		return false;
	c = static_cast<char>(i);
	return true;
}

bool intToDouble(int i, double& d)
{
	d =static_cast<double>(i);
	return true;
}

bool intToFloat(int i, float& f)
{
	f = static_cast<float>(i);
	return true;
}



bool doubleToChar(double d, char& c)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d < 127)
		return false;
	c = static_cast<char>(d);
	return true;
}

bool doubleToInt(double d, int& i)
{
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        return false;
    i = static_cast<int>(d);
    return true;
}

bool doubleToFloat(double d, float& f)
{
	if (std::isnan(d) || std::isinf(d))
	{
		f = static_cast<float>(d);
		return true;
	}
	if (d < -std::numeric_limits<float>::max() ||
		d > std::numeric_limits<float>::max())
		return false;
	f = static_cast<float>(d);
	return true;
}



bool floatToChar(float f, char& c)
{
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        return false;
    c = static_cast<char>(f);
    return true;
}

bool floatToInt(float f, int& i)
{
	if (std::isnan(f) || std::isinf(f) || f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
        return false;
    i = static_cast<int>(f);
    return true;
}

bool floatToDouble(float f, double& d)
{
	d = static_cast<float>(f);
	return true;
}