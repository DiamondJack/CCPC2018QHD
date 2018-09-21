if (($#<3)); then
	echo Too Few Arguments.
	exit
fi

n=$1
Q=$2
p=$3

mod=998244353

num(){
	if ((100*RANDOM/32768<p)); then
		echo 0;
	else
		echo $(((RANDOM*32768*32768+RANDOM*32768+RANDOM)%mod));
	fi
}

echo $n
for ((i=1;i<=n;++i)); do
	echo -n `num`
	# echo $i $n
	if (($i!=$n)); then
		echo -n " "
	else
		echo ""
	fi
done
echo $Q
for ((i=1;i<=Q;++i)); do
	pos=$(((RANDOM*32768+RANDOM)%n+1))
	value=`num`
	echo "${pos} ${value}"
done

