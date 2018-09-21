g++ ../std.cpp -o std -O2
g++ ../force.cpp -o force -O2
GEN_SRC="../../data/gen.py"

for ((i=1;;++i)); do
	echo id#$i:
	python3 ${GEN_SRC} 100 99 5 >input.in
	./std <input.in >output.out
	./force <input.in >answer.ans
	if diff output.out answer.ans >diff.log.txt; then
		echo Accepted!
	else
		echo WrongAnswer
		break
	fi
done
