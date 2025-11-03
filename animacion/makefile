all: bin/particulas

bin/particulas: src/main.cpp src/particula.cpp src/gestor.cpp
	@mkdir -p bin
	g++ src/main.cpp src/particula.cpp src/gestor.cpp -o bin/particulas -std=c++20 -Iinclude -Wall -Wextra -lftxui-component -lftxui-dom -lftxui-screen -pthread

run: bin/particulas
	./bin/particulas

clean:
	rm -rf bin
