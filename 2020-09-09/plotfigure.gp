set key b r
set xlabel 'N'
set ylabel 'D%'
set title 'Percentual difference between equivalent sums'
set log y
set term pdf
set out "series_resta.pdf"
plot 'datos.txt' u 1:2 w l t 'sum2', '' u 1:3 w l t 'sum3'
