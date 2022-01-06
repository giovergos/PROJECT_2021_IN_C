# PROJECT_2021_IN_C
Here is the display of the project.
Create a program that handles hiking routes. The program has a base of routes, which includes different fields, like the starting and ending points, 
the length of every route in meters, 
the maximum, and the minimum altitude of every route in meters, 
and the total amount of ascents and descents (also in meters). 
The user can search routes by several criteria, and get information about them, such as the estimated time of hiking. The main file is already given. 
You must create the file funcs.h which includes the structure route with the necessary fields for every route, and the functions which get called by main. 
Necessary fields for every route:
•	Starting point (string with maximum length of 50 characters including spaces)
•	Length of the route in meters (integer number)
•	Ascent in meters (integer number)
•	Descent (integer number)
•	Maximum altitude in meters (integer number)
•	Minimum altitude in meters (integer number)
•	Ending point (string with maximum length of 50 characters including spaces)
Functions:
•	readFromInput: The function reads from the user an integer number N which represents the total number of routes and then reads the data of N routes (the necessary fields for every route). 
The function returns the number N as a result.
•	printData: The function shows all the routes sorted in waning order according to their length. 
Every route is showed firstly as it was read (from the starting to ending point) and then is showed backwards (from the ending to starting point) since the starting and ending point are different. 
Every time a route is showed, all the data are also showed, plus the estimated time of hiking in the route rounded in integer minutes (based on Naismith’s rule).
•	findShort: The function reads an integer number L and shows the routes whose length is <=L sorted in waning order according to their length. 
Every route is showed firstly as it was read (from the starting to ending point) and then is showed backwards (from the ending to starting point) since the starting and ending point are different. 
Every time a route is showed, all the data are also showed, plus the estimated time of hiking in the route rounded in integer minutes (based on Naismith’s rule).
•	findLocation: The function reads a location and shows the routes that either the starting or the ending point is this location. The function shows the routes sorted in waning order according to their length. 
Every route is showed firstly as it was read (from the starting to ending point) and then is showed backwards (from the ending to starting point) since the starting and ending point are different. 
Every time a route is showed, all the data are also showed, plus the estimated time of hiking in the route rounded in integer minutes (based on Naismith’s rule).
•	findUpHill: The function shows the routes whose ascent is absolute bigger than the descent. The function shows the routes sorted in waning order according to their length. 
Every route is showed firstly as it was read (from the starting to ending point) and then is showed backwards (from the ending to starting point) since the starting and ending point are different. 
Every time a route is showed, all the data are also showed, plus the estimated time of hiking in the route rounded in integer minutes (based on Naismith’s rule).
•	findDownHill: The function shows the routes whose descent is absolute bigger than the ascent. The function shows the routes sorted in waning order according to their length. 
Every route is showed firstly as it was read (from the starting to ending point) and then is showed backwards (from the ending to starting point) since the starting and ending point are different. 
Every time a route is showed, all the data are also showed, plus the estimated time of hiking in the route rounded in integer minutes (based on Naismith’s rule).
•	findAltitude: The function reads two integer numbers (min and max) and shows the routes whose total path is between of the min and max. The function shows the routes sorted in waning order according to their length. 
Every route is showed firstly as it was read (from the starting to ending point) and then is showed backwards (from the ending to starting point) since the starting and ending point are different. 
Every time a route is showed, all the data are also showed, plus the estimated time of hiking in the route rounded in integer minutes (based on Naismith’s rule).
•	findTimely: The function reads an integer number T and shows the routes whose estimated time of hiking is <=T in waning order according to their length. 
If there is a route that the two times of hiking needs less than T, then it shows the starting and ending point (unless the points are the same). 
Every time a route is showed, all the data are also showed, plus the estimated time of hiking in the route rounded in integer minutes (based on Naismith’s rule).
•	readFromFile: The function reads a string S that includes the name of a text file, it opens the S file for reading and then it reads an integer number N from the file which represents the total number of routes 
and then reads the data of N routes (the necessary fields for every route). The function returns the number N as a result.
•	saveData: The function reads a string S that includes the name of a text file, it opens the S file for writing and writes in the file all the routes sorted in waning order according to their length. 
The writing must be similar to the printing way of the function printData.
After completing all these steps, you must change the readFromFile and readFromInput functions, using pointers and dynamic memory allocation. 
Check main to understand the changes you must do.

