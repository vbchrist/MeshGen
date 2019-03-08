#include <CGAL/Simple_cartesian.h>

class actor{

    typedef CGAL::cpp11::array<double, 3> point;
    //Methods
    void modify_orientation(){};
    bool advance(){
        // Modify position vector
        // Add orientation vector to position vector 
        // Check for an intersection of the line segment between new and old position vs all enviroment surface meshes
        // If interset == false
        //  Set new position    
        //  Return true
        // Else 
        //  Return false
    };

    //Objects
    point position;
    point orientation;
    //pattern line; 
}