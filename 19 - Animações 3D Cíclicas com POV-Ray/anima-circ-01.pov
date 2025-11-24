#include "colors.inc" 

#declare Start = 0.0; 
#declare End = 360.0; 
#declare Angulo = Start+(End-Start)*clock; 

camera {location  <0, 20,-80> look_at <0, 10, 0>}

light_source {<2, 30, -30> colour White}

object {
    plane { y, 0 } 
    pigment {White}
}            



