/* 
 * Author: Luke Hindman
 * Date: Fri 13 Nov 2020 12:21:37 PM PST
 * Description: Starter code for final project (myps)
 */

#define _GNU_SOURCE
#include <stdio.h>
#include "ProcEntry.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define DEFAULT_PROC_DIR "/proc"

void print_usage(void) {
    printf("Usage: ./myps [-d <path>] [-p] [-c] [-z] [-h]\n");
    printf("       -d <path> Directory containing proc entries (default: /proc)\n");
    printf("       -p        Display proc entries sorted by pid (default)\n");
    printf("       -c        Display proc entries sorted by command lexicographically\n");
    printf("       -z        Display ONLY proc entries in the zombie state\n");
    printf("       -h        Display this help message\n");
}

static int pidSort(const void *a, const void *b)
{
     ProcEntry *f = *(ProcEntry **)a;
     ProcEntry *s = *(ProcEntry **)b;
     return f->process_id - s->process_id;
}

static int cmdSort(const void *a, const void *b) {
    ProcEntry *f = *(ProcEntry **)a;
    ProcEntry *s = *(ProcEntry **)b;
    return strcmp(f->comm, s->comm);
}

int main(int argc, char *argv[]) {
    char proc_dir[256] = DEFAULT_PROC_DIR;
    int sort_by_pid = 1;
    int sort_by_cmd = 0;
    int show_zombies_only = 0;

    int opt;
    while ((opt = getopt(argc, argv, "d:pczh")) != -1) {
        switch (opt) {
            case 'd':
                strncpy(proc_dir, optarg, sizeof(proc_dir));
                break;
            case 'p':
                sort_by_pid = 1;
                sort_by_cmd = 0;
                break;
            case 'c':
                sort_by_cmd = 1;
                sort_by_pid = 0;
                break;
            case 'z':
                show_zombies_only = 1;
                break;
            case 'h':
                print_usage();
                return 0;
            default:
                print_usage();
                return 1;
        }
    }

    DIR *proc_dir_ptr = opendir(proc_dir);
    if (!proc_dir_ptr) {
        fprintf(stderr, "Error opening proc directory\n");
        return 1;
    }

    struct dirent *dir_entry;
    ProcEntry **proc_entries = NULL;
    int num_entries = 0;

    // Count the number of processes
    while ((dir_entry = readdir(proc_dir_ptr)) != NULL) {
        if (atoi(dir_entry->d_name) != 0) {
            num_entries++;
        }
    }

    // Allocate memory for the ProcEntry array
    proc_entries = (ProcEntry **)malloc(sizeof(ProcEntry *) * num_entries);
    if (!proc_entries) {
        fprintf(stderr, "Memory allocation error\n");
        closedir(proc_dir_ptr);
        return 1;
    }

    // Reset directory stream to start
    rewinddir(proc_dir_ptr);

    int num_processes = 0;
    // Read process information
    while ((dir_entry = readdir(proc_dir_ptr)) != NULL) {
        if (atoi(dir_entry->d_name) != 0) {
            char stat_file_path[512];
            int len = strlen(proc_dir);
            strcpy(stat_file_path, proc_dir);
            stat_file_path[len] = '/';
            strcpy(&stat_file_path[len + 1], dir_entry->d_name);
            strcat(stat_file_path, "/stat");

            ProcEntry *entry = CreateProcEntryFromFile(stat_file_path);
            if (!entry) {
                fprintf(stderr, "Error reading process stat file: %s\n", stat_file_path);
                for (int i = 0; i < num_processes; i++) {
                    DestroyProcEntry(proc_entries[i]);
                }
                free(proc_entries);
                closedir(proc_dir_ptr);
                return 1;
            }

            if (!show_zombies_only || entry->state == 'Z') {
                proc_entries[num_processes++] = entry;
            } else {
                DestroyProcEntry(entry); // Free memory if not needed
            }
        }
    }
    closedir(proc_dir_ptr);

    // Sort the ProcEntry array
    if (sort_by_pid) {
        qsort(proc_entries, num_processes, sizeof(ProcEntry *), pidSort);
    }
    else if (sort_by_cmd){
        qsort(proc_entries, num_processes, sizeof(ProcEntry *), cmdSort);
    }

    // Print the header
    printf("%7s %7s %5s %5s %5s %7s %-25s %-20s\n","PID","PPID","STATE","UTIME","STIME","THREADS","CMD","STAT_FILE");
    
    // Print the process entries
    for (int i = 0; i < num_processes; i++) {
        PrintProcEntry(proc_entries[i]);
    }

    // Free allocated memory
    for (int i = 0; i < num_processes; i++) {
        DestroyProcEntry(proc_entries[i]);
    }
    free(proc_entries);

    return 0;
}
