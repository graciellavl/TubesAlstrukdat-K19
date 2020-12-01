    Kata kata;
    kata.Length = K.Length;
    for (int i = 0; i < kata.Length; i++) {
        kata.TabKata[i] = kata.TabKata[i];
    }
    printf("\noutput file %s\n", kata.TabKata);
    printf("len: %s\n", kata.Length);
    return kata;