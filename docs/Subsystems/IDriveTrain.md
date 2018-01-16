# IDriveTrain
Object-oriented drivetrain subsystem interface.

## Public Methods
#### IDriveTrain::IDriveTrain(std::string name)
Constructs a new IDriveTrain instance with a given name.
#### virtual void InitDefaultCommand()
Virtual function implemented by subclasses of IDriveTrain. Sets the default command for controlling a
drivetrain.
#### virtual void Stop()
Virtual function implemented by subclasses of IDriveTrain. Stops the drivetrain. Safety first. FIRST second.
#### virtual void Drive(SDriveData driveData)
Virtual function implemented by subclasses of IDriveTrain. The SDriveData structure allows 1 function
declaration for both holonomic and non-holonomic drivetrains. Safety/enabling is expected to be
implemented in the default command.

# Private Methods
_This class does not define any private methods._

#### struct SDriveData
_Note: Anonymous struct typedef'ed to SDriveData._
##### Members
``double cartX``  
Cartesian X. For holonomic drivetrains.

``double cartY``  
Cartesian Y. For holonomic drivetrains.

``double cartR``  
Rotation. For holonomic drivetrains.

``double lTank``  
Left tank power. For non-holonomic drivetrains.

``double rTank``  
Right tank power. For non-holonomic drivetrains.

---
###### LOOP framework v0