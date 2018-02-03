#ifndef IntakeGroup_H
#define IntakeGroup_H

#include <Commands/CommandGroup.h>
#include <Commands/Intake/IntakeTiltSet.h>
#include "IntakeMotorSet.h"

class IntakeGroup : public CommandGroup {
public:
	IntakeGroup();
};

#endif  // IntakeGroup_H
