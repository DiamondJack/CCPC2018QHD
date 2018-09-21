g++ ../wyz/std.cpp -o std -O2
for ((i=1;;++i)); do
	if [ ! -e ${i}.in ]; then
		break
	fi
	time ./std <$i.in >$i.ans
done
