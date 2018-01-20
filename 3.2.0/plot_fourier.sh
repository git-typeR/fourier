gnuplot -e "
  plot 'fourier.data' using 1:2 with line;
  pause -1
"
gnuplot -e "
  plot 'fourier.data' using 1:3 with line;
  pause -1;
"
