#ifndef MATH_H
#define MATH_H

#define SET_BIT(var,bit) (var|=(1<<bit))

#define CLR_BIT(var,bit) (var&=(~(1<<bit)))

#define TOGGLE_BIT(var,bit) (var^=(1<<bit))

#define GET_BIT(var,bit) ((var>>bit) & 1)

#endif 
