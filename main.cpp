#include <iostream>
#include "SFML/Audio.hpp"
#include <vector>
#include <chrono>

#include "sound.hpp"
#include "envelope.h"

using namespace std;
using namespace std::chrono;

#define SAMPLING_RATE 44100.0l // nyquist frequency of highest freq in human audible range

int main() {
    std::cout<<"Honey Test"<<std::endl;

    sf::SoundBuffer buffer;
    vector <sf::Int16> samples;

    double test = 1/SAMPLING_RATE;
    double dtime = 0;

    auto envelope_test = new envelope(0.5, 0.2, 0.1, 1, 2);
    for (int i = 0; i < (SAMPLING_RATE * 4); i++) {
        // samples.push_back(sound::SquareWave(dtime, 440, 0.5));
        // samples.push_back(sound::Noise(0.5)); 

        if (i == 0) {
            envelope_test->set_trigger_on(dtime);
        }

        samples.push_back(sound::SineWave(dtime, 220, envelope_test->get_amplitude(dtime)));
        // samples.push_back(sound::SawtoothWave(i, 110, 0.3, 32) + sound::SquareWave(i, 164.81, 0.2));
        // samples.push_back(sound::SawtoothWave(dtime, 220, 0.3, 40));
        dtime = dtime + 1/SAMPLING_RATE;
    }



    buffer.loadFromSamples(&samples[0], samples.size(), 1, SAMPLING_RATE);

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

	while(1) {}

    return 0;

}
