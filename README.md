# AI Job Candidate Management System (C)

A modular, menu-driven C mini-project for maintaining candidate profiles and job openings, searching profiles, calculating a simple match score, ranking candidates, and shortlisting suitable profiles.

## Features
- Candidate registration with duplicate-ID checking
- Job registration with duplicate-ID checking
- Display candidate and job records
- Search by candidate ID or skill (case-insensitive skill lookup)
- Rank candidates against a selected job
- Shortlist candidates scoring at least 70%
- Linked-list memory cleanup on exit
- Input helpers that read complete lines and validate numeric input

## Data structures and matching
- Singly linked lists store candidates and job openings.
- Candidate pointers are copied into a temporary array for ranking.
- Insertion sort arranges the candidates by score in descending order.
- Skill match: 70 points when the required-skill text is found in the candidate skill text.
- Experience match: 30 points when candidate experience meets the job requirement.
- Maximum score: 100 points.

This is a simple educational matching model, not a machine-learning or hiring-decision system. A production system would need more detailed skill parsing, validation, privacy protections, and human review.

## Files
- `main.c` — menu and program entry point
- `input.c`, `input.h` — reusable console input functions
- `candidate.c`, `candidate.h` — candidate records
- `job.c`, `job.h` — job records
- `search.c`, `search.h` — search and match scoring
- `ranking.c`, `ranking.h` — candidate ranking
- `shortlist.c`, `shortlist.h` — shortlisting

## Compile (GCC / MinGW / MSYS2)
```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c input.c candidate.c job.c search.c ranking.c shortlist.c -o job_system
```

Run on Windows:
```bash
./job_system.exe
```

Run on Linux/macOS:
```bash
./job_system
```
