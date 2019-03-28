// Modify this file for your assignment
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SZ 80

char commands[80][80];
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
int callLs(int commandNum);
int isPipe(int commandNum);
int execvPipe(char* commandBefore[], char* commandAfter[]);

int getCurWorkDir(){
	char* result = getcwd(curPath, BUF_SZ);
	if (result == NULL){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	int result;
	// Install our signal handler
	signal(SIGINT, sigint_handler);
	printf("This is a shell.\n");
	printf("You can only terminate by pressing Ctrl+C\n");
	char command[81];
	while(1){
		printf("mini-shell>");
		scanf("%[^\n]",command);
		getchar();
	//	printf("Running forever!\n");
//		printf("command: %s\n", command);
		
		int commandNum = splitCommand(command);
		
		if (commandNum != 0){ // The input is not null.
			if (isPipe(commandNum)){
				//
				char* commandBefore[BUF_SZ];
				char s [20];
   				s [0] = '\0';
   				strcat(s, "/bin/");
    				strcat(s, commands[0]);
    				commandBefore[0] = s;
       				int m;
        			for (m = 1 ; m < isPipe(commandNum) - 1; m ++){
        				commandBefore[m] = commands[m];
				}
				commandBefore[m + 1] = NULL;


				char* commandAfter[BUF_SZ];
				char t [20];
   				t[0] = '\0';
    				strcat(t, "/usr/bin/");
    				strcat(t, commands[isPipe(commandNum)]);
    				commandAfter[0] = t;
        			int n;
				int k;
        			for (n = isPipe(commandNum) + 1, k = 1; n < commandNum; n ++, k ++){
        				commandAfter[k] = commands[n];
				}
				commandAfter[k + 1] = NULL;
				
				result = execvPipe(commandBefore, commandAfter);
				if (!result){
					printf("exit error\n");
					exit(-1);
				}
			}
			// command: exit
			else if (strcmp(commands[0], "exit") == 0){
				result = callExit();
				if (!result){
					printf("exit error\n");
					exit(-1);
				}
			}
			
			// command: help
			else if (strcmp(commands[0], "help") == 0){
				result = callHelp();
				if (!result){
					exit(-1);
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
						exit(-1);
					}
				}
			}
			else if (strcmp(commands[0], "guessinggame") == 0){
                		result = callGuessingGame();
                		if (!result){
                    			exit(-1);
				}
			}
			
            else {
                result = callLs(commandNum);
                if (!result){
                    exit(-1);
                }
		}
	} 
}
 return 0;
}
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

int callHelp(){
	printf("Help:\n");
	

	return 1;
}	

int callExit(){
	pid_t pid = getpid();
	if (kill(pid, SIGTERM) == -1){
		return 0;
	}
	else{
		return 1;
	}
}

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

int callLs(int commandNum){
    char* myargv[commandNum + 1];
    char s[20];
    s[0] = '\0';

    strcat(s, "/bin/");
    strcat(s, commands[0]);
  //  myargv[0]=strcat("/bin/", commands[0]);
    myargv[0] = s;
 // 	printf("%s", myargv[0]);
    int i;
    for (i = 1; i < commandNum; i++){
    	myargv[i] = commands[i];
    }
    myargv[commandNum]=NULL;
    
    int child_status; 
    if (fork() == 0){
        execve(myargv[0],myargv,NULL);
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
int isPipe(int commandNum){
	int i;
	for (i = 0; i < commandNum; i ++){
		if (strcmp(commands[i], "|") == 0){
			return i + 1;
		}
	}
	return 0;
}

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
            execve(commandBefore[0], commandBefore, NULL);
            exit(1);
	}
        wait(&child_status2);
	if (WEXITSTATUS(child_status2) > 0){
	    printf("Command not found--Did you mean something else?\n");
	}
        close(fd[1]);
        
        dup2(fd[0], 0);
        execve(commandAfter[0], commandAfter, NULL);
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

