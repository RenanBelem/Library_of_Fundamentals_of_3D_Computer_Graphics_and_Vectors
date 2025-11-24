#include "colors.inc" 

camera {location  <0, 10,-100> look_at <25, 10, 0>}

light_source {<2, 30, -30> colour White}

object {plane { y, 0 } pigment {White}}            

#declare xfactor = clock;

#switch (xfactor)
    #range(0.0,0.5)  
    #debug "IDA"
        #declare PosX = xfactor;
        #break
    #range(0.5,1.0)  
    #debug "VOLTA"
        #declare PosX = 0.5-(xfactor-0.5);
        #break
#end

object {
  sphere { <0,10,0>,10} 
  pigment {Red} 
  translate<PosX*100,0,0>
}