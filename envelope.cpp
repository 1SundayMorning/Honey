#include <stdio.h>
#include "envelope.h"
using namespace std;

envelope::envelope(
    double attack_time, double decay_time, double sustain_amplitude, 
    double main_amplitude, double release_time) :
    attack_time_(attack_time), decay_time_(decay_time), 
    sustain_amplitude_(sustain_amplitude), main_amplitude_(main_amplitude),
    release_time_(release_time) {}

double envelope::get_amplitude(double curr_time) {

    //Attack
    if (on_) {
        if ((curr_time - trigger_time_) <= attack_time_) {
            return main_amplitude_ * (curr_time - trigger_time_)/attack_time_;
        }
        //Decay
        else if ((curr_time - trigger_time_) > attack_time_ && \
            (curr_time - trigger_time_) <= (attack_time_ + decay_time_)) {
            
            double curr_percent = (curr_time - trigger_time_ - attack_time_)/decay_time_;

            double amp_differential = main_amplitude_ - sustain_amplitude_;
            
            return main_amplitude_ - (amp_differential * curr_percent);
        }
        //Sustain
        else if ((curr_time - trigger_time_) > (attack_time_ + decay_time_) && on_) {
            return sustain_amplitude_;
        }
    }
    else {
        return sustain_amplitude_ * ((curr_time - trigger_off_time_)/decay_time_);
    }
    return 0.0;
}

// key is pressed
void envelope::set_trigger_on(double curr_time) {
    //set current time
    trigger_time_ = curr_time;
    on_ = true;
}

//key is released
void envelope::set_trigger_off(double curr_time) {
    trigger_off_time_ =  curr_time;
    on_ = false;

}