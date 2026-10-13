#include <stdio.h>
#include <stdlib.h>
#include "candidate.h"
#include "input.h"

Candidate *candidateHead = NULL;

Candidate *findCandidateById(int id)
{
    Candidate *node = candidateHead;
    while (node != NULL) {
        if (node->id == id) return node;
        node = node->next;
    }
    return NULL;
}

void registerCandidate(void)
{
    Candidate *item, *tail;

    puts("\n--- Candidate registration ---");
    item = malloc(sizeof *item);
    if (item == NULL) {
        puts("Unable to allocate memory for this candidate.");
        return;
    }

    item->id = readInt("Candidate ID: ");
    if (findCandidateById(item->id) != NULL) {
        puts("That candidate ID is already in use.");
        free(item);
        return;
    }
    readLine("Full name: ", item->name, sizeof item->name);
    readLine("Qualification: ", item->qualification, sizeof item->qualification);
    readLine("Skills (separate multiple skills with commas): ",
             item->skills, sizeof item->skills);
    item->experience = readFloat("Experience in years: ");
    item->next = NULL;

    if (candidateHead == NULL) {
        candidateHead = item;
    } else {
        tail = candidateHead;
        while (tail->next != NULL) tail = tail->next;
        tail->next = item;
    }
    puts("Candidate profile saved.");
}

void displayCandidates(void)
{
    Candidate *node = candidateHead;
    if (node == NULL) {
        puts("There are no candidate profiles yet.");
        return;
    }

    puts("\n--- Registered candidates ---");
    while (node != NULL) {
        printf("\nID: %d\nName: %s\nQualification: %s\nSkills: %s\nExperience: %.1f years\n",
               node->id, node->name, node->qualification,
               node->skills, node->experience);
        node = node->next;
    }
}

void releaseCandidates(void)
{
    Candidate *node = candidateHead;
    while (node != NULL) {
        Candidate *next = node->next;
        free(node);
        node = next;
    }
    candidateHead = NULL;
}
