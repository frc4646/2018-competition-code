# Code for the 2018-2019 season
And also use of the LOOP framework.  

## Configuration
Configuration is done in [Config.h](src/Config.h).

To change drivetrain, change the definition of ``DRIVETRAIN`` and change the ``#include``s in [CommandBase.h](src/CommandBase.h).

    // Mecanum
    #define DRIVETRAIN MecanumDrive

	// Tank drive
	#define DRIVETRAIN TankDrive

By default, it is configured for TankDrive.
###### For more information:
* [Config.h](src/Config.h)
* [CommandBase.h](src/CommandBase.h)

## Drivetrain OOP
All drivetrains must subclass ``IDriveTrain`` in order to standardize the drivetrain APIs. All drivetrains
should implement a function with the signature

    void [class name]::Drive(SDriveData driveData)

``SDriveData`` is a struct defined in [IDriveTrain]. It is defined as

    typedef struct {
        double cartX;
        double cartY;
        double cartR;
        double lTank;
        double rTank;
    } SDriveData;

It allows one ``Drive()`` method to be defined for both holonomic and tank-based drivetrains.
###### For more information:
* [IDriveTrain](src/Subsystems/IDriveTrain.h)

Brackets are for std libs.
Quotations for everything else.

---
###### LOOP framework v0