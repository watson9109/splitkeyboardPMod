$fs=0.01;
$fa=0.1;

function l2p_distance (lp1,lp2, p)
    = pow((p - ((((p - lp2)*(lp1 - lp2))/((lp1-lp2)*(lp1-lp2)))*(lp1-lp2) + lp2)) * (p - ((((p - lp2)*(lp1 - lp2))/((lp1-lp2)*(lp1-lp2)))*(lp1-lp2) + lp2)), 1/2);

board_point = [
    [0, 0, 0],          
    [141.25, 0, 0],
    [141.25, 114.25, 0],
    [115.75, 114.25, 0],
    [115.75, 96, 0],
    [67.5, 96, 0],
    [67.5, 77.75, 0],
    [0, 77.75, 0],
];
    bottom_divider=l2p_distance(board_point[3], board_point[7], board_point[1]) ;

bottom_max_height=20; // under p1
bottom_min_height=3.5; // under p7, p3
    bottom_under_p0= l2p_distance(board_point[3], board_point[7], board_point[0]) / bottom_divider * (bottom_max_height - bottom_min_height) + bottom_min_height;
    bottom_under_p2= l2p_distance(board_point[3], board_point[7], board_point[2]) / bottom_divider * (bottom_max_height - bottom_min_height) + bottom_min_height;
    bottom_under_p4= l2p_distance(board_point[3], board_point[7], board_point[4]) / bottom_divider * (bottom_max_height - bottom_min_height) + bottom_min_height;
    bottom_under_p5= l2p_distance(board_point[3], board_point[7], board_point[5]) / bottom_divider * (bottom_max_height - bottom_min_height) + bottom_min_height;
    bottom_under_p6= l2p_distance(board_point[3], board_point[7], board_point[6]) / bottom_divider * (bottom_max_height - bottom_min_height) + bottom_min_height;

plate_point = [
/*  0 */    [0, 0, 0], 
/*  1 */    [-141.25, 0, 0],
/*  2 */    [-141.25, -114.25, 0],
/*  3 */    [-115.75, -114.25, 0],
/*  4 */    [-115.75, -96, 0],
/*  5 */    [-67.5, -96, 0],
/*  6 */    [-67.5, -77.75, 0],
/*  7 */    [0, -77.75, 0],
/*  8 */    [0, 0, -bottom_under_p0],
/*  9 */    [-141.25, 0, -bottom_max_height],
/* 10 */    [-141.25, -114.25, -bottom_under_p2],
/* 11 */    [-115.75, -114.25, -bottom_min_height],
/* 12 */    [-115.75, -96, -bottom_under_p4],
/* 13 */    [-67.5, -96, -bottom_under_p5],
/* 14 */    [-67.5, -77.75, -bottom_under_p6],
/* 15 */    [0, -77.75, -bottom_min_height]
];

plate_face = [
    [0, 7, 6, 1],
    [1, 6, 5, 4],
    [1, 4, 3, 2],
    [0, 1, 9, 8],
    [1, 2,10, 9],
    [2, 3,11,10],
    [3, 4,12,11],
    [4, 5,13,12],    
    [5, 6,14,13],
    [6, 7,15,14],
    [7, 0, 8,15],
    [8,9,14,15],
    [9,12,13,14],
    [9,10,11,12]
];

hole_point = [
    [-6.25, -13.500, -3.1],
    [-2.75, -75.500, -3.1],
    [-69.75, -93.5, -3.1],
    [-116.25, -94.5, -3.1],
    [-118.25, -112, -3.1],
    [-136.75, -112, -3.1],
    [-133.75, -81.5, -3.1]
];

difference () {
    polyhedron(plate_point, plate_face);
    for(i = hole_point){
        translate(i){
            cylinder(d = 3.5, h =10);
        }
    }
    translate([-141.25, 0, 0]){
        cube([44, 90, 10], center=true);
    }
}




// for(i = [0:0.1:10]){
//     rotate([-i,0,0]){
//         rotate([0,0,17.5]){
//             translate([0,77.8,0]){
//                     import("/home/wataru9109/Documents/splitkeyboardPmod/keyBOARD/keyboard.stl", convexity=10);
//             }
//         }
//     }
// }

// hull () {
//     import("/home/wataru9109/Documents/splitkeyboardPmod/keyBOARD/keyboard.stl", convexity=10);
//     translate([0,0,-19.5]){
//         sphere(r = 0.5);
//     }
//     translate([141.3,0,-19.5]){
//         sphere(r = 0.5);
//     }
//     translate([141.3,-114.3,-19.5]){
//         sphere(r = 0.5);
//     }
// }