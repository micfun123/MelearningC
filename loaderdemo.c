void loadWords(){
    FILE *fp;
    fp = fopen("words.txt", "r");
    if (fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    int i = 0;
    while(fscanf(fp, "%s", words[i]) != EOF){
        i++;
    }
    fclose(fp);
}