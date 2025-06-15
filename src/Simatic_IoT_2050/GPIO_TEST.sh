#!/bin/bash

# Alle Pins von 0 bis 20 auf Ausgang setzen und HIGH schalten
for pin in $(seq 0 13); do
    echo "Setze GPIO $pin auf OUTPUT und HIGH"
    mraa-gpio setdir $pin out
    mraa-gpio set $pin 1
    sleep .2
done

# 1 Sekunde warten
sleep .5

# Alle Pins von 0 bis 20 wieder auf LOW schalten
for pin in $(seq 13 -1 0); do
    echo "Setze GPIO $pin auf LOW"
    mraa-gpio set $pin 0
    sleep .2
done
