g++ ../wyz/std.cpp -O2 -o std
for ((i=1;i<=2;++i)); do
	time ./std <$i.in >$i.ans
done
