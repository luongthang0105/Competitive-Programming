for ((i = 1; i <= 100; ++i)); do
    echo $i
    ./gen $i > int
    ./correct < int > out_expected
    ./a < int > out_mine
    diff -w out_mine out_expected || break
done