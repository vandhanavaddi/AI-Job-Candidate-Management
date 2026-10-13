#include <stdio.h>
#include <stdlib.h>
#include "job.h"
#include "input.h"

Job *jobHead = NULL;

Job *findJobById(int id)
{
    Job *node = jobHead;
    while (node != NULL) {
        if (node->id == id) return node;
        node = node->next;
    }
    return NULL;
}

void registerJob(void)
{
    Job *item, *tail;

    puts("\n--- Job opening registration ---");
    item = malloc(sizeof *item);
    if (item == NULL) {
        puts("Unable to allocate memory for this job.");
        return;
    }

    item->id = readInt("Job ID: ");
    if (findJobById(item->id) != NULL) {
        puts("That job ID is already in use.");
        free(item);
        return;
    }
    readLine("Job title: ", item->title, sizeof item->title);
    readLine("Required skills (comma-separated if needed): ",
             item->requiredSkills, sizeof item->requiredSkills);
    item->requiredExperience = readFloat("Minimum experience in years: ");
    item->next = NULL;

    if (jobHead == NULL) {
        jobHead = item;
    } else {
        tail = jobHead;
        while (tail->next != NULL) tail = tail->next;
        tail->next = item;
    }
    puts("Job opening saved.");
}

void displayJobs(void)
{
    Job *node = jobHead;
    if (node == NULL) {
        puts("There are no job openings yet.");
        return;
    }

    puts("\n--- Available job openings ---");
    while (node != NULL) {
        printf("\nID: %d\nTitle: %s\nRequired skills: %s\nMinimum experience: %.1f years\n",
               node->id, node->title, node->requiredSkills,
               node->requiredExperience);
        node = node->next;
    }
}

void releaseJobs(void)
{
    Job *node = jobHead;
    while (node != NULL) {
        Job *next = node->next;
        free(node);
        node = next;
    }
    jobHead = NULL;
}
