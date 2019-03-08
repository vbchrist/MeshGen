#include <vector>

struct pattern{
    typedef CGAL::cpp11::array<double, 3> point;
//Constructor
    pattern(){};
//Objects
    std::vector<point> polyline;
}

