// std
#include <iostream>
#include <string>
#include <memory>

// CGAL
#include <CGAL/IO/STL_reader.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/bbox.h>

//local
#include "STL.h"
#include "enviroment.h"

int main(int argc, char *argv[])
{
    typedef CGAL::Simple_cartesian<double> Kernel;
    typedef CGAL::Surface_mesh<Kernel::Point_3> Surface_Mesh;

    STL_manager stl;

    // Import the enviroment mesh and the
    std::string enviro_stl = "/home/ch816772/MeshGen/tank.STL";
    std::string obj_stl = "/home/ch816772/MeshGen/block.STL";
    std::string out_stl = "/home/ch816772/MeshGen/out.STL";

    Surface_Mesh mesh;
    stl.import_STL(enviro_stl, mesh);
    enviroment e(mesh);

    stl.import_STL(obj_stl, mesh);
    e.add_internal_geom(mesh);

    std::cout << " Location [" << CGAL::Polygon_mesh_processing::bbox(e.get_component_mesh(0)) << "]\n";

    for (double t = 0; t < 10; t++)
    {
        e.advance(t);
        std::cout << " Location [" << CGAL::Polygon_mesh_processing::bbox(e.get_component_mesh(0)) << "]\n";
    }

    //stl.export_STL(out_stl, *(e.get_component(0)));

    return 0;
}