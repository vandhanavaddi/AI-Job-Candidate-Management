#include <stdio.h>
#include "candidate.h"
#include "job.h"
#include "search.h"
#include "shortlist.h"
#include "input.h"

void shortlistedCandidates(void)
{
    Candidate *node;
    Job *job;
    int jobId, found = 0;

    if (candidateHead == NULL) {
        puts("There are no candidate profiles to shortlist.");
        return;
    }
    if (jobHead == NULL) {
        puts("Add a job opening before shortlisting candidates.");
        return;
    }

    displayJobs();
    jobId = readInt("\nShortlist for job ID: ");
    job = findJobById(jobId);
    if (job == NULL) {
        puts("That job ID does not exist.");
        return;
    }

    printf("\nShortlisted profiles for %s (score >= 70%%)\n", job->title);
    for (node = candidateHead; node != NULL; node = node->next) {
        float score = calculateScore(node, job);
        if (score >= 70.0f) {
            printf("ID: %d | %s | score: %.1f%% | skills: %s\n",
                   node->id, node->name, score, node->skills);
            found = 1;
        }
    }
    if (!found) puts("No candidates met the shortlisting threshold.");
}
