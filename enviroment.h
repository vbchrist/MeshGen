#include <vector>
#include <memory>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/transform.h>

#include "component.h"

class enviroment
{
  typedef CGAL::Simple_cartesian<double> Kernel;
  typedef CGAL::Surface_mesh<Kernel::Point_3> Mesh;

public:
  enviroment(Mesh &bounding_geom) : bounding_geom_(bounding_geom){};
  bool add_internal_geom(Mesh internal_component)
  {
    /*
        bool intersect = CGAL::Polygon_mesh_processing::do_intersect(bounding_geom_, internal_component);
        if (!intersect)
        {
            internal_components.emplace_back(internal_component);
            return true;
        }
        return false;
        */
    internal_components.emplace_back(internal_component);
    return true;
  };

  bool advance(double &time_step)
  {
    internal_components[0].translate(Kernel::Vector_3(0,1,0));
  };

  Mesh get_component_mesh(size_t idx)
  {
    return internal_components[idx].get_mesh();
  };

private:
  Mesh bounding_geom_;
  std::vector<component> internal_components;
};