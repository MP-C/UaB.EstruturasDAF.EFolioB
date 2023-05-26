./compile.sh

total=0
passed=0

for file in in/*.in;
do
    total=$((total+1))
    test="$(basename ${file%.in})"
    echo $test

    ../program.out < ${file} > outhyp/${test}.outhyp

    diff -b outhyp/${test}.outhyp expected/${test}.out > diff.txt
    if [ ! -s diff.txt ]
    then
        echo "passed"
        passed=$((passed+1))
    else
        echo "diff"
        cat diff.txt
        rm diff.txt 2> /dev/null
        continue
    fi

    rm diff.txt 2> /dev/null
done

rm ../*.o 2> /dev/null

echo "SCORE: " ${passed}/${total}
