for NTH in {1..8}; do
    echo -n "$NTH ";
    ./integral.x NTH | head -n 1;
done > scaling.txt

echo "Computing parallel metrics from file scaling-$NTH.txt ..."
awk 'BEGIN {TS=1.0;} { if(NR=1) TS=$2; print $1, $2, TS/$2, TS/$2/$1}' scaling.txt > metrics.txt
echo "Done"
