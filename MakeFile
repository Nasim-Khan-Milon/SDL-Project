all:
	g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

	g++ -I src/include -L src/lib -o Task_101 Task_101.cpp -lmingw32 -lSDL2main -lSDL2

	g++ -I src/include -L src/lib -o Task_102 Task_102.cpp -lmingw32 -lSDL2main -lSDL2
	
	g++ -I src/include -L src/lib -o Task_103 Task_103.cpp -lmingw32 -lSDL2main -lSDL2