#!/bin/bash

send_event()
{
	evt="dev/input/$1"
	key=$2
	$(adb shell sendevent $evt 1 $key 1 ; adb shell sendevent $evt 0 0 0 ;adb shell sendevent $evt 1 $key 0 ;adb shell sendevent $evt 0 0 0)
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
			;; # Screen ON/OFF F3
		'OS')
			evt="dev/input/event3"
			$(adb shell sendevent $evt 1 116 108 ; adb shell sendevent $evt 0 0 0 ;adb shell sendevent $evt 1 116 103 ;adb shell sendevent $evt 0 0 0)
			;; # Shutdown F4
		'') send_event "event0" "352"
			;; # Enter
		'[A') send_event "event4" "103"
			;; # Up
		'[B') send_event "event3" "108"
			;; # Down
		'[D') send_event "event0" "105"
			;; # Left
		'[C') send_event "event0" "106"
			;; # Right
		'OP') send_event "event0" "139"
			;; # SoftLeft F1
		'OQ') send_event "event0" "158"
			;; # SoftRight F2
		'[3') send_event "event4" "116"
			;; # EndCall Delete
		'[2') send_event "event0" "231"
			;; # Call Insert
		#*) >&2 echo 'ERR bad input'; return ;;
	esac
done
