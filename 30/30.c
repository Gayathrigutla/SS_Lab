/*
Name : 30.c
Author : Gutla Gayathri
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define SCRIPT_PATH "/home/gayathri/Desktop/SS/30/a.out"  
#define TARGET_HOUR 14 
#define TARGET_MINUTE 30

void run_script() {
    // Executing the script using system()
    if (system(SCRIPT_PATH) == -1) {
        perror("system failed");
        exit(EXIT_FAILURE);
    }
}

void daemonize() {
    pid_t pid, sid;
    
    // Forking the process
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    

    sid = setsid();
    if (sid < 0) {
        perror("setsid failed");
        exit(EXIT_FAILURE);
    }
    
    // Changing the working directory
    if (chdir("/") < 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }
    
    // Close file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    time_t now;
    struct tm *tm_info;
    int sleep_time;

    daemonize();

    while (1) {
        now = time(NULL);
        tm_info = localtime(&now);

        if (tm_info->tm_hour == TARGET_HOUR && tm_info->tm_min == TARGET_MINUTE) {
            run_script();
            sleep(60); // Sleep for 60 seconds
        }
        
        sleep(30); // Sleep for 30 s
    }

    return EXIT_SUCCESS;
}


