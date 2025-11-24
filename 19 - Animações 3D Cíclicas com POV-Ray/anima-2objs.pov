#include "colors.inc" 

camera {location  <0, 10,-80> look_at <25, 10, 0>}

light_source {<2, 30, -30> colour White}

object {plane { y, 0 } pigment {White}}            

#declare Start = 0.0; 
#declare End = 50.0; 
#declare PosX = Start+(End-Start)*clock; 

object {
  sphere { <0,5,-10>,5} 
  pigment {Red} 
  translate<PosX,0,0>
}

object {
  sphere { <0,10,20>,10} 
  pigment {Green} 
  translate<50-PosX,0,0>
}