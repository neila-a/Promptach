# Promptach

English | [中文普通话大陆简体](./docs/README.cmn-Hans-CN.md)

A pluggable, highly configurable prompt generator.

## Effect

![Effect drawing](./docs/assets/effect_drawing.png)

## Features

### A brand-new path display

#### Git folders

In Promptach, git branches are no longer displayed outside the path like other prompt generators, but are instead included in the path.  
Consider this scenario: you are in the `docs` folder on the `main` branch of a git repository located at `~/projects/example`. In other prompt generators, it would typically look like this:

```bash
~/project/example/docs (on main)
```

And in Promptach, it will be displayed in a more ergonomic way:

```bash
~/project/example main docs
```

#### Path replacement

Promptach also provides settings for path replacement display. In the scenario above, if `projects` is configured to display as `📁`, it will be displayed as follows:

```bash
~/📁/example main docs
```

#### Path with symbolic links

When entering a path with symbolic links, the symbolic links will be displayed.  
Consider this scenario:

```bash
> tree /foo
foo
└── content
> tree /bar
├── abs -> /foo
└── rel -> ../foo
```

When entering `/bar/abs/content`, path will be displayed as `/bar/(abs → /foo)/content`;  
when entering `/bar/rel/content`, path will be displayed as `/bar/(rel → ../foo)/content`.

### Graphical setting interface

There are no countless YAML, TOML, or INI files to edit - Promptach provides a clear and intuitive graphical setup interface.  
Of course, you can still edit directly if you prefer.

#### Setting program

Run `PromptachSettings`.

#### Configuration file location

In `$XDG_CONFIG_DIRS/Promptach`.

### Concise display

No rounded corners, no background colors - just plain text paired with carefully blended foreground colors.  
The always-available right prompt - in Promptach, the right prompt is implemented by detecting the console width and is not dependent on a specific shell.  
If you want, the number of texts is not limited to left and right: the middle prompt or more are also supported.

### Fast speed

Promptach is not written in shell. It is written in C++.

## Build

```bash
nix build
```

## Install from cachix

https://promptach.cachix.org/#pull

## Usage

In the shell, set the environment variable `PROMPT_COMMAND` (not `PS1`) to `Promptach`.  
Additionally, it will not overwrite `PS1`, which needs to be set manually. It is recommended to set PS1 to `> `.

## Known issues

- Incompatible with [ble.sh](https://github.com/akinomyoga/ble.sh).  
  No errors will be reported, but there are obvious visual issues, such as unexpected extra line breaks.
- ANSI colors are displayed directly in the program.
- Changes often occur in the settings program that are not displayed in a timely manner and require a restart.
