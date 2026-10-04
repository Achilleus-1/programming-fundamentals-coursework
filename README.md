# Programming Fundamentals Coursework

Java and C programs covering input validation, collections, graphics, records, and linked lists.

## Original coursework

- CS 1083-003 — Programming I for Computer Scientists, Fall 2023
- CS 1714-0E5 — Computer Programming II, Spring 2024

Originally completed at the University of Texas at San Antonio during the terms above and imported to GitHub later. This repository preserves the submitted implementation; repository documentation and import housekeeping were added separately.

**Languages and technologies:** Java, C, Swing/AWT, Make.

## Implementation

- Calorie tracking and cyclone-record management in Java.
- Animated helix drawing and a screen-saver exercise.
- C dice-game logic, airline route records, and a linked-list tournament simulation.

## Concepts

- Input validation, arrays, object-oriented basics, file parsing, pointers, and linked lists.

## Repository layout

| Directory | Contents |
|---|---|
| `java/calorie-tracker` | CalorieCount.java |
| `java/cyclone-records` | Cyclone.java |
| `java/animated-helix` | Helix.java |
| `java/debugging-exercises` | Small debugging exercises |
| `java/screen-saver` | ScreenSaver.java |
| `c/dice-game` | Dice game |
| `c/airline-route-records` | Route parsing and summaries |
| `c/linked-list-tournament` | Champion list and tournament |

## Running the source

Use a JDK for each Java directory and a C toolchain/Make for the C directories. Compile each exercise separately; there is no shared application entry point.

## Scope and limitations

- DrawingPanel is referenced by the graphics exercises but its source was not supplied. These exercises cannot compile without that dependency.
- The original C input datasets are not included unless they were present as machine-readable inputs in the archive.

Only source code, build configuration, and required text inputs are included. Written submissions, assignment instructions, PDFs, videos, generated outputs, binary builds, and private configuration are omitted. Anonymized contributor labels and supplied-code comments retain the distinction between submitted work and scaffolding. No license for course-provided material is inferred.
