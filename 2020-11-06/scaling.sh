NS=1000000
echo "Starting strong scaling with system size: $NS"
for NTH in 1 2 3 4; do
    echo -n "$NTH ";
    ./a.out $NS $NTH;
done > scaling-$NS.txt

echo "Computing parallel metrics from file scaling-$NS.txt ..."
awk 'BEGIN {TS=1.0;} {if(NR==1) TS=$2; print $1, $2, TS/$2}' scaling-$NS.txt > metrics-$NS.txt
 echo "Metrics saved to: metrics-$NS.txt"

echo "done"
