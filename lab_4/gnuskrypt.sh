

set term jpeg


set xlabel "x" # etykieta osi OX
set ylabel "wektory wlasne" # etykieta osi OY

unset yrange
set out "wektorywlasne0.jpeg"
plot "wektory_dla_alfy0.dat" u 1:2 w l ,'' u 1:3 w l,'' u 1:4 w l,'' u 1:5 w l ,'' u 1:6 w l

set xlabel "x" # etykieta osi OX
set ylabel "wektory wlasne" # etykieta osi OY

unset yrange
set out "wektorywlasne100.jpeg"
plot "wektory_dla_alfy100.dat" u 1:2 w l ,'' u 1:3 w l,'' u 1:4 w l,'' u 1:5 w l ,'' u 1:6 w l

