# fasttime

License: Public domain



C/C++ fast clock timer for game engines

Benchmark code:
`
	auto timeBench = ftInit();

	int rounds = 0;
	while (ftElapsed(timeBench) < 1000) {
		++rounds;
	}
	printf("Benchmark time rounds: %d\n", rounds);
`
Benchmark results:

Benchmark time rounds: 42412263

Run on Ryzen 7 2700x @ 4.2 ghz
