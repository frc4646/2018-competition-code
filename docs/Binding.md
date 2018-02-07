# Binding
Anonymous-method-based command. For when creating a new command just for a specific situation is too silly.

## Public Methods
#### Binding::Binding(std::function<void (void)> init, std::function<void (void)> exec, std::function<void (void)> end, int numRequires, ...)
Constructs a new Binding. ``init``, ``exec``, and ``end`` are method references that return nothing and have no paramaters.

``init`` is called when the command initializes.  
``exec`` is called every time the command runs ``Execute``.  
``end`` is called when the command stops.
``numRequires`` is the number of subsystems required by the binding.  
``...`` is a parameter list. For every subsystem required, add a ``CommandBase::[required subsystem here].get()`` as a parameter.