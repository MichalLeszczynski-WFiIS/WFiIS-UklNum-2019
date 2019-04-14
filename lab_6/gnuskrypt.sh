

set term jpeg


set xlabel "argument" # etykieta osi OX
set ylabel "wartosc" # etykieta osi OY

#set yrange [0:4]
set out "f.jpeg"
plot "f.dat" u 1:2 w l, '' u 1:3 w l


set out "g.jpeg"
plot "g.dat" u 1:2 w l, '' u 1:3 w l


set yrange [0:2.5] 


set out "newton_wielomian.jpeg"
plot "newton_funkcja_wielomian.dat" u 1:5 w l

set out "newton_log.jpeg"
plot "newton_funkcja_log.dat" u 1:5 w l

set out "siecznych_wielomian.jpeg"
plot "siecznych_funkcja_wielomian.dat" u 1:5 w l

set out "siecznych_log.jpeg"
plot "siecznych_funkcja_log.dat" u 1:5 w l