for (( i = 1; i <= 20; i++ ))
do
    python rand.py > rand-$i.in
    ./a.out < rand-$i.in > rand-$i.ans
done
