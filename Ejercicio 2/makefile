local:
	g++ -std=c++20 -g -Wall -Wconversion -Wno-sign-conversion -Werror -o Ejercicio_2 *.cpp -lm
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./Ejercicio_2
	rm Ejercicio_2