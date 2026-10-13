#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "search.h"
#include "input.h"

static int containsIgnoreCase(const char *text, const char *word)
{
    size_t wordLength;
    const char *start;

    if (text == NULL || word == NULL || *word == '\0') return 0;
    wordLength = strlen(word);
    for (start = text; *start != '\0'; ++start) {
        size_t i = 0;
        while (i < wordLength && start[i] != '\0' &&
               tolower((unsigned char)start[i]) == tolower((unsigned char)word[i]))
            ++i;
        if (i == wordLength) return 1;
    }
    return 0;
}

void searchCandidate(void)
{
    int id = readInt("Enter candidate ID to find: ");
    Candidate *found = findCandidateById(id);

    if (found == NULL) {
        puts("No candidate has that ID.");
        return;
    }
    printf("\nID: %d\nName: %s\nQualification: %s\nSkills: %s\nExperience: %.1f years\n",
           found->id, found->name, found->qualification,
           found->skills, found->experience);
}

void searchBySkill(void)
{
    char skill[80];
    Candidate *node = candidateHead;
    int matches = 0;

    readLine("Skill to search for: ", skill, sizeof skill);
    if (skill[0] == '\0') {
        puts("Please enter a skill name.");
        return;
    }

    while (node != NULL) {
        if (containsIgnoreCase(node->skills, skill)) {
            printf("\nID: %d | Name: %s | Skills: %s | Experience: %.1f years\n",
                   node->id, node->name, node->skills, node->experience);
            matches++;
        }
        node = node->next;
    }
    if (matches == 0) puts("No profiles matched that skill.");
    else printf("\nFound %d matching profile(s).\n", matches);
}

float calculateScore(const Candidate *candidate, const Job *job)
{
    float score = 0.0f;
    if (candidate == NULL || job == NULL) return 0.0f;

    if (containsIgnoreCase(candidate->skills, job->requiredSkills))
        score += 70.0f;
    if (job->requiredExperience <= 0.0f || candidate->experience >= job->requiredExperience)
        score += 30.0f;

    return score;
}
