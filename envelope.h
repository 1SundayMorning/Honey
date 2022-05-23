#ifndef ENVELOPE_H
#define ENVELOPE_H

class envelope {
public:
    envelope() {};
    
    envelope(double attack_time, double decay_time, double sustain_amplitude, 
            double main_amplitude, double release_time);
    

    double get_amplitude(double curr_time);

    void set_trigger_on(double curr_time);

    void set_trigger_off(double curr_time);

private:
    double attack_time_;
    double decay_time_;
    double sustain_amplitude_;
    double main_amplitude_;
    double release_time_;
    double trigger_time_;
    double trigger_off_time_;
    bool on_;

};

#endif