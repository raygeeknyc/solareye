include <defs.scad>
 /* This makes the base plate with an angled groove and lip to hold the panel base.
 */
 union() {
     difference() {
         union() {
            cube([b3+2*t1, w+2*t1, t3]);
                                     // Create 3 sets of lips around each of the 3 slots

            translate([t1/2+b1-t, t1, t3-t1]) cube([t/2, w, t/2+t1]);     
            translate([t1/2+b1+t/2, t1, t3]) cube([t/2, w, t/2]);  
          
            translate([t1/2+b2-t, t1, t3]) cube([t/2, w, t/2]);     
            translate([t1/2+b2+t/2, t1, t3]) cube([t/2, w, t/2]);     

            translate([t1/2+b3-t, t1, t3]) cube([t/2, w, t/2]);     
            translate([t1/2+b3+t/2, t1, t3]) cube([t/2, w, t/2]);     
   
         }
        // Create a diaganol slot for the panel base
        translate([t1, t1, t1]) rotate([0,330,0]) cube([t3+t1*2, w, t3-t1]);
     // Create 3 slots
     translate([t1/2+b1-t/2, t1, t3-t1]) cube([t, w, t3]);     
     translate([t1/2+b2-t/2, t1, t3-t1]) cube([t, w, t3]);     
     translate([t1/2+b3-t/2, t1, t3-t1]) cube([t, w, t3]);     
     }

     // Add a lip at the panel base
     translate([t1/2, t1, t3-t1]) cube([t1/2, w, t3-t1+t/2]);
 }