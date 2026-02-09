#include "ScalarConvert.hpp"
#include <cerrno>
#include <climits>

bool toCharFromInt(int i, char& c)
{
	if (i < 0 || i > 127)
		return false;
	c = static_cast<char>(i);
	return true;
}

bool toInt(const std::string& s, int& out)
{
	char* end;
	errno = 0;
	long val = std::strtol(s.c_str(), &end, 10);

	if (*end != '\0' || errno == ERANGE || val < INT_MIN || val > INT_MAX)
		return false;

	out = static_cast<int>(val);
	return true;
}

bool toDouble(const std::string& s, double& out)
{
	char* end;
	errno = 0;
	out = std::strtod(s.c_str(), &end);

	if (*end != '\0' || errno == ERANGE)
		return false;
	if (out > static_cast<double>(std::numeric_limits<int>::max()) ||
		out > static_cast<double>(std::numeric_limits<int>::max()))
		return false;
	return true;
}

bool toFloatFromDouble(double d, float& f)
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
