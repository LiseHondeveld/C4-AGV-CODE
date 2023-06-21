#ifndef AGV_MOTOR_H_INCLUDED
#define AGV_MOTOR_H_INCLUDED

void agv_motor_init();
extern int DirectieMotorL;
extern int DirectieMotorR;
extern int MotorTrackingPositieL;
extern int MotorTrackingPositieR;
void PredefinedBocht(void);

#endif // AGV_MOTOR_H_INCLUDED
