/*
 * A look at v1.x encryption on config files
 */

int rc4_decrypt(unsigned char *in, unsigned long size, 
    unsigned char *S, unsigned char *out) {
    int i, j, dataCount;
    i = j = dataCount = 0;
    unsigned char temp, rc4_byte;
    for (dataCount = 0; dataCount < size; dataCount++) {
        i = (i + 1) & 255;
        j = (j + S[i]) & 255;
        temp = S[j];
        S[j] = S[i];
        S[i] = temp;
        rc4_byte = S[(temp + S[j]) & 255];
        out[dataCount] = in[dataCount] ^ rc4_byte;
    }
    return dataCount;
} 

