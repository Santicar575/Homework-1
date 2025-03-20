local:
	g++ -std=c++20 -g -Wall -Wconversion -Wno-sign-conversion -Werror -o Ejercicio_3 *.cpp -lm
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./Ejercicio_3
	rm Ejercicio_3