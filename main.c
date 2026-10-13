#include <stdio.h>
#include "candidate.h"
#include "job.h"
#include "search.h"
#include "ranking.h"
#include "shortlist.h"
#include "input.h"

static void showMenu(void)
{
    puts("\n========== AI JOB CANDIDATE MANAGER ==========");
    puts("1. Add candidate");
    puts("2. Add job opening");
    puts("3. View all candidates");
    puts("4. View all job openings");
    puts("5. Find candidate by ID");
    puts("6. Find candidates by skill");
    puts("7. Rank candidates for a job");
    puts("8. Show shortlisted candidates");
    puts("0. Exit");
}

int main(void)
{
    int option;

    do {
        showMenu();
        option = readInt("Choose an option: ");

        switch (option) {
            case 1: registerCandidate(); break;
            case 2: registerJob(); break;
            case 3: displayCandidates(); break;
            case 4: displayJobs(); break;
            case 5: searchCandidate(); break;
            case 6: searchBySkill(); break;
            case 7: candidateRanking(); break;
            case 8: shortlistedCandidates(); break;
            case 0: puts("Thank you for using the system."); break;
            default: puts("Invalid option. Select a number from the menu.");
        }
    } while (option != 0);

    releaseCandidates();
    releaseJobs();
    return 0;
}
