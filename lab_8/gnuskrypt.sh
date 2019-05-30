

set term jpeg


set xlabel "argument" # etykieta osi OX
set ylabel "wartosc funkcji" # etykieta osi OY


set out "funkcja_1_n5.jpeg"
plot "funkcja_1_n5.dat" u 1:2 w l, '' u 1:3 w l

set out "funkcja_1_n8.jpeg"
plot "funkcja_1_n8.dat" u 1:2 w l, '' u 1:3 w l

set out "funkcja_1_n21.jpeg"
plot "funkcja_1_n21.dat" u 1:2 w l, '' u 1:3 w l

set out "funkcja_2_n5.jpeg"
plot "funkcja_2_n5.dat" u 1:2 w l, '' u 1:3 w l

set out "funkcja_2_n8.jpeg"
plot "funkcja_2_n8.dat" u 1:2 w l, '' u 1:3 w l

set out "funkcja_2_n21.jpeg"
plot "funkcja_2_n21.dat" u 1:2 w l, '' u 1:3 w l
