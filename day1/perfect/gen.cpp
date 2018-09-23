#include <bits/stdc++.h>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)
#define foreach(x, y) for(__typeof(y.begin()) x = y.begin(); x != y.end(); ++x)
using namespace std;
typedef pair<int, int> pii;

int R(int x)
{
	return ((rand() & 32767) * 32768 + (rand() & 32767)) % x;
}

struct Case
{
	vector<int> p; // 0, 1: unused; other: father
	Case(int n)
	{
		p.resize(n + 1);
	}
	int get_n() const
	{
		return (int) p.size() - 1;
	}
	void dump(FILE *file)
	{
		int n = get_n();
		
		vector<int> perm; perm.resize(n + 1);
		f(i, 1, n) perm[i] = i;
		// random_shuffle(perm.begin() + 1, perm.end());
		
		vector<pii> edges;
		f(i, 2, n)
		{
			pii e(perm[i], perm[p[i]]);
			if(R(2)) swap(e.first, e.second);
			edges.push_back(e);
		}
		// random_shuffle(edges.begin(), edges.end());
		
		fprintf(file, "%d\n", n);
		foreach(it, edges) fprintf(file, "%d %d\n", it->first, it->second);
	}
};

int input_id = 0;

struct File
{
	File()
	{
		total_n = 0;
	}
	bool add(const Case &cas)
	{
		if(total_n + cas.get_n() > 1000000) return false;
		total_n += cas.get_n();
		cases.push_back(cas);
		return true;
	}
	void dump(FILE *file)
	{
		random_shuffle(cases.begin(), cases.end());
		fprintf(file, "%d\n", (int) cases.size());
		foreach(it, cases) it->dump(file);
	}
	void dump()
	{
		++input_id;
		char buf[256];
		sprintf(buf, "data/%d.in", input_id);
		FILE *fout = fopen(buf, "w");
		dump(fout);
		fclose(fout);
		
		sprintf(buf, "saffah\\std < data/%d.in > data/%d.ans", input_id, input_id);
		fprintf(stderr, "%s\n", buf);
		system(buf);
		fprintf(stderr, "%s ok\n", buf);
	}
private:
	int total_n;
	vector<Case> cases;
};

Case gen_random(int n)
{
	Case c(n);
	f(i, 2, n) c.p[i] = R(i - 1) + 1;
	return c;
}
Case gen_perfect(int n, int k)
{
	Case c(n);
	f(i, 2, n) c.p[i] = (i + k - 2) / k;
	return c;
}
Case gen_fake(int n, int k)
{
	Case c(n);
	f(i, 2, n) for(c.p[i] = i - 1; c.p[i] % k != 1; c.p[i] = (c.p[i] - 1) / k * k + 1);
	return c;
}
Case gen_rand_fake(int n, int k)
{
	while(n % k != 1) --n;
	Case c(n);
	h(i, (n - 1) / k, 1)
	{
		g(_, 0, k)
		{
			int j;
			do
			{
				j = R(n) + 1;
			}
			while(j <= i || c.p[j]);
			c.p[j] = i;
		}
	}
	return c;
}

File make_random(int l, int r)
{
	File file;
	while(file.add(gen_random(R(r - l + 1) + l)));
	return file;
}
File make_perfect(int k)
{
	File file;
	for(int n = 1, pow = 1; n > 0 && file.add(gen_perfect(n, k)); n += (pow *= k));
	return file;
}
File make_perfect_and_fake(int k)
{
	File file;
	for(int n = 1, pow = 1; n > 0; n += (pow *= k))
	{
		if(!file.add(gen_perfect(n, k))) break;
		if(!file.add(gen_fake(n, k))) break;
		if(!file.add(gen_rand_fake(n, k))) break;
		if(1000000 / k < pow) break;
	}
	return file;
}
File make_special()
{
	File file;
	file.add(gen_perfect(999997, 1));
	return file;
}

int main()
{
	make_special().dump();
	make_random(1, 7).dump();
	make_random(7, 13).dump();
	make_random(13, 13).dump();
	make_random(980, 1010).dump();
	
	make_random(1000000, 1000000).dump();
	make_perfect(1).dump();
	make_perfect(2).dump();
	make_perfect(3).dump();
	make_perfect(4).dump();
	
	make_perfect(24).dump();
	make_perfect(88).dump();
	make_perfect(899).dump();
	make_perfect(999998).dump();
	make_perfect_and_fake(2).dump();
	
	make_perfect_and_fake(3).dump();
	make_perfect_and_fake(4).dump();
	make_perfect_and_fake(24).dump();
	make_perfect_and_fake(63).dump();
	make_perfect_and_fake(541).dump();
	
	make_perfect_and_fake(333330).dump();
	return 0;
}
