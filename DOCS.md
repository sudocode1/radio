# @end
- Ends a statement.
- Usage: @end 
# out
- Outputs text without a newline.
- Usage: out 
# out!
- Outputs text with a newline.
- Usage: out! 
# @nl
- Prints a newline.
- Usage: @nl 
# @strout
- Outputs a string variable.
- Usage: @strout 
# @intout
- Outputs an int variable.
- Usage: @intout 
# @floatout
- Outputs a float variable.
- Usage: @floatout 
# @!define
- Defines a function without parameters.
- Usage: @!define 
# @define
- Defines a function.
- Usage: @define returnType name
- Parameters
  - returnType - The function's return type.
  - name - The function's name.
- Sub-methods
  ## @param
  - Adds a parameter. 
  - Usage: @param type name
  - Parameters
    - type - The param's type.
    - name - The param's name.

  ## @finalparam
  - Adds the final parameter. If a parameter isn't directly followed by another one, it's required to use @finalparam.
  - Usage: @finalparam type name
  - Parameters
    - type - The param's type.
    - name - The param's name.
# @!call
- Calls a function with no params
- Usage: @!call fn
- Parameters
  - fn - The function's name
# @call
- Calls a function with the specified params
- Usage: @call fn ...params
- Parameters
  - fn - The function's name
  - ...params - A list of parameters, seperated by commas.
# @int
- Defines a number variable.
- Usage: @int name = value
- Parameters
  - name - The variable's name.
  - value - The variable's value.
# @str
- Defines a string variable.
- Usage: @str name = value
- Parameters
  - name - The variable's name.
  - value - The variable's value.
# @double
- Defines a double variable.
- Usage: @double name = value
- Parameters
  - name - The variable's name.
  - value - The variable's value.
# for
- Adds a for loop.
- Usage: for decl; cond; step
- Parameters
  - decl - The variable declaration.
  - cond - The condition.
  - step - The statement which gets executed after each iteration.
# if
- Adds an if statement.
- Usage: if cond
- Parameters
  - cond - The condition.
- Sub-methods
  ## else if
  - Adds an else if statement.
  - Usage: else if cond
  - Parameters
    - cond - The condition.

  ## elif
  - Adds an else if statement.
  - Usage: elif cond
  - Parameters
    - cond - The condition.

  ## else
  - Adds an else statement.
  - Usage: else cond
  - Parameters
    - cond - The condition.
# while
- Adds a while statement.
- Usage: while cond
- Parameters
  - cond - The condition.
# @redefine
- Redefines an already existing variable.
- Usage: @redefine name = value
- Parameters
  - name - The variable's name.
  - value - The variable's value.