
// Integrantes: Renan Belem, Thomas Frentzel, Pedro Henrique Faria, Gabriel Sposito

#include "colors.inc"
#include "textures.inc"
#include "shapes.inc"
#include "metals.inc"
#include "glass.inc"
#include "woods.inc"
       
camera
{

location <0, 0, 5>

look_at <0, 0, 0>
}


light_source { <0, 1, -1> color White}       

while true{

sphere
{

    <x+1, y+1, z+1>, 1
    texture
    {
        pigment { color <0.5, 0.5, 0.75> }
         
     }  
}   
}