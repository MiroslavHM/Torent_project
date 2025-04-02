#include <stdio.h>
#include <string.h>
#include "../shared/common.h"

int main() {
    TorrentRequest request;

    FILE *file = fopen("data/request.txt", "r");
    if (file == NULL) {
        perror("Не може да се отвори request.txt");
        return 1;
    }

    if (fscanf(file, "%49[^;];%99[^;];%99[^;];%199[^\n]",
               request.username,
               request.torrent_name,
               request.download_path,
               request.source_url) != 4) {
        printf("Невалиден формат в request.txt\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    // Проверка дали заявката вече съществува
    if (request_exists_in_file("data/downloads.txt", &request)) {
        printf("Заявката вече съществува и няма да бъде записана.\n");
    } else {
        if (save_request_to_file("data/downloads.txt", &request)) {
            printf("Заявката беше записана успешно.\n");
        } else {
            printf("Грешка при запис на заявката.\n");
        }
    }

    return 0;
}
