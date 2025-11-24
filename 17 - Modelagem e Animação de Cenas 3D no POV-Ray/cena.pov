#include "colors.inc"
#include "textures.inc"
#include "shapes.inc"
#include "metals.inc"
#include "glass.inc"
#include "woods.inc"

camera
{

location <0, 2, 3>

look_at <0, 0, 0>
}

plane
{ <0, 1, 0>, -1

pigment
{

checker color Green, color Brown
}
}

light_source { <0, 5, 0> color Yellow}   

sphere
{

    <0, 0.25, 0.25>, 0.5
    texture
    {
        pigment { color <0.5, 0.5, 0.75> }
         
     }  
}  
sphere
{

    <-1.5, 0.25, 0.25>, 0.5
    texture
    {
        pigment { color <0.5, 0.5, 0.75> }
         
     }  
}      
sphere
{

    <1, 0.25, 0.25>, 0.3
    texture
    {
        pigment { color <0.5, 0.5, 0.75> }
         
     }  
}        

cylinder
{
    <-2, 0.25, 0.1>,
    <0.1, 0.1, 0.1>, 
    0.125
    open 
    texture
    {
        T_Silver_3A
        scale 4
    }
}
cylinder
{
    <1, 0.25, 0.1>,
    <0.1, 0.1, 0.1>, 
    0.125
    open 
    texture
    {
        T_Silver_3A
        scale 4
    }
}   

box 
{ 
    <-1, 1.75, 0.8>, 
    <1, 1.4, 0.8>
    texture 
    { 
        T_Gold_3A 
        }
} 

cone {
    <0, 1, -1>, 0  
    <0, 0, 1.5>, 0.3   
    texture
    { 
    pigment {color <1,1,1> }
    }

  }