
This library was originally taken from the text appearing on the webpage:
   http://playground.arduino.cc/Main/RunningMedian

The original Author - Rob Tillaart - describes it as the follow.

One of the main applications for the Arduino board is reading and logging of
sensor data. For instance one monitors the CO concentration every second of the
day. As samples may fluctuate and generate "spikes" in the graphs one can make
multple measurements and take the median as "working" value. As the
measurements are not static in time what one often wants is the median of a
last defined period, a sort of "running median".  The median is defined as the
middle value of an array of sorted values. The two main advantages of using the
median above average is that it is not influenced by a single outlier and it
allways represent a real measurement. On the other hand by averaging one could
create extra precision.

