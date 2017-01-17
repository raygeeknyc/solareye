include <defs.scad>

difference() {
cube([w-1, a, t-1]);
translate([cdst1,cdst1,cdst1]) cube([cdst2,a-cdst1,t-1-cdst1]);
translate([0,2*cdst1,cdst1]) cube([cdst1,cdst2,cdst2]);
    
translate([w-1-cdst1-cdst2,cdst1,cdst1]) cube([cdst2,a-cdst1,t-1-cdst1]);
translate([w-1-cdst1,2*cdst1,cdst1]) cube([cdst1,cdst2,cdst2]);
}
translate([-1*cds2,0,0]) {
    include <right_cds_holder.scad>
}
translate([w-1,0,0]) {
    include <left_cds_holder.scad>
}