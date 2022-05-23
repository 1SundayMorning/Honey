#ifndef SOUND_HPP
#define SOUND_HPP

#include <math.h>

class sound {
    #define TWOPI 6.283185307
    #define PI 3.14159265359
    #define INTEGER_MAX_POSITIVE 32767
public:
    static short SineWave(double time, double freq, double amp) {
        short result;
        double rad = TWOPI * time * freq;
        short amplitude = INTEGER_MAX_POSITIVE * amp;
        result = amplitude * sin(rad);
        return result;
    }

    static short SquareWave(double time, double freq, double amp) {
        short result;
        double rad = TWOPI * time * freq;
        short amplitude = INTEGER_MAX_POSITIVE * amp;
        result = amplitude * sin(rad);
        if (result > 0) {
            return amplitude;
        }
        else {
            return 0;
        }
    }

    static short Noise(double amp) {
        short result = 0;
        short amplitude = INTEGER_MAX_POSITIVE * amp;
        result = rand() % amplitude;
        return result;
    }

    static double SawtoothWave(double time, double freq, double amp, double harmonics) {
        short result = 0;
        short amplitude = INTEGER_MAX_POSITIVE * amp;
        for (int i = 1; i <= harmonics; i++) {
            result += amplitude * sin(TWOPI * time * freq * i)/i;
        }
        return result;
    }

    static short SawtoothModWave(double time, double freq, double amp) {
        short result = 0;
        short amplitude = INTEGER_MAX_POSITIVE * amp;
        // result = amplitude * ((freq * (PI) * fmod(time, (1/freq))) - PI/2);
        result = amplitude * (2.0 / PI) * (freq * PI * fmod(time, 1/freq) - (PI / 2.0));
        double result2 = amplitude * (2.0 / PI) * (freq * PI * fmod(time, 1.0 / freq) - (PI / 2.0));
        return result;
    }
};

#endif
