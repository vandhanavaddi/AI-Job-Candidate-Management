#include <stdio.h>
#include <stdlib.h>
#include "candidate.h"
#include "job.h"
#include "search.h"
#include "ranking.h"
#include "input.h"

void candidateRanking(void)
{
    Candidate *node;
    Candidate **items;
    int count = 0, i, j, selectedJobId;
    Job *selectedJob;

    if (candidateHead == NULL) {
        puts("Register at least one candidate before ranking.");
        return;
    }
    if (jobHead == NULL) {
        puts("Register a job opening before ranking candidates.");
        return;
    }

    displayJobs();
    selectedJobId = readInt("\nRank candidates for job ID: ");
    selectedJob = findJobById(selectedJobId);
    if (selectedJob == NULL) {
        puts("That job ID does not exist.");
        return;
    }

    for (node = candidateHead; node != NULL; node = node->next) count++;
    items = malloc((size_t)count * sizeof *items);
    if (items == NULL) {
        puts("Not enough memory to prepare the ranking.");
        return;
    }

    node = candidateHead;
    for (i = 0; i < count; ++i) {
        items[i] = node;
        node = node->next;
    }

    /* Sort pointers by match score, highest score first. */
    for (i = 1; i < count; ++i) {
        Candidate *key = items[i];
        float keyScore = calculateScore(key, selectedJob);
        j = i - 1;
        while (j >= 0 && calculateScore(items[j], selectedJob) < keyScore) {
            items[j + 1] = items[j];
            --j;
        }
        items[j + 1] = key;
    }

    printf("\nRanking for: %s (job ID %d)\n", selectedJob->title, selectedJob->id);
    puts("---------------------------------------------------------------");
    for (i = 0; i < count; ++i) {
        printf("%d. %-22s | score: %5.1f%% | experience: %.1f years\n",
               i + 1, items[i]->name,
               calculateScore(items[i], selectedJob), items[i]->experience);
    }
    free(items);
}
