#ifndef SOUND_H
#define SOUND_H

#include <math.h>

namespace sound {
    #define TWOPI 6.283185307
    #define PI 3.14159265359

    short SineWave(double time, double freq, double amp) {
        short result;
        double tpc = 44100 / freq; //ticks per cycle
        double cycles = time / tpc;
        double rad = TWOPI * cycles;
        short amplitude = 32767 * amp;
        result = amplitude * sin(rad);
        return result;
    }

    short SquareWave(double time, double freq, double amp) {
        short result = 0;
        int tpc = 44100/freq; // ticks per cycle
        int cyclepart = int(time) & tpc;
        int halfcycle = tpc / 2;
        short amplitude = 32767 * amp;
        if (cyclepart < halfcycle) {
            result = amplitude;
        }
        return result;
    }

    short Noise(double amp) {
        short result = 0;
        short amplitude = 32767 * amp;
        result = rand() % amplitude;
        return result;
    }

    double SawtoothWave(double time, double freq, double amp, double harmonics) {
        short result = 0;
        short amplitude = 32767 * amp;
        for (int i = 1; i <= harmonics; i++) {
            result += amplitude * sin(TWOPI * time * freq * i / 44100) / i;
        }
        return result;
    }

    short SawtoothModWave(double time, double freq, double amp) {
        short result = 0;
        double amplitude = 32767 * amp;
        // result = amplitude * ((freq * (PI) * fmod(time, (1/freq))) - PI/2);
        result = amplitude * (2.0 / PI) * (freq * PI * fmod(time, 1.0 / freq) - (PI / 2.0));
        double result2 = amplitude * (2.0 / PI) * (freq * PI * fmod(time, 1.0 / freq) - (PI / 2.0));
        std::cout<<"result: "<<result<<std::endl;
        std::cout<<"result2: "<<result2<<std::endl;
        std::cout<<"fmod: "<<fmod(time, (1/freq))<<std::endl;
        std::cout<<"1/freq: "<<1/freq<<std::endl;
        std::cout<<"time: "<<time<<std::endl;
        return result;
    }
}

#endif
