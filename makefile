bin/programa2 : src/Punteros.cpp
	c++ src/Punteros.cpp -o bin/programa2 -I include

ejecutar : bin/programa2
	./bin/programa2


musica/musica.mp3: musica/awesomeness.wav
	da.wav -codec:a libmp3lame -qscale:a 2 salida.mp3

bin/ejemplo: src/test.cpp
	c++ src/test.cpp -o bin/ejemplo -l ftxui-screen

ejemplo: bin/ejemplo
	./bin/ejemplo