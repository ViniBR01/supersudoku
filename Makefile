supersudoku: main.cpp
	g++ -o supersudoku.out main.cpp -g -fsanitize=address
	./supersudoku.out

run:
	./supersudoku.out

debug:
	gdb ./supersudoku.out
