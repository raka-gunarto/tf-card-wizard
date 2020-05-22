# TF Card Wizard
A stupid little program written in C++ to (90% of the time) pick a card for Twisted Fate in League of Legends.
You're better off actually doing it manually though this is so slow (unless you're completely useless at TF) (Also you might get a spanking from Riot Games if you use it in real games).

Also will only work on a 1920x1080 resolution screen :)

## How does it work?
Firstly, it creates a keyboard hook to listen for keypresses globally. Then whenever you press the keys "1" "2" or "3", it runs a function.

This function is quite simple, it checks for a single pixel on the hotbar to determine which card is on the card... carousel? Then it picks the card depending on which key you pressed!

## Usage
1. Run the program
2. Pick a card using number keys
	i. Blue is 1
	ii. Red is 2
	iii. Gold is 3  


