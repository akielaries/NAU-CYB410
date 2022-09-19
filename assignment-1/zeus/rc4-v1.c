/*
 * Example of config file encryption seen in v1
 */

dataSize = size of data
dataIn = encrypted data
char b;
    for (i = 0; i < dataSize; i++) {
        dataOut[i] = 0;
    }
    for (i = 0; i < dataSize; i++) {
        b = dataIn[i];
        if ((i % 2) == 0) {
            b += 2 * i + 10;
        }
        else {
            b += 0xF9 - 2 * i;
        }
        dataOut[i] += b;
    }


