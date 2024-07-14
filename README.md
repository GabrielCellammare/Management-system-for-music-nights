# Management system for music nights

*The Music Evenings Management System is software that is responsible for selling tickets for music events at venues or theaters in Bari, keeping track of the artist or group performing, the venue, the row, the number and cost of the seat booked*

Each user is registered by: 
-nickname (unique)

-e-mail

-last name

-first name

-gender (M/F/unspecified)

-date of birth (optional)

-cell phone no. 

-preferred music genre (chosen with a like from: BLUES, CLASSICAL, HEAVY METAL, HIP-HOP, JAZZ, POP, PUNK, ROCK, OTHER).

Each music event features: 

-unique code

-year

-month

-day

-start and end times of show

-name of artist or group performing

-name of venue

-cost of tickets first row, cost of tickets last row, number of seats per row.


Each reservation includes: 
-unique event code

-user nickname

-row of reserved seat, number of reserved seat, amount paid.  

Please note: If Cprima and Cultima are the costs of the first and last row (whose number is Nultimate), the cost Cn of the seats in row n is: 
C<sub>n</sub>=C<sub>prima</sub> - (n - 1)/(N<sub>ultimate</sub> - 1)*(C<sub>prima</sub>- C<sub>ultimate</sub>).

E.g., if the first row costs C_10 and the 20th row costs C<sub>5</sub> then the second row costs 
 C<sub>2</sub>=10-(2-1)/(20-1)*(10-5) approximates €9.74.


At startup, the system must load from CSV files information about events, users, and reservations. In addition, the system must allow to:

-register a new user; check that he/she is not already registered; 

-edit user data (without being able to change nicknames); 

-add a new event; 

-search for an event by date or artist name and later edit or cancel the event; 

-print the list of those booked to a certain event on the screen; 

-print the list of events attended by a user in order of date or in order of cost;

-sell a ticket to a user; 

-check whether a certain seat at a certain event is free or occupied;

-Print the total takings of an event. 


On delivery, csvs with at least 3 past events, 3 future events, 50 users and at least 20 tickets sold per event must be included.
The csv files can be generated easily with excel, google sheets or other spreadsheets.  
