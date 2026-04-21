# Names of God

A simple C++ command line program that lists the Names of God found in the Bible, along with their pronunciations, Scripture references, descriptions, and meanings.

Data sourced from [GotQuestions.org — Names of God](https://www.gotquestions.org/names-of-God.html).

## Build

```bash
g++ -std=c++17 -o namesofGod namesofGod.cpp
```

## Usage

```
./namesofGod [options]
```

Running with no arguments picks and prints one Name of God at random.

### Options

| Flag | Long form | Description |
|------|-----------|-------------|
| `-p` | `--pick` | Pick and print one Name of God at random (default) |
| `-l` | `--list` | List all Names of God with details |
| `-f <str>` | `--filter <str>` | List only names matching `<str>` (case-insensitive) |
| `-c` | `--count` | Show the count of Names of God |
| `-sr` | `--showref` | Call `bv` for each reference after printing (requires `bv` on PATH) |
| `-v` | `--version` | Show version |
| `-h` | `--help` | Show help message |

If `--list` and `--count` are both given, the list is shown first.  
If `--filter` and `--count` are both given, the count reflects only the matched names.

## Examples

Pick a random name:
```bash
./namesofGod
./namesofGod --pick
```

Pick a random name and show its Bible verses:
```bash
./namesofGod -sr
./namesofGod -p -sr
```

List all names:
```bash
./namesofGod --list
```

Filter by partial name (case-insensitive):
```bash
./namesofGod --filter yahweh
./namesofGod -f olam
```

Filter and show verses for each result:
```bash
./namesofGod -f yahweh -sr
```

Show total count:
```bash
./namesofGod --count
```

Show count of filtered results:
```bash
./namesofGod -f yahweh -c
```

List filtered results and their count:
```bash
./namesofGod -f el -l -c
```

## Names Included

25 names are included, covering the major Hebrew, Aramaic, and Greek names and titles of God:

- El, Eloah
- Elohim
- El Shaddai
- Adonai
- YHWH / Yahweh / Jehovah
- Yahweh-Jireh
- Yahweh-Rapha
- Yahweh-Nissi
- Yahweh-M'Kaddesh
- Yahweh-Shalom
- Yahweh-Elohim
- Yahweh-Tsidkenu
- Yahweh-Rohi
- Yahweh-Shammah
- Yahweh-Sabaoth
- El Elyon
- El Roi
- El Olam
- El Gibhor
- El Hannun
- El Emunah
- Qanna
- Shaphat
- Abba
- Ancient of Days

## License

MIT License — Copyright (c) 2026 Todd Birtcher
