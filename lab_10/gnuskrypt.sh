

set term jpeg


set xlabel "argument" # etykieta osi OX
set ylabel "wartosc roznicy" # etykieta osi OY

set logscale y
set out "min_log.jpeg"
plot "min_ln.dat" u 1:3 w l t 'zloty podzial', "min_ln_lambda_3.dat" u 1:3 w l t 'podzial na rowne czesci'

set out "min_wielomian.jpeg"
plot "min_wielomian.dat" u 1:3 w l t 'zloty podzial', "min_wielomian_lambda_3.dat" u 1:3 w l t 'podzial na rowne czesci'

