
oneway: oneway.o
	g++ -o oneway oneway.o -lssl -lcrypto

oneway-AFL-COMP: 
	AFL_SKIP_CPUFREQ=1 AFL_HARDEN=1 afl-g++ -o oneway_AFL oneway.cpp -lssl -lcrypto

oneway-AFL-RUN:
	AFL_SKIP_CPUFREQ=1 afl-fuzz -i in -o out ./oneway_AFL

oneway.o: oneway.cpp
	g++ -Wall -fexceptions -g -c -I libb64-1.2/include  oneway.cpp -o oneway.o

