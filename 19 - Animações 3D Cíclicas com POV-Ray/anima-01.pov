#include "colors.inc" 

camera { location  <0, 10,-100>  look_at <0, 0, 0>  }

light_source {<2, 30, -30> colour White }

object {
  plane { y, -10 } 
  pigment {White}
}            

object {
  sphere { <0,0,0>,10} 
  pigment {Red} 
}     

union{
difference {
object {
  sphere { <0,0,0>,10} 
  pigment {Blue}
  }
object {
  cylinder {  <-10, 0, 0>, <10,0,0>, 5 }
  pigment {Blue}
  }
}
object {
  cone { <0,5,0>, 8 <0,20,0>, 0 }
  pigment {Yellow}
  rotate <-90,0,0>
  }
   
  translate <80,10,0>
  rotate <0,clock,0>
  scale <0.5,0.5,0.5> 
}
  
union{
difference {
object {
  sphere { <0,0,0>,10} 
  pigment {Yellow}
  }
object {
  cylinder {  <-10, 0, 0>, <10,0,0>, 5 }
  pigment {Yellow}
  }
}
object {
  cone { <0,5,0>, 8 <0,20,0>, 0 }
  pigment {Blue}
  rotate <-90,0,0>
  }
   
  translate <-20,20,80-clock/2>
  rotate <0,-90,0> 
}
