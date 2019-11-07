a = -0.9453;
b = 12.6276;
Ts = 0.01;

g = tf ([b] , [1 a 0], Ts);
rlocus(g)
NL = saturation('LinearInterval',[-6 6]);


