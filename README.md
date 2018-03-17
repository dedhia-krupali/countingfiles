# countingfiles

1.	The fcount.cpp program accepts an argument which is the absolute path of a directory.
2.	The absolute address entered is then recursively traversed to calculate the number of files and subdirectories in it.
3.	It also calculates the total bytes occupied by these files and subdirectories.
4.	The fdisp.cpp program accepts the argument of the option from the command prompt and due to the pipe structure also helps to send the output of the fcount.cpp file to the fdisp.cpp file.
5.	How to run this program

•	Start the command prompt in your void Linux VM
•	Go to the directory where these programs are stored using the command cd
•	Run the command “g++ fcount.cpp –o fcount”
•	This would create an output file named fcount
•	Next run the command “g++ fdisp.cpp –o fdisp”
•	This would create an output file for fdisp.cpp named fdisp.
•	Now when these programs have been compiled:
•	Type in the following comments to get the desired results i.e the number of files, directories or bytes.
Commands to be executed:
•	./fcount “ABSOLUTE ADDRESS OF DIRECTORY” | xargs ./fdisp –f
•	./fcount “ABSOLUTE ADDRESS OF DIRECTORY” | xargs ./fdisp –d
•	./fcount “ABSOLUTE ADDRESS OF DIRECTORY” | xargs ./fdisp –b

6.	The absolute address is the input of fcount.cpp and the options –f/-d/-b is the input of the fdisp.cpp

