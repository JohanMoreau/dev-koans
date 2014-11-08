#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <cassert>

struct point3d{ float x,y,z,w; };

std::ostream& operator<<(std::ostream& os, const point3d& p)
{
	return os << "[" << p.x << " - " << p.y << " - " << p.z << " - " << p.w << "]";
}

std::istream& operator>>(std::istream& is, point3d& p)
{
	return is >> p.x >> p.y >> p.z >> p.w;
}

point3d sum(const point3d& a, const point3d& b)
{
	return {a.x + b.w*b.x ,a.y + b.w*b.y ,a.z + b.w*b.z ,a.w + b.w};
}

float dist(const point3d& a, const point3d& b)
{
	auto dx = a.x - b.x;
	auto dy = a.y - b.y;
	auto dz = a.z - b.z;
	return dx*dx+dy*dy+dz*dz;
}

bool compare(const point3d& ref, const point3d& a, const point3d& b )
{
	return dist(a,ref) < dist(b,ref);
}

class vector_w3dp: private std::vector<point3d>
{
	public:
	using parent = std::vector<point3d>;
	using parent::push_back;
	using parent::operator[];
	using parent::begin;
	using parent::end;
	using parent::size;
	using parent::vector;

	point3d barycentre()
	{
		point3d that = std::accumulate(begin(), end(), point3d{}, []
			(point3d const& bary, point3d const& cur) 
			{ return sum(bary, cur); });
		that.x /= that.w;
		that.y /= that.w;
		that.z /= that.w;
		that.w = 1.;
		return that;
	}

	point3d find_neareast(point3d const& ref)
	{
		assert( this->size() );
		return *std::min_element(begin(), end(), [&ref]
			(point3d const& a, point3d const& b) 
			{ return compare(ref,a,b); });

	}
};

vector_w3dp read_points( std::string const& filename)
{
	vector_w3dp that;
	std::ifstream file(filename.c_str());
	if (file.is_open())
	{
		std::string line;
		while(std::getline(file,line))
		{
			std::istringstream oss(line);
			point3d p;
			oss >> p;
			that.push_back(p);
		}
	}
	return that;
}

int main()
{
	vector_w3dp v = read_points("test.txt");
	for(auto const& myP : v)
		std::cout << myP << std::endl;
	std::cout << "barycentre : " << v.barycentre() << std::endl;
	std::cout << "point proche bary: " << v.find_neareast(v.barycentre()) << std::endl;

	return 0;
}
