#!/bin/bash

send_event()
{
	evt="dev/input/$1"
	key=$2
	$(adb shell sendevent $evt 1 $key 1 ; adb shell sendevent $evt 0 0 0 ;adb shell sendevent $evt 1 $key 0 ;adb shell sendevent $evt 0 0 0)
}

send_event_alphabet() {
	evt="dev/input/$1"
	key=$2
	i=1
	j=$3
	while [ $i -le $j ]
	do
		$(adb shell sendevent $evt 1 $key 1 ; adb shell sendevent $evt 0 0 0 ;adb shell sendevent $evt 1 $key 0 ;adb shell sendevent $evt 0 0 0)
		i=$(($i+1))
	done
	send_event "event0" "106"
}

# https://stackoverflow.com/a/46481173
escape_char=$(printf "\u1b")
while true; do
	read -rsn1 mode # get 1 character
	if [[ $mode == $escape_char ]]; then
		read -rsn2 mode # read 2 more chars
	fi
	case $mode in
		'OR') send_event "event3" "116"
			;; # Screen ON/OFF => F3
		'OS')
			evt="dev/input/event3"
			$(adb shell sendevent $evt 1 116 108 ; adb shell sendevent $evt 0 0 0 ;adb shell sendevent $evt 1 116 103 ;adb shell sendevent $evt 0 0 0)
			;; # Shutdown => F4
		'') send_event "event0" "352"
			;; # Enter => OK\Enter\Newline
		'[A') send_event "event4" "103"
			;; # Up => Arrow Up
		'[B') send_event "event3" "108"
			;; # Down => Arrow Down
		'[D') send_event "event0" "105"
			;; # Left => Arrow Left
		'[C') send_event "event0" "106"
			;; # Right => Arrow Right
		'OP') send_event "event0" "139"
			;; # SoftLeft => F1
		'OQ') send_event "event0" "158"
			;; # SoftRight => F2
		'[3') send_event "event4" "116"
			;; # EndCall/Backspace => Delete
		'[2') send_event "event0" "231"
			;; # Call => Insert
		'0')
			evt="dev/input/event0"
			$(adb shell sendevent $evt 1 11 1 ; adb shell sendevent $evt 0 0 0 ;adb shell sendevent $evt 1 11 0 ;adb shell sendevent $evt 0 0 0)
			;; # Space or 0
		'1')
			evt="dev/input/event0"
			$(adb shell sendevent $evt 1 2 1 ; adb shell sendevent $evt 0 0 0 ;adb shell sendevent $evt 1 2 0 ;adb shell sendevent $evt 0 0 0)
			;; # toggle Keypad 1
		'a')
			send_event_alphabet "event0" "3" "1"
			;;
		'b')
			send_event_alphabet "event0" "3" "2"
			;;
		'c')
			send_event_alphabet "event0" "3" "3"
			;;
		'2')
			send_event_alphabet "event0" "3" "4"
			;;
		'd')
			send_event_alphabet "event0" "4" "1"
			;;
		'e')
			send_event_alphabet "event0" "4" "2"
			;;
		'f')
			send_event_alphabet "event0" "4" "3"
			;;
		'3')
			send_event_alphabet "event0" "4" "4"
			;;
		'g')
			send_event_alphabet "event0" "5" "1"
			;;
		'h')
			send_event_alphabet "event0" "5" "2"
			;;
		'i')
			send_event_alphabet "event0" "5" "3"
			;;
		'4')
			send_event_alphabet "event0" "5" "4"
			;;
		'j')
			send_event_alphabet "event0" "6" "1"
			;;
		'k')
			send_event_alphabet "event0" "6" "2"
			;;
		'l')
			send_event_alphabet "event0" "6" "3"
			;;
		'5')
			send_event_alphabet "event0" "6" "4"
			;;
		'm')
			send_event_alphabet "event0" "7" "1"
			;;
		'n')
			send_event_alphabet "event0" "7" "2"
			;;
		'o')
			send_event_alphabet "event0" "7" "3"
			;;
		'6')
			send_event_alphabet "event0" "7" "4"
			;;
		'p')
			send_event_alphabet "event0" "8" "1"
			;;
		'q')
			send_event_alphabet "event0" "8" "2"
			;;
		'r')
			send_event_alphabet "event0" "8" "3"
			;;
		's')
			send_event_alphabet "event0" "8" "4"
			;;
		'7')
			send_event_alphabet "event0" "8" "5"
			;;
		't')
			send_event_alphabet "event0" "9" "1"
			;;
		'u')
			send_event_alphabet "event0" "9" "2"
			;;
		'v')
			send_event_alphabet "event0" "9" "3"
			;;
		'8')
			send_event_alphabet "event0" "9" "4"
			;;
		'w')
			send_event_alphabet "event0" "10" "1"
			;;
		'x')
			send_event_alphabet "event0" "10" "2"
			;;
		'y')
			send_event_alphabet "event0" "10" "3"
			;;
		'z')
			send_event_alphabet "event0" "10" "4"
			;;
		'9')
			send_event_alphabet "event0" "10" "5"
			;;
		*) >&2 echo 'ERR bad input'
		;;
	esac
done
