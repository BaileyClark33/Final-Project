## Home Education Washing Machine
By Bailey Clark and Philip Cittadino

### Project Description

The Home Education Washing Machine and Dryer System is an educational tool that simulates real-world laundry processes, teaching users proper techniques 
through interactive automation, which emphasizes promptness. The system ensures that users follow necessary steps before starting a cycle. It requires 
the user to first select the appropriate mode using push buttons then add detergent and finally close the door. Once all conditions are met, the 
system locks the door and initiates the cycle. Upon completion, the door unlocks, and users have two minutes to open the door and remove their 
laundry before an alarm sounds, reinforcing the importance of promptness. Additionally, a screen will display the minutes remaining on the 
cycle and the status of the cycle. This system will ensure young adults not only do their laundy in the correct order, but also get their laundry 
promptly 


Code was created for a dryer system in this repository however was never tested. All Dryer code is commented out.  
## Project Behavior Table

|Specification                                                                            |        Test Result          |         Comment
|------------------|-----------------------------|----------------------
| LCD displays welcome message                    |         pass  |
| Gas Sensor sensing hand sanitizer|         fail    |        
| Gas overide button chenges LCD display to ask for a selection and the door to be closed                    |         pass  |            
| Selection buttons and corrosponding LEDs turn on and turn the others off      | pass|                                                                      
| Start button does not turn on the motor when the door is open or is a selection has not been clicked | pass |
| Motor runs, LCD displays time, Servo Locks when the start button is pressed when the door is closed and a selection has been made                 | pass |
| Motor stops and servo unlocks when the timer runs out | pass |
| LCD displays a new timer for the testing portion of the education washer and keeps counting down | pass |
| Alarm sounds if this new timer runs out| pass|
| LCD displays success message if the door is open when the dicipline time is running | pass |
