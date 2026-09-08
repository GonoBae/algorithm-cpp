# Algorithm Study with C++

C++ algorithm practice repository. It keeps current solutions separate from historical study records so that each solution can be explained, tested, and revisited clearly.

## Current practice — 2026

- Platform: Programmers and Baekjoon
- Language: C++
- Focus: data structures, algorithms, time complexity, and repeatable problem-solving
- Recording rule: every current solution includes the problem ID, topic, complexity, and a short note about the approach or a previous mistake.

## Repository layout

```text
solutions/                  # Current solutions from 2026 onward
  programmers/
  baekjoon/
docs/
  solved.md                 # Current solution index and revisit notes
archive/
  2024-03/                  # Previous individual CTS study record
  2022-2023-team-study/     # Migrated personal contributions from team study
MIGRATION.md                # Migration scope and provenance
```

## Current solution workflow

1. Solve independently and submit.
2. Add a C++ source file under `solutions/` using `problem-id_problem-name.cpp`.
3. Add the solution to [docs/solved.md](docs/solved.md): topic, complexity, first difficulty, and revisit date.
4. Re-solve difficult problems without references and update the note.

## Historical records

| Period | Record | Note |
|---|---|---|
| 2026– | [Current solutions](solutions/README.md) | Active C++ algorithm practice |
| 2024-03 | [Previous individual study](archive/2024-03/) | Preserved from the former `CTS` repository |
| 2022–2023 | [Personal team-study contributions](archive/2022-2023-team-study/) | Only the original `GonoBae` sources and README entries are included |

Historical code is retained as a learning record. Current study uses the `solutions/` structure and does not overwrite older solutions.

## Notes

- This repository contains personal study code only.
- Problem statements are linked instead of copied into the repository.
- Older sources are preserved for history; they are not automatically treated as the current recommended implementation.
