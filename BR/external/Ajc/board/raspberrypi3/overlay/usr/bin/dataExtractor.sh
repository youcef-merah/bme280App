#!/bin/sh

while true; do
	bme280 | nc $1 $2
    sleep 3;
done;

