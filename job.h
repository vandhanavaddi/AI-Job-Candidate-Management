#ifndef JOB_H
#define JOB_H

typedef struct Job {
    int id;
    char title[80];
    char requiredSkills[200];
    float requiredExperience;
    struct Job *next;
} Job;

extern Job *jobHead;

void registerJob(void);
void displayJobs(void);
Job *findJobById(int id);
void releaseJobs(void);

#endif
