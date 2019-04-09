

set term jpeg


set xlabel "liczba iteracji" # etykieta osi OX
set ylabel "Przyblizenia wektorow wlasnych" # etykieta osi OY

set yrange [0:4]
set out "lambdy.jpeg"
plot "lambdy.dat" matrix using 1:3:2 with lines palette