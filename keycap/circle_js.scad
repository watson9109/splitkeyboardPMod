$fs = 0.01;
sqrt_3 = 1.7320508;
sticktop_diameter = 12; 
sticktop_height = 4;
sticktop_dimple = 1;
stem_thickness = 1.0;
stem_c_diameter = 4.1;
stem_l_interval = 3.1;
stem_height = 3.0;





translate([20, 0 ,0]){

}



module cylinderOneSideChamfered (diameter, height, depth) 
{
    minkowski () {
        cylinder(d = diameter-2*depth, h = height-(1*depth));
        cylinder(h= depth, r1 = depth, r2 =0);
    }
}


difference() {
    cylinderOneSideChamfered(sticktop_diameter, sticktop_height, 1);
    translate([0, 0, sticktop_height+(sticktop_dimple^2 + (sticktop_diameter/2-1)^2)/(2*sticktop_dimple)-sticktop_dimple]){
        sphere((sticktop_dimple^2 + (sticktop_diameter/2-1)^2)/(2*sticktop_dimple));
    }
}
//cylinder(d = sticktop_diameter, h = sticktop_height);

translate([0, 0, -stem_height]) 
{
    difference () 
    {
        cylinder(d = 2 * stem_thickness + stem_c_diameter, h = stem_height);      
        translate([0,0,-0.2]) 
        {
            difference () 
            {
                cylinder(d = stem_c_diameter, h = stem_height+0.4);
                translate([stem_c_diameter/2 + stem_l_interval/2, 0, 0]) 
                    cube([stem_c_diameter, stem_c_diameter, 10], center=true);
                translate([-stem_c_diameter/2 - stem_l_interval/2, 0, 0]) 
                    cube([stem_c_diameter, stem_c_diameter, 10], center=true);
            }
        }
    }
}
