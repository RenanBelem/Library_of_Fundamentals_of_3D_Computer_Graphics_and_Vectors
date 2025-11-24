#include "colors.inc"
camera {
    location  <0, 10.5,-50>
    direction <0,  0,   1>
    up        <0,  1,   0>
    right   <4/3,  0,   0>
    look_at <0, 11, 0>
}

light_source {<-clock, 30, -30> 
colour Yellow 
}

object {
  plane { y, 0 } 
  pigment {Brown}
}            

object {
  sphere { <0,12,0>,10} 
  pigment {White} 
}

torus {
    10, 2
    texture {
         pigment { color rgb <1,1,1>}
    }
    translate <0, 25, 0>
    rotate <0,-90,0>
}