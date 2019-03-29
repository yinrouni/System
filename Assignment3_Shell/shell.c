// Modify this file for your assignment
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SZ 80

//the commands divided by space.
char commands[80][80];
//the current path
char curPath[80];

// Create a signal handler
void sigint_handler(int sig){
	write(1,"mini-shell terminated\n",35); 
	exit(0);
}

int callCd(int commandNum);
int splitCommands(char command[BUF_SZ]);
int callHelp();
int callExit();
int callGuessingGame();
int callCommand(int commandNum);
int isPipe(int commandNum);
int execvPipe(char* commandBefore[], char* commandAfter[]);

//Get current working directory.
int getCurWorkDir(){
	char* result = getcwd(curPath, BUF_SZ);
	if (result == NULL){
		return 0;
	}
	else{
		return 1;
	}
}

// If there is any error, exit the most recently launched shell.
int main(){
	// to track the status of the command execution.
	int result;
	// Install our signal handler
	signal(SIGINT, sigint_handler);
	printf("This is a shell.\n");
	printf("You can only terminate by pressing Ctrl+C\n");
	char command[BUF_SZ];
	while(1){
		printf("mini-shell>");
		scanf("%[^\n]",command);
		getchar();  // deal with '\n' along with the input
		
		int commandNum = splitCommand(command);
		
		if (commandNum != 0){ // The input is not null.
			if (isPipe(commandNum)){
				// Get the command before the pipe. 
				// The command before the pipe should end up with NULL.
				char* commandBefore[BUF_SZ];
				char s [20];
   				s [0] = '\0';
   				//strcat(s, "/bin/");
    				strcat(s, commands[0]);
    				commandBefore[0] = s;
       				int m;
        			for (m = 1 ; m < isPipe(commandNum) - 1; m ++){
        				commandBefore[m] = commands[m];
				}
				commandBefore[m + 1] = NULL;
				
				// Get the command after the pipe.
				// The command after the pipe should end up with NULL as well.
				char* commandAfter[BUF_SZ];
				char t [20];
   				t[0] = '\0';
    				strcat(t, commands[isPipe(commandNum)]);
    				commandAfter[0] = t;
        			int n;
				int k;
				for (n = isPipe(commandNum) + 1, k = 1; n < commandNum; n ++, k ++){
        				commandAfter[k] = commands[n];
				}
				if (k == 1){
				commandAfter[k] = NULL;}
				else{
				commandAfter[k + 1] = NULL;
				}
	
				result = execvPipe(commandBefore, commandAfter);
				if (!result){
					printf("pipe error\n");
					continue;
				}
			}
			//commands without a pipe.

			// command: exit
			else if (strcmp(commands[0], "exit") == 0){
				result = callExit();
				if (!result){
					printf("exit error\n");
					continue;
				}
			}
			
			// command: help
			else if (strcmp(commands[0], "help") == 0){
				result = callHelp();
				if (!result){
					printf("help error\n");
					continue;
				}
			}
			
			// command: cd
			else if (strcmp(commands[0], "cd") == 0){
				result = callCd(commandNum);
				if(!result){
					exit(-1);
				}
				else{
					result = getCurWorkDir();
					if (!result){
						printf("cd error\n");
						continue;
					}
				}
			}

			// command: guessinggame
			else if (strcmp(commands[0], "guessinggame") == 0){
                		result = callGuessingGame();
                		if (!result){
                    			printf("guessing game error\n");
					continue;
				}
			}
			
			// other non builtin commands
        	    	else {
                		result = callCommand(commandNum);
                		if (!result){
                    			printf("non-builtin command error\n");
					continue;
                		}
			}
		} 
	}
 	return 0;
}

// Split the commands by spaces in to an array of strings.
// Each String is a command.
// Return the number of parts the command has.
int splitCommand(char command[BUF_SZ]){
    	int num = 0;
	int i, j;
	int len = strlen(command);

	for (i = 0, j = 0; i < len; ++i){
		if (command[i] != ' '){
			commands[num][j++] = command[i];
		}
		else{
			if (j != 0){
				commands[num][j] = '\0';
				++num;
				j = 0;
			}
		}
	}
	if (j != 0){
		commands[num][j] = '\0';
		++ num;
	}

	return num;
}

// Command cd implement.
// A command cd should have 2 part, "cd" and the destination.
int callCd(int commandNum){
	int result = 1;
	
	if (commandNum != 2){
		result = 0;
	}
	else{
		int ret = chdir(commands[1]);
		if (ret == -1){
			result = 0;
		}
	}
	return result;
}

// Command help implement.
// Print all the builtin commands and related information.
int callHelp(){
	printf("Help:\n");
	printf("There are 4 built-in command in this mini shell.\n");
	printf("cd\tmoving up or down the directory tree.\n");
	printf("help\tprint out all of the built-in commands.\n");
	printf("exit\tterminate the shell.\n");
	printf("guessinggame\tplay a guessing game (guess a number from 0 - 10)\n");	

	return 1;
}	

// Command exit implement.
// Exit the shell.
int callExit(){
	pid_t pid = getpid();
	if (kill(pid, SIGTERM) == -1){
		return 0;
	}
	else{
		return 1;
	}
}

// Command guessinggame implements
// Guessing a number from 0 - 10.
// You have 5 chances.
int callGuessingGame(){
    srand(time(NULL));
    int target = rand() % 10 + 1;
    
    printf("===============================\n");
    printf("CPU Says: Pick a number 1-10\n");
    printf("===============================\n");
    
    int guess;
    int num = 0;
    int times;
    
    for (times = 0; times < 5; times ++){
        printf("Make a guess: ");
        scanf("%d", &guess);
        num ++;
        if (guess < target){
            printf("No guess higher!\n");
            if (times == 4){
                printf("No chance, you lose.");
            }
        }
        else if (guess > target){
            printf("No guess lower!\n");
            if (times == 4){
                printf("No chance, you lose.");
            }
        }
        else if (guess == target){
            printf("You got it!\n");
            break;
        }
    }
	getchar();
    return 1;
}

//Non builtin commands implemtens.
//Execution the command in a child process created by fork().
//If the command fail to be executed in the child process, 
//reutrn the error message, command not found.
int callCommand(int commandNum){
    char* myargv[commandNum + 1];
    char s[20];
    s[0] = '\0';

    strcat(s, commands[0]);
    myargv[0] = s;
    int i;
    for (i = 1; i < commandNum; i++){
    	myargv[i] = commands[i];
    }
    myargv[commandNum]=NULL;
    
    int child_status; 
    if (fork() == 0){
        execvp(myargv[0],myargv);
        exit(1);
    }
    else{
        wait(&child_status); 
        if (WEXITSTATUS(child_status) > 0){
	printf("Command not found--Did you mean something else?\n");
    }
    return 1;
    }
}

// If there is no pipe in the command, reutrn 0;
// If there is a pipe in the command, return the index of the command following the pipe.
int isPipe(int commandNum){
	int i;
	for (i = 0; i < commandNum; i ++){
		if (strcmp(commands[i], "|") == 0){
			return i + 1;
		}
	}
	return 0;
}

// Execute commands with a pipe.
// Create a child process in the child process created in the shell.
// Execute the command before the pipe in the child's child process, 
// pass the output to its parent process(i.e. the child process).
// Then Execute the command after the pipe in the child process.
// If one of the 2 commands fails, return the error message, command not found.
int  execvPipe(char* commandBefore[], char* commandAfter[]){
    int child_status1;
    pid_t pid = fork();
    if (pid == 0){
        int fd[2];
        int ret = pipe(fd);
        
	int child_status2;
        if (fork() == 0){
            
            close(fd[0]);
            dup2(fd[1], 1);
            execvp(commandBefore[0], commandBefore);
            exit(1);
	}
        wait(&child_status2);
	if (WEXITSTATUS(child_status2) > 0){
	    printf("Command not found--Did you mean something else?\n");
	}
        close(fd[1]);
        
        dup2(fd[0], 0);
        execvp(commandAfter[0], commandAfter);
        exit(1);
    }
    else{
        wait(&child_status1);
	if (WEXITSTATUS(child_status1) > 0){
		printf("Command not found--Did you mean something else?\n");
	}
    }
return 1;
}

