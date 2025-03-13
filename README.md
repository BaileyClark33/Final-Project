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

The hardware used in this project included a gas sensor designed to detect whether "detergent" had been placed in the machine. Five push buttons were incorporated into the system, each 
serving a specific function. One button acted as the gas override, allowing users to bypass the detergent detection. Three buttons were used for selecting the wash cycle temperature, 
offering options for hot, warm, or cold settings. The final push button served as the "Go" button, initiating the washing machine cycle. An LCD display was included to provide 
real-time feedback to the user, such as the remaining time on the cycle. A light sensor was implemented to detect the status of the door, determining whether it was open or closed. 
Since precise positioning was crucial, a positional servo was used to lock the door securely before the wash cycle began. A DC motor was installed to spin the drum once the cycle 
was in progress, simulating the functionality of a real washing machine. Additionally, a buzzer was programmed to sound an alert if the user failed to retrieve their 
laundry within two minutes of the cycle’s completion.

Although code was written for a dryer system as part of this repository, it was never tested. The dryer-related code remains commented out but is included in the Modular Diagram for 
anyone interested in implementing both washing and drying functions in the future.


## Project Behavior Table

|Specification                                                                            |        Test Result          |         Comment
|------------------|-----------------------------|----------------------
| LCD displays welcome message                    |         pass  |
| Gas Sensor sensing hand sanitizer|         fail    | Gas sensor sensitivity was changed and gas was only detected when this sensitivity was being changed and not during testing
| Gas overide button chenges LCD display to ask for a selection and the door to be closed                    |         pass  |            
| Selection buttons and corrosponding LEDs turn on and turn the others off      | pass|                                                                      
| Start button does not turn on the motor when the door is open or is a selection has not been clicked | pass | The top of the machine should stay on so that the light sensor detects a closed door when the door is closed and not the light coming from the top
| Motor runs, LCD displays time, Servo Locks when the start button is pressed when the door is closed and a selection has been made                 | pass | Door must be closed all the say for the servo to lock the outside of the door
| Motor stops and servo unlocks when the timer runs out | pass |
| LCD displays a new timer for the testing portion of the education washer and keeps counting down | pass |
| Alarm sounds if this new timer runs out| pass|
| LCD displays success message if the door is open when the dicipline time is running | pass |


## Modular Diagram of the Code

<img width="513" alt="Screenshot 2025-03-13 at 7 15 36 AM" src="https://github.com/user-attachments/assets/6714e988-672a-466e-a9fa-495972ea29f9" />


## Price for Washing Machine Hardware
<img width="1216" alt="Screenshot 2025-03-13 at 8 04 34 AM" src="https://github.com/user-attachments/assets/8c22a814-ca6e-43da-8fc4-7817748155ca" />

