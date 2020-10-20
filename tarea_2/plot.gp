set grid
set title 'Con optimizacion'
set xlabel 'N'
set ylabel 'time (s)'
f(x) = A*x**B
A=1.0e-6; B=1.0e-6;
fit f(x) 'datos.txt' u 1:2 via A, B
plot 'datos.txt' w lp lw 2 ps 2 t 'datos', f(x) lw 1 lc rgb "blue" t 'fit'
pause -1
