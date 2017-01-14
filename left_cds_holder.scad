include <defs.scad>

difference() {
cube([cds2,cds2,cdst3]);
translate([cdst1,cdst1,cdst1]) cube([cds2-2*cdst1,cds2-2*cdst1,cdst3-cdst1]);
translate([cds2-cdst1, cdst1, cdst3-cdst1]) cube([cds2-2*cdst1, cds2-2*cdst1, cdst1]);
translate([0, cdst1, cdst1]) cube([cdst1,cds2-2*cdst1, cdst3-cdst1]);
}