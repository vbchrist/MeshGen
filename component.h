
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/transform.h>

#include <CGAL/Min_sphere_of_spheres_d.h>
#include <CGAL/Min_sphere_of_points_d_traits_3.h>

class component
{

    typedef CGAL::Simple_cartesian<double> Kernel;
    typedef Kernel::Point_3 Point;
    typedef Kernel::Vector_3 Vector;
    typedef Kernel::Direction_3 Direction;
    typedef CGAL::Surface_mesh<Kernel::Point_3> Surface_Mesh;

    typedef CGAL::Min_sphere_of_points_d_traits_3<Kernel, double> Traits;
    typedef CGAL::Min_sphere_of_spheres_d<Traits> Min_sphere;

  public:
    component(Surface_Mesh &mesh) : mesh_(mesh)
    {
        // The vertex iterator type is a nested type of the Vertex_range
        Surface_Mesh::Vertex_range::iterator vb, ve;
        Surface_Mesh::Vertex_range r = mesh_.vertices();
        // The iterators can be accessed through the C++ range API
        //vb = r.begin();
        //ve = r.end();
        // or the boost Range API
        vb = boost::begin(r);
        ve = boost::end(r);

        //Min_sphere(); // check in the sphepoints
        //CGAL_assertion(ms.is_valid());
        //std::cout << "Bounding sphere is " << ms.discriminant() << "\n";
        //std::cout << "Bounding sphere rad is " << ms.radius() << "\n";
    };

    bool translate(const Vector &translation_vector)
    {
        CGAL::Polygon_mesh_processing::transform(Kernel::Aff_transformation_3(CGAL::TRANSLATION, translation_vector), mesh_);
    }

    Surface_Mesh get_mesh()
    {
        return mesh_;
    }

  private:
    // center_of_gravity
    Point cog;
    // orientation
    Direction orientation;
    // center_of_collision
    Point coc;
    double rad;
    // Surface mesh
    Surface_Mesh mesh_;
};