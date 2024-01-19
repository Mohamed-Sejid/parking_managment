<h1 align="center" id="title">Parking management system</h1>

<p align="center"><img src="https://github.com/Mohamed-Sejid/parking_managment" alt="project-image"></p>

<p id="description">This project is a GUI (Graphical User Interface) for a parking system prototype that uses a microcontroller to communicate with the PC using serial communication. The system has 3 Presence sensors and servo motors to control the entrance and access. The LED's on the interface will change color from green to yellow if the spot is no longer free. This project was made using QML and Qt creator C++. The microcontroller end is an STM32f407 that is utilizing FreeRTOS and multiple tasks to check Infrared sensors that will give us an idea on car presence and it will control servo motors for the entrance and exit. Another serial task is created to handle sending and receiving data through UART. This is not a full fetched project it's a semestrial project that was made in a short period of time for academic purposes.The GUI github repo: https://github.com/Mohamed-Sejid/parking_managment</p>

The microcontroller section is made using an STM32F407. The project was made using CubeMX to add HAL, pinout, UART, timers and PWM. The github repo for the project https://github.com/Mehdique/FreeRTOS-Parking


<h2>Project Screenshots:</h2>

<img src="https://i.imgur.com/lT5T90r.png" alt="project-screenshot" width="400" height="400/">
