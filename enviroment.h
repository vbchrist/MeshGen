#include <vector>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>

class enviroment
{
    typedef CGAL::Simple_cartesian<double> Kernel;
    typedef CGAL::Surface_mesh<Kernel::Point_3> Mesh;

  public:
    enviroment(Mesh bounding_geom) : bounding_geom_(bounding_geom){};
    bool add_internal_geom(Mesh internal_component)
    {
        bool intersect = CGAL::Polygon_mesh_processing::do_intersect(bounding_geom_, internal_component);
        if (!intersect)
        {
            internal_components.emplace_back(internal_component);
            return true;
        }
        return false;
    };

  private:
    Mesh bounding_geom_;
    std::vector<Mesh> internal_components;
}