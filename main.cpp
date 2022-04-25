#include <iostream>
#include "SFML/Audio.hpp"
#include <vector>

#include "sound.h"

using namespace std;

int main() {
    std::cout<<"Honey Test"<<std::endl;

    sf::SoundBuffer buffer;
    vector <sf::Int16> samples;

    for (int i = 0; i < 44100; i++) {
        // samples.push_back(sound::SquareWave(i, 440, 0.5));
        // samples.push_back(sound::Noise(0.5)); 
        // samples.push_back(sound::SineWave(i, 440, 0.5));
        samples.push_back(sound::SawtoothWave(i, 196, 0.3, 32));
    }


    buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

	while(1) {}

    return 0;

}
