#ifndef CANDIDATE_H
#define CANDIDATE_H

typedef struct Candidate {
    int id;
    char name[60];
    char qualification[100];
    char skills[200];
    float experience;
    struct Candidate *next;
} Candidate;

extern Candidate *candidateHead;

void registerCandidate(void);
void displayCandidates(void);
Candidate *findCandidateById(int id);
void releaseCandidates(void);

#endif
