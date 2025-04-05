# Dependencies

* readline
You can build readline for `ubuntu` with the command
`sudo apt-get install libreadline-dev`

# Minishell

My implementation of shell based on bash, made with C.
It was assigned to me and my partner to build a custom shell with C using bash as an inspiration.

#### These are the features the shell needs to have:

* Have a working history.
* Search and launch the right executable (based on PATH with a relative or absolute path).
* Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
* Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
* Implement the following redirections and pipes:
* Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
* Handle $? which should expand to the exit status of the most recently executed command.
* Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
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

## Explanation

I think its better to explain the structs used for this project because they where crucial for this shell implementation.

### `struct s_token:`

```
typedef struct	s_token
{
	char			*value;
	t_type			type;
	struct s_token		*next;
	struct s_token		*prev;
}		t_token;
```

Starting with t_token, its a simple doubly liked list, when I first implemented, I thought that I would need access to both next and previous tokens, but later I found out that it wasn't necessary, but it was too late and I was too lazy to delete it (lol).
Also I had the value of each token stored in a normal string.
The last piece of data that I want to talk about this struct is `t_type`.
The first reason that made me choose a linked list to store tokens was to assign each token a type.
So I used an enum to identify all the types I wanted to add to this custom shell:

### `enum	e_type:`

```
typedef enum	e_type
{
	HERE_DOC,
	LESSER,
	GREATER,
	APPEND,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	PIPE,
	BUILTINS,
	COMMAND,
	FULL_COMMAND,
	OPTION,
	ARGUMENT,
	IDENTIFIER
}		t_type;
```

### `struct s_env:`

Another linked list used for this shell was to store environment variables, this one store each env's key and value. I'll explain later what are environment variables but I choose this format because is more maleable with unset and export. altough I needed later a function to convert to a 2d array for execve (ill explain later).

```
typedef struct	s_env
{
	char		*name;
	char		*value;
	struct s_env	*next;
}		t_env;
```

### `struct s_pipe:`
The last auxiliar struct is t_pipe, which isn't a linked list for once, this one stores metadata for pipe execution, `pipe_fd[2]` this is a variable to store 2 file descriptors, one for reading and one for writing, `input_fd` stores the fd for the current command, `**ev` stores the env array for execve and `id` stores the Process ID for the forked child.

```
typedef struct s_pipe
{
	int		i;
	int		pipe_fd[2];
	int		input_fd;
	int		flag;
	char	**ev;
	pid_t	id;
}		t_pipe;
```

### `struct s_shell:`
And finally, the "main" structure
```
typedef struct	s_shell
{
	bool		flag;
	int			exit_status;
	char		*input;
	char		*path;
	char		**array;
	t_env		*env;
	t_token		*token;
	t_pipe		*pipe;
}			t_shell;
```
It stores all the necessary information for the execution of the program, like `input` it stores the current line prompted by the user, `exit_status` that, I kid you not, it stores the exit status of the last command executed >shocker<.
You will see a lot of stuff in this project that I implemented initially in this project that I noticed later that I didn't need but never deleted, like that 2d array, I will explain the parsing, but first I splited the input into tiny strings then used that strings for each token's value, but I should just splited the input and directly insert into the tokens, the way I implemented, just added a another layer of chores and I do not recommend.
Finally, there are the pointers to the structs I explained earlier.
