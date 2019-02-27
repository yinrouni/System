# Terminal and Linked List
<img align="right" width="300px" src="https://support.rstudio.com/hc/article_attachments/115019778247/2017-08-11_13-53-02-dropdown-new-v2.png">

> "Refresh! We are now in Systems!"

We have previously done quite a bit of work with data structures such as a linked list. Now we are going to connect it with using our terminal to grab some data.

# Part 0 - SSH and git pull

1. First open a terminal and ssh into the Khoury servers ``` ssh khoury_user_name_here@login.khoury.neu.edu ```
2. Navigate to your Monorepo directory(Use the `cd` command to change directory, `ls` to see files, and `pwd` to see your path)
3. When you are within your Monorepo, do a ```git pull```. This will add all of the files I have previously pushed into your repositories.

If for some reason you are having troubles, you can always create a new copy of your monorepo by running `git clone https://github.com/COURSENAME/monorepo-yourUserNameHere` in a separate directory.

# Part 1 - VIM and TMUX Round 2 (Wait--do I really have to use these tools??)

<img align="right" width="300px" src="https://joshldavis.com/img/vim/tabs.gif">

**Yes you should be using VIM and Tmux you are a systems programmer now. :) **

### Student and Teacher Dialouge

*"But I love visual studio, sublime, XCode, Atom, etc."*

*That's great, but you cannot use those in a remote environment easily--so I suggest learning another skill. By all means, use both or multiple tools to write the highest quality code.*

*"Hehe, the professor will never know if I just use notepad. I'll just take a shortcut on this assignment"*

*While that's true you can take a shortcut now, it will eventually catch up to you. I promise this is a good skill to learn! This first assignment is much more lightweight, take the time now to do things properly.*

Here are some suggested resources to get started.
* (VIM+TMUX Example) https://www.youtube.com/watch?v=YD9aFIvlQYs (16:31)
* Type *man tmux* in a terminal.
* Tmux tutorial - https://www.youtube.com/watch?v=BHhA_ZKjyxo (11:23)

(This is an ungraded task--only work on this if you finish the deliverable). You will have to do a little bit of work to figure out how to open and read from files for this task.)

# Part 2 - Linked List and Data (Revisited!)

## First task - obtain some data

Provided within the lab is a shell script (**data.sh**) to obtain some real world data. Provided below are some examples for obtaining some data that we can read in using shell scripts. You can choose whichever data you and your partner like. 

Running the script with `sh data.sh` will bring in the data and save it to a text file or a spreadsheet. You could then read this data into a linked list and display it.

```shell
# Column selector for Red Sox data (prints out index and column name):
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/red_sox_history.csv | awk -F ',' '{ if (NR ==1)  for (i=1; i<=NF; i++){ print i, $i } }

# Win column from Red Sox historical data:
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/red_sox_history.csv | awk -F ',' '{ if (NR > 2)  { print $5 } }' > sox_wins.txt

# An alternative win column selector (Now you know about curl and wget)
wget -O - http://www.mshah.io/comp/Fall18/Systems/Lab/2/baseballdata.csv | cut -d ',' -f 5 | tail -n +2 > data.txt

# There are more public domain texts at the Guttenberg project https://www.gutenberg.org/ 
# Below are some other examples.

# US Declaration of Independence broken up at each comma:
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/usdeclar.txt | awk -F ',' '{ if (NR > 6)  for (i=1; i<=NF; i++) { print $i } }' > doi-segment.txt

# US Declaration of Independence word by word:
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/usdeclar.txt | awk '{ if (NR > 6)  for (i=1; i<=NF; i++) { print $i } }' > doi-word.txt

```

Notes:
- Depending on the data you read in, it may be text or integer based--adapt your function signatures as needed.


## More resources to help

- Hackerrank has an excellent series of shell tutorials here: https://www.hackerrank.com/domains/shell/bash
  - I highly recommend going through them if you are not comfortable with the shell.
- **If you accidently delete something** you can navigate to `cd .snapshot/` which will show files that have been periodically backed up for that current directory. This is yet anothe reason to make sure you are working within the CCIS systems which provide this backup service.

## Deliverable

* Copy and Paste the output from the command-line interface of you running five different terminal commands above into a file called "output.txt" (no capitalization, exactly as named.)
  * Make sure to 'add/commit/push' this file to the repo in this directory.
* Modify the file called 'main.c' in your respository containing the power example.
  * Make sure to 'add/commit/push' this file to the repo in this directory.
  
## Going Further

(Some more programs to research and try out

1. history
2. tree
3. touch
4. awk
5. sed
