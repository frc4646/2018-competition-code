# Binding
Anonymous-method-based command. For when creating a new command just for a specific situation is too silly.

## Public Methods
#### Binding::Binding(std::function<void (void)> init, std::function<void (void)> exec, std::function<void (void)> end, int numRequires, ...)
Constructs a new Binding. ``init``, `` are method references that return nothing and have no paramaters