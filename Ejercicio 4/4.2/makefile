local:
	g++ -std=c++20 -g -Wall -Wconversion -Wno-sign-conversion -Werror -o Ejercicio_4 *.cpp -lm
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./Ejercicio_4
	rm Ejercicio_4