#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int save_request_to_file(const char *filename, const TorrentRequest *request) {
    FILE *file = fopen(filename, "a"); 
    if (file == NULL) {
        perror("Не може да се отвори файлът за запис");
        return 0;
    }

    fprintf(file, "%s;%s;%s;%s\n",
            request->username,
            request->torrent_name,
            request->download_path,
            request->source_url);

    fclose(file);
    return 1;
}

int request_exists_in_file(const char *filename, const TorrentRequest *request) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        TorrentRequest temp;
        

        if (sscanf(line, "%49[^;];%99[^;];%99[^;];%199[^;\n]",
                   temp.username,
                   temp.torrent_name,
                   temp.download_path,
                   temp.source_url) == 4) {

            if (strcmp(temp.username, request->username) == 0 &&
                strcmp(temp.torrent_name, request->torrent_name) == 0) {
                fclose(file);
                return 1; 
            }
        }
    }

    fclose(file);
    return 0; 
}
