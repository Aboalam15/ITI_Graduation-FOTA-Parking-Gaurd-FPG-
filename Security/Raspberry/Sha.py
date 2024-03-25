def rotate_right(value, shift):
    return (value >> shift) | (value << (32 - shift)) & 0xFFFFFFFF

def sha1(data):
    # Initialize variables
    h0 = 0x67452301
    h1 = 0xEFCDAB89
    h2 = 0x98BADCFE
    h3 = 0x10325476
    h4 = 0xC3D2E1F0

    # Pre-processing
    data += b'\x80'
    while len(data) % 64 != 56:
        data += b'\x00'
    data += (len(data) * 8).to_bytes(8, byteorder='big')

    # Process the message in 512-bit blocks
    for i in range(0, len(data), 64):
        chunk = data[i:i+64]

        # Break chunk into sixteen 32-bit big-endian words
        words = [int.from_bytes(chunk[j:j+4], byteorder='big') for j in range(0, 64, 4)]

        # Extend the sixteen 32-bit words into eighty 32-bit words
        for j in range(16, 80):
            words.append(rotate_right(words[j-3] ^ words[j-8] ^ words[j-14] ^ words[j-16], 1))

        # Initialize hash value for this chunk
        a = h0
        b = h1
        c = h2
        d = h3
        e = h4

        # Main loop
        for j in range(80):
            if 0 <= j < 20:
                f = (b & c) | ((~b) & d)
                k = 0x5A827999
            elif 20 <= j < 40:
                f = b ^ c ^ d
                k = 0x6ED9EBA1
            elif 40 <= j < 60:
                f = (b & c) | (b & d) | (c & d)
                k = 0x8F1BBCDC
            else:
                f = b ^ c ^ d
                k = 0xCA62C1D6

            temp = (rotate_right(a, 5) + f + e + k + words[j]) & 0xFFFFFFFF
            e = d
            d = c
            c = rotate_right(b, 30)
            b = a
            a = temp

        # Add this chunk's hash to result so far
        h0 = (h0 + a) & 0xFFFFFFFF
        h1 = (h1 + b) & 0xFFFFFFFF
        h2 = (h2 + c) & 0xFFFFFFFF
        h3 = (h3 + d) & 0xFFFFFFFF
        h4 = (h4 + e) & 0xFFFFFFFF

    # Produce the final hash value (big-endian)
    return (h0 << 128) | (h1 << 96) | (h2 << 64) | (h3 << 32) | h4