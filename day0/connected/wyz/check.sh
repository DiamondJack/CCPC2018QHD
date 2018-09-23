g++ connected.cpp -O2
for ((i=1;i<=8;++i))
do
./a.out <../data/$i.in >tmp.out
if diff tmp.out ../data/$i.ans
then
echo testcase$i is right
else
echo testcase$i boomed!!!!!!!!
fi
done
rm tmp.out
rm a.out
