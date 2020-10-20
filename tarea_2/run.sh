for N in 1 2 5 10 50 100 150 200 250 300 350 400 450 500 ; do
    echo -n "$N "
    ./a.out $N
done > datos.txt
