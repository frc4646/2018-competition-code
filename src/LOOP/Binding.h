#ifndef Binding_H
#define Binding_H

#include <Commands/Command.h>
#include <functional>

namespace loop {
	class Binding : public Command {
	private:
		std::function<void (void)> initialise;
		std::function<void (void)> execute;
		std::function<void (void)> endOrInterrupt;
	public:
		Binding(std::function<void (void)> init, std::function<void (void)> exec, std::function<void (void)> end, int numRequires, ...);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
	};
}

#endif  // Binding_H
