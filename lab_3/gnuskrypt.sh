

set term jpeg


set xlabel "iteracje" # etykieta osi OX
set ylabel "norma" # etykieta osi OY
set logscale y

set out "norma_r.jpeg"
plot "norma_r.dat" u 1:2 w l linewidth 2


unset logscale y
set out "norma_x.jpeg"
plot "norma_x.dat" u 1:2 w l linewidth 2
