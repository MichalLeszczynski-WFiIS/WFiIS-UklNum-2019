

set term jpeg


set xlabel "argument" # etykieta osi OX
set ylabel "wartosc" # etykieta osi OY


set out "n20c.jpeg"
plot "n20c.dat" u 1:2 w l, '' u 1:3 w l

set out "n5c.jpeg"
plot "n5c.dat" u 1:2 w l, '' u 1:3 w l

set out "n10c.jpeg"
plot "n10c.dat" u 1:2 w l, '' u 1:3 w l

set out "n15c.jpeg"
plot "n15c.dat" u 1:2 w l, '' u 1:3 w l
