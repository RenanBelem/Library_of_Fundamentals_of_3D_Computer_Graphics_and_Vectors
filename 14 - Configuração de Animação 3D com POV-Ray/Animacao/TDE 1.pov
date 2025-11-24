global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }}  
#include "colors.inc"
#include "textures.inc"
//camera
#declare Camera = camera{ angle 80 
                            right    x*image_width/image_height
                            location  <0.1*clock*-2.2 , 1.0 , -10>
                            look_at   <0.0 , 2.0 , 0.0>}
camera{Camera}

//fontes de luz
light_source {
    <0, 30, -10>
    color White
    spotlight
    radius 14
    falloff 17
    tightness 9
    area_light <1, 1, 1>, <1, 1, 1>, 2, 2
    adaptive 1
    jitter
    point_at <1, 1, 1>
    } 
    
light_source {
    <10, 30, 10> color White
    } 

//ceu
plane{<0,1,0>,1 hollow  // 
      
        texture{ pigment {color rgb<0.1,0.3,0.75>*0.7}
                 #if (version = 3.7 )  finish {emission 1 diffuse 0}
                 #else                 finish { ambient 1 diffuse 0}
                 #end 
               } 

        texture{ pigment{ bozo turbulence 0.75
                          octaves 6  omega 0.7 lambda 2 
                          color_map {
                          [0.0  color rgb <0.95, 0.95, 0.95> ]
                          [0.05  color rgb <1, 1, 1>*1.25 ]
                          [0.15 color rgb <0.85, 0.85, 0.85> ]
                          [0.55 color rgbt <1, 1, 1, 1>*1 ]
                          [1.0 color rgbt <1, 1, 1, 1>*1 ]
                          }  
                         translate< 3, 0,-1>
                         scale <0.3, 0.4, 0.2>*3
                        } 
                 #if (version = 3.7 )  finish {emission 1 diffuse 0}
                 #else                 finish { ambient 1 diffuse 0}
                 #end 
               } 
       scale 10000
     }

//grama
plane { <0,1,0>, 0 
        texture{ pigment{color rgb<0.35,0.65,0.0>*0.8}
                 normal {bumps 0.75 scale 0.015}
                 finish {ambient 0.1 diffuse 0.8}
               } 
      } 

//esferas
sphere{ <5,0,0>, 0.2 scale <1,1.5,1>
        texture { pigment{ rgb<1,0,1> }
                  finish { diffuse 0.9
                           phong 1}
                } 
        translate < 1.5*clock*0.4, 2.5, 2.0>    
        rotate <0, 360*clock, 0>
       }   
       
       
sphere{ <0,0,0>, 0.4 scale <1,1.5,1>
        texture { pigment{ rgb<1,1,0> }
                  finish { diffuse 0.9
                           phong 1}
                } 
        translate < 1.5*clock*0.4, 2.5, 2.0>    
        rotate <0, 360*clock, 0> 
       }   
       
      
sphere{ <-5,0,0>, 0.3 scale <1,1.5,1>
        texture { pigment{ rgb<0,1,1> }
                  finish { diffuse 0.9
                           phong 1}
                } 
        translate < 1.5*clock*0.4, 2.5, 3.0>    
        rotate <0, 360*clock, 0>      
       }  