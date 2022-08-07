#ifndef CYLINDER_H
#define CYLINDER_H


class Cylinder {
    private:
        double base_radius = 1;
        double height = 1;
    public:
        Cylinder() = default;
        Cylinder(double radius_param, double height_param);
        //Functions (methods)
        double volume();
        // Getter
        double get_radius();
        double get_height();
        // Setter
        void set_radius(double radius);
        void set_height(double height_param);
};

#endif