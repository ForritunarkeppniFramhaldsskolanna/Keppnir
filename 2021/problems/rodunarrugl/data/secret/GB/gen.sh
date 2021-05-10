for (( i = 1; i <= 15; i++ ))
do
    python rand.py > rand-$i.in
    ./a.out < rand-$i.in > rand-$i.ans
done
