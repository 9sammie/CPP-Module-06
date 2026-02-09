#include "ScalarConvert.hpp"
#include <climits>

int literalType(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return (DOUBLE);
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (FLOAT);
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);

	size_t	i = 0;
	bool	has_digit = false;
	bool	has_dot = false;
	bool	has_f = false;

    if ((str[i] == '+' || str[i] == '-') && i == 0)
        i++;
	while (str[i])
	{
		if (std::isdigit(str[i]))
			has_digit = true;
		else if (str[i] == '.' && !has_dot && !has_f)
			has_dot = true;
		else if (str[i] == 'f' && i == str.length() - 1 && has_dot)
			has_f = true;
		else
			return OTHER;
		i++;
	}
	if (!has_digit)
		return OTHER;
	if (!has_dot && !has_f)
		return INT;
	if (has_dot && !has_f)
		return DOUBLE;
	if (has_dot && has_f)
		return FLOAT;
	return (OTHER);
}

void invalidate_all(bool& c, bool& i, bool& f, bool& d)
{
    c = i = f = d = false;
}

void cast(const std::string& str, int type)
{
	char	c;
	int		i;
	float	f;
	double	d;

	bool char_ok = true;
	bool int_ok = true;
	bool float_ok = true;
	bool double_ok = true;
    std::string tmp = str;


	switch (type)
	{
		case CHAR:
			c = str[0];
			i = static_cast<int>(c);
			d = static_cast<double>(c);
			f = static_cast<float>(c);
			break;

		case INT:
			int_ok = toInt(str, i);
			if (!int_ok)
			{
				char_ok  = false;
				double_ok = toDouble(str, d);
				float_ok = double_ok && toFloatFromDouble(d, f);
				break;
			}
			char_ok = toCharFromInt(i, c);
			d = static_cast<double>(i);
			f = static_cast<float>(i);
			break;

		case FLOAT:
    	    if (!tmp.empty() && tmp.back() == 'f')
    	        tmp.pop_back();
		
    	    double_ok = toDouble(tmp, d);
    	    if (!double_ok)
    	    {
    	        invalidate_all(char_ok, int_ok, double_ok, float_ok);
    	        break;
    	    }
		
    	    int_ok = (d >= INT_MIN && d <= INT_MAX);
    	    if (int_ok)
    	        i = static_cast<int>(d);
		
    	    char_ok = int_ok && toCharFromInt(i, c);
    	    float_ok = toFloatFromDouble(d, f);
	    	break;
		
		case DOUBLE:
			double_ok = toDouble(str, d);
			if (!double_ok)
			{
				invalidate_all(char_ok, int_ok, double_ok, float_ok);			
				break;
			}
			int_ok = (d >= INT_MIN && d <= INT_MAX);
			if (int_ok)
				i = static_cast<int>(d);
			char_ok = int_ok && toCharFromInt(i, c);
			float_ok = toFloatFromDouble(d, f);
			break;

		default:
			char_ok = int_ok = float_ok = double_ok = false;
	}

	print_char(char_ok, c);
	print_int(int_ok, i);
	print_double(double_ok, d);
	print_float(float_ok, f);
}
