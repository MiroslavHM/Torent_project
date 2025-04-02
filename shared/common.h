#ifndef COMMON_H
#define COMMON_H

#define MAX_NAME_LEN 50
#define MAX_PATH_LEN 100
#define MAX_URL_LEN 200
#define MAX_TORRENT_NAME 100

// Структура за торент заявка

typedef struct {
    char username[MAX_NAME_LEN];
    char torrent_name[MAX_TORRENT_NAME];
    char download_path[MAX_PATH_LEN];
    char source_url[MAX_URL_LEN];
} TorrentRequest;

// Декларация на функцията за запис

int save_request_to_file(const char *filename, const TorrentRequest *request);
int request_exists_in_file(const char *filename, const TorrentRequest *request);

#endif 

