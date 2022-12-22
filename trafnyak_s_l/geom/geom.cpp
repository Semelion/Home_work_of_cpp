#define _USE_MATH_DEFINES
#include "geom.hpp"
#include <cmath>
#include<iostream>
#include <limits>


std::ostream& operator<<(std::ostream& ostrm, const geom::Rdec2D& z) {
	return ostrm << '(' << z.x << ',' << z.y << ')';
}
std::ostream& operator<<(std::ostream& ostrm, const geom::Rpol2D& z) {
	return ostrm << '[' << z.r << ',' << z.phi << ']';
}
geom::Rdec2D operator-(const geom::Rdec2D& lhs) {
	return { -lhs.x, -lhs.y };
}
geom::Rpol2D operator-(const geom::Rpol2D& lhs) {
	if (lhs.phi >= M_PI) {
		return { lhs.r, lhs.phi - M_PI };
	}
	else {
		return { lhs.r, lhs.phi + M_PI };
	}
}
void operator-=(geom::Rdec2D& lhs, geom::Rdec2D& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
}
void operator-=(geom::Rpol2D& lhs, geom::Rpol2D& rhs) {
	geom::Rdec2D vectr1 = ToDec(lhs);
	geom::Rdec2D vectr2 = ToDec(rhs);
	vectr1.x -= vectr2.x;
	vectr1.y -= vectr2.y;
	lhs = geom::ToPol(vectr1);
}

geom::Rdec2D operator+(const geom::Rdec2D& lhs, const geom::Rdec2D& rhs) {
	return { lhs.x + rhs.x, lhs.y + rhs.y };
}
geom::Rpol2D operator+(const geom::Rpol2D& lhs, const geom::Rpol2D& rhs) {
	geom::Rdec2D vectr1 = ToDec(lhs);
	geom::Rdec2D vectr2 = ToDec(rhs);
	return geom::ToPol({ vectr1.x + vectr2.x, vectr1.y + vectr2.y });
}

void operator+=(geom::Rdec2D& lhs, geom::Rdec2D& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
}

void operator+=(geom::Rpol2D& lhs, geom::Rpol2D& rhs) {
	geom::Rdec2D vectr1 = ToDec(lhs);
	geom::Rdec2D vectr2 = ToDec(rhs);
	vectr1.x += vectr2.x;
	vectr1.y += vectr2.y;
	lhs = geom::ToPol(vectr1);
	//rhs = geom::ToPol(vectr2);
}

geom::Rdec2D operator-(const geom::Rdec2D& lhs, const geom::Rdec2D& rhs) {
	return { lhs.x - rhs.x, lhs.y - rhs.y };
}
geom::Rpol2D operator-(const geom::Rpol2D& lhs, const geom::Rpol2D& rhs) {
	geom::Rdec2D vectr1 = ToDec(lhs);
	geom::Rdec2D vectr2 = ToDec(rhs);
	return geom::ToPol({ vectr1.x - vectr2.x, vectr1.y - vectr2.y });
}

geom::Rdec2D operator*(const geom::Rdec2D& lhs, const double& nmbr) {
	return { nmbr * lhs.x,nmbr * lhs.y };
}
geom::Rpol2D operator*(const geom::Rpol2D& lhs, const double& nmbr) {
	return { lhs.r * nmbr, lhs.phi };
}

geom::Rdec2D operator /(const geom::Rdec2D& lhs, const double& nmbr) {
	return {lhs.x/nmbr, lhs.y/nmbr };
}
geom::Rpol2D operator /(const geom::Rpol2D& lhs, const double& nmbr) {
	return { lhs.r / nmbr, lhs.phi };
}

double Dot(const geom::Rdec2D& lhs, const geom::Rdec2D& rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y;
}
double Dot(const geom::Rpol2D& lhs, const geom::Rpol2D& rhs) {
	return (lhs.r * rhs.r * std::cos(std::abs(lhs.phi - rhs.phi)));
}

double geom::Norm(const geom::Rdec2D& lhs) {
	return sqrt(lhs.x * lhs.x + lhs.y * lhs.y);
}

geom::Rdec2D ToDec(const geom::Rpol2D& lhs) {
	return { lhs.r * std::cos(lhs.phi), lhs.r * std::sin(lhs.phi) };
}
geom::Rpol2D geom::ToPol(const geom::Rdec2D& lhs) {
	if (lhs.y > 0) {
		return { geom::Norm(lhs), std::acos(lhs.x / geom::Norm(lhs)) };
	}
	else {
		return { geom::Norm(lhs), 2 * M_PI - std::acos(lhs.x / geom::Norm(lhs)) };
	}
}

bool operator ==(const geom::Rpol2D& lhs, const geom::Rpol2D& rhs) {
	return ((std::abs(lhs.r - rhs.r) < geom::epsl) && (std::abs(lhs.phi - rhs.phi) < geom::epsl));
}
bool operator ==(const geom::Rdec2D& lhs, const geom::Rdec2D& rhs) {
	return (std::abs(geom::Norm(rhs)-geom::Norm(lhs))<geom::epsl && std::abs(rhs.x/lhs.x-rhs.y/lhs.y)<geom::epsl);
}
bool operator!=(const geom::Rpol2D& lhs, const geom::Rpol2D& rhs) {
	return !((std::abs(lhs.r - rhs.r) < geom::epsl) && (std::abs(lhs.phi - rhs.phi) < geom::epsl));
}
bool operator!=(const geom::Rdec2D& lhs, const geom::Rdec2D& rhs) {
	return !(std::abs(geom::Norm(rhs) - geom::Norm(lhs))<geom::epsl && std::abs(rhs.x / lhs.x - rhs.y / lhs.y)<geom::epsl);
}