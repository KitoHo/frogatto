/*
	Copyright (C) 2003-2013 by David White <davewx7@gmail.com>
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef DECIMAL_HPP_INCLUDED
#define DECIMAL_HPP_INCLUDED

#include <string>

#include <iosfwd>
#include <boost/cstdint.hpp>
#if defined(TARGET_BLACKBERRY)
#include <math.h>
#endif

static const int64_t DECIMAL_PRECISION = 1000000;
static const int64_t DECIMAL_PLACES = 6;

class decimal
{
public:
	static decimal from_string(const std::string& s);
	static decimal from_int(int v) { return decimal(v); }
	static decimal from_raw_value(int64_t v) { decimal d; d.value_ = v; return d; }
	static decimal epsilon() { return decimal::from_raw_value(static_cast<int64_t>(1)); }
	decimal() : value_(0) {}
	explicit decimal(int value) : value_(int64_t(value)*DECIMAL_PRECISION) {}
#if defined(TARGET_BLACKBERRY)
	explicit decimal(double value) : value_(llround(value*DECIMAL_PRECISION)) {}
#else
	explicit decimal(double value) : value_(int64_t(value*DECIMAL_PRECISION)) {}
#endif

	int64_t value() const { return value_; }
	int as_int() const { return int( value_/DECIMAL_PRECISION ); }
	float as_float() const { return value_/float(DECIMAL_PRECISION); }
	int64_t fractional() const { return value_%DECIMAL_PRECISION; }

	decimal operator-() const {
		return decimal(from_raw_value(-value_));
	}

	friend decimal operator+(const decimal& a, const decimal& b);
	friend decimal operator-(const decimal& a, const decimal& b);
	friend decimal operator*(const decimal& a, const decimal& b);
	friend decimal operator/(const decimal& a, const decimal& b);

	void operator+=(decimal a) { *this = *this + a; } 
	void operator-=(decimal a) { *this = *this - a; } 
	void operator*=(decimal a) { *this = *this * a; } 
	void operator/=(decimal a) { *this = *this / a; }

	void operator+=(int a) { operator+=(decimal::from_int(a)); } 
	void operator-=(int a) { operator-=(decimal::from_int(a)); } 
	void operator*=(int a) { operator*=(decimal::from_int(a)); } 
	void operator/=(int a) { operator/=(decimal::from_int(a)); }

private:
	int64_t value_;
};

inline decimal operator+(const decimal& a, const decimal& b) {
	return decimal::from_raw_value(a.value() + b.value());
}

inline decimal operator-(const decimal& a, const decimal& b) {
	return decimal::from_raw_value(a.value() - b.value());
}

decimal operator*(const decimal& a, const decimal& b);
decimal operator/(const decimal& a, const decimal& b);

inline bool operator==(const decimal& a, const decimal& b) {
	return a.value() == b.value();
}

inline bool operator!=(const decimal& a, const decimal& b) {
	return !operator==(a, b);
}

inline bool operator<=(const decimal& a, const decimal& b) {
	return a.value() <= b.value();
}

inline bool operator>=(const decimal& a, const decimal& b) {
	return b <= a;
}

inline bool operator<(const decimal& a, const decimal& b) {
	return !(b <= a);
}

inline bool operator>(const decimal& a, const decimal& b) {
	return !(a <= b);
}

inline decimal operator+(decimal a, int b) { return operator+(a, decimal::from_int(b)); }
inline decimal operator-(decimal a, int b) { return operator-(a, decimal::from_int(b)); }
inline decimal operator*(decimal a, int b) { return operator*(a, decimal::from_int(b)); }
inline decimal operator/(decimal a, int b) { return operator/(a, decimal::from_int(b)); }
inline bool operator<(decimal a, int b) { return operator<(a, decimal::from_int(b)); }
inline bool operator>(decimal a, int b) { return operator>(a, decimal::from_int(b)); }
inline bool operator<=(decimal a, int b) { return operator<=(a, decimal::from_int(b)); }
inline bool operator>=(decimal a, int b) { return operator>=(a, decimal::from_int(b)); }

inline decimal operator+(int a, decimal b) { return operator+(decimal::from_int(a), b); }
inline decimal operator-(int a, decimal b) { return operator-(decimal::from_int(a), b); }
inline decimal operator*(int a, decimal b) { return operator*(decimal::from_int(a), b); }
inline decimal operator/(int a, decimal b) { return operator/(decimal::from_int(a), b); }
inline bool operator<(int a, decimal b) { return operator<(decimal::from_int(a), b); }
inline bool operator>(int a, decimal b) { return operator>(decimal::from_int(a), b); }
inline bool operator<=(int a, decimal b) { return operator<=(decimal::from_int(a), b); }
inline bool operator>=(int a, decimal b) { return operator>=(decimal::from_int(a), b); }

std::ostream& operator<<(std::ostream& s, decimal d);

#endif
