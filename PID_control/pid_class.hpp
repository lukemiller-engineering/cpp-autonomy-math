#pragma once

class PID {
public:
    PID(double kp, double ki, double kd)
        : kp(kp), ki(ki), kd(kd), prev_error(0.0), integral(0.0) {}

    double update(double target, double measured, double dt) {
        double error = target - measured;
        integral += error * dt;
        double derivative = (error - prev_error) / dt;
        prev_error = error;
        return kp * error + ki * integral + kd * derivative;
    }

private:
    double kp;
    double ki;
    double kd;
    double prev_error;
    double integral;
};
