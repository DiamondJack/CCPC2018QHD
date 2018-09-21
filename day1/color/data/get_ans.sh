g++ ../wyz/std.cpp -O2 -o std
for ((i=1;i<=3;++i)); do
	time ./std <$i.in >$i.ans
done
