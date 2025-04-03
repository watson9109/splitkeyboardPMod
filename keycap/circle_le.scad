$fs = 0.1;
sqrt_2 = 1.41421356;
knob_outer_height = 25;
knob_outer_diameter = 13;
knob_inner_height = 10;
knob_inner_diameter = 6.1;
knob_inner_D_interval = 5.1;
knob_inner_D_height = 7;

module cylinderOneSideChamfered (diameter, height, depth) 
{
    minkowski () {
        cylinder(d = diameter-2*depth, h = height-(1*depth));
        cylinder(h= depth, r1 = depth, r2 =0);
    }
}

//cube([20,20,20], center=true);



difference (){
    for(i = [0:15:360]){
        rotate([0,0,i]){
            minkowski () {
                cylinder(h = 1, r1=1, r2 = 0);
                cube([(knob_outer_diameter/2-1) / sqrt_2, (knob_outer_diameter/2-1) / sqrt_2, knob_outer_height-1]);
            }
        }
    }
    translate([0, 0, -0.1]){
        difference (){
            cylinder(d = knob_inner_diameter, h = knob_inner_height+0.1);
            translate([knob_inner_D_interval-knob_inner_diameter/2 + 5, 0, 5 + knob_inner_height - knob_inner_D_height]) {
                cube([10, 10, 10], center=true);
            }
        }
        cylinder(d = knob_inner_diameter, h = knob_inner_height-knob_inner_D_height);
    }
}
//cylinder(d = sticktop_diameter, h = sticktop_height);

// translate([0, 0, -stem_height/2]) 
// {
//     difference () 
//     {
//         cylinder(d = 2 * stem_thickness + stem_c_diameter, h = stem_height);      
//         translate([0,0,-0.2]) 
//         {
//             difference () 
//             {
//                 cylinder(d = stem_c_diameter, h = stem_height+0.4);
//                 translate([stem_c_diameter/2 + stem_l_interval/2, 0, 0]) 
//                     cube([stem_c_diameter, stem_c_diameter, 10], center=true);
//                 translate([-stem_c_diameter/2 - stem_l_interval/2, 0, 0]) 
//                     cube([stem_c_diameter, stem_c_diameter, 10], center=true);
//             }
//         }
//     }
// }
