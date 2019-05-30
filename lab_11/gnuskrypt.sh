

set term jpeg


set xlabel "czas" # etykieta osi OX
set ylabel "wartosc funkcji" # etykieta osi OY

set out "k8.jpeg"
plot "k8.dat" u 1:2 w d t 'zaburzona', "k8.dat" u 1:3 w l t 'niezaburzona', "k8.dat" u 1:4 w l t 'splot'

set out "k10.jpeg"
plot "k10.dat" u 1:2 w d t 'zaburzona', "k10.dat" u 1:3 w l t 'niezaburzona', "k8.dat" u 1:4 w l t 'splot'

set out "k12.jpeg"
plot "k12.dat" u 1:2 w d t 'zaburzona', "k12.dat" u 1:3 w l t 'niezaburzona', "k8.dat" u 1:4 w l t 'splot'
