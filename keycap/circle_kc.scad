$fs = 0.01;
keytop_diameter = 17; 
keytop_height = 4;
stem_thickness = 1.3;
stem_size_x = 4.1;
stem_size_y = 6.5;
stem_size_z = 4.0;




module cylinderOneSideChamfered (diameter, height, depth) 
{
    minkowski () {
        cylinder(d = diameter-2*depth, h = height-(1*depth));
        cylinder(h= depth, r1 = depth, r2 =0);
    }
}

cylinderOneSideChamfered(keytop_diameter, keytop_height, 1);

//cylinder(d = keytop_diameter, h = keytop_height);

translate([0, 0, -stem_size_z/2]){
    difference () {
        cube([stem_size_x,stem_size_y,stem_size_z], center=true);
            cube([stem_thickness,stem_size_x+0.2,stem_size_z+0.1], center=true);
            cube([stem_size_x+0.1,stem_thickness+0.1,stem_size_z+0.1], center=true);
    }
} 

translate([0,0,keytop_height]){
    cube([2,5,2], center =true);
}