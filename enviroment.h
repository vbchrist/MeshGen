#include <vector>

class enviroment(){

typedef CGAL::Simple_cartesian<double> Kernel;
typedef CGAL::Surface_mesh<Kernel::Point_3> Mesh;

public:
    enviroment(Mesh bounding_geom):bounding_geom(bounding_geom_){};
    bool add_internal_geom(){};
private:
    Mesh bounding_geom_;
    std::vector<Mesh> internal_components;
}



Class Enviroment
Methods 
    Build from surface_mesh 
    Add internal geometry
        Mesh intersection detection
Objects
    surface_mesh        external surface
vec<surface_mesh> list of internal objects defined by surface meshes