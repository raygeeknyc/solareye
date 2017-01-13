b2=79.9;
w=210;
t1=10;
t3=20;
 /* This makes the base plate with an angled groove and lip to hold the panel base.
 */
 union() {
     difference() {
         cube([b2+2*t1, w+2*t1, t3]);
        translate([t1, t1, t1]) rotate([0,345,0]) cube([t3+t1*2, w, t3-t1]);
     }
     translate([t1/2, t1, t3-t1]) cube([t1/2, w, t3]);
 }