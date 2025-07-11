#ifndef READLINE_H
#define READLINE_H

// read_line: skips leading white-space schars, then reads the reminder of the input line
// and stores it in str. Truncates the line if its length exceeds n. 
// Returns the number of chars stored.
int read_line(char str[], int n);

#endif

