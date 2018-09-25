SRC="../data/"
g++ std.cpp -o std -O2 -std=c++11
if (($#>0)); then
	start=$1
else
	start=1
fi
for ((i=$start;;++i)); do
	if [ ! -e ${SRC}/$i.in ]; then
		break
	fi
	echo checking testcase#$i:
	./std <${SRC}/$i.in >output.out
	if diff ${SRC}/$i.ans output.out >diff.log.txt; then
		echo Right!
	else
		echo output does not match!!!!!!!!!
		break
	fi
done

