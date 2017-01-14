include <defs.scad>

cube([t-1, w-1, a1]);
translate([t+5,0,0]) cube([t-1, w-1, a2]);
translate([(t+5)*2,0,0]) cube([t-1, w-1, a3]);
