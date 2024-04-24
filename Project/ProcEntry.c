#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ProcEntry.h"

ProcEntry * CreateProcEntry(void) {
    ProcEntry * entry = (ProcEntry *)malloc(sizeof(ProcEntry));
    if (entry != NULL) {
        entry->process_id = 0;
        entry->parent_process_id = 0;
        entry->comm = NULL;
        entry->state = '\0';
        entry->utime = 0;
        entry->stime = 0;
        entry->number_of_threads = 0;
        entry->path = NULL;
    }
    return entry;
}

ProcEntry * CreateProcEntryFromFile(const char statFile[]) {
    if (statFile == NULL) {
        fprintf(stderr, "null stat file\n");
        return NULL;
    }

    FILE *file = fopen(statFile, "r");
    if (file == NULL) {
        fprintf(stderr, "null file\n");
        return NULL;
    }

    ProcEntry *entry = CreateProcEntry();
    if (entry == NULL) {
        fprintf(stderr, "null entry file\n");
        fclose(file);
        return NULL;
    }

    char comm[256]; // Assuming maximum length of 255 for comm
    // char comm[256] = "(";
    int rc = 0;
    rc = fscanf(
        file,
        "%d (%255[^\n)])%*c %c %d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lu %lu %*d %*d %*d %*d %ld",
        &(entry->process_id),
        comm,
        &(entry->state),
        &(entry->parent_process_id),
        &(entry->utime),
        &(entry->stime),
        &(entry->number_of_threads)
    );
    if (rc != 7) {
        
        fclose(file);
        fprintf(stderr, "error reading file, found %d\n", rc);
        // printf("%7s %7s %5s %5s %5s %7s %-25s %-20s\n","PID","PPID","STATE","UTIME","STIME","THREADS","CMD","STAT_FILE");
        // printf("Is this doing anything?%7d %7d %5c %5lu %5lu %7lu ((%-25s))asdasfd %-20s\n", 
        //        entry->process_id,
        //        entry->parent_process_id,
        //        entry->state,
        //        entry->utime / sysconf(_SC_CLK_TCK),
        //        entry->stime / sysconf(_SC_CLK_TCK),
        //        entry->number_of_threads,
        //        entry->comm,
        //        entry->path
        //     );
        DestroyProcEntry(entry);
        return NULL;
    }

    // Allocate memory for comm field
    // strcat(comm, comm_read);
    // strcat(comm, ")");
    entry->comm = (char *)malloc(strlen(comm) + 1);
    if (entry->comm == NULL) {
        fclose(file);
        DestroyProcEntry(entry);
        return NULL;
    }
    strcpy(entry->comm, comm);

    // Allocate memory for path field
    size_t len = strlen(statFile);
    entry->path = (char *)malloc(len + 1);
    if (entry->path == NULL) {
        fclose(file);
        free(entry->comm); // Free comm before destroying entry
        DestroyProcEntry(entry);
        return NULL;
    }
    strcpy(entry->path, statFile);

    fclose(file);
    return entry;
}

void DestroyProcEntry(ProcEntry * entry) {
    if (entry != NULL) {
        free(entry->comm);
        free(entry->path);
        free(entry);
    }
}

void PrintProcEntry(ProcEntry * entry) {
    if (entry != NULL) {
        printf("%7d %7d %5c %5lu %5lu %7lu (%-25s %-20s\n", 
               entry->process_id,
               entry->parent_process_id,
               entry->state,
               entry->utime / sysconf(_SC_CLK_TCK),
               entry->stime / sysconf(_SC_CLK_TCK),
               entry->number_of_threads,
               entry->comm,
               entry->path
            );
    }
}
