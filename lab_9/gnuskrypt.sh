

set term jpeg


set xlabel "argument" # etykieta osi OX
set ylabel "wartosc funkcji" # etykieta osi OY


set out "funkcja_1.jpeg"
plot "funkcja_1.dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_2.jpeg"
plot "funkcja_2.dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_3(5,5).jpeg"
plot "funkcja_3(5,5).dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_3(5,0).jpeg"
plot "funkcja_3(5,0).dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_3(10,10).jpeg"
plot "funkcja_3(10,10).dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_1(5,5).jpeg"
plot "funkcja_1(5,5).dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_1(30,30).jpeg"
plot "funkcja_1(30,30).dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_1_a_b(30,30).jpeg"
plot "funkcja_1_a_b(30,30).dat" u 1:2 w p, '' u 1:3 w l

set out "funkcja_1_a_b(5,5).jpeg"
plot "funkcja_1_a_b(5,5).dat" u 1:2 w p, '' u 1:3 w l