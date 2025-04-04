# Minishell

My implementation of shell based on bash, made with C.
It was assigned to me and my partner to build a custom shell with C using bash as an inspiration.

#### These are the features the shell needs to have:

* Display a prompt when waiting for a new command.
* Have a working history.
* Search and launch the right executable (based on PATH with a relative or absolute path).
* Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
* Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
* Implement the following redirections:
	* \< should redirect input.
	* \> should redirect output.
	* \>> should redirect output in append mode.
	* \<< should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
* Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
* Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
* Handle $? which should expand to the exit status of the most recently executed command.
* Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
* In interactive mode:
	* ctrl-C displays a new prompt on a new line.
	* ctrl-D exits the shell.
	* ctrl-\ does nothing.
* Implement the following built-in commands:
	* echo with option -n
	* cd with only a relative or absolute path
	* pwd with no options
	* export with no options
	* unset with no options
	* env with no options or arguments
	* exit with no options

#### With the constraints:

* Use at most one global variable to indicate a received signal. This global variable must only store the signal number and must not provide any additional information or access to data.
* Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).

## Dependencies

* readline
You can build readline for `ubuntu` with the command
`sudo apt-get install libreadline-dev`
