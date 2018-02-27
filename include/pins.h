// The pins for the components of the robot
#define RIGHT_DRIVETRAIN_PIN 2
#define LEFT_DRIVETRAIN_PIN 3
#define LEFT_LIFT_PIN 4
#define RIGHT_LIFT_PIN 5
#define UPPER_LIFT_PIN 6
#define INTAKE_PIN 7
#define CLAW_PIN 8
// The pins for the Limit switches
#define LS_CLAW_PIN 1
#define LS_LEFT_LIFT_PIN 2
#define LS_RIGHT_LIFT_PIN 3
// The pins for Potentiometers
#define P_LEFT_LIFT_PIN 4
#define P_RIGHT_LIFT_PIN 5
// The bit shifted versions of the pins.
#define RIGHT_DRIVETRAIN_BIT (1 << RIGHT_DRIVETRAIN_PIN)
#define LEFT_DRIVETRAIN_BIT (1 << LEFT_DRIVETRAIN_PIN)
#define LEFT_LIFT_BIT (1 << LEFT_LIFT_PIN)
#define RIGHT_LIFT_BIT (1 << RIGHT_LIFT_PIN)
#define UPPER_LIFT_BIT (1 << UPPER_LIFT_PIN)
#define INTAKE_BIT (1 << INTAKE_PIN)
#define CLAW_BIT (1 << CLAW_PIN)

#define RIGHT_DRIVE_JOYSTICK_AXIS 2
#define LEFT_DRIVE_JOYSTICK_AXIS 3
