# Promptach

A pluggable, highly configurable prompt generator.

## Features

### A brand-new path display

In Promptach, git branches are no longer displayed outside the path like other prompt generators, but are instead included in the path.  
Consider this scenario: you are in the `docs` folder on the `main` branch of a git repository located at `~/projects/example`. In other prompt generators, it would typically look like this:

```bash
~/project/example/docs (on main)
```

And in Promptach, it will be displayed in a more ergonomic way:

```bash
~/project/example main docs
```

In addition, Promptach also provides settings for path replacement display. In the scenario above, if `projects` is configured to display as `📁`, it will be displayed as follows:

```bash
~/📁/example main docs
```

### Graphical setting interface

There are no countless YAML, TOML, or INI files to edit - Promptach provides a clear and intuitive graphical setup interface.  
Of course, you can still edit directly if you prefer.

<details>

<summary>Technical details</summary>

#### Setting program

Run `PromptachSettings`.

#### Configuration file location

In `$XDG_CONFIG_DIRS/Promptach`.

</details>

### Concise display

No rounded corners, no background colors - just plain text paired with carefully blended foreground colors.  
The always-available right prompt - in Promptach, the right prompt is implemented by detecting the console width and is not dependent on a specific shell.

### Fast speed

Promptach is not written in shell. It is written in C++.

## Build

```bash
nix build
```

## Usage

In the shell, set the environment variable `PROMPT_COMMAND` (not `PS1`) to `Promptach`.  
Additionally, it will not overwrite `PS1`, which needs to be set manually. It is recommended to set PS1 to `> `.
