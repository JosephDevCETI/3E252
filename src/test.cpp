#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <chrono>

using namespace ftxui;
using namespace std;

int main() {
    Screen pantalla = Screen::Create(
        Dimension::Full(), 
        Dimension::Fixed(10)
    );

    //Pixel pixel = pantalla.PixelAt(5, 5); pixel como copia
    int x = 0;

    while(true) {

        cout << pantalla.ResetPosition(true);
        pantalla.Clear();

        Pixel& pixel = pantalla.PixelAt(x, 5); //pixel como referencia
        pixel.character = 'X';
        pixel.background_color = Color::Blue;
        pixel.foreground_color = Color::Red;

        pantalla.Print();

        this_thread::sleep_for(chrono::milliseconds(50));

        x++;

       // if (x > 10) break;
    }
    

    return 0;
}